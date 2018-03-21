// Se desea realizar una aplicación mediante el dsPIC33EP256MU806, que permita
// visualizar en una interfaz grafica una señal lógica a la vez de mostrar los valores de
// su frecuencia y periodo. Para esta aplicación hemos conectado un NE555 en
// configuración astable, dicho oscilador tiene una resistencia variable llamada Rp con
// la cual variaremos la frecuencia y el ciclo útil de la señal cuadrada generada.
// Una vez generada la señal cuadrada, la misma se introduce al dsPIC33EP256MU806
// mediante el pin del módulo de captura el mismo, el módulo captura genera una
// interrupción cada vez que perciba un flanco por su pin correspondiente según se
// configure.
// En esta aplicación hemos utilizado dos de los 16 módulos de captura que posee este
// dsPIC, un módulo de captura (IC1) para medir los tiempos de los ciclos de la señal
// cuadrada y el otro módulo de captura (IC2) para almacenar la cantidad de pulsos
// recibidas en un segundo.
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

unsigned short i=0,j,k,valor[9],nivel=0;
char txt[16];
float frecuencia,tiempo[9];
int pulsos=0,tiempo_anterior=0,tiempo_actual=0;
void captura_onda_ic1() org 0x16{
	if(k<7){
	tiempo[k]=IC1TMR;
	valor[k]=nivel;
	nivel=!nivel;
	k++;
	}
	else
	IC1CON1bits.ICM=0;//módulo desactivado
	IFS0bits.IC1IF=0;
}

void captura_frecuencia_ic2() org 0x1E{
	pulsos++;
	IFS0bits.IC2IF=0;
}
void main(){ 
	ANSELC=0;
	ANSELD=0;
	ANSELE=0;
	ANSELB=0;
	CORCONbits.IPL3=0; //la interrupción de la CPU es de nivel 7 o menor
	SRbits.IPL=0; //interrupción de la CPU es de nivel 0
	INTCON1bits.NSTDIS=0; //interrupción anidadas activada
	INTCON2bits.GIE=1; //interrupciones habilitadas
	IC1CON1bits.ICTSEL=4; //usa como fuente de reloj el timer1
	IC1CON1bits.ICM=1; Captura en bajada y subida
	IC2CON1bits.ICM=5; //captura al 16th evento
	RPINR7bits.IC1R=46; //asigna IC1 al RPI46
	IC2CON1bits.ICTSEL=7; //usa como fuente de reloj el principal del sistema
	RPINR7bits.IC2R=45; //asigna IC2 al RPI45
	T1CONbits.TON=1; //enciende timer 1
	IEC0bits.IC1IE=1; //habilita interrupción del IC1
	IFS0bits.IC1IF=0; //limpia la bandera de interrupción
	IEC0bits.IC2IE=1; //habilita interrupción del IC2
	IFS0bits.IC2IF=0; //limpia la bandera de interrupción
	Glcd_Init();
	Glcd_Set_Font(font5x7, 5, 7, 32);
	while(1){
		frecuencia=pulsos;
		frecuencia=frecuencia*16*2;
		Glcd_Fill(0);
		//mostrando informacion en la GLCD////
		Glcd_Write_Text("Frecu.(hz)=", 0, 6, 1);
		floattostr(frecuencia,txt);
		Glcd_Write_Text(txt,65, 6, 1);
		Glcd_Write_Text("Perid.(us)=", 0, 7, 1);
		frecuencia=(1/frecuencia)*1000000;
		floattostr(frecuencia,txt);
		Glcd_Write_Text(txt,65, 7, 1);
		///////////////////////////////////////
		for(i=0;i<7;i++){
			tiempo[i]=(tiempo[i]/tiempo[6])*127; //escalando tiempos
			tiempo_actual=tiempo[i]; //eliminando parte decimal
//dibujando puntos en la GLCD//////
for(j=tiempo_anterior;j<=tiempo_actual;j++)
{ if(valor[i]==0)Glcd_Dot(j, 40, 2);
else if(valor[i]==1)Glcd_Dot(j, 20, 2);
}
///////////////////////////////////
Glcd_V_Line(20, 40, tiempo_actual, 1);
tiempo_anterior=tiempo_actual;
}
//reestableciendo variables///
pulsos=0;
tiempo_anterior=0;
i=0;
nivel=0;
IC1CON1bits.ICM=1;//módulo activado
TMR1=0;
//////////////////////////////
delay_ms(1000);
}
}