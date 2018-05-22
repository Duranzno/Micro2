//modo esclavo

//Variables de GLCD
sbit GLCD_D0 at RD4_bit;
sbit GLCD_D1 at RD5_bit;
sbit GLCD_D2 at RD6_bit;
sbit GLCD_D3 at RD7_bit;
sbit GLCD_D4 at RF0_bit;
sbit GLCD_D5 at RF1_bit;
sbit GLCD_D6 at RE0_bit;
sbit GLCD_D7 at RE1_bit;
sbit GLCD_CS1 at LATE2_bit;
sbit GLCD_CS2 at LATE3_bit;
sbit GLCD_RS at LATD1_bit;
sbit GLCD_RW at LATD2_bit;
sbit GLCD_EN at LATD3_bit;
sbit GLCD_RST at LATC14_bit;

sbit GLCD_D0_Direction at TRISD4_bit;
sbit GLCD_D1_Direction at TRISD5_bit;
sbit GLCD_D2_Direction at TRISD6_bit;
sbit GLCD_D3_Direction at TRISD7_bit;
sbit GLCD_D4_Direction at TRISF0_bit;
sbit GLCD_D5_Direction at TRISF1_bit;
sbit GLCD_D6_Direction at TRISE0_bit;
sbit GLCD_D7_Direction at TRISE1_bit;
sbit GLCD_CS1_Direction at TRISE2_bit;
sbit GLCD_CS2_Direction at TRISE3_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISC14_bit;
char tecla, buffer;
//~~~~~~~~~~~~~~~~~~~~~~Configuraciones Iniciales~~~~~~~~~~~~~~~~~~~~~~~~~~

void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(System3x5 , 3, 5, 32);
  Glcd_Fill(0);
}
void Error_SPI() org 0x26{
	IFS0bits.SPI1EIF=0;

}
void encender_led(){LATFBITS.LATF4=~LATFBITS.LATF4;}
void SPI() org 0x28{
   Glcd_Write_Text("si interrupmpe", 60, 5, 1);
   encender_led();

	IFS0bits.SPI1IF=0;

}


void main (){
	ANSELC=0;
	ANSELD=0;
	ANSELE=0;
	ANSELB=0;
	
     TRISFBITS.TRISF5=0;
    SRbits.IPL=0;
    CORCONbits.IPL3=0;
    INTCON1bits.NSTDIS=0;
    INTCON2bits.GIE=1;
    IPC2bits.SPI1EIP=3;
    IPC2bits.SPI1IP=3;
    IEC0bits.SPI1EIE=0;
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

	SPI1BUF = 0;
	IFS0bits.SPI1IF = 0; // Clear the Interrupt flag
	IEC0bits.SPI1IE = 0; // Disable the interrupt
	// SPI1CON1 Register Settings
	SPI1CON1bits.DISSCK = 0; // Internal Serial Clock is enabled
	SPI1CON1bits.DISSDO = 0; // SDOx pin is controlled by the module
	SPI1CON1bits.MODE16 = 1; // Communication is word-wide (16 bits)
	SPI1CON1bits.SMP = 0; // Input data is sampled at the middle of data
// output time.
	SPI1CON1bits.CKE = 0; // Serial output data changes on transition
// from Idle clock state to active clock state
	SPI1CON1bits.CKP = 0; // Idle state for clock is a low level; active
// state is a high level
	SPI1CON1bits.MSTEN = 0; // Master mode disabled
	SPI1STATbits.SPIROV=0; // No Receive Overflow has occurred
	SPI1STATbits.SPIEN = 1; // Enable SPI module
	IFS0bits.SPI1IF = 0; // Clear the Interrupt flag
  IEC0bits.SPI1IE = 1;  //habilito las interrupciones
  
	RPINR20bits.SDI1R=46; //SDI1 pines spi
	RPINR20bits.SCK1R=47; //SCK1
	RPOR9bits.RP101R=5; //SDO
	config_LCD();

	while(1){
	  Glcd_Write_Text("Esperando......", 1, 60, 1);
	 while(!SPI1STATbits.SPIRBF); //Esperando que llegue el dato
     Glcd_Write_Text("LLEGO'", 5, 60, 1);
   


  }





}