#include "ui.h"
//#include "UART.h"
#include "config.h"
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int i=0,j=0,escape=0,cnt,mot1=0,mot2=0;
char readbuff[64];
char writebuff[64];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT{
  USB_Interrupt_Proc();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main() {
  InitMCU();
  HID_Enable(&readbuff,&writebuff); //inicializamos en módulo usb hid
 while(1){
  while(!HID_Write(menu,64));
  
  
  while(!HID_Read());
  for(cnt=0;cnt<64;cnt++) writebuff[cnt]=readbuff[cnt];
    if(strcmp(readbuff,caso1)==0){//CASE 1 
      while(!HID_Write(Bien1,64));
      while(escape==0){
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
        }
      escape=0;
      }
    }
    else if(strcmp(readbuff,caso2)==0){//CASE 2
      while(!HID_Write(Bien2,64));
      //Mostrar valor Velocidad
    }
    else if(strcmp(readbuff,caso3)==0){//CASE 3
      while(!HID_Write(Bien3,64));
    }
  Delay_ms(1000);
  }
}