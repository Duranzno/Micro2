//Variables de GLCD
sbit GLCD_D0 at RD4_bit;
sbit GLCD_D1 at RD5_bit;
sbit GLCD_D2 at RD6_bit;
sbit GLCD_D3 at RD7_bit;
sbit GLCD_D4 at RF0_bit;
sbit GLCD_D5 at RF1_bit;
sbit GLCD_D6 at RE0_bit;
sbit GLCD_D7 at RE1_bit;
sbit GLCD_CS1 at LATE2_bit;
sbit GLCD_CS2 at LATE3_bit;
sbit GLCD_RS at LATD1_bit;
sbit GLCD_RW at LATD2_bit;
sbit GLCD_EN at LATD3_bit;
sbit GLCD_RST at LATC14_bit;

sbit GLCD_D0_Direction at TRISD4_bit;
sbit GLCD_D1_Direction at TRISD5_bit;
sbit GLCD_D2_Direction at TRISD6_bit;
sbit GLCD_D3_Direction at TRISD7_bit;
sbit GLCD_D4_Direction at TRISF0_bit;
sbit GLCD_D5_Direction at TRISF1_bit;
sbit GLCD_D6_Direction at TRISE0_bit;
sbit GLCD_D7_Direction at TRISE1_bit;
sbit GLCD_CS1_Direction at TRISE2_bit;
sbit GLCD_CS2_Direction at TRISE3_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISC14_bit;
//~~~~~~~~~~~~~~~~~~~~~~Configuraciones Iniciales~~~~~~~~~~~~~~~~~~~~~~~~~~
void config_RTCC(){
  
}
void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
}
void led_switch() {
   LATFBITS.LATF5=~LATFBITS.LATF5;
}
void config_IO(){
  ANSELB=ANSELC=ANSELD=ANSELE=0;
  TRISDbits.TRISD0=1;   //Pines falla
  TRISDbits.TRISD11=1;  //Pines falla
  TRISDbits.TRISD9=1;   //entrada opto para motor 1
  TRISDbits.TRISD8=1;   //entrada opto para motor 2
  TRISFbits.TRISF4=0;   //LED de prueba;
  RPOR9bits.RP101R=1;   //U1TX
  RPINR0bits.INT1R=73;  // RPI73 en INT1 motor 1 RPM 
  RPINR1bits.INT2R=72;  // RPI72 en INT2 motor 2 RPM
  RPINR18bits.U1RXR=46; //U1RX
  RPINR13bits.FLT4R=75; // pin de falla pwm4
  RPINR13bits.FLT3R=64; //pin de falla pwm3
}

void config_TMR2_ANIM () {
  TMR2=0;
  T2CON=0x0030; //Prescaler 256:1, modo timer
  PR2=65350; //1000ms
  IEC0bits.T2IE=1;
  IFS0bits.T2IF=0;
  IPC1bits.T2IP=7;
}
void config_USB(){
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

void config_INT(){
  SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
  INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
  INTCON2bits.GIE=1; //interrupciones habilitadas
  CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
 // IEC3bits.T8IE=1;
  IFS3bits.T7IF=0;
  IEC3bits.T7IE=1;
 // IPC12bits.T8IP=7;
  IPC12bits.T7IP=5;
 }

void config_timer8() {
  TMR8=0;
  PR8=58594;
  T8CON=0x0030;
}
void config_timer7() {
  TMR7=0;
  PR7=23438;
  T7CON=0x0030;
}

unsigned ajuste (unsigned control) {
 if (control<=20) {
   return 6500;
  }else
  if (control>20&&control<=60) {
  return 10000;
  } else
    if (control>60&&control<=80) {
  return 11000;
  } else
    if (control>80&&control<=90) {
  return 12000;
  }     else
    if (control>90&&control<=140) {
  return 15000;
  }         else
    if (control>140&&control<=160) {
  return 19000;
  }    else
    if (control>160&&control<=180) {
  return 20000 ;
  }        else
    if (control>180&&control<=210) {
  return 21500;
  }      else
    if (control>210&&control<=255) {
  return 23800;
  }
}