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
unsigned short posicion=0;

void INT0() org 0x14{
	posicion=1;
	IFS0bits.INT0IF=0;
	}
void INT1() org 0x3C{
	posicion=2;
	IFS1bits.INT1IF=0;
	}
void INT2() org 0x4E{
	posicion=3;
	IFS1bits.INT2IF=0;
	}
void main(){
	ANSELC=0; ANSELD=0; ANSELE=0;
	CORCONbits.IPL3=0; //la interrupción de la CPU es de nivel 7 o menor
	SRbits.IPL=0; //interrupción de la CPU es de nivel 0
	INTCON1bits.NSTDIS=0; //interrupción anidadas activada
	INTCON2bits.GIE=1; //interrupciones habilitadas
	IFS0bits.INT0IF=0;
	IFS1bits.INT1IF=0;
	IFS1bits.INT2IF=0;
	INTCON2bits.INT0EP=0; //flanco positivo
	INTCON2bits.INT1EP=0; //flanco positivo
	INTCON2bits.INT2EP=0; //flanco positivo
	IEC0bits.INT0IE=1;
	IEC1bits.INT1IE=1;
	IEC1bits.INT2IE=1;
	RPINR0Bits.INT1R=75; //asigna INT1 al puerto rpi75
	RPINR1Bits.INT2R=74; //asigna INT2 al puerto rpi74
	
	Glcd_Init();
	Glcd_Set_Font(font5x7 , 5, 7, 32);
	Glcd_Fill(0);
	while(1){
		switch(posicion){
			case 0:
				Glcd_Write_Text("Esperando.......", 5, 3, 1);
				delay_ms(500);
				break;
			case 1:
				Glcd_Image(perro); delay_ms(500);
				Glcd_Image(perro2); delay_ms(500);
				break;
			case 2:
				Glcd_Image(pez1); delay_ms(250);
				Glcd_Image(pez3); delay_ms(250);
				Glcd_Image(pez5); delay_ms(250);
				Glcd_Image(pez7); delay_ms(250);
				break;	
			case 3:
				Glcd_Image(falla); delay_ms(500);
				Glcd_Image(falla2);delay_ms(500);
						break;
			}
		}
}
const code char perro[1024] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 32, 224,
128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 192, 96, 32, 48, 8, 14, 9, 8,
11, 12, 9, 14, 8, 16, 16, 32, 32, 64, 64, 192, 192, 96, 24, 228, 2, 254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 64, 48, 24, 12, 6, 3, 7, 6, 0, 0, 0, 0, 0, 224, 240,
248, 252, 134, 246, 135, 254, 254, 252, 0, 0, 0, 0, 0, 3, 7, 12, 252, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 254, 241, 224, 96, 160, 224, 192, 0, 0, 0, 0, 0, 0, 0, 0,
1, 1, 1, 1, 1, 1, 1, 129, 129, 192, 192, 224, 224, 240, 112, 120, 60, 14, 11, 24, 16, 48, 96, 64, 192, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
192, 32, 16, 208, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 6, 6, 254, 142, 134, 230, 30, 30, 26, 154, 249,
9, 8, 8, 8, 4, 4, 6, 7, 7, 7, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 2, 4, 12, 24, 16, 48, 16, 140, 67, 48, 12, 3, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 1, 0, 0, 128, 248,
192, 192, 192, 128, 0, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 128, 224, 112, 8, 0, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 12, 240, 0, 3, 15, 127,
255, 131, 7, 7, 15, 255, 0, 0, 0, 0, 0, 192, 252, 126, 127, 253, 252, 254, 255, 255, 60, 24, 16, 32, 64, 128, 128, 0, 0, 0, 128, 128, 127, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 5, 7, 4, 4, 4, 4, 7,
14, 17, 29, 17, 16, 28, 16, 24, 12, 7, 0, 0, 12, 12, 15, 15, 15, 120
7, 0, 0, 0, 0, 0, 56, 39, 56, 32, 32, 63, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0 };