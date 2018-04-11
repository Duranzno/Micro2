void texto_menu(){
    Glcd_Write_TEXT("Laboratorio 2",31,0,1);
    Glcd_Write_TEXT("1) Cronometro",0,1,1);
    Glcd_Write_TEXT("1) Captura",0,2,1);
    Glcd_Write_TEXT("3) PWM  ",0,3,1);
}
int cursor_menu(int max_n_options){
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
      if(keydata==ESC){
        Glcd_Write_TEXT("ESC" ,60,7,1);
        break;
      }
      }
    }
  }
    return it;
}
void caso_1(){
  ...
     selected=cursor_menu(5);
   ...
}
void main(){
	...
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
