int i=0,j=0;
char readbuff[64];
char writebuff[64];
unsigned adc_valor,resistencia;
void InitMCU()
{ ANSELC=0x0000; //Configuracion de E/S digitales
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

void USB1Interrupt() iv IVT_ADDR_USB1INTERRUPT
{
USB_Interrupt_Proc();
}
void main(void)
{
InitMCU();
HID_Enable(&readbuff,&writebuff); //inicializamos en módulo usb hid

while(1)
{
  for (i=0;i<64;i++)
 {
  writebuff[i]=' ';
  }
for(j=0;j<4;j++){

writebuff[63]='p';
writebuff[62]='a';
writebuff[61]='o';
writebuff[60]='l';
writebuff[59]='a';
writebuff[58]=' ';

 writebuff[57]='g';
writebuff[56]='a';
writebuff[55]='b';
writebuff[54]='r';
writebuff[53]='i';
writebuff[52]=' ';


while(!HID_Write(&writebuff,64));
delay_ms(1000);
}
}
}