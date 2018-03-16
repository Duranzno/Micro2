#include <math.h>

const int BAR_HEIGHT=4;
const int BAR_WIDTH=5;
const int WHITE=0;
const int BLACK=1;

const int MAX_BAR_HEIGHT=BAR_HEIGHT*25;
const int BARS_H_LOCATIONS[]={0,1,2,3,4};
typedef enum {Int0,Int1,Int2,Int3,Int4}Bars;
void bar_drawer(unsigned short x_left,unsigned short contador_barra);
int DrawableBars(int real_number_of_bars);
//Las barras se usan calculando la posicion X mas a la izquierda, todos tienen un alto y un ancho definidos
void barras(Bars interrupcion,int contador_barra) {
  switch(interrupcion){
    case Int0:
    //Int0 tiene una posicion especifica constante asignada aqui, se toma 0 como ejemplo
    // void Glcd_Box(unsigned short x_upper_left, unsigned short y_upper_left, unsigned short x_bottom_right, unsigned short y_bottom_right, unsigned short color);
    bar_drawer(BARS_H_LOCATIONS[Int0],contador_barra);
    break;
    case Int1:
    bar_drawer(BARS_H_LOCATIONS[Int1],contador_barra);
    break;
    case Int2:
    bar_drawer(BARS_H_LOCATIONS[Int2],contador_barra) ;
    break;
    case Int3:
    bar_drawer(BARS_H_LOCATIONS[Int3],contador_barra);
    break;
    case Int4:
    bar_drawer(BARS_H_LOCATIONS[Int4],contador_barra);
    break;
    default:
    break;
    }
}
void bar_drawer(unsigned short x_left,unsigned short contador_barra){
//        contador_barra=contador_barra==0?1:contador_barra;//Contador de barras nunca puede ser cero al momento de usar esta funcion
//se debe de haber aumentado antes
  int x_right=x_left+BAR_WIDTH;
  int y_bottom,y_top;
  int contador_reset=DrawableBars(contador_barra);
  if(contador_barra>1){
    if (contador_reset==1){
    //Se van a borrar todas las barras
         Glcd_Box(x_left,MAX_BAR_HEIGHT,x_right,BAR_HEIGHT,WHITE);
    }
    else{
    //Se va a dibujar una sola barra dentro de la escala
      y_bottom=DrawableBars(contador_barra)*BAR_HEIGHT;
      y_top=y_bottom+BAR_HEIGHT;
      Glcd_Box(x_left,y_top,x_right,y_bottom,BLACK);
    }
  }
}
int DrawableBars(int real_number_of_bars){
  //Funcion para devolver el numero necesario de barras a formar si el contador>25 dentro de un rango de [0-25].
  //Ejemplo 80-->5
  if(real_number_of_bars>25){
    int quotient=real_number_of_bars/25;
    quotient=floor(quotient);
    return real_number_of_bars-25*quotient;
  }else{
    return real_number_of_bars;
  }
}