#include "barras.h"
#include "sprites.h"


const code char camion[1024] = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0, 128, 240, 240, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 120,  28,  12,   6, 134, 198, 198, 198, 198, 198, 198, 198, 198, 198, 206, 254, 248,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,  30,  31,  31,  49,  96, 224, 224, 224, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 255, 255, 255, 255, 127, 127, 127, 127, 127, 127, 127, 127, 127,  97,  96,  96,  96,  96, 224, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 192, 224, 112,  48,  57,  27,  31,  31,  31,  62,  62,  60, 252, 252, 248, 240, 240, 224, 240, 224, 192, 192, 192, 192, 255, 255, 254, 255, 255, 127,  63,  63,  27,  31,  31,  31,  63,  63,  63, 255, 255, 255, 255, 255,  15, 255, 252, 240,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0, 248,   7,   1,   0,  96, 248, 142,   6,   6,   6,  14, 248, 248, 246,   7,   1,   7, 255, 255,   7,   7,   7,   7,   7,   7,   7, 255, 255,   7,   0,   0,  96, 248, 142,   6,   6,   7,  14, 184, 248, 248,   8,   7,  15, 254, 112,   0,   0,  15, 127,  48,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   1,  30,  60, 116, 226, 195, 195, 134, 134, 134, 131, 195, 195, 192,  96,  56,  30,  15,   3,   0,   0,   0,   0,   0,   0,   0,   1,   3,  30,  56, 112, 252, 205, 195, 134, 134, 134, 195, 195, 193, 192,  96,  60,  31,   3,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
};


// PS2 pinout definition
sbit PS2_Data at RF4_bit;
sbit PS2_Clock at RF5_bit;
sbit PS2_Data_Direction at TRISF4_bit;
sbit PS2_Clock_Direction at TRISF5_bit;

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



unsigned short keydata = 0;
unsigned short special = 0;
unsigned short down = 0;
    int op=0;
void casoC(){
 Glcd_Write_TEXT("Ultimo Reset",60,0,1);
 do{
   if (RCONbits.WDTO==1){
     Glcd_Write_TEXT("WDT",0,1,BLACK);
     delay_ms(500);
     RCONbits.WDTO=0;
   }else if(RCONbits.EXTR==1){
     Glcd_Write_TEXT("MCLR",0,2,1);
     delay_ms(500);
     RCONbits.EXTR=0;
   }else if (RCONbits.POR==1){
     Glcd_Write_TEXT("POR",0,3,1);
     delay_ms(500);
     RCONbits.POR=0;
   }
 while(Ps2_Key_Read(&keydata, &special, &down));
 }while(op!=34);
 op='c';
}
void main(){
   ANSELC=0; ANSELD=0; ANSELE=0;                  //ANALOGICO SON B Y F



  LATB = 0;              // Set PORTB to zero
  ANSELB = 0;
  TRISB = 0;             // Initialize PORTB as output
  Glcd_Init();
  Glcd_Set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
PS2_Config();
      Glcd_Write_TEXT("Laboratorio 1",31,0,1);
         delay_ms(3000);
while(1){
         LATB = ~LATB; // Invert PORTB value
         Glcd_Write_TEXT("Laboratorio 1",31,0,1);
         Glcd_Image(camion);
          animate_kirby();
          delay_ms(3000);
          animate_bullet();
          delay_ms(3000);
          animate_blooper_20s();
          delay_ms(3000);
          animate_dog_20s();
          delay_ms(3000);
          animate_shell_20s();
          delay_ms(3000);
          animate_charmander();
         delay_ms(3000);
         Glcd_Fill(0);
         Glcd_Write_TEXT("Presione 'A' para Caso 1",0,1,1);
         Glcd_Write_TEXT("Presione 'B' para Caso 2",0,2,1);
         Glcd_Write_TEXT("Presione 'C' para Caso 3",0,3,1);
         Glcd_Write_TEXT("Presione 'D' para WDT   ",0,4,1);
         delay_ms(3000);

  while(op!=34){
   if(Ps2_Key_Read(&keydata, &special, &down)){
    Glcd_Fill(0);
     switch(op){
                case 'a':
                Glcd_Write_TEXT("Caso A",60,0,1);
                delay_ms(1000);
                op=keydata;
                break;

                case 'b':
                Glcd_Write_TEXT("Caso B ",60,0,1);
                delay_ms(1000);
                op=keydata;
                break;

                case 'c':
                     Glcd_Write_TEXT("Caso C ",60,0,1);
                     delay_ms(1000);
                     casoC();
                     op=keydata;
                     break;

                case 'd':
                     Glcd_Write_TEXT("Caso D ",60,0,1);
                     delay_ms(1000);
                     op=keydata;
                     break;

                case 34:
                     Glcd_Write_TEXT("Menu Principal ",60,0,1);
                     delay_ms(1000);
                     op=keydata;
                     break;
     default:
             Glcd_Write_TEXT("Erroneo ",60,0,1);
             delay_ms(1000);
             break;
     }
   }
 }
}
}