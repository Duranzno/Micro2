
#define decena_hora 0
#define unidad_hora 1
#define decena_minuto 3
#define unidad_minuto 4
int page2pos(int page_num){
switch(page_num){
    case 0:
    return 0;
    break;
    case 1:
    return 8;
    break;
    case 2:
    return 16;
    break;
    case 3:
    return 24;
    break;
    case 4:
    return 32;
    break;
    case 5:
    return 40;
    break;
    case 6:
    return 48;
    break;
    case 7:
    return 56;
    break;
  }
}
char intToAscii(int fn){
   char t=0;
   if(fn>0&&fn<=9){
      intToStr(fn,t);
   }else if(fn==10){
      intToStr(0,t);
   }else{
    t='0';
   }
   return t;
}

void oscilador_usado(){
  switch(OSCCONBits.COSC){
    case 0:
      glcd_write_text("FRC",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
    case 1:
      glcd_write_text("FRCPLL",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
    case 2:
      glcd_write_text("posc",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
    case 3:
      glcd_write_text("posc_pll",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
   case 4:
      glcd_write_text("sosc",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
    case 5:
      glcd_write_text("lprc",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
    case 6:
      glcd_write_text("frcdiv16",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
      case 7:
      glcd_write_text("frcdivn",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
     default:
      glcd_write_text("none",0,7,1);
      delay_ms(2000);
      glcd_fill(0);
      break;
  }
 }