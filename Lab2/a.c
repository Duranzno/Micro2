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
          arreglo_hora_militar_up(indice,it);
          clean_PS2();
        }
        if(keydata==DOWN_ARROW){
          it=it-1;
          arreglo_hora_militar_dw(indice,it);
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
#define decena_hora 0
#define unidad_hora 1
#define decena_minuto 3
#define unidad_minuto 4

unsigned short arreglo_hora_militar_up(int i,unsigned int valor_nuevo){
  if(i==decena_hora){
    if(valor_nuevo>2){//Decena de hora solo puede ser 0,1 o 2 2->0
     return 0;
    }
  }
  if(i==unidad_hora){
    if(HORA[decena_hora]==2&&valor_nuevo>3){//Arreglo Hora 23->00
      HORA[decena_hora]=0;
      return 0;
    }
    if(valor_nuevo=>9){return 0;}//Arreglo Unidad Hora && Unidad Minuto 9->0
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
    if(valor_nuevo<0){//Decena de hora solo puede ser 0,1 o 2 2->0;
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
void cron_cursor(){
int x_pos=60,i,j;
  //hay 5 variables de hora y alarma
  clean_PS2();
  for(i=0;i<5;i++){
    if(i!=2){
      j=num_selector(60+i*5+1,i)+'0';
      HORA[i]=j;
    }else if(i==2){
      HORA[2]=':' ;
    }
    clean_PS2();
    cron_write();
  }
}

void cron_write(){
  Glcd_Write_TEXT("                                              ",60,7,1);
  int i=0;
  for(i=0;i<12;i++){
    Glcd_Write_Char(HORA[i],60+i*5+1,7,1);
  }
}