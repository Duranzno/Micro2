
unsigned adc_value;
char txt[6];
unsigned short canal[]={30,31,14,15},i;
void main(){
	ANSELC=0x0000; //Configuracion de E/S digitales
	ANSELD=0x0000; //Configuracion de E/S digitales
	ANSELE=0x00C0; //RE7 y RE6 como entradas analogicas
	ANSELB=0xC000; //RB15 y RB14 como entradas analogicas
	Glcd_Init(); //Inicializacion Interfaz Grafica
	Glcd_Set_Font(font5x7, 5, 7, 32);// Definicion de la fuente para las letras
	Glcd_Fill(0); //Borrado de la pantalla
	ADC1_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF); //Inicializacion delconvertidor ADC
	Glcd_Write_Text(" ADC(10bits) R(Ohms) ", 0, 0, 0);
	Glcd_Write_Text(" ADC(12bits) R(Ohms) ", 0, 4, 0);
	Glcd_V_Line(0, 63, 73, 1);
	while(1)
	{
		for(i=0;i<2;i++){
			adc_value = ADC1_Get_Sample(canal[i]);
			WordToStr(adc_value, txt);
			Glcd_Write_Text(txt, 0, i+1, 1);
			adc_value=adc_value*4.96578;
			WordToStr(adc_value, txt);
			Glcd_Write_Text(txt, 80, i+1, 1);
	}
	Delay_ms(250);
	
	AD1CON1bits.AD12B=1; //cambiando a modalidad 12bits
	for(i=2;i<4;i++){
		adc_value = ADC1_Get_Sample(canal[i]);
		WordToStr(adc_value, txt);
		Glcd_Write_Text(txt, 0, i+3, 1);
		adc_value=adc_value*1.24053;
		WordToStr(adc_value, txt);
		Glcd_Write_Text(txt, 80, i+3, 1);
	}
	AD1CON1bits.AD12B=0; // cambiando a modalidad 10bits
	Delay_ms(250);
	}
}