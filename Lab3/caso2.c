// 2.2 Visualizar la distancia recorrida, numero de vueltas y sentido del QAD.
//         *La primera medida será a partir de los 5000 cm después de activar un pulsador al pin INDEX. 
//Trabaje con los modos de inicialización de POSCNT del QEI
//         *Si la distancia sobrepasa el 10% por encima o por debajo de su valor inicial debe visualizar una animación referida a esta situación por 5 segundos, utilice el modo comparación del QEI
long valor_anterior,valor_actual;
float recorrido;

void caso_2(){
  char texto[12];
  valor_anterior=0;
  Glcd_Write_Text(" Sentido: ", 0, 0, 0);
  Glcd_Write_Text(" Distancia(cmts.): ", 0, 4, 0);
  //debido a que POSCNT cuenta con dos registros de 16bits,
  //los unimos en una variable para calcular la distancia
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
  //delay_ms(250);
}