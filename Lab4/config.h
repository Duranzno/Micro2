<<<<<<< HEAD

=======
//Variables de GLCD
sbit GLCD_D0 at RD4_bit;
sbit GLCD_D1 at RD5_bit;
sbit GLCD_D2 at RD6_bit;
sbit GLCD_D3 at RD7_bit;
sbit GLCD_D4 at RF0_bit;
sbit GLCD_D5 at RF1_bit;
sbit GLCD_D6 at RE0_bit;
sbit GLCD_D7 at RE1_bit;
sbit GLCD_CS1 at LATE3_bit;
sbit GLCD_CS2 at LATE2_bit;
sbit GLCD_RS at LATD1_bit;
sbit GLCD_RW at LATD2_bit;
sbit GLCD_EN at LATD3_bit;
sbit GLCD_RST at LATC14_bit;

sbit GLCD_D0_Direction at TRISD4_bit;
sbit GLCD_D1_Direction at TRISD5_bit;
sbit GLCD_D2_Direction at TRISD6_bit;
sbit GLCD_D3_Direction at TRISD7_bit;
sbit GLCD_D4_Direction at TRISF0_bit;
sbit GLCD_D5_Direction at TRISF1_bit;
sbit GLCD_D6_Direction at TRISE0_bit;
sbit GLCD_D7_Direction at TRISE1_bit;
sbit GLCD_CS1_Direction at TRISE3_bit;
sbit GLCD_CS2_Direction at TRISE2_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISC14_bit;
//~~~~~~~~~~~~~~~~~~~~~~Configuraciones Iniciales~~~~~~~~~~~~~~~~~~~~~~~~~~
  void config_IO(){
    ANSELB=ANSELC=ANSELD=ANSELE=0;
    ANSELBbits.ANSB5=1;       // an5
    ANSELBbits.ANSB0=1; // an4
    TRISB=0xffff;
    TRISE=TRISG=0;
    TRISDbits.TRISD0=1;
    TRISDbits.TRISD11=1;

}
>>>>>>> cb230bff23c6693b82dcfc38d579331a1ca20523
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
void config_INT(){
  SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
  INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
  INTCON2bits.GIE=1; //interrupciones habilitadas
  CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
  IPC14bits.QEI1IP=2; // interrupcion del modulo cuadratura 2
  IPC2bits.T3IP=3;
  IPC1bits.T2IP=7;
  IPC6bits.T4IP=3;
//------------------------- habilitacion de interrupcion

 }


void config_pin () {
        TRISDbits.TRISD9=1; // entrada opto para motor 1
        TRISDbits.TRISD8=1; // entrada opto para motor 2
        RPINR0bits.INT1R=73; // RPI73 en INT1 motor 1
        RPINR1bits.INT2R=72; // RPI72 en INT2 motor 2
}
void config_velocidad () {
IFS1bits.INT1IF=0;
IFS1bits.INT2IF=0;
INTCON2bits.INT1EP=0; //flanco positivo
INTCON2bits.INT2EP=0; //flanco positivo
IEC1bits.INT1IE=2;
IEC1bits.INT2IE=2;
}


void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
}