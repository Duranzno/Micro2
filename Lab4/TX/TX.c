#include "hid.h"
#include "adc.h"
#include "config_TX.h"
#define ESC_key 254
#define PARTE_ALTA 0x3FC
#include "config_maestro.h"
#include "memoria_i2d.h"
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void buffer_caso1();void caso2();void caso3();void caso1();void SPI_ESC();
void caso2_check();
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int i=0,j=0,escape=0,cnt,mot1=0,mot2=0,bandera1=0,bandera2=0,rpm1=0,rpm2=0;
float pantalla=0;
char readbuff[64];
char writebuff[64];
unsigned short enviado=0;
unsigned caso1_val[6]={0,0,0,0,0,0},adc_value1=0,adc_value2=0;
unsigned short  pote1=0,pote2=0,pote3=0;
char txt [30];

void cambio_led () {
   LATFBITS.LATF5=~LATFBITS.LATF5;

}
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
    adc_value1=ADC1BUF0;
    adc_value2=ADC1BUF1;
    pote1=adc_value1;
    pote2=adc_value2;

    delay_ms(10);
    enviado=pote2;
    SPI1_Write(enviado);    delay_ms(10);
    enviado=pote1;
    SPI1_Write(enviado);    delay_ms(10);
    
    bandera1++;
}


 void interupcion_ext1() org 0x3C {
    IFS1bits.INT1IF=0;
    rpm1++;

 }
  void interupcion_ext2() org 0x4E {
    IFS1bits.INT2IF=0;
    rpm2++;
 }
 void timer7 () org 0x74 {
  IFS3bits.T7IF=0;
  caso1_val[0]=rpm1*75;
  caso1_val[1]=rpm2*75;
  rpm1=0;
  rpm2=0;
}


void Error_SPI() org 0x26{
        IFS0bits.SPI1EIF=0;
          write("Error");
                 delay_ms(3000);

}
void SPI() org 0x28{
        IFS0bits.SPI1IF=0;
            write("ALGUN DATO SE TRANSMITIO");
                 delay_ms(3000);

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main() {
    // cambio_led();
    config_INT();//config_timer8();
    InitMCU();
   	config_timer3();
    config_adc();
   	config_pin();
   	HID_Enable(&readbuff,&writebuff); //inicializamos en módulo usb hid
	SPI1_Init_Advanced(_SPI_MASTER,_SPI_8_BIT,_SPI_PRESCALE_SEC_8,
	_SPI_PRESCALE_PRI_64,_SPI_SS_DISABLE,_SPI_DATA_SAMPLE_MIDDLE,
	_SPI_CLK_IDLE_LOW,_SPI_ACTIVE_2_IDLE);
	RPOR0bits.RP64R=5; //SDO1
	RPOR8bits.RP99R=6; //SCK1
	RPINR20bits.SDI1R=72; //SDI1
    while(1){
            menu2();
            while(!HID_Read());
            for(cnt=0;cnt<64;cnt++) {
                    writebuff[cnt]=readbuff[cnt];
            }
            if(strcmp(readbuff,caso_1)==0){//CASE 1
                 write("Bienvenido al Caso 1");
                 	enviado=1;
                	SPI1_Write(enviado);
                    caso1();
            }
            else if(strcmp(readbuff,caso_2)==0){//CASE 2
                    write("Bienvenido al Caso 2");
            		enviado=2;
                	SPI1_Write(enviado);
                  	caso2();
            }
            else if(strcmp(readbuff,caso_3)==0){//CASE 3
            		write("Bienvenido al Caso 3");
                	enviado=3;
                	SPI1_Write(enviado);
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
    //hid_caso_1(caso1_val[0],caso1_val[1],caso1_val[2],caso1_val[3],caso1_val[4],caso1_val[5],pote1,pote2);
    delay_ms(150);
    config_velocidad ();
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
            escape++;SPI_ESC();}
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
    delay_ms(100);
    escape=0;
    while(escape==0){
        if(HID_Read()){
            escape++;SPI_ESC();}
        else{
            caso2_check();
        }
    }
}
void caso3(){
    hid_caso_3();
    delay_ms(100);
    while(escape==0){
        while(!HID_Read());
            for(cnt=0;cnt<64;cnt++) {
                    writebuff[cnt]=readbuff[cnt];
            }
            switch(readbuff[0]){
                case '0':enviado=0; caso3_1[28]=readbuff[0]; hid_caso_3();  SPI1_Write(enviado);break;
                case '1':enviado=1; caso3_1[28]=readbuff[0]; hid_caso_3(); SPI1_Write(enviado);break;
                case '2':enviado=2; caso3_1[28]=readbuff[0]; hid_caso_3(); SPI1_Write(enviado);break;
                case '3':enviado=3; caso3_1[28]=readbuff[0]; hid_caso_3(); SPI1_Write(enviado);break;
                case '4':enviado=4; caso3_1[28]=readbuff[0]; hid_caso_3(); SPI1_Write(enviado);break;
                case '5':enviado=5; caso3_1[28]=readbuff[0]; hid_caso_3(); SPI1_Write(enviado);break;
                case '6':enviado=6; caso3_1[28]=readbuff[0]; hid_caso_3(); SPI1_Write(enviado);break;
                case '7':enviado=7; caso3_1[28]=readbuff[0]; hid_caso_3(); SPI1_Write(enviado);break;
                case '8':enviado=8; caso3_1[28]=readbuff[0]; hid_caso_3(); SPI1_Write(enviado);break;
                case '9':enviado=9; caso3_1[28]=readbuff[0]; hid_caso_3(); SPI1_Write(enviado);break;
                case 'A':case 'a':enviado=10; caso3_1[28]='A'; hid_caso_3(); SPI1_Write(enviado);break;
                case 'B':case 'b':enviado=11; caso3_1[28]='B'; hid_caso_3(); SPI1_Write(enviado);break;
                case 'C':case 'c':enviado=12; caso3_1[28]='C'; hid_caso_3(); SPI1_Write(enviado);break;
                case 'D':case 'd':enviado=13; caso3_1[28]='D'; hid_caso_3(); SPI1_Write(enviado);break;
                case 'E':case 'e':enviado=14; caso3_1[28]='E'; hid_caso_3(); SPI1_Write(enviado);break;
                case 'F':case 'f':enviado=15; caso3_1[28]='F'; hid_caso_3(); SPI1_Write(enviado);break;
                default:escape++;SPI_ESC();break;
            }
    }
}
void SPI_ESC(){
    delay_ms(10);
    enviado=ESC_key;
    SPI1_Write(enviado);
}
int value;
char txt4[5];char txt3[4];
void floattostr3(const float valor,char *output) {
        int i11,i2,d1,d2,d3;
        float n0;
                char txt2[15];
        i11 = valor*0.1;
        i2 = valor-(10*i11);
        bytetostr(i2, txt2);
        txt4[0]= ltrim(txt2);
        txt4[1]='.';
        n0 = (valor - 10*i11 - i2)*10000;
        d1 = n0/1000;
        bytetostr(d1, txt2);
        txt4[2]=ltrim(txt2);
        d2 = (n0 - d1*1000)/100;
        bytetostr(d2, txt2);
        txt4[3]=ltrim(txt2);
        d3 = (n0 - d1*1000 - d2*100)/10;
        bytetostr(d3, txt2);
        txt4[4]=ltrim(txt2);
        output[0]=txt4[0];
        output[1]=txt4[1];
        output[2]=txt4[2];
        output[3]=txt4[3];
        output[4]=txt4[4];
       }
void caso2_check(){
    if(CM3CONbits.COUT==0){
        if (bandera2==0){
            bandera2=1;
            write("Voltaje en limite superior");
            enviado=1;
            SPI1_Write(enviado);
                space2();
                space2();
                 space2();
                 space2();
            }

    }else if(CM1CONbits.COUT==0){
        if (bandera2==0) {
            bandera2=2;
            write("Voltaje en limite inferior");
             enviado=2;
            SPI1_Write(enviado);
              space2();
                 space2();
                 space2();
                 space2();
        }
    }else if(CM1CONbits.COUT==1&&CM3CONbits.COUT==1) {
        if (bandera2<3&&bandera2>0) {
            bandera2=3;
            write("Voltaje Normal");
            enviado=3;
            SPI1_Write(enviado);
              space2();
                 space2();
                 space2();
                 space2();
        }
        else  bandera2=0;
    }


    
}