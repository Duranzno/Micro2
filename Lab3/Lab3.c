#include "config.h"
#include "sprites.h"
#include "ui.h"
#include "caso1.h"
#include "caso2.h"
#include "caso3.h"
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void caso_1();
//~~~~~~~~~~~~~~~~~~~~~~~~Constantes  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned adc_value;
int selected;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void main() {
  config_IO();  config_LCD();
  PS2_Config(); Glcd_Fill(0);
  ADC1_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF); //Inicializacion del convertidor ADC
  texto_menu(1);
  while(1){
     selected=cursor_menu(3);
   switch(selected){
     case 1:
       clean_PS2();
//       caso_1();
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
        caso_3_tests();
       break;
       }
   }
}
void caso_1(){
  Glcd_Fill(0);
  Glcd_Write_Text("PWM3",0,1,1);
  config_PWM();
  adc_value = ADC1_Get_Sample(5);
  if(adc_value<200){
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
  }
  WordToStr(adc_value, txt);
  Glcd_Write_Text(txt, 10, 3, 1);
  adc_value=adc_value*0.003271;
  WordToStr(adc_value, txt);
  Glcd_Write_Text(txt, 10, 4, 1);
  delay_ms(2000);
}