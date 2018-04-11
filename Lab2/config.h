//~~~~~~~~~~~~~~~~~~Constantes  del dsPIC~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
//Entrada Botones y Dipswitches
//Las entradas del teclado y las salidas de la pantalla son manejadas por las librerias;
}
void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
}
void config_TMR(){
  //TIMER 1 HORA REAL
    TMR1=0;
    PR1=31250; //1000ms
    IEC0bits.T1IE=1;//enable interrupcion
    IFS0bits.T1IF=0;//limpia bandera
    IPC0bits.T1IP=3;//prioridad interrupcion
    T1CON=0;
    T1CONBits.TCKPS= 2;   //Preescalador 64
    T1CONBits.TON=0;
    
}
void config_INT(){
  SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
  INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
  INTCON2bits.GIE=1; //interrupciones habilitadas
  CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
//------------------------- habilitacion de interrupcion
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
 IPC0bits.IC1IP=2;
  IPC0bits.IC1IP=2;

}

void config_timeric ()  {
T3CONbits.TSIDL=1;
T2CON= 0x8020; // config 64:1 prescaler
PR2=31250; //1000 ms
T2CONbits.T32=1; // Modo 32 bits
 IPC1bits.T2IP=3;
}