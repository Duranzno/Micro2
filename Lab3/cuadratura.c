valor inicial=5000;
valor_ini_h=0x0000;
valor_ini_l=0x84B;

void config_pin () {
	TRISDbits.TRISD10=1;  // entrada INDEX
	TRISDbits.TRISD9=1; // entrada fase A
	TRISDbits.TRISD8=1;  // entrada fase B
	RPINR15bits.INDX1R=74;  // pin para INDEX
	RPINR14bits.QEA1R=73;  // fase A
 	RPINR14bits.QEB1R=72; // fase B
}
void int_captura () ORG 0x88 {
	if(QEI1STATbits.PCHEQIRQ==1)
		inter_mayor();
	if(QEI1STATbits.PCLEQIRQ==1)
	    inter_menor()// animacion de menor a 4500 cm

}

void inter_mayor (){
	//animacion de mayor a 5500 cm
}
void inter_menor (){
	//animacion de menor a 4500cm
}

void config_cuadratura () {
IEC3bits.QEI1IE=1; //habilita interrupciÃ³n de Cuadratura
IFS3bits.QEI1IF=0; //limpia la bandera de interrupcion
QEI1CONbits.PIMOD=2; // el contador se inicializa con el valor del registro QEI1IC
QEI1ICH=valor_ini_h;
QEI1ICL=valor_ini_h;
QEI1STATbits.PCHEQIEN=1; //interrupcion por comparacion de cuadratura
QEI1STATbits.PCLEQIEN=1; // interrupcion por comparacion de cuadratura	
QEI1STATbits.IDXIEN=1; //interrupcion por INDEX pin
}