#define ESC 27
#define DER 0
#define IZQ 1
#define FALLA 1
#define NOFALLA 0
char menu[] = "Menu";
char Bien1[] = "\r Bienvenido al caso 1  \x0a \x0d";char Bien2[] = "\n Bienvenido al caso 2 \x0a \x0d";
char Bien3[] = " Bienvenido al caso 3";char Bien3[] = " Bienvenido al caso 3";char Bien4[] = " Bienvenido al caso 4";
char caso_1[] = "A",caso_2[] = "B",caso_3[] = "C",caso_4[] = "D";
char config_al[] = "Configuracion de Alarma";char config_ho[] = "Configuracion de Reloj";
char POT1[] = "  POT 1: \r",POT2[] = "  POT 2: \r";
char MOTO1[] = " MOT 1 ACT ",MOTO2[] = " MOT 2 ACT ";
char error1[]= "\r POT 1 HA SUPERADO\n \r";char error2[]= "\r POT 2 HA SUPERADO \n \r";

char caso1_1[]="VEL(RPN) ######             |                 ####";char caso1_2[]="SENT        ###             |                  ###";
char caso1_3[]="FALLA        ##             |                   ##";char caso1_4[]="POT          ##             |                   ##";

char caso2_nor[]="Todo esta funcionando bien  |              ";char caso2_sup[]="Limite Superior             |              ";
char caso2_inf[]="Limite Inferior             |              ";char caso2_pot[]=  "POT          ##             |              ";

char caso3_1[]="Salida por el PIN AN18 | OP=#";
char caso3_2[]="V |0.83  0.93  1.03  1.13  1.24  1.34  1.44  1.55|";char caso3_3[]="OP|   0     1     2     3     4     5     6     7|";
char caso3_4[]="V |1.65  1.75  1.86  1.96  2.06  2.17  2.27  2.37|";char caso3_5[]="OP|   8     9     A     B     C     D     E     F|";
char m[12][]{"Enero","Febrero","Marzo","Abril","Mayo",
                "Junio","Julio","Agosto","Septiembre",
                ,"Octubre","Noviembre","Diciembre"}
int cont = 0,it=0;

char txt7[7];

void space(int n){
        int i;
        for(i=0;i<n;i++){while(!HID_Write("\n \x0a \x0d",64));}        
}

void write(char *txt){
        space(2);
        while(!HID_Write(txt,64));
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~HID MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void hid_menu(){
        write(menu);
        write("--------------------------------------------------");
        write("CASO A MOTORES");
        write("CASO B COMPARACION");
        write("CASO C DAC");
        space(5);        
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~HID CASO1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void update_caso1(unsigned rpn1,unsigned rpn2){
        inttostr(rpn1,txt7);
        caso1_1[9] =txt7[0];caso1_1[10]=txt7[1];caso1_1[11]=txt7[2];
        caso1_1[12]=txt7[3];caso1_1[13]=txt7[4];caso1_1[14]=txt7[5];
        inttostr(rpn2,txt7);
        caso1_1[45]=txt7[1];caso1_1[46]=txt7[2];caso1_1[47]=txt7[3];
        caso1_1[48]=txt7[4];caso1_1[49]=txt7[5];
}
void update_caso3(unsigned falla1,unsigned falla2){
        //falla=1 si & falla=0 no
        if(falla1){
                caso1_3[13]='S';caso1_3[14]='I';
        }else{
                caso1_3[13]='N';caso1_3[14]='O';
        }
        if(falla2){
                caso1_3[48]='S';caso1_3[49]='I';
        }else{
                caso1_3[48]='N';caso1_3[49]='O';
        }
}
void update_caso4(unsigned pot1,unsigned pot2){
        inttostr(pot1,txt7);
        caso1_4[9] =txt7[0];caso1_4[10]=txt7[1];caso1_4[11]=txt7[2];
        caso1_4[12]=txt7[3];caso1_4[13]=txt7[4];caso1_4[14]=txt7[5];
        inttostr(pot2,txt7);
        caso1_4[44]=txt7[0];caso1_4[45]=txt7[1];caso1_4[46]=txt7[2];
        caso1_4[47]=txt7[3];caso1_4[48]=txt7[4];caso1_4[49]=txt7[5];
}
void update_caso2(unsigned sent1,unsigned sent2){
        //sent=1 izquierda & sent=0 derecha
        if(sent1){
                caso1_2[12]='I';caso1_2[13]='Z';caso1_2[14]='Q';
        }else{
                caso1_2[12]='D';caso1_2[13]='E';caso1_2[14]='R';
        }
        if(sent2){
                caso1_2[47]='I';caso1_2[48]='Z';caso1_2[49]='Q';
        }else{
                caso1_2[47]='D';caso1_2[48]='E';caso1_2[49]='R';
        }
}
void logd(char *txt){
        write(txt);space(9);
}
void hid_caso_1(unsigned rpn1,unsigned rpn2,unsigned sent1,unsigned sent2,
        unsigned falla1,unsigned falla2,unsigned pot1,unsigned pot2){

        update_caso1(rpn1,rpn2);
        update_caso2(sent1,sent2);
        update_caso3(falla1,falla2);
        update_caso4(pot1,pot2);
        
        write("        MOTOR 1             |              MOTOR 2");
        write("----------------------------|---------------------");
        write(caso1_1);
        write(caso1_2);
        write(caso1_3);
        write(caso1_4);
        space(6);
}
void hid_caso_3(){
        write(Bien3);
        write("----------------------------|---------------------");
        write(caso3_1);
        write(caso3_2);
        write(caso3_3);
        write(caso3_4);
        write(caso3_5);
        space(4);
}
void hid_caso_4(){
        write(Bien4);
        write("e) Programar Fecha y Hora Inicial");
        write("f) Encender Alarma  30s");
        write("g) Encender Alarma  60s");
        write("h) Encender Alarma  90s");
        write("i) Encender Alarma 120s");
        space(4);
}
void hid_caso_2(unsigned pot){
        write(Bien2);
        if(pot<1000){
                write(caso2_inf);
        }else if(pot>1000){
                write(caso2_sup);
        }else{
                write(caso2_nor);
        }
        inttostr(pot,txt7);
        caso2_pot[9] =txt7[0];caso2_pot[10]=txt7[1];caso2_pot[11]=txt7[2];
        caso2_pot[12]=txt7[3];caso2_pot[13]=txt7[4];caso2_pot[14]=txt7[5];
        write(caso2_pot);
        space(9);
}