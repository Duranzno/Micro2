//_____//~~~~~~~~~~~~~~~~~~Constantes  del dsPIC~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Variables de PS2
sbit PS2_Data at RF4_bit;
sbit PS2_Clock at RF5_bit;
sbit PS2_Data_Direction at TRISF4_bit;
sbit PS2_Clock_Direction at TRISF5_bit;
//Variables de GLCD
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
//~~~~~~~~~~~~~~~~~~~~~~Configuraciones Iniciales~~~~~~~~~~~~~~~~~~~~~~~~~~
  void config_IO(){
    ANSELB=0;
    ANSELC=0;
    ANSELD=0;
    ANSELE=0;
    ANSELG=0;             //ANA//logiCO SON B Y F
    TRISB=0xffff;
    TRISE=0;
    TRISG=0;
    TRISDbits.TRISD11=1;  // desde rd11 a rd8 son  entradas del modulo captura
    TRISDbits.TRISD10=1;
    TRISDbits.TRISD9=1;
    TRISDbits.TRISD8=1;
    TRISFbits.TRISF3=0;  // salida paola
    TRISEbits.TRISE5=0;
    TRISEbits.TRISE7=0;
    TRISGbits.TRISG6=0;
    TRISGbits.TRISG8=0;
    RPOR6bits.RP85R =0b010000;     //pin comparador 1  RE5
    RPOR6bits.RP87R =0b010001;    //pin comparador 2  RE7
    RPOR13bits.RP118R=0b010010;  //pin comparador 3 RG6
    RPOR14bits.RP120R=0b010011;//Las entradas del teclado y las salidas de la pantalla son manejadas por las librerias;
    RPOR0bits.RP64R=0b010100;
}
void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
}
void config_pin () {
  TRISDbits.TRISD11=1; // pin D11 como entrada
  RPINR7bits.IC1R=75; //captura 1 por el D11
  TRISDbits.TRISD10=1;// pin D10 como entrada
  RPINR8bits.IC3R=74; // captura 3 por el d10
  TRISDbits.TRISD9=1; // pin d09 como entrada
  RPINR9bits.IC5R=73; // captura 5 por el d09 
  TRISDbits.TRISD8=1; // pin D08 como entrada
  RPINR34bits.IC11R=72; //captura 7 por el d08

}
void config_captura (){
        //-------------timer2-----------------------
  TMR2=0;
  T2CONbits.TCKPS=2; // Prescaler 64:1, modo timer
  T2CONbits.TGATE=0;
  T2CONbits.TCS=0;
  PR2=31250; //1000ms
  IEC0bits.T2IE=1;//enable interrupcion
  IFS0bits.T2IF=0;//limpia bandera
    //--------------captura 2----------------------
  IC2CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
  IC2CON1bits.ICM=5; // captura cada 4 flancos positivos
//---------------configuracion captura 2 como 32 bits-------------
  IC2CON2bits.IC32=1; //configuracion 32 bits
  //----------------captura 1------------------
  IC1CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
  IC1CON1bits.ICM=5; // captura cada 4 flancos positivos
 // T1CONbits.TON=1; //enciende timer 1
  IEC0bits.IC1IE=1; //habilita interrupciÃ³n del IC1
  IFS0bits.IC1IF=0; //limpia la bandera de interrupciÃ³n
  //------------configuracion captura 1 como 32 bits------------
  IC1CON2bits.IC32=1; //configuracion 32 bits;
  
     //--------------captura 4----------------------
  IC4CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
  IC4CON1bits.ICM=5; // captura cada 4 flancos positivos
//---------------configuracion captura 4 como 32 bits-------------
  IC4CON2bits.IC32=1; //configuracion 32 bits
  //----------------captura 3------------------
  IC3CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
  IC3CON1bits.ICM=5; // captura cada 4 flancos positivos
 // T1CONbits.TON=1; //enciende timer 1
  IEC2bits.IC3IE=1; //habilita interrupciÃ³n del IC1
  IFS2bits.IC3IF=0; //limpia la bandera de interrupciÃ³n
  //------------configuracion captura 3 como 32 bits------------
  IC3CON2bits.IC32=1; //configuracion 32 bits;
  
     //--------------captura 6----------------------
  IC6CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
  IC6CON1bits.ICM=5; // captura cada 4 flancos positivos
//---------------configuracion captura 6 como 32 bits-------------
  IC6CON2bits.IC32=1; //configuracion 32 bits
  //----------------captura 5------------------
  IC5CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
  IC5CON1bits.ICM=5; // captura cada 4 flancos positivos
 // T1CONbits.TON=1; //enciende timer 1
  IEC2bits.IC5IE=1; //habilita interrupciÃ³n del IC1
  IFS2bits.IC5IF=0; //limpia la bandera de interrupciÃ³n
//------------configuracion captura 1 como 32 bits------------
  IC5CON2bits.IC32=1; //configuracion 32 bits
//--------------captura 12----------------------
  IC12CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
  IC12CON1bits.ICM=5; // captura cada 4 flancos positivos
//---------------configuracion captura 12 como 32 bits-------------
  IC12CON2bits.IC32=1; //configuracion 32 bits
  //----------------captura 11------------------
  IC11CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
  IC11CON1bits.ICM=5; // captura cada 4 flancos positivos
 // T1CONbits.TON=1; //enciende timer 1
  IEC7bits.IC11IE=1; //habilita interrupciÃ³n del IC1
  IFS7bits.IC11IF=0; //limpia la bandera de interrupciÃ³n
  //------------configuracion captura 1 como 32 bits------------
  IC5CON2bits.IC32=1; //configuracion 32 bits;
}
void config_cron(){
  //PR1=22938; //1000ms
//  TMR1=0;
  IEC0bits.T1IE=1;
  IFS0bits.T1IF=0;
  IPC0bits.T1IP=3;
//  T1CONBits.TGATE=0;
//  T1CONBits.TSYNC=0;
//  T1CONBits.TCS=0;//TGATE, TSYNC Y TCS Habilitan modo TEMP
//  T1CONBits.TCKPS=1;
//  T1conbits.TON=0;
  TMR1=0;
	T1CON=0X8020; //Prescaler 64:1, modo timer
	PR1=3125;
}
void config_TMR_45(){
  IEC1bits.T4IE=1;
  IEC1bits.T5IE=1;
  IFS1bits.T4IF=0;
  IFS1bits.T5IF=0;
  T4CONbits.TCKPS=0;            //preescaler 1:1
  T4CONbits.TCS=0;
  TMR4=0;
  PR4=2000;                    // timer a 1ms
  T5CONbits.TCKPS=5;            //prescaler 256:1
  T5CONbits.TCS=0;
  TMR5=0;
  PR5=39062; // timer a 5s

}
void config_OC(){
  OC5CON1bits.OCTSEL=7;
  OC1CON1bits.OCTSEL=2;        // T4CLK fuente de reloj
  OC2CON1bits.OCTSEL=2;
  OC3CON1bits.OCTSEL=2;
  OC4CON1bits.OCTSEL=2;
  OC1CON2bits.OCTRIS=1;
  OC2CON2bits.OCTRIS=1;
  OC3CON2bits.OCTRIS=1;
  OC4CON2bits.OCTRIS=1;
  OC5CON2bits.OCTRIS=1;
  
  OC5CON1bits.OCM=5;
  OC1CON1bits.OCM=5;          //MODO COMPARADOR DUAL DE PULSOS CONTINUOS
  OC2CON1bits.OCM=5;
  OC3CON1bits.OCM=5;
  OC4CON1bits.OCM=5;
  OC5R=306; OC5RS=2047;
  OC1R=306; OC1RS=2047;     //CICLO UTIL 15%
  OC2R=921; OC2RS=2047;     //CICLO UTIL 45%
  OC3R=1227; OC3RS=2047;     //CICLO UTIL 60%
  OC4R=1637; OC4RS=2047;     //CICLO UTIL 80%
  OC1CON2bits.SYNCSEL=0b01111;    //disparo con el OC 5
  OC2CON2bits.SYNCSEL=0b00101;
  OC3CON2bits.SYNCSEL=0b01111;
  OC4CON2bits.SYNCSEL=0b01111;
  OC5CON2bits.SYNCSEL=0b01111;
}
void config_INT(){
  SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
  INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
  INTCON2bits.GIE=1; //interrupciones habilitadas
  CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
//------------------------- habilitacion de interrupcion
  IPC0bits.T1IP=2;
  IPC1bits.T2IP=4;
  IPC6bits.T4IP=2;
  IPC7bits.T5IP=3;
  IPC0bits.IC1IP=2;
  IPC9bits.IC3IP=2;
  IPC9bits.IC5IP=2;
  IPC31bits.IC11IP=2;
 // IPC1bits.IC2IP=2;
 }