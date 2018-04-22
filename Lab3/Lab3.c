#include "config.h"
#include "sprites.h"
#include "ui.h"
#include "caso1.h"
#include "caso2.h"
//#include "caso3.h"
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void caso_1();
//~~~~~~~~~~~~~~~~~~~~~~~~Constantes  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned adc_value;
float pote1;
int selected,decimales;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void inter_timer () org 0x24 {
   IFS0bits.T3IF=0;
}
void inter_adc () org 0x2E {
 IFS0bits.AD1IF=0;
  adc_value=ADC1BUF0;
  PDC4=adc_value;
  //pot1=adc_value;
}
void inter_mayor (){
        Glcd_Write_Text("Limite superior ", 0, 4, 1);
}
void inter_menor (){
        Glcd_Write_Text("Limite inferior ", 0, 4, 1);
}
void INT_QEI() org 0x88 {
char texto[15];
 // void QEI();
  glcd_fill(0);
  delay_ms(150);
   glcd_write_text("INT2",62,5,1);
              if(QEI1statbits.IDXIEN==1)
           {
           POS1CNTH=0;
             POS1CNTL=2122;
             valor_sup= QEI1GECH;
  valor_sup=(valor_sup<<16)+ QEI1GECL;
   Floattostr(valor_sup,texto);
  Glcd_Write_Text(texto, 60, 7, 1);
  glcd_write_text("INDEEX",0,0,1);
  delay_ms(200);
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
{
 IFS6bits.PWM4IF=0;
 PWMCON4bits.FLTSTAT=0;
 PWMCON4bits.FLTIEN=0;


}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void main() {
  config_IO();  config_LCD();
  config_INT();
  PS2_Config(); Glcd_Fill(0);
 // ADC1_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF); //Inicializacion del convertidor ADC
/*AD1CON1bits.SSRCG=0;
  AD1CON1bits.SSRC=2;*/
  texto_menu(1);
  while(1){
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
//        texto_caso_3();
     //   caso_3_tests();
       break;
       }
   }
}
void caso_1(){
Glcd_fill(0);
 adc_value=0;
while (1) {

  Glcd_Write_Text("PWM3",0,1,1);
  config_timer3();
  config_PWM();
  config_adc();
  T3CONbits.TON=1;
  // adc_value = ADC1_Get_Sample(5);
  //PDC4=500;
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
  if(PWMCON4bits.FLTSTAT==1)
  {Glcd_Write_Text("  BLOQUEADO  ",0,4,1);
  IOCON4bits.FLTDAT=0;
  PWMCON4bits.FLTSTAT=0;}

  }
}