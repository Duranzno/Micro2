
_barras:

;barras.h,14 :: 		void barras(Bars interrupcion,int contador_barra) {
;barras.h,15 :: 		switch(interrupcion){
	PUSH	W10
	GOTO	L_barras0
;barras.h,16 :: 		case Int0:
L_barras2:
;barras.h,19 :: 		bar_drawer(BARS_H_LOCATIONS[Int0],contador_barra);
	CLR	W10
	CALL	_bar_drawer
;barras.h,20 :: 		break;
	GOTO	L_barras1
;barras.h,21 :: 		case Int1:
L_barras3:
;barras.h,22 :: 		bar_drawer(BARS_H_LOCATIONS[Int1],contador_barra);
	MOV.B	#1, W10
	CALL	_bar_drawer
;barras.h,23 :: 		break;
	GOTO	L_barras1
;barras.h,24 :: 		case Int2:
L_barras4:
;barras.h,25 :: 		bar_drawer(BARS_H_LOCATIONS[Int2],contador_barra) ;
	MOV.B	#2, W10
	CALL	_bar_drawer
;barras.h,26 :: 		break;
	GOTO	L_barras1
;barras.h,27 :: 		case Int3:
L_barras5:
;barras.h,28 :: 		bar_drawer(BARS_H_LOCATIONS[Int3],contador_barra);
	MOV.B	#3, W10
	CALL	_bar_drawer
;barras.h,29 :: 		break;
	GOTO	L_barras1
;barras.h,30 :: 		case Int4:
L_barras6:
;barras.h,31 :: 		bar_drawer(BARS_H_LOCATIONS[Int4],contador_barra);
	MOV.B	#4, W10
	CALL	_bar_drawer
;barras.h,32 :: 		break;
	GOTO	L_barras1
;barras.h,33 :: 		default:
L_barras7:
;barras.h,34 :: 		break;
	GOTO	L_barras1
;barras.h,35 :: 		}
L_barras0:
	CP.B	W10, #0
	BRA NZ	L__barras31
	GOTO	L_barras2
L__barras31:
	CP.B	W10, #1
	BRA NZ	L__barras32
	GOTO	L_barras3
L__barras32:
	CP.B	W10, #2
	BRA NZ	L__barras33
	GOTO	L_barras4
L__barras33:
	CP.B	W10, #3
	BRA NZ	L__barras34
	GOTO	L_barras5
L__barras34:
	CP.B	W10, #4
	BRA NZ	L__barras35
	GOTO	L_barras6
L__barras35:
	GOTO	L_barras7
L_barras1:
;barras.h,36 :: 		}
L_end_barras:
	POP	W10
	RETURN
; end of _barras

_bar_drawer:
	LNK	#2

;barras.h,37 :: 		void bar_drawer(unsigned short x_left,unsigned short contador_barra){
;barras.h,40 :: 		int x_right=x_left+BAR_WIDTH;
	PUSH	W11
	PUSH	W12
	PUSH	W13
	ZE	W10, W1
	ADD	W14, #0, W0
	ADD	W1, #5, [W0]
;barras.h,42 :: 		int contador_reset=DrawableBars(contador_barra);
	PUSH.D	W10
	ZE	W11, W10
	CALL	_DrawableBars
	POP.D	W10
; contador_reset start address is: 0 (W0)
;barras.h,43 :: 		if(contador_barra>1){
	CP.B	W11, #1
	BRA GTU	L__bar_drawer37
	GOTO	L_bar_drawer8
L__bar_drawer37:
;barras.h,44 :: 		if (contador_reset==1){
	CP	W0, #1
	BRA Z	L__bar_drawer38
	GOTO	L_bar_drawer9
L__bar_drawer38:
; contador_reset end address is: 0 (W0)
;barras.h,46 :: 		Glcd_Box(x_left,MAX_BAR_HEIGHT,x_right,BAR_HEIGHT,WHITE);
	MOV.B	#4, W13
	MOV.B	[W14+0], W12
	MOV.B	#100, W11
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
;barras.h,47 :: 		}
	GOTO	L_bar_drawer10
L_bar_drawer9:
;barras.h,50 :: 		y_bottom=DrawableBars(contador_barra)*BAR_HEIGHT;
	PUSH	W10
	ZE	W11, W10
	CALL	_DrawableBars
	POP	W10
	SL	W0, #2, W1
;barras.h,51 :: 		y_top=y_bottom+BAR_HEIGHT;
	ADD	W1, #4, W0
;barras.h,52 :: 		Glcd_Box(x_left,y_top,x_right,y_bottom,BLACK);
	MOV.B	W1, W13
	MOV.B	[W14+0], W12
	MOV.B	W0, W11
	MOV.B	#1, W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
;barras.h,53 :: 		}
L_bar_drawer10:
;barras.h,54 :: 		}
L_bar_drawer8:
;barras.h,55 :: 		}
L_end_bar_drawer:
	POP	W13
	POP	W12
	POP	W11
	ULNK
	RETURN
; end of _bar_drawer

_DrawableBars:

;barras.h,56 :: 		int DrawableBars(int real_number_of_bars){
;barras.h,59 :: 		if(real_number_of_bars>25){
	PUSH	W11
	CP	W10, #25
	BRA GT	L__DrawableBars40
	GOTO	L_DrawableBars11
L__DrawableBars40:
;barras.h,60 :: 		int quotient=real_number_of_bars/25;
	MOV	#25, W2
	REPEAT	#17
	DIV.S	W10, W2
;barras.h,61 :: 		quotient=floor(quotient);
	PUSH	W10
	ASR	W0, #15, W1
	SETM	W2
	CALL	__Long2Float
	MOV.D	W0, W10
	CALL	_floor
	CALL	__Float2Longint
	POP	W10
;barras.h,62 :: 		return real_number_of_bars-25*quotient;
	MOV	#25, W1
	MUL.SS	W1, W0, W0
	SUB	W10, W0, W0
	GOTO	L_end_DrawableBars
;barras.h,63 :: 		}else{
L_DrawableBars11:
;barras.h,64 :: 		return real_number_of_bars;
	MOV	W10, W0
;barras.h,66 :: 		}
;barras.h,64 :: 		return real_number_of_bars;
;barras.h,66 :: 		}
L_end_DrawableBars:
	POP	W11
	RETURN
; end of _DrawableBars

_config_INT:

;Lab1.c,41 :: 		void config_INT(){
;Lab1.c,42 :: 		SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
	MOV	#lo_addr(SRbits), W0
	MOV.B	[W0], W1
	MOV.B	#31, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(SRbits), W0
	MOV.B	W1, [W0]
;Lab1.c,43 :: 		INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
	BCLR	INTCON1bits, #15
;Lab1.c,44 :: 		INTCON2bits.GIE=1; //interrupciones habilitadas
	BSET	INTCON2bits, #15
;Lab1.c,45 :: 		CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
	BCLR	CORCONbits, #3
;Lab1.c,47 :: 		IEC0bits.INT0IE=1; //HABILITA INTERRUPCION POR INT0
	BSET	IEC0bits, #0
;Lab1.c,48 :: 		IEC1bits.INT1IE=1; //HABILITA
	BSET	IEC1bits, #4
;Lab1.c,49 :: 		IEC1bits.INT2IE=1;
	BSET	IEC1bits, #13
;Lab1.c,50 :: 		IEC3bits.INT3IE=1;
	BSET	IEC3bits, #5
;Lab1.c,51 :: 		IEC3bits.INT4IE=1;
	BSET	IEC3bits, #6
;Lab1.c,53 :: 		IFS0bits.INT0IF=0; //interrupcion de INT0 ACTIVADA
	BCLR	IFS0bits, #0
;Lab1.c,54 :: 		IFS1bits.INT2IF =0; // interrupcion de INT1 ACTIVADA
	BCLR	IFS1bits, #13
;Lab1.c,55 :: 		IFS1bits.INT2IF =0 ; // INTERRIPCION DE INT2 ACTVADA
	BCLR	IFS1bits, #13
;Lab1.c,56 :: 		IFS3bits.INT3IF =0; //INTERRUPCION DE INT3 ACTIVADA
	BCLR	IFS3bits, #5
;Lab1.c,57 :: 		IFS3bits.INT4IF =0; // INTERRUPCION DE INT4 ACTIVADA
	BCLR	IFS3bits, #6
;Lab1.c,59 :: 		IPC0bits.INT0IP= 5;
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC0bits), W0
	MOV.B	W1, [W0]
;Lab1.c,60 :: 		IPC5BITS.INT1IP= 4;
	MOV.B	#4, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC5bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IPC5bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC5bits), W0
	MOV.B	W1, [W0]
;Lab1.c,61 :: 		IPC7bits.INT2IP =3;
	MOV.B	#48, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC7bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#112, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC7bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC7bits), W0
	MOV.B	W1, [W0]
;Lab1.c,62 :: 		IPC13bits.INT3IP=2;
	MOV.B	#32, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#112, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC13bits), W0
	MOV.B	W1, [W0]
;Lab1.c,63 :: 		IPC13bits.INT4IP=1;
	MOV	#256, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR	W1, [W0], W1
	MOV	#1792, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC13bits
;Lab1.c,65 :: 		INTCON2bits.INT0EP=0;
	BCLR	INTCON2bits, #0
;Lab1.c,66 :: 		INTCON2bits.INT1EP=0;
	BCLR	INTCON2bits, #1
;Lab1.c,67 :: 		INTCON2bits.INT2EP=0;
	BCLR	INTCON2bits, #2
;Lab1.c,68 :: 		INTCON2bits.INT3EP=0;
	BCLR	INTCON2bits, #3
;Lab1.c,69 :: 		INTCON2bits.INT4EP =0;
	BCLR	INTCON2bits, #4
;Lab1.c,70 :: 		}
L_end_config_INT:
	RETURN
; end of _config_INT

_config_IO:

;Lab1.c,78 :: 		void config_IO(){
;Lab1.c,80 :: 		ANSELB=0;
	CLR	ANSELB
;Lab1.c,81 :: 		ANSELC=0; ANSELD=0; ANSELE=0;                  //ANALOGICO SON B Y F
	CLR	ANSELC
	CLR	ANSELD
	CLR	ANSELE
;Lab1.c,87 :: 		RPINR0bits.INT1R = BTN_PPS_LOCATIONS[1];//El Periferico INT1 esta en el pin 47
	MOV	#9472, W0
	MOV	W0, W1
	MOV	#lo_addr(RPINR0bits), W0
	XOR	W1, [W0], W1
	MOV	#32512, W0
	AND	W1, W0, W1
	MOV	#lo_addr(RPINR0bits), W0
	XOR	W1, [W0], W1
	MOV	W1, RPINR0bits
;Lab1.c,88 :: 		RPINR1bits.INT2R = BTN_PPS_LOCATIONS[2];
	MOV.B	#36, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#127, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPINR1bits), W0
	MOV.B	W1, [W0]
;Lab1.c,89 :: 		RPINR1bits.INT3R=  BTN_PPS_LOCATIONS[3];
	MOV	#8960, W0
	MOV	W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR	W1, [W0], W1
	MOV	#32512, W0
	AND	W1, W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, RPINR1bits
;Lab1.c,90 :: 		RPINR2bits.INT4R=  BTN_PPS_LOCATIONS[4];
	MOV.B	#34, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPINR2bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#127, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPINR2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPINR2bits), W0
	MOV.B	W1, [W0]
;Lab1.c,92 :: 		}
L_end_config_IO:
	RETURN
; end of _config_IO

_config_CN:

;Lab1.c,94 :: 		void config_CN(){
;Lab1.c,96 :: 		TRISB = 0;
	CLR	TRISB
;Lab1.c,97 :: 		CNENBbits.CNIEB0=1;
	BSET	CNENBbits, #0
;Lab1.c,98 :: 		CNENBbits.CNIEB1=1;
	BSET	CNENBbits, #1
;Lab1.c,99 :: 		CNENBbits.CNIEB6=1;
	BSET	CNENBbits, #6
;Lab1.c,100 :: 		CNENBbits.CNIEB7=1;
	BSET	CNENBbits, #7
;Lab1.c,101 :: 		CNENBbits.CNIEB8=1;
	BSET	CNENBbits, #8
;Lab1.c,103 :: 		CNPUBbits.CNPUB0=1;
	BSET	CNPUBbits, #0
;Lab1.c,104 :: 		CNPUBbits.CNPUB1=1;
	BSET	CNPUBbits, #1
;Lab1.c,105 :: 		CNPUBbits.CNPUB6=1;
	BSET	CNPUBbits, #6
;Lab1.c,106 :: 		CNPUBbits.CNPUB7=1;
	BSET	CNPUBbits, #7
;Lab1.c,107 :: 		CNPUBbits.CNPUB8=1;
	BSET	CNPUBbits, #8
;Lab1.c,109 :: 		IFS1bits.CNIF=0;
	BCLR	IFS1bits, #3
;Lab1.c,110 :: 		IEC1bits.CNIE=1;//Resset Interrupcion
	BSET	IEC1bits, #3
;Lab1.c,114 :: 		}
L_end_config_CN:
	RETURN
; end of _config_CN

_config_LCD:

;Lab1.c,115 :: 		void config_LCD(){
;Lab1.c,116 :: 		Glcd_Init();
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CALL	_Glcd_Init
;Lab1.c,117 :: 		Glcd_Set_Font(font5x7 , 5, 7, 32);
	MOV	#___Lib_System_DefaultPage, W0
	MOV.B	#7, W13
	MOV.B	#5, W12
	MOV	#lo_addr(_font5x7), W10
	MOV	W0, W11
	MOV	#32, W0
	PUSH	W0
	CALL	_Glcd_Set_Font
	SUB	#2, W15
;Lab1.c,118 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,119 :: 		}
L_end_config_LCD:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _config_LCD

_main:
	MOV	#2048, W15
	MOV	#6142, W0
	MOV	WREG, 32
	MOV	#1, W0
	MOV	WREG, 50
	MOV	#4, W0
	IOR	68

;Lab1.c,121 :: 		void main(){
;Lab1.c,122 :: 		config_INT();
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CALL	_config_INT
;Lab1.c,123 :: 		config_IO();
	CALL	_config_IO
;Lab1.c,125 :: 		config_LCD();
	CALL	_config_LCD
;Lab1.c,127 :: 		while(1){
L_main13:
;Lab1.c,134 :: 		if (RCONbits.WDTO==1)
	BTSS	RCONbits, #4
	GOTO	L_main15
;Lab1.c,136 :: 		Glcd_PartialImage(63,40,30,20,30,20,kirby_1);  delay_ms(500);
	MOV	#20, W13
	MOV	#30, W12
	MOV	#40, W11
	MOV	#63, W10
	MOV	#lo_addr(_kirby_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#20, W0
	PUSH	W0
	MOV	#30, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
	MOV	#8, W8
	MOV	#41252, W7
L_main16:
	DEC	W7
	BRA NZ	L_main16
	DEC	W8
	BRA NZ	L_main16
;Lab1.c,138 :: 		Glcd_Write_TEXT("WDT",0,1,BLACK);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr1_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,139 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_main18:
	DEC	W7
	BRA NZ	L_main18
	DEC	W8
	BRA NZ	L_main18
;Lab1.c,140 :: 		RCONbits.WDTO=0;
	BCLR	RCONbits, #4
;Lab1.c,141 :: 		}
L_main15:
;Lab1.c,142 :: 		if(RCONbits.EXTR==1)
	BTSS	RCONbits, #7
	GOTO	L_main20
;Lab1.c,144 :: 		Glcd_PartialImage(63,40,30,20,30,20,kirby_3);  delay_ms(500);
	MOV	#20, W13
	MOV	#30, W12
	MOV	#40, W11
	MOV	#63, W10
	MOV	#lo_addr(_kirby_3), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#20, W0
	PUSH	W0
	MOV	#30, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
	MOV	#8, W8
	MOV	#41252, W7
L_main21:
	DEC	W7
	BRA NZ	L_main21
	DEC	W8
	BRA NZ	L_main21
;Lab1.c,146 :: 		Glcd_Write_TEXT("MCLR",0,2,BLACK);     delay_ms(500);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr2_Lab1), W10
	CALL	_Glcd_Write_Text
	MOV	#8, W8
	MOV	#41252, W7
L_main23:
	DEC	W7
	BRA NZ	L_main23
	DEC	W8
	BRA NZ	L_main23
;Lab1.c,147 :: 		RCONbits.EXTR=0;
	BCLR	RCONbits, #7
;Lab1.c,148 :: 		}
L_main20:
;Lab1.c,149 :: 		if (RCONbits.POR==1)
	BTSS	RCONbits, #0
	GOTO	L_main25
;Lab1.c,151 :: 		Glcd_PartialImage(63,40,30,20,30,20,kirby_2);  delay_ms(500);
	MOV	#20, W13
	MOV	#30, W12
	MOV	#40, W11
	MOV	#63, W10
	MOV	#lo_addr(_kirby_2), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#20, W0
	PUSH	W0
	MOV	#30, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
	MOV	#8, W8
	MOV	#41252, W7
L_main26:
	DEC	W7
	BRA NZ	L_main26
	DEC	W8
	BRA NZ	L_main26
;Lab1.c,153 :: 		Glcd_Write_TEXT("POR",0,3,BLACK);  delay_ms(500);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr3_Lab1), W10
	CALL	_Glcd_Write_Text
	MOV	#8, W8
	MOV	#41252, W7
L_main28:
	DEC	W7
	BRA NZ	L_main28
	DEC	W8
	BRA NZ	L_main28
;Lab1.c,154 :: 		RCONbits.POR=0;
	BCLR	RCONbits, #0
;Lab1.c,156 :: 		}
L_main25:
;Lab1.c,160 :: 		}
	GOTO	L_main13
;Lab1.c,164 :: 		}
L_end_main:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
