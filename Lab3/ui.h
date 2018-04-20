#define ENTER 13
#define ESC 118//V
#define UP_ARROW 111//O
#define DOWN_ARROW 108//L


unsigned short keydata = 0, special = 0, down = 0,y;
char txt[15];
char t[3],c1;

void clean_PS2(){ keydata = 0, special = 0, down = 0;}
unsigned short page2pos(int page_num);

void cursor_animation(int it,int max_n_options,int ft){
  Glcd_Rectangle(0,page2pos(it),127,page2pos(it+1)-1,2);//se sombrea la opcion dada
  if(it==1||it==0){//desombreo de la anterior
    if(ft){return;}
    Glcd_Rectangle(0,page2pos(max_n_options),127,page2pos(max_n_options)-1,2);//se sombrea la opcion dada
  }
  else{
    Glcd_Rectangle(0,page2pos(it-1),127,page2pos(it)-1,2);//se sombrea la opcion dada
  }
}

int cursor_menu(int max_n_options){
  //aqui se va a estar utilizando el it como iterator, revisando si el teclado
//ha seleccionado las flechas de arriba o abajo, aumentando o disminuyendo al operador
  int ft=0;//Bandera de primera vez
  int it=1;
  clean_PS2();
  while(keydata!=ENTER){
    cursor_animation(it);
    if(Ps2_Key_Read(&keydata, &special, &down)){
      ft++;
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
        cursor_animation(it,max_n_options,ft);
      }
      }
    }
  }
  clean_PS2();
  return it;
}

//Texto del laboratorio
void texto_menu(){
  glcd_fill(0);
  Glcd_Write_TEXT("Laboratorio 3",60,0,1);
  Glcd_Write_TEXT("1) Motores",0,1,1);
  Glcd_Write_TEXT("2) QAD"   ,0,2,1);
  Glcd_Write_TEXT("3) Potenciometro",0,3,1);
}
unsigned short page2pos(int page_num){
  switch(page_num){
      case 0:
        return 0;    break;
      case 1:
        return 8;    break;
      case 2:
        return 16;    break;
      case 3:
        return 24;    break;
      case 4:
        return 32;    break;
      case 5:
        return 40;    break;
      case 6:
        return 48;    break;
      case 7:
        return 56;    break;
      case 8:
        return 0;     break;
      default:
        return 0;
    }
}