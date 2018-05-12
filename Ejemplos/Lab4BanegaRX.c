 ///////////////////////////////////////////////////RECEPCION//////////////////////////////////////////////////////
const code char BIENVENIDO[1024] = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 224,  32,  32,  32,  32,  32, 192,   0, 224,   0,   0, 224,  32,  32,  32,  32,  32,   0,   0, 224, 192,   0,   0,   0,   0, 224,   0,  96, 128,   0,   0,   0, 128,  96,   0, 224,  32,  32,  32,  32,  32,   0,   0, 224, 192,   0,   0,   0,   0, 224,   0, 224,   0,   0, 224,  32,  32,  32,  32,  64, 128,   0, 192,  32,  32,  32,  32,  32,  32, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 192, 224, 208, 168, 208, 160,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  63,  34,  34,  34,  34,  34,  29,   0,  63,   0,   0,  63,  34,  34,  34,  34,  32,   0,   0,  63,   0,   1,   6,   8,  48,  63,   0,   0,   3,  12,  48,  12,   3,   0,   0,  63,  34,  34,  34,  34,  32,   0,   0,  63,   0,   1,   6,   8,  48,  63,   0,  63,   0,   0,  63,  32,  32,  32,  32,  16,  15,   0,  31,  32,  32,  32,  32,  32,  32,  31,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,  64, 224, 240, 152, 232, 180,  27, 237, 178,  29, 230,  57, 198, 243,  30,   0, 252, 196,  56, 224,  24, 240, 216,  48, 232, 152, 112, 224, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   1,   3,   6,   5,   3,   6,   3,   6,   5,  14,   1,  31,   0,  28, 187, 108, 247, 253, 246, 123,  53,  27,  13,   6,   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   6,   3,   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
};

const code char MENU[1024] = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 224,  96, 128,   0, 128,  96, 224,   0, 224, 160, 160,  32,   0, 224,  96, 128,   0, 224,   0, 224,   0,   0,   0, 224,   0,   0,   0, 224,  32,  32, 192,   0, 224,  32,  32,  32, 192,   0, 224,   0, 224,  96, 128,   0, 224,   0, 192,  32,  32,  32,  64,   0, 224,   0, 224,  32,  32, 192,   0,   0, 128,  96, 128,   0,   0, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   7,   0,   1,   6,   1,   0,   7,   0,   7,   4,   4,   4,   0,   7,   0,   1,   6,   7,   0,   3,   4,   4,   4,   3,   0,   0,   0,   7,   1,   1,   0,   0,   7,   1,   1,   1,   6,   0,   7,   0,   7,   0,   1,   6,   7,   0,   3,   4,   4,   4,   2,   0,   7,   0,   7,   1,   1,   0,   0,   6,   1,   1,   1,   6,   0,   7,   4,   4,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192,  32,  32,  32,  64,   0,   0, 128,  96, 128,   0,   0,  64, 160,  32,  64,   0, 192,  32,  32,  32, 192,   0,   0,   0,   0,   0,  64, 224,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192,  32,  32,  32,  64,   0,   0, 128,  96, 128,   0,   0,  64, 160,  32,  64,   0, 192,  32,  32,  32, 192,   0,   0,   0,   0,   0,  64,  32,  32, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   3,   4,   4,   4,   2,   0,   6,   1,   1,   1,   6,   0,   2,   4,   5,   2,   0,   3,   4,   4,   4,   3,   0,   0,   0,   0,   0,   0,   7,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   3,   4,   4,   4,   2,   0,   6,   1,   1,   1,   6,   0,   2,   4,   5,   2,   0,   3,   4,   4,   4,   3,   0,   0,   0,   0,   0,   6,   5,   5,   4,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,  64,  64,  64, 128,   0,   0,   0, 192,   0,   0,   0, 128,  64,  64, 128,   0, 128,  64,  64,  64, 128,   0,   0,   0,   0, 128,  64,  64, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   7,   8,   8,   8,   4,   0,  12,   3,   2,   3,  12,   0,   4,   9,  10,   4,   0,   7,   8,   8,   8,   7,   0,   0,   0,   0,   4,   8,   9,   6,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192,   0,   0,   0,   0,   0,   0, 192, 192,   0,   0,   0, 192,  64,  64,  64,  64, 128,   0, 128,  64,  64,  64,  64, 128,   0, 192,  64,  64,  64,  64, 128,   0,   0,   0, 192, 192,   0,   0,   0,  64,  64, 192,  64,  64,   0, 128,  64,  64,  64,  64, 128,   0, 192,  64,  64,  64,  64, 128,   0, 192,   0, 128,  64,  64,  64,  64, 128,   0,   0,   0, 128,  64,  64, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  31,  16,  16,  16,   0,  24,   7,   4,   4,   7,  24,   0,  31,  18,  18,  18,  18,  13,   0,  15,  16,  16,  16,  16,  15,   0,  31,   2,   2,   2,   2,  29,   0,  24,   7,   4,   4,   7,  24,   0,   0,   0,  31,   0,   0,   0,  15,  16,  16,  16,  16,  15,   0,  31,   2,   2,   2,   2,  29,   0,  31,   0,  15,  16,  16,  16,  16,  15,   0,   0,   0,   8,  16,  18,  13,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
};
// Glcdmodule connections
sbit GLCD_D7 at RE1_bit;
sbit GLCD_D6 at RE0_bit;
sbit GLCD_D5 at RF1_bit;
sbit GLCD_D4 at RF0_bit;
sbit GLCD_D3 at RD7_bit;
sbit GLCD_D2 at RD6_bit;
sbit GLCD_D1 at RD5_bit;
sbit GLCD_D0 at RD4_bit;
sbit GLCD_D7_Direction at TRISE1_bit;
sbit GLCD_D6_Direction at TRISE0_bit;
sbit GLCD_D5_Direction at TRISF1_bit;
sbit GLCD_D4_Direction at TRISF0_bit;
sbit GLCD_D3_Direction at TRISD7_bit;
sbit GLCD_D2_Direction at TRISD6_bit;
sbit GLCD_D1_Direction at TRISD5_bit;
sbit GLCD_D0_Direction at TRISD4_bit;
sbit GLCD_CS1 at LATE3_bit;
sbit GLCD_CS2 at LATE2_bit;
sbit GLCD_RS at LATD1_bit;
sbit GLCD_RW at LATD2_bit;
sbit GLCD_EN at LATD3_bit;
sbit GLCD_RST at LATC13_bit;
sbit GLCD_CS1_Direction at TRISE3_bit;
sbit GLCD_CS2_Direction at TRISE2_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISC13_bit;
// EndGlcdmodule connections
void BIENVE()
{
 Glcd_Image(BIENVENIDO);
 Glcd_Write_Text("Juan DiSarli",40,5,1);
 Glcd_Write_Text("Jose Banega",40,6,1);
 Glcd_Write_Text("Jose Guatume",40,7,1);
 Delay_ms(2000);
}
unsigned tecla=48;
unsigned short mot=1;
unsigned char txt[8],txt1[8];
unsigned int valor1,valor2,valor=0;
unsigned buffer;


void main()
    {
    //CONFIGURACION DEL PLL PARA ALCANZAR UNA VELOCIDAD DE 30MHZ
    PLLFBD = 58; //M = 60
    CLKDIVbits.PLLPOST= 0; // N1 = 2
    CLKDIVbits.PLLPRE= 0; // N2 = 2
    OSCTUN = 0;
    OSCCON=0x0301;
    while(OSCCONbits.COSC!= 0x3);
    ANSELC=0;
    ANSELD=0;
    ANSELE=0;
    ANSELB=0;
    TRISBBITS.TRISB15=1;
    TRISEbits.TRISE4=0;
   TRISEbits.TRISE5=0;
   TRISEbits.TRISE6=0;
   TRISEbits.TRISE7=0; //PWM 3 y 4
   PTCONbits.PTEN=1;//SE act. el modulo pwm
    SPI1_Init_Advanced(_SPI_SLAVE,_SPI_8_BIT,_SPI_PRESCALE_SEC_8,_SPI_PRESCALE_PRI_64,_SPI_SS_DISABLE,_SPI_DATA_SAMPLE_MIDDLE,_SPI_CLK_IDLE_LOW, _SPI_ACTIVE_2_IDLE);
    RPINR20bits.SDI1R=46;//SDI1
    RPINR20bits.SCK1R=47; //SCK1
    RPOR9bits.RP101R=5;//SDO
    //---
    //PWM 3 y 4
   IOCON3=0xC000;
   IOCON4=0xC000;//modulo PWM controla PWMH y PWML del PWM 3 y 4
   PTCON=0x0400;
   PTCON2=0;
   DTR3=50;
   DTR4=50;
   ALTDTR3=50;
   ALTDTR4=50;// tiempo muerto de 4.5us
   PTPER=1024;//perido de 3.9kHz
   PDC3=512;
   PDC4=512;
    PTCONbits.PTEN=1;//SE act. el modulo pwm
    // -----

    Glcd_Init();
    Glcd_Set_Font(font5x7 , 5, 7, 32);
    BIENVE();
    Glcd_Fill(0);
    Glcd_Write_Text("Tecla Pulsada:", 0, 2, 1);
    Glcd_Write_Char(tecla, 10, 4, 1);
    delay_ms(1000);
    while(1)
      {
      while(!SPI1STATbits.SPIRBF); //Esperando que se reciba el dato
      tecla=SPI1_Read(buffer);
      Glcd_Write_Char(tecla, 10, 4, 1);
      delay_ms(1000);
      switch(tecla)
          {
          case 49:
          Glcd_Write_Text("CASO 1", 10, 6, 1);
          delay_ms(500);
            while(mot < 3)
           {
                  if(mot==1)

              {
                       if( SPI1STATBITS.SPIROV==1)
                      {SPI1STATBITS.SPIROV=0;
                      continue;              }

                      while(!SPI1STATbits.SPIRBF);
                      valor=SPI1_Read(buffer);
                      valor1=valor;
                      Inttostr(valor1,txt1);


                    if( SPI1STATBITS.SPIROV==1)
                      {SPI1STATBITS.SPIROV=0;
                      continue;              }

                      while(!SPI1STATbits.SPIRBF);
                      valor=SPI1_Read(buffer);
                      valor2=valor;
                      Inttostr(valor2,txt);


                      valor=(valor2<<8)+valor1;

                      Inttostr(valor,txt);
                      if(valor > 1024){mot =3;valor = 512;}
                      PDC3=valor;
                      Glcd_Write_text("MOTOR 1 ", 60, 3, 1);
                      Glcd_Write_text(txt, 60, 4, 1);
                      mot++;
                      
                   }

                   else if(mot==2)
                   {
                      if( SPI1STATBITS.SPIROV==1)
                      {SPI1STATBITS.SPIROV=0;
                      continue;              }

                      while(!SPI1STATbits.SPIRBF);
                      valor=SPI1_Read(buffer);
                      valor1=valor;
                      Inttostr(valor1,txt1);


                    if( SPI1STATBITS.SPIROV==1)
                      {SPI1STATBITS.SPIROV=0;
                      continue;              }

                      while(!SPI1STATbits.SPIRBF);
                      valor=SPI1_Read(buffer);
                      valor2=valor;
                      Inttostr(valor2,txt);


                      valor=(valor2<<8)+valor1;
                      Inttostr(valor,txt1);
                      if(valor > 1024){  mot =3;valor = 512;}
                      PDC4=valor;
                      Glcd_Write_text("MOTOR 2 ",60,5,1);
                      Glcd_Write_text(txt1, 60,6, 1);
                      mot--;
                   }


           }
              PDC4=512;
                   PDC4=512;
                   mot =1;
                   Glcd_fill(0);
                   Glcd_Write_Text("MOTORES DESACTIVADOS", 0, 4, 1);
                   delay_ms(2000);
                   Glcd_fill(0);
                   Glcd_Write_Text("Tecla Pulsada:", 0, 2, 1);
                   Glcd_Write_Char(tecla, 10, 4, 1);
                   delay_ms(1000);
          break;

          case 50:
          Glcd_Write_Text("CASO 2", 10, 6, 1);
          delay_ms(2000);
          break;

          case 51:
          Glcd_Write_Text("CASO 3", 10, 6, 1);
          delay_ms(2000);
          break;
          
          case 52:
          Glcd_Write_Text("GUARDANDO EN EEPROM", 10, 6, 1);
          delay_ms(2000);
          break;
          
          case 53:
          Glcd_Write_Text("LEYENDO LA EEPROM", 10, 6, 1);
          delay_ms(2000);
          break;
          }
          Glcd_fill(0);
                   Glcd_Write_Text("Tecla Pulsada:", 0, 2, 1);
                   Glcd_Write_Char(tecla, 10, 4, 1);
                   delay_ms(1000);
                   tecla = 48;
      }
}