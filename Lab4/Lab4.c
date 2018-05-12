#include "ui.h"
#include "UART.h"
#include "config.h"
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void InitMCU(){
  ANSELC=0x0000; //Configuracion de E/S digitales
  ANSELD=0x0000; //Configuracion de E/S digitales
  ANSELE=0x0040; //RE6 como entrada analogica
  ANSELB=0x0000; //Configuracion de E/S digitales
  //CONFIGURACION DEL PLL PARA ALCANZAR UNA VELOCIDAD DE 30MHZ
  PLLFBD = 58; //M = 60
  CLKDIVbits.PLLPOST = 0; // N1 = 2
  CLKDIVbits.PLLPRE = 0; // N2 = 2
  OSCTUN = 0;
  OSCCON=0x0301;
while (OSCCONbits.COSC != 0x3);
  //CONFIGURACION DEL PLL AUXILIAR PARA EL USB
  //SE REQUIEREN 48MHZ
  ACLKCON3 = 0x24C0;
  ACLKDIV3 = 0x7;
  ACLKCON3bits.ENAPLL = 1;
  while(ACLKCON3bits.APLLCK != 1);
}
int i=0,j=0,escape=0,mot1=0,mot2=0;
char readbuff[64];
char writebuff[64];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT{
  USB_Interrupt_Proc();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main() {
  animate_charmander_2s();
  Glcd_Fill(0);
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
