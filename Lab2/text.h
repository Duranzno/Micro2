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
  // GLCD_FILL(0);
  Glcd_Write_Text("Puerto de Entrada",SANGRIA,0,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,1,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,2,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,3,1);
  Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,4,1);
  Glcd_Write_Text("5) Volver"   ,SANGRIA,5,1);
}
void texto_caso_3(){
  // GLCD_FILL(0);
  Glcd_Write_Text("Elegir Ciclo Util:",0,0,1);
  Glcd_Write_Text("1) 15%"  ,SANGRIA,1,1);
  Glcd_Write_Text("2) 45%"  ,SANGRIA,2,1);
  Glcd_Write_Text("3) 60%"  ,SANGRIA,3,1);
  Glcd_Write_Text("4) 80%"  ,SANGRIA,4,1);
  Glcd_Write_Text("5) 100%"  ,SANGRIA,4,1);
}