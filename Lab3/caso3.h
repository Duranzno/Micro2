// 2.3        El diseño debe tener la opción de visualizar en la interfaz gráfica el valor en voltaje de cada uno de los potenciómetros en forma dinámica. 
//         *Use al menos 3 dígitos de precisión para cada caso en la interfaz gráfica o LCD y actualice cada 1 segundo. Dibuje una perilla semicircular que simule el movimiento de cada potenciómetro con sus valores inicio y final y al menos cinco subdivisiones.
// Nota2:Utilice el modo de Latcheo Simultaneo.
#define a 64//origen x
#define r 32//radio
//hacer un cambio de origen
void glcd_draw_semicircle();
int xtoy(int x){
                return abs(sqrt(pow(r,2)-pow(x-64,2)));
}
void glcd_draw_pointer(unsigned short x_medida){
        //x_medida va de 0->64
        Glcd_Line(a,0,x_medida+32,xtoy(x_medida),1);
}
int i
void caso_1_tests(){
        //circulos
        glcd_fill(0);
        Glcd_Circle(0,0,1,1);Glcd_Write_TEXT("COU",60,0,1);delay_ms(500);//circulo origen unitario
        glcd_fill(0);
        Glcd_Circle(64,0,1,1);Glcd_Write_TEXT("COIU",60,0,1);delay_ms(500);//circulo origen ideal unitario
        glcd_fill(0);
        Glcd_Circle(64,64,1,1);Glcd_Write_TEXT("COIIU",60,0,1);delay_ms(500);//circulo origen ideal inverso  unitario
        glcd_fill(0);
        Glcd_Circle(0,0,1,5);Glcd_Write_TEXT("CO5",60,0,1);delay_ms(500);//circulo origen unitario
        glcd_fill(0);
        Glcd_Circle(64,0,1,5);Glcd_Write_TEXT("COI5",60,0,1);delay_ms(500);//circulo origen ideal unitario
        glcd_fill(0);
        Glcd_Circle(64,64,1,5);Glcd_Write_TEXT("COII5",60,0,1);delay_ms(500);//circulo origen ideal inverso  unitario
        //lineas

        for(=0;i<64;i+=3){
                glcd_fill(0);
                glcd_draw_pointer(i);
                delay_ms(500);
        }
        animate_fail_2s("Larelele");
}