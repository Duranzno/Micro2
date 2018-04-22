// 2.3        El diseño debe tener la opción de visualizar en la interfaz gráfica el valor en voltaje de cada uno de los potenciómetros en forma dinámica. 
//         *Use al menos 3 dígitos de precisión para cada caso en la 
//interfaz gráfica o LCD y actualice cada 1 segundo. 
//Dibuje una perilla semicircular que simule el movimiento de cada
// potenciómetro con sus valores inicio y final y al menos cinco subdivisiones.
// Nota2:Utilice el modo de Latcheo Simultaneo.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Interrupciones~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
short paolale=0;
void tee() org 0x1A{
	//ya se habra hecho el ADCINIT
	ADC1_Get_Sample(5);
	if(paolale){
		//le doy el valor al caso de alejandro

	}else if(paloale==1){
		//le doy el valor al caso de paola


	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void config_cron(){
  IEC0bits.T1IE=1;
  IFS0bits.T1IF=0;
  IPC0bits.T1IP=3;
  TMR1=0;
  T1CON=0X0010; //Prescaler 16:1, modo timer
  PR1=12500;
  //T1CONbits.TON=1;
}
#define r 30//radio
//hacer un cambio de origen

void autolog(char *message,int value){
        char txt2[15];
        inttostr(value,txt2);
        glcd_write_text(strcat(txt2,message),0,7,1);delay_ms(500);glcd_write_text("                     ",0,7,1);
}
int xtoy(unsigned short x,unsigned short center_x,unsigned short center_y){
                int y=floor(center_y-sqrt(pow(r,2)-pow(x-center_x,2)));
                autolog("r^2",ceil(pow(r,2)));
                autolog("(x-cx)^2",pow(x-center_x,2));
                autolog("sqrt(r^2-(x-cx)^2)",sqrt(pow(r,2)-pow(x-center_x,2)));
                autolog("r^2",center_y-sqrt(pow(r,2)-pow(x-center_x,2)));
            return y;
}
void glcd_draw_pointer(unsigned short x,unsigned short center_x,unsigned short center_y){
        //x_medida va de 0->60
        Glcd_Line(center_x,center_y,x,xtoy(x,center_x,center_y),1);
}
void glcd_draw_subdiv(unsigned short startx,int page){
	glcd_write_text("0K",xtoy(startx),page,1);
	startx+=12;
	glcd_circle_fill(startx,xtoy(startx),2,1);
	glcd_write_text("1K",xtoy(startx),page,1);
	startx+=12;
	glcd_circle_fill(startx,xtoy(startx),2,1);
	glcd_write_text("2K",xtoy(startx),page,1);
	startx+=12;
	glcd_circle_fill(startx,xtoy(startx),2,1);
	glcd_write_text("3K",xtoy(startx),page,1);
	startx+=12;
	glcd_circle_fill(startx,xtoy(startx),2,1);
	glcd_write_text("4K",xtoy(startx),page,1);
	startx+=12;
	glcd_circle_fill(startx,xtoy(startx),2,1);
	glcd_write_text("5K",xtoy(startx),page,1);
}
void caso_3_tests(){
int x;     char txt2[15]; int y;
        glcd_fill(0);
        glcd_circle(32,64,30,1);
        glcd_circle(96,64,30,1);;//circulo origen ideal inverso  unitario

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