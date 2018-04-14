#line 1 "C:/Users/Gristelia/Documents/Micro II/laboratorios/micro2/Lab2/laboratorio2.c"
#line 1 "c:/users/gristelia/documents/micro ii/laboratorios/micro2/lab2/config.h"


sbit PS2_Data at RF4_bit;
sbit PS2_Clock at RF5_bit;
sbit PS2_Data_Direction at TRISF4_bit;
sbit PS2_Clock_Direction at TRISF5_bit;

sbit GLCD_D7 at RE1_bit;
sbit GLCD_D6 at RE0_bit;
sbit GLCD_D5 at RF1_bit;
sbit GLCD_D4 at RF0_bit;
sbit GLCD_D3 at RD7_bit;
sbit GLCD_D2 at RD6_bit;
sbit GLCD_D1 at RD5_bit;
sbit GLCD_D0 at RD4_bit;
sbit GLCD_D7_Direction at TRISE1_bit;
sbit GLCD_D6_Direction at TRISE0_bit;
sbit GLCD_D5_Direction at TRISF1_bit;
sbit GLCD_D4_Direction at TRISF0_bit;
sbit GLCD_D3_Direction at TRISD7_bit;
sbit GLCD_D2_Direction at TRISD6_bit;
sbit GLCD_D1_Direction at TRISD5_bit;
sbit GLCD_D0_Direction at TRISD4_bit;
sbit GLCD_CS1 at LATE3_bit;
sbit GLCD_CS2 at LATE2_bit;
sbit GLCD_RS at LATD1_bit;
sbit GLCD_RW at LATD2_bit;
sbit GLCD_EN at LATD3_bit;
sbit GLCD_RST at LATE4_bit;
sbit GLCD_CS1_Direction at TRISE3_bit;
sbit GLCD_CS2_Direction at TRISE2_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISE4_bit;

void config_IO(){
 ANSELB=0;
 ANSELC=0;
 ANSELD=0;
 ANSELE=0;
 ANSELG=0;
 TRISB=0xffff;
 TRISE=0;
 TRISG=0;
 TRISDbits.TRISD11=1;
 TRISDbits.TRISD10=1;
 TRISDbits.TRISD9=1;
 TRISDbits.TRISD8=1;
 TRISFbits.TRISF3=0;
 TRISEbits.TRISE5=0;
 TRISEbits.TRISE7=0;
 TRISGbits.TRISG6=0;
 TRISGbits.TRISG8=0;
 RPOR6bits.RP85R =0b010000;
 RPOR6bits.RP87R =0b010001;
 RPOR13bits.RP118R=0b010010;
 RPOR14bits.RP120R=0b010011;
 RPOR0bits.RP64R=0b010100;

}
void config_LCD(){
 Glcd_Init();
 Glcd_set_Font(font5x7 , 5, 7, 32);
 Glcd_Fill(0);
}
void config_pin () {
 TRISDbits.TRISD11=1;
 RPINR7bits.IC1R=75;
 TRISDbits.TRISD10=1;
 RPINR8bits.IC3R=74;
 TRISDbits.TRISD9=1;
 RPINR9bits.IC5R=73;
 TRISDbits.TRISD8=1;
 RPINR34bits.IC11R=72;

}
void config_captura (){

 TMR2=0;
 T2CONbits.TCKPS=2;
 T2CONbits.TGATE=0;
 T2CONbits.TCS=0;
 PR2=31250;
 IEC0bits.T2IE=1;
 IFS0bits.T2IF=0;

 IC2CON1bits.ICTSEL=7;
 IC2CON1bits.ICM=5;

 IC2CON2bits.IC32=1;

 IC1CON1bits.ICTSEL=7;
 IC1CON1bits.ICM=5;

 IEC0bits.IC1IE=1;
 IFS0bits.IC1IF=0;

 IC1CON2bits.IC32=1;


 IC4CON1bits.ICTSEL=7;
 IC4CON1bits.ICM=5;

 IC4CON2bits.IC32=1;

 IC3CON1bits.ICTSEL=7;
 IC3CON1bits.ICM=5;

 IEC2bits.IC3IE=1;
 IFS2bits.IC3IF=0;

 IC3CON2bits.IC32=1;


 IC6CON1bits.ICTSEL=7;
 IC6CON1bits.ICM=5;

 IC6CON2bits.IC32=1;

 IC5CON1bits.ICTSEL=7;
 IC5CON1bits.ICM=5;

 IEC2bits.IC5IE=1;
 IFS2bits.IC5IF=0;

 IC5CON2bits.IC32=1;

 IC12CON1bits.ICTSEL=7;
 IC12CON1bits.ICM=5;

 IC12CON2bits.IC32=1;

 IC11CON1bits.ICTSEL=7;
 IC11CON1bits.ICM=5;

 IEC7bits.IC11IE=1;
 IFS7bits.IC11IF=0;

 IC5CON2bits.IC32=1;
}
void config_TMR_1(){

 TMR1=0;
 PR1=31250;
 IEC0bits.T1IE=1;
 IFS0bits.T1IF=0;

 T1CON=0;
 T1CONBits.TCKPS= 2;
 T1CONBits.TON=0;

}
void config_TMR_45(){
 IEC1bits.T4IE=1;
 IEC1bits.T5IE=1;
 IFS1bits.T4IF=0;
 IFS1bits.T5IF=0;
 T4CONbits.TCKPS=0;
 T4CONbits.TCS=0;
 TMR4=0;
 PR4=2000;
 T5CONbits.TCKPS=5;
 T5CONbits.TCS=0;
 TMR5=0;
 PR5=39062;

}
void config_OC(){
 OC5CON1bits.OCTSEL=7;
 OC1CON1bits.OCTSEL=2;
 OC2CON1bits.OCTSEL=2;
 OC3CON1bits.OCTSEL=2;
 OC4CON1bits.OCTSEL=2;
 OC1CON2bits.OCTRIS=1;
 OC2CON2bits.OCTRIS=1;
 OC3CON2bits.OCTRIS=1;
 OC4CON2bits.OCTRIS=1;
 OC5CON2bits.OCTRIS=1;

 OC5CON1bits.OCM=5;
 OC1CON1bits.OCM=5;
 OC2CON1bits.OCM=5;
 OC3CON1bits.OCM=5;
 OC4CON1bits.OCM=5;
 OC5R=306; OC5RS=2047;
 OC1R=306; OC1RS=2047;
 OC2R=921; OC2RS=2047;
 OC3R=1227; OC3RS=2047;
 OC4R=1637; OC4RS=2047;
 OC1CON2bits.SYNCSEL=0b01111;
 OC2CON2bits.SYNCSEL=0b00101;
 OC3CON2bits.SYNCSEL=0b01111;
 OC4CON2bits.SYNCSEL=0b01111;
 OC5CON2bits.SYNCSEL=0b01111;
}
void config_INT(){
 SRbits.IPL =0;
 INTCON1bits.NSTDIS =0;
 INTCON2bits.GIE=1;
 CORCONbits.IPL3 = 0;

 IPC0bits.T1IP=2;
 IPC1bits.T2IP=4;
 IPC6bits.T4IP=2;
 IPC7bits.T5IP=3;
 IPC0bits.IC1IP=2;
 IPC9bits.IC3IP=2;
 IPC9bits.IC5IP=2;
 IPC31bits.IC11IP=2;

 }



 void config_ic() {
 IC1CON1bits.ICTSEL=1;
 IC2CON1bits.ICTSEL=1 ;
 IC1CON1bits.ICM=2;
 IC2CON1bits.ICM=2;
 IC1CON2bits.IC32=1;
 IC2CON2bits.IC32=1;

 IC1CON2bits.SYNCSEL=13;
 IC2CON2bits.SYNCSEL=13;
 IEC0bits.IC1IE=1;
 IEC0bits.IC2IE=1;
 IFS0bits.IC1IF=0;
 IFS0bits.IC2IF=0;
 IC1CON2bits.ICTRIG=0;
 IC2CON2bits.ICTRIG=0;
}
void config_timeric () {
 T3CONbits.TSIDL=1;
 T2CON= 0x8020;
 PR2=31250;
 T2CONbits.T32=1;
 IPC1bits.T2IP=3;
}
#line 1 "c:/users/gristelia/documents/micro ii/laboratorios/micro2/lab2/ui.h"







unsigned short keydata = 0, special = 0, down = 0,y;
char txt[15];
char t[3],c1;
void clean_PS2(){ keydata = 0, special = 0, down = 0;}

void cursor_animation(int it){
 int i;
 for(i=1; i < 6; i++ ){
 if(i==it){
 Glcd_Write_Text("*",0,i,1);
 }else{
 Glcd_Write_Text(" ",0,i,1);
 }
 }
}
int cursor_menu(int max_n_options){




 int it=1;
 while(keydata!= 13 ){
 cursor_animation(it);
 if(Ps2_Key_Read(&keydata, &special, &down)){
 if(down){
 if(keydata== 108 ||keydata== 111 ){
 if(keydata== 108 ){
 it=it+1;
 if(it>max_n_options){it=1;}
 clean_PS2();
 }
 if(keydata== 111 ){
 it=it-1;
 if(it==0){it=max_n_options;}
 clean_PS2();
 }
 cursor_animation(it);
 } else if(keydata== 118 ){
 Glcd_Write_TEXT("ESC" ,60,7,1);delay_ms(500);
 break;
 } else{
 Glcd_Write_TEXT("ERR" ,60,7,1);delay_ms(500);
 }
 }
 }
 }
 return it;
}



void texto_menu(){
 Glcd_Write_TEXT("Laboratorio 2",60,0,1);
 Glcd_Write_TEXT("1) Cronometro", 6 ,1,1);
 Glcd_Write_TEXT("1) Captura" , 6 ,2,1);
 Glcd_Write_TEXT("3) PWM  " , 6 ,3,1);
}
void texto_caso_1(){

 Glcd_Write_Text("Cronometro",60,0,1);
 Glcd_Write_Text("1) Programar Hora", 6 ,1,1);
 Glcd_Write_Text("2) PLAY" , 6 ,2,1);
 Glcd_Write_Text("3) PAUSE" , 6 ,3,1);
 Glcd_Write_Text("4) RESET  " , 6 ,4,1);
 Glcd_Write_Text("5) Alarma", 6 ,5,1);
}
void texto_caso_2(){
 GLCD_FILL(0);
 Glcd_Write_Text("Puerto de Entrada",60,0,1);
 Glcd_Write_Text("RP75/RD11" ,0,1,1);
 Glcd_Write_Text("RP74/RD10" ,0,2,1);
 Glcd_Write_Text("RP73/RD09" ,0,3,1);
 Glcd_Write_Text("RP72/RD8" ,0,4,1);
}
void texto_caso_3(){
 GLCD_FILL(0);
 Glcd_Write_Text("Puerto de Entrada",60,0,1);
 Glcd_Write_Text("RP101/RG8 80%" ,0,4,1);
 Glcd_Write_Text("RP85 /RE5 15%" ,0,1,1);
 Glcd_Write_Text("RP87 /RE7 45%" ,0,2,1);
 Glcd_Write_Text("RP87 /RG6 60%" ,0,3,1);
}
#line 1 "c:/users/gristelia/documents/micro ii/laboratorios/micro2/lab2/extras.h"





int page2pos(int page_num){
switch(page_num){
 case 0:
 return 0;
 break;
 case 1:
 return 8;
 break;
 case 2:
 return 16;
 break;
 case 3:
 return 24;
 break;
 case 4:
 return 32;
 break;
 case 5:
 return 40;
 break;
 case 6:
 return 48;
 break;
 case 7:
 return 56;
 break;
 }
}
char intToAscii(int fn){
 char t=0;
 if(fn>0&&fn<=9){
 intToStr(fn,t);
 }else if(fn==10){
 intToStr(0,t);
 }else{
 t='0';
 }
 return t;
}

void oscilador_usado(){
 switch(OSCCONBits.COSC){
 case 0:
 glcd_write_text("FRC",0,7,1);
 delay_ms(2000);
 glcd_fill(0);
 break;
 case 1:
 glcd_write_text("FRCPLL",0,7,1);
 delay_ms(2000);
 glcd_fill(0);
 break;
 case 2:
 glcd_write_text("posc",0,7,1);
 delay_ms(2000);
 glcd_fill(0);
 break;
 case 3:
 glcd_write_text("posc_pll",0,7,1);
 delay_ms(2000);
 glcd_fill(0);
 break;
 case 4:
 glcd_write_text("sosc",0,7,1);
 delay_ms(2000);
 glcd_fill(0);
 break;
 case 5:
 glcd_write_text("lprc",0,7,1);
 delay_ms(2000);
 glcd_fill(0);
 break;
 case 6:
 glcd_write_text("frcdiv16",0,7,1);
 delay_ms(2000);
 glcd_fill(0);
 break;
 case 7:
 glcd_write_text("frcdivn",0,7,1);
 delay_ms(2000);
 glcd_fill(0);
 break;
 default:
 glcd_write_text("none",0,7,1);
 delay_ms(2000);
 glcd_fill(0);
 break;
 }
 }
#line 6 "C:/Users/Gristelia/Documents/Micro II/laboratorios/micro2/Lab2/laboratorio2.c"
unsigned short op=0;
unsigned short d_mseg=0,u_mseg=0,u_seg=0,d_seg=0,u_min=0,d_min=0,u_hora=0,d_hora=0;
char hora[12] ={'0','0',':','0','0',':','0','0',':','0','0','\0'};
char alarma[12]={'0','0',':','0','0',':','0','0',':','0','0','\0'};
char texta=1+'0';
int ENALARM=0,conta1=0,selected=0;
float T1,T2,T3,T4;
int pulso=0, pulso2=0,pulso3=0,pulso4=0;
float frecuencia,frecuencia2,frecuencia3,frecuencia4;
void cron_write();

void TIMER1() org 0x1A{
 u_seg++;
 if(u_seg==10)
 { u_seg=0;
 d_seg++;
 if(d_seg==6)
 { d_seg=0;
 u_min++;
 if(u_min==10)
 { u_min=0;
 d_min++;
 if(d_min==6)
 { d_min=0;
 u_hora++;
 if(u_hora==10 && d_hora==0)
 { u_hora=0;
 d_hora++;
 }
 else if(u_hora==3 && d_hora==1)
 { u_hora=1;
 d_hora=0;
 }
 }
 }
 }
 }
 if(ENALARM&&Alarma[0]==HORA[0]&&Alarma[1]==HORA[1]&&Alarma[3]==HORA[3]&&Alarma[4]==HORA[4]){
 Glcd_Fill(0);

 ENALARM=0;
 }
 HORA[0]=d_hora+'0';
 HORA[1]=u_hora+'0';
 HORA[2]=':';
 HORA[3]=d_min+'0';
 HORA[4]=u_min+'0';
 HORA[5]=':';
 HORA[6]=d_seg+'0';
 HORA[7]=u_seg+'0';
 HORA[8]=':';
 HORA[9]=d_mseg+'0';
 HORA[10]=u_mseg+'0';
 HORA[11]='\0';
 cron_write();
 IFS0bits.T1IF=0;
}
void captura_onda_ic1() org 0x16{
 pulso++;
 inttostr(pulso,txt);
 glcd_write_text(txt,0,7,1);
 IFS0bits.IC1IF=0;

}


void captura_onda_ic3() org 0x5E{
 pulso2++;
 inttostr(pulso2,txt);
 glcd_write_text(txt,10,5,1);
 Glcd_Write_Text("c3",60,5,1);
 IFS2bits.IC3IF=0;

}
void captura_onda_ic5() org 0x62{
 pulso3++;
 inttostr(pulso3,txt);
 glcd_write_text(txt,20,7,1);
 Glcd_Write_Text("c5",65,4,1);
 IFS2bits.IC5IF=0;

}
void captura_onda_ic11() org 0x112{
 pulso4++;
 inttostr(pulso4,txt);
 glcd_write_text(txt,40,7,1);

 IFS7bits.IC11IF=0;

}







void int_timer2 () org 0x22{
 IC1CON1bits.ICM=0;
 IC3CON1bits.ICM=0;
 IC5CON1bits.ICM=0;
 IC11CON1bits.ICM=0;
 T2CONbits.TON=1;
 IFS0bits.T2IF=0;
 frecuencia=pulso*4*2;
 frecuencia2=pulso2*4*2;
 frecuencia3=pulso3*4*2;
 frecuencia4=pulso4*4*2;
 T1=(1/frecuencia)*1000000;
 T2=(1/frecuencia2)*1000000;
 T3=(1/frecuencia3)*1000000;
 T4=(1/frecuencia4)*1000000;
}
void Timer4() org 0x4A{
 IFS1bits.T4IF=0;
}
void Timer5() org 0x4C{
 IFS1bits.T5IF=0;
}

void cron_write();
void clean_PS2();


unsigned short arreglo_hora_militar_up(int i,unsigned int valor_nuevo){
 if(i== 0 ){
 if(valor_nuevo==4){
 return 0;
 }
 }
 if(i== 1 ){
 if(HORA[ 0 ]==2&&valor_nuevo>3){
 HORA[ 0 ]=0;
 return 0;
 }
 if(valor_nuevo>=9){return 0;}
 }
 if(i== 3 ){
 if(valor_nuevo>5){
 return 0;
 }
 }
 if(i== 4 ){
 if(valor_nuevo>9){return 0;}
 }
}
unsigned short arreglo_hora_militar_dw(int i,unsigned int valor_nuevo){
 if(i== 0 ){
 if(valor_nuevo==-1){
 return 2;
 }
 }
 if(i== 1 ){
 if(HORA[ 0 ]==0&&valor_nuevo<0){
 HORA[ 0 ]=2;
 return 3;
 }else if(valor_nuevo<0){return 9;}
 }
 if(i== 3 ){
 if(valor_nuevo<0){
 return 5;
 }
 }
 if(i== 4 ){
 if(valor_nuevo<0){return 9;}
 }
}
int i=0;
void cron_write(){
 Glcd_Write_TEXT("                                              ",60,7,1);
 i=0;
 for(i=0;i<12;i++){
 Glcd_Write_Char(HORA[i],50+i*5,7,1);
 }
}
void num_update(int it,int x_pos,int page){
 Glcd_Write_Char(it+'0',x_pos,page,1);
}

int num_selector(int x_pos,int indice){
 int it=0;
 num_update(it,x_pos,7);
 clean_PS2();
 while(keydata!= 13 ){
 if(Ps2_Key_Read(&keydata, &special, &down)){
 if(down){
 if(keydata== 108 ||keydata== 111 ){
 if(keydata== 111 ){
 it=it+1;
 it=arreglo_hora_militar_up(indice,it);
 clean_PS2();
 }
 if(keydata== 108 ){
 it=it-1;
 it=arreglo_hora_militar_dw(indice,it);
 clean_PS2();
 }
 num_update(it,x_pos,7);
 clean_PS2();
 }
 clean_PS2();
 }
 }
 }
 return it;
}
void cron_cursor(){
int x_pos=50,i,j;

 clean_PS2();
 for(i=0;i<5;i++){
 if(i!=2){
 j=num_selector(50+i*5,i)+'0';
 HORA[i]=j;
 }else if(i==2){
 HORA[2]=':' ;
 }
 clean_PS2();
 cron_write();
 }
}
void caso_1(){
 while(keydata!= 118 ){
 selected=cursor_menu(5);
 switch(selected){
 case 1:
 cron_cursor();
 clean_PS2();
 break;
 case 2:
 Glcd_Write_Text("PLAY",30,7,1);
 T1CONBits.TON=1;
 break;
 case 3:
 Glcd_Write_Text("pause",30,7,1);
 T1CONBits.TON=0;
 break;
 case 4:
 Glcd_Write_Text("RESET",30,7,1);

 break;
 case 5:
 Glcd_Write_Text("ALARM",30,7,1);

 break;
 }
 }
}

void frecuencia_pantalla (){
 Glcd_Write_Text("Frecu.(hz)", 0, 1, 1);
 Glcd_Write_Text("Periodo(us)", 65, 1, 1);
 floattostr(frecuencia,txt);
 Glcd_Write_Text(txt,5, 2, 1);
 floattostr(frecuencia2,txt);
 Glcd_Write_Text(txt,5, 3, 1);
 floattostr(frecuencia3,txt);
 Glcd_Write_Text(txt,5, 4, 1);
 floattostr(frecuencia4,txt);
 Glcd_Write_Text(txt,5, 5, 1);
 floattostr(T1,txt);
 Glcd_Write_Text(txt,65, 2, 1);
 floattostr(T2,txt);
 Glcd_Write_Text(txt,65, 3, 1);
 floattostr(T3,txt);
 Glcd_Write_Text(txt,65, 4, 1);
 floattostr(T4,txt);
 Glcd_Write_Text(txt,65, 5, 1);
}
void caso_2(){
 config_captura();
 T2CONbits.TON=1;
 Glcd_Fill(0);
 while(keydata!= 118 ){
 frecuencia_pantalla();
 Glcd_Write_TEXT("c2" ,10,7,1);delay_ms(1000);




 Ps2_Key_Read(&keydata, &special, &down);
 }
}

void caso_3(){
 texto_caso_3();
 T5CONbits.TON=1;
 T4CONbits.TON=1;
 delay_ms(300);
 while(keydata!= 118 ){
 Ps2_Key_Read(&keydata, &special, &down);
 }
 T5CONbits.TON=0;
 T4CONbits.TON=0;
}

void main(){
 config_IO(); config_LCD();
 config_INT();

 config_OC();
 config_TMR_45();

 config_pin();


 Glcd_Fill(0);

 PS2_Config(); Glcd_Fill(0);
 while(1){
 texto_menu();
 selected=cursor_menu(3);
 switch(selected){
 case 1:
 clean_PS2();
 texto_caso_1();
 caso_1();
 break;
 case 2:
 clean_PS2();

 caso_2();
 break;
 case 3:
 clean_PS2();
 texto_caso_3();
 caso_3();
 break;
 }
 }
}
