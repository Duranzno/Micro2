//#include "config.h"
#include "config_RX.h"
#include "motores.h"
#include "sprites.h"
//~~~~~~~~~~~~~~~~~~~~~~~~Variables  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned short dato=0, dato2=0;
unsigned char URECIBIR="#";
float pantalla=0;
char txt[7];
int cnt;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void timer8 () org 0x7A {
  IFS3bits.T8IF=0;
  LATFBITS.LATF4=~LATFBITS.LATF4;
}
void UART_RX_INT() org 0x00002C{
 IFS0bits.U1RXIF=0;
 PORTBbits.RB0=~PORTBbits.RB0;
 if(U1STAbits.FERR == 1)
  {URECIBIR='0';}
  if(U1STAbits.OERR == 1){
    U1STAbits.OERR = 0;
    URECIBIR='0';}
  if(U1STAbits.URXDA == 1){
    URECIBIR = U1RXREG;
  }

 }
void PWM4() org 0xD6{ 
 IFS6bits.PWM4IF=0;
 if(PORTDbits.RD11==0)
  {
  //glcd_image(stop);

  glcd_write_text("Falla Motor 4",0,7,1);
  IOCON4bits.FLTDAT=0;
  PWMCON4bits.FLTSTAT=0;
  //T2CONbits.TON=1;contador=0;
  }

}

void PWM3() org 0xD4{
 IFS6bits.PWM3IF=0;
 PWMCON3bits.FLTSTAT=0;
 if(PORTDbits.RD0==0){
  IOCON4bits.FLTDAT=0;
  PWMCON4bits.FLTSTAT=0;
   //glcd_image(stop2);
   glcd_write_text("Falla Motor 3",0,6,1);

  //T2CONbits.TON=1;
  }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main () {
   for(cnt=0;cnt<7;cnt++) {
                        txt[cnt]="#";
                }
                InitMCU();
  config_IO();  config_LCD();
  delay_ms(100);
  config_INT(); //config_timer8();
  config_Init_rx();
  TRISFbits.TRISF4=0;
 // config_timer8()  ;
  Glcd_Fill(0);
  animate_charmander_2s();
  while(1){
    //while(!UART1_Data_Ready()); //Espera que reciba un dato

    floattostr(pantalla,txt);
    glcd_fill(0);
    glcd_write_text(URECIBIR,60,0,1);
    glcd_write_text("recibio algo",60,7,1);
    /*while(!UART1_Data_Ready()); //Espera que reciba un dato
    dato=UART1_Read();
    pantalla=dato;
    floattostr(pantalla,txt);
    glcd_fill(0);
    glcd_write_text(txt,60,0,1);
    glcd_write_text("recibio algo",60,7,1);
    if(dato==1){
      config_motor();
      glcd_write_text("Caso 1",0,4,1);
      delay_ms(100);
      while(!UART1_Data_Ready());
      if(dato!=255) {
        dato=UART1_Read();
      while(!UART1_Data_Ready());
      dato2=UART1_Read();
      pantalla=dato;
     floattostr(pantalla,txt);
   glcd_write_text(txt,0,6,1);
          pantalla=dato2;
    floattostr(pantalla,txt);
   glcd_write_text(txt,0,7,1);
   }
   dato=0;
     }
    else if(dato==2) {
      glcd_write_text("Caso 2",2,4,1); 
      delay_ms(100); }
   else if(dato==3) {
      glcd_write_text("Caso 3",2,4,1); 
      delay_ms(100); }
      else {
      glcd_write_text("Caso 5",2,4,1);
      delay_ms(100);  }
       dato=0;*/
       }



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
      PORTBbits.RB0=~PORTBbits.RB0;}*/

}