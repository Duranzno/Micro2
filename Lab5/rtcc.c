int year=0, mesydia=0, diasyhora=0, minyseg=0;
// Glcd module connections
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
// End Glcd module connections
int year=0X0001, mesydia=0X0101, diasyhora=0X0101, minyseg=0X0000;
int mesydiaA=0X1028, diasyhoraA=0X0110, minysegA=0X0000;
Void RTCC_assembler ()
{
asm {MOV # 0x55, W0}
asm {MOV W0, NVMKEY }
asm {MOV # 0xAA, W0 }
asm {MOV W0, NVMKEY }
asm {BSET RCFGCAL, # RTCWREN;}// Setea el bit RTCWREN
; **********************************************
RCFGCALbits.RTCEN = 0; Limpia bit RTCEN , desactiva modulo
ALCFGRPTbits.ALRMEN=0; //desactivar alarma
; **********************************************
; Escribe a Timer RTCC
; **********************************************
RCFGCALbits.RTCOE = 1; // habilita el pulso de salida RTCC
PADCFG1bits.RTSECSEL = 0; // salida de la alarma
//Configura la fecha y hora al RTC
RCFGCALbits.RTCPTR = 3;
RTCVAL = year;
RTCVAL = mesydia;
RTCVAL = diasyhora;
RTCVAL = minyseg;
RCFGCALbits.RTCEN = 1; // activa modulo
RCFGCALbits.RTCWREN = 0; // deshabilita escritura en RTCC
delay_ms(1000);
}
}
void main()
{
ANSELC=0;
ANSELD=0;
ANSELE=0;
ANSELB=0;
OSCCONbits.LPOSCEN=1; //activa el oscilador secundario
RTCC_assembler(); // inicializa escritura RTCC y graba valores iniciales
PADCFG1bits.RTSECSEL=1; // habilita salida de reloj a un segundo
RCFGCALbits.CAL=1; //ajusta a cero
RCFGCALbits.RTCOE=1; // habilita el pin RTCC ( se puede usar para
verificar que el RTCC está funcionando )
Keypad_Init();
Glcd_Init();
Glcd_Set_Font(character8x7 , 8, 7, 32);
Glcd_Fill(0);
Glcd_Write_Text(“Reloj Digital:", 0, 2, 1);
while(1)
{
while(RCFGCALbits.RTCSYNC==0)
{RCFGCALbits.RTCPTR=3;
year=RTCVAL;
mesydia=RTCVAL;
diasyhora=RTCVAL;
minyseg=RTCVAL;
// transforma de bcd a decimal
anio= Bcd2Dec( year & 0x00FF );
mes= Bcd2Dec((mesydia & 0xFF00)>>8 );
dia= Bcd2Dec( mesydia & 0x00FF );
hora= Bcd2Dec( diasyhora & 0x00FF );
minn= Bcd2Dec((minyseg & 0xFF00)>>8 );
seg= Bcd2Dec( minyseg & 0x00FF );
shortToStr(anio, texanio);
shortToStr(mes, textmes);
shortToStr(dia, textdia);
shortToStr(hora, texthora);
shortToStr(minn, textminn);
shortToStr(seg, textseg);
Glcd_Write_Char(txtanio, 1, 4, 1); //ordenar
Glcd_Write_Char(txtmes, 2, 4, 1);// ordenar
Glcd_Write_Char(txtdia, 3, 4, 1);//ordenar
Glcd_Write_Char(txthora, 4, 4, 1);//ordenar
Glcd_Write_Char(txtminn, 5, 4, 1);//ordenar
Glcd_Write_Char(txtseg, 6, 4, 1);//ordenar
}
}
}