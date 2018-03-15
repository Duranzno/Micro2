// Se desea realizar una aplicación que permita el manejo de una matriz de led’s mediante un
// dsPIC33EP256MU806, en la cual se deberán mostrar diversas letras dependiendo la opción
// seleccionada por el usuario.
// Para la implementación de esta aplicación se utilizaron algunos pines de los puertos C, D, y F
// como salidas digitales, así mismo se configuraron algunos pines del puerto F como entrada
// digital. Las salidas se conectaron a un buffer y a un decodificador y estos a su vez se
// conectaron a una matriz de diodos LED, las entradas se conectaron a un dip-switch. Para
// realizar la conexión al dip-switch se utilizaron específicamente los pines 4 y 5 del puerto F
// para así obtener 4 combinaciones, las cuales son: ‘00’, ‘01’, ‘10’ y ‘11’.
// Para iniciar esta aplicación se empezó configurando los puertos como entradas y salidas
// digitales. Una vez realizada la configuración se establecieron condiciones en la
// programación para que la visualización en la matriz de diodos LED dependiera de la
// combinación vista desde el dip-switch.
// En la matriz de LED se pueden visualizar las letras ‘A’, ‘B’, ‘C’ o ‘D’ según las combinaciones
// ‘00’, ‘01’, ‘10 y ‘11 respectivamente.
// La figura siguiente muestra la visualización de cada letra según la combinación dada por el
// dip-switch. Para efectos de visualización, se utilizaron 8 pines con el fin de controlar el
// buffer y el decodificador, para así, lograr la correcta visualización en la matriz de diodos LED.
sbit A0 at LATD5_bit;
sbit A1 at LATF1_bit;
sbit A2 at LATD1_bit;
sbit A3 at LATC13_bit;
sbit A4 at LATD9_bit;
sbit O1 at LATE4_bit;
sbit O2 at LATD3_bit;
sbit O3 at LATD10_bit;
unsigned short i;
unsigned short letra_a[5][7]={
{0,0,1,1,1,0,0},
{0,1,0,0,0,1,0},
{0,1,1,1,1,1,0},
{0,1,0,0,0,1,0},
{0,1,0,0,0,1,0}};
unsigned short letra_b[5][7]={
{0,1,1,1,1,0,0},
{0,1,0,0,0,1,0},
{0,1,1,1,1,0,0},
{0,1,0,0,0,1,0},
{0,1,1,1,1,0,0}};
unsigned short letra_c[5][7]={
{0,0,1,1,1,1,0},
{0,1,0,0,0,0,0},
{0,1,0,0,0,0,0},
{0,1,0,0,0,0,0},
{0,0,1,1,1,1,0}};
unsigned short letra_d[5][7]={
{0,1,1,1,1,0,0},
{0,1,0,0,0,1,0},
{0,1,0,0,0,1,0},
{0,1,0,0,0,1,0},
{0,1,1,1,1,0,0}};
void contador(unsigned short n)
{ O1= n & 0x01;
O2= (n & 0x02)>>1;
O3= (n & 0x04)>>2; }
void main() {
	ANSELC=0;
	ANSELD=0;
	ANSELE=0;
	TRISFbits.TRISF4=1; //s0
	TRISFbits.TRISF5=1; //s1
	TRISDbits.TRISD5=0; //a0
	TRISFbits.TRISF1=0; //a1
	TRISDbits.TRISD1=0; //a2
	TRISCbits.TRISC13=0; //a3
	TRISDbits.TRISD9=0; //a4
	TRISEbits.TRISE4=0; //o1
	TRISDbits.TRISD3=0; //o2
	TRISDbits.TRISD10=0; //o3
	while(1){
		 if(PORTFbits.RF4==0 && PORTFbits.RF5==0){ 
			for(i=0;i<7;i++){
			A0=letra_a[0][i];
			A1=letra_a[1][i];
			A2=letra_a[2][i];
			A3=letra_a[3][i];
			A4=letra_a[4][i];
			contador(i);
			Delay_ms(2);
			}
			else if(PORTFbits.RF4==0 && PORTFbits.RF5==1){
				for(i=0;i<7;i++){
				A0=letra_b[0][i];
				A1=letra_b[1][i];
				A2=letra_b[2][i];
				A3=letra_b[3][i];
				A4=letra_b[4][i];
				contador(i);
				Delay_ms(2);
				}
			}
			else if(PORTFbits.RF4==1 && PORTFbits.RF5==0){
				for(i=0;i<7;i++){
				A0=letra_c[0][i];
				A1=letra_c[1][i];
				A2=letra_c[2][i];
				A3=letra_c[3][i];
				A4=letra_c[4][i];
				contador(i);
				Delay_ms(2);
				}
			}	
			else if(PORTFbits.RF4==1 && PORTFbits.RF5==1){
				for(i=0;i<7;i++){
					A0=letra_d[0][i];
					A1=letra_d[1][i];
					A2=letra_d[2][i];
					A3=letra_d[3][i];
					A4=letra_d[4][i];
					contador(i);
					Delay_ms(2);
					}
				}
			}
	}
}