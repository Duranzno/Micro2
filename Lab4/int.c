#define FP 15000000
#define BAUDRATE 9600
#define BRGVAL ((FP/BAUDRATE)/16)-1
unsigned char UENVIAR;
unsigned char URECIBIR;
 void UART_TX_INT() org 0x00002A{
      IFS0bits.U1TXIF=0;
      U1TXREG=UENVIAR;
 }
 void UART_RX_INT() org 0x00002C{
 IFS0bits.U1RXIF=0;
 if(U1STAbits.FERR == 1)
  {URECIBIR='0';}
  if(U1STAbits.OERR == 1){
    U1STAbits.OERR = 0;
    URECIBIR='0';}
  if(U1STAbits.URXDA == 1){
    URECIBIR = U1RXREG;
  }

 }

void config_Init_rx(){

  U1MODEbits.STSEL=0;
  U1MODEbits.PDSEL=0;
  U1MODEbits.ABAUD=0;
  U1MODEbits.BRGH=0;
  U1BRG=BRGVAL;
  U1STAbits.URXISEL1=0;
  IFS0bits.U1RXIF=0;
  IEC0bits.U1RXIE=1;
  IPC2bits.U1RXIP=6;
  RPINR18bits.U1RXR=46; //U1RX
  RPOR9bits.RP101R=1;
  U1MODEbits.UARTEN=1;

}


void config_TX(){
  U1MODEbits.STSEL=0;
  U1MODEbits.PDSEL=0;
  U1MODEbits.ABAUD=0;
  U1MODEbits.BRGH=0;
  U1BRG=BRGVAL;
  U1STAbits.UTXISEL1=0;
  IEC0BITS.U1TXIE=1;
  U1MODEbits.UARTEN=1;
  delay_us(105);
  IFS0bits.U1TXIF=0;
  IEC0bits.U1TXIE=1;
  IPC3bits.U1TXIP=6;
}