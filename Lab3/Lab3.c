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
        Glcd_Write_Text("Limite superior ", 0, 4, 0);
}
void inter_menor (){
        Glcd_Write_Text(" Limite inferior ", 0, 4, 0);
}
void int_captura() org 0x88 {
              if(QEI1statbits.IDXIEN==1)
           {POS1CNTH=0;
             POS1CNTL=2122;
             //inttostr(QEI1CONbits.PIMOD,txt);glcd_write_text("_INDEX",0,0,1) ;delay_ms(500); glcd_write_text("             ",0,0,1);
  }
        if(QEI1STATbits.PCHEQIRQ==1)
       {
                 inter_mayor(); // animacion de mayor a 5000cm
       }
        if(QEI1STATbits.PCLEQIRQ==1)
           {
            inter_menor();// animacion de menor a 4500 cm       
           } 
       
  
   IFS3bits.QEI1IF=0;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Casos~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Caso 1~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Caso 2~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Caso 3~~~~~~~~~~~~~~~~~~~~~~~~~~
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