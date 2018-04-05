//#include "sprites.h"
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
unsigned short keydata = 0, special = 0, down = 0;
unsigned short u_seg=0,d_seg=0,u_min=0,d_min=0,u_hora=0,d_hora=0;//Constantes de las ubicaciones de los pines
char hora[8];
//____________________________________________________________________________________________________________________________________
//~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TIMER1() org 0x1A
{
  u_seg++;
          if(u_seg==10)
          { u_seg=0;
          d_seg++;
                if(d_seg==6)
                { d_seg=0;
                u_min++;
                      if(u_min==10)
                      { u_min=0;
                      d_min++;
                            if(d_min==6)
                            { d_min=0;
                            u_hora++;
                                  if(u_hora==10 && d_hora==0)
                                  { u_hora=0;
                                  d_hora++;
                                  }
                                  else if(u_hora==3 && d_hora==1)
                                  { u_hora=1;
                                  d_hora=0;
                                  }
                            }
                      }
                }
          }
  HORA[0]=d_hora+'0';
  HORA[1]=u_hora+'0';
  HORA[2]=':';
  HORA[3]=d_min+'0';
  HORA[4]=u_min+'0';
  HORA[5]=':';
  HORA[6]=d_seg+'0';
  HORA[7]=u_seg+'0';
  HORA[8]='\0';
  Glcd_Write_Text(HORA,30,3,1);
  IFS0bits.T1IF=0;
}
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
//Entrada Botones y Dipswitches
//Las entradas del teclado y las salidas de la pantalla son manejadas por las librerias;
}
void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
}
void config_TMR(){
  //TIMER 1 HORA REAL
    TMR1=0;
    PR1=57343; //1000ms
    IEC0bits.T1IE=1;//enable interrupcion
    IFS0bits.T1IF=0;//limpia bandera
    IPC0bits.T1IP=3;//prioridad interrupcion
    T1CON=0;
    T1CONBits.TCKPS= 2;   //Preescalador 256
    
}
void config_INT(){
  SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
  INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
  INTCON2bits.GIE=1; //interrupciones habilitadas
  CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
//------------------------- habilitacion de interrupcion

  //prioridad int
// Banderas de Interrupcion post Reset (Limpieza)

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Casos~~~~~~~~~~~~~~~~~~~~~~~~
 void oscilador_usado(){
  switch(OSCCONBits.COSC){
    case 0:
      glcd_write_text("FRC",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
    case 1:
      glcd_write_text("FRCPLL",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
    case 2:
      glcd_write_text("posc",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
    case 3:
      glcd_write_text("posc_pll",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
   case 4:
      glcd_write_text("sosc",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
    case 5:
      glcd_write_text("lprc",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
    case 6:
      glcd_write_text("frcdiv16",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
      case 7:
      glcd_write_text("frcdivn",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
     default:
      glcd_write_text("none",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
  }
 }
void main(){
  config_IO();  config_LCD();
  config_INT(); config_TMR();
//  animate_charmander_5s();
  PS2_Config();  Glcd_Fill(0);
  while(1){
    Glcd_Write_TEXT("Laboratorio 2",31,0,1);
    Glcd_Write_TEXT("'Q' Cronometro",0,1,1);
    oscilador_usado();
    if(Ps2_Key_Read(&keydata, &special, &down)){
       if(down &&!special){
              switch(keydata){
                case 'q':
                case 'Q':
                  T1CONbits.TON=1;
                  Glcd_Fill(0);
                  Glcd_Write_Text("HORA:",0,3,1);
                  delay_ms(2000);
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