// 2.3        El diseño detmp2 tener la opción de visualizar en la interfaz gráfica el valor en voltaje de cada uno de los potenciómetros en forma dinámica. 
//         *Use al menos 3 dígitos de precisión para cada caso en la 
//interfaz gráfica o LCD y actualice cada 1 segundo. 
//Dibuje una perilla semicircular que simule el movimiento de cada
// potenciómetro con sus valores inicio y final y al menos cinco subdivisiones.
// Nota2:Utilice el modo de Latcheo Simultaneo.
#define CENTER_Y 50
#define R_BIG 30
#define R_S 2


unsigned short center_x,r,POT1=0,POT2=0;
float tmp1,tmp2;
int y,old_x1=0,old_x2=0;
char txt2[15];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CALCULOS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void autolog(char *message,float value){
        char txt2[15];
        floattostr(value,txt2);
        glcd_write_text(strcat(message,txt2),0,7,1);delay_ms(1000);glcd_write_text("                     ",0,7,1);
}
int xtoy(int x){
    if(x<=64){center_x=32;}
    else{center_x=96;}
    r=30;
     tmp1=pow(r,2);
     tmp2=pow(x-center_x,2);
     tmp1=tmp1-tmp2;
     tmp1=floor(CENTER_Y-sqrt(tmp1));
     x=tmp1;
    return x;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~GLCD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void glcd_draw_pointer(unsigned short x){
           if(x<=64){center_x=32;}
    else{center_x=96;}
        Glcd_Line(center_x,CENTER_Y,x,xtoy(x),1);
        if(x<=64){
            if(old_x1){old_x1=2;}
            Glcd_Line(center_x,CENTER_Y,old_x1,xtoy(old_x1),0);old_x1=x;

        }else {
            if(old_x2){old_x2=66;}
            Glcd_Line(center_x,CENTER_Y,old_x2,xtoy(old_x2),0); old_x2=x;
        }
}
void glcd_draw_subdiv(unsigned short startx){
        int page=7;
        glcd_circle_fill(startx,xtoy(startx)-2,R_S,1);
        glcd_write_text("0",startx,page-1,1);
        startx+=15;
        glcd_circle_fill(startx,xtoy(startx),R_S,1);
        glcd_write_text(".8",startx-7,page,1);
        startx+=15;
        glcd_circle_fill(startx,xtoy(startx),R_S,1);
        glcd_write_text("1.7",startx-5,page-1,1);
        startx+=15;
        glcd_circle_fill(startx,xtoy(startx),R_S,1);
        glcd_write_text("4.5",startx-2,page,1);
        startx+=15;
        glcd_circle_fill(startx,xtoy(startx)-2,R_S,1);
        glcd_write_text("3.4",startx-10,page-1,1);
}
void glcd_draw_semicircles(){
        glcd_circle(32,CENTER_Y,30,1);//nalga 1
          glcd_circle(96,CENTER_Y,30,1);//nalga 2
          Glcd_Rectangle_Round_Edges_Fill(0,51,127,63,0,0);
        glcd_draw_subdiv(2);


        glcd_draw_subdiv(66);
}
         int x;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CASO~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void caso_3(){
        char txt2[15];
//        pot1=pot2;//PORQUE POR AHORA SOLO ESTA IMPLEMENTADO UN POTENCIOMETRO
        POT1=0;
        glcd_draw_semicircles();
        old_x1=old_x2=0;
         Glcd_set_Font(font5x7 , 5, 7, 32);
}
void caso_3_test(){
    Glcd_Set_Font(Font_Glcd_System3x5 ,3,4,32);
        glcd_fill(0);
       glcd_draw_semicircles();

       for(x=2;x<64;x++){
        glcd_draw_pointer(x);
       }
       old_x1=old_x2=0;
        Glcd_set_Font(font5x7 , 5, 7, 32);
         //     Glcd_Line(32,64,32,34,1);
//        Glcd_Line(32,64,10,43,1);
//        Glcd_Line(32,64,53,xtoy(53),1);
//       glcd_draw_pointer(pot1+2,32);
}