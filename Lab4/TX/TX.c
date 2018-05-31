#include "hid.h"
#include "adc.h"
#include "config_TX.h"
#define ESC_key 254
#define PARTE_ALTA 0x3FC
#include "pwm_reloj.h"
#include "config_maestro.h"
//~~~~~~~~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void buffer_caso1();void caso2();void caso3();void caso1();void SPI_ESC();void caso5();void caso4();
unsigned leer_24lc256(unsigned char adres);
void escribir_24lc256(unsigned char valor,unsigned char adres);
void programar_Alarma();void programar_RTCC();void caso2_check();
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int i=0,j=0,escape=0,cnt,mot1=0,mot2=0,bandera1=0,bandera2=0,bandera4=0,bandera5=0,rpm1=0,rpm2=0;
unsigned char henhol=0; // varuable de posicion en la memoria 
unsigned valor=0,adres=0;
unsigned potval[5]={0,0,0,0,0};
float pantalla=0,voltaje=0;
char readbuff[64];
char writebuff[64];
unsigned short enviado=0;
unsigned caso1_val[6]={0,0,0,0,0,0},adc_value1=0,adc_value2=0,adc_value=0;
unsigned short  pote1=0,pote2=0,pote3=0;
char txt [30];
int value;
char txt4[5];char txt3[4];
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void timer1 () org 0x1A {IFS0bits.T1IF=0;

   if (bandera2==1)
      write("Voltaje en limite superior");
   else if (bandera2==2)
      write("Voltaje en limite inferior");
   else if (bandera2==3)
   write("Voltaje normal");
    adc_value = ADC2_Get_Sample(14);
    pantalla=adc_value*0.0034;
 sprintf(txt,"Voltaje=%.3f",pantalla);
 write(txt);
 space2();
 space2();
 space2();
 space2();
        enviado=bandera2;
    SPI1_Write(enviado);
}
void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT{USB_Interrupt_Proc();}      
void INT_Inicio_Conversion_T3 () org 0x24 {IFS0bits.T3IF=0;
   adc_value1 = ADC1_Get_Sample(0);
    delay_ms(10);
    
    adc_value2 = ADC1_Get_Sample(3);
    pote1=adc_value1>>2;
    pote2=adc_value2>>2;
    delay_ms(10);
    enviado=pote2;
    SPI1_Write(enviado);    delay_ms(10);
    enviado=pote1;
    SPI1_Write(enviado);    delay_ms(10);

    bandera1++;
}//inicializa conversion del adc
void INT_ADC() org 0x2E {
    IFS0bits.AD1IF=0;
    adc_value1=ADC1BUF0;
    adc_value2=ADC1BUF1;
    pote1=adc_value1>>2;
    pote2=adc_value2>>2;
    delay_ms(5);
    enviado=pote2;
    SPI1_Write(enviado);    delay_ms(10);
    enviado=pote1;
    SPI1_Write(enviado);    delay_ms(10);

    bandera1++;
}
void interupcion_ext1() org 0x3C  {IFS1bits.INT1IF=0;rpm1++;}
void interupcion_ext2() org 0x4E  {IFS1bits.INT2IF=0;rpm2++;}
void timer7 () org 0x74 {
  IFS3bits.T7IF=0;
  caso1_val[0]=rpm1*75;
  caso1_val[1]=rpm2*75;
  rpm1=0;
  rpm2=0;
  adc_value = ADC2_Get_Sample(14);
  logd(adc_value);
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
  config_pin();
  config_INT();
  I2C1_Init(100000); //inicializa i2c a 100Khz
  config_timer1();
  config_Pwm_reloj();
  InitMCU();
  config_timer3();
  // config_adc();
  ADC1_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF);
  ADC2_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF); 
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
    for(cnt=0;cnt<64;cnt++) {writebuff[cnt]=readbuff[cnt];}
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
      T1CONbits.TON=0;
    }
    else if(strcmp(readbuff,caso_3)==0){//CASE 3
      write("Bienvenido al Caso 3");
      enviado=3;
      SPI1_Write(enviado);
      caso3();
    }
    else if(strcmp(readbuff,caso_4)==0){//CASE D
      enviado=4;
      SPI1_Write(enviado);
      bandera4=0;
      caso4();
    }
    else if(strcmp(readbuff,caso_5)==0){//CASE D
      enviado=5;
      SPI1_Write(enviado);
      bandera5=0;
      caso5();
    }
    else if(strcmp(readbuff,"P")==0){//CASE D
      unsigned char as;
      as=leer_24lc256(1);
      sprintf(txt,"se leyo %u",as);
      write(txt);
      escribir_24lc256(42,1);
      as=0;
      as=leer_24lc256(1);
      sprintf(txt,"se leyo %u",as);
      write(txt);
    }
  Delay_ms(1000);
  escape=0;
  }
}
void caso1(){
  bandera1=0;
 //  AD1CON1bits.ADON=1;// Se act el modulo
  T3CONbits.TON=1; // activa timer 3 para inicio de conver.
  //hid_caso_1(caso1_val[0],caso1_val[1],caso1_val[2],caso1_val[3],caso1_val[4],caso1_val[5],pote1,pote2);
  delay_ms(150);
 // config_velocidad ();
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
T1CONbits.TON=1;
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
T1CONbits.TON=0;
}
void caso3(){
  hid_caso_3();
  delay_ms(100);
  while(escape==0){
    while(!HID_Read());
      for(cnt=0;cnt<64;cnt++) {writebuff[cnt]=readbuff[cnt]; }
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

void caso2_check(){
  adc_value = ADC2_Get_Sample(14);
  if(CM3CONbits.COUT==0){
     bandera2=1;
  }
  else if(CM1CONbits.COUT==0){
     bandera2=2;
  }
  else if(CM1CONbits.COUT==1&&CM3CONbits.COUT==1) {
  bandera2=3;


  }    
}

void escribir_24lc256(unsigned char valor,unsigned char adres){
  I2C1_Start(); // emitir señal de inicio I2C
  I2C1_Write(0xA0); // enviar byte a través de (dirección del dispositivo + W)
  I2C1_Write(123); // direccion sin usar
  I2C1_Write(adres); // enviar byte (dirección de ubicación EEPROM)
  I2C1_Write(valor); // enviar datos (los datos se escriban)
  I2C1_Stop();
  Delay_ms(100);

}
unsigned  leer_24lc256(unsigned char adres){
  unsigned char valor;
  I2C1_Start(); // emitir señal de inicio I2C
  I2C1_Write(0xA0); // enviar byte a través de (dirección del dispositivo + W)
  I2C1_Write(123); // enviar byte (dirección de datos)
  I2C1_Write(adres); // enviar byte (dirección de datos)
  I2C1_Restart(); // emitir señal repetida para iniciar I2C
  I2C1_Write(0xA1); // enviar byte (dirección del dispositivo + R)
  valor = I2C1_Read(1); // Leer los datos
  I2C1_Stop();
  Delay_ms(50);
  return valor;
}
void guardado_int1( unsigned  adc_valor, unsigned char adre){
  unsigned char tmp;
  if(adre<10){
  inttostr(adre,txt);
 // write(txt);
  inttostr(adc_valor,txt);
  //write("adc_valor ");
  //write(txt);
  tmp=(adc_valor & 0x0300)>>8;
  escribir_24lc256(tmp,adre); //guardando parte alta en posicion 0
  
   tmp=leer_24lc256( adre);
  inttostr(tmp,txt);
 //write("adc_valor>>8 ");
  //write(txt);
  delay_ms(50)  ;

 adre++;
 tmp=(adc_valor & 0x00FF);
  escribir_24lc256(tmp,adre); //guardando parte alta en posicion 0
 
  tmp=leer_24lc256( adre);
  //write("adc_valor&0xFF ");
  inttostr(tmp,txt);
  //write(txt);
  }else{adre=0;}
}

void valores (){
  //Paso los valores de la memoria en 16 bits al array potval[5]
  unsigned char parte_baja,parte_alta,k;
  adres=0;
  while(adres<10){
    parte_alta=leer_24lc256(adres);
    adres++;
    parte_baja=leer_24lc256(adres);
    adres++;
    
    //sprintf(txt_caso4,"Alta:%u, Baja:%u",parte_alta,parte_baja); write(txt_caso4);
    potval[adres-2]=(parte_alta<<8)+parte_baja;
    //sprintf(txt_caso4,"potval:%u",potval[adres-2]); write(txt_caso4);
  }

  delay_ms(80);
  write("sali de valores");
}
unsigned prueba=0,prueba2=0;
//~~~~~~~~~~~~~~~~~~~~~~~Caso 4~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 float fpot[5];
void caso4() {
  henhol=0;
    //T1CONbits.TON=1;

    while (escape==0){
      adc_value = ADC2_Get_Sample(14);
      voltaje=adc_value*0.0034;      
      valores();
      for(i=0;i<10;i++){
        fpot[i]=potval[i]*0.0034;
      }
      sprintf(txt_caso41,"V1:%.3f,  V2:%.3f, V3:%.3f",fpot[0],fpot[2],fpot[4]);
      delay_ms(50);
      sprintf(txt_caso42,"V4:%.3f,V5:%.3f",fpot[6],fpot[8]);
      delay_ms(50);
      hid_caso_4(voltaje,henhol); 
    // bandera4++;
    escape=0;
    while(!HID_Read());

    for(cnt=0;cnt<64;cnt++) { writebuff[cnt]=readbuff[cnt];}
    if(strcmp(readbuff,"b")==0){//CASE 4
    write("nada");
    }
    else if(strcmp(readbuff,"T")==0){//CASE 2
      write("actualizar");
      adc_value = ADC2_Get_Sample(14);
      escape=0;
      }  
      else   if(strcmp(readbuff,"K")==0){//CASE 4
      if (henhol==10){henhol=0;}
      adc_value = ADC2_Get_Sample(14);
      guardado_int1(adc_value,henhol);
      henhol+=2;
      escape=0;
    }
    else {escape++;}
    delay_ms(300);
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~Caso 5~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void update_hid(){
  sprintf(buffer,"%u:%u:%u del dia %u del mes %u,del ano%u",u_hora[HOR],u_hora[MIN],u_hora[SEG],u_hora[DIA],u_hora[MES],u_hora[ANO]);
  logd(buffer);
}
void caso5(){
  while (escape==0){
    hid_caso_5();
    while(!HID_Read());
    for(cnt=0;cnt<64;cnt++) { writebuff[cnt]=readbuff[cnt];}
   
    if(strcmp(readbuff,"X")==0){
      //Iniciar Reloj
      enviado="X";
      SPI1_Write(enviado);
      logd("Ver glcd pantalla");
      //update_hid()
      //Delay_ms(3000);
      escape=0;
    }else if(strcmp(readbuff,"Y")==0){
      enviado='Y';
      SPI1_Write(enviado);
      programar_RTCC();
      escape=0;
    }else if(strcmp(readbuff,"U")==0){
      enviado='U';
      SPI1_Write(enviado);
        logd("RELOJ ACTUALIZADO");
      escape=0;
    }
    else  if(strcmp(readbuff,"Z")==0){
      enviado='Z';
      SPI1_Write(enviado);
      programar_Alarma();
    }else {escape++;
    enviado=254;
    SPI1_Write(enviado);
    }
    delay_ms(300);
  }
}

//Configutacion Hora
//usar programar_RTCC, programar Alarma;

int update_hid_hora(){
  int i,j;
  while(!HID_Read()); for(cnt=0;cnt<64;cnt++) {writebuff[cnt]=readbuff[cnt];}
  i=readbuff[0]-'0';
  j=readbuff[1]-'0';
  return (j+i*10);
}
void hid_configuracion_hora(){
  sprintf(buffer,"1) SEGUNDO   (0-59)          %u",u_hora[SEG]);write(buffer);
  sprintf(buffer,"2) MINUTO    (0-59)          %u",u_hora[MIN]);write(buffer);
  sprintf(buffer,"3) HORA      (0-23)          %u",u_hora[HOR]);write(buffer);
  sprintf(buffer,"4) DIA       (1-28/29/30/31) %u",u_hora[DIA]);write(buffer);
  sprintf(buffer,"5) MES       (1-12)          %u",u_hora[MES]);write(buffer);
  sprintf(buffer,"6) YEAR      (0-99)          %u",u_hora[ANO]);write(buffer);
}
void programar_RTCC(){
  int i;
  for(i=0;i<6;i++){u_hora[i]=0;}

  hid_configuracion_hora();
  for(i=0;i<6;i++){
    sprintf(buffer,"Modificando %d",i+1);write(buffer);

    u_hora[i]=update_hid_hora();
    hid_configuracion_hora();
    enviado=u_hora[i];
    SPI1_Write(enviado);
    }  
    write("Mande la vaina");

}
//Alarma
void programar_Alarma(){
   hid_config_al();
  RTCBandera=0;
  while(!HID_Read());
            for(cnt=0;cnt<64;cnt++) {writebuff[cnt]=readbuff[cnt];}
            if(strcmp(readbuff,caso_1)==0){//CASE 1
              write("Alarma 30");
              enviado=1;
              SPI1_Write(enviado);
            }
            else if(strcmp(readbuff,caso_2)==0){//CASE 2
              CASO_ALARMA=RTCC_60;
              write("Alarma 60");
              enviado=2;
              SPI1_Write(enviado);
            }
            else if(strcmp(readbuff,caso_3)==0){//CASE 3
              CASO_ALARMA=RTCC_90;
              write("Alarma 90");
              enviado=3;
              SPI1_Write(enviado);
            }
            else if(strcmp(readbuff,caso_4)==0){//CASE 3
              CASO_ALARMA=RTCC_120;
              write("Alarma 120");
              enviado=4;
              SPI1_Write(enviado);
            }
}