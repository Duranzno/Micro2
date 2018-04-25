#include "config.h"
#include "sprites.h"
#include "ui.h"
#include "caso1.h"
#include "caso2.h"
#include "caso3.h"
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void caso_1();void caso2();
//~~~~~~~~~~~~~~~~~~~~~~~~Constantes  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned adc_value,adc_value2;
float pote1,pote2;
int selected,decimales;
int contador=0,bandera=0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void INT_Inicio_Conversion_T3 () org 0x24 {IFS0bits.T3IF=0;}//inicializa conversion del adc
void INT_Mayor_QEI (){
  /*glcd_partialimage(48,32,32,32,32,32,up);*/
  //glcd_partialimage(47,10,32,32,32,32,up);

  glcd_write_text("Falla QEI",0,7,1);
  contador=0;
  T2CONbits.TON=1;
}
void INT_Menor_QEI (){
//  glcd_partialimage(48,32,32,32,32,32,dw);
  //glcd_partialimage(47,10,32,32,32,32,dw);
  glcd_write_text("Falla QEI",0,7,1);
  contador=0;
  T2CONbits.TON=1;
}
void INT_Animacion_1seg_T2 () org 0x22 {
  contador++;
  bandera=1;
  if (contador==3 && bandera==2) {//2 segundos cambio imagen QEI
    glcd_fill(0);
    glcd_partialimage(47,10,32,32,32,32,danger_w);

//    glcd_partialimage(48,32,32,32,32,32,danger_w);
   }
   if (contador==5 && bandera==1) {//Cambio Imagen PWM
    glcd_fill(0);
    glcd_partialimage(47,10,32,32,32,32,danger_w);
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
void ajuste (unsigned control) {

 if (control<=200) {
   PDC4=500;
  }else
  if (control>200&&control<=350) {
  PDC4=850;
  } else
    if (control>350&&control<=450) {
  PDC4=1250;
  } else
    if (control>450&&control<=480) {
  PDC4=1450;
  }     else
    if (control>480&&control<=530) {
  PDC4=2000;
  }         else
    if (control>530&&control<=600) {
  PDC4=2450;
  }    else
    if (control>600&&control<=750) {
  PDC4=2850 ;
  }        else
    if (control>750&&control<=950) {
  PDC4=3250;
  }      else
    if (control>950&&control<=1023) {
  PDC4=3800;
  }
}
void ajuste2 (unsigned control2) {

if (control2<=200) {
   PDC3=500;
  }else
  if (control2>200&&control2<=350) {
  PDC3=850;
  } else
    if (control2>350&&control2<=450) {
  PDC3=1250;
  } else
    if (control2>450&&control2<=480) {
  PDC3=1450;
  }     else
    if (control2>480&&control2<=530) {
  PTCONbits.PTEN=0;
  }         else
    if (control2>530&&control2<=600) {
  PDC3=2450;
  }    else
    if (control2>600&&control2<=750) {
  PDC3=2850 ;
  }        else
    if (control2>750&&control2<=950) {
  PDC3=3250;
  }      else
    if (control2>950&&control2<=1023) {
  PDC3=3800;
  }
}
void inter_adc () org 0x2E {
 IFS0bits.AD1IF=0;
  adc_value=ADC1BUF0;
  adc_value2=ADC1BUF1;
  delay_ms(5);
  ajuste(adc_value);
  ajuste2(adc_value2);
  POT1=adc_value;
  POT2=adc_value2;

 // config_pdc4 ()
/*PDC4=adc_value;
  PDC3=adc_value2;*/
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
  glcd_image(stop);
   //glcd_partialimage(47,10,32,32,32,32,stop2);
  glcd_write_text("Falla Motor 4",0,7,1);
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
   glcd_partialimage(47,10,32,32,32,32,stop);
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
      glcd_fill(0);
      break;

     case 2:
      caso2();
      glcd_fill(0);
      break;
     
     case 3:
     Glcd_Set_Font(Font_Glcd_System3x5 ,3,5,32);
     glcd_fill(0);
     config_adc();
     config_timer3();
     T3Conbits.TON=1;
     caso_3_setup();
       while(keydata!=ESC){
        clean_PS2();
        caso_3();
        Ps2_Key_Read(&keydata, &special, &down);
      }
      Glcd_set_Font(font5x7 , 5, 7, 32);
      glcd_fill(0);
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
    Glcd_Write_Text("PWM3",0,1,1);
    T3CONbits.TON=1;
    delay_ms(1000);
    WordToStr(adc_value, txt);
    clean_PS2();
    Ps2_Key_Read(&keydata, &special, &down);
    if(keydata==ESC){return;}
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
void caso2 () {
  char texto[12];
    GLCD_FILL(0);
  Glcd_Write_Text(" Sentido:", 0, 0, 0);
  Glcd_Write_Text(" Distancia(cmts.): ", 0, 4, 0);
  Glcd_Write_Text(" Vueltas ", 0, 7, 0);

  valor_anterior=0;
  cont=0;
  cont2=0;
  vueltas=0;
  config_cuadratura();
  //debido a que POSCNT cuenta con dos registros de 16bits,
  //los unimos en una variable para calcular la distancia
  while(keydata!=ESC){
        clean_PS2();
        bandera=2;
    valor_actual=POS1CNTH;
  valor_actual=(valor_actual<<16)+POS1CNTL;
  recorrido=valor_actual;
  recorrido=recorrido*2.35619; //se divide el poscnt entre 4
  //luego se multiplica por (2.pi.r)/4
   if(valor_actual ==2122 )  {
   recorrido=5000; }
  Floattostr(recorrido,texto);
  Ps2_Key_Read(&keydata, &special, &down);
    if(keydata==ESC){return;}

  Glcd_Write_Text(texto, 1, 5, 1);
  if(valor_anterior<valor_actual)
  {
  Glcd_Write_Text("derecha    ", 1, 2, 1);
  cont=cont+1;
  }
  else if(valor_anterior>valor_actual)
  {
   Glcd_Write_Text("izquierda", 1, 2, 1);
    cont2=cont2+1;
  }
    if(cont ==8 )
    {vueltas++;
    cont=0; }
    if(cont2 ==8 )
    {vueltas=vueltas-1;
    cont2=0; }
     Inttostr(vueltas,texto);
  Glcd_Write_Text(texto, 60, 7, 1);
   valor_anterior=valor_actual;

        Ps2_Key_Read(&keydata, &special, &down);
      }
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

}