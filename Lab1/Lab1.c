#include"sprites.c"
typedef int boolean;
#define true 1
#define false 0
const int BAR_HEIGHT=5;
const int BAR_WIDTH=5;
const int WHITE=0;
const int BLACK=1;
const int MAX_BAR_HEIGHT=BAR_HEIGHT*25;
//Las barras se usan calculando la posicion X mas a la izquierda, todos tienen un alto y un ancho definidos
void main() {
	int x_bars_locations[5]={0,1,2,3,4}
    typedef enum {Int0,Int1,Int2,Int3,Int4} Bars;
    Bars bars;
    //get number of bars
     if (number_of_bars%25==0)
     {
     	Glcd_Box()
     }
     switch(bars){
     	case Int0:
     	//Int0 tiene una posicion especifica constante asignada aqui, se toma 0 como ejemplo
     	// void Glcd_Box(unsigned short x_upper_left, unsigned short y_upper_left, unsigned short x_bottom_right, unsigned short y_bottom_right, unsigned short color);
	     	bar_drawer(x_bars_locations[Int0],number_of_bars)
    		break;
     	default:
     	break;
     }
}
void bar_drawer(unsigned short x_left,unsigned short number_of_bars){
	int y_bottom=number_of_bars*BAR_HEIGHT;
	int y_top=y_bottom+BAR_HEIGHT;
	int x_right=x_left+BAR_WIDTH;
	if (number_of_bars%25==0){
 		Glcd_Box(x_left,MAX_BAR_HEIGHT,x_right,0,WHITE)
	}
	else {
		Glcd_Box(x_left,y_top,x_right,y_bottom,BLACK);
	}
}
int check_if()