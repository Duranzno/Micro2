//_____//~~~~~~~~~~~~~~~~~~Constantes  del dsPIC~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Variables de PS2
sbit PS2_Data at RF4_bit;
sbit PS2_Clock at RF5_bit;
sbit PS2_Data_Direction at TRISF4_bit;
sbit PS2_Clock_Direction at TRISF5_bit;
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
    TRISDbits.TRISD10=1;  // entrada INDEX
    TRISDbits.TRISD9=1; // entrada fase A
    TRISDbits.TRISD8=1;  // entrada fase B
    RPINR13bits.FLT4R=75; // pin de falla pwm4
    RPINR13bits.FLT3R=64; //pin de falla pwm3
    RPINR15bits.INDX1R=74;  // pin para INDEX
    RPINR14bits.QEA1R=73;  // fase A
    RPINR14bits.QEB1R=72; // fase B
}
void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
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

void config_cuadratura () {
  QEI1IOCbits.INDEX=1;
  QEI1LECL=1910;
  QEI1LECH=0;
  QEI1GECL=2335; // registro bajo del comparacion mayor
  QEI1GECH=0;
  IEC3bits.QEI1IE=1; //habilita interrupcion de Cuadratura
  IFS3bits.QEI1IF=0; //limpia la bandera de interrupcion
  QEI1CONbits.PIMOD=3; // el contador se inicializa con el valor del registro QEI1IC
  QEI1CONbits.IMV=3;
  //QEI1ICH=valor_ini_h;
  // QEI1ICL=valor_ini_l;
  QEI1STATbits.PCHEQIEN =1; //interrupcion por comparacion de cuadratura
  QEI1STATbits.PCLEQIEN=1; // interrupcion por comparacion de cuadratura
  QEI1STATbits.IDXIEN=1; //interrupcion por INDEX pin
  QEI1CONbits.QEIEN=1; //habilita el módulo de cuadratura
  QEI1IOCbits.FLTREN=1; //Activa filtro digital
}
 void config_timer2 () {
  TMR2=0;
  T2CON=0X0020; //Prescaler 256:1, modo timer
  PR2=31250; //1000ms
  IEC0bits.T2IE=1;
  IFS0bits.T2IF=0;
}