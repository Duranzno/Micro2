#define ESC 27
char menu[] = "Menu";
char Bien1[] = "\r Bienvenido al caso 1  \x0a \x0d";
char Bien2[] = "\n Bienvenido al caso 2 \x0a \x0d";
char Space[]="\n \x0a \x0d"  ;
char Bien3[] = "\x0a \x0d \x0a \x0d  Bienvenido al caso 3 \x0a \x0d";
char caso1[] = "A",caso2[] = "B",caso3[] = "C";
char POT1[] = "  POT 1: \r",POT2[] = "  POT 2: \r";
char MOTO1[] = " MOT 1 ACT ",MOTO2[] = " MOT 2 ACT ";
char error1[]= "\r POT 1 HA SUPERADO\n \r";
char error2[]= "\r POT 2 HA SUPERADO \n \r";
char Bi4[] = "\r \x0a 4 GUARDAR  \r" ;
char Bi5[] = "\r \x0a 5 MOSTRAR  \r" ;
char Bi6[] = "\r \x0a 6 SALIR  \r" ;
char Bien5[] = "\r Bienvenido al caso 5 \r";
char caso1_1[]="VEL(RPN) ######             |                 ####";
char caso1_2[]="SENT        ###             |                  ###";
char caso1_3[]="FALLA        ##             |                   ##";

unsigned PA,PB;
int cont = 0,it=0;
char CL[]="\x0a";
char IL[]="x0d";
char CL1[]="\n";
char IL1[]="\r";
char txt7[7];

void space1(){
        while(!HID_Write(space,64));        
}
void space2(){
        while(!HID_Write(space,64));
        while(!HID_Write(space,64));
}
void write(char *txt){
        space2();
        while(!HID_Write(txt,64));
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~HID MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void menu2(){
        write(menu);
        write("--------------------------------------------------");
        write("CASO A MOTORES");
        write("CASO B COMPARACION");
        write("CASO C DAC");
        space1();
        space1();
        space1();
        space1();
        space1();        
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~HID CASO1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void update_caso1(unsigned rpn1,unsigned rpn2){
        inttostr(rpn1,txt7);
        caso1_1[9] =txt7[0];
        caso1_1[10]=txt7[1];
        caso1_1[11]=txt7[2];
        caso1_1[12]=txt7[3];
        caso1_1[13]=txt7[4];
        caso1_1[14]=txt7[5];
        inttostr(rpn2,txt7);
        caso1_1[45]=txt7[1];
        caso1_1[46]=txt7[2];
        caso1_1[47]=txt7[3];
        caso1_1[48]=txt7[4];
        caso1_1[49]=txt7[5];
}
void update_caso3(unsigned falla1,unsigned falla2){
        //falla=1 si & falla=0 no
        if(falla1){
                caso1_3[13]='S';
                caso1_3[14]='I';
        }else{
                caso1_3[13]='N';
                caso1_3[14]='O';
        }
        if(falla2){
                caso1_3[48]='S';
                caso1_3[49]='I';
        }else{
                caso1_3[48]='N';
                caso1_3[49]='O';
        }
}
void update_caso2(unsigned sent1,unsigned sent2){
        //sent=1 izquierda & sent=0 derecha
        if(sent1){
                caso1_2[12]='I';
                caso1_2[13]='Z';
                caso1_2[14]='Q';
        }else{
                caso1_2[12]='D';
                caso1_2[13]='E';
                caso1_2[14]='R';
        }
        if(sent2){
                caso1_2[47]='I';
                caso1_2[48]='Z';
                caso1_2[49]='Q';
        }else{
                caso1_2[47]='D';
                caso1_2[48]='E';
                caso1_2[49]='R';
        }
}
void logd(char *txt){
        write(txt);
        space1();
        space1();
        space1();
        space1();
        space1();
        space1();
        space1();
        space1();
        space1();
}
void caso_1(unsigned rpn1,unsigned rpn2,
        unsigned sent1,unsigned sent2,
        unsigned falla1,unsigned falla2){

        update_caso1(rpn1,rpn2);
        update_caso2(sent1,sent2);
        update_caso3(falla1,falla2);
        
        write("        MOTOR 1             |              MOTOR 2");
        write("----------------------------|---------------------");
        write(caso1_1);
        write(caso1_2);
        write(caso1_3);
        space1();
        space1();
        space1();
        space1();
        space1();
        space1();
}