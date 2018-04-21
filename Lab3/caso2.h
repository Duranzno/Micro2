//2.2 Visualizar la distancia recorrida, numero de vueltas y sentido del QAD.
//         *La primera medida será a partir de los 5000 cm después de activar un pulsador al pin INDEX. 
//Trabaje con los modos de inicialización de POSCNT del QEI
//         *Si la distancia sobrepasa el 10% por encima o por debajo de su valor inicial debe visualizar una animación referida a esta situación por 5 segundos, utilice el modo comparación del QEI
#define valor_inicial 5000;
#define valor_ini_h 0x0000;
#define valor_ini_l 2123;
long valor_anterior,valor_actual,valor_sup;
float recorrido;

void config_cuadratura () {
  QEI1IOCbits.INDEX=1;
  QEI1LECL=1910;
  QEI1LECH=0;
  QEI1GECL=2335; // registro bajo del comparacion mayor
  QEI1GECH=0;
  IEC3bits.QEI1IE=1; //habilita interrupcion de Cuadratura
  IFS3bits.QEI1IF=0; //limpia la bandera de interrupcion
  QEI1CONbits.PIMOD=1; // el contador se inicializa con el valor del registro QEI1IC
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
void QEI(){
char texto[15];
  glcd_fill(0);
   glcd_write_text("INT2",62,5,1);
              if(QEI1statbits.IDXIEN==1)
           {POS1CNTH=0;
             POS1CNTL=2122;
             valor_sup= QEI1ICH;
  valor_sup=(valor_sup<<16)+ QEI1ICL;
   Floattostr(valor_sup,texto);
  Glcd_Write_Text(texto, 60, 7, 1);
  delay_ms(500);

             glcd_write_text("INDEEX",0,0,1);
  }
        if(QEI1STATbits.PCHEQIRQ==1)
       {
        //         inter_mayor(); // animacion de mayor a 5000cm
       }
        if(QEI1STATbits.PCLEQIRQ==1)
           {
          //  inter_menor();// animacion de menor a 4500 cm
           }
}
void caso2 () {

  char texto[12];
  glcd_fill(0);  ;
  valor_anterior=0;
  Glcd_Write_Text(" Sentido: ", 0, 0, 0);
  Glcd_Write_Text(" Distancia(cmts.): ", 0, 4, 0);
  config_cuadratura();
  
  inttostr(QEI1CONbits.PIMOD,texto);glcd_write_text(txt,0,0,1) ;delay_ms(500); glcd_write_text("         ",0,0,1);
    if(QEI1CONbits.PIMOD==0){glcd_write_text(strcat("0","pimod"),2,0,1) ;delay_ms(500); glcd_write_text("         ",0,0,1);}
    else if(QEI1CONbits.PIMOD==2){glcd_write_text(strcat("2","pimod"),2,0,1) ;delay_ms(500); glcd_write_text("         ",0,0,1);}
  //debido a que POSCNT cuenta con dos registros de 16bits,
  //los unimos en una variable para calcular la distancia
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    while (1) {
  valor_actual=POS1CNTH;
  valor_actual=(valor_actual<<16)+POS1CNTL;
  recorrido=valor_actual;
  recorrido=recorrido*2.35619; //se divide el poscnt entre 4
  //luego se multiplica por (2.pi.r)/4
  Floattostr(recorrido,texto);
  Glcd_Write_Text(texto, 1, 7, 1);
  if(valor_anterior<valor_actual) Glcd_Write_Text("derecha ", 1, 2, 1);
  else if(valor_anterior>valor_actual) Glcd_Write_Text("izquierda", 1, 2, 1);
  valor_anterior=valor_actual;
     }
}