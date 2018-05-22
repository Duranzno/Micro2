// void InitMCU(){
/*ANSELC=0x0000; //Configuracion de E/S digitales
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
    TRISDbits.TRISD10=0;
    TRISFBITS.TRISF5=0;


}*/
void config_spi () {
  IFS0bits.SPI1IF = 0; // Clear the Interrupt flag
  IEC0bits.SPI1IE = 0; // Disable the interrupt
  // SPI1CON1 Register Settings
  SPI1CON1bits.DISSCK = 0; // Internal serial clock is enabled
  SPI1CON1bits.DISSDO = 0; // SDOx pin is controlled by the module
  SPI1CON1bits.MODE16 = 1; // Communication is word-wide (16 bits)
  SPI1CON1bits.SMP = 0; // Input data is sampled at the middle of data output time
  SPI1CON1bits.CKE = 0; // Serial output data changes on transition from
  // Idle clock state to active clock state
  SPI1CON1bits.CKP = 0; // Idle state for clock is a low-level;
  // active state is a high-level
  SPI1CON1bits.MSTEN = 1; // Master mode enabled
  SPI1STATbits.SPIEN = 1; // Enable SPI module

  // Interrupt Controller Settings
  IFS0bits.SPI1IF = 0; // Clear the Interrupt flag
  IEC0bits.SPI1IE = 1; // Enable the interrupt
  IEC0bits.SPI1EIE=1; // interrupcion  por error
  IPC2bits.SPI1EIP=3; // prioridad
  IPC2bits.SPI1IP=4; // prioridad
  }