// 2.3        El diseño detmp2 tener la opción de visualizar en la interfaz gráfica el valor en voltaje de cada uno de los potenciómetros en forma dinámica. 
//         *Use al menos 3 dígitos de precisión para cada caso en la 
//interfaz gráfica o LCD y actualice cada 1 segundo. 
//Dibuje una perilla semicircular que simule el movimiento de cada
// potenciómetro con sus valores inicio y final y al menos cinco subdivisiones.
// Nota2:Utilice el modo de Latcheo Simultaneo.
#define CENTER_Y 64
unsigned short center_x,r=30,POT1=0,POT2=0;
float tmp1,tmp2;
int y;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CALCULOS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void autolog(char *message,float value){
        char txt2[15];
        floattostr(value,txt2);
        glcd_write_text(strcat(message,txt2),0,7,1);delay_ms(1000);glcd_write_text("                     ",0,7,1);
}
float xtoy(unsigned short x){

    r=30;
    tmp1=0;tmp2=0;
        tmp1=pow(r,2); //floattostr(tmp1,txt2); glcd_write_text(strcat("r^2",txt2),0,7,1);delay_ms(500);glcd_write_text("                     ",0,7,1);
        autolog("r^2 ",tmp1);
        tmp2=pow(x-center_x,2);//  floattostr(tmp1,txt2); glcd_write_text(strcat("(x-cx)^2",txt2),0,7,1);delay_ms(500);glcd_write_text("                     ",0,7,1);
        autolog("x^2 ",tmp2);
        tmp1=tmp1-tmp2;    //floattostr(tmp1,txt2); glcd_write_text(strcat("tmp1-tmp2",txt2),0,7,1);delay_ms(500);glcd_write_text("                     ",0,7,1);
        autolog("t1-t2 ",tmp1);
        tmp1=sqrt(tmp1);//  floattostr(tmp1,txt2); glcd_write_text(strcat("final",txt2),0,7,1);delay_ms(500);glcd_write_text("                     ",0,7,1);
         autolog("raiz ",tmp1);
         y=tmp1;
    return y;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~GLCD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void glcd_draw_pointer(unsigned short x,unsigned short center_x){
        Glcd_Line(center_x,xtoy(x),x,64,1);
}
void glcd_draw_subdiv(unsigned short startx,int page){
        glcd_circle_fill(startx,64,2,1);
        glcd_write_text("0V",startx,page,1);
        glcd_circle_fill(startx+60,64,2,1);
        glcd_write_text("3.4V",startx+60,page,1);
}
void glcd_draw_semicircles(int x){
        glcd_circle(x,64,30,1);//nalga 1
        glcd_draw_subdiv(x,2);
}
         int x;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CASO~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
         //glcd_fill(0);
//        glcd_draw_semicircles(CX1);delay_ms(2500);
//        glcd_fill(0);
float lol,ae,be;
void caso_3_tests(int x){
  char txt2[15];

    char txt2[15];
    if(x<=64){center_x=32;}
    else{center_x=96;}
     r=30
     ae=pow(r,2);
     be=pow(x-center_x,2);
     ae=ae-be;
     ae=floor(CENTER_Y-sqrt(ae));
     x=ae;
     inttostr(x,txt2); glcd_write_text(txt2,0,7,1);delay_ms(500);glcd_write_text("                     ",0,7,1);
    return x;
}
void caso_3(){
        char txt2[15];
        pot1=pot2;//PORQUE POR AHORA SOLO ESTA IMPLEMENTADO UN POTENCIOMETRO
        glcd_draw_semicircles(32);
        // glcd_draw_semicircles(96);

        inttostr(pot1,txt2);glcd_write_text(strcat(pot1,"POT1"),0,0,1);
        glcd_draw_pointer(pot1+2,32);
}
void caso_3_impl_main(){
        while(keydata!=ESC){
        clean_PS2();
        caso_3();
        Ps2_Key_Read(&keydata, &special, &down);
     }
    glcd_fill(0);
}