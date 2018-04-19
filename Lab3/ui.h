#define ENTER 13
#define ESC 118//V
#define UP_ARROW 111//O
#define DOWN_ARROW 108//L

unsigned short keydata = 0, special = 0, down = 0,y;
char txt[15];
char t[3],c1;
void clean_PS2(){ keydata = 0, special = 0, down = 0;}

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
int cursor_menu(int max_n_options){
  //aqui se va a estar utilizando el it como iterator, revisando si el teclado
//ha seleccionado las flechas de arriba o abajo, aumentando o disminuyendo al operador
//SIEMPRE HAY 5 OPCIONES

  int it=1;
   clean_PS2();
  while(keydata!=ENTER){
    cursor_animation(it);
    if(Ps2_Key_Read(&keydata, &special, &down)){
      if(down){
       if(keydata==DOWN_ARROW||keydata==UP_ARROW){
        if(keydata==DOWN_ARROW){
          it=it+1;
          if(it>max_n_options){it=1;}
          clean_PS2();
        }
        if(keydata==UP_ARROW){
          it=it-1;
          if(it==0){it=max_n_options;}
          clean_PS2();
        }
        cursor_animation(it);
      }
      }
    }
  }
  clean_PS2();
  
    return it;
}
int cursor_menu2(int max_n_options){
  //aqui se va a estar utilizando el it como iterator, revisando si el teclado
//ha seleccionado las flechas de arriba o abajo, aumentando o disminuyendo al operador
//SIEMPRE HAY 5 OPCIONES

  int it=0;
   clean_PS2();
  while(keydata!=ENTER){
    cursor_animation(it);
    if(Ps2_Key_Read(&keydata, &special, &down)){
      if(down){
       if(keydata==DOWN_ARROW||keydata==UP_ARROW){
        if(keydata==DOWN_ARROW){
          it=it+1;
          if(it>max_n_options){it=0;}
          clean_PS2();
        }
        if(keydata==UP_ARROW){
          it=it-1;
          if(it==-1){it=max_n_options;}
          clean_PS2();
        }
        cursor_animation(it);
      }
      }
    }
  }
    clean_PS2();
    return it;
}
//Cursor Numero

//Texto del laboratorio
void texto_menu(){
  glcd_fill(0);
  Glcd_Write_TEXT("Laboratorio 2",60,0,1);
  Glcd_Write_TEXT("1) Cronometro",SANGRIA,1,1);
  Glcd_Write_TEXT("2) Captura"   ,SANGRIA,2,1);
  Glcd_Write_TEXT("3) PWM  "     ,SANGRIA,3,1);
}
void texto_caso_1(){
  GLCD_FILL(0);
  Glcd_Write_Text("Cronometro",60,0,1);
  Glcd_Write_Text("2) PLAY"  ,SANGRIA,2,1);
  Glcd_Write_Text("1) Programar Hora",SANGRIA,1,1);
  Glcd_Write_Text("3) PAUSE"  ,SANGRIA,3,1);
  Glcd_Write_Text("4) RESET  "  ,SANGRIA,4,1);
  Glcd_Write_Text("5) Alarma",SANGRIA,5,1);
}
void texto_caso_2(){
  GLCD_FILL(0);
  Glcd_Write_Text("Puerto de Entrada",60,0,1);
  Glcd_Write_Text("RP75/RD11"  ,0,1,1);
  Glcd_Write_Text("RP74/RD10"  ,0,2,1);
  Glcd_Write_Text("RP73/RD09"  ,0,3,1);
  Glcd_Write_Text("RP72/RD8"  ,0,4,1);
}
void texto_caso_3(){
  GLCD_FILL(0);
  Glcd_Write_Text("Puerto de Entrada",60,0,1);
  Glcd_Write_Text("RP101/RG8 80%"  ,0,4,1);
  Glcd_Write_Text("RP85 /RE5 15%"  ,0,1,1);
  Glcd_Write_Text("RP87 /RE7 45%"  ,0,2,1);
  Glcd_Write_Text("RP87 /RG6 60%"  ,0,3,1);
}