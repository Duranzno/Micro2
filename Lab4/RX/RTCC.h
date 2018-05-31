// 2.8.- Se debe activar y visualizar un reloj digital,
//usando el RTCC del DsPIC,
//con la opción de programar la fecha y
// hora inicial y una alarma repetitiva
//cada 30 , 60 , 90 o 120 segundos, y
// que una vez activada, encienda y apague un led externo.
// Nota: Estudiantes que logre activar el RTCC
//usando el cristal externo de 32 Khz obtendrá una nota extra.
#define RTCC_NONE        0
#define RTCC_30         1
#define RTCC_60         2
#define RTCC_90         3
#define RTCC_120         4

unsigned short rtcc_VAL=0,RTCBandera=0,CASO_ALARMA=RTCC_NONE;
char  buffer[30];
unsigned short int anio=0,mes=0,dia=0,hora=0,seg=0,minn=0 ;

/*fecha tiene {Unidad_DIA,Decena_Dia,Unidad_A~o,Decena A~o}
rtc_hora es una copia de RTCVAL en su config cochina de microchip
rtc_hora[6]{seg,min,hora,dia,mes,a~o}*/
int year=0x0000, mesydia=0x0000, diasyhora=0x0000, minyseg=0x0000;
// ***_hora[4]{SEGMIN,HORAdiadelasemana,DIAMES,ANONAD} se usan las mayusculas

//~~~~~~~~~~~~~~~~~~~~~~~Capa Hardware~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void rtcc_read(){
        //while(RCFGCALbits.RTCSYNC==0){
        RCFGCALbits.RTCPTR=3;
            year=RTCVAL;
            mesydia=RTCVAL;
            diasyhora=RTCVAL;
            minyseg=RTCVAL;
        //}
}
void RTCC_assembler (short yea,short mon,short day,short hor,short min,short seg){
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
         RCFGCALbits.RTCPTR=3;
        RTCVAL = Dec2Bcd(yea);
        RTCVAL = (Dec2Bcd(day)|Dec2Bcd(mon)<<8);
        RTCVAL = Dec2Bcd(hor);
        RTCVAL = (Dec2Bcd(seg)|Dec2Bcd(min)<<8);
        RCFGCALbits.RTCEN = 1;
        RCFGCALbits.RTCWREN = 0; // deshabilita escritura en RTCC
        delay_ms(1000);
}
void config_RTCC(){
        OSCCONbits.LPOSCEN=1; //activa el oscilador secundario
        RTCC_assembler(96,04,01,05,15,05);
        PADCFG1bits.RTSECSEL=1; // habilita salida de reloj a un segundo
        RCFGCALbits.CAL=1; //ajusta a cero
        RCFGCALbits.RTCOE=1; // habilita el pin RTCC ( se puede usar para verificar que el RTCC está funcionando )
        IFS3bits.RTCIF=0;//Habilitacion de Interrupcion
        IEC3bits.RTCIE=1;
        IPC15bits.RTCIP=6;
}
//~~~~~~~~~~~~~~~~~~~~Movimiento entre capas~~~~~~~~~~~~~~~~~~~~
void rtc2int(){
            anio= Bcd2Dec( year & 0x00FF );
            mes= Bcd2Dec((mesydia & 0xFF00)>>8 );
            dia= Bcd2Dec( mesydia & 0x00FF );
            hora= Bcd2Dec( diasyhora & 0x00FF );
            minn= Bcd2Dec((minyseg & 0xFF00)>>8 );
            seg= Bcd2Dec( minyseg & 0x00FF );
            //minn=minn-64;
            //hora=hora-20

            //dia=dia-159;
}
void int2rtc(){
        year=(Dec2Bcd(anio));
        mesydia=Dec2Bcd(dia)|(Dec2Bcd(mes)<<8);
        diasyhora=Dec2Bcd(hora);
        minyseg=(Dec2Bcd(seg)|(minn)<<8);
}

//hid