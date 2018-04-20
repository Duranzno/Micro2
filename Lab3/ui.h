#define ENTER 13
#define ESC 118//V
#define UP_ARROW 111//O
#define DOWN_ARROW 108//L


unsigned short keydata = 0, special = 0, down = 0;
char txt[15];
void clean_PS2(){ keydata = 0, special = 0, down = 0;}
unsigned short page2pos(int page_num);
void texto_menu(int i){
  Glcd_Write_TEXT("Laboratorio 3",60,0,1);
  if(i==1){
        Glcd_Write_TEXT("1) Motores",0,1,0);
        Glcd_Write_TEXT("2) QAD",0,2,1);
        Glcd_Write_TEXT("3) Potenciometro",0,3,1);
  }else if(i==2){
        Glcd_Write_TEXT("1) Motores",0,1,1);
        Glcd_Write_TEXT("2) QAD",0,2,0);
        Glcd_Write_TEXT("3) Potenciometro",0,3,1);
   }else if(i==3){
        Glcd_Write_TEXT("1) Motores",0,1,1);
        Glcd_Write_TEXT("2) QAD"   ,0,2,1);
        Glcd_Write_TEXT("3) Potenciometro",0,3,0);
   }else{
        Glcd_Write_TEXT("1) Motores",0,1,1);
        Glcd_Write_TEXT("2) QAD "   ,0,2,1);
        Glcd_Write_TEXT("3) Potenciometro",0,3,1);
  }
}
int cursor_menu(){
  //aqui se va a estar utilizando el it como iterator, revisando si el teclado
//ha seleccionado las flechas de arriba o abajo, aumentando o disminuyendo al operador
  int it=0;
  int max_n_options=3;
  clean_PS2();
  texto_menu(0);
  delay_ms(2000);
  while(keydata!=ENTER){
    if(Ps2_Key_Read(&keydata, &special, &down)){
      if(down){
       if(keydata==DOWN_ARROW||keydata==UP_ARROW){
        if(keydata==DOWN_ARROW){
          it=it+1;
          if(it>max_n_options){it=1;}
          texto_menu(it); clean_PS2();glcd_write_text("dw",0,0,1) ;delay_ms(500); glcd_write_text("    ",0,0,1);

        }
        if(keydata==UP_ARROW){
          it=it-1;
          if(it==0){it=max_n_options;}
          texto_menu(it); clean_PS2();glcd_write_text("up",0,0,1) ;delay_ms(500); glcd_write_text("    ",0,0,1);
        }

      }glcd_write_text("ud",0,0,1);delay_ms(500); glcd_write_text("    ",0,0,1);
      }glcd_write_text("down",0,0,1);delay_ms(500); glcd_write_text("    ",0,0,1);
    }
  }
  glcd_write_text("esc",0,0,1) ;  delay_ms(500); glcd_write_text("    ",0,0,1);
  clean_PS2();
  return it;
}


unsigned short page2pos(int page_num){
  page_num=64-page_num;
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