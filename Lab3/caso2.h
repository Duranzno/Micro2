2.2 Visualizar la distancia recorrida, numero de vueltas y sentido del QAD.
//         *La primera medida será a partir de los 5000 cm después de activar un pulsador al pin INDEX. 
//Trabaje con los modos de inicialización de POSCNT del QEI
//         *Si la distancia sobrepasa el 10% por encima o por debajo de su valor inicial debe visualizar una animación referida a esta situación por 5 segundos, utilice el modo comparación del QEI
long valor_anterior,valor_actual;
float recorrido;
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
	Glcd_Write_Text("Limite superior ", 0, 4, 0);
}
void inter_menor (){
	Glcd_Write_Text(" Limite inferior ", 0, 4, 0);
}
void config_cuadratura () {
IEC3bits.QEI1IE=1; //habilita interrupcion de Cuadratura
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

void caso2 () {
  char texto[12];
  valor_anterior=0;
  Glcd_Write_Text(" Sentido: ", 0, 0, 0);
  Glcd_Write_Text(" Distancia(cmts.): ", 0, 4, 0);
	config_cuadratura();
	//debido a que POSCNT cuenta con dos registros de 16bits,
//los unimos en una variable para calcular la distancia
valor_actual=POS1CNTL;
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
valor_actual=(valor_actual>>16)+POS1HLD;
recorrido=valor_actual;
recorrido=recorrido*2.35619; //se divide el poscnt entre 4
//luego se multiplica por (2.pi.r)/4
Floattostr(recorrido,texto);
Glcd_Write_Text(texto, 1, 7, 1);
if(valor_anterior<valor_actual) Glcd_Write_Text("derecha ", 1, 2, 1);
else if(valor_anterior>valor_actual) Glcd_Write_Text("izquierda", 1, 2, 1);
valor_anterior=valor_actual;
}