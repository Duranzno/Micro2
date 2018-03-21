#include "barras.h"
#include "sprites.h"
//~~~~~~~~~~~~~~~~~~Constantes  del dsPIC~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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

//____________________________________________________________________________________________________________________________________
//~~~~~~~~~~~~~~~~~~Constantes  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Constantes de las ubicaciones de los pines
const int BTN_PPS_LOCATIONS[5]={-1,37,36,35,34};//5 posiciones para las 4 Ubicaciones de los botones de Interrupciion del ejercicio 1
// el 0 nunca se usa porque INT0 esta fijo en el pin 46 RP64. RB2-5
const int DIP_PPS_LOCATIONS[5]={32,33,38,39,40};//5 posiciones para 5 Dipswitches RPI32,33,38,39,40 Y RB0,1,6,7,8
const int KEYBOARD_PPS_LOCATIONS[2]={100,101};//RF4,RF5
//const int LED_PPS_LOCATIONS[3]={85,87,118};//3 posiciones para 3 LEDS de salida    RE5,RE7,RG6

//Variables de trabajo
int counters[5]={0,0,0,0,0};
int valores_cn[4]={0,0,0,0};
unsigned short keydata = 0, special = 0, down = 0,casoQactivo=0;
//____________________________________________________________________________________________________________________________________
//~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void InterrAdapter(int Ix);
void bar_drawer(unsigned short x_left,unsigned short contador_barra);
int DrawableBars(int real_number_of_bars);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void INT0() org 0x14{
  InterrAdapter(0);
  delay_ms(600);
  IFS0bits.INT0IF=0;
}
void INT1() org 0x3C{
  InterrAdapter(1);
  delay_ms(600);
  IFS1bits.INT1IF=0;
}
void INT2() org 0x4E{
  InterrAdapter(2);
  delay_ms(600);
  IFS1bits.INT2IF=0;
}
void INT3() org 0x7E{
  InterrAdapter(3);
  delay_ms(600);
  IFS3bits.INT3IF=0;
}
void INT4() org 0x80{
  InterrAdapter(4);
  delay_ms(600);
  IFS3bits.INT4IF=0;
}
void INT_CN() org 0x3A{
  IFS1bits.CNIF = 0;
  if(PORTBbits.RB5 ==1){
      valores_cn[0]=1;
      valores_cn[1]=0;
      valores_cn[2]=0;
      valores_cn[3]=0;

  }else if(PORTBbits.RB4==1){
      valores_cn[0]=0;
      valores_cn[1]=1;
      valores_cn[2]=0;
      valores_cn[3]=0;
  }else if(PORTBbits.RB3==1){
      valores_cn[0]=0;
      valores_cn[1]=0;
      valores_cn[2]=1;
      valores_cn[3]=0;
  }else if(PORTBbits.RB2==1){
      valores_cn[0]=0;
      valores_cn[1]=0;
      valores_cn[2]=0;
      valores_cn[3]=1;
  }
  if(PORTBbits.RB1==1){
      RCONbits.SWDTEN=1;
      Glcd_Write_TEXT("INT WDT",0,0,1);
}
  delay_ms(1000);
  Glcd_Fill(0);
}
void InterrAdapter(int Ix){
  if(casoQactivo==1){
    counters[Ix]++;
    barra(Ix,counters[Ix]);
  }
}
//~~~~~~~~~~~~~~~~~~~~~~Configuraciones Iniciales~~~~~~~~~~~~~~~~~~~~~~~~~~
void config_IO(){
  ANSELB=0;
  ANSELC=0;
  ANSELD=0;
  ANSELE=0;
  ANSELG=0;             //ANA//logiCO SON B Y F
  TRISB=0xffff;
  TRISDbits.TRISD0=1;
  TRISDbits.TRISD11=1;
  TRISDbits.TRISD10=1;
  TRISDbits.TRISD9=1;
  TRISE=0;
  TRISG=0;
//Entrada Botones y Dipswitches
//Las entradas del teclado y las salidas de la pantalla son manejadas por las librerias;
}
void config_LCD(){
  Glcd_Init();
  Glcd_Set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
}
void config_CN(){//CNENx, CNPUx,CNIEx
     CNENBbits.CNIEB5=1;CNENBbits.CNIEB4=1;     CNENBbits.CNIEB3=1;
     CNENBbits.CNIEB2=1;CNENBbits.CNIEB1=1;

     CNPUBbits.CNPUB5=1;//CNPU RB1-rb5, rpi33-37
     CNPUBbits.CNPUB4=1;CNPUBbits.CNPUB3=1;
     CNPUBbits.CNPUB2=1;CNPUBbits.CNPUB1=1;
      
     IPC4bits.CNIP=7;//Prioridad
     IFS1bits.CNIF=0;     IEC1bits.CNIE=1;//Resset Interrupcion
}
void config_INT(){
  SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
  INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
  INTCON2bits.GIE=1; //interrupciones habilitadas
  CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
//------------------------- habilitacion de interrupcion
  IEC0bits.INT0IE=1; //HABILITA INTERRUPCION POR INT0
  IEC1bits.INT1IE=1; //HABILITA
  IEC1bits.INT2IE=1;  IEC3bits.INT3IE=1; IEC3bits.INT4IE=1;
  //prioridad int
// Banderas de Interrupcion post Reset (Limpieza)
  IFS0bits.INT0IF=0; //interrupcion de INT0 ACTIVADA
  IFS1bits.INT2IF =0; // interrupcion de INT1 ACTIVADA
  IFS1bits.INT2IF =0 ; // INTERRIPCION DE INT2 ACTVADA
  IFS3bits.INT3IF =0; //INTERRUPCION DE INT3 ACTIVADA
  IFS3bits.INT4IF =0; // INTERRUPCION DE INT4 ACTIVADA
//Prioridad de Interrupciones
   counters[0]=0;  counters[1]=0;  counters[2]=0;
  counters[3]=0;  counters[4]=0;
//--------------------interrupcion flanco positivo
  INTCON2bits.INT0EP=0;  INTCON2bits.INT1EP=0;
  INTCON2bits.INT2EP=0;  INTCON2bits.INT3EP=0;
  INTCON2bits.INT4EP =0;
//PPS para los pines de Interrupcion
  RPINR0bits.INT1R=75;  RPINR1bits.INT2R=74;
  RPINR1bits.INT3R=73;  RPINR2bits.INT4R=72;
}
void disable_INT(){
  IPC0bits.INT0IP= 0;  IPC5BITS.INT1IP=0;
  IPC7bits.INT2IP =0;  IPC13bits.INT3IP=0;
  IPC13bits.INT4IP=0;
  counters[0]=0;  counters[1]=0;
  counters[2]=0;  counters[3]=0;
  counters[4]=0;
  casoQactivo=0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Casos~~~~~~~~~~~~~~~~~~~~~~~~
void casoQ(){
  IPC0bits.INT0IP= 6;  IPC5BITS.INT1IP=5;
  IPC7bits.INT2IP =4;  IPC13bits.INT3IP=3;
  IPC13bits.INT4IP=2;  Glcd_Fill(0);
  casoQactivo=1;
  do{
    down=0;special=0;keydata=0;
    Ps2_Key_Read(&keydata, &special, &down);
  }while(keydata!=34 && !down & !special);
  disable_INT();
  Glcd_Fill(0);
  disable_INT();
}
void casoW(){
  valores_cn[0]=0;  valores_cn[1]=0;
  valores_cn[2]=0;  valores_cn[3]=0;
  Glcd_Fill(0)   ;
  Glcd_Write_TEXT("Caso 2",0,0,1);
  delay_ms(1000);
  do{
    Glcd_Fill(0);
    down=0;special=0;keydata=0;
    if(valores_cn[0]==1){
      animate_charmander_5s();
    }
    else if(valores_cn[1]==1){
      animate_kirby_5s(0,0);
    }
    else if(valores_cn[2]==1){
      animate_shell_5s(0,0);
    }
    else if(valores_cn[3]==1){
      animate_bullet_5s()
    }   
    Ps2_Key_Read(&keydata, &special, &down);
  }while(keydata!=34 && !down & !special);
}

void casoE(){
 Glcd_Fill(0);
    Glcd_Write_TEXT("Caso E",60,0,1);
  do{
     down=0;
     special=0;
    if (RCONbits.WDTO==1){
      Glcd_Write_TEXT("WDT",0,1,1);
      RCONbits.WDTO=0;
      PORTEbits.RE5=1;
      animate_dog_20s();
    }else if(RCONbits.EXTR==1){
      Glcd_Write_TEXT("MCLR",0,2,1);
      RCONbits.EXTR=0;
      RCONbits.POR=0;
      PORTEbits.RE7=1;
      animate_blooper_20s();
      continue;
    }else if (RCONbits.POR==1){
      Glcd_Write_TEXT("POR",0,3,1);
      RCONbits.POR=0;
      PORTGbits.RG6=1;
      animate_charmander_20s();
      break;
    }

    Ps2_Key_Read(&keydata, &special, &down);
  }while(keydata!=34&&!down&&!special);
     LATEbits.LATE5=0;    

  LATEbits.LATE7=0;
  LATGbits.LATG6=0;
  //  PORTGbits.RG6=0;
//  PORTEbits.RE7=0;
//  PORTEbits.RE5=0;
}

void main(){
  config_IO();  config_LCD();
  config_INT();  config_CN();
  animate_charmander_5s();
  PS2_Config();  Glcd_Fill(0);
  while(1){
    Glcd_Write_TEXT("Laboratorio 1",31,0,1);
    Glcd_Write_TEXT("'Q' para Caso Q",0,1,1);
    Glcd_Write_TEXT("'W' para Caso W",0,2,1);
    Glcd_Write_TEXT("'E' para Caso E",0,3,1);
    Glcd_Write_TEXT("'R' para WDT   ",0,4,1);
    if(Ps2_Key_Read(&keydata, &special, &down)){
 if(down &&!special){
        switch(keydata){
          case 'q':
          case 'Q':
            Glcd_Write_TEXT("Caso Q",60,0,1);
            casoQ();
            break;
          case 'w':
          case 'W':
            Glcd_Write_TEXT("Caso W",60,0,1);
            casoW();
            Glcd_Fill(0);
            break;
          case 'e':
          case 'E':
            Glcd_Fill(0);
            Glcd_Write_TEXT("Ultimo Reset",60,0,1);
            casoE();
            Glcd_Fill(0);
            break;
          default:
            Glcd_Fill(0);
            Glcd_Write_TEXT("Erroneo ",60,0,1);
            delay_ms(2000);
            break;
          }
        }
      }
    }
}