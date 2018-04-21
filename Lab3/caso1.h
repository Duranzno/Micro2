// 2.1 Control de velocidad de 2 Motores Independientes:
//         *La velocidad y cambio de giro de los motores serán controlados por 2 potenciómetros respectivamente utilizando el modo complementario.
//         *Deben activarse 2 teclas (matricial ó  PS2) para generar una falla en sus respectivos motores y detenerlos mientras se mantienen pulsados, además debe visualizarse una animación, por 8 segundos, referida a la falla y el tipo de motor
//         *El periodo de trabajo será de 2 milisegundos para ambos motores en modo centro alineado.
// Nota1: EL muestreo será cada un segundo por disparo de eventos especiales por parte de un temporizador. 
void config_PWM(){
  PTCONbits.PTEN=1;
  PWMCON4bits.FLTSTAT=1;
  PWMCON4bits.FLTIEN=1;
  PWMCON4bits.ITB=1;
  PWMCON4bits.CAM=1;
  PWMCON4bits.IUE=1;
  IOCON4bits.PENH=1;
  IOCON4bits.PENL=1;
  IOCON4bits.POLH=0;
  IOCON4bits.POLL=0;
  DTR3=100;
  PHASE4=4000; // periodo de 2ms
  PDC4=4000; //100%
 }
 config_timer3 () {
 TMR3=0;
T3CON=0X0020; //Prescaler 64:1, modo timer
PR3=31250; //1000ms
}