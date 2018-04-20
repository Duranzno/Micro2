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
    RPOR14bits.RP120R=0b010011;
    RPOR0bits.RP64R=0b010100;// pin comparador 4 RG8
}
void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
}
void config_pin () {
}
void config_INT(){
  SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
  INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
  INTCON2bits.GIE=1; //interrupciones habilitadas
  CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
//------------------------- habilitacion de interrupcion
  
 }