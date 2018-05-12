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