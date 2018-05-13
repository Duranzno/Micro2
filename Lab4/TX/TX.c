#include "hid.h"
//#include "config.h"
#include "config_TX.h"


//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int i=0,j=0,escape=0,cnt,mot1=0,mot2=0;
char readbuff[64];
char writebuff[64];
unsigned  short enviado=0;
unsigned caso1_val[6]
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void timer8 () org 0x7A {
        IFS3bits.T8IF=0;
        LATFBITS.LATF5=~LATFBITS.LATF5;
}
void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT{
  USB_Interrupt_Proc();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char txt [30]   ;
float dato=0;
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
                        enviado=1;
                        UART1_Write(enviado);
                        delay_ms(100);
                         enviado=0;
                         enviado=5;
                        while(!escape){
                        	if(HID_Read()){
                        		escape++;
                        	}else{
                        		//ORDEN RPN1,RPN2,DER(0)/IZQ(1)
                        		//FALLA(1)/NOFALLA(0);
                        		caso1_val[0]=150;
                        		caso1_val[1]=300;
                        		caso1_val[2]=DER;
                        		caso1_val[3]=IZQ;
                        		caso1_val[4]=FALLA;
                        		caso1_val[5]=NOFALLA;
                        		caso1(caso1_val[0],caso1_val[1],
                        			caso1_val[2],caso1_val[3],
                        			caso1_val[4],caso1_val[5]);
                        		
                        	}                  

                        }
                         while(!UART1_Data_Ready()); //Espera que reciba un dato
                         enviado=UART1_Read();
                           dato=enviado;
                         floattostr(dato,txt);
                         logd(txt);
                        delay_ms(2000);
                }
                else if(strcmp(readbuff,caso2)==0){//CASE 2
                        enviado=2;

                        UART1_Write(enviado);
                        delay_ms(100);
                         enviado=0;
                         enviado=5;

                         while(!UART1_Data_Ready()); //Espera que reciba un dato
                         enviado=UART1_Read();
                           dato=enviado;
                         floattostr(dato,txt);
                         logd(txt);
                }
                else if(strcmp(readbuff,caso3)==0){//CASE 3
                        while(!HID_Write(Bien3,64));
                        enviado=3;

                        UART1_Write(enviado);
                        delay_ms(100);
                         enviado=0;
                         enviado=5;

                         while(!UART1_Data_Ready()); //Espera que reciba un dato
                         enviado=UART1_Read();
                           dato=enviado;
                         floattostr(dato,txt);
                         logd(txt);
                }
        Delay_ms(1000);
        escape=0;
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