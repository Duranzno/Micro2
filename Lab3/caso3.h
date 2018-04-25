// 2.3        El diseño detmp2 tener la opción de visualizar en la interfaz gráfica el valor en voltaje de cada uno de los potenciómetros en forma dinámica. 
//         *Use al menos 3 dígitos de precisión para cada caso en la 
//interfaz gráfica o LCD y actualice cada 1 segundo. 
//Dibuje una perilla semicircular que simule el movimiento de cada
// potenciómetro con sus valores inicio y final y al menos cinco subdivisiones.
// Nota2:Utilice el modo de Latcheo Simultaneo.
#define CENTER_Y 50
#define R_BIG 30
#define R_S 2


int center_x,r,z2,POT1=0,POT2=0;
float tmp1,tmp2;
int y,old_x1=0,old_x2=0;
char txt2[15];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CALCULOS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void autolog(char *message,float value){
        char txt2[15];
        floattostr(value,txt2);
        glcd_write_text(strcat(message,txt2),0,7,1);delay_ms(1000);glcd_write_text("                     ",0,7,1);
}
int xtoy(int x,int a){
    if(a==0){center_x=32;r=30;
     tmp1=pow(r,2);
     tmp2=pow(x+2-32,2);
     tmp1=tmp1-tmp2;
     tmp1=floor(CENTER_Y-sqrt(tmp1));
     x=tmp1;
    return x;}
    else if(a==1){
    
      center_x=96;r=30;
     tmp1=pow(r,2);
     tmp2=pow(x-32,2);
     tmp1=tmp1-tmp2;
     tmp1=floor(CENTER_Y-sqrt(tmp1));
     x=tmp1;
    return x;}

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~GLCD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void glcd_draw_pointer(unsigned short x,int a){
           if(a==0){
           center_x=32;
           Glcd_Line(32,CENTER_Y,old_x1,xtoy(old_x1,0),2);
           Glcd_Line(32,CENTER_Y,x,xtoy(x,0),1);
           old_x1=x;
           }
           else if(a==1){
           center_x=96;
           Glcd_Line(96,CENTER_Y,old_x2+64,xtoy(old_x2,1),2);
           Glcd_Line(96,CENTER_Y,x+64,xtoy(x,1),1);
           old_x2=x;
           
           }
            //glcd_write_text("                                              ",0,0,1);
        /*if(x<=64){
            if(old_x1){old_x1=2;}
            //Glcd_Line(center_x,CENTER_Y,old_x1,xtoy(old_x1),0);old_x1=x;

        }else {
            if(old_x2){old_x2=66;}
            //Glcd_Line(center_x,CENTER_Y,old_x2,xtoy(old_x2),0); old_x2=x;
        }*/
}
void glcd_draw_subdiv(unsigned short startx){
        int page=7;
        glcd_circle_fill(startx,xtoy(startx,0),R_S,1);
        glcd_write_text("0",startx,page-1,1);
        startx+=15;
        glcd_circle_fill(startx,xtoy(startx,0),R_S,1);
        glcd_write_text("0.23",startx-7,page,1);
        startx+=15;
        glcd_circle_fill(startx,xtoy(startx,0),R_S,1);
        glcd_write_text("1",startx-5,page-1,1);
        startx+=15;
        glcd_circle_fill(startx,xtoy(startx,0),R_S,1);
        glcd_write_text("1.9",startx-11,page,1);
        glcd_write_text("2.8",startx-4,page-1,1);

        startx+=15;

        glcd_circle_fill(startx,xtoy(startx,0)-2,R_S,1);
        glcd_write_text("3.5",startx-11,page,1);
  }
void glcd_draw_subdiv2(unsigned short startx){
        int page=7;
        glcd_circle_fill(startx+64,xtoy(startx,0),R_S,1);
        glcd_write_text("0",startx+64,page-1,1);
        startx+=15;
        glcd_circle_fill(startx+64,xtoy(startx,0),R_S,1);
        glcd_write_text("0.23",startx+64-7,page,1);
        startx+=15;
        glcd_circle_fill(startx+64,xtoy(startx,0),R_S,1);
        glcd_write_text("1",startx+64-5,page-1,1);
        startx+=15;
        glcd_circle_fill(startx+64,xtoy(startx,0),R_S,1);
        glcd_write_text("1.9",startx+64-11,page,1);
        glcd_write_text("2.8",startx+64-4,page-1,1);
        startx+=15;
        glcd_circle_fill(startx+64,xtoy(startx,0)-2,R_S,1);
        glcd_write_text("3.5",startx-11+64,page,1);
  }
void glcd_draw_semicircles(){
        glcd_circle(32,CENTER_Y,30,1);//nalga 1
        glcd_circle(96,CENTER_Y,30,1);//nalga 2
        Glcd_Rectangle_Round_Edges_Fill(0,51,127,63,0,0);
        glcd_draw_subdiv(2);
        glcd_draw_subdiv2(2);
}
void convertidor_voltaje(const float valor,unsigned short x,unsigned short page) {
        int i11,i2,d1,d2,d3;
        float n0;
        i11 = valor*0.1;
        i2 = valor-(10*i11);
        bytetostr(i2, txt2);
        glcd_write_text(ltrim(txt2), 5+x, page, 1);
        glcd_write_text(".", 11+x, page, 1);
        n0 = (valor - 10*i11 - i2)*10000;
        d1 = n0/1000;
        bytetostr(d1, txt2);
        glcd_write_text(ltrim(txt2), 17+x, page, 1);
        d2 = (n0 - d1*1000)/100;
        bytetostr(d2, txt2);
        glcd_write_text(ltrim(txt2), 23+x, page, 1);
        d3 = (n0 - d1*1000 - d2*100)/10;
        bytetostr(d3, txt2);
        glcd_write_text(ltrim(txt2), 29+x, page, 1);}
         int x;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CASO~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void caso_3(){

        tmp1=pot1*0.058;
        tmp2=pot2*0.058;
        x=tmp1;
        y=tmp2;
        glcd_draw_pointer(x,0);
        glcd_draw_pointer(y,1);
        tmp1=pot1*0.00334;
        tmp2=pot2*0.00334;
        x=tmp1*1000;
        tmp1=x*(1.00/1000);
         x=tmp2*1000;
        tmp2=x*(1.00/1000);
        convertidor_voltaje(tmp1,0,0);
        convertidor_voltaje(tmp2,64,0);
}
void caso_3_setup(){
        glcd_draw_semicircles();
        old_x1=old_x2=0;

         //0.00334
}
void caso_3_test(){

        glcd_fill(0);
       glcd_draw_semicircles();

       for(x=2;x<64;x++){
        glcd_draw_pointer(x,0);
       }
       old_x1=old_x2=0;
       delay_ms(500);
       for(x=2;x<64;x++){
            Glcd_Line(32,CENTER_Y,x,xtoy(x,0)+1,2);
       }
        Glcd_set_Font(font5x7 , 5, 7, 32);
         //     Glcd_Line(32,64,32,34,1);
//        Glcd_Line(32,64,10,43,1);
//        Glcd_Line(32,64,53,xtoy(53),1);
//       glcd_draw_pointer(pot1+2,32);
}