void config_PWM();void config_PWM3();
void config_motor() {
   config_PWM();  config_PWM3();
}
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
  DTR4=2000;
  ALTDTR4=2000;
  PHASE4=30000; // periodo de 2ms
  PDC4=20000; //100%
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
  DTR3=2000;
  ALTDTR3=2000;
  PHASE3=30000; // periodo de 2ms
  PDC3=20000; //100%
  IOCON3bits.FLTDAT=0;  // falla en pin pone bajo todo
  FCLCON3=0x0015;//falla indep. act,pin falla 3,act en baj0
  FCLCON3bits.FLTSRC=2;  // pin de falla 3
}
