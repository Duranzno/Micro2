// TRANSMISOR
// DECLARACION DE VARIABLES
int cnt,escape =0;
unsigned opc=0;
unsigned short mot =1;
int pota1=0,pota2=0;
char readbuff[64],adcv[8];
char writebuff[64];
unsigned adc_valor,resistencia;
char menu[] = "\r Menu \n CASO 1 \n CASO 2 \n CASO 3 \x0d \x0a";
char Bien1[] = "\r Bienvenido al caso 1 \r" ,Bien2[] = "\n Bienvenido al caso 2",Bien3[] = "\n Bienvenido al caso 3 \r";
char caso1[] = "1",caso2[] = "2",caso3[] = "3",caso4[] = "4",caso5[] = "5",caso6[] = "6";
char POT1[] = "  POT 1: \r",POT2[] = "  POT 2: \r";
char MOT1[] = " MOT 1 ACT ",MOT2[] = " MOT 2 ACT ";
char error1[]= "\r POT 1 HA SUPERADO EL VOLTAJE 1.2 \n \r";
char error2[]= "\r POT 2 HA SUPERADO EL VOLTAJE 1.2 \n \r";
char Bi4[] = "\r \x0a 4 GUARDAR  \r" ;
char Bi5[] = "\r \x0a 5 MOSTRAR  \r" ;
char Bi6[] = "\r \x0a 6 SALIR  \r" ;
char Bien5[] = "\r Bienvenido al caso 5 \r";
unsigned PA,PB;
unsigned i=0,j=0;
int cont = 0;
char CL[]="\x0a";
char IL[]="\x0d";
char CL1[]="\n";
char IL1[]="\r";

void InitMCU()
    { ANSELC=0x0000; //Configuracionde E/S digitales
    ANSELD=0x0000; //Configuracionde E/S digitales
    ANSELB=0x0000; //Configuracionde E/S digitales
    //CONFIGURACION DEL PLL PARA ALCANZAR UNA VELOCIDAD DE 30MHZ
    PLLFBD = 58; //M = 60
    CLKDIVbits.PLLPOST= 0; // N1 = 2
    CLKDIVbits.PLLPRE= 0; // N2 = 2
    OSCTUN = 0;
    OSCCON=0x0301;
    while(OSCCONbits.COSC!= 0x3);
    //CONFIGURACION DEL PLL AUXILIAR PARA EL USB
    //SE REQUIEREN 48MHZ
    ACLKCON3 = 0x24C0;
    ACLKDIV3 = 0x7;
    ACLKCON3bits.ENAPLL = 1;
    while(ACLKCON3bits.APLLCK != 1);
}
void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT
{
     USB_Interrupt_Proc();
}
unsigned valor_adc;
char txt[15];
float volt;
unsigned short valor1,valor2;

unsigned parte_alta,parte_baja,resistencia_alamacenada;
char txt3[6];


void escribir_24lc02(unsigned char valor,unsigned char direccion)
{ 
    I2C1_Start(); // emitir señal de inicio I2C
    I2C1_Write(0xA0); // enviar byte a través de (dirección del dispositivo + W)
    I2C1_Write(direccion); // enviar byte (dirección de ubicación EEPROM)
    I2C1_Write(valor); // enviar datos (los datos se escriban)
    I2C1_Stop();
    Delay_ms(50);
}
unsigned leer_24lc02(unsigned char direccion)
{ 
    unsigned char valor;
    I2C1_Start(); // emitir señal de inicio I2C
    I2C1_Write(0xA0); // enviar byte a través de (dirección del dispositivo + W)
    I2C1_Write(direccion); // enviar byte (dirección de datos)
    I2C1_Restart(); // emitir señal repetida para iniciar I2C
    I2C1_Write(0xA1); // enviar byte (dirección del dispositivo + R)
    valor = I2C1_Read(1); // Leer los datos
    I2C1_Stop();
    Delay_ms(50);
    return valor;
}


void main(void)
{
ANSELBbits.ANSB0=1;
ANSELBbits.ANSB15=1;//rb0 y rb15 analogico
TRISBbits.TRISB0=1;
TRISBbits.TRISB15=1;//ENTRADAS ANALOGICAS ADC

//-----------MODO SPI---------------
ANSELD=0;
ANSELE =0;
TRISE=0;
SPI1_Init_Advanced(_SPI_MASTER,_SPI_8_BIT,_SPI_PRESCALE_SEC_8,_SPI_PRESCALE_PRI_64,_SPI_SS_DISABLE,_SPI_DATA_SAMPLE_MIDDLE,_SPI_CLK_IDLE_LOW,_SPI_ACTIVE_2_IDLE);
RPOR0bits.RP64R=5; //SDO1
RPOR8bits.RP99R=6; //SCK1
RPINR20bits.SDI1R=72; //SDI1
//--------------------

ADC1_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF); //Inicializaciondel convertidor ADC
InitMCU();
HID_Enable(&readbuff,&writebuff); //inicializamos en módulo usbhid
delay_ms(2000);

while(1)
    {
    while(!HID_Write(menu,64));
    while(!HID_Read());
    for(cnt=0;cnt<64;cnt++)
    writebuff[cnt]=readbuff[cnt];
    if(strcmp(readbuff,caso1)==0)
         {  while(!HID_Write(Bien1,64));
         opc = 49;
         SPI1_Write(opc);
         delay_ms(1000);

          delay_ms(500);
          while(escape ==0)
         { if(HID_Read())
           {escape++;
                  pota1=255;
                  valor1=pota1;
                  delay_ms(500);
                  SPI1_Write(valor1);
                  valor2=pota1;
                  SPI1_Write(valor2);
                  delay_ms(500);
                  intToStr(pota1,adcv);
                  while(!HID_Write(adcv,64));
           }

          if(mot ==1)
                        {
                             valor_adc=ADC1_Get_Sample(15);
                                     pota1=valor_adc;
                                     valor1=pota1;
                                      delay_ms(500);
                                     SPI1_Write(valor1);
                                     valor2=(pota1>>8);
                                     SPI1_Write(valor2);
                                     delay_ms(500);
                                     intToStr(pota1,adcv);
                                     while(!HID_Write("\r",64));
                                     while(!HID_Write("\x0a",64));
                                      while(!HID_Write(MOT1,64));
                                     while(!HID_Write(adcv,64));
                                     mot++;
                                     delay_ms(500);
                        }

           else if(mot == 2)
                 {
                    valor_adc=ADC1_Get_Sample(0);
                                     pota1=valor_adc;
                                     valor1=pota1;
                                      delay_ms(500);
                                     SPI1_Write(valor1);
                                     valor2=(pota1>>8);
                                     SPI1_Write(valor2);
                                     delay_ms(500);
                                     intToStr(pota1,adcv);
                                     while(!HID_Write(MOT2,64));
                                     while(!HID_Write(adcv,64));
                                     while(!HID_Write("\r",64));
                                     while(!HID_Write("\x0a",64));
                                     mot--;
                                     delay_ms(500);

                 }

         }
           escape=0;
         Delay_ms(1000);
      }
    else if (strcmp(readbuff,caso2)==0)
       {  I2C1_Init(100000); //inicializa i2c a 100Khz
         while(escape == 0 )
         {  while(!HID_Write("\r",64));
            while(!HID_Write("\x0a",64));
            while(!HID_Write(Bien2,64));
          opc = 50;
          SPI1_Write(opc);
          Delay_ms(1000);
          while(!HID_Write("\r",64));
          while(!HID_Write("\x0a",64));
          while(!HID_Write(Bi4,64));
          while(!HID_Write(Bi5,64));
          while(!HID_Write(Bi6,64));
          while(!HID_Write("\r",64));
          while(!HID_Write("\x0a",64));
          while(!HID_Read());
                 for(cnt=0;cnt<64;cnt++)
                 writebuff[cnt]=readbuff[cnt];
          if(strcmp(readbuff,caso4)==0)
          {  opc = 52;
             SPI1_Write(opc);
             while(!HID_Write("\r",64));
            while(!HID_Write("\x0a",64));
            while(!HID_Write("Ha guardado en la posicion ",64));
            Inttostr(cont,txt);
            while(!HID_Write(txt,64));
            while(!HID_Write("\r",64));
            while(!HID_Write("\x0a",64));

            adc_valor = ADC1_Get_Sample(0);
            resistencia=adc_valor;
            PA = adc_valor>>8;
            PB = adc_valor&0xFF;
            escribir_24lc02(PA,(0+i)); //guardando parte alta en posicion 0
            escribir_24lc02(PB,(1+i)); //guardando parte baja en posicion 1
            while(!HID_Write("\r",64));
            while(!HID_Write("\x0a",64));
            while(!HID_Write(POT1,64));
            WordToStr(resistencia,txt);
            while(!HID_Write(txt,64));
            
            adc_valor = ADC1_Get_Sample(15);
            resistencia=adc_valor;
            PA = adc_valor>>8;
            PB = adc_valor&0xFF;
            escribir_24lc02(PA,(10+i)); //guardando parte alta en posicion 0
            escribir_24lc02(PB,(11+i)); //guardando parte baja en posicion 1
            while(!HID_Write(POT2,64));
            WordToStr(resistencia,txt);
            while(!HID_Write(txt,64));
            while(!HID_Write("\r",64));
            while(!HID_Write("\x0a",64));
           i = i +2;
           cont++;
           if(cont == 5)cont=0;
           if(i == 10)i=0;
          }
          else if(strcmp(readbuff,caso5)==0)
           {    opc = 53;
                SPI1_Write(opc);
           for(j=0; j<10 ; j=j+2)
             {
               parte_alta= leer_24lc02((0+j));
               parte_baja= leer_24lc02((1+j));
               resistencia_alamacenada= (parte_alta<<8)+parte_baja;
               while(!HID_Write("\r",64));
               while(!HID_Write("\x0a",64));
               while(!HID_Write(POT1,64));
               WordToStr(resistencia_alamacenada,txt);
               while(!HID_Write(txt,64));
               delay_ms(50);

               parte_alta= leer_24lc02((10+j));
               parte_baja= leer_24lc02((11+j));
               resistencia_alamacenada= (parte_alta<<8)+parte_baja;
               while(!HID_Write(POT2,64));
               WordToStr(resistencia_alamacenada,txt);
               while(!HID_Write(txt,64));
               while(!HID_Write("\r",64));
               while(!HID_Write("\x0a",64));
               delay_ms(50);
             }
           }
          else if(strcmp(readbuff,caso6)==0) escape++;

          
          }
          
          escape =0;
       }
    else if (strcmp(readbuff,caso3)==0) 
      {  while(!HID_Write(Bien3,64));
         opc =51;
          SPI1_Write(opc);

      }
    Delay_ms(1000);
    }
}