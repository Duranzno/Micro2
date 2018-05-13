#include "ui.h"
#include "config.h"
#include "UART.h"





 unsigned dato=0, dato2=0;
void main () {
        config_IO();
        config_INT();
        config_LCD();

        UART1_Init_Advanced(2400,2,1,1);
        RPINR18bits.U1RXR=46; //U1RX
        RPOR9bits.RP101R=1; //U1TX
        config_uart_rx ();
          while(1)
 {
  while(!UART1_Data_Ready()); //Espera que reciba un dato
  dato=UART1_Read();
  if(dato==1) {
   glcd_write_text("Caso 1",0,7,1);  }
   else if(dato==2) {
   glcd_write_text("Caso 2",0,7,1);  }
   else if(dato==3) {
   glcd_write_text("Caso 1",0,7,1);  }
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