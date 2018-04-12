#include "config.h"
#include "ui.h"
#include "extras.h"

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
void cron_write();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TIMER1() org 0x1A{
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
//    animate_bell_5s();
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
void captura_onda_ic1() org 0x16{
  pulso++;
  inttostr(pulso,txt);
  glcd_write_text(txt,0,7,1);
  IFS0bits.IC1IF=0;
}
void int_timer2 () org 0x22{
  IC1CON1bits.ICM=0;
  Glcd_Write_Text("t2",0,4,1);
  T2CONbits.TON=1;
  IFS0bits.T2IF=0; // limpia bandera de interrupcion
  frecuencia=pulso*4*2;
  periodo=(1/frecuencia)*1000000;
}
void Timer4() org 0x4A{
  IFS1bits.T4IF=0;
}
void Timer5() org 0x4C{
  IFS1bits.T5IF=0;
}
//~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cron_write();
void clean_PS2();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Casos~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~Caso 1~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned short arreglo_hora_militar_up(int i,unsigned int valor_nuevo){
  if(i==decena_hora){
    if(valor_nuevo==4){//Decena de hora solo puede ser 0,1 o 2 2->0
     return 0;
    }
  }
  if(i==unidad_hora){
    if(HORA[decena_hora]==2&&valor_nuevo>3){//Arreglo Hora 23->00
      HORA[decena_hora]=0;
      return 0;
    }
    if(valor_nuevo>=9){return 0;}//Arreglo Unidad Hora && Unidad Minuto 9->0
  }
  if(i==decena_minuto){
    if(valor_nuevo>5){//Decena minuto llega hasta 5->0
      return 0;
    }
  }
  if(i==unidad_minuto){
    if(valor_nuevo>9){return 0;}//Arreglo Unidad Hora && Unidad Minuto 9->0
  }
}
unsigned short arreglo_hora_militar_dw(int i,unsigned int valor_nuevo){
  if(i==decena_hora){
    if(valor_nuevo==-1){//Decena de hora solo puede ser 0,1 o 2 2->0;
     return 2;
    }
  }
  if(i==unidad_hora){
    if(HORA[decena_hora]==0&&valor_nuevo<0){//Arreglo Hora 23->00
      HORA[decena_hora]=2;
      return 3;
    }else if(valor_nuevo<0){return 9;}//Arreglo Unidad Hora && Unidad Minuto 9->0
  }
  if(i==decena_minuto){
    if(valor_nuevo<0){//Decena minuto llega hasta 5
      return 5;
    }
  }
  if(i==unidad_minuto){
    if(valor_nuevo<0){return 9;}//Arreglo Unidad Hora && Unidad Minuto 9->0
  }
}
int i=0;
void cron_write(){
  Glcd_Write_TEXT("                                              ",60,7,1);
  i=0;
  for(i=0;i<12;i++){
    Glcd_Write_Char(HORA[i],50+i*5,7,1);
  }
}
void num_update(int it,int x_pos,int page){
  Glcd_Write_Char(it+'0',x_pos,page,1);
}

int  num_selector(int x_pos,int indice){
  int it=0;
  num_update(it,x_pos,7);
  clean_PS2();
  while(keydata!=ENTER){
    if(Ps2_Key_Read(&keydata, &special, &down)){
      if(down){
       if(keydata==DOWN_ARROW||keydata==UP_ARROW){
        if(keydata==UP_ARROW){
          it=it+1;
          it=arreglo_hora_militar_up(indice,it);
          clean_PS2();
        }
        if(keydata==DOWN_ARROW){
          it=it-1;
          it=arreglo_hora_militar_dw(indice,it);
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
int x_pos=50,i,j;
  //hay 5 variables de hora y alarma
  clean_PS2();
  for(i=0;i<5;i++){
    if(i!=2){
      j=num_selector(50+i*5,i)+'0';
      HORA[i]=j;
    }else if(i==2){
      HORA[2]=':' ;
    }
    clean_PS2();
    cron_write();
  }
}
void caso_1(){
  while(keydata!=ESC){
     selected=cursor_menu(5);
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
//~~~~~~~~~~~~~~~~~~~~~~Caso 2~~~~~~~~~~~~~~~~~~~~~~~~~~
void frecuencia_pantalla (){
  Glcd_Write_Text("Frecu.(hz)=", 0, 1, 1);
  floattostr(frecuencia,txt);
  Glcd_Write_Text(txt,65, 1, 1);
  floattostr(periodo,txt);
  Glcd_Write_Text(txt,65, 2, 1);
}
void caso_2(){
	config_captura();
  T2CONbits.TON=1; //enciende timer 1
  Glcd_Fill(0);
  while(keydata!=ESC){
    frecuencia_pantalla();
    Glcd_Write_TEXT("c2" ,10,7,1);delay_ms(1000);
    // if(!FloatToStr(T1,txt)){Glcd_Write_Text(txt,65,1,1);}
    // if(!FloatToStr(T2,txt)){Glcd_Write_Text(txt,65,2,1);}
    // if(!FloatToStr(T3,txt)){Glcd_Write_Text(txt,65,3,1);}
    // if(!FloatToStr(T4,txt)){Glcd_Write_Text(txt,65,4,1);}
    Ps2_Key_Read(&keydata, &special, &down);
  }
}
//~~~~~~~~~~~~~~~~~~~~~~Caso 3~~~~~~~~~~~~~~~~~~~~~~~~~~
void caso_3(){
  texto_caso_3();
  T5CONbits.TON=1;
  T4CONbits.TON=1;
  delay_ms(300);
  while(keydata!=ESC){
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
    selected=cursor_menu(3);
    switch(selected){
      case 1:
        clean_PS2();
        texto_caso_1();
        caso_1();
        break;
      case 2:
        clean_PS2();
        // texto_caso_2();
        caso_2();
        break;
      case 3:
        clean_PS2();
        texto_caso_3();
        caso_3();
        break;
    }
  }
}