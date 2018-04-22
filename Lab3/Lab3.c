#include "config.h"
#include "sprites.h"
#include "ui.h"
#include "caso1.h"
#include "caso2.h"
#include "caso3.h"
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void caso_1();
//~~~~~~~~~~~~~~~~~~~~~~~~Constantes  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned adc_value,adc_value2;
float pote1,pote2;
int selected,decimales;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void inter_timer () org 0x24 {
   IFS0bits.T3IF=0;
}
void inter_timer2 () org 0x22 {
   glcd_fill(0);
  Glcd_Write_Text(" Sentido: ", 0, 0, 1);
  Glcd_Write_Text(" Distancia(cmts.): ", 0, 4, 1);
   IFS0bits.T2IF=0;
   T2CONbits.TON=0;
}
void inter_timer4 () org 0x4A {
   glcd_fill(0);
  Glcd_Write_Text("PWM4", 55, 0, 1);
   IFS1bits.T4IF=0;
   T4CONbits.TON=0;
}
void inter_adc () org 0x2E {
 IFS0bits.AD1IF=0;
  adc_value=ADC1BUF0;
  adc_value2=ADC1BUF1;
  adc_value=(adc_value*3)+500;
  adc_value2=(adc_value2*3)+500;
 // config_pdc4 ()
  PDC4=adc_value;
  PDC3=adc_value2;
  //pot1=adc_value;
}
void inter_mayor (){
        Glcd_Image(danger_w);
        T2CONbits.TON=1;
}
void inter_menor (){
        Glcd_Image(dw);
        T2CONbits.TON=1;
}
void INT_QEI() org 0x88 {
char texto[15];

              if(QEI1statbits.IDXIEN==1)
           {
           POS1CNTH=0;
             POS1CNTL=2122;

              delay_ms(50);
              QEI1CONbits.PIMOD=0;
             QEI1statbits.IDXIEN=0;

           }
        if(QEI1STATbits.PCHEQIRQ==1)
       {
                 inter_mayor(); // animacion de mayor a 5000cm
         QEI1STATbits.PCHEQIRQ=0;
       }
        if(QEI1STATbits.PCLEQIRQ==1)
           {
            inter_menor();// animacion de menor a 4500 cm
            QEI1STATbits.PCLEQIRQ=0;
           }
   IFS3bits.QEI1IF=0;
}
void PWM4() org 0xD6
{  glcd_write_text("fallaPWM4",0,0,1);
 IFS6bits.PWM4IF=0;

 if(PORTDbits.RD11==0)
  {Glcd_Write_Text("  BLOQUEADO  ",0,7,1);
  IOCON4bits.FLTDAT=0;
  PWMCON4bits.FLTSTAT=0;
  T4CONbits.TON=1;
  }

}



void PWM3() org 0xD4
{  glcd_write_text("fallaPWM3",8,0,1);
 IFS6bits.PWM3IF=0;
  PWMCON3bits.FLTSTAT=0;
   if(PORTDbits.RD0==0)
  {Glcd_Write_Text("  BLOQUEADO  ",0,7,1);
  IOCON4bits.FLTDAT=0;
  PWMCON4bits.FLTSTAT=0;
  T4CONbits.TON=1;
  }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void main() {
  config_IO();  config_LCD();
  config_INT();
  PS2_Config(); Glcd_Fill(0);
 // ADC1_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF); //Inicializacion del convertidor ADC
/*AD1CON1bits.SSRCG=0;
  AD1CON1bits.SSRC=2;*/
  texto_menu(1);
  while(1){
  caso_1();
     selected=cursor_menu(3);
   switch(selected){
     case 1:
       clean_PS2();
      caso_1();
      break;
     case 2:

      while(keydata!=ESC){
        clean_PS2();
        caso2();

        delay_ms(2500);
        Ps2_Key_Read(&keydata, &special, &down);
      }
       break;
     case 3:
       clean_PS2();

   //    caso_3_tests();
       break;
       }
   }
}
void caso_1(){
Glcd_fill(0);
  config_timer3();
  config_PWM();
  config_PWM3();
  config_adc();
 adc_value=0;
 config_timer4 ();
while (1) {

  Glcd_Write_Text("PWM3",0,1,1);

   T3CONbits.TON=1;
  // adc_value = ADC1_Get_Sample(5);
  //PDC4=1000;
  //PDC3=3000;
  //Glcd_Write_Text("500 ",30,5,1);
/*delay_ms(1000);
   PDC4=1000;
  Glcd_Write_Text("1000",30,5,1);
  delay_ms(1000);
  PDC4=1500;
  Glcd_Write_Text("1500",30,5,1);
  delay_ms(1000);
  PDC4=2000;
  Glcd_Write_Text("2000",30,5,1);
  delay_ms(1000);
   PDC4=2500;
  Glcd_Write_Text("2500",30,5,1);
  delay_ms(1000);
   PDC4=3000;
  Glcd_Write_Text("3000",30,5,1);
  delay_ms(1000);
   PDC4=3500;*/
  /*if(adc_value<200){
    PDC4=2100;//75% del ciclo util
    Glcd_Write_Text("SETENTA",30,5,1);
    }
  else if(adc_value>200&&adc_value<=400){
    PDC4=2300;
    Glcd_Write_Text("CINCUENTA",0,1,1);
  }
  else if(adc_value>400&&adc_value<700){
    PDC4=2700;
    Glcd_Write_Text("VEINTE",0,1,1);
  }else if(adc_value>700){
    PDC4=3000;
    Glcd_Write_Text("DIEZ",0,1,1);
  }*/
  delay_ms(1000);
 WordToStr(adc_value, txt);
 Glcd_Write_Text(txt, 10, 3, 1);
  pote1=adc_value*0.00339;
  decimales=1000*pote1;
  pote1=decimales*(1.00/1000);
  FloatToStr(pote1, txt);
  Glcd_Write_Text(txt, 10, 4, 1);
   WordToStr(adc_value2, txt);
 Glcd_Write_Text(txt, 70, 3, 1);
  pote1=adc_value*0.00339;
  decimales=1000*pote2;
  pote2=decimales*(1.00/1000);
  FloatToStr(pote2, txt);
  Glcd_Write_Text(txt, 70, 4, 1);
   }


  }
