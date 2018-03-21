const int BAR_HEIGHT=2;
const int BAR_WIDTH=20;
const int WHITE=0;
const int BLACK=1;

const int MAX_BAR_HEIGHT=BAR_HEIGHT*25;
unsigned short BARS_H_LOCATIONS[5]={4,29,54,79,104};
char txt[5];
unsigned short x_left,x_right,y_top,y_bottom,count,contador_reset,Ix;
int quotient;
void bar_drawer(unsigned short x_left,unsigned short contador_barra);
int DrawableBars(int real_number_of_bars);
           void box(int x_left,int count);
void barra(int INTx,int contador_barra) {
//     void Glcd_Box(unsigned short x_upper_left, unsigned short y_upper_left, unsigned short x_bottom_right, unsigned short y_bottom_right, unsigned short color);
    box(BARS_H_LOCATIONS[INTx],contador_barra);
    ShortToStr(contador_barra,txt);
//    txt=Ltrim(txt);
    Glcd_Write_Text(txt,BARS_H_LOCATIONS[INTx],0,1);
}
void box(int x_left,int count){
   y_top=64-DrawableBars(count)*2;
        y_bottom=y_top+2;

   x_right=x_left+20;
    contador_reset=DrawableBars(count);
  if(count>1){
    if (contador_reset==1){

         Glcd_Box(x_left,7,x_right,64,0);
       //      Glcd_Box(x_left,64,x_right,62, 1);
    }  else {
         Glcd_Box(x_left,y_top,x_right,y_bottom, 1);}
    }else {
         Glcd_Box(x_left,y_top,x_right,y_bottom, 1);
  }
}
 int DrawableBars(int real_number_of_bars){
   //Funcion para devolver el numero necesario de barras a formar si el contador>25 dentro de un rango de [0-25].
   //Ejemplo 80-->5
   if(real_number_of_bars>25){
      quotient=real_number_of_bars/25;
      quotient=floor(quotient);
     return real_number_of_bars-25*quotient;
   }else{
     return real_number_of_bars;
   }
 }