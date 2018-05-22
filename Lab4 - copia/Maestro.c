

void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT{
  USB_Interrupt_Proc();
}
void Error_SPI() org 0x26{
	IFS0bits.SPI1EIF=0;

}
void SPI() org 0x28{
	IFS0bits.SPI1IF=0;

}
char writebuff[64],readbuff[64];                
int cnt=0;
void main(){
  ANSELC=0;
	ANSELD=0;
	ANSELE=0;
	ANSELB=0;
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
 
    SRbits.IPL=0;
    CORCONbits.IPL3=0;
    INTCON1bits.NSTDIS=0;
    INTCON2bits.GIE=1;
    IPC2bits.SPI1EIP=3;
    IPC2bits.SPI1IP=3;
    IEC0bits.SPI1EIE=0;
    RPINR20bits.SDI1R=83;
    RPOR5bits.RP84R=0b000101;
    RPOR5bits.RP82R=0b000110;

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


  HID_Enable(&readbuff,&writebuff);
  while(1){
    while(!HID_Write('q',64));
    while(!HID_Read());
    for(cnt=0;cnt<64;cnt++) {writebuff[cnt]=readbuff[cnt];            }
            if(strcmp(readbuff,'a')==0){//CASE 1
                     while(!HID_Write('a',64));
            }
    }

}