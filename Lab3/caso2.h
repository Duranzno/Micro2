//2.2 Visualizar la distancia recorrida, numero de vueltas y sentido del QAD.
//         *La primera medida será a partir de los 5000 cm después de activar un pulsador al pin INDEX. 
//Trabaje con los modos de inicialización de POSCNT del QEI
//         *Si la distancia sobrepasa el 10% por encima o por debajo de su valor inicial debe visualizar una animación referida a esta situación por 5 segundos, utilice el modo comparación del QEI
#define valor_inicial 5000;
#define valor_ini_h 0x0000;
#define valor_ini_l 2123;
long valor_anterior,valor_actual,valor_sup;
float recorrido;
int cont=0,cont2=0,vueltas=0;
void config_cuadratura () {
  QEI1IOCbits.INDEX=1;
  QEI1LECL=1910;
  QEI1LECH=0;
  QEI1GECL=2335; // registro bajo del comparacion mayor
  QEI1GECH=0;
  IEC3bits.QEI1IE=1; //habilita interrupcion de Cuadratura
  IFS3bits.QEI1IF=0; //limpia la bandera de interrupcion
  QEI1CONbits.PIMOD=3; // el contador se inicializa con el valor del registro QEI1IC
  QEI1CONbits.IMV=3;
  //QEI1ICH=valor_ini_h;
  // QEI1ICL=valor_ini_l;
  QEI1STATbits.PCHEQIEN =1; //interrupcion por comparacion de cuadratura
  QEI1STATbits.PCLEQIEN=1; // interrupcion por comparacion de cuadratura
  QEI1STATbits.IDXIEN=1; //interrupcion por INDEX pin
  QEI1CONbits.QEIEN=1; //habilita el módulo de cuadratura
  QEI1IOCbits.FLTREN=1; //Activa filtro digital
}
/*void inter_mayor (){
        Glcd_Write_Text("Limite superior ", 0, 4, 1);
}
void inter_menor (){
        Glcd_Write_Text(" Limite inferior ", 0, 4, 1);
}*/
void config_timer2 () {
 TMR2=0;
T2CON=0X0030; //Prescaler 256:1, modo timer
PR2=39063; //1000ms
IEC0bits.T2IE=1;
IFS0bits.T2IF=0;
}

void caso2 () {
  char texto[12];
  glcd_fill(0);  ;
  valor_anterior=0;
  cont=0;
     cont2=0;
   vueltas=0;
  Glcd_Write_Text(" Sentido:", 0, 0, 0);
  Glcd_Write_Text(" Distancia(cmts.): ", 0, 4, 0);
    Glcd_Write_Text(" Vueltas ", 0, 7, 0);
  config_cuadratura();
  config_timer2();
  //debido a que POSCNT cuenta con dos registros de 16bits,
  //los unimos en una variable para calcular la distancia
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    while (1) {
  valor_actual=POS1CNTH;
  valor_actual=(valor_actual<<16)+POS1CNTL;
  recorrido=valor_actual;
  recorrido=recorrido*2.35619; //se divide el poscnt entre 4
  //luego se multiplica por (2.pi.r)/4
   if(valor_actual ==2122 )  {
   recorrido=5000; }
  Floattostr(recorrido,texto);
  Glcd_Write_Text(texto, 1, 5, 1);
  if(valor_anterior<valor_actual) 
  { 
  Glcd_Write_Text("derecha    ", 1, 2, 1);
  cont=cont+1;
  }
  else if(valor_anterior>valor_actual)
  {
   Glcd_Write_Text("izquierda", 1, 2, 1);
    cont2=cont2+1;
  }
    if(cont ==8 )
    {vueltas++;
    cont=0; }
    if(cont2 ==8 )
    {vueltas=vueltas-1;
    cont2=0; }
     Inttostr(vueltas,texto);
  Glcd_Write_Text(texto, 60, 7, 1);
   valor_anterior=valor_actual;
     }
}