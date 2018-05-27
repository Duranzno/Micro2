// 2.8.- Se debe activar y visualizar un reloj digital,
//usando el RTCC del DsPIC,
//con la opción de programar la fecha y
// hora inicial y una alarma repetitiva
//cada 30 , 60 , 90 o 120 segundos, y
// que una vez activada, encienda y apague un led externo.
// Nota: Estudiantes que logre activar el RTCC
//usando el cristal externo de 32 Khz obtendrá una nota extra.
#define RTCC_NONE	0
#define RTCC_30 	1
#define RTCC_60 	2
#define RTCC_90 	3
#define RTCC_120 	4
#define SEG 0
#define MIN 1
#define HOR 2
#define DIA 3
#define MES 4
#define ANO 5
#define SEM 6
#define SEGMIN 	0
#define HORSEM 	1
#define DIAMES 	2
#define ANONAD 3
unsigned short rtcc_VAL=0,RTCBandera=0,CASO_ALARMA=RTCC_NONE;
unsigned short 	u_hora	[7]={0,0,0,0,0,0,0};
char  buffer[30];


/*fecha tiene {Unidad_DIA,Decena_Dia,Unidad_A~o,Decena A~o}
rtc_hora es una copia de RTCVAL en su config cochina de microchip
rtc_hora[6]{seg,min,hora,dia,mes,a~o}*/
int rtc_hora[4]={0X0000,0X0101,0X0101,0X0001};
// ***_hora[4]{SEGMIN,HORAdiadelasemana,DIAMES,ANONAD} se usan las mayusculas

//~~~~~~~~~~~~~~~~~~~~~~~Capa Hardware~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void rtcc_write(){
	RTCVAL = rtc_hora[ANONAD];	RTCVAL = rtc_hora[DIAMES];
	RTCVAL = rtc_hora[HORSEM];	RTCVAL = rtc_hora[SEGMIN];
}
void rtcc_read(){
	while(RCFGCALbits.RTCSYNC==0){
	rtc_hora[ANONAD]=RTCVAL;	rtc_hora[DIAMES]=RTCVAL;
	rtc_hora[HORSEM]=RTCVAL;	rtc_hora[SEGMIN]=RTCVAL;
	}
}
void RTCC_assembler (){
	asm {MOV # 0x55, W0}
	asm {MOV W0, NVMKEY }
	asm {MOV # 0xAA, W0 }
	asm {MOV W0, NVMKEY }
	asm {BSET RCFGCAL, # RTCWREN;}// Setea el bit RTCWREN
	RCFGCALbits.RTCEN = 0;// Limpia bit RTCEN , desactiva modulo
	ALCFGRPTbits.ALRMEN=0; //desactivar alarma
	// Escribe a Timer RTCC
	RCFGCALbits.RTCOE = 1; // habilita el pulso de salida RTCC
	PADCFG1bits.RTSECSEL = 0; // salida de la alarma
	//Configura la fecha y hora al RTC
	RCFGCALbits.RTCPTR = 3;
	rtcc_write();
	RCFGCALbits.RTCEN = 1; // activa modulo
	RCFGCALbits.RTCWREN = 0; // deshabilita escritura en RTCC
	delay_ms(1000);
}
void config_RTCC(){
	OSCCONbits.LPOSCEN=1; //activa el oscilador secundario
	RTCC_assembler();
	IFS3bits.RTCIF=0;//Habilitacion de Interrupcion
	IEC3bits.RTCIE=1;
	IPC15bits.RTCIP=10;
	PADCFG1bits.RTSECSEL=1; // habilita salida de reloj a un segundo
	RCFGCALbits.CAL=1; //ajusta a cero
	RCFGCALbits.RTCOE=1; // habilita el pin RTCC ( se puede usar para verificar que el RTCC está funcionando )
}
void config_Pwm_reloj() {
	PTPER = 458; /* Periodo del PWM en tiempo base primario */
	/* Desplazamiento de fase */
	PHASE1 = 0;
	/* Ciclo útil*/
	PDC1 = 224;
	/* Tiempo muerto*/
	DTR1 = 10;
	ALTDTR1 = 10;
	/* Modo Push-Pull */
	IOCON1 =  0xC800;
	/* Tiempo base primario, Modo Flanco Alineado y ciclo útil independiente */
	PWMCON1 =  0x0000;
	/* prescaler 1:1 */
	PTCON2 = 0x0000;
	/* habilitación de módulo PWM*/
	PTCON = 0x8000;
}
//~~~~~~~~~~~~~~~~~~~~Movimiento entre capas~~~~~~~~~~~~~~~~~~~~
void rtc2int(){
	u_hora[SEG]= Bcd2Dec( rtc_hora[SEGMIN] & 0x00FF);
	u_hora[MIN]= Bcd2Dec((rtc_hora[SEGMIN] & 0xFF00)>>8);
	u_hora[DIA]= Bcd2Dec( rtc_hora[DIAMES] & 0x00FF);
	u_hora[MES]= Bcd2Dec((rtc_hora[DIAMES] & 0xFF00)>>8 );
	u_hora[HOR]= Bcd2Dec( rtc_hora[HORSEM] & 0x00FF);
  	u_hora[ANO]= Bcd2Dec( rtc_hora[ANONAD] & 0x00FF);
}
void int2rtc(){
	rtc_hora[ANONAD]=(Dec2Bcd(u_hora[ANO]));
	rtc_hora[DIAMES]=Dec2Bcd(u_hora[DIA])|(Dec2Bcd(u_hora[MES])<<8);
	rtc_hora[HORSEM]=Dec2Bcd(u_hora[HOR]);
	rtc_hora[SEGMIN]=Dec2Bcd(u_hora[SEG])|(Dec2Bcd(u_hora[MIN])<<8);
}

//hid