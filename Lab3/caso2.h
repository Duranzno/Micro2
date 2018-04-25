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


