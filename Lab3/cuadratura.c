// 2.2 Visualizar la distancia recorrida, numero de vueltas y sentido del QAD.
// 	*La primera medida será a partir de los 5000 cm después de activar un pulsador al pin INDEX.
//Trabaje con los modos de inicialización de POSCNT del QEI
// 	*Si la distancia sobrepasa el 10% por encima o por debajo de su valor inicial debe visualizar una animación referida a esta situación por 5 segundos, utilice el modo comparación del QEI
#include "config.h"
long valor_anterior,valor_actual;
char txt[12];
float recorrido;
void main()
{ //puertos de E/S digitales
ANSELD=0;
TRISDbits.TRISD9=1; // entrada fase A
TRISDbits.TRISD8=1;  // entrada fase B
ANSELB=0; valor_anterior=0;
RPINR14bits.QEA1R=73; //asignar QEA1 al pin RPI14
RPINR14bits.QEB1R=72; //asignar QEB1 al pin RPI15
QEI1CONbits.QEIEN=1; //habilita el módulo de cuadratura
QEI1IOCbits.FLTREN=1; //Activa filtro digital
config_IO();
Glcd_Init();
Glcd_Set_Font(font5x7 , 5, 7, 32);
Glcd_Fill(0);
Glcd_Write_Text(" Sentido: ", 0, 0, 0);
Glcd_Write_Text(" Distancia(cmts.): ", 0, 4, 0);
while(1)
{ //debido a que POSCNT cuenta con dos registros de 16bits,
//los unimos en una variable para calcular la distancia

valor_actual=POS1CNTH;
valor_actual=(valor_actual<<16)+POS1CNTL;
recorrido=valor_actual;
recorrido=recorrido*2.35619; //se divide el poscnt entre 4
//luego se multiplica por (2.pi.r)/4
Floattostr(recorrido,txt);
Glcd_Write_Text(txt, 1, 7, 1);
if(valor_anterior<valor_actual) Glcd_Write_Text("derecha ", 1, 2, 1);
else if(valor_anterior>valor_actual) Glcd_Write_Text("izquierda", 1, 2, 1);
valor_anterior=valor_actual;
}
}