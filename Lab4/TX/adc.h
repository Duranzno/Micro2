void ajuste(unsigned control);
void ajuste2(unsigned control2);

void config_timer3 () {
  TMR3=0;
  T3CON=0X0030; //Prescaler 64:1, modo timer
  PR3=65000; //1000ms
  IEC0bits.T3IE=1;
  IFS0bits.T3IF=0;
}
void config_adc() {
 AD1CON1bits.AD12B=0;// ADC de 10 bits
 AD1CON1bits.FORM=0; // ENTERO SIN SIGNO
 AD1CON1bits.SSRCG=0;
 AD1CON1bits.SSRC=2;//TIMER3 inicia la convercion
 AD1CON1bits.SIMSAM=1;// Muestreo simultaneo
 AD1CON1bits.ASAM=1;
 AD1CON1bits.SAMP=0;
 AD1CON2bits.VCFG=0;// AVdd y AVss como referencias
 AD1CON2bits.CSCNA=0;
 AD1CON2bits.CHPS=1;//CH0 y  CH1 Act.
 AD1CON2bits.SMPI=0;// interrupcion a la primera conversion
 AD1CON2bits.BUFM=0; //llenado desde la primera direccion
 AD1CON2bits.ALTS=0;
 AD1CON3bits.ADRC=0; //reloj interno  Tcy
 AD1CON3bits.SAMC=11; //10TAD del tiempo de muestreo
 AD1CON3bits.ADCS=0; //TAD=Tcy
 AD1CON4bits.ADDMAEN=0; //SIN DMA
 AD1CHS123bits.CH123NA=0; //entrada negativa es AVss
 AD1CHS123bits.CH123SA=0;// CH1 entrada positiva AN0(RB0)
 AD1CHS0bits.CH0NA=0; //entrada negativa es AVss
 AD1CHS0bits.CH0SA=5;//ENTRADA positiva AN15(rb15)
 IFS0bits.AD1IF=0;//bandera=0
 IEC0bits.AD1IE=1;//hab interrupcion
 IPC3bits.AD1IP=6;
 delay_ms(10);
}


