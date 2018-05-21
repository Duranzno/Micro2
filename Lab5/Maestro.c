//MODO MAESTRO

void Error_SPI() org 0x26{
	IFS0bits.SPI1EIF=0;

}
void SPI() org 0x28{
	IFS0bits.SPI1IF=0;

}
void main(){
  ANSELC=0;
	ANSELD=0;
	ANSELE=0;
	ANSELB=0;
  SRbits.IPL=0;
    CORCONbits.IPL3=0;
    INTCON1bits.NSTDIS=0;
    INTCON2bits.GIE=1;
    IPC2bits.SPI1EIP=3;
    IPC2bits.SPI1IP=3;
    IEC0bits.SPI1EIE=0;

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
  SPI1BUF = 0x0000; // Write data to be transmitted
  // Interrupt Controller Settings
  IFS0bits.SPI1IF = 0; // Clear the Interrupt flag
  IEC0bits.SPI1IE = 1; // Enable the interrupt
  
  while(1){
  
  }

}
