//#include "config.h"
#include "config_RX.h"

#include "sprites.h"
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned dato=0, dato2=0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void timer8 () org 0x7A {
  IFS3bits.T8IF=0;
  LATFBITS.LATF4=~LATFBITS.LATF4;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main () {
  config_IO();  config_LCD();
  config_INT(); config_timer8();
  config_RX();
  TRISFbits.TRISF4=0;
  config_timer8()  ;
  Glcd_Fill(0);
  animate_charmander_2s();
  delay_ms(2000);
  while(1){
    while(!UART1_Data_Ready()); //Espera que reciba un dato
    dato=UART1_Read();
    if(dato==1){
      glcd_write_text("Caso 1",0,31,1);
     }
    else if(dato==2) {
      glcd_write_text("Caso 2",0,31,1);  }
   else if(dato==3) {
      glcd_write_text("Caso 3",0,31,1);  }
      dato=0;
/*while(!UART1_Data_Ready()); //Espera que reciba un dato
      dato2=UART1_Read();
      dato2=(dato2<<8)+dato;
      PDC3=dato2;
      PORTBbits.RB0=~PORTBbits.RB0;
      while(!UART1_Data_Ready()); //Espera que reciba un dato
      dato=UART1_Read();
      PORTBbits.RB0=~PORTBbits.RB0;
      while(!UART1_Data_Ready()); //Espera que reciba un dato
      dato2=UART1_Read();
      dato2=(dato2<<8)+dato;
      PDC4=dato2;
      PORTBbits.RB0=~PORTBbits.RB0;*/
 }
}