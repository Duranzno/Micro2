
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