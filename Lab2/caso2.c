void config_ic() 

IC1CON1bits.ICTSEL=0; //
IC1CON1bits.ICM=2; //captura 
IC1CONbits.IC32=1; // modo 32 bits
IC2CONbits.IC32=1; // modo 32 bits
IEC0bits.IC1IE=1; // habilita interrupciones modulo 1
IEC0bits.IC2IE=1; // habilita interrupciones modulo 2
IFS0bits.IC1IF=0; // borra bandera
IFS0bits.IC2IF=0; // borra bandera