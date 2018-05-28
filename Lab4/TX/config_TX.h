#define FP 15000000
#define BAUDRATE 9600
#define BRGVAL ((FP/BAUDRATE)/16)-1
unsigned char UENVIAR;
void  CONFIG_CM(){
  ANSELDbits.ANSD7=1;//ENTRADA ANALOGICA c3in1+ 3V pin 55
  ANSELCbits.ANSC14=1;//ENTRADA ANALOGICA c3in1- POT pin 48
  ANSELBbits.ANSB5=1;//ENTRADA ANALOGICA c1in+ POT RB5 pin 11

  
  
  CM3CONbits.COE=0;
  CM1CONbits.COE=0;
  CM3CONbits.CON=1;
  CM1CONbits.CON=1;
  CM3CONbits.CPOL=0;
  CM1CONbits.CPOL=0;

  CM3CONBITS.CREF=0;//CONECTADO A C3IN1+
  CM3CONBITS.CCH=1;//CONECTADO A C3IN1-
  CM1CONBITS.CREF=0;//CONECTADO A C1IN1+
  CM1CONBITS.CCH=11;////CONECTADO A INTREF
  CVRCONbits.BGSEL=1;
  CVRCONbits.CVREN=1;
  CM1CONbits.CEN=1;
  CM3CONbits.CEN=1; 
 }
 void config_timer1() {
  TMR1=0;
  PR1=65000;
  T1CON=0x0030;
  IFS0BITS.T1IF=0;
  IEC0BITS.T1IE=1;
  IPC0BITS.T1IP=5;
}
void InitMCU(){
        ANSELC=0x0000; //Configuracion de E/S digitales
        ANSELD=0x0000; //Configuracion de E/S digitales
        ANSELE=0x0040; //RE6 como entrada analogica
        ANSELB=0x0000; //Configuracion de E/S digitales
        //CONFIGURACION DEL PLL PARA ALCANZAR UNA VELOCIDAD DE 30MHZ
        PLLFBD = 58; //M = 60
        CLKDIVbits.PLLPOST = 0; // N1 = 2
        CLKDIVbits.PLLPRE = 0; // N2 = 2
        OSCTUN = 0;
        OSCCON=0x0301;
while (OSCCONbits.COSC != 0x3);
        //CONFIGURACION DEL PLL AUXILIAR PARA EL USB
        //SE REQUIEREN 48MHZ
        ACLKCON3 = 0x24C0;
        ACLKDIV3 = 0x7;
        ACLKCON3bits.ENAPLL = 1;
        while(ACLKCON3bits.APLLCK != 1);
}
void config_TX(){
  U1MODEbits.STSEL=0;
  U1MODEbits.PDSEL=0;
  U1MODEbits.ABAUD=0;
  U1MODEbits.BRGH=0;
  U1BRG=BRGVAL;
  U1STAbits.UTXISEL1=0;
  IEC0BITS.U1TXIE=1;
  U1MODEbits.UARTEN=1;
  delay_us(105);
  IFS0bits.U1TXIF=0;
  IEC0bits.U1TXIE=1;
  IPC3bits.U1TXIP=6;
}
void config_INT(){
  SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
  INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
  INTCON2bits.GIE=1; //interrupciones habilitadas
  CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
  IPC14bits.QEI1IP=2; // interrupcion del modulo cuadratura 2
  IPC2bits.T3IP=5;
  
  IPC6bits.T4IP=3;
//------------------------- habilitacion de interrupcion
 }


void config_pin () {
    ANSELBbits.ANSB0=1; // RBO analogico
    ANSELBbits.ANSB3=1; // RB4 analogico
    TRISBbits.TRISB0=1;
    TRISBbits.TRISB3=1;
    //TRISDbits.TRISD9=1; // entrada opto para motor 1
    TRISDbits.TRISD8=1; // entrada opto para motor 2
  //  RPINR0bits.INT1R=73; // RPI73 en INT1 motor 1
    RPINR1bits.INT2R=72; // RPI72 en INT2 motor 2
    TRISDbits.TRISD10=0;
    TRISFBITS.TRISF5=0;
    
    
}
/*void config_velocidad () {

        IFS1bits.INT2IF=0;
        INTCON2bits.INT1EP=0; //flanco positivo
        INTCON2bits.INT2EP=0; //flanco positivo
        IEC1bits.INT1IE=1;
        IEC1bits.INT2IE=1;
        IPC5BITS.INT1IP=4;
        IPC7bits.INT2IP =4;
}*/