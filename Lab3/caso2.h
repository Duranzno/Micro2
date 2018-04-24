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


void caso2 () {
  char texto[12];
    GLCD_FILL(0);
  Glcd_Write_Text(" Sentido:", 0, 0, 0);
  Glcd_Write_Text(" Distancia(cmts.): ", 0, 4, 0);
  Glcd_Write_Text(" Vueltas ", 0, 7, 0);

  valor_anterior=0;
  cont=0;
  cont2=0;
  vueltas=0;
  config_cuadratura();
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