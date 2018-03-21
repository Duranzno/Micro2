#line 1 "C:/Users/Alejandro/Documents/Git/M2/Lab1.c"
#line 1 "c:/users/alejandro/documents/git/m2/barras.h"
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

 box(BARS_H_LOCATIONS[INTx],contador_barra);
 ShortToStr(contador_barra,txt);

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

 } else {
 Glcd_Box(x_left,y_top,x_right,y_bottom, 1);}
 }else {
 Glcd_Box(x_left,y_top,x_right,y_bottom, 1);
 }
}
void funcionPractica(){
 Glcd_Fill(0);
 delay_ms(5000);





 for(count=1;count<61;count=count++){
 for(Ix=0;Ix<5;Ix++){
 x_left=BARS_H_LOCATIONS[Ix];
#line 61 "c:/users/alejandro/documents/git/m2/barras.h"
box(x_left,count);

delay_ms(500) ;


 }
 }
}


 int DrawableBars(int real_number_of_bars){


 if(real_number_of_bars>25){
 quotient=real_number_of_bars/25;
 quotient=floor(quotient);
 return real_number_of_bars-25*quotient;
 }else{
 return real_number_of_bars;
 }
 }
#line 1 "c:/users/alejandro/documents/git/m2/sprites.h"
 const code char charmander_1[1024] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 32, 16, 0, 8, 8, 8, 8, 0, 16, 16, 160, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 64, 64, 64, 64, 64, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 223, 62, 56, 16, 0, 0, 0, 16, 28, 174, 127, 252, 252, 255, 255, 240, 128, 0, 0, 0, 0, 0, 0, 0, 0, 8, 112, 224, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 120, 134, 1, 0, 0, 0, 0, 0, 28, 36, 124, 120, 49, 6, 24, 96, 128, 0, 240, 56, 212, 8, 20, 24, 240, 0, 0, 128, 0, 192, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 4, 8, 8, 136, 200, 60, 26, 29, 142, 79, 55, 27, 3, 7, 143, 254, 248, 112, 64, 128, 0, 0, 0, 0, 0, 131, 255, 255, 252, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 152, 8, 104, 73, 15, 48, 64, 192, 128, 128, 80, 64, 32, 152, 151, 72, 48, 12, 1, 6, 1, 0, 0, 192, 112, 14, 1, 0, 1, 10, 21, 11, 151, 111, 158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 50, 41, 33, 16, 31, 96, 128, 14, 25, 20, 24, 8, 4, 62, 135, 1, 0, 0, 0, 0, 131, 252, 252, 254, 127, 63, 31, 15, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 7, 135, 247, 15, 1, 1, 1, 0, 0, 0, 0, 0, 128, 64, 0, 0, 1, 3, 28, 112, 144, 16, 136, 136, 196, 226, 249, 62, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 64, 32, 32, 17, 10, 140, 156, 248, 248, 232, 8, 5, 6, 124, 132, 6, 143, 29, 56, 240, 224, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 78, 81, 32, 32, 67, 204, 248, 240, 240, 96, 32, 32, 62, 57, 112, 224, 224, 64, 64, 64, 96, 95, 135, 7, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 2, 2, 3, 2, 3, 1, 1, 0, 0, 0, 0, 0, 1, 2, 2, 3, 2, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};







const code char charmander_2[1024] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 64, 32, 32, 16, 16, 16, 8, 4, 52, 122, 222, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 64, 224, 56, 7, 0, 0, 63, 112, 224, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 68, 12, 152, 56, 248, 112, 224, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 64, 124, 27, 0, 0, 0, 16, 32, 56, 252, 246, 226, 254, 255, 255, 254, 192, 192, 192, 192, 192, 192, 192, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60, 211, 128, 128, 0, 0, 48, 64, 192, 168, 248, 140, 255, 255, 254, 248, 192, 128, 128, 192, 64, 32, 32, 16, 16, 16, 136, 136, 136, 136, 136, 150, 116, 88, 183, 94, 191, 125, 58, 5, 63, 248, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 254, 248, 128, 0, 0, 0, 0, 7, 10, 16, 16, 244, 240, 240, 248, 248, 254, 255, 223, 143, 135, 131, 195, 227, 231, 223, 143, 79, 61, 248, 48, 49, 97, 193, 195, 227, 98, 254, 60, 28, 248, 176, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 17, 40, 224, 224, 232, 224, 248, 247, 255, 255, 127, 127, 127, 127, 127, 63, 31, 15, 255, 127, 119, 39, 39, 39, 67, 195, 131, 3, 1, 59, 127, 125, 240, 224, 240, 248, 244, 224, 30, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 103, 131, 31, 60, 120, 240, 240, 224, 224, 192, 192, 193, 103, 63, 31, 56, 16, 48, 33, 33, 33, 33, 33, 49, 147, 255, 255, 122, 121, 125, 126, 248, 240, 224, 128, 1, 2, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 96, 16, 136, 136, 132, 134, 207, 255, 63, 31, 31, 29, 24, 96, 128, 0, 0, 0, 8, 20, 39, 90, 138, 5, 1, 3, 3, 15, 31, 63, 255, 254, 248, 240, 248, 232, 132, 3, 192, 48, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 4, 8, 16, 51, 63, 127, 127, 255, 240, 192, 192, 192, 240, 248, 253, 254, 254, 254, 254, 254, 127, 115, 65, 128, 128, 128, 128, 128, 192, 224, 243, 255, 254, 248, 224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 38, 47, 18, 23, 28, 8, 7, 3, 1, 0, 0, 0, 0, 0, 0, 14, 49, 65, 66, 196, 228, 252, 248, 248, 240, 241, 227, 228, 228, 40, 44, 30, 23, 19, 11, 9, 5, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 10, 15, 23, 23, 23, 15, 23, 23, 31, 7, 3, 0, 0, 0, 0, 0, 8, 21, 23, 31, 47, 47, 47, 31, 47, 39, 23, 15, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 13, 20, 12, 17, 15, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const code char blooper_1[175] = {
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 63, 63, 63, 63, 127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 239, 231, 227, 1, 128, 128, 128, 128, 128, 128, 128, 128, 1, 227, 231, 239, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 7, 9, 198, 6, 9, 143, 143, 9, 6, 198, 9, 7, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 252, 224, 255, 240, 192, 255, 255, 192, 240, 255, 224, 252, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
};

const code char blooper_2[175] = {
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 63, 31, 15, 7, 3, 3, 3, 3, 7, 15, 31, 63, 127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 142, 6, 6, 0, 196, 4, 4, 204, 204, 4, 4, 196, 0, 6, 6, 142, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 252, 252, 255, 252, 255, 255, 252, 255, 252, 252, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
};

const code char blooper_3[175] = {
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 127, 63, 31, 15, 15, 15, 15, 31, 63, 127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 251, 249, 248, 64, 160, 160, 96, 224, 224, 96, 160, 160, 64, 248, 249, 251, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 1, 2, 241, 1, 2, 227, 227, 2, 1, 241, 2, 1, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 248, 255, 252, 240, 255, 255, 240, 252, 255, 248, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
};

const code char blooper_4[175] = {
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 191, 159, 143, 7, 3, 1, 0, 0, 0, 0, 1, 3, 7, 143, 159, 191, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 227, 193, 129, 0, 49, 193, 1, 243, 243, 1, 193, 49, 0, 129, 193, 227, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3
};






const code char bullet[54] = {
 0, 0, 128, 64, 32, 240, 240, 216, 232, 232, 232, 232, 232, 248, 0, 232, 232, 0,
 0, 15, 30, 61, 126, 255, 243, 227, 225, 227, 240, 248, 249, 255, 0, 255, 255, 0,
 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0
};







const code char shell_1[32] = {
0, 176, 184, 60, 126, 254, 254, 255, 255, 231, 198, 206, 252, 248, 192, 0,
14, 31, 29, 15, 0, 15, 31, 63, 63, 31, 31, 15, 15, 15, 15, 0
};

const code char shell_2[32] = {
0, 128, 240, 248, 252, 252, 238, 198, 198, 238, 252, 252, 248, 240, 128, 0,
0, 31, 31, 31, 31, 63, 63, 127, 127, 63, 63, 31, 31, 31, 31, 0
};

const code char shell_3[32] = {
0, 192, 248, 252, 206, 198, 231, 255, 255, 254, 254, 126, 60, 184, 176, 0,
0, 15, 15, 15, 15, 31, 31, 63, 63, 31, 15, 0, 15, 29, 31, 14
};





const code char dog_1[155] = {
224, 248, 252, 254, 254, 31, 7, 7, 254, 254, 14, 7, 103, 254, 254, 103, 7, 14, 254, 254, 7, 7, 31, 62, 60, 124, 124, 62, 30, 0, 0,
 1, 7, 15, 15, 0, 0, 0, 136, 1, 65, 11, 34, 135, 203, 203, 135, 34, 11, 65, 1, 136, 0, 128, 192, 192, 224, 240, 240, 248, 252, 0,
 0, 128, 192, 224, 240, 248, 252, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 63, 31, 15, 7, 3, 129, 240, 0,
254, 255, 255, 255, 111, 3, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 8, 6, 3, 1, 0,
 1, 3, 3, 3, 0, 0, 7, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0
};





const code char dog_2[155] = {
224, 248, 252, 254, 254, 31, 7, 7, 254, 254, 14, 39, 71, 254, 254, 71, 39, 14, 254, 254, 7, 7, 31, 62, 60, 124, 124, 62, 30, 0, 0,
 1, 7, 15, 143, 192, 192, 64, 136, 1, 65, 11, 34, 135, 75, 75, 135, 34, 11, 65, 1, 136, 64, 192, 192, 128, 0, 0, 0, 0, 0, 0,
 0, 252, 255, 255, 255, 255, 252, 254, 245, 225, 229, 207, 196, 192, 192, 228, 255, 253, 253, 253, 254, 252, 255, 255, 255, 255, 252, 224, 0, 0, 0,
 0, 0, 7, 15, 31, 31, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 31, 63, 63, 63, 31, 7, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 7, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0
};





const code char dog_3[155] = {
 0, 224, 248, 252, 254, 254, 31, 14, 30, 252, 248, 56, 156, 28, 248, 248, 28, 156, 56, 248, 252, 30, 14, 31, 62, 60, 124, 124, 62, 30, 0,
 0, 1, 7, 15, 143, 192, 192, 0, 32, 7, 7, 44, 136, 29, 47, 47, 29, 136, 44, 7, 7, 32, 0, 192, 192, 128, 0, 0, 0, 0, 0,
 0, 0, 252, 255, 255, 255, 255, 249, 250, 228, 229, 196, 220, 194, 193, 193, 250, 252, 252, 253, 252, 254, 249, 255, 255, 255, 255, 252, 224, 0, 0,
 0, 0, 0, 7, 15, 31, 31, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 31, 63, 63, 63, 31, 7, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 7, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 7, 0, 0, 0, 0, 0, 0, 0, 0
};





const code char kirby_1[63] = {
128, 64, 96, 32, 56, 12, 6, 2, 3, 1, 41, 241, 1, 43, 242, 6, 12, 48, 32, 96, 192,
 3, 4, 8, 8, 24, 240, 224, 192, 192, 192, 192, 224, 152, 132, 194, 226, 226, 124, 60, 4, 3,
 0, 0, 0, 0, 0, 1, 3, 7, 7, 7, 7, 3, 1, 1, 1, 1, 0, 0, 0, 0, 0
};





const code char kirby_2[63] = {
 0, 0, 0, 128, 224, 56, 12, 4, 6, 2, 2, 210, 226, 2, 22, 228, 12, 56, 224, 128, 0,
 0, 30, 63, 33, 224, 224, 192, 128, 128, 0, 0, 0, 129, 64, 68, 65, 192, 224, 161, 49, 30,
 0, 0, 0, 0, 3, 7, 7, 6, 7, 3, 3, 7, 6, 6, 6, 6, 6, 7, 3, 0, 0
};





const code char kirby_3[63] = {
 0, 128, 224, 48, 24, 8, 12, 4, 4, 4, 4, 84, 228, 4, 84, 232, 8, 48, 224, 128, 0,
 0, 31, 48, 104, 208, 160, 160, 224, 48, 32, 32, 32, 33, 64, 196, 193, 192, 96, 56, 31, 0,
 0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0
};
#line 169 "c:/users/alejandro/documents/git/m2/sprites.h"
const code char kirby_4[63] = {
 0, 0, 192, 240, 24, 12, 4, 6, 2, 2, 2, 82, 226, 6, 84, 236, 24, 112, 192, 0, 0,
 0, 0, 15, 248, 224, 160, 32, 48, 48, 48, 68, 192, 193, 128, 196, 129, 224, 56, 31, 0, 0,
 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 0, 0, 0, 0, 0
};





const code char kirby_5[63] = {
 0, 0, 0, 224, 56, 12, 4, 6, 2, 2, 2, 2, 2, 22, 230, 20, 236, 120, 224, 0, 0,
 0, 0, 192, 255, 48, 32, 32, 64, 192, 128, 128, 144, 128, 132, 129, 196, 193, 176, 239, 0, 0,
 0, 0, 1, 3, 3, 7, 7, 7, 7, 7, 3, 3, 3, 3, 3, 3, 1, 1, 0, 0, 0
};





const code char kirby_6[63] = {
 0, 0, 240, 60, 14, 6, 3, 1, 1, 1, 1, 1, 129, 11, 54, 230, 28, 240, 0, 0, 0,
240, 184, 15, 56, 96, 192, 192, 192, 128, 128, 132, 128, 193, 192, 192, 224, 242, 255, 226, 126, 60,
 1, 3, 7, 6, 7, 7, 7, 3, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0
};
void animate_charmander_5s(){
 Glcd_Image(charmander_1);
 delay_ms(2500);

 Glcd_Image(charmander_2);
 delay_ms(2500);
}
void animate_charmander_20s(){
 animate_charmander_5s();
 animate_charmander_5s();
 animate_charmander_5s();
 animate_charmander_5s();
}

void animate_bullet(unsigned int x_left){
 Glcd_PartialImage(x_left,23,18,18,18,18,bullet);
}

void animate_bullet_5s(){
 animate_bullet(109);delay_ms(1000);
 animate_bullet(91) ;delay_ms(1000);
 animate_bullet(73) ;delay_ms(1000);
 animate_bullet(55) ;delay_ms(1000);
 animate_bullet(37) ;delay_ms(1000);
 animate_bullet(19) ;delay_ms(1000);
 animate_bullet(1) ;delay_ms(1000);
}
void animate_shell(unsigned int x_left, unsigned int y_top,code const far char * image){
 Glcd_PartialImage(x_left,y_top,16,16,16,16,image);
}
void animate_shell_5s(unsigned int x_left, unsigned int y_top){
 Glcd_Fill(0);
 animate_shell(x_left,y_top,shell_1);
 delay_ms(1667);
 animate_shell(x_left,y_top,shell_2);
 delay_ms(1667);
 animate_shell(x_left,y_top,shell_1);
 delay_ms(1667);
}
void animate_dog(unsigned int x_left, unsigned int y_top,code const far char * image){
 Glcd_PartialImage(x_left,y_top,31,40,31,40,image);
}
void animate_dog_5s(unsigned int x_left, unsigned int y_top){
 Glcd_Fill(0);
 animate_shell(x_left,y_top,shell_1);
 delay_ms(1667);
 animate_dog(x_left,y_top,dog_2);
 delay_ms(1667);
 animate_dog(x_left,y_top,dog_2);
 delay_ms(1667);
}
void animate_dog_20s(){
 animate_dog_5s(48,12);animate_dog_5s(48,12);animate_dog_5s(48,12);animate_dog_5s(48,12);
}
void animate_kirby(unsigned int x_left, unsigned int y_top,code const far char * image){
 Glcd_PartialImage(x_left,y_top,21,19,19,21,image);
}
void animate_kirby_5s(int x_left,int y_top){
 Glcd_Fill(0);
 animate_kirby(x_left,y_top,kirby_1);delay_ms(833);
 animate_kirby(x_left,y_top,kirby_2) ;delay_ms(833);
 animate_kirby(x_left,y_top,kirby_3) ;delay_ms(833);
 animate_kirby(x_left,y_top,kirby_4) ;delay_ms(833);
 animate_kirby(x_left,y_top,kirby_5) ;delay_ms(833);
 animate_kirby(x_left,y_top,kirby_6);delay_ms(833);
}

void animate_blooper(unsigned int x_left, unsigned int y_top,code const far char * blooper){
 Glcd_PartialImage(x_left,y_top,35,34,35,34,blooper);
}
void animate_blooper_5s(int x_left,int y_top){
 Glcd_Fill(1);
 animate_blooper(x_left,y_top,blooper_1);
 delay_ms(2500);
 animate_blooper(x_left,y_top,blooper_2);
 delay_ms(2500);
}
void animate_blooper_20s(){
 animate_blooper_5s(46,15);
 animate_blooper_5s(46,15);
 animate_blooper_5s(46,15);
 animate_blooper_5s(46,15);
}
#line 5 "C:/Users/Alejandro/Documents/Git/M2/Lab1.c"
sbit PS2_Data at RF4_bit;
sbit PS2_Clock at RF5_bit;
sbit PS2_Data_Direction at TRISF4_bit;
sbit PS2_Clock_Direction at TRISF5_bit;

sbit GLCD_D7 at RE1_bit;
sbit GLCD_D6 at RE0_bit;
sbit GLCD_D5 at RF1_bit;
sbit GLCD_D4 at RF0_bit;
sbit GLCD_D3 at RD7_bit;
sbit GLCD_D2 at RD6_bit;
sbit GLCD_D1 at RD5_bit;
sbit GLCD_D0 at RD4_bit;
sbit GLCD_D7_Direction at TRISE1_bit;
sbit GLCD_D6_Direction at TRISE0_bit;
sbit GLCD_D5_Direction at TRISF1_bit;
sbit GLCD_D4_Direction at TRISF0_bit;
sbit GLCD_D3_Direction at TRISD7_bit;
sbit GLCD_D2_Direction at TRISD6_bit;
sbit GLCD_D1_Direction at TRISD5_bit;
sbit GLCD_D0_Direction at TRISD4_bit;
sbit GLCD_CS1 at LATE3_bit;
sbit GLCD_CS2 at LATE2_bit;
sbit GLCD_RS at LATD1_bit;
sbit GLCD_RW at LATD2_bit;
sbit GLCD_EN at LATD3_bit;
sbit GLCD_RST at LATE4_bit;
sbit GLCD_CS1_Direction at TRISE3_bit;
sbit GLCD_CS2_Direction at TRISE2_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISE4_bit;




const int BTN_PPS_LOCATIONS[5]={-1,37,36,35,34};

const int DIP_PPS_LOCATIONS[5]={32,33,38,39,40};
const int KEYBOARD_PPS_LOCATIONS[2]={100,101};



int counters[5]={0,0,0,0,0};
int valores_cn[4]={0,0,0,0};
unsigned short keydata = 0, special = 0, down = 0,casoQactivo=0;






void InterrAdapter(int Ix);
#line 73 "C:/Users/Alejandro/Documents/Git/M2/Lab1.c"
void bar_drawer(unsigned short x_left,unsigned short contador_barra);
int DrawableBars(int real_number_of_bars);
#line 108 "C:/Users/Alejandro/Documents/Git/M2/Lab1.c"
void INT0() org 0x14{

 InterrAdapter(0);
 delay_ms(600);
 IFS0bits.INT0IF=0;
}
void INT1() org 0x3C{

 InterrAdapter(1);
 delay_ms(600);
 IFS1bits.INT1IF=0;
}
void INT2() org 0x4E{

 InterrAdapter(2);
 delay_ms(600);
 IFS1bits.INT2IF=0;
}
void INT3() org 0x7E{

 InterrAdapter(3);
 delay_ms(600);
 IFS3bits.INT3IF=0;
}
void INT4() org 0x80{

 InterrAdapter(4);
 delay_ms(600);
 IFS3bits.INT4IF=0;
}
void INT_CN() org 0x3A{
 IFS1bits.CNIF = 0;
 if(PORTBbits.RB5 ==1){

 valores_cn[0]=1;
 valores_cn[1]=0;
 valores_cn[2]=0;
 valores_cn[3]=0;

 }else if(PORTBbits.RB4==1){

 valores_cn[0]=0;
 valores_cn[1]=1;
 valores_cn[2]=0;
 valores_cn[3]=0;
 }else if(PORTBbits.RB3==1){

 valores_cn[0]=0;
 valores_cn[1]=0;
 valores_cn[2]=1;
 valores_cn[3]=0;
 }else if(PORTBbits.RB2==1){

 valores_cn[0]=0;
 valores_cn[1]=0;
 valores_cn[2]=0;
 valores_cn[3]=1;
 }
 if(PORTBbits.RB1==1){

 RCONbits.SWDTEN=1;
 Glcd_Write_TEXT("INT WDT",0,0,1);
}
 delay_ms(1000);
 Glcd_Fill(0);

}
void InterrAdapter(int Ix){
 if(casoQactivo==1){
 counters[Ix]++;
 barra(Ix,counters[Ix]);
 }
}



void config_IO(){
 ANSELB=0;
 ANSELC=0;
 ANSELD=0;
 ANSELE=0;
 ANSELG=0;
 TRISB=0xffff;
 TRISDbits.TRISD0=1;
 TRISDbits.TRISD11=1;
 TRISDbits.TRISD10=1;
 TRISDbits.TRISD9=1;
 TRISE=0;
 TRISG=0;


}
void config_LCD(){
 Glcd_Init();
 Glcd_Set_Font(font5x7 , 5, 7, 32);
 Glcd_Fill(0);
}
void config_CN(){
 CNENBbits.CNIEB5=1;
 CNENBbits.CNIEB4=1;
 CNENBbits.CNIEB3=1;
 CNENBbits.CNIEB2=1;
 CNENBbits.CNIEB1=1;

 CNPUBbits.CNPUB5=1;
 CNPUBbits.CNPUB4=1;
 CNPUBbits.CNPUB3=1;
 CNPUBbits.CNPUB2=1;
 CNPUBbits.CNPUB1=1;

 IPC4bits.CNIP=7;
 IFS1bits.CNIF=0;
 IEC1bits.CNIE=1;
}
void config_INT(){
 SRbits.IPL =0;
 INTCON1bits.NSTDIS =0;
 INTCON2bits.GIE=1;
 CORCONbits.IPL3 = 0;

 IEC0bits.INT0IE=1;
 IEC1bits.INT1IE=1;
 IEC1bits.INT2IE=1;
 IEC3bits.INT3IE=1;
 IEC3bits.INT4IE=1;


 IFS0bits.INT0IF=0;
 IFS1bits.INT2IF =0;
 IFS1bits.INT2IF =0 ;
 IFS3bits.INT3IF =0;
 IFS3bits.INT4IF =0;

 counters[0]=0;
 counters[1]=0;
 counters[2]=0;
 counters[3]=0;
 counters[4]=0;

 INTCON2bits.INT0EP=0;
 INTCON2bits.INT1EP=0;
 INTCON2bits.INT2EP=0;
 INTCON2bits.INT3EP=0;
 INTCON2bits.INT4EP =0;

 RPINR0bits.INT1R=75;
 RPINR1bits.INT2R=74;
 RPINR1bits.INT3R=73;
 RPINR2bits.INT4R=72;
}
void disable_INT(){
 IPC0bits.INT0IP= 0;
 IPC5BITS.INT1IP=0;
 IPC7bits.INT2IP =0;
 IPC13bits.INT3IP=0;
 IPC13bits.INT4IP=0;
 counters[0]=0;
 counters[1]=0;
 counters[2]=0;
 counters[3]=0;
 counters[4]=0;
 casoQactivo=0;
}


void casoExtra(){
 int Ix,count;
 Glcd_Fill(0) ;
 for(count=0;count<25;count++){
 for(Ix=0;Ix<5;Ix++){
 x_right=BARS_H_LOCATIONS[Ix]+20;
 y_bottom=count*2;
 y_top=y_bottom+2;
 Glcd_Box(BARS_H_LOCATIONS[ix],y_top,x_right,y_bottom, 1);
 delay_ms(750);
 }
 delay_ms(1000);
 }
}
void casoQ(){
 IPC0bits.INT0IP= 6;
 IPC5BITS.INT1IP=5;
 IPC7bits.INT2IP =4;
 IPC13bits.INT3IP=3;
 IPC13bits.INT4IP=2;
 Glcd_Fill(0);
 casoQactivo=1;
 do{
 down=0;special=0;keydata=0;
 Ps2_Key_Read(&keydata, &special, &down);
 }while(keydata!=34 && !down & !special);
 disable_INT();
 Glcd_Fill(0);
 disable_INT();
}
void casoW(){
 valores_cn[0]=0;
 valores_cn[1]=0;
 valores_cn[2]=0;
 valores_cn[3]=0;
 Glcd_Fill(0) ;
 Glcd_Write_TEXT("Caso 2",0,0,1);
 delay_ms(1000);
 do{
 Glcd_Fill(0);

 down=0;special=0;keydata=0;
 if(valores_cn[0]==1){

 animate_charmander_5s();
 }
 else if(valores_cn[1]==1){


 animate_kirby_5s(0,0);
 }
 else if(valores_cn[2]==1){


 animate_shell_5s(0,0);
 }
 else if(valores_cn[3]==1){



 Glcd_PartialImage(100,23,18,18,18,18,bullet); delay_ms(500);Glcd_Fill(0);
 Glcd_PartialImage(80,23,18,18,18,18,bullet); delay_ms(500);Glcd_Fill(0);
 Glcd_PartialImage(60,23,18,18,18,18,bullet); delay_ms(500);Glcd_Fill(0);
 Glcd_PartialImage(40,23,18,18,18,18,bullet); delay_ms(500);Glcd_Fill(0);
 }
 Ps2_Key_Read(&keydata, &special, &down);
 }while(keydata!=34 && !down & !special);
}

void casoE(){
 Glcd_Fill(0);
 Glcd_Write_TEXT("Caso E",60,0,1);
 do{


 down=0;
 special=0;
 if (RCONbits.WDTO==1){
 Glcd_Write_TEXT("WDT",0,1,1);
 RCONbits.WDTO=0;
 PORTEbits.RE5=1;
 animate_dog_20s();
 }else if(RCONbits.EXTR==1){
 Glcd_Write_TEXT("MCLR",0,2,1);
 RCONbits.EXTR=0;
 RCONbits.POR=0;
 PORTEbits.RE7=1;
 animate_blooper_20s();
 continue;
 }else if (RCONbits.POR==1){
 Glcd_Write_TEXT("POR",0,3,1);
 RCONbits.POR=0;
 PORTGbits.RG6=1;
 animate_charmander_20s();
 break;
 }

 Ps2_Key_Read(&keydata, &special, &down);
 }while(keydata!=34&&!down&&!special);
 LATEbits.LATE5=0;

 LATEbits.LATE7=0;
 LATGbits.LATG6=0;



}

void main(){
 config_IO();
 config_LCD();
 config_INT();
 config_CN();
 animate_charmander_5s();
 PS2_Config();
 Glcd_Fill(0);

 while(1){
 Glcd_Write_TEXT("Laboratorio 1",31,0,1);
 Glcd_Write_TEXT("'Q' para Caso Q",0,1,1);
 Glcd_Write_TEXT("'W' para Caso W",0,2,1);
 Glcd_Write_TEXT("'E' para Caso E",0,3,1);
 Glcd_Write_TEXT("'R' para WDT   ",0,4,1);
 if(Ps2_Key_Read(&keydata, &special, &down)){

 if(down &&!special){
 switch(keydata){
 case 'q':
 case 'Q':
 Glcd_Write_TEXT("Caso Q",60,0,1);
 casoQ();
 break;

 case 'w':
 case 'W':
 Glcd_Write_TEXT("Caso W",60,0,1);
 casoW();
 Glcd_Fill(0);
 break;

 case 'e':
 case 'E':
 Glcd_Fill(0);
 Glcd_Write_TEXT("Ultimo Reset",60,0,1);
 casoE();
 Glcd_Fill(0);
 break;

 case 'r':
 case 'R':
 Glcd_Fill(0);
 Glcd_Write_TEXT("Caso R ",60,0,1);

 break;
 case 't':
 case 'T':






 funcionPractica();
#line 461 "C:/Users/Alejandro/Documents/Git/M2/Lab1.c"
 break;
 case 'C':
 break;
 Glcd_Write_TEXT("CUADRO ",60,0,1);
 Glcd_Box(10,10,20,20,1);
 default:
 Glcd_Fill(0);
 Glcd_Write_TEXT("Erroneo ",60,0,1);
 delay_ms(2000);
 break;
 }
 }
 }
 }
}
