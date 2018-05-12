#include "ui.h"
#include "UART.h"
#include "config.h"
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int i=0,j=0;
char readbuff[64];
char writebuff[64];
unsigned adc_valor,resistencia;
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
 
}