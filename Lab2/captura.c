int pulso;
float frecuencia,periodo;
void captura_onda_ic1() org 0x16
{ 
 pulso++
 IFS0bits.IC1IF=0;
}
 void int_timer1 () org 0x1A{
  T1CONbits.TON=0; // deshabilita timer1
  IFS0bits.T1IF=0; // limpia bandera de interrupcion
 }
void config_pin () {
	TRISDbits.TRISD11=1; // pin D11 como entrada
	RPINR7bits.IC1R=75; //captura por el D11

}
void config_captura (){
pulso=0;
TMR1=0;
T1CON=0X0020; // Prescaler 64:1, modo timer
PR1=31250; //1000ms
IC1CON1bits.ICTSEL=4; //usa como fuente de reloj el timer1
IC1CON1bits.ICM=5; // captura cada 4 flancos positivos 
RPINR7bits.IC1R=75; //asigna IC1 al RPI75
T1CONbits.TON=1; //enciende timer 1
IEC0bits.IC1IE=1; //habilita interrupción del IC1
IFS0bits.IC1IF=0; //limpia la bandera de interrupción
}

void frecuencia_pantalla (){
	frecuencia=pulsos*16*2;
	Glcd_Write_Text("Frecu.(hz)=", 0, 6, 1);
    floattostr(frecuencia,txt);
    Glcd_Write_Text(txt,65, 6, 1);
    periodo=(1/frecuencia)*40000000;
    floattostr(periodo,txt);
    Glcd_Write_Text(txt,65, 7, 1);

}