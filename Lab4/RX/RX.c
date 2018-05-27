#include "config_RX.h"
#include "motores.h"
#include "sprites.h"
#include "RTCC.h"
#define ESC_key 254
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned short dato=0, dato2=0;
char tecla, buffer;
int pantalla=0;
char txt[7]={'#','#','#','#','#','#','#'};
int cnt,rpm1=0,rpm2=0;
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void caso2();void caso3();void caso1();
void encender_led(){LATFBITS.LATF4=~LATFBITS.LATF4;}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*void timer8 () org 0x7A {
  IFS3bits.T8IF=0;
  rpm=0;
  rpm2=0;
}*/

/*void INT_T05s_T2()org 0x22{
    T05s++;
    inttostr(T05s,txt);
    glcd_write_text(txt,0,3,1);
    if(T05s%2==0){T1s++;}
     if(T05s>6){T2CONbits.TON=0;T1s=0;T05s=0;}
    if(caso!=CASE_NULL&&T1s==3){T1s=0;}
    else if(caso==CASE_NULL&&T1s==2){T1s=0;}
    selector_sprite(caso,T1s);
    IFS0bits.T2IF=0;
}*/
 void interupcion_ext1() org 0x3C {
    IFS1bits.INT1IF=0;
    rpm1++;

 }
  void interupcion_ext2() org 0x4E {
    IFS1bits.INT2IF=0;
    rpm2++;
 }
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
     //caso=CASE_PWM4; T2CONbits.TON=1;
  }
}

void PWM3() org 0xD4{
  IFS6bits.PWM3IF=0;
  PWMCON3bits.FLTSTAT=0;
  if(PORTDbits.RD0==0){
    IOCON4bits.FLTDAT=0;
    PWMCON4bits.FLTSTAT=0;
   //  caso=CASE_PWM3; T2CONbits.TON=1;
    glcd_write_text("Falla Motor 3",64,6,1);
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Error_SPI() org 0x26{
        IFS0bits.SPI1EIF=0;

}

void SPI() org 0x28{
   Glcd_Write_Text("si interrupmpe", 60, 5, 1);
      dato=SPI1BUF;
    Glcd_Write_Text("algo esta en dato", 60, 2, 1);
    delay_ms(1000) ;
        IFS0bits.SPI1IF=0;

}

char ale[30];
void main (){
        ANSELC=0;
        ANSELD=0;
        ANSELE=0;
        ANSELB=0;

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
        config_LCD();
         while(1)
         { sprintf(ale,"%.3f",0.1234);
           Glcd_write_text(ale,64,0,1);

           while(!SPI1STATbits.SPIRBF); //Esperando que llegue el dato
            Glcd_write_text("PAOLA",64,2,1);
            dato=SPI1_Read(buffer);
             if (dato==1) {

                 Glcd_write_text("P1",64,3,1);
                  caso1();  }
                 if (dato==2) {
                 Glcd_write_text("P2",64,4,1);
                 caso2();  }
                 if (dato==3) {
                 Glcd_write_text("P3",64,5,1);
                 caso3();  }
                 if (dato==5) {
                 Glcd_write_text("P5",64,5,1);
                 caso5();  
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

void caso1(){
  config_motor();config_timer7();//config_velocidad ();
  //T8CONbits.TON=1;
  glcd_write_text("Caso 1",64,2,1);
  delay_ms(100);
// T7CONbits.TON=1; // activa conteo para RPM de motores

  while (dato!=ESC_key){
    encender_led();
     while(!SPI1STATbits.SPIRBF); //Esperando que llegue el dato
    dato=SPI1_Read(buffer);
    if (dato==ESC_key){continue;}
    PDC3=ajuste(dato);
   while(!SPI1STATbits.SPIRBF); //Esperando que llegue el dato
    dato2=SPI1_Read(buffer);
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
void caso2(){
    GLCD_fill(0);
  glcd_write_text("Caso 2",64,0,1); 
  while (dato!=ESC_key){
    dato=SPI1_Read(buffer);
    if (dato==1) {
         caso=CASE_MAY;
         T2CONbits.TON=1;
    }
     if (dato==2) {
        caso=CASE_MEN;

        // caso=CASE_MAY;
         T2CONbits.TON=1;
    }
     if (dato==2) {
        //caso=CASE_MEN;
         T2CONbits.TON=1;
    }
     if (dato==3) {
     GLCD_fill(0);
      glcd_write_text("NORMAL",64,0,1); 
    }
   }
}
  
void caso3(){
dato=0;   
  glcd_write_text("Caso 3",64,4,1); 
  delay_ms(50); 
  while (dato!=ESC_key){ 
           while(!SPI1STATbits.SPIRBF); //Espera que reciba un dato   
    dato=SPI1_Read(buffer);
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
void caso5(){
  config_RTCC();
  GLCD_fill(0);
  glcd_write_text("Caso 5",64,0,1); 
  update_hid();
  delay_ms(2000);
  while (dato!=ESC_key){
    dato=SPI1_Read(buffer);
    if (dato=='X') {
      glcd_write_text("Habilitacion Reloj",64,0,1); 
      RCFGCALbits.RTCEN = 1;
      update_hid();
      //enable reloj y update pantalla
    }
    else if (dato=='Y') {
      glcd_write_text("Config Reloj",64,0,1); 
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buffer);
      u_hora[SEG]=dato;
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buffer);
      u_hora[MIN]=dato;
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buffer);
      u_hora[HOR]=dato;
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buffer);
      u_hora[DIA]=dato;
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buffer);
      u_hora[MES]=dato;
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buffer);
      u_hora[ANO]=dato;
      update_hid();
    }
    else if (dato=='Z') {
      RCFGCALbits.RTCEN = 0;
      ALCFGRPTbits.AMASK=0b0000;
      ALCFGRPTbits.ALRMPTR=10;
      glcd_write_text("Config Alarma",64,0,1); 
      while(!SPI1STATbits.SPIRBF); dato=SPI1_Read(buffer);
      switch dato{
        case 'A':
        glcd_write_text("Alarma de 30s",64,1,1); 
        CASO_ALARMA=RTCC_30;
        break;
        case 'B':
        glcd_write_text("Alarma de 60s",64,1,1); 
        CASO_ALARMA=RTCC_60;
        break;
        case 'C':
        glcd_write_text("Alarma de 90s",64,1,1); 
        CASO_ALARMA=RTCC_90;
        break;
        case 'D':
        glcd_write_text("Alarma de 120s",64,1,1); 
        CASO_ALARMA=RTCC_120;
        break;
        default:
        CASO_ALARMA=RTCC_NONE;
        break;       
      }
    ALRMVAL = 0x0000;//MESDIAS
    ALRMVAL = 0x0000;//SEMHOR
    ALRMVAL = 0x0000;//MINSEC
    ALCFGRPTbits.CHIME = 1;
    ALCFGRPTbits.ALRMEN = 1;
    }
    else {

      escape++;
    }
  }
}
void update_hid(){
  sprintf(buffer,"%u:%u:%u   del dia %u",u_hora[HOR],u_hora[MIN],u_hora[SEG],u_hora[DIA]);
  glcd_write_text(buffer,64,6,1); 
  sprintf(buffer,"del mes %u,del año %u",u_hora[MES],u_hora[ANO]);
  glcd_write_text(buffer,64,7,1); 
}
