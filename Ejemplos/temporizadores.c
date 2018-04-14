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
Unsigned short unidad_segundo=0, decena_segundo=0, unidad_minuto=0,
decena_minuto=0, unidad_hora=0, decena_hora=0;
char hora[8];
void t1() org 0x1A{
	unidad_segundo++;
	if(unidad_segundo==10){
		unidad_segundo=0;
		decena_segundo++;
		if(decena_segundo==6){
			decena_segundo=0;
			unidad_minuto++;
			if(unidad_minuto==10){
				unidad_minuto=0;
				decena_minuto++;
				if(decena_minuto==6){
					decena_minuto=0;
					unidad_hora++;
					if(unidad_hora==10 && decena_hora==0){
						unidad_hora=0;
						decena_hora++;
					}
					else if(unidad_hora==1 && decena_hora==3){
						unidad_hora=0;
						decena_hora=0;
					}
				}
			}
		}
	}
	hora[0]=decena_hora+'0';
	hora[1]=unidad_hora+'0';
	hora[2]= ':';
	hora[3]=decena_minuto+'0';
	hora[4]=unidad_minuto+'0';
	hora[5]= ':';
	hora[6]=decena_segundo+'0';
	hora[7]=unidad_segundo+'0';
	hora[8]= '\0';
	Glcd_Write_Text(hora, 30, 3, 1);
	IFS0bits.T1IF=0;
}

void t2() org 0x22{
	PORTBbits.RB15=~PORTBbits.RB15;
	IFS0bits.T2IF=0;
}
void t3() org 0x24{
	PORTFbits.RF4=~PORTFbits.RF4;
	IFS0bits.T3IF=0;
}
void main(){
	ANSELC=0;
	ANSELD=0;
	ANSELE=0;
	ANSELB=0;
	CORCONbits.IPL3=0; //la interrupcion de la CPU es de nivel 7 o menor
	SRbits.IPL=0; //interrupcion de la CPU es de nivel 0
	INTCON1bits.NSTDIS=0; //interrupcion anidadas activada
	INTCON2bits.GIE=1; //interrupciones habilitadas
	TRISBbits.TRISB15=0;
	PORTBbits.RB15=0;
	TRISFbits.TRISF4=0;
	PORTFbits.RF4=0;
	TMR1=0;
	T1CON=0X8020; //Prescaler 64:1, modo timer
	PR1=31250; //1000ms
	TMR2=0;
	T2CON =0X8010; Prescaler 16:1, modo timer
	PR2=45000; //360ms
	TMR3=0;
	T3CON=0X8010; Prescaler 16:1 , modo timer
	PR3=22500; //180ms
	IEC0bits.T1IE=1;
	IEC0bits.T2IE=1;
	IEC0bits.T3IE=1;
	IFS0bits.T1IF=0;
	IFS0bits.T2IF=0;
	IFS0bits.T3IF=0;
	IPC0bits.T1IP=3;
	IPC1bits.T2IP=4;
	IPC2bits.T3IP=5;
	Glcd_Init();
	Glcd_Set_Font(Character8x7, 8, 7, 32);
	Glcd_Fill(0);
	while(1);
}