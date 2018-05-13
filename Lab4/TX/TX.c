#include "hid.h"
#include "config.h"
#include "config_TX.h"

#define DER 0

#define IZQ 1
#define FALLA 1
#define NOFALLA 0
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int i=0,j=0,escape=0,cnt,mot1=0,mot2=0;
char readbuff[64];
char writebuff[64];
unsigned  short enviado=0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void timer8 () org 0x7A {
	IFS3bits.T8IF=0;
	LATFBITS.LATF5=~LATFBITS.LATF5;
}
void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT{
  USB_Interrupt_Proc();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main() {
	config_INT();config_timer8();InitMCU();
	TRISDbits.TRISD10=0;
	TRISFBITS.TRISF5=0;
	config_pin();
	UART1_Init(9600);
	HID_Enable(&readbuff,&writebuff); //inicializamos en módulo usb hid
	while(1){
		menu2();
		while(!HID_Read());
		for(cnt=0;cnt<64;cnt++) { 
			writebuff[cnt]=readbuff[cnt]; 
		}
		if(strcmp(readbuff,caso1)==0){//CASE 1
			caso_1(150,300,DER,DER,NOFALLA,FALLA);
			enviado=1;
			UART1_Write(enviado);
			delay_ms(2000);
		}
		else if(strcmp(readbuff,caso2)==0){//CASE 2
			enviado=2;
			UART1_Write(enviado);
		}
		else if(strcmp(readbuff,caso3)==0){//CASE 3
			while(!HID_Write(Bien3,64));
			enviado=3;
			UART1_Write(enviado);
		}
	Delay_ms(1000);
	}
}
/*
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
}*/