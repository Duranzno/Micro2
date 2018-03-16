#include "barras.h"
#include "sprites.h"

// Glcd module connections
sbit GLCD_D7 at RE1_bit;
sbit GLCD_D6 at RE0_bit;
sbit GLCD_D5 at RF1_bit;
sbit GLCD_D4 at RF0_bit;
sbit GLCD_D3 at RD7_bit;
sbit GLCD_D2 at RD6_bit;
sbit GLCD_D1 at RD5_bit;
sbit GLCD_D0 at RD4_bit;
sbit GLCD_D7_Direction at TRISE1_bit;
sbit GLCD_D6_Direction at TRISE0_bit;
sbit GLCD_D5_Direction at TRISF1_bit;
sbit GLCD_D4_Direction at TRISF0_bit;
sbit GLCD_D3_Direction at TRISD7_bit;
sbit GLCD_D2_Direction at TRISD6_bit;
sbit GLCD_D1_Direction at TRISD5_bit;
sbit GLCD_D0_Direction at TRISD4_bit;
sbit GLCD_CS1 at LATE3_bit;
sbit GLCD_CS2 at LATE2_bit;
sbit GLCD_RS at LATD1_bit;
sbit GLCD_RW at LATD2_bit;
sbit GLCD_EN at LATD3_bit;
sbit GLCD_RST at LATE4_bit;
sbit GLCD_CS1_Direction at TRISE3_bit;
sbit GLCD_CS2_Direction at TRISE2_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISE4_bit;
// End Glcd module connections
unsigned short posicion=0;
//void INT0() org 0x14{;}
//void INT1() org 0x3C{;}
//void INT2() org 0x4E{:}
//void INT3() org 0x7E{;}
//void INT4() org 0x80{;}

void config_INT(){
  SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
  INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
  INTCON2bits.GIE=1; //interrupciones habilitadas
  CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
//------------------------- habilitacion de interrupcion
  IEC0bits.INT0IE=1; //HABILITA INTERRUPCION POR INT0
  IEC1bits.INT1IE=1; //HABILITA
  IEC1bits.INT2IE=1;
  IEC3bits.INT3IE=1;
  IEC3bits.INT4IE=1;
// Banderas de Interrupcion post Reset (Limpieza)
  IFS0bits.INT0IF=0; //interrupcion de INT0 ACTIVADA
  IFS1bits.INT2IF =0; // interrupcion de INT1 ACTIVADA
  IFS1bits.INT2IF =0 ; // INTERRIPCION DE INT2 ACTVADA
  IFS3bits.INT3IF =0; //INTERRUPCION DE INT3 ACTIVADA
  IFS3bits.INT4IF =0; // INTERRUPCION DE INT4 ACTIVADA
//Prioridad de Interrupciones
  IPC0bits.INT0IP= 5;
  IPC5BITS.INT1IP= 4;
  IPC7bits.INT2IP =3;
  IPC13bits.INT3IP=2;
  IPC13bits.INT4IP=1;
//--------------------interrupcion flanco positivo
  INTCON2bits.INT0EP=0;
  INTCON2bits.INT1EP=0;
  INTCON2bits.INT2EP=0;
  INTCON2bits.INT3EP=0;
  INTCON2bits.INT4EP =0;
}
const int BTN_PPS_LOCATIONS[5]={-1,47,46,45,44};//5 posiciones para las 4 Ubicaciones de los botones de Interrupciion del ejercicio 1
// el 0 nunca se usa porque INT0 esta fijo
//const int LED_PPS_LOCATIONS[3]={1,2,3};//3 posiciones para 3 LEDS de salida
void config_IO(){
//TRISx,PORTX,LATx,ODCx
  ANSELC=0; ANSELD=0; ANSELE=0;                  //ANALOGICO SON B Y F
  //------------------------------------------------------
  //Asignacion Pines Entrada
  //INT0 No tiene PPS y es constante, a los demas se les tiene que colocar
  //el numero del RPINx en su registro correspondiente.
   //Necesito otras entradas para el 5 dipswitches, y 4 de usb/ps/2
  RPINR0bits.INT1R = BTN_PPS_LOCATIONS[1];//El Periferico INT1 esta en el pin 47
  RPINR1bits.INT2R = BTN_PPS_LOCATIONS[2];
  RPINR1bits.INT3R=  BTN_PPS_LOCATIONS[3];
  RPINR2bits.INT4R=  BTN_PPS_LOCATIONS[4];
  //Necesito 3 salidas extras de GPIO

}
const int DIP_PPS_LOCATIONS[5]={0,1,2,3,4};//5 posiciones para 5 Dipswitches
void config_CN(){
     TRISB = 0;
     CNENB=
     
//CNENx, CNPUx,CNIEx

}
void config_LCD(){
  Glcd_Init();
  Glcd_Set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
}
void main(){
  config_INT();
  config_IO();
  config_CN();//para los dipswitches
  config_LCD();

  while(1){
  //void Glcd_PartialImage(unsigned int x_left, unsigned int y_top, unsigned int width, unsigned int height, unsigned int picture_width, unsigned int picture_height, code const far char * image);
//  Glcd_PartialImage(63,32,30,20,30,20,kirby_1);  delay_ms(500);

       
       if (RCONbits.WDTO==1)
       {

       }
            if(RCONbits.EXTR==1)
            {

            }
                if (RCONbits.POR==1)
                 {
        
        
                 } 


         }

  
}