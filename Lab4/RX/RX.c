  #include "config_RX.h"
#include "motores.h"
 #include "sprites.h"
#include "RTCC.h"
#define ESC_key 254
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned short dato=0, dato2=0;
char tecla, buff;
int pantalla=0;
char txt_hora[2];

char txt[7]={'#','#','#','#','#','#','#'};
int cnt,rpm1=0,rpm2=0;
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void caso2();void caso3();void caso1();void caso5();  void update_hid(); void caso4();
void encender_led(){LATFBITS.LATF4=1;delay_ms(92);LATFBITS.LATF4=0;}
//void update_hid(){encender_led();}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*void timer8 () org 0x7A {
  IFS3bits.T8IF=0;
  rpm=0;
  rpm2=0;
}*/
void selector_sprite(int caso,int cnt){
if (caso==0)
      glcd_write_text("Error CASE_NULL",64,4,1);


    if (caso==1)
           { encender_led();  
      if(cnt==1){animate_64b(mayorquea);}
                        else if(cnt==2){animate_64b(mayorqueb);}
                        else if(cnt==3){animate_64b(mayorquec);}
      }
      if (caso==2)
                        {  encender_led();    if(cnt==1){animate_64b(menorqueb);}
                        else if(cnt==2){animate_64b(menorquec);}
                        else if(cnt==3){animate_64b(menorquea);}
      }
       if (caso==3)
       { encender_led();    if(cnt==1){animate_64b(pwm3a);}
      else if(cnt==2){animate_64b(pwm3b);}
      else if(cnt==3){animate_64b(pwm4c);}
        }
       if (caso==4)
        { encender_led();   if(cnt==1){animate_64b(pwm4a);}
      else if(cnt==2){animate_64b(pwm4b);}
      else if(cnt==3){animate_64b(pwm4c);}
      }

}
//------------------------------------
void INT_T05s_T2()org 0x22{
T05s++;

    inttostr(T05s,txt);glcd_write_text(txt,0,3,1);
    if(T05s%2==0){T1s++;}
    if(T05s>6){T2CONbits.TON=0;GLCD_FILL(0);T1s=0;T05s=0;}
    if(caso!=CASE_NULL&&T1s==3){T1s=0;}
    else if(caso==CASE_NULL&&T1s==2){T1s=0;}
    selector_sprite(caso,T1s);
    IFS0bits.T2IF=0;
}
void INT_RELOJ()org 0x000090{
  LATFBITS.LATF4=0;
  switch(CASO_ALARMA){
    case RTCC_30:        
      if(RTCBandera%3==0){encender_led();glcd_write_text("ALRM 60s",64,6,1);}
    break;
    case RTCC_60:
      if(RTCBandera%6==0){encender_led();glcd_write_text("ALRM 60s",64,6,1);}
    break;
    case RTCC_90:
      if(RTCBandera%9==0){encender_led();glcd_write_text("ALRM 90s",64,6,1);}
    break;
    case RTCC_120:
      if(RTCBandera%12==0){encender_led();glcd_write_text("ALRM 120s",64,6,1);}
    break;
    default:
    case RTCC_NONE:
      RTCBandera=0;
    break;
  }
  sprintf(buffer,"ALRM #%u",RTCBandera+1); 
  glcd_write_text(buffer,64,7,1);
  RTCBandera++;
  IFS3bits.RTCIF=0;
}
void interupcion_ext1() org 0x3C {IFS1bits.INT1IF=0; rpm1++;}
void interupcion_ext2() org 0x4E {IFS1bits.INT2IF=0; rpm2++;}
void timer7 () org 0x74 {
  IFS3bits.T7IF=0;
  rpm1=rpm1*75;
  rpm2=rpm2*75;
  inttostr(rpm1,txt);
  glcd_write_text(txt,64,0,1);
  inttostr(rpm2,txt);
  glcd_write_text(txt,64,1,1);
  rpm1=0;
  rpm2=0;
}
void PWM4() org 0xD6{
  IFS6bits.PWM4IF=0;
  PWMCON3bits.FLTSTAT=0;
  if(PORTDbits.RD11==0){
    glcd_write_text("Falla Motor 4",64,7,1);
    IOCON4bits.FLTDAT=0;
    PWMCON4bits.FLTSTAT=0;
    caso=CASE_PWM4; T2CONbits.TON=1;
  }
}

void PWM3() org 0xD4{
  IFS6bits.PWM3IF=0;
  PWMCON3bits.FLTSTAT=0;
  if(PORTDbits.RD0==0){
    IOCON4bits.FLTDAT=0;
    PWMCON4bits.FLTSTAT=0;
    caso=CASE_PWM3; T2CONbits.TON=1;
    glcd_write_text("Falla Motor 3",64,6,1);
  }
}

void update_hid(){
  rtcc_read();rtc2int();
  //sprintf(buffer,"%02.2u|%02.2u",minyseg,diasyhora);
  //glcd_write_text(buffer,64,4,1);
  //sprintf(buffer,"%02.2u|%02.2u",mesydia,year);
  //glcd_write_text(buffer,64,5,1);
  sprintf(buffer,"%02.2u:%02.2u:%02.2u",hora,minn,seg);
  glcd_write_text(buffer,64,1,1);
  sprintf(buffer,"%02.2u/%02.2u/%02.2u",dia,mes,anio);
  glcd_write_text(buffer,64,2,1);

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Error_SPI() org 0x26{IFS0bits.SPI1EIF=0;}

void SPI() org 0x28{
  Glcd_Write_Text("si interrupmpe", 60, 5, 1);
  dato=SPI1BUF;
  Glcd_Write_Text("algo esta en dato", 60, 2, 1);
  delay_ms(1000) ;
  IFS0bits.SPI1IF=0;
}


void main (){
  ANSELC=0;ANSELD=0;ANSELE=0;ANSELB=0;
  TRISFBITS.TRISF5=0;
  SRbits.IPL=0;
  CORCONbits.IPL3=0;
  INTCON1bits.NSTDIS=0;
  INTCON2bits.GIE=1;
  IPC2bits.SPI1EIP=3;
  IPC2bits.SPI1IP=3;
  IEC0bits.SPI1EIE=0;
  //CONFIGURACION DEL PLL PARA ALCANZAR UNA VELOCIDAD DE 30MHZ
  PLLFBD = 58; //M = 60
  CLKDIVbits.PLLPOST = 0; // N1 = 2
  CLKDIVbits.PLLPRE = 0; // N2 = 2
  OSCTUN = 0;
  OSCCON=0x0301;
  while (OSCCONbits.COSC != 0x3);
  //CONFIGURACION DEL PLL AUXILIAR PARA EL USB
  //SE REQUIEREN 48MHZ
  ACLKCON3 = 0x24C0;
  ACLKDIV3 = 0x7;
  ACLKCON3bits.ENAPLL = 1;
  while(ACLKCON3bits.APLLCK != 1);

  SPI1_Init_Advanced(_SPI_SLAVE,_SPI_8_BIT,_SPI_PRESCALE_SEC_8,
  _SPI_PRESCALE_PRI_64,_SPI_SS_DISABLE,_SPI_DATA_SAMPLE_MIDDLE
  ,_SPI_CLK_IDLE_LOW, _SPI_ACTIVE_2_IDLE);
  RPINR20bits.SDI1R=46; //SDI1
  RPINR20bits.SCK1R=47; //SCK1
  RPOR9bits.RP101R=5; //SDO
  config_IO();config_vref();
  config_LCD(); config_timer2();
  while(1){
    glcd_fill(0);
    Glcd_write_text("Esperando...",64,0,1);
    dato=0;
    while(!SPI1STATbits.SPIRBF); //Esperando que llegue el dato
    dato=0;
    dato=SPI1_Read(buff);
    if (dato==1) {
      GLCD_FILL(0);
      Glcd_write_text("P1",64,0,1);
      caso1();  
    }
    else if (dato==2) {
      Glcd_write_text("P2",64,0,1);
      caso2(); 
    }
    else if (dato==3) {
      Glcd_write_text("P3",64,0,1);
      caso3();  
    }
      else if (dato==4) {
      caso4();
    }
    else if (dato==5) {
      Glcd_write_text("P5",64,0,1);
      caso5();
    } 
  }
}
//-------------------------------------------------CASO 1------------------------------------------------------
void caso1(){
  config_motor();config_timer7();//config_velocidad ();
  //T8CONbits.TON=1;
  glcd_write_text("Caso 1",64,2,1);
  delay_ms(100);
// T7CONbits.TON=1; // activa conteo para RPM de motores

  while (dato!=ESC_key){
    encender_led();
     while(!SPI1STATbits.SPIRBF); //Esperando que llegue el dato
    dato=SPI1_Read(buff);
    if (dato==ESC_key){continue;}
    PDC3=ajuste(dato);
   while(!SPI1STATbits.SPIRBF); //Esperando que llegue el dato
    dato2=SPI1_Read(buff);
    if (dato2==ESC_key){continue;}
    PDC4=ajuste(dato2);
    pantalla=PDC3;
    inttostr(pantalla,txt);
    glcd_write_text(txt,64,6,1);
    pantalla=PDC4;
    floattostr(pantalla,txt);
    glcd_write_text(txt,64,7,1);
  }
  T8CONbits.TON=0;
  dato=0;

}
//-------------------------------------------------CASO 2------------------------------------------------------
void caso2(){
    GLCD_fill(0);
  glcd_write_text("Caso 2",64,0,1); 
  while (dato!=ESC_key){
    dato=SPI1_Read(buff);
    if (dato==1) {
         caso=CASE_MAY;
         T2CONbits.TON=1;
    }
     if (dato==2) {      

         caso=CASE_MEN;
         T2CONbits.TON=1;
    }
     if (dato==3) {
     GLCD_fill(0);
      glcd_write_text("NORMAL",64,0,1); 
    }
   }
}
//-------------------------------------------------CASO 3------------------------------------------------------  
void caso3(){
GLCD_FILL(0);
dato=0;   
  glcd_write_text("Caso 3",64,4,1); 
  delay_ms(50); 
  while (dato!=ESC_key){ 
           while(!SPI1STATbits.SPIRBF); //Espera que reciba un dato   
    dato=SPI1_Read(buff);
    if(dato<16&&dato>=0){
      pantalla=dato;
      CVRCONbits.CVR=dato;
      //glcd_write_text(space,65,7,1);
      floattostr(pantalla,txt);
      glcd_write_text(txt,65,7,1);
      dato=0;
    }
  }
 dato=0;
}
//---------------------------caso 4--------------------------------
void caso4() {
Glcd_fill(0);
  glcd_write_text("CASO 4",65,0,1);
   delay_ms(2000);
}
//-------------------------------------------------CASO 5------------------------------------------------------
void caso5(){
  update_hid();
  config_RTCC();
  GLCD_fill(0);
  glcd_write_text("Caso 5",64,0,1); 
 
  while (dato!=ESC_key){
    Update_hid();
    dato=SPI1_Read(buff);
    if (dato=='X') {
      glcd_write_text("RelojEN",64,0,1);
    RCFGCALbits.RTCEN = 0;// Limpia bit RTCEN , desactiva modulo

    }
    else if (dato=='Y') {
      glcd_write_text("Config Reloj",64,0,1);
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buff);
      seg=dato;encender_led();
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buff);
      minn=dato;encender_led();
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buff);
      hora=dato;encender_led();
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buff);
      dia=dato;encender_led();
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buff);
      mes=dato;encender_led();
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buff);
      anio=dato;encender_led();
      
      RTCC_assembler(anio,mes,dia,hora,minn,seg);
       PADCFG1bits.RTSECSEL=1; // habilita salida de reloj a un segundo
       
      RCFGCALbits.RTCOE=1; // habilita el pin RTCC ( se puede usar para verificar que el RTCC está funcionando )
        delay_ms(50);
    }
     else if (dato=='U') {
          Update_hid();
     }
    else if (dato=='Z') {
      
      
      RTCBandera=0;
      glcd_write_text("Config Alarma",64,0,1); 
      while(!SPI1STATbits.SPIRBF);
      dato=SPI1_Read(buff);
      switch (dato){
        case 1:
        glcd_write_text("CALRM 30s",64,6,1); 
        CASO_ALARMA=RTCC_30;
        break;
        case 2:
        glcd_write_text("CALRM 60s",64,6,1); 
        CASO_ALARMA=RTCC_60;
        break;
        case 3:
        glcd_write_text("CALRM 90s",64,6,1); 
        CASO_ALARMA=RTCC_90;
        break;
        case 4:
        glcd_write_text("CALRM 120s",64,6,1); 
        CASO_ALARMA=RTCC_120;
        break;
        default:
        glcd_write_text("CALRM NONE",64,6,1); 
        CASO_ALARMA=RTCC_NONE;
        break;       
      }
    ALCFGRPTbits.ALRMEN = 0; 
    ALCFGRPTbits.ALRMPTR=0;
    ALRMVAL = 0x0000;
    ALCFGRPTbits.AMASK=0b0010;
    ALCFGRPTbits.CHIME = 1;
    ALCFGRPTbits.ALRMEN = 1;
    }

  }
}


/*void main() {

  InitMCU();config_IO();config_vref();encender_led();
   delay_ms(50);
  config_INT(); UART1_Init(9600);
 // config_timer8();
<<<<<<< HEAD
 config_TMR2_ANIM ();
=======
 config_TMR2_ANIM (); config_LCD();
>>>>>>> 0a11a144dccf812f1381596135ce4779763da330
 //animate_charmander_2s(); Glcd_Fill(0);
 //encender_led();


  while(1){
  encender_led();

    glcd_write_text("Laboratorio 4",64,0,1);
    glcd_write_text("Esperando Comando",64,1,1);
    delay_ms(100);
    while(!SPI1STATbits.SPIRBF); //Espera que reciba un dato
    dato=UART1_Read();
    pantalla=dato;
    floattostr(pantalla,txt);
    glcd_fill(0);
    glcd_write_text(txt,60,0,1);
    glcd_write_text("recibio algo",60,0,1);
    if (dato>0&&dato<4) {
    switch(dato){
      case 1:
        caso1();

          PDC4=15000;
  PDC3=15000;
  T7CONbits.TON=0;
  IPC5BITS.INT1IP=0;
  IPC7bits.INT2IP=0;
  Glcd_Fill(0);
        break;
      case 2:
        caso2();Glcd_Fill(0);
        break;
      case 3:

        caso3();Glcd_Fill(0);
        break;
      default:
        glcd_write_text("Error",64,4,1);
        delay_ms(100);
        break;
    }

  dato=0;
     }
  }
}*/