sbit GLCD_D7 at RD6_bit;
sbit GLCD_D6 at RD5_bit;
sbit GLCD_D5 at RD4_bit;
sbit GLCD_D4 at RD3_bit;
sbit GLCD_D3 at RD2_bit;
sbit GLCD_D2 at RD1_bit;
sbit GLCD_D1 at RC14_bit;
sbit GLCD_D0 at RC13_bit;
sbit GLCD_D7_Direction at TRISD6_bit;
sbit GLCD_D6_Direction at TRISD5_bit;
sbit GLCD_D5_Direction at TRISD4_bit;
sbit GLCD_D4_Direction at TRISD3_bit;
sbit GLCD_D3_Direction at TRISD2_bit;
sbit GLCD_D2_Direction at TRISD1_bit;
sbit GLCD_D1_Direction at TRISC14_bit;
sbit GLCD_D0_Direction at TRISC13_bit;
sbit GLCD_CS1 at LATD7_bit;
sbit GLCD_CS2 at LATF0_bit;
sbit GLCD_RS at LATD10_bit;
sbit GLCD_RW at LATD11_bit;
sbit GLCD_EN at LATD0_bit;
sbit GLCD_RST at LATF1_bit;
sbit GLCD_CS1_Direction at TRISD7_bit;
sbit GLCD_CS2_Direction at TRISF0_bit;
sbit GLCD_RS_Direction  at TRISD10_bit;
sbit GLCD_RW_Direction at TRISD11_bit;
sbit GLCD_EN_Direction at TRISD0_bit;
sbit GLCD_RST_Direction at TRISF1_bit;

unsigned adc_value;
 char txt[9];
 void main()
 {ANSELC=0; ANSELD=0; ANSELE=0; ANSELB=0;
 ANSELE=0X00C0;  //PING RE6 Y RE7 ENTRADAS ANALOGICAS


CORCONbits.IPL3=0;
SRbits.IPL=0;
INTCON1bits.NSTDIS=0;
INTCON2bits.GIE=1;


CM2CONbits.CREF=0;  // referencia externa en el pin inversor
CM2CONbits.CCH=2;   // referencia interna en el pin no inversor
CVRCONbits.BGSEL=1; // referencia interna de 0.6 v en el pin no inversor
CM2CONbits.CON=1;   // comparador habilitado

CM1CONbits.CREF=1;  // entrada vin+ se onecta internamente al voltaje de CVrefin
CVRCONbits.CVR=15 ; // BIT DE SELECCION DE VOLTAJE DE GUENTE DE REFERENCIA
CM1CONbits.CCH=2;   // referencia interna en el pin no inversor
CM1CONbits.CON=1;   // comparador habilitado

 ADC1_Init_Advanced(_ADC_12bit,_ADC_INTERNAL_REF); //Initialization del convertidor ADC

Glcd_Init();
Glcd_Set_Font(font5x7 , 5, 7, 32);
Glcd_Fill(0);
Glcd_Write_Text("Verificacion sensores", 1, 0, 0);

while(1)
{
adc_value= ADC1_Get_Sample(31);
if(CMSTATbits.C1OUT==1)
Glcd_Write_Text("FALLA", 10, 3, 1);
else Glcd_Write_Text("ESTADO NORMAL", 10, 3, 1);
adc_value=adc_value*0.8984375;
WordToStr(adc_value, txt);
Glcd_Write_Text(txt, 40, 5, 1);
Glcd_Write_Text("mV",70, 5, 1);
Delay_ms(500);

 if(CMSTATbits.C2OUT==0)
Glcd_Write_Text("FALLA", 10, 3, 1);
else Glcd_Write_Text("ESTADO NORMAL", 10, 3, 1);
adc_value=adc_value*0.8984375;
WordToStr(adc_value, txt);
Glcd_Write_Text(txt, 40, 5, 1);
Glcd_Write_Text("mV",70, 5, 1);
Delay_ms(500);

}
}