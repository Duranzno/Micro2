#define FP 15000000
#define BAUDRATE 9600
#define BRGVAL ((FP/BAUDRATE)/16)-1
unsigned char UENVIAR;

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

void config_timer8() {
  tmr8=0;
  pr8=31250;
  t8con=0x8020;
  IFS3bits.T8IF=0;
  IEC3bits.T8IE=1;
  IPC12bits.T8IP=7;
  T8CONbits.TON=1;
}
void config_pin () {
    ANSELBbits.ANSB0=1; // RBO analogico
    ANSELBbits.ANSB3=1; // RB4 analogico
    TRISBbits.TRISB0=1;
    TRISBbits.TRISB3=1;
    TRISDbits.TRISD9=1; // entrada opto para motor 1
    TRISDbits.TRISD8=1; // entrada opto para motor 2
    RPINR0bits.INT1R=73; // RPI73 en INT1 motor 1
    RPINR1bits.INT2R=72; // RPI72 en INT2 motor 2
    RPOR0bits.RP64R=1; //U1TX
    RPINR18bits.U1RXR=72; //U1RX
    TRISDbits.TRISD10=0;
    TRISFBITS.TRISF5=0;
    
    
}