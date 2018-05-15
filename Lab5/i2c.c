// Glcd module connections
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
sbit GLCD_RST at LATE4_bit;
sbit GLCD_CS1_Direction at TRISE3_bit;
sbit GLCD_CS2_Direction at TRISE2_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISE4_bit;
// End Glcd module connections
unsigned adc_valor,resistencia,parte_alta,parte_baja,
resistencia_alamacenada;
char txt[6];
void escribir_24lc02(unsigned char valor,unsigned char direccion)
{ I2C1_Start(); // emitir señal de inicio I2C
I2C1_Write(0xA0); // enviar byte a través de (dirección del dispositivo + W)
I2C1_Write(direccion); // enviar byte (dirección de ubicación EEPROM)
I2C1_Write(valor); // enviar datos (los datos se escriban)
I2C1_Stop();
Delay_ms(50);
}
unsigned leer_24lc02(unsigned char direccion)
{ unsigned char valor;
I2C1_Start(); // emitir señal de inicio I2C
I2C1_Write(0xA0); // enviar byte a través de (dirección del dispositivo + W)
I2C1_Write(direccion); // enviar byte (dirección de datos)
I2C1_Restart(); // emitir señal repetida para iniciar I2C
I2C1_Write(0xA1); // enviar byte (dirección del dispositivo + R)
valor = I2C1_Read(1); // Leer los datos
I2C1_Stop();
Delay_ms(50);
return valor;
}
void guardado_int1() org 0x3C
{ escribir_24lc02((adc_valor>>8),0); //guardando parte alta en posicion 0
escribir_24lc02((adc_valor&0xFF),1); //guardando parte baja en posicion 1
IFS1bits.INT1IF=0;
}
void main()
{ ANSELC=0x0000; //Configuracion de E/S digitales
ANSELD=0x0000; //Configuracion de E/S digitales
ANSELE=0x0040; //RE6 como entrada analogica
ANSELB=0x0000; //Configuracion de E/S digitales
CORCONbits.IPL3=0; //la interrupción de la CPU es de nivel 7 o menor
SRbits.IPL=0; //interrupción de la CPU es de nivel 0
INTCON1bits.NSTDIS=0; //interrupción anidadas activada
INTCON2bits.GIE=1; //interrupciones habilitadas
IFS1bits.INT1IF=0;
IEC1bits.INT1IE=1; Habilita interrupción por INT1
RPINR0Bits.INT1R=47; //asigna INT1 al puerto rpi47
ADC1_Init_Advanced(_ADC_12bit, _ADC_INTERNAL_REF); //Inicializacion del
convertidor ADC
I2C1_Init(100000); //inicializa i2c a 100Khz
Glcd_Init();
Glcd_Set_Font(Font5x7 , 5, 7, 32);
Glcd_Fill(0);
Glcd_Write_Text(" Resistencia actual ", 0, 0, 0);
Glcd_Write_Text(" Valor almacenado ", 0, 4, 0);
while(1)
{ adc_valor = ADC1_Get_Sample(30);
resistencia=adc_valor*1.24053;
WordToStr(resistencia, txt);
Glcd_Write_Text(txt, 50, 2, 1);
parte_alta=leer_24lc02(0); //lee la posición 0 de la memoria
parte_baja=leer_24lc02(1); //lee la posición 1 de la memoria
resistencia_alamacenada=(parte_alta<<8)+parte_baja;
resistencia_alamacenada=resistencia_alamacenada*1.24053;
WordToStr(resistencia_alamacenada, txt);
Glcd_Write_Text(txt, 50, 6, 1);
Delay_ms(500);
}
}