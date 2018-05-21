
unsigned adc_value;
char txt[6];
void main()
{ ANSELC=0;
ANSELD=0;
ANSELE=0x00C0; //RE7 y RE6 como entradas analógicas
CORCONbits.IPL3=0; //la interrupción de la CPU es de nivel 7 o menor
SRbits.IPL=0; //interrupción de la CPU es de nivel 0
INTCON1bits.NSTDIS=0; //interrupción anidadas activada
INTCON2bits.GIE=1; //interrupciones habilitadas
CM1CONbits.CREF=0; // referencia externa en el pin inversor
CM1CONbits.CCH=3; // referencia interna en el pin no inversor
CVRCONbits.BGSEL=0; // referencia interna de 1.2v en el pin no
inversor
CM1CONbits.CON=1; // comparador habilitado
ADC1_Init_Advanced(_ADC_12bit,_ADC_INTERNAL_REF); //Initialization del
convertidor ADC
Glcd_Init();
Glcd_Set_Font(font5x7 , 5, 7, 32);
Glcd_Fill(0);
Glcd_Write_Text("Verificacion sensores", 1, 0, 0);
while(1)
{ adc_value = ADC1_Get_Sample(31);
if(CMSTATbits.C1OUT==0)
Glcd_Write_Text("nivel no alcanzado ", 10, 3, 1);
else Glcd_Write_Text("nivel alcanzado ", 10, 3, 1);
adc_value=adc_value*0.8984375;
WordToStr(adc_value, txt);
Glcd_Write_Text(txt, 40, 5, 1);
Glcd_Write_Text("mV",70, 5, 1);
Delay_ms(500);
}
}