#include "hid.h"
#include "adc.h"
#include "config_TX.h"
#define ESC_key 254
#define PARTE_ALTA 0x3FC
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void caso2();void caso3();void caso1();void caso4();
void buffer_caso2();void buffer_caso1();
void UART_ESC();
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int escape=0,cnt,mot1=0,mot2=0,bandera1=0,bandera2=0,rpm1=0,rpm2=0,enviado=0;
unsigned short  adc_value1,adc_value2,pote1=0,pote2=0,pote3=0;
unsigned caso1_val[6]={0,0,0,0,0,0};
float pantalla=0;
char readbuff[64];
char writebuff[64];
char txt [30];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void timer8 () org 0x7A {
//         IFS3bits.T8IF=0;
//         LATFBITS.LATF5=~LATFBITS.LATF5;
// }
void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT{
  //USB_Interrupt_Proc();
}
void INT_Inicio_Conversion_T3 () org 0x24 {IFS0bits.T3IF=0;}//inicializa conversion del adc
void INT_ADC() org 0x2E {
    IFS0bits.AD1IF=0;
    adc_value1=ADC1BUF0;
    adc_value2=ADC1BUF1;
    pote1=adc_value1;
    pote2=adc_value2;
    delay_ms(10);
    enviado=pote2;
    //UART1_Write(enviado);    delay_ms(10);
    enviado=pote1;
    //UART1_Write(enviado);    delay_ms(10);
    bandera1++;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main() {
    //config_USB();
    config_IO();led_switch();
    config_INT();//config_timer8();
    config_adc();config_timer3();
    config_vref();    
    UART1_Init(9600);
    HID_Enable(&readbuff,&writebuff); //inicializamos en módulo usb hid
    while(1){
            hid_menu();
            while(!HID_Read());
            for(cnt=0;cnt<64;cnt++) {
                    writebuff[cnt]=readbuff[cnt];
            }
            if(strcmp(readbuff,caso_1)==0){//CASE 1
                    caso1();
            }
            else if(strcmp(readbuff,caso_2)==0){//CASE 2
                    caso2();
            }
            else if(strcmp(readbuff,caso_3)==0){//CASE 3
                    caso3();
            }
            else if(strcmp(readbuff,caso_4)==0){//CASE 3
                    caso4();
            }
    Delay_ms(1000);
    escape=0;
    }
}
void caso1(){  
    bandera1=0;
    AD1CON1bits.ADON=1;// Se act el modulo
    T3CONbits.TON=1; // activa timer 3 para inicio de conver.
    enviado=1;
    //UART1_Write(enviado);
    delay_ms(150);
    while(escape==0){
        if (bandera1==3) {
                buffer_caso1();
                hid_caso_1(caso1_val[0],caso1_val[1],
                caso1_val[2],caso1_val[3],
                caso1_val[4],caso1_val[5],
                pote1,pote2);
                bandera1=0;
            
        }
        if(HID_Read()){
            escape++;UART_ESC();}
        
      }
    AD1CON1bits.ADON=0;// Se act el modulo
    T3CONbits.TON=0;
    T7CONbits.TON=0;
    IPC5BITS.INT1IP=0;
    IPC7bits.INT2IP=0;
}
void buffer_caso1(){ 
    if(pote1<128){caso1_val[2]=IZQ;}
     else {caso1_val[2]=DER;}
    if(pote2<128){caso1_val[3]=IZQ;}
     else {caso1_val[3]=DER;}   
    caso1_val[4]=FALLA;
    caso1_val[5]=FALLA;
}

void caso2(){
    T7CONbits.TON=0;
    config_CM();
    enviado=2;
    //UART1_Write(enviado);
    delay_ms(100);
    escape=0;
    while(escape==0){
        if(HID_Read()){
            escape++;UART_ESC();}
        else{
            buffer_caso2();
        }
    }
}
void caso3(){
    hid_caso_3();
    enviado=3;
    UART1_Write(enviado);
    delay_ms(100);
    while(escape==0){
        while(!HID_Read());
            for(cnt=0;cnt<64;cnt++) {
                    writebuff[cnt]=readbuff[cnt];
            }
            switch(readbuff[0]){
                case '0':enviado=0; caso3_1[28]=readbuff[0]; hid_caso_3();  UART1_Write(enviado);break;
                case '1':enviado=1; caso3_1[28]=readbuff[0]; hid_caso_3(); UART1_Write(enviado);break;
                case '2':enviado=2; caso3_1[28]=readbuff[0]; hid_caso_3(); UART1_Write(enviado);break;
                case '3':enviado=3; caso3_1[28]=readbuff[0]; hid_caso_3(); UART1_Write(enviado);break;
                case '4':enviado=4; caso3_1[28]=readbuff[0]; hid_caso_3(); UART1_Write(enviado);break;
                case '5':enviado=5; caso3_1[28]=readbuff[0]; hid_caso_3(); UART1_Write(enviado);break;
                case '6':enviado=6; caso3_1[28]=readbuff[0]; hid_caso_3(); UART1_Write(enviado);break;
                case '7':enviado=7; caso3_1[28]=readbuff[0]; hid_caso_3(); UART1_Write(enviado);break;
                case '8':enviado=8; caso3_1[28]=readbuff[0]; hid_caso_3(); UART1_Write(enviado);break;
                case '9':enviado=9; caso3_1[28]=readbuff[0]; hid_caso_3(); UART1_Write(enviado);break;
                case 'A':case 'a':enviado=10; caso3_1[28]='A'; hid_caso_3(); UART1_Write(enviado);break;
                case 'B':case 'b':enviado=11; caso3_1[28]='B'; hid_caso_3(); UART1_Write(enviado);break;
                case 'C':case 'c':enviado=12; caso3_1[28]='C'; hid_caso_3(); UART1_Write(enviado);break;
                case 'D':case 'd':enviado=13; caso3_1[28]='D'; hid_caso_3(); UART1_Write(enviado);break;
                case 'E':case 'e':enviado=14; caso3_1[28]='E'; hid_caso_3(); UART1_Write(enviado);break;
                case 'F':case 'f':enviado=15; caso3_1[28]='F'; hid_caso_3(); UART1_Write(enviado);break;
                default:escape++;UART_ESC();break;
            }
    }
}
void UART_ESC(){
    delay_ms(10);
    enviado=ESC_key;
    //UART1_Write(enviado);
}


void buffer_caso2(){
    if(CM3CONbits.COUT==0){
        if (bandera2==0){
            bandera2=1;
            write("Voltaje en limite superior");
            enviado=1;
            //UART1_Write(enviado);
            //space(8)
            }

    }else if(CM1CONbits.COUT==0){
        if (bandera2==0) {
            bandera2=2;
            write("Voltaje en limite inferior");
             enviado=2;
            //UART1_Write(enviado);
            space(8);
        }
    }else if(CM1CONbits.COUT==1&&CM3CONbits.COUT==1) {
        if (bandera2<3&&bandera2>0) {
            bandera2=3;
            write("Voltaje Normal");
            enviado=3;
            //UART1_Write(enviado);
            space(8);
        }
        else  bandera2=0;
    }
}
void caso4(){}