// 2.1 Control de velocidad de 2 Motores Independientes:
//         *La velocidad y cambio de giro de los motores serán controlados por 2 potenciómetros respectivamente utilizando el modo complementario.
//         *Deben activarse 2 teclas (matricial ó  PS2) para generar una falla en sus respectivos motores y detenerlos mientras se mantienen pulsados, además debe visualizarse una animación, por 8 segundos, referida a la falla y el tipo de motor
//         *El periodo de trabajo será de 2 milisegundos para ambos motores en modo centro alineado.
// Nota1: EL muestreo será cada un segundo por disparo de eventos especiales por parte de un temporizador. 
void config_PWM(){
  IEC6bits.PWM4IE=1;   // interrupcion pwm4
  IFS6bits.PWM4IF=0;   // limpia bandera pwm4
  IPC24bits.PWM4IP=6;  // nivel de interrupcion pwm4
  PTCONbits.PTEN=1;
  PWMCON4bits.FLTSTAT=0;   //bandera de pin de falla
  PWMCON4bits.FLTIEN=1;
  PWMCON4bits.ITB=1;
  PWMCON4bits.CAM=1;
  PWMCON4bits.IUE=1;
  IOCON4bits.PENH=1;
  IOCON4bits.PENL=1;
  IOCON4bits.POLH=0;
  IOCON4bits.POLL=0;
  DTR4=100;
  ALTDTR4=100;
  PHASE4=4000; // periodo de 2ms
  PDC4=3000; //100%
  IOCON4bits.FLTDAT=0;  // falla en pin pone bajo todo
  FCLCON4=0x0015;//falla indep. act,pin falla 3,act en baj0
  FCLCON4bits.FLTSRC=3;  // pin de falla 4
 }
 void config_PWM3(){
  IEC6bits.PWM3IE=1;   // interrupcion pwm4
  IFS6bits.PWM3IF=0;   // limpia bandera pwm4
  IPC24bits.PWM3IP=6;  // nivel de interrupcion pwm4
  PTCONbits.PTEN=1;
  PWMCON3bits.FLTSTAT=0;   //bandera de pin de falla
  PWMCON3bits.FLTIEN=1;
  PWMCON3bits.ITB=1;
  PWMCON3bits.CAM=1;
  PWMCON3bits.IUE=1;
  IOCON3bits.PENH=1;
  IOCON3bits.PENL=1;
  IOCON3bits.POLH=0;
  IOCON3bits.POLL=0;
  DTR3=100;
  ALTDTR3=100;
  PHASE3=4000; // periodo de 2ms
  PDC3=3000; //100%
  IOCON3bits.FLTDAT=0;  // falla en pin pone bajo todo
  FCLCON3=0x0015;//falla indep. act,pin falla 3,act en baj0
  FCLCON3bits.FLTSRC=2;  // pin de falla 3
  }
 void config_timer3 () {
 TMR3=0;
T3CON=0X0020; //Prescaler 64:1, modo timer
PR3=31250; //1000ms
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
 AD1CON3bits.SAMC=6; //5TAD del tiempo de muestreo
 AD1CON3bits.ADCS=0; //TAD=Tcy
 AD1CON4bits.ADDMAEN=0; //SIN DMA
 AD1CHS123bits.CH123NA=0; //entrada negativa es AVss
 AD1CHS123bits.CH123SA=0;// CH1 entrada positiva AN0(RB0)
 AD1CHS0bits.CH0NA=0; //entrada negativa es AVss
 AD1CHS0bits.CH0SA=5;//ENTRADA positiva AN15(rb15)
 IFS0bits.AD1IF=0;//bandera=0
 IEC0bits.AD1IE=1;//hab interrupcion
 IPC3bits.AD1IP=6;
 AD1CON1bits.ADON=1;// Se act el modulo
 delay_ms(10);

}