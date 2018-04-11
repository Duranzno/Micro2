void Timer4() org 0x4A{
    IFS1bits.T4IF=0;
    }
void Timer5() org 0x4C{
    IFS1bits.T5IF=0;
    }


void main() {
  ANSELE=0;
  ANSELG=0;
  ANSELD=0;
  TRISEbits.TRISE5=0;
  TRISEbits.TRISE7=0;
  TRISGbits.TRISG6=0;
  TRISGbits.TRISG8=0;
  TRISFbits.TRISF5=0;
  RPOR6bits.RP85R =0b010000;     //pin comparador 1  RE5
  RPOR6bits.RP87R =0b010001;    //pin comparador 2  RE7
 RPOR13bits.RP118R=0b010010;  //pin comparador 3 RG6
 RPOR14bits.RP120R=0b010011;
 RPOR9bits.RP101R=0b010100;
   // pin comparador 4 RG8
   SRbits.IPL=0;
   CORCONbits.IPL3=0;
   INTCON2bits.GIE=1;
   IEC1bits.T4IE=1;
   IEC1bits.T5IE=1;
   IFS1bits.T4IF=0;
   IFS1bits.T5IF=0;
   
   
 T4CONbits.TCKPS=0;            //preescaler 1:1
 T4CONbits.TCS=0;
 TMR4=0;
 PR4=2000;                    // timer a 1ms
 T5CONbits.TCKPS=5;            //prescaler 256:1
 T5CONbits.TCS=0;
 TMR5=0;
 PR5=49063; // timer a 5s
 OC5CON1bits.OCTSEL=3;
 OC1CON1bits.OCTSEL=2;        // T4CLK fuente de reloj
 OC2CON1bits.OCTSEL=2;
 OC3CON1bits.OCTSEL=2;
 OC4CON1bits.OCTSEL=2;
 OC5CON1bits.OCM=5;
 OC1CON1bits.OCM=5;          //MODO COMPARADOR DUAL DE PULSOS CONTINUOS
 OC2CON1bits.OCM=5;
 OC3CON1bits.OCM=5;
 OC4CON1bits.OCM=5;
 OC5R=10; OC5RS=2047;
 OC1R=306; OC1RS=2047;     //CICLO UTIL 15%
 OC2R=921; OC2RS=2047;     //CICLO UTIL 45%
 OC3R=1227; OC3RS=2047;     //CICLO UTIL 60%
 OC4R=1637; OC4RS=2047;     //CICLO UTIL 80%
 OC1CON2bits.SYNCSEL=0b00101;    //disparo con el OC 5
 OC2CON2bits.SYNCSEL=0b00101;
 OC3CON2bits.SYNCSEL=0b00101;
 OC4CON2bits.SYNCSEL=0b00101;
 OC5CON2bits.SYNCSEL=0b01111;
  T5CONbits.TON=1;
  T4CONbits.TON=1;
  while(1){

  
  }
}