#include "config_RX.h"
#include "motores.h"
#include "sprites.h"
#define ESC_key 254
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned short dato=0, dato2=0;
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
             0
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

void main() {

  InitMCU();config_IO();config_vref();encender_led();
   delay_ms(50);
  config_INT(); UART1_Init(9600);
 // config_timer8(); 
 config_TMR2_ANIM (); config_LCD();
 //animate_charmander_2s(); Glcd_Fill(0);
 //encender_led();


  while(1){
  encender_led();

    glcd_write_text("Laboratorio 4",64,0,1);
    glcd_write_text("Esperando Comando",64,1,1);
    delay_ms(100);
    while(!UART1_Data_Ready()); //Espera que reciba un dato
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
}

void caso1(){
  config_motor();config_timer7();config_velocidad ();
  //T8CONbits.TON=1;
  glcd_write_text("Caso 1",64,2,1);
  delay_ms(100);
 T7CONbits.TON=1; // activa conteo para RPM de motores
  while(!UART1_Data_Ready());

  while (dato!=ESC_key){
                  encender_led();
    dato=UART1_Read();
    if (dato==ESC_key){continue;}
    PDC3=ajuste(dato);
    while(!UART1_Data_Ready());
    dato2=UART1_Read();
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
    dato=UART1_Read();
    if (dato==1) {
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
           while(!UART1_Data_Ready()); //Espera que reciba un dato   
    dato=UART1_Read();
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