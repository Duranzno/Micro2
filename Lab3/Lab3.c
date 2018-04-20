#include "config.h"
#include "sprites.h"
#include "ui.h"
#include "caso1.h"
//#include "caso2.h"
#include "caso3.h"
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~Constantes  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Casos~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Caso 1~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Caso 2~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Caso 3~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

unsigned int adc_value;
void main() {
config_IO();
 config_LCD();
 	PS2_Config();  Glcd_Fill(0);
 	ADC1_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF); //Inicializacion del convertidor ADC
 	while(1){
    Glcd_Write_TEXT("Laboratorio 3",31,0,1);
    Glcd_Write_TEXT("'PRUEBA 1 ->o",0,1,1);

    if(Ps2_Key_Read(&keydata, &special, &down)){
       if(down &&!special){
              switch(keydata){
                case 'a':
                case 'o':
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
                   	}else if(adc_value>400&&adc_value<700){
                      PDC4=2700;
                      Glcd_Write_Text("VEINTE",0,1,1);
                    }else if(adc_value>700){
                      PDC4=3000;
                      Glcd_Write_Text("DIEZ",0,1,1);
                   }WordToStr(adc_value, txt);

                  Glcd_Write_Text(txt, 10, 3, 1);
                  adc_value=adc_value*4.96578;
                   WordToStr(adc_value, txt);
                   Glcd_Write_Text(txt, 10, 4, 1);
                  delay_ms(2000);
                  break;
                case 'l':
                case 'v':
                caso_1_tests();
                break;
                default:
                  Glcd_Fill(0);
                  Glcd_Write_TEXT("Erroneo ",60,0,1);
                  delay_ms(2000);
                  break;
                }
              }
            }


}
}