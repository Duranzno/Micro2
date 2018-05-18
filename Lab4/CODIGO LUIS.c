//TRANSMISOR
char readbuff[64];
char writebuff[64];
char menu[]="Opcion: ", op1[]="Caso 1", op2[]="Caso 2", op3[]="Caso 3", normal1[]="Volt de pot1 Normal", normal2[]="Volt de pot2 Normal", sup1[]="Volt de pot1 superado", sup2[]="Volta de pot2 superado";
float valor_adc,valor_adc2,voltaje1,voltaje2;
unsigned t=0, t2=0;
int cnt, opc=0;

void InitMCU()
{
  CORCONbits.IPL3=0; //la interrupción de la CPU es de nivel 7 o menor
  SRbits.IPL=0; //interrupción de la CPU es de nivel 0
  INTCON2bits.GIE=1;  //Habilito interrupciones globales
  INTCON1bits.NSTDIS=0; //interrupción anidadas activada
  //Configuracion de Puertos
  ANSELC=0x0000; //Configuracionde E/S digitales
  ANSELD=0x0000; //Configuracionde E/S digitales
  ANSELE=0; //Configuracionde E/S digitales
  ANSELB=0x8001; //Configuracionde E/S digitales
  TRISEbits.TRISE5=0;
  PORTEbits.RE5=0;
  TRISEbits.TRISE6=0;
  PORTEbits.RE6=0;
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
  ADC1_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF); //Inicializacion del convertidor ADC
  //Configuracion del Comparador 1
  CM1CONbits.CREF=0; // referencia externa en el pin inversor
  CM1CONbits.CCH=3; // referencia interna en el pin no inversor
  CVRCONbits.BGSEL=0; // referencia interna de 1.2v en el pin no inversor
  //Configuracion del Comparador 2
  CM2CONbits.CREF=0; // referencia externa en el pin inversor
  CM2CONbits.CCH=3; // referencia interna en el pin no inversor
  //Configuracion UART
  UART1_Init(9600);
  RPOR0bits.RP64R=1; //U1TX
  RPINR18bits.U1RXR=72; //U1RX
}


void IntUSB1() iv IVT_ADDR_USB1INTERRUPT
{
USB_Interrupt_Proc();
}

void main(void)
{
 InitMCU();
 HID_Enable(&readbuff,&writebuff); //inicializamos en módulo usbhid
 delay_ms(2000);
 while(1)
 {
 switch(opc)
 {
            case 0:
                   PORTEbits.RE5=~PORTEbits.RE5;
                   delay_ms(5000);
                   while(!HID_Write(menu,64));
                   delay_ms(1000);
                   while(!HID_Read());
                   for(cnt=0;cnt<64;cnt++)
                   writebuff[cnt]=readbuff[cnt];
                   PORTEbits.RE6=~PORTEbits.RE6;
                   while(!HID_Write(&writebuff,64));
                   delay_ms(1000);
                   PORTEbits.RE5=~PORTEbits.RE5;
                   opc=writebuff[0]-48;
                   break;

            case 1:
                   while(!HID_Write(op1,64));
                   Delay_ms(1000);
                   while(!HID_Read())
                   {
                   t=ADC1_Get_Sample(0);
                   UART1_Write(t);
                   Delay_ms(100);
                   t=(t>>8);
                   UART1_Write(t);
                   Delay_ms(100);
                   t2=ADC1_Get_Sample(15);
                   UART1_Write(t2);
                   Delay_ms(100);
                   t2=(t2>>8);
                   UART1_Write(t2);
                   Delay_ms(100);
                   }
                   opc=0;
                   break;

            case 2:
                    while(!HID_Write(op2,64));
                    Delay_ms(3000);
                    opc=0;
                    break;
                    
            case 3:
                    CM1CONbits.CON=1; // comparador habilitado
                    while(!HID_Write(op3,64));
                    while(!HID_Read())
                    {
                     PORTEbits.RE5=~PORTEbits.RE5;
                     valor_adc=ADC1_Get_Sample(0);
                     voltaje1=valor_adc*0.0031964;
                     FloatToStr(voltaje1,writebuff);
                     writebuff[5]='_';
                     writebuff[6]='V';
                     writebuff[7]='o';
                     writebuff[8]='l';
                     writebuff[9]='t';
                     writebuff[10]=' ';
                     writebuff[11]='\0';
                     if(valor_adc<312)
                     {
                     writebuff[5]='_';
                     writebuff[6]='m';
                     writebuff[7]='V';
                     writebuff[8]='o';
                     writebuff[9]='l';
                     writebuff[10]='t';
                     writebuff[11]=' ';
                     writebuff[12]='\0';
                     }
                     while(!HID_Write(&writebuff,64));
                     Delay_ms(1000);
                     valor_adc2=ADC1_Get_Sample(15);
                     voltaje2=valor_adc2*0.0031964;
                     FloatToStr(voltaje2,writebuff);
                     writebuff[5]='_';
                     writebuff[6]='V';
                     writebuff[7]='o';
                     writebuff[8]='l';
                     writebuff[9]='t';
                     writebuff[10]=' ';
                     writebuff[11]='\0';
                     if(valor_adc2<312)
                     {
                     writebuff[5]='_';
                     writebuff[6]='m';
                     writebuff[7]='V';
                     writebuff[8]='o';
                     writebuff[9]='l';
                     writebuff[10]='t';
                     writebuff[11]=' ';
                     writebuff[12]='\0';
                     }
                     while(!HID_Write(&writebuff,64));
                     Delay_ms(1000);
                     if(CMSTATbits.C1OUT==0)
                     {
                      while(!HID_Write(normal1,64));
                      Delay_ms(1000);
                     }
                     else 
                     {
                      while(!HID_Write(sup1,64));
                      Delay_ms(1000);
                     }
                     if(CMSTATbits.C2OUT==0)
                     {
                      while(!HID_Write(normal2,64));
                      Delay_ms(1000);
                     }
                     else 
                     {
                      while(!HID_Write(sup2,64));
                      Delay_ms(1000);
                     }
                    }
                    CM1CONbits.CON=0; // comparador deshabilitado
                    opc=0;
                    break;
 }
}
}
RECEPTOR
int opc=0; 
unsigned dato=0, dato2=0;
void main() 
{
 ANSELC=0;
 ANSELD=0;
 ANSELE=0;
 ANSELB=0;
 TRISBbits.TRISB0=0;
 ANSELGbits.ANSG7=0;
 ANSELBbits.ANSB12=0;
 TRISBbits.TRISB12=1;
 TRISGbits.TRISG7=1;
 PORTBbits.RB0=0;
 //CONFIGURACION DEL PLL PARA ALCANZAR UNA VELOCIDAD DE 30MHZ
 PLLFBD = 58; //M = 60
 CLKDIVbits.PLLPOST= 0; // N1 = 2
 CLKDIVbits.PLLPRE= 0; // N2 = 2
 OSCTUN = 0;
 OSCCON=0x0301;
 while(OSCCONbits.COSC!= 0x3);
 //Configuracion del UART
 UART1_Init(9600);
 RPINR18bits.U1RXR=46; //U1RX
 RPOR9bits.RP101R=1; //U1TX
 Delay_ms(1000);
//Configuracion PWM complementado
 PTCONbits.PTEN=1; //habilita el módulo PWM
 IOCON3bits.PENH=1; //PWM3H es controlado por el módulo PWM
 IOCON3bits.PENL=1; //PWM3L es controlado por el módulo PWM
 IOCON4bits.PENH=1; //PWM4H es controlado por el módulo PWM
 IOCON4bits.PENL=1; //PWM4L es controlado por el módulo PWM
 PTPER=1024; // periodo de 900us;
 PDC3=512;
 PDC4=512;
 //tiempo muerto de 9us
 DTR2=50; DTR3=50;
 //Configuracion del Modo Falla
 IEC6bits.PWM3IE=1;
 IEC6bits.PWM4IE=1;
 RPINR12bits.FLT1R=119;//Falla 1 en el pin RG7
 RPINR12bits.FLT2R=44;//Falla 2 en el pin RB12
 FCLCON3bits.FLTSRC=0;//Falla 1 para el PWM3
 FCLCON4bits.FLTSRC=1;//Falla 2 para el PWM4
 PWMCON3bits.FLTIEN=1;//Falla para el PWM3 habilitada
 PWMCON4bits.FLTIEN=1;//Falla para el PWM4 habilitada
 FCLCON3bits.FLTPOL=1;//Falla 1 activada por flanco de bajada
 FCLCON4bits.FLTPOL=1;//Falla 2 activada por flanco de bajada
 FCLCON3bits.IFLTMOD=0;//Falla 1 modo normal
 FCLCON4bits.IFLTMOD=0;//Falla 2 modo normal
 FCLCON3bits.FLTMOD=1;

 FCLCON4bits.FLTMOD=1;
 IPC24bits.PWM3IP=3;//Prioridad 3 para la falla 1
 IPC24bits.PWM4IP=3;//Prioridad 3 para la falla 2
 CNPUGbits.CNPUG7=1;//Pull Up RG7 activas
 CNPUBbits.CNPUB12=1;//Pull Up RB12 activas
 while(1)
 {
  while(!UART1_Data_Ready()); //Espera que reciba un dato
  dato=UART1_Read();
  PORTBbits.RB0=~PORTBbits.RB0;
  while(!UART1_Data_Ready()); //Espera que reciba un dato
  dato2=UART1_Read();
  dato2=(dato2<<8)+dato;
  PDC3=dato2;
  PORTBbits.RB0=~PORTBbits.RB0;
  while(!UART1_Data_Ready()); //Espera que reciba un dato
  dato=UART1_Read();
  PORTBbits.RB0=~PORTBbits.RB0;
  while(!UART1_Data_Ready()); //Espera que reciba un dato
  dato2=UART1_Read();
  dato2=(dato2<<8)+dato;
  PDC4=dato2;
  PORTBbits.RB0=~PORTBbits.RB0;
 }
}



























