// 2.3        El diseño debe tener la opción de visualizar en la interfaz gráfica el valor en voltaje de cada uno de los potenciómetros en forma dinámica. 
//         *Use al menos 3 dígitos de precisión para cada caso en la interfaz gráfica o LCD y actualice cada 1 segundo. Dibuje una perilla semicircular que simule el movimiento de cada potenciómetro con sus valores inicio y final y al menos cinco subdivisiones.
// Nota2:Utilice el modo de Latcheo Simultaneo.

#define r 30//radio
//hacer un cambio de origen


int xtoy(unsigned short x,unsigned short center_x,unsigned short center_y){
                int y=floor(center_y-sqrt(pow(r,2)-pow(x-center_x,2)));
            return y;
}
void glcd_draw_pointer(unsigned short x,unsigned short center_x,unsigned short center_y){
        //x_medida va de 0->60
        Glcd_Line(center_x,center_y,x,xtoy(x,center_x,center_y),1);
}

void caso_3_tests(){
int x;     char txt2[15]; int y;
        glcd_fill(0);
        glcd_circle(32,64,30,1);
        glcd_circle(96,64,30,1);;//circulo origen ideal inverso  unitario

        
        for(x=0;x<61;x+=1){
//                glcd_draw_pointer(x+2,32,64);
                  y=xtoy(x+2,32,64);
                   inttostr(y,txt2);
                   glcd_write_text(strcat(txt2,"_xtoy"),0,0,1);
                delay_ms(25);
        }
        for(x=0;x<61;x+=1){
                glcd_draw_pointer(x+66,96,64);
                delay_ms(25);
        }
        glcd_fill(0);

        
}