#include "config.h"
#include "ui.h"
#include "extras.h"
#include "sprites.h"
//~~~~~~~~~~~~~~~~~~Constantes  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

unsigned short unidad_segundo=0, decena_segundo=0, unidad_minuto=0,decena_minuto=0, unidad_hora=0, decena_hora=0,decena_milisegundo=0,unidad_milisegundo=0;
char hora[12]={'0','0',':','0','0',':','0','0',':','0','0','\0'};
char alarma[6]={'0','0',':','0','0','\0'};
char texta=1+'0';
int ENALARM=1,conta1=0,selected=0,max_1=1, i=0;
float T1,T2,T3,T4;
int pulso=0, pulso2=0,pulso3=0,pulso4=0;
 float frecuencia=0,frecuencia2=0,frecuencia3=0,frecuencia4=0;
void cron_inttostr();    void caso_1();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cron(){
unidad_milisegundo=unidad_milisegundo+5;
  if(unidad_milisegundo>9){
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

   cron_inttostr();
  if(ENALARM==0 &&
    alarma[0]==HORA[0] &&
    alarma[1]==HORA[1] &&
    alarma[3]==HORA[3] &&
    alarma[4]==HORA[4]){
    Glcd_fill(0);
    ENALARM=2;
    IFS0Bits.T1IF=0;
  }
  Glcd_Write_Text(hora, 30, 7, 1);

  IFS0bits.T1IF=0;

}

void tee() org 0x1A{
  cron();
}
void captura_onda_ic1() org 0x16{
  pulso++;
  IFS0bits.IC1IF=0;

}


void captura_onda_ic3() org 0x5E{
  pulso2++;

  IFS2bits.IC3IF=0;

}
void captura_onda_ic5() org 0x62{
  pulso3++;
  IFS2bits.IC5IF=0;

}
void captura_onda_ic11() org 0x112{
  pulso4++;
  IFS7bits.IC11IF=0;

}
// void captura_onda_ic2() org 0x1E{
//  pulso++;
//  inttostr(pulso,txt);
//  Glcd_Write_Text(txt,0,7,1);
//    Glcd_Write_Text("cap2",0,5,1);
void int_timer2 () org 0x22{
  IC1CON1bits.ICM=0;
   IC3CON1bits.ICM=0;
   IC5CON1bits.ICM=0;
   IC11CON1bits.ICM=0;
  // Glcd_Write_Text("T2",0,7,1);
  T2CONbits.TON=0;
  IFS0bits.T2IF=0; // limpia bandera de interrupcion
  frecuencia=pulso*4*2;
  frecuencia2=pulso2*4*2;
  frecuencia3=pulso3*4*2;
  frecuencia4=pulso4*4*2;
  T1=(1/frecuencia)*1000000;
  T2=(1/frecuencia2)*1000000;
  T3=(1/frecuencia3)*1000000;
  T4=(1/frecuencia4)*1000000;
    Glcd_Write_Text("Entrada", 0, 1, 1);
    Glcd_Write_Text("2)", 5, 3, 1);
    Glcd_Write_Text("3)", 5, 4, 1);
  Glcd_Write_Text("4)", 5, 5, 1);
  Glcd_Write_Text("Periodo (us)", 50, 1, 1);
  Glcd_Write_Text("1)", 5, 2, 1);
    floattostr(T1,txt);
  Glcd_Write_Text(txt,65, 2, 1);

   floattostr(T2,txt);
  Glcd_Write_Text(txt,65, 3, 1);

  floattostr(T3,txt);
  Glcd_Write_Text(txt,65, 4, 1);

floattostr(T4,txt);
  Glcd_Write_Text(txt,65, 5, 1);
  IFS0bits.IC2IF=0;
}
//  IFS0bits.IC2IF=0;
//}
void Timer4() org 0x4A{
  IFS1bits.T4IF=0;
}
void Timer5() org 0x4C{
     T4CONbits.TON=1;

     IFS1bits.T5IF=0;
}
//~~~~~~~~~~~~~~~~Declaraciones de Funciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void clean_PS2();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Casos~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~Caso 1~~~~~~~~~~~~~~~~~~~~~~~~~~

void cron_inttostr(){
  hora[0]=decena_hora+'0';
  hora[1]=unidad_hora+'0';
  hora[3]=decena_minuto+'0';
  hora[4]=unidad_minuto+'0';
  hora[6]=decena_segundo+'0';
  hora[7]=unidad_segundo+'0';
  hora[9]=decena_milisegundo+'0';
  hora[10]=unidad_milisegundo+'0';
  hora[11]= '\0';
}


void num_update(int it,int x_pos,int page){
  Glcd_Write_Char(it+'0',x_pos,page,1);
}
   int it=0;
  

int arreglo_hora_militar(int indice,int valor_nuevo){
    if(indice==0){
      //DECENA_HORA
      if(max_1==0){
        if(valor_nuevo>1){return 0;}//Decena de hora solo puede ser 0,1 o si max_1==0 porque unidad hora>3
        else if(valor_nuevo<0){return 1;} //Decena de hora solo puede ser 0,1 o si max_1==0 porque unidad hora>3
        else{return valor_nuevo;}
      }else{
        if(valor_nuevo>2){return 0;}//Decena de hora solo puede ser 0,1 o 2 2->0
        else if(valor_nuevo<0){return 2;} //Decena de hora solo puede ser 0,1 o 2 2->0;
        else{return valor_nuevo;}
      }
    }
    else if(indice==1){
    //UNIDAD_HORA
      if(valor_nuevo>9){return 0;}//Arreglo Unidad Hora && Unidad Minuto 9->0
      else if(valor_nuevo<0){return 9;}//Arreglo Unidad Hora && Unidad Minuto 0->9
      else{return valor_nuevo;}
    }
    else if(indice==3){
    //DECENA_MIN
    if(valor_nuevo>5){ return 0;}//Decena minuto llega hasta 5->0
    if(valor_nuevo<0){return 5;}//Decena minuto llega hasta 5
    }
    else if(indice==4){
   //UNIDAD_MIN
    if(valor_nuevo>9){return 0;}//Arreglo Unidad Hora && Unidad Minuto 9->0
    if(valor_nuevo<0){return 9;}//Arreglo Unidad Hora && Unidad Minuto 9->0
    }
    else {
    return valor_nuevo;}
}
int  num_selector(int x_pos,int is){
   it=0;
  num_update(it,x_pos,7);
  clean_PS2();
  while(keydata!=ENTER){
    if(Ps2_Key_Read(&keydata, &special, &down)){
      if(down){
       if(keydata==DOWN_ARROW||keydata==UP_ARROW){
        if(keydata==UP_ARROW){
          inttostr(it,txt) ;
          glcd_write_text(txt,0,0,1);
          inttostr(is,txt) ;
          glcd_write_text(txt,60,0,1);
          it=arreglo_hora_militar(is,it+1);
          clean_PS2();
        }
        if(keydata==DOWN_ARROW){
          inttostr(it,txt) ;
          glcd_write_text(txt,0,0,1);
          inttostr(is,txt) ;
          glcd_write_text(txt,60,0,1);
          it=arreglo_hora_militar(is,it-1);

          
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

  //hay 5 variables de hora y alarma
  num_selector(0,0);
  glcd_write_text("Hora:",0,7,1);
  unidad_minuto=num_selector(74,4);
  decena_minuto=num_selector(68,3);
  glcd_write_char(':',62,7,1);
  unidad_hora=num_selector(56,1);
  if(unidad_hora>3){max_1=0;}
  else{max_1=1;}
  decena_hora=num_selector(50,0);

  decena_segundo=0;
  unidad_segundo=0;
  decena_milisegundo=0;
  unidad_milisegundo=0;
  cron_inttostr();
  max_1=1;
}
void cron_alarm(){
  num_selector(0,0);
  glcd_write_text("Alarma:",0,7,1);
  alarma[4]=num_selector(74,4)+'0';
  alarma[3]=num_selector(68,3)+'0';
  glcd_write_char(':',62,7,1);
  alarma[1]=num_selector(56,1)+'0';
  if(alarma[1]>'3'){max_1=0;}
  else{max_1=1;}
  alarma[0]=num_selector(50,0)+'0';
  max_1=1;
  ENALARM=0;
}


  int set=0;
void caso_1(){
  clean_PS2();
  set=0;
  while(set!=ESC){
  set=cursor_menu2(5);
     switch(set){
      case 1:
        cron_cursor();
        clean_PS2();
        Glcd_write_text("                                                    ",0,7,1);
        break;
      case 2:
        T1CONbits.TON=1;
        Glcd_write_text("                                                    ",0,7,1);
        break;
      case 3:
        T1CONBits.TON=0;
        Glcd_write_text("                                                    ",0,7,1);
        break;
      case 4:
          decena_hora=0;          unidad_hora=0;
          decena_minuto=0;          unidad_minuto=0;
          decena_segundo=0;          unidad_segundo=0;
          decena_milisegundo=0;          unidad_milisegundo=0;
          cron_inttostr();
          Glcd_Write_Text(hora, 30, 7, 1);
          Glcd_write_text("                                                    ",0,7,1);
        break;
      case 5:
        ENALARM=0;
        cron_alarm();
        Glcd_write_text("                                                                ",0,7,1);
        break;

       default:

      Glcd_write_text("                                                    ",0,7,1);
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
  Glcd_Write_Text("Periodo(ms)", 65, 1, 1);
     inttostr(pulso,txt);
  glcd_write_text(txt,5,2,1);
    inttostr(pulso2,txt);
  glcd_write_text(txt,5,3,1);
    inttostr(pulso3,txt);
  glcd_write_text(txt,5,4,1);
    inttostr(pulso4,txt);
  glcd_write_text(txt,5,5,1);
}

void caso_2(){
pulso=0;
pulso2=0;
pulso3=0;
pulso4=0;
Glcd_Write_Text("Caso 2",65, 0, 1);
  config_pin();
  config_captura();
  T2CONbits.TON=1; //enciende timer 2
  Glcd_Fill(0);

  clean_PS2();
  while(keydata!=ESC){
    Ps2_Key_Read(&keydata, &special, &down);
  }
}
//~~~~~~~~~~~~~~~~~~~~~~Caso 3~~~~~~~~~~~~~~~~~~~~~~~~~~
 void caso_3();
//~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~
void main(){
  config_IO();  config_LCD();
  config_INT();
  config_cron();
 // config_OC();
 // config_TMR_45();
  config_pin();


  PS2_Config();  Glcd_Fill(0);
  
 // glcd_write_text("a",1,1,1);
  //T1conbits.Ton=1;
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
void caso_3(){
  texto_caso_3();
    ANSELE=0;
  ANSELG=0;
  ANSELD=0;
  TRISEbits.TRISE5=0;
  TRISEbits.TRISE7=0;
  TRISGbits.TRISG6=0;
  TRISGbits.TRISG8=0;
  TRISGbits.TRISG8=0;
  RPOR6bits.RP85R =0b010000;     //pin comparador 1  RE5
  RPOR6bits.RP87R =0b010001;    //pin comparador 2  RE7
 RPOR13bits.RP118R=0b010010;  //pin comparador 3 RG6
 RPOR14bits.RP120R=0b010011;
 RPOR0bits.RP64R=0b010100;// pin comparador 4 RG8
   IEC1bits.T4IE=1;
   IEC1bits.T5IE=1;
   IFS1bits.T4IF=0;
   IFS1bits.T5IF=0;
  T4CON=0;            //preescaler 1:1
 TMR4=0;
 PR4=2000;                    // timer a 1ms
 T5CON=0x8030;            //prescaler 256:1
 TMR5=0;
 PR5=39062; // timer a 5s
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
 OC1CON2bits.OCTRIG=1;
 OC2CON2bits.OCTRIG=1;
 OC3CON2bits.OCTRIG=1;
 OC4CON2bits.OCTRIG=1;
 OC5CON2bits.OCTRIG=0;
 OC1CON1bits.TRIGMODE=0;
 OC2CON1bits.TRIGMODE=0;
 OC3CON1bits.TRIGMODE=0;
 OC4CON1bits.TRIGMODE=0;
 OC5R=8000; OC5RS=8200;
 OC1R=306; OC1RS=2047;     //CICLO UTIL 15%
 OC2R=921; OC2RS=2047;     //CICLO UTIL 45%
 OC3R=1227; OC3RS=2047;     //CICLO UTIL 60%
 OC4R=1637; OC4RS=2047;     //CICLO UTIL 80%
 OC1CON2bits.SYNCSEL=0b00101;    //disparo con el OC 5
 OC2CON2bits.SYNCSEL=0b00101;
 OC3CON2bits.SYNCSEL=0b00101;
 OC4CON2bits.SYNCSEL=0b00101;
 OC5CON2bits.SYNCSEL=0b01111;



  while(keydata!=ESC){
    Ps2_Key_Read(&keydata, &special, &down);
  }
  T5CONbits.TON=0;
  T4CONbits.TON=0;
}