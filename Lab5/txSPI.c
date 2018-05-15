///////////////////////////////////////////////////TRANSMISION//////////////////////////////////////////////
////////
// Keypad module connections
unsigned keypadPort at PORTE;
unsigned keypadPort_Direction at TRISE;
// End Keypad module connections
unsigned short tecla=0;
int teclado()
{ int temp=0;
while(temp==0)temp=Keypad_Key_Press();
switch(temp)
{ case 1: temp = 68; break; // D
case 2: temp = 67; break; // C
case 3: temp = 66; break; // B
case 4: temp = 65; break; // A
case 5: temp = 35; break; // #
case 6: temp = 57; break; // 9
case 7: temp = 54; break; // 6
case 8: temp = 51; break; // 3
case 9: temp = 48; break; // 0
case 10: temp = 56; break; // 8
case 11: temp = 53; break; // 5
case 12: temp = 50; break; // 2
case 13: temp = 42; break; // *
case 14: temp = 55; break; // 7
case 15: temp = 52; break; // 4
case 16: temp = 49; break; // 1
}
Delay_ms(200);
return temp;
}
void main()
{ ANSELC=0;
ANSELD=0;
ANSELE=0;
ANSELB=0;
SPI1_Init_Advanced(_SPI_MASTER,_SPI_8_BIT,_SPI_PRESCALE_SEC_8,_
SPI_PRESCALE_PRI_64,_SPI_SS_DISABLE,_SPI_DATA_SAMPLE_MIDDLE,
_SPI_CLK_IDLE_LOW,_SPI_ACTIVE_2_IDLE);
RPOR0bits.RP64R=5; //SDO1
RPOR8bits.RP99R=6; //SCK1
RPINR20bits.SDI1R=72; //SDI1
Keypad_Init();
while(1)
{ tecla=teclado();
SPI1_Write(tecla);
Delay_ms(100);
}
}

