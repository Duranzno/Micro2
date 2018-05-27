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
unsigned short rtcc_VAL=0,RTCIF=0,CASO_ALARMA=RTCC_NONE;
unsigned short 	u_hora	[7]={0,0,0,0,0,0,0};
char  buffer[30];
void INT_RELOJ()org 0x000090{
	switch(CASO_ALARMA){
		case RTCC_30:
		switch_led();
		break;
		case RTCC_60:
		if(RTCIF%2==0){switch_led();}
		break;
		case RTCC_90:
		if(RTCIF%3==0){switch_led();}
		break;
		case RTCC_120:
		if(RTCIF%4==0){switch_led();}
		break;
		default:
		case RTCC_NONE:
		RTCIF=0;
		break;
	}
	RTCIF++;
	IFS3bits.RTCIF=0;
}

/*fecha tiene {Unidad_DIA,Decena_Dia,Unidad_A~o,Decena A~o}
rtc_hora es una copia de RTCVAL en su config cochina de microchip
rtc_hora[6]{seg,min,hora,dia,mes,a~o}*/
int rtc_hora[4]=0{'0X0000','0X0101','0X0101','0X0001'}
// ***_hora[4]{SEGMIN,HORAdiadelasemana,DIAMES,ANONAD} se usan las mayusculas

//~~~~~~~~~~~~~~~~~~~~~~~Capa Hardware~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void rtcc_write(){
	RTCVAL = rtc_hora[ANONAD];	RTCVAL = rtc_hora[DIAMES];
	RTCVAL = rtc_hora[HORSEM];	RTCVAL = rtc_hora[MINSEG];
}
void rtcc_read(){
	while(RCFGCALbits.RTCSYNC==0){
	rtc_hora[ANONAD]=RTCVAL;	rtc_hora[DIAMES]=RTCVAL;
	rtc_hora[HORSEM]=RTCVAL;	rtc_hora[MINSEG]=RTCVAL;
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
	RTCC_assembler();
	IFS3bits.RTCIF=0;
	IEC3bits.RTCIE=1;
	IPC15bits.RTCIP=10;
	PADCFG1bits.RTSECSEL=1; // habilita salida de reloj a un segundo
	RCFGCALbits.CAL=1; //ajusta a cero
	RCFGCALbits.RTCOE=1; // habilita el pin RTCC ( se puede usar para verificar que el RTCC está funcionando )
	//	OSCCONbits.LPOSCEN=1; //activa el oscilador secundario
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
void int2rtc(){int i;
	rtc_hora[ANONAD]=(Dec2Bcd(u_hora[ANO]));
	rtc_hora[DIAMES]=Dec2Bcd(u_hora[DIA])|(Dec2Bcd(u_hora[MES])<<8);
	rtc_hora[HORSEM]=Dec2Bcd(u_hora[HOR]);
	rtc_hora[SEGMIN]=Dec2Bcd(u_hora[SEG])|(Dec2Bcd(u_hora[MIN])<<8);
}
//~~~~~~~~~~~~~~~~~~~~~~~Caso 4~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void update_hid(){
	sprintf(buffer,"%u:%u:%u del dia %u del mes %u,del año%s",u_hora[HOR],u_hora[MIN],u_hora[SEG],u_hora[DIA],u_hora[MES],u_hora[ANO]);
	logd(buffer);
}
//Configutacion Hora
//usar programar_RTCC, programar Alarma;
void programar_RTCC(){
	int i;
	u_hora={0,0,0,0,0,0,0};
	hid_configuracion_hora();
	for(i=0;i<6;i++){
		u_hora[i]=update_hid_hora();
		hid_configuracion_hora();

	}
}
unsigned int update_hid_hora(){
	unsigned short i,j;
	while(!HID_Read());
	i=readbuff[0]-'0';
	j=readbuff[1]-'0';
	return (j*10+i);
}
void hid_configuracion_hora(){
	sprintf(buffer,"SEGUNDO 		(0-59)%u",u_hora[SEG]);write(buffer);
	sprintf(buffer,"MINUTO 		    (0-59)%u",u_hora[MIN]);write(buffer);
	sprintf(buffer,"HORA 		    (0-23)%u",u_hora[HOR]);write(buffer);
	sprintf(buffer,"DIA    (1-28/29/30/31)%u",u_hora[DIA]);write(buffer);
	sprintf(buffer,"MES 			(1-12)%u",u_hora[MES]);write(buffer);
	sprintf(buffer,"AÑO 			(0-99)%u",u_hora[ANO]);write(buffer);
}

//Alarma
void programar_Alarma(int RTCC_CASE){
	RCFGCALbits.RTCEN = 0;
	ALCFGRPTbits.AMASK=0b0000;
	ALRMPTR=10;
	hid_config_al();
	RTCIF=0;
	while(!HID_Read());
            for(cnt=0;cnt<64;cnt++) {
                    writebuff[cnt]=readbuff[cnt];
            }
            if(strcmp(readbuff,caso_1)==0){//CASE 1
                CASO_ALARMA=RTCC_30;
            }
            else if(strcmp(readbuff,caso_2)==0){//CASE 2
                CASO_ALARMA=RTCC_60;
            }
            else if(strcmp(readbuff,caso_3)==0){//CASE 3
            	CASO_ALARMA=RTCC_90;
            }
            else if(strcmp(readbuff,caso_4)==0){//CASE 3
            	CASO_ALARMA=RTCC_120;
            }
	ALRMVAL = 0x0000;//MESDIAS
	ALRMVAL = 0x0000;//SEMHOR
	ALRMVAL = 0x0000;//MINSEC	
	ALCFGRPTbits.CHIME = 1;
	ALCFGRPTbits.ALRMEN = 1;

}
void hid_config_al(){
        write(config_al);
        write("--------------------------------------------------");
        write("CASO A Cada 30s");
        write("CASO B Cada 60s");
        write("CASO C Cada 90s");
        write("CASO D Cada 120s");
        space(5);        
}
