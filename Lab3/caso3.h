// 2.3        El diseño debe tener la opción de visualizar en la interfaz gráfica el valor en voltaje de cada uno de los potenciómetros en forma dinámica. 
//         *Use al menos 3 dígitos de precisión para cada caso en la 
//interfaz gráfica o LCD y actualice cada 1 segundo. 
//Dibuje una perilla semicircular que simule el movimiento de cada
// potenciómetro con sus valores inicio y final y al menos cinco subdivisiones.
// Nota2:Utilice el modo de Latcheo Simultaneo.
#define CX1 32
#define CX2 96
#define CENTER_Y 64
unsigned short center_x,r=30,POT1=0,POT2=0;
int y;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CALCULOS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void autolog(char *message,int value){
        char txt2[15];
        inttostr(value,txt2);
        glcd_write_text(strcat(txt2,message),0,7,1);delay_ms(500);glcd_write_text("                     ",0,7,1);
}
int xtoy(unsigned short x){
    if(x<=64){center_x=CX1;}
    else{center_x=CX2;}
    r=30;
    y=floor(CENTER_Y-sqrt(pow(r,2)-pow(x-center_x,2)));

    return y;
}
int xtoy2(unsigned short x){
    if(x<=64){center_x=CX1;}
    else{center_x=CX2;}
    r=30;
    y=CENTER_Y-sqrt(pow(r,2)-pow(x-center_x,2));
    return y;
}
int xtoy_small(unsigned short x){
    if(x<=64) {center_x=CX1;}
    else {center_x=CX2;}
    r=5;
    y=floor(CENTER_Y-sqrt(pow(r,2)-pow(x-center_x,2)));
    return y;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~GLCD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void glcd_draw_pointer(unsigned short x,unsigned short center_x){
        Glcd_Line(center_x,xtoy(x),x,xtoy_small(x),1);
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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CASO~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void caso_3_tests(){
        glcd_fill(0);
        glcd_draw_semicircles(CX1);delay_ms(2500);
        glcd_fill(0);
//        autolog("Numero favorito Eduardo",7);
        r=30;center_x=CX1;x=20;
            autolog(" r^2=900= ",pow(r,2));
    autolog(" (x-cx)^2=144= ",pow(x-center_x,2));
    autolog(" sqrt(r^2-(x-cx)^2)=27.495= ",sqrt(pow(r,2)-pow(x-center_x,2)));
    autolog(" CENTER_Y-sqrt(pow(r,2)-pow(x-center_x,2))=36.46= ",CENTER_Y-sqrt(pow(r,2)-pow(x-center_x,2)));
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
}                                   1
