#include "ui.h"
#include "config.h"
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int i=0,j=0,escape=0,cnt,mot1=0,mot2=0;
char readbuff[64];
char writebuff[64];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void timer8 () org 0x7A {
IFS3bits.T8IF=0;
LATFBITS.LATF5=~LATFBITS.LATF5;
}
void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT{
  USB_Interrupt_Proc();
}
//-----------------prueba de micro funcionando---------------
void config_timer8() {
tmr8=0;
pr8=31250;
t8con=0x8020;

IFS3bits.T8IF=0;
IEC3bits.T8IE=1;
IPC12bits.T8IP=7;
T2CONbits.TON=1;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main() {
 config_INT;
 TRISDbits.TRISD10=0;
 TRISFBITS.TRISF5=0;
 // UART1_Init_Advanced (9600, 1, 1, 1);
  config_timer8();
  InitMCU();
  HID_Enable(&readbuff,&writebuff); //inicializamos en módulo usb hid
 while(1){

  menu2();
  while(!HID_Read());
  for(cnt=0;cnt<64;cnt++) { 
  writebuff[cnt]=readbuff[cnt]; 
  }
  if(strcmp(readbuff,caso1)==0){//CASE 1
       caso_1(25);
       delay_ms(2000);
      //while(!HID_Write(Bien1,64));
  }
  else if(strcmp(readbuff,caso2)==0){//CASE 2
      //Mostrar valor Velocidad
  }
  else if(strcmp(readbuff,caso3)==0){//CASE 3
      while(!HID_Write(Bien3,64));
  }
  Delay_ms(1000);
}
}
  /*while(escape==0){
        if(HID_Read()){
          escape++;
          while(!HID_Write("Escape\n",64));
        }
        if(mot1){
          while(!HID_Write(MOT1,64));
          Delay_ms(500);
          //Falla Motor 1
        }
        if(mot2){
          while(!HID_Write(MOT2,64));
          Delay_ms(500);
          //Falla Motor 2
        }*/