#include "ui.h"
#include "config.h"
//#include "UART.h"
//Variables de GLCD
sbit GLCD_D0 at RD4_bit;
sbit GLCD_D1 at RD5_bit;
sbit GLCD_D2 at RD6_bit;
sbit GLCD_D3 at RD7_bit;
sbit GLCD_D4 at RF0_bit;
sbit GLCD_D5 at RF1_bit;
sbit GLCD_D6 at RE0_bit;
sbit GLCD_D7 at RE1_bit;
sbit GLCD_CS1 at LATE3_bit;
sbit GLCD_CS2 at LATE2_bit;
sbit GLCD_RS at LATD1_bit;
sbit GLCD_RW at LATD2_bit;
sbit GLCD_EN at LATD3_bit;
sbit GLCD_RST at LATC14_bit;

sbit GLCD_D0_Direction at TRISD4_bit;
sbit GLCD_D1_Direction at TRISD5_bit;
sbit GLCD_D2_Direction at TRISD6_bit;
sbit GLCD_D3_Direction at TRISD7_bit;
sbit GLCD_D4_Direction at TRISF0_bit;
sbit GLCD_D5_Direction at TRISF1_bit;
sbit GLCD_D6_Direction at TRISE0_bit;
sbit GLCD_D7_Direction at TRISE1_bit;
sbit GLCD_CS1_Direction at TRISE3_bit;
sbit GLCD_CS2_Direction at TRISE2_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISC14_bit;
//~~~~~~~~~~~~~~~~~~~~~~Configuraciones Iniciales~~~~~~~~~~~~~~~~~~~~~~~~~~
  void config_IO(){
    ANSELB=ANSELC=ANSELD=ANSELE=0;
    ANSELBbits.ANSB5=1;       // an5
    ANSELBbits.ANSB0=1; // an4
    TRISE=TRISG=0;
    TRISDbits.TRISD0=1;
    TRISDbits.TRISD11=1;
}
void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
}
void timer8 () org 0x7A {
IFS3bits.T8IF=0;
//LATFBITS.LATF4=~LATFBITS.LATF4;
}
void config_timer8() {
tmr8=0;
pr8=31250;
t8con=0x8020;

IFS3bits.T8IF=0;
IEC3bits.T8IE=1;
IPC12bits.T8IP=7;
T8CONbits.TON=1;
}



 unsigned dato=0, dato2=0;
void main () {
 // InitMCU();
  config_IO();  config_LCD();
  config_INT();
  TRISFbits.TRISF4=0;
  config_timer8()  ;
   Glcd_Fill(0);
   delay_ms(2000);
        config_INT();
     //   config_timer8();
        UART1_Init(9600);
        RPINR18bits.U1RXR=46; //U1RX
        RPOR9bits.RP101R=1; //U1TX

          while(1)
 {
  while(!UART1_Data_Ready()); //Espera que reciba un dato
  dato=UART1_Read();
  if(dato==1) {
      LATFBITS.LATF4=1;
      delay_ms(500);
      LATFBITS.LATF4=0;
      delay_ms(500);
        LATFBITS.LATF4=1;
      delay_ms(500);
      LATFBITS.LATF4=0;
   glcd_write_text("Caso 1",0,31,1);
     }
   else if(dato==2) {
   LATFBITS.LATF4=1;
      delay_ms(500);
      LATFBITS.LATF4=0;
      delay_ms(500);
      LATFBITS.LATF4=1;
      delay_ms(500);
      LATFBITS.LATF4=0;
      delay_ms(500);
        LATFBITS.LATF4=1;
      delay_ms(500);
      LATFBITS.LATF4=0;
   glcd_write_text("Caso 2",0,31,1);  }
   else if(dato==3) {
   LATFBITS.LATF4=1;
      delay_ms(2000);
      LATFBITS.LATF4=0;
   glcd_write_text("Caso 1",0,31,1);  }
   dato=0;
 /*while(!UART1_Data_Ready()); //Espera que reciba un dato
  dato2=UART1_Read();
  dato2=(dato2<<8)+dato;
  PDC3=dato2;
  PORTBbits.RB0=~PORTBbits.RB0;
  while(!UART1_Data_Ready()); //Espera que reciba un dato
  dato=UART1_Read();
  PORTBbits.RB0=~PORTBbits.RB0;
  while(!UART1_Data_Ready()); //Espera que reciba un dato
  dato2=UART1_Read();
  dato2=(dato2<<8)+dato;
  PDC4=dato2;
  PORTBbits.RB0=~PORTBbits.RB0;*/
 }
 
 
 
}