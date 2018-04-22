// 2.3        El diseño debe tener la opción de visualizar en la interfaz gráfica el valor en voltaje de cada uno de los potenciómetros en forma dinámica. 
//         *Use al menos 3 dígitos de precisión para cada caso en la 
//interfaz gráfica o LCD y actualice cada 1 segundo. 
//Dibuje una perilla semicircular que simule el movimiento de cada
// potenciómetro con sus valores inicio y final y al menos cinco subdivisiones.
// Nota2:Utilice el modo de Latcheo Simultaneo.

int POT1=0,POT2=0;
void autolog(char *message,int value){
        char txt2[15];
        inttostr(value,txt2);
        glcd_write_text(strcat(txt2,message),0,7,1);delay_ms(500);glcd_write_text("                     ",0,7,1);
}
int xtoy(unsigned short x){
	unsigned short center_x,r=30,center_y=64;
	if(x<=64){center_x=32;}
	else{center_x=96;}
    int y=floor(center_y-sqrt(pow(r,2)-pow(x-center_x,2)));
    // autolog("r^2",ceil(pow(r,2)));
    // autolog("(x-cx)^2",pow(x-center_x,2));
    // autolog("sqrt(r^2-(x-cx)^2)",sqrt(pow(r,2)-pow(x-center_x,2)));
    // autolog("r^2",center_y-sqrt(pow(r,2)-pow(x-center_x,2)));
	return y;
}
int xtoy2(unsigned short x){
	unsigned short center_x,r=5,center_y=64;
	if(x<=64){center_x=32;}
	else{center_x=96;}
    int y=floor(center_y-sqrt(pow(r,2)-pow(x-center_x,2)));
    // autolog("r^2",ceil(pow(r,2)));
    // autolog("(x-cx)^2",pow(x-center_x,2));
    // autolog("sqrt(r^2-(x-cx)^2)",sqrt(pow(r,2)-pow(x-center_x,2)));
    // autolog("r^2",center_y-sqrt(pow(r,2)-pow(x-center_x,2)));
	return y;
}
void glcd_draw_pointer(unsigned short x,unsigned short center_x){
        //x_medida va de 0->60

        Glcd_Line(center_x,64,x,xtoy(x,center_x,64),1);
}
void glcd_draw_subdiv(unsigned short startx,int page){
	glcd_write_text("0K",xtoy2(startx),page,1);
	startx+=12;
	glcd_circle_fill(startx,xtoy2(startx),2,1);
	glcd_write_text("1K",xtoy2(startx),page,1);
	startx+=12;
	glcd_circle_fill(startx,xtoy2(startx),2,1);
	glcd_write_text("2K",xtoy2(startx),page,1);
	startx+=12;
	glcd_circle_fill(startx,xtoy2(startx),2,1);
	glcd_write_text("3K",xtoy2(startx),page,1);
	startx+=12;
	glcd_circle_fill(startx,xtoy2(startx),2,1);
	glcd_write_text("4K",xtoy2(startx),page,1);
	startx+=12;
	glcd_circle_fill(startx,xtoy2(startx),2,1);
	glcd_write_text("5K",xtoy2(startx),page,1);
}
void glcd_draw_semicircles(int x){
	glcd_circle(x,64,30,1);//nalga 1
	glcd_draw_subdiv(x,2);
}

void caso_3_impl_main(){
	while(keydata!=ESC){
        clean_PS2();
        caso_3();
        Ps2_Key_Read(&keydata, &special, &down);
     }
    glcd_fill(0);
}
void caso_3(){
	pot1=pot2;//PORQUE POR AHORA SOLO ESTA IMPLEMENTADO UN POTENCIOMETRO
	glcd_draw_semicircles(32);
	// glcd_draw_semicircles(96);
	char txt2[15];
	inttostr(pot1,txt2);glcd_write_text(strcat(pot1,message),0,0,1);	
	glcd_draw_pointer(pot1+2,32)
}
void caso_3_tests(){
	int x;     char txt2[15]; int y;
    glcd_fill(0);

    y=xtoy(0+2,32,64);
//        for(x=0;x<61;x+=1){
//                glcd_draw_pointer(x+2,32,64);
//                  y=xtoy(x+2,32,64);
//                   inttostr(y,txt2);
//                   glcd_write_text(strcat(txt2,"_xtoy"),0,0,1);
//                delay_ms(25);
//        }
    for(x=0;x<61;x+=1){
            glcd_draw_pointer(x+66,96,64);
            delay_ms(25);
    }
    glcd_fill(0);

    
}