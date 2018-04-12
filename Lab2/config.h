//_____//~~~~~~~~~~~~~~~~~~Constantes  del dsPIC~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Variables de PS2
sbit PS2_Data at RF4_bit;
sbit PS2_Clock at RF5_bit;
sbit PS2_Data_Direction at TRISF4_bit;
sbit PS2_Clock_Direction at TRISF5_bit;
//Variables de GLCD
sbit GLCD_D7 at RE1_bit;
sbit GLCD_D6 at RE0_bit;
sbit GLCD_D5 at RF1_bit;
sbit GLCD_D4 at RF0_bit;
sbit GLCD_D3 at RD7_bit;
sbit GLCD_D2 at RD6_bit;
sbit GLCD_D1 at RD5_bit;
sbit GLCD_D0 at RD4_bit;
sbit GLCD_D7_Direction at TRISE1_bit;
sbit GLCD_D6_Direction at TRISE0_bit;
sbit GLCD_D5_Direction at TRISF1_bit;
sbit GLCD_D4_Direction at TRISF0_bit;
sbit GLCD_D3_Direction at TRISD7_bit;
sbit GLCD_D2_Direction at TRISD6_bit;
sbit GLCD_D1_Direction at TRISD5_bit;
sbit GLCD_D0_Direction at TRISD4_bit;
sbit GLCD_CS1 at LATE3_bit;
sbit GLCD_CS2 at LATE2_bit;
sbit GLCD_RS at LATD1_bit;
sbit GLCD_RW at LATD2_bit;
sbit GLCD_EN at LATD3_bit;
sbit GLCD_RST at LATE4_bit;
sbit GLCD_CS1_Direction at TRISE3_bit;
sbit GLCD_CS2_Direction at TRISE2_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISE4_bit;
//~~~~~~~~~~~~~~~~~~~~~~Configuraciones Iniciales~~~~~~~~~~~~~~~~~~~~~~~~~~
void config_IO(){
  ANSELB=0;
  ANSELC=0;
  ANSELD=0;
  ANSELE=0;
  ANSELG=0;             //ANA//logiCO SON B Y F
  TRISB=0xffff;
  TRISE=0;
  TRISG=0;
  TRISDbits.TRISD11=1;  // desde rd11 a rd8 son  entradas del modulo captura
  TRISDbits.TRISD10=1;
  TRISDbits.TRISD9=1;
  TRISDbits.TRISD8=1;
  TRISFbits.TRISF3=0;  // salida paola
  TRISEbits.TRISE5=0;
  TRISEbits.TRISE7=0;
  TRISGbits.TRISG6=0;
  TRISGbits.TRISG8=0;
  RPOR6bits.RP85R =0b010000;     //pin comparador 1  RE5
  RPOR6bits.RP87R =0b010001;    //pin comparador 2  RE7
  RPOR13bits.RP118R=0b010010;  //pin comparador 3 RG6
  RPOR14bits.RP120R=0b010011;//Las entradas del teclado y las salidas de la pantalla son manejadas por las librerias;
  RPOR0bits.RP64R=0b010100;

}
void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
}
void config_pin () {
  TRISDbits.TRISD11=1; // pin D11 como entrada
  RPINR7bits.IC1R=75; //captura por el D11
}
void config_captura (){
  TMR2=0;
  T2CONbits.TCKPS=2; // Prescaler 64:1, modo timer
  T2CONbits.TGATE=0;
  T2CONbits.TCS=0;
  PR2=31250; //1000ms
  IEC0bits.T2IE=1;//enable interrupcion
  IFS0bits.T2IF=0;//limpia bandera
  IC1CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
  IC1CON1bits.ICM=5; // captura cada 4 flancos positivos
  RPINR7bits.IC1R=75; //asigna IC1 al RPI75
 // T1CONbits.TON=1; //enciende timer 1
  IEC0bits.IC1IE=1; //habilita interrupciÃ³n del IC1
  IFS0bits.IC1IF=0; //limpia la bandera de interrupciÃ³n
}
void config_TMR_1(){
  //TIMER 1 HORA REAL
	TMR1=0;
    PR1=31250; //1000ms
    IEC0bits.T1IE=1;//enable interrupcion
    IFS0bits.T1IF=0;//limpia bandera
   // IPC0bits.T1IP=3;//prioridad interrupcion
    T1CON=0;
    T1CONBits.TCKPS= 2;   //Preescalador 64
    T1CONBits.TON=0;

}
void config_TMR_45(){
  IEC1bits.T4IE=1;
  IEC1bits.T5IE=1;
  IFS1bits.T4IF=0;
  IFS1bits.T5IF=0;
  T4CONbits.TCKPS=0;            //preescaler 1:1
  T4CONbits.TCS=0;
  TMR4=0;
  PR4=2000;                    // timer a 1ms
  T5CONbits.TCKPS=5;            //prescaler 256:1
  T5CONbits.TCS=0;
  TMR5=0;
  PR5=39062; // timer a 5s

}
void config_OC(){
  OC5CON1bits.OCTSEL=7;
  OC1CON1bits.OCTSEL=2;        // T4CLK fuente de reloj
  OC2CON1bits.OCTSEL=2;
  OC3CON1bits.OCTSEL=2;
  OC4CON1bits.OCTSEL=2;
  OC1CON2bits.OCTRIS=1;
  OC2CON2bits.OCTRIS=1;
  OC3CON2bits.OCTRIS=1;
  OC4CON2bits.OCTRIS=1;
  OC5CON2bits.OCTRIS=1;
  
  OC5CON1bits.OCM=5;
  OC1CON1bits.OCM=5;          //MODO COMPARADOR DUAL DE PULSOS CONTINUOS
  OC2CON1bits.OCM=5;
  OC3CON1bits.OCM=5;
  OC4CON1bits.OCM=5;
  OC5R=306; OC5RS=2047;
  OC1R=306; OC1RS=2047;     //CICLO UTIL 15%
  OC2R=921; OC2RS=2047;     //CICLO UTIL 45%
  OC3R=1227; OC3RS=2047;     //CICLO UTIL 60%
  OC4R=1637; OC4RS=2047;     //CICLO UTIL 80%
  OC1CON2bits.SYNCSEL=0b01111;    //disparo con el OC 5
  OC2CON2bits.SYNCSEL=0b00101;
  OC3CON2bits.SYNCSEL=0b01111;
  OC4CON2bits.SYNCSEL=0b01111;
  OC5CON2bits.SYNCSEL=0b01111;
}
void config_INT(){
  SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
  INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
  INTCON2bits.GIE=1; //interrupciones habilitadas
  CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
//------------------------- habilitacion de interrupcion
  IPC0bits.T1IP=2;
  IPC1bits.T2IP=4;
  IPC6bits.T4IP=2;
  IPC7bits.T5IP=3;
  IPC0bits.IC1IP=2;
 }
//prioridad int
// Banderas de Interrupcion post Reset (Limpieza)

 void config_ic() {
	IC1CON1bits.ICTSEL=1; // reloj timer 3
	IC2CON1bits.ICTSEL=1 ; // reloj timer 3
	IC1CON1bits.ICM=2; //captura
	IC2CON1bits.ICM=2; // captura
	IC1CON2bits.IC32=1; // modo 32 bits
	IC2CON2bits.IC32=1; // modo 32 bits

	IC1CON2bits.SYNCSEL=13; // sincronismo timer 3
	IC2CON2bits.SYNCSEL=13; // sincronismo timer 3
	IEC0bits.IC1IE=1; // habilita interrupciones modulo 1
	IEC0bits.IC2IE=1; // habilita interrupciones modulo 2
	IFS0bits.IC1IF=0; // borra bandera
	IFS0bits.IC2IF=0; // borra bandera
	IC1CON2bits.ICTRIG=0;
	IC2CON2bits.ICTRIG=0;
}
void config_timeric ()  {
	T3CONbits.TSIDL=1;
	T2CON= 0x8020; // config 64:1 prescaler
	PR2=31250; //1000 ms
	T2CONbits.T32=1; // Modo 32 bits
	IPC1bits.T2IP=3;
}