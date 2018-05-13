#include "hid.h"
#include "adc.h"
#include "config_TX.h"


//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void buffer_caso1();void caso2();void caso3();
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int i=0,j=0,escape=0,cnt,mot1=0,mot2=0;
float pantalla=0;
char readbuff[64];
char writebuff[64];
unsigned  short enviado=0;
unsigned    caso1_val[6]={},
unsigned adc_value1,adc_value12,POT1,POT2;
char txt [30];
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void timer8 () org 0x7A {
        IFS3bits.T8IF=0;
        LATFBITS.LATF5=~LATFBITS.LATF5;
}
void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT{
  USB_Interrupt_Proc();
}
void INT_Inicio_Conversion_T3 () org 0x24 {IFS0bits.T3IF=0;}//inicializa conversion del adc

void inter_adc () org 0x2E {
    IFS0bits.AD1IF=0;
    adc_value1=ADC1BUF0;
    adc_value2=ADC1BUF1;
    delay_ms(10);
    adc_value1=ajuste(adc_value1);
    adc_value2=ajuste(adc_value12);
      if(adc_value1<2000){
        caso1_val[2]=IZQ;}
      else {
        caso1_val[2]=DER;}
      if(adc_value2<2000){
        caso1_val[3]=IZQ;}
      else {
        caso1_val[3]=DER;}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main() {
        config_INT();config_timer8();InitMCU();
        config_timer3();config_adc();
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
                        caso1();
                }
                else if(strcmp(readbuff,caso2)==0){//CASE 2
                        caso2();
                }
                else if(strcmp(readbuff,caso3)==0){//CASE 3
                        caso3();
                }
        Delay_ms(1000);
        escape=0;
        }
}
void caso1(){
    enviado=1;
    UART1_Write(enviado);
    delay_ms(150);
    UART1_Write(adc_value1&0xFF);
    delay_ms(50);
    UART1_Write(adc_value2&0xFF);
    delay_ms(50);
    while(!escape){
        if(HID_Read()){
            escape++;}
        else{
            //ORDEN RPN1,RPN2,DER(0)/IZQ(1)
            //FALLA(1)/NOFALLA(0);
            buffer_caso1()            
            caso1(caso1_val[0],caso1_val[1],
            caso1_val[2],caso1_val[3],
            caso1_val[4],caso1_val[5],
            pot1,pot2);
        }                  
}
void buffer_caso1(){    
    caso1_val[0]=150;
    caso1_val[1]=300;
    caso1_val[4]=FALLA;
    caso1_val[5]=NOFALLA;
}
void caso2(){
    enviado=2;UART1_Write(enviado);delay_ms(100);
}
void caso3(){
    enviado=3; UART1_Write(enviado);delay_ms(100);
}