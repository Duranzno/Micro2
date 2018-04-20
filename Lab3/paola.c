//Variables de PS2
sbit PS2_Data at RF4_bit;
sbit PS2_Clock at RF5_bit;
sbit PS2_Data_Direction at TRISF4_bit;
sbit PS2_Clock_Direction at TRISF5_bit;
//Variables de GLCD
sbit GLCD_D0 at RD4_bit;
sbit GLCD_D1 at RD5_bit;
sbit GLCD_D2 at RD6_bit;
sbit GLCD_D3 at RD7_bit;
sbit GLCD_D4 at RF0_bit;
sbit GLCD_D5 at RF1_bit;
sbit GLCD_D6 at RE0_bit;
sbit GLCD_D7 at RE1_bit;
sbit GLCD_CS1 at LATE3_bit;
sbit GLCD_CS2 at LATE2_bit;
sbit GLCD_RS at LATD1_bit;
sbit GLCD_RW at LATD2_bit;
sbit GLCD_EN at LATD3_bit;
sbit GLCD_RST at LATC14_bit;

sbit GLCD_D0_Direction at TRISD4_bit;
sbit GLCD_D1_Direction at TRISD5_bit;
sbit GLCD_D2_Direction at TRISD6_bit;
sbit GLCD_D3_Direction at TRISD7_bit;
sbit GLCD_D4_Direction at TRISF0_bit;
sbit GLCD_D5_Direction at TRISF1_bit;
sbit GLCD_D6_Direction at TRISE0_bit;
sbit GLCD_D7_Direction at TRISE1_bit;
sbit GLCD_CS1_Direction at TRISE3_bit;
sbit GLCD_CS2_Direction at TRISE2_bit;
sbit GLCD_RS_Direction at TRISD1_bit;
sbit GLCD_RW_Direction at TRISD2_bit;
sbit GLCD_EN_Direction at TRISD3_bit;
sbit GLCD_RST_Direction at TRISC14_bit;

//____________________________________________________________________________________________________________________________________
//~~~~~~~~~~~~~~~~~~Constantes  del sistema~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned short keydata = 0, special = 0, down = 0;
unsigned adc_value;
 void config_LCD(){
  Glcd_Init();
  Glcd_set_Font(font5x7 , 5, 7, 32);
  Glcd_Fill(0);
  }
  void confi_PWM(){
  PTCONbits.PTEN=1;
  PWMCON4bits.FLTSTAT=1;
  PWMCON4bits.FLTIEN=1;
  PWMCON4bits.ITB=1;
  PWMCON4bits.CAM=1;
  PWMCON4bits.IUE=1;
  IOCON4bits.PENH=1;
  IOCON4bits.PENL=1;
  IOCON4bits.POLH=0;
  IOCON4bits.POLL=0;
  DTR3=100;
  PHASE4=10000; // periodo de 900us
  PDC4=10000; //100%

 }
   char txt[6];
void main() {
  ANSELC=0;
  ANSELD=0;
  ANSELE=0;
  ANSELB=0;
  ANSELBbits.ANSB5=1;

  
  RPINR13bits.FLT4R=64;

  config_LCD();
  PS2_Config();  Glcd_Fill(0);
   ADC1_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF); //Inicializacion del convertidor ADC

while(1){
    Glcd_Write_TEXT("Laboratorio 3",31,0,1);
    Glcd_Write_TEXT("'PRUEBA 1 ->o",0,1,1);

    if(Ps2_Key_Read(&keydata, &special, &down)){
       if(down &&!special){
              switch(keydata){
                case 'a':
                case 'o':
                  Glcd_Fill(0);
                  Glcd_Write_Text("PWM3",0,1,1);
                  confi_PWM();
                   adc_value = ADC1_Get_Sample(5);
                   if(adc_value<200){
                    PDC4=1000;
                    Glcd_Write_Text("SETENTA",0,1,1);}
                     //else if(200<adc_value<=400){                      PDC4=5000;Glcd_Write_Text("CINCUENTA",0,1,1); }
                      //else if(400<adc_value<700){
                     //  PDC4=2500; Glcd_Write_Text("VEINTE",0,1,1);}
                      // else if(adc_value>700){
                      //  PDC4=1000;Glcd_Write_Text("DIEZ",0,1,1);}
                   WordToStr(adc_value, txt);

                  Glcd_Write_Text(txt, 10, 3, 1);
                  adc_value=adc_value*4.96578;
                   WordToStr(adc_value, txt);
                   Glcd_Write_Text(txt, 10, 4, 1);
                  delay_ms(2000);
                  break;
                default:
                  Glcd_Fill(0);
                  Glcd_Write_TEXT("Erroneo ",60,0,1);
                  delay_ms(2000);
                  break;
                }
              }
            }


}
}