#include "config.h"
#include "ui.h"
//#include "extras.h"

//~~~~~~~~~~~~~~~~~~Constantes  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

unsigned short unidad_segundo=0, decena_segundo=0, unidad_minuto=0,decena_minuto=0, unidad_hora=0, decena_hora=0,decena_milisegundo=0,unidad_milisegundo=0;
char hora[10];
char alarma[12]={'0','0',':','0','0',':','0','0',':','0','0','\0'};
char texta=1+'0';
int ENALARM=0,conta1=0,selected=0;
float T1,T2,T3,T4;
int pulso=0, pulso2=0,pulso3=0,pulso4=0;
float frecuencia,frecuencia2,frecuencia3,frecuencia4;
void cron_write();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void tee() org 0x1A{
  unidad_milisegundo=unidad_milisegundo+5;
  if(unidad_milisegundo==10){
  unidad_milisegundo=0;
  decena_milisegundo++;
  if(decena_milisegundo==10){
    decena_milisegundo=0;
    unidad_segundo++;
    if(unidad_segundo==10){
      unidad_segundo=0;
      decena_segundo++;
      if(decena_segundo==6){
        decena_segundo=0;
        unidad_minuto++;
        if(unidad_minuto==10){
          unidad_minuto=0;
          decena_minuto++;
          if(decena_minuto==6){
            decena_minuto=0;
            unidad_hora++;
            if(unidad_hora==10 && decena_hora==0){
              unidad_hora=0;
              decena_hora++;
            }
            else if(unidad_hora==1 && decena_hora==3){
              unidad_hora=0;
              decena_hora=0;
            }
          }
        }
      }
    }
  }
  }
  hora[0]=decena_hora+'0';
  hora[1]=unidad_hora+'0';
  hora[2]= ':';
  hora[3]=decena_minuto+'0';
  hora[4]=unidad_minuto+'0';
  hora[5]= ':';
  hora[6]=decena_segundo+'0';
  hora[7]=unidad_segundo+'0';
  hora[8]=decena_milisegundo+'0';
  hora[9]=unidad_milisegundo+'0';
  hora[10]= '\0';
  Glcd_Write_Text(hora, 30, 3, 1);
  IFS0bits.T1IF=0;
}
void captura_onda_ic1() org 0x16{
  pulso++;
  inttostr(pulso,txt);
  glcd_write_text(txt,0,7,1);
  IFS0bits.IC1IF=0;

}


void captura_onda_ic3() org 0x5E{
  pulso2++;
  inttostr(pulso2,txt);
  glcd_write_text(txt,10,5,1);
 // Glcd_Write_Text("c3",60,5,1);
  IFS2bits.IC3IF=0;

}
void captura_onda_ic5() org 0x62{
  pulso3++;
  inttostr(pulso3,txt);
  glcd_write_text(txt,20,7,1);
  // Glcd_Write_Text("c5",65,4,1);
  IFS2bits.IC5IF=0;

}
void captura_onda_ic11() org 0x112{
  pulso4++;
  inttostr(pulso4,txt);
  glcd_write_text(txt,40,7,1);
 // Glcd_Write_Text("ca",80,4,1);
  IFS7bits.IC11IF=0;

}
// void captura_onda_ic2() org 0x1E{
//  pulso++;
//  inttostr(pulso,txt);
//  glcd_write_text(txt,0,7,1);
//    Glcd_Write_Text("cap2",0,5,1);
void int_timer2 () org 0x22{
  IC1CON1bits.ICM=0;
   IC3CON1bits.ICM=0;
   IC5CON1bits.ICM=0;
   IC11CON1bits.ICM=0;
  // Glcd_Write_Text("T2",0,7,1);
  T2CONbits.TON=1;
  IFS0bits.T2IF=0; // limpia bandera de interrupcion
  frecuencia=pulso*4*2;
  frecuencia2=pulso2*4*2;
  frecuencia3=pulso3*4*2;
  frecuencia4=pulso4*4*2;
  T1=(1/frecuencia)*1000000;
  T2=(1/frecuencia2)*1000000;
  T3=(1/frecuencia3)*1000000;
  T4=(1/frecuencia4)*1000000;
}
//  IFS0bits.IC2IF=0;
//}
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
//unsigned short arreglo_hora_militar_up(int i,unsigned int valor_nuevo){
//  if(i==decena_hora){
//    if(valor_nuevo==4){//Decena de hora solo puede ser 0,1 o 2 2->0
//     return 0;
//    }
//  }
//  if(i==unidad_hora){
//    if(HORA[decena_hora]==2&&valor_nuevo>3){//Arreglo Hora 23->00
//      HORA[decena_hora]=0;
//      return 0;
//    }
//    if(valor_nuevo>=9){return 0;}//Arreglo Unidad Hora && Unidad Minuto 9->0
//  }
//  if(i==decena_minuto){
//    if(valor_nuevo>5){//Decena minuto llega hasta 5->0
//      return 0;
//    }
//  }
//  if(i==unidad_minuto){
//    if(valor_nuevo>9){return 0;}//Arreglo Unidad Hora && Unidad Minuto 9->0
//  }
//}
//unsigned short arreglo_hora_militar_dw(int i,unsigned int valor_nuevo){
//  if(i==decena_hora){
//    if(valor_nuevo==-1){//Decena de hora solo puede ser 0,1 o 2 2->0;
//     return 2;
//    }
//  }
//  if(i==unidad_hora){
//    if(HORA[decena_hora]==0&&valor_nuevo<0){//Arreglo Hora 23->00
//      HORA[decena_hora]=2;
//      return 3;
//    }else if(valor_nuevo<0){return 9;}//Arreglo Unidad Hora && Unidad Minuto 9->0
//  }
//  if(i==decena_minuto){
//    if(valor_nuevo<0){//Decena minuto llega hasta 5
//      return 5;
//    }
//  }
//  if(i==unidad_minuto){
//    if(valor_nuevo<0){return 9;}//Arreglo Unidad Hora && Unidad Minuto 9->0
//  }
//}
int i=0;
void cron_write(){
//  Glcd_Write_TEXT("                                              ",60,7,1);
  i=0;
  for(i=0;i<11;i++){
    if(i!=2||i!=5||i!=8){
    Glcd_Write_Char(HORA[i],50+i*5,7,1);
    }
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
//          it=arreglo_hora_militar_up(indice,it);
          clean_PS2();
        }
        if(keydata==DOWN_ARROW){
          it=it-1;
//          it=arreglo_hora_militar_dw(indice,it);
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
int i=0;
  //hay 5 variables de hora y alarma
  clean_PS2();
  for(i=0;i<5;i++){
    if(i!=2){
      HORA[i]=num_selector(50+i*5,i)+'0';

    }else if(i==2){
      HORA[2]=':' ;
    }
    clean_PS2();
    cron_write();
  }
}
void caso_1(){
  while(selected!=ESC){
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
int glcd_write_float(float f,unsigned short pos,unsigned short page,unsigned short color){
  if(floattostr(f,txt)==0){
  Glcd_Write_Text(txt,pos,page,color);
  return 0;} else {
  return 1;
  }
}
void frecuencia_pantalla (){

  Glcd_Write_Text("Frecu.(hz)", 0, 1, 1);
  Glcd_Write_Text("Periodo(us)", 65, 1, 1);
  floattostr(frecuencia,txt);
  Glcd_Write_Text(txt,5, 2, 1);
  glcd_write_float(frecuencia3,5,4,1);
 /*floattostr(frecuencia3,txt);
  Glcd_Write_Text(txt,5, 4, 1);
  floattostr(frecuencia4,txt);
  Glcd_Write_Text(txt,5, 5, 1);
  floattostr(T1,txt);
  Glcd_Write_Text(txt,65, 2, 1);
  floattostr(T2,txt);
  Glcd_Write_Text(txt,65, 3, 1);
  floattostr(T3,txt);
  Glcd_Write_Text(txt,65, 4, 1);
  floattostr(T4,txt);
  Glcd_Write_Text(txt,65, 5, 1);*/
}

void caso_2(){
  config_captura();
  config_pin();
  T2CONbits.TON=1; //enciende timer 1
  Glcd_Fill(0);
  frecuencia_pantalla();
  clean_PS2();
  while(keydata!=ESC){
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
  config_cron();
  config_OC();
  config_TMR_45();
  config_pin();


  PS2_Config();  Glcd_Fill(0);
  
  glcd_write_text("a",1,1,1);
  T1conbits.Ton=1;
  while(1){
   // texto_menu();
//    selected=cursor_menu(3);
//    switch(selected){
//      case 1:
//        clean_PS2();
//        texto_caso_1();
//        caso_1();
//        break;
//      case 2:
//        clean_PS2();
//        // texto_caso_2();
//        caso_2();
//        break;
//      case 3:
//        clean_PS2();
//        texto_caso_3();
//        caso_3();
//        break;
//    }
  }
}