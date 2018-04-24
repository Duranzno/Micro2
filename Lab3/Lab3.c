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
int contador=0,bandera=0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void INT_Inicio_Conversion_T3 () org 0x24 {IFS0bits.T3IF=0;}//inicializa conversion del adc
void INT_Mayor_QEI (){
  /*glcd_partialimage(48,32,32,32,32,32,up);*/
  Glcd_Image(charmander_1) ;
  contador=0;
  T2CONbits.TON=1;
}
void INT_Menor_QEI (){
//  glcd_partialimage(48,32,32,32,32,32,dw);
  Glcd_Image(charmander_1);
  contador=0;
  T2CONbits.TON=1;
}
void INT_Animacion_1seg_T2 () org 0x22 {
  Glcd_Write_Text("t2", 55, 7, 1);
  inttostr(contador,txt);
  Glcd_Write_Text(txt, 0, 7, 1);
  contador++;
  bandera=1;
  if (contador==3 && bandera==2) {//2 segundos cambio imagen QEI
    glcd_fill(0);
    Glcd_Image(charmander_2);

//    glcd_partialimage(48,32,32,32,32,32,danger_w);
   }
   if (contador==5 && bandera==1) {//Cambio Imagen PWM
    glcd_fill(0);
    Glcd_Image(charmander_2) ;
  }
   if (contador==6 && bandera==2) {//5 segundos, limpia pantalla
    glcd_fill(0);
  Glcd_Write_Text(" Sentido: ", 0, 0, 0);
  Glcd_Write_Text(" Distancia(cmts.): ", 0, 4, 0);
   T2CONbits.TON=0;
   contador=0;
   }
   if (contador==9 && bandera==1){
    glcd_fill(0);
  Glcd_Write_Text("PWM4", 55, 0, 1);
             Glcd_Write_Text("PWM3",0,1,1);
    contador=0;T2conbits.ton=0;
   }
   IFS0bits.T2IF=0;
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

void INT_QEI() org 0x88 {
  char texto[15];
  if(QEI1statbits.IDXIEN==1){
    POS1CNTH=0;
    POS1CNTL=2122;
    recorrido=5000;
    delay_ms(50);
    QEI1CONbits.PIMOD=0;
    QEI1statbits.IDXIEN=0;
  }
  if(QEI1STATbits.PCHEQIRQ==1){
    INT_Mayor_QEI(); // animacion de mayor a 5000cm
    QEI1STATbits.PCHEQIRQ=0;
  }
  if(QEI1STATbits.PCLEQIRQ==1){
    INT_Menor_QEI();// animacion de menor a 4500 cm
    QEI1STATbits.PCLEQIRQ=0;
    }
  IFS3bits.QEI1IF=0;
}

void PWM4() org 0xD6{ 
 IFS6bits.PWM4IF=0;
 if(PORTDbits.RD11==0)
  {
  Glcd_Image(charmander_1) ;
  glcd_write_text("Falla Motor 4",0,6,1);
  IOCON4bits.FLTDAT=0;
  PWMCON4bits.FLTSTAT=0;
  T2CONbits.TON=1;contador=0;
  }

}

void PWM3() org 0xD4{
 IFS6bits.PWM3IF=0;
 PWMCON3bits.FLTSTAT=0;
 if(PORTDbits.RD0==0){
  IOCON4bits.FLTDAT=0;
  PWMCON4bits.FLTSTAT=0;
  Glcd_Image(charmander_1) ;
   glcd_write_text("Falla Motor 3",0,6,1);
  contador=0;
  T2CONbits.TON=1;
  }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int j;
void main() {
  config_IO();  config_LCD();
  config_INT();
  PS2_Config();
  glcd_image(dw);delay_ms(1000);
  animate_charmander_2s();
  Glcd_Fill(0);
  config_timer2();
 // ADC1_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF); //Inicializacion del convertidor ADC
/*AD1CON1bits.SSRCG=0;
  AD1CON1bits.SSRC=2;*/
//  texto_menu(1);
  while(1){
    selected=cursor_menu(3);
    switch(selected){
     case 1:


      caso_1();
      break;

     case 2:

      while(keydata!=ESC){
        clean_PS2();
        bandera=2;
        caso2();
        Ps2_Key_Read(&keydata, &special, &down);
      }
      break;
     
     case 3:
  Glcd_Write_Text("PWM3",0,1,1);    //caso_3_test();
     T2CONbits.TON=1;
      break;
    }
   }
}
void caso_1(){
  Glcd_fill(0); 
  config_timer3();  config_timer4();
  config_PWM();  config_PWM3();
  config_adc();
  adc_value=0;
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
  while (keydata!=ESC){
    clean_PS2();
    Glcd_Write_Text("PWM3",0,1,1);
    T3CONbits.TON=1;
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
    Ps2_Key_Read(&keydata, &special, &down);
  }
}