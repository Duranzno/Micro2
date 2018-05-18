///////////////////////////////////////////////////RECEPCION/////////////////////////////////////
/////////////////
// Glcd module connections
sbit GLCD_D7 at RE1_bit;
sbit GLCD_D6 at RE0_bit;
sbit GLCD_D5 at RF1_bit;
sbit GLCD_D4 at RF0_bit;
sbit GLCD_D3 at RD7_bit;
sbit GLCD_D2 at RD6_bit;
sbit GLCD_D1 at RD5_bit;
sbit GLCD_D0 at RD4_bit;
sbit GLCD_D7_Direction at TRISE1_bit;
sbit GLCD_D6_Direction at TRISE0_bit;
sbit GLCD_D5_Direction at TRISF1_bit;
sbit GLCD_D4_Direction at TRISF0_bit;
sbit GLCD_D3_Direction at TRISD7_bit;
sbit GLCD_D2_Direction at TRISD6_bit;
sbit GLCD_D1_Direction at TRISD5_bit;
sbit GLCD_D0_Direction at TRISD4_bit;
sbit GLCD_CS1 at LATE3_bit;
sbit GLCD_CS2 at LATE2_bit;
sbit GLCD_RS at LATD1_bit;
sbit GLCD_RW at LATD2_bit;
sbit GLCD_EN at LATD3_bit;
sbit GLCD_RST at LATE4_bit;
sbit GLCD_CS1_Direction at TRISE3_bit;
sbit GLCD_CS2_Direction at TRISE2_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISE4_bit;
// End Glcd module connections
char tecla, buffer;
void main()
{ ANSELC=0;
ANSELD=0;
ANSELE=0;
ANSELB=0;
SPI1_Init_Advanced(SPI_SLAVE,_SPI_8_BIT,_SPI_PRESCALE_SEC_8,_S
PI_PRESCALE_PRI_64,_SPI_SS_DISABLE,_SPI_DATA_SAMPLE_MIDDLE
,_SPI_CLK_IDLE_LOW, _SPI_ACTIVE_2_IDLE);
RPINR20bits.SDI1R=46; //SDI1
RPINR20bits.SCK1R=47; //SCK1
RPOR9bits.RP101R=5; //SDO
Glcd_Init();
Glcd_Set_Font(character8x7 , 8, 7, 32);
Glcd_Fill(0);
Glcd_Write_Text("Tecla Pulsada:", 0, 2, 1);
while(1)
{ while(!SPI1STATbits.SPIRBF); //Esperando que llegue el dato
tecla=SPI1_Read(buffer);
Glcd_Write_Char(tecla, 10, 4, 1);
}
}