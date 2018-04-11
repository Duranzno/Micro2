 #define ENTER 13
#define ESC 34
#define LEFT_ARROW 30
#define RIGHT_ARROW 31
#define UP_ARROW 111
#define DOWN_ARROW 108
#define SANGRIA 6
unsigned short keydata = 0, special = 0, down = 0,y;
char txt[15];
char t[3],c1;
void clean_PS2(){ keydata = 0, special = 0, down = 0;}
//Cursores & Animaciones de Cursores
//Cursor Menu

void cursor_animation(int it){
  int i;
  for(i=1; i < 6; i++ ){
      if(i==it){
      Glcd_Write_Text("*",0,i,1);
      }else{
      Glcd_Write_Text(" ",0,i,1);
      }
  }
}
int cursor_menu(){
  //aqui se va a estar utilizando el it como iterator, revisando si el teclado
//ha seleccionado las flechas de arriba o abajo, aumentando o disminuyendo al operador
//SIEMPRE HAY 5 OPCIONES
  int it=1;
  while(keydata!=ENTER){
    cursor_animation(it);
    if(Ps2_Key_Read(&keydata, &special, &down)){
      if(down){
       if(keydata==DOWN_ARROW||keydata==UP_ARROW){
        if(keydata==DOWN_ARROW){
          it=it+1;
          if(it==6){it=1;}
          clean_PS2();
        }
        if(keydata==UP_ARROW){
          it=it-1;
          if(it==0){it=5;}
          clean_PS2();
        }
        cursor_animation(it);
      }
      if(keydata==ESC){
        Glcd_Write_TEXT("ESC" ,60,7,1);
        break;
      }
      }
    }
  }
    return it;
}
//Cursor Numero
void num_update(int it,int x_pos,int page){
  intToStr(it,t);
  Glcd_Write_Text(t,x_pos,page,1);
}
void parpadeo_barra(int x_pos){
//  Glcd_Write_Text("_",x_pos,7,2);  delay_ms(250);  Glcd_Write_Text("_",x_pos,7,2);  delay_ms(100);
//  Glcd_Write_Text("_",x_pos,7,2);  delay_ms(250);  Glcd_Write_Text("_",x_pos,7,2);  delay_ms(100);
//  Glcd_Write_Text("_",x_pos,7,2);  delay_ms(250);  Glcd_Write_Text("_",x_pos,7,2);  delay_ms(100);
}

//Texto del laboratorio
void texto_menu(){
        Glcd_Write_TEXT("Laboratorio 2",31,0,1);
    Glcd_Write_TEXT("'Q' Cronometro",0,1,1);
    Glcd_Write_TEXT("'W' Captura",0,2,1);
    Glcd_Write_TEXT("'E' PWM  ",0,3,1);
}
void texto_caso_1(){
  // GLCD_FILL(0);
  Glcd_Write_Text("Cronometro",60,0,1);
  Glcd_Write_Text("1) Programar Hora",SANGRIA,1,1);
  Glcd_Write_Text("2) PLAY"  ,SANGRIA,2,1);
  // Glcd_Write_pchar(play ,16,2,1);
  Glcd_Write_Text("3) PAUSE"  ,SANGRIA,3,1);
  // Glcd_Write_pchar(pause,16,3,1);
  Glcd_Write_Text("4) RESET  "  ,SANGRIA,4,1);
  // Glcd_Write_pchar(stop ,16,4,1);Glcd_Write_pchar(play ,30,4,1);
  Glcd_Write_Text("5) Alarma",SANGRIA,5,1);
}
void texto_caso_2(){
  GLCD_FILL(0);
  Glcd_Write_Text("Puerto de Entrada",SANGRIA,0,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,1,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,2,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,3,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,4,1);
  Glcd_Write_Text("5) Volver"   ,SANGRIA,5,1);
}
void texto_caso_3(){
  GLCD_FILL(0);
  Glcd_Write_Text("Puerto de Entrada",SANGRIA,0,1);
  Glcd_Write_Text("RP101/RG8 80%"  ,SANGRIA,4,1);
  Glcd_Write_Text("RP85 /RE5 15%"  ,SANGRIA,1,1);
  Glcd_Write_Text("RP87 /RE7 45%"  ,SANGRIA,2,1);
  Glcd_Write_Text("RP87 /RG6 60%"  ,SANGRIA,3,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,1,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,2,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,3,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,4,1);
}


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
  // TRISFbits.TRISF5=0; choca con el ps/2
  TRISEbits.TRISE5=0;
  TRISEbits.TRISE7=0;
  TRISGbits.TRISG6=0;
  TRISGbits.TRISG8=0;
  RPOR6bits.RP85R =0b010000;     //pin comparador 1  RE5
  RPOR6bits.RP87R =0b010001;    //pin comparador 2  RE7
  RPOR13bits.RP118R=0b010010;  //pin comparador 3 RG6
  RPOR14bits.RP120R=0b010011;
//Las entradas del teclado y las salidas de la pantalla son manejadas por las librerias;
}
void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
}
void config_pin () {
  TRISDbits.TRISD11=1; // pin D11 como entrada
  RPINR7bits.IC1R=75; //captura por el D11
}
void config_captura (){
  TMR1=0;
  T1CON=0X0020; // Prescaler 64:1, modo timer
  PR1=31250; //1000ms
  IC1CON1bits.ICTSEL=4; //usa como fuente de reloj el timer1
  IC1CON1bits.ICM=5; // captura cada 4 flancos positivos
  RPINR7bits.IC1R=75; //asigna IC1 al RPI75
 // T1CONbits.TON=1; //enciende timer 1
  IEC0bits.IC1IE=1; //habilita interrupciÃ³n del IC1
  IFS0bits.IC1IF=0; //limpia la bandera de interrupciÃ³n
}
void config_TMR_1(){
  //TIMER 1 HORA REAL
    TMR1=0;
    PR1=31250; //1000ms
    IEC0bits.T1IE=1;//enable interrupcion
    IFS0bits.T1IF=0;//limpia bandera
    IPC0bits.T1IP=3;//prioridad interrupcion
    T1CON=0;
    T1CONBits.TCKPS= 2;   //Preescalador 64
    T1CONBits.TON=0;

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
  PR5=49063; // timer a 5s

}
void config_OC(){
  OC5CON1bits.OCTSEL=3;
  OC1CON1bits.OCTSEL=2;        // T4CLK fuente de reloj
  OC2CON1bits.OCTSEL=2;
  OC3CON1bits.OCTSEL=2;
  OC4CON1bits.OCTSEL=2;
  OC5CON1bits.OCM=5;
  OC1CON1bits.OCM=5;          //MODO COMPARADOR DUAL DE PULSOS CONTINUOS
  OC2CON1bits.OCM=5;
  OC3CON1bits.OCM=5;
  OC4CON1bits.OCM=5;
  OC5R=10; OC5RS=2047;
  OC1R=306; OC1RS=2047;     //CICLO UTIL 15%
  OC2R=921; OC2RS=2047;     //CICLO UTIL 45%
  OC3R=1227; OC3RS=2047;     //CICLO UTIL 60%
  OC4R=1637; OC4RS=2047;     //CICLO UTIL 80%
  OC1CON2bits.SYNCSEL=0b00101;    //disparo con el OC 5
  OC2CON2bits.SYNCSEL=0b00101;
  OC3CON2bits.SYNCSEL=0b00101;
  OC4CON2bits.SYNCSEL=0b00101;
  OC5CON2bits.SYNCSEL=0b01111;
}
void config_INT(){
  SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
  INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
  INTCON2bits.GIE=1; //interrupciones habilitadas
  CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
//------------------------- habilitacion de interrupcion

 }
  //prioridad int
// Banderas de Interrupcion post Reset (Limpieza)

 void config_ic() {

IC1CON1bits.ICTSEL=1; // reloj timer 3
IC2CON1bits.ICTSEL=1 ; // reloj timer 3
IC1CON1bits.ICM=2; //captura
IC2CON1bits.ICM=2; // captura
IC1CON2bits.IC32=1; // modo 32 bits
IC2CON2bits.IC32=1; // modo 32 bits

IC1CON2bits.SYNCSEL=13; // sincronismo timer 3
IC2CON2bits.SYNCSEL=13; // sincronismo timer 3
IEC0bits.IC1IE=1; // habilita interrupciones modulo 1
IEC0bits.IC2IE=1; // habilita interrupciones modulo 2
IFS0bits.IC1IF=0; // borra bandera
IFS0bits.IC2IF=0; // borra bandera
IC1CON2bits.ICTRIG=0;
IC2CON2bits.ICTRIG=0;
 IPC0bits.IC1IP=2;
  IPC0bits.IC1IP=2;

}

void config_timeric ()  {
T3CONbits.TSIDL=1;
T2CON= 0x8020; // config 64:1 prescaler
PR2=31250; //1000 ms
T2CONbits.T32=1; // Modo 32 bits
 IPC1bits.T2IP=3;
}_______________________________________________________________________________________________________________________________
//~~~~~~~~~~~~~~~~~~Constantes  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned short op=0;
unsigned short d_mseg=0,u_mseg=0,u_seg=0,d_seg=0,u_min=0,d_min=0,u_hora=0,d_hora=0;//Constantes de las ubicaciones de los pines
char hora[12]  ={'0','0',':','0','0',':','0','0',':','0','0','\0'};
char alarma[12]={'0','0',':','0','0',':','0','0',':','0','0','\0'};
char texta=1+'0';
int ENALARM=0,conta1=0,selected=0;
float T1,T2,T3,T4;
int pulso=0;
float frecuencia,periodo;
//____________________________________________________________________________________________________________________________________
//~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cron_write();
void clean_PS2();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void TIMER1() org 0x1A
// {
//   u_seg++;
//           if(u_seg==10)
//           { u_seg=0;
//           d_seg++;
//                 if(d_seg==6)
//                 { d_seg=0;
//                 u_min++;
//                       if(u_min==10)
//                       { u_min=0;
//                       d_min++;
//                             if(d_min==6)
//                             { d_min=0;
//                             u_hora++;
//                                   if(u_hora==10 && d_hora==0)
//                                   { u_hora=0;
//                                   d_hora++;
//                                   }
//                                   else if(u_hora==3 && d_hora==1)
//                                   { u_hora=1;
//                                   d_hora=0;
//                                   }
//                             }
//                       }
//                 }
//           }
//   if(ENALARM&&Alarma[0]==HORA[0]&&Alarma[1]==HORA[1]&&Alarma[3]==HORA[3]&&Alarma[4]==HORA[4]){
//     Glcd_Fill(0);
//     animate_bell_5s();
//     ENALARM=0;
//   }
//   HORA[0]=d_hora+'0';
//   HORA[1]=u_hora+'0';
//   HORA[2]=':';
//   HORA[3]=d_min+'0';
//   HORA[4]=u_min+'0';
//   HORA[5]=':';
//   HORA[6]=d_seg+'0';
//   HORA[7]=u_seg+'0';
//   HORA[8]=':';
//   HORA[9]=d_mseg+'0';
//   HORA[10]=u_mseg+'0';
//   HORA[11]='\0';
//   cron_write();
//   IFS0bits.T1IF=0;
// }
void captura_onda_ic1() org 0x16{ 
    pulso++;
//    inttostr(pulso,txt);
//    glcd_write_text(txt,0,7,1);
    IFS0bits.IC1IF=0;
}
void int_timer1 () org 0x1A{
  T1CONbits.TON=0; // deshabilita timer1
  IFS0bits.T1IF=0; // limpia bandera de interrupcion
  frecuencia=pulso*4*2;
  periodo=(1/frecuencia)*4000000;
 }
void Timer4() org 0x4A{
    IFS1bits.T4IF=0;
    }
void Timer5() org 0x4C{
    IFS1bits.T5IF=0;
    }


//~~~~~~~~~~~~~~~~~~~~~~Caso 1~~~~~~~~~~~~~~~~~~~~~~~~~~
int  num_selector(){
  int it=0;

  clean_PS2();
  while(keydata!=ENTER){
    if(Ps2_Key_Read(&keydata, &special, &down)){
      if(down){
       if(keydata==DOWN_ARROW||keydata==UP_ARROW){
        if(keydata==UP_ARROW){
          it=it+1;
          if(it==10){it=0;}
          clean_PS2();
        }
        if(keydata==DOWN_ARROW){
          it=it-1;
          if(it==-1){it=9;}
          clean_PS2();
        }
        cron_write();
        clean_PS2();
      }
      }
    }
  }
  return it;
}

void cron_cursor(){
int x_pos=60,i,j;
  //hay 5 variables de hora y alarma
  clean_PS2();
  for(i=0;i<5;i++){
    if(i!=2){
      j=num_selector()+'0';
      HORA[i]=j;
    }else if(i==2){
      HORA[2]=':' ;
    }
    clean_PS2();
    cron_write();
  }
}

void cron_write(){
  Glcd_Write_TEXT("                                                                ",60,7,1);
  Glcd_Write_TEXT(HORA,60,7,1);
}
void frecuencia_pantalla (){
        Glcd_Write_Text("Frecu.(hz)=", 0, 1, 1);
   floattostr(frecuencia,txt);
    Glcd_Write_Text(txt,65, 1, 1);
//    floattostr(periodo,txt);
//    Glcd_Write_Text(txt,65, 7, 1);

}          

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Casos~~~~~~~~~~~~~~~~~~~~~~~~
void caso_1(){
  while(keydata!=ESC){
     selected=cursor_menu();
      switch(selected){
      case 1:
        cron_cursor();
        clean_PS2();
        break;
      case 2:
        Glcd_Write_Text("PLAY",30,7,1);
        T1CONBits.TON=1;
        break;
      case 3:
        Glcd_Write_Text("pause",30,7,1);
        T1CONBits.TON=0;
        break;
      case 4:
      Glcd_Write_Text("RESET",30,7,1);
//        hora={'0','0',':','0','0',':','0','0',':','0','0','\0'};
        break;
      case 5:
      Glcd_Write_Text("ALARM",30,7,1);
//        alarm_cursor();
        break;
      }
  }
}
void caso_2(){
	  config_captura();
   T1CONbits.TON=1; //enciende timer 1
        Glcd_Fill(0);
  while(keydata!=ESC){
          frecuencia_pantalla();
          delay_ms(500);
    // if(!FloatToStr(T1,txt)){Glcd_Write_Text(txt,65,1,1);}
    // if(!FloatToStr(T2,txt)){Glcd_Write_Text(txt,65,2,1);}
    // if(!FloatToStr(T3,txt)){Glcd_Write_Text(txt,65,3,1);}
    // if(!FloatToStr(T4,txt)){Glcd_Write_Text(txt,65,4,1);}
    Ps2_Key_Read(&keydata, &special, &down);
  }
}
void caso_3(){
        texto_caso_3();
        while(keydata!=ESC){
                T5CONbits.TON=1;
                  T4CONbits.TON=1;
                  Ps2_Key_Read(&keydata, &special, &down);
        }
        T5CONbits.TON=0;
          T4CONbits.TON=0;
}

//~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~
void main(){
  config_IO();  config_LCD();
  config_INT();
   // config_TMR_1();
  config_OC();
  config_TMR_45();
 // config_captura();
  config_pin();
//  config_IC() ;config_timeric ();
//  animate_charmander_5s();
   Glcd_Fill(0);
//  glcd_space_test();
  PS2_Config();  Glcd_Fill(0);
  while(1){
    texto_menu();
    if(Ps2_Key_Read(&keydata, &special, &down)){
       if(down){
              Glcd_Write_TEXT("Entrar",0,7,1);
              delay_ms(500);
              Glcd_Write_TEXT("        ",0,7,1);
              
              op=0;
              switch(keydata){
                case 'x':

                  clean_PS2();
                  texto_caso_1();
                  caso_1();
                break;

                case 'w':

                  clean_PS2();
                  // texto_caso_2();
                  caso_2();
                break;
                case 'e':

                  clean_PS2();
                  texto_caso_3();
                  caso_3();
                break;
                
                case UP_ARROW:
                  Glcd_Write_TEXT("AR",60,7,1);
                break;

                 case DOWN_ARROW:
                  Glcd_Write_TEXT("AB",60,7,1);
                break;

                case 'd':
                  cron_write();
                  delay_ms(500);
                  break;
                default:
                  Glcd_Write_TEXT("Erroneo ",60,7,1); delay_ms(500);Glcd_Write_TEXT("        ",60,7,1);
                  break;

                }
                // Glcd_Fill(0);
              }
            }
    }
}