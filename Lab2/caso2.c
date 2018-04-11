void config_ic() {

IC1CON1bits.ICTSEL=1; // reloj timer 3
IC2CON1bits.ICTSEL=1 ; // reloj timer 3
IC1CON1bits.ICM=2; //captura 
IC2CON1bits.ICM=2; // captura 
IC1CON2bits.IC32=1; // modo 32 bits
IC2CON2bits.IC32=1; // modo 32 bits
IC1CON1bits.SYNCSEL=13; // sincronismo timer 3
IC2CON1bits.SYNCSEL=13; // sincronismo timer 3
IEC0bits.IC1IE=1; // habilita interrupciones modulo 1
IEC0bits.IC2IE=1; // habilita interrupciones modulo 2
IFS0bits.IC1IF=0; // borra bandera
IFS0bits.IC2IF=0; // borra bandera
IC1CON1bits.ICTRIG=0; 
IC2CONbits.ICTRIG=0;


}

void config_timeric ()  {
T3CONbits.TSIDL=1; 
T2CON= 0x8020 // config 64:1 prescaler
PR2=31250; //1000 ms
T2CONbits.T32=1; // Modo 32 bits

}
 