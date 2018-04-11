
#include "sprites.h"
#include "extras.h"
#include "text.h"
#include "config.h"


//____________________________________________________________________________________________________________________________________
//~~~~~~~~~~~~~~~~~~Constantes  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned short op=0;
unsigned short d_mseg=0,u_mseg=0,u_seg=0,d_seg=0,u_min=0,d_min=0,u_hora=0,d_hora=0;//Constantes de las ubicaciones de los pines
char hora[12]  ={'0','0',':','0','0',':','0','0',':','0','0','\0'};
char alarma[12]={'0','0',':','0','0',':','0','0',':','0','0','\0'};
char texta=1+'0';
int ENALARM=0,conta1=0,selected=0;
float T1,T2,T3,T4;
//____________________________________________________________________________________________________________________________________
//~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cron_write();
void clean_PS2();
void clean_line(int page){
  y=page2pos(page)         ;
  glcd_write_text("                                                                                 ",0,y,1);
}
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
  if(ENALARM&&Alarma[0]==HORA[0]&&Alarma[1]==HORA[1]&&Alarma[3]==HORA[3]&&Alarma[4]==HORA[4]){
    Glcd_Fill(0);
    animate_bell_5s();
    ENALARM=0;
  }
  HORA[0]=d_hora+'0';
  HORA[1]=u_hora+'0';
  HORA[2]=':';
  HORA[3]=d_min+'0';
  HORA[4]=u_min+'0';
  HORA[5]=':';
  HORA[6]=d_seg+'0';
  HORA[7]=u_seg+'0';
  HORA[8]=':';
  HORA[9]=d_mseg+'0';
  HORA[10]=u_mseg+'0';
  HORA[11]='\0';
  cron_write();
  IFS0bits.T1IF=0;
}
void intercaso2ic1() org 0x16{
 conta1++;
 IFS0bits.IC1IF=0; // borra bandera
}
//void intercaso2ic2() org 0x1E {
// conta1++;
// IFS0bits.IC2IF=0; // borra bandera
//}
//void timer2inter() org 0x22{
// T1=(1/conta1)*1000000;
// IFS0bits.T2IF=0;  // borra bander
//}
//~~~~~~~~~~~~~~~~~~~~~~Caso 1~~~~~~~~~~~~~~~~~~~~~~~~~~
int  num_selector(int x_pos){
  int it=0;
  num_update(it,x_pos,7);
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
        num_update(it,x_pos,7);
        clean_PS2();
      }
      clean_PS2();
      }
    }
  }
  return it;
}
void cron_cursor(){
int x_pos=60,i;
  //hay 5 variables de hora y alarma

  for(i=0;i<5;i++){

    if(i!=2){
      HORA[i]='0'+num_selector(60+i*5);
    }else if(i==2){
      HORA[2]=':' ;
    }
    clean_PS2();
    cron_write();
  }
}

void cron_write(){
  Glcd_Write_TEXT("                                              ",60,7,1);
  Glcd_Write_TEXT(HORA,60,7,1);
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
        break;
      case 3:
        Glcd_Write_Text("pause",30,7,1);
        break;
      case 4:
      Glcd_Write_Text("RESET",30,7,1);
        break;
      case 5:
      Glcd_Write_Text("ALARM",30,7,1);
        break;
      }
  }
}
void caso_2(){
  while(keydata!=ESC){
    if(!FloatToStr(T1,txt)){Glcd_Write_Text(txt,65,1,1);}
    if(!FloatToStr(T2,txt)){Glcd_Write_Text(txt,65,2,1);}
    if(!FloatToStr(T3,txt)){Glcd_Write_Text(txt,65,3,1);}
    if(!FloatToStr(T4,txt)){Glcd_Write_Text(txt,65,4,1);}
    Ps2_Key_Read(&keydata, &special, &down);
  }
}
//~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~
void main(){
  config_IO();  config_LCD();
  config_INT(); config_TMR();
//  config_IC() ;config_timeric ();
  animate_charmander_5s(); Glcd_Fill(0);

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

                case 'W':

                  clean_PS2();
                  texto_caso_2();
                  caso_2();
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