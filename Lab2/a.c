void num_update(int it,int x_pos,int page){
  Glcd_Write_Char(it+'0',x_pos,page,1);
}
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
int x_pos=60,i,j;
  //hay 5 variables de hora y alarma
  clean_PS2();
  for(i=0;i<5;i++){
    if(i!=2){
      j=num_selector(60+i*5)+'0';
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
    Glcd_Write_Char(HORA[i],60+i*5,7,1);
  }
}