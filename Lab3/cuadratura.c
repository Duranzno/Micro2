valor_inicial=5000;
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
QEI1CONbits.QEIEN=1; //habilita el módulo de cuadratura
QEI1IOCbits.FLTREN=1; //Activa filtro digital
}

float valor_actual,valor_anterior,recorrido;


void caso2 () {
	config_cuadratura();
	//debido a que POSCNT cuenta con dos registros de 16bits,
//los unimos en una variable para calcular la distancia
valor_actual=POS1CNTL;
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
valor_actual=(valor_actual>>16)+POS1HLD;
recorrido=valor_actual;
recorrido=recorrido*2.35619; //se divide el poscnt entre 4
//luego se multiplica por (2.pi.r)/4
Floattostr(recorrido,txt);
Glcd_Write_Text(txt, 1, 6, 1);
if(valor_anterior<valor_actual) Glcd_Write_Text("derecha ", 1, 2, 1);
else if(valor_anterior>valor_actual) Glcd_Write_Text("izquierda", 1, 2, 1);
valor_anterior=valor_actual;
}