#include "hid.h"
#include "adc.h"
#include "config_TX.h"
#define ESC_key
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void buffer_caso1();void caso2();void caso3();void caso1();void UART_ESC();
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int i=0,j=0,escape=0,cnt,mot1=0,mot2=0,bandera1=0;
float pantalla=0;
char readbuff[64];
char writebuff[64];
unsigned short enviado=0;
unsigned caso1_val[6]={0,0,0,0,0,0};
unsigned short  adc_value1,adc_value2,pote1=0,pote2=0;
char txt [30];
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void timer8 () org 0x7A {
//         IFS3bits.T8IF=0;
//         LATFBITS.LATF5=~LATFBITS.LATF5;
// }
void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT{
  USB_Interrupt_Proc();
}
void INT_Inicio_Conversion_T3 () org 0x24 {IFS0bits.T3IF=0;}//inicializa conversion del adc
void INT_ADC() org 0x2E {
    IFS0bits.AD1IF=0;
    adc_value1=(ADC1BUF0);
    adc_value2=ADC1BUF1;
    pote1=(adc_value1>>8);
    pote2=(adc_value2>>8);
    delay_ms(10);

    enviado=pote1;
    UART1_Write(enviado);    delay_ms(10);
    enviado=pote2;
    UART1_Write(enviado);    delay_ms(10);
    bandera1++;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main() {
    config_INT();//config_timer8();
    InitMCU();
    config_timer3();
    config_adc();
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
    bandera1=0;
    AD1CON1bits.ADON=1;// Se act el modulo
    T3CONbits.TON=1; // activa timer 3 para inicio de conver.
    hid_caso1(caso1_val[0],caso1_val[1],caso1_val[2],caso1_val[3],caso1_val[4],caso1_val[5],pote1,pote2);
    enviado=1;
    UART1_Write(enviado);
    delay_ms(150);
    while(escape==0){
        if (bandera1==3) {
        buffer_caso1();
            hid_caso1(caso1_val[0],caso1_val[1],
            caso1_val[2],caso1_val[3],
            caso1_val[4],caso1_val[5],
            pote1,pote2);
            bandera1=0;
    if(adc_value1<512){
        caso1_val[2]=IZQ;}
      else {
        caso1_val[2]=DER;}
      if(adc_value2<512){
        caso1_val[3]=IZQ;}
      else {
        caso1_val[3]=DER;}
            }
        if(HID_Read()){
            escape++;UART_ESC();}
        else{
            //ORDEN RPN1,RPN2,DER(0)/IZQ(1)
            //FALLA(1)/NOFALLA(0);

        }
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
    hid_caso3();
    enviado=3;
    UART1_Write(enviado);
    delay_ms(100);
    while(escape==0){
        while(!HID_Read());
            for(cnt=0;cnt<64;cnt++) {
                    writebuff[cnt]=readbuff[cnt];
            }
            switch(readbuff[0]){
                case '0':enviado=0; caso3_1[28]=readbuff[0]; hid_caso3();  UART1_Write(enviado);break;
                case '1':enviado=1; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case '2':enviado=2; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case '3':enviado=3; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case '4':enviado=4; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case '5':enviado=5; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case '6':enviado=6; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case '7':enviado=7; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case '9':enviado=8; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case '0':enviado=9; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case 'A':case 'a':enviado=10; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case 'B':case 'b':enviado=11; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case 'C':case 'c':enviado=12; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case 'D':case 'd':enviado=13; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case 'E':case 'e':enviado=14; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                case 'F':case 'f':enviado=15; caso3_1[28]=readbuff[0]; hid_caso3(); UART1_Write(enviado);break;
                default:escape++;UART_ESC();break;
            }
    }
}
void UART_ESC(){
    delay_ms(10);
    enviado=254;
    UART1_Write(enviado);
}