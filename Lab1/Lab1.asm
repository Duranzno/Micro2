
_barras:

;barras.h,15 :: 		void barras(Bars interrupcion,int bar_counter) {
;barras.h,16 :: 		switch(interrupcion){
	PUSH	W10
	GOTO	L_barras0
;barras.h,17 :: 		case Int0:
L_barras2:
;barras.h,20 :: 		bar_drawer(BARS_H_LOCATIONS[Int0],bar_counter);
	CLR	W10
	CALL	_bar_drawer
;barras.h,21 :: 		break;
	GOTO	L_barras1
;barras.h,22 :: 		case Int1:
L_barras3:
;barras.h,23 :: 		bar_drawer(BARS_H_LOCATIONS[Int1],bar_counter);
	MOV.B	#1, W10
	CALL	_bar_drawer
;barras.h,24 :: 		break;
	GOTO	L_barras1
;barras.h,25 :: 		case Int2:
L_barras4:
;barras.h,26 :: 		bar_drawer(BARS_H_LOCATIONS[Int2],bar_counter) ;
	MOV.B	#2, W10
	CALL	_bar_drawer
;barras.h,27 :: 		break;
	GOTO	L_barras1
;barras.h,28 :: 		case Int3:
L_barras5:
;barras.h,29 :: 		bar_drawer(BARS_H_LOCATIONS[Int3],bar_counter);
	MOV.B	#3, W10
	CALL	_bar_drawer
;barras.h,30 :: 		break;
	GOTO	L_barras1
;barras.h,31 :: 		case Int4:
L_barras6:
;barras.h,32 :: 		bar_drawer(BARS_H_LOCATIONS[Int4],bar_counter);
	MOV.B	#4, W10
	CALL	_bar_drawer
;barras.h,33 :: 		break;
	GOTO	L_barras1
;barras.h,34 :: 		default:
L_barras7:
;barras.h,35 :: 		break;
	GOTO	L_barras1
;barras.h,36 :: 		}
L_barras0:
	CP.B	W10, #0
	BRA NZ	L__barras15
	GOTO	L_barras2
L__barras15:
	CP.B	W10, #1
	BRA NZ	L__barras16
	GOTO	L_barras3
L__barras16:
	CP.B	W10, #2
	BRA NZ	L__barras17
	GOTO	L_barras4
L__barras17:
	CP.B	W10, #3
	BRA NZ	L__barras18
	GOTO	L_barras5
L__barras18:
	CP.B	W10, #4
	BRA NZ	L__barras19
	GOTO	L_barras6
L__barras19:
	GOTO	L_barras7
L_barras1:
;barras.h,37 :: 		}
L_end_barras:
	POP	W10
	RETURN
; end of _barras

_bar_drawer:

;barras.h,38 :: 		void bar_drawer(unsigned short x_left,unsigned short bar_counter){
;barras.h,41 :: 		int x_right=x_left+BAR_WIDTH;
	PUSH	W11
	PUSH	W12
	PUSH	W13
	ZE	W10, W0
; x_right start address is: 8 (W4)
	ADD	W0, #5, W4
;barras.h,43 :: 		bar_counter=bar_counter%25   ;
	ZE	W11, W0
	MOV	#25, W2
	REPEAT	#17
	DIV.S	W0, W2
	MOV	W1, W0
	MOV.B	W0, W11
;barras.h,44 :: 		if (bar_counter==0){
	CP.B	W0, #0
	BRA Z	L__bar_drawer21
	GOTO	L_bar_drawer8
L__bar_drawer21:
;barras.h,46 :: 		Glcd_Box(x_left,MAX_BAR_HEIGHT,x_right,0,WHITE);
	CLR	W13
	MOV.B	W4, W12
; x_right end address is: 8 (W4)
	MOV.B	#125, W11
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
;barras.h,47 :: 		}
	GOTO	L_bar_drawer9
L_bar_drawer8:
;barras.h,50 :: 		y_bottom=DrawableBars(bar_counter)*BAR_HEIGHT;
; x_right start address is: 8 (W4)
	PUSH	W4
	PUSH	W10
	ZE	W11, W10
	CALL	_DrawableBars
	POP	W10
	POP	W4
	MOV	#5, W1
	MUL.SS	W0, W1, W2
;barras.h,51 :: 		y_top=y_bottom+BAR_HEIGHT;
	ADD	W2, #5, W0
;barras.h,52 :: 		Glcd_Box(x_left,y_top,x_right,y_bottom,BLACK);
	MOV.B	W2, W13
	MOV.B	W4, W12
; x_right end address is: 8 (W4)
	MOV.B	W0, W11
	MOV.B	#1, W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
;barras.h,53 :: 		}
L_bar_drawer9:
;barras.h,54 :: 		}
L_end_bar_drawer:
	POP	W13
	POP	W12
	POP	W11
	RETURN
; end of _bar_drawer

_DrawableBars:

;barras.h,55 :: 		int DrawableBars(int real_number_of_bars){
;barras.h,58 :: 		if(real_number_of_bars>25){
	PUSH	W11
	CP	W10, #25
	BRA GT	L__DrawableBars23
	GOTO	L_DrawableBars10
L__DrawableBars23:
;barras.h,59 :: 		int quotient=real_number_of_bars/25;
	MOV	#25, W2
	REPEAT	#17
	DIV.S	W10, W2
;barras.h,60 :: 		quotient=floor(quotient);
	PUSH	W10
	ASR	W0, #15, W1
	SETM	W2
	CALL	__Long2Float
	MOV.D	W0, W10
	CALL	_floor
	CALL	__Float2Longint
	POP	W10
;barras.h,61 :: 		return real_number_of_bars-25*quotient;
	MOV	#25, W1
	MUL.SS	W1, W0, W0
	SUB	W10, W0, W0
	GOTO	L_end_DrawableBars
;barras.h,62 :: 		}else{
L_DrawableBars10:
;barras.h,63 :: 		return real_number_of_bars;
	MOV	W10, W0
;barras.h,65 :: 		}
;barras.h,63 :: 		return real_number_of_bars;
;barras.h,65 :: 		}
L_end_DrawableBars:
	POP	W11
	RETURN
; end of _DrawableBars

_config_INT:

;Lab1.c,50 :: 		void config_INT(){
;Lab1.c,51 :: 		SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
	MOV	#lo_addr(SRbits), W0
	MOV.B	[W0], W1
	MOV.B	#31, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(SRbits), W0
	MOV.B	W1, [W0]
;Lab1.c,52 :: 		INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
	BCLR	INTCON1bits, #15
;Lab1.c,53 :: 		INTCON2bits.GIE=1; //interrupciones habilitadas
	BSET	INTCON2bits, #15
;Lab1.c,54 :: 		CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
	BCLR	CORCONbits, #3
;Lab1.c,56 :: 		IEC0bits.INT0IE=1; //HABILITA INTERRUPCION POR INT0
	BSET	IEC0bits, #0
;Lab1.c,57 :: 		IEC1bits.INT1IE=1; //HABILITA
	BSET	IEC1bits, #4
;Lab1.c,58 :: 		IEC1bits.INT2IE=1;
	BSET	IEC1bits, #13
;Lab1.c,59 :: 		IEC3bits.INT3IE=1;
	BSET	IEC3bits, #5
;Lab1.c,60 :: 		IEC3bits.INT4IE=1;
	BSET	IEC3bits, #6
;Lab1.c,62 :: 		INTCON2bits.INT0EP=0;
	BCLR	INTCON2bits, #0
;Lab1.c,63 :: 		INTCON2bits.INT1EP=0;
	BCLR	INTCON2bits, #1
;Lab1.c,64 :: 		INTCON2bits.INT2EP=0;
	BCLR	INTCON2bits, #2
;Lab1.c,65 :: 		INTCON2bits.INT3EP=0;
	BCLR	INTCON2bits, #3
;Lab1.c,66 :: 		INTCON2bits.INT4EP =0;
	BCLR	INTCON2bits, #4
;Lab1.c,68 :: 		IFS0bits.INT0IF=0; //interrupcion de INT0 ACTIVADA
	BCLR	IFS0bits, #0
;Lab1.c,69 :: 		IFS1bits.INT2IF =0; // interrupcion de INT1 ACTIVADA
	BCLR	IFS1bits, #13
;Lab1.c,70 :: 		IFS1bits.INT2IF =0 ; // INTERRIPCION DE INT2 ACTVADA
	BCLR	IFS1bits, #13
;Lab1.c,71 :: 		IFS3bits.INT3IF =0; //INTERRUPCION DE INT3 ACTIVADA
	BCLR	IFS3bits, #5
;Lab1.c,72 :: 		IFS3bits.INT4IF =0; // INTERRUPCION DE INT4 ACTIVADA
	BCLR	IFS3bits, #6
;Lab1.c,74 :: 		}
L_end_config_INT:
	RETURN
; end of _config_INT

_config_IO:

;Lab1.c,76 :: 		void config_IO(){
;Lab1.c,77 :: 		ANSELC=0; ANSELD=0; ANSELE=0;                  //ANALOGICO SON B Y F
	CLR	ANSELC
	CLR	ANSELD
	CLR	ANSELE
;Lab1.c,79 :: 		RPINR0bits.INT1R = 47;
	MOV	#12032, W0
	MOV	W0, W1
	MOV	#lo_addr(RPINR0bits), W0
	XOR	W1, [W0], W1
	MOV	#32512, W0
	AND	W1, W0, W1
	MOV	#lo_addr(RPINR0bits), W0
	XOR	W1, [W0], W1
	MOV	W1, RPINR0bits
;Lab1.c,80 :: 		RPINR1bits.INT2R = 46;
	MOV.B	#46, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#127, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPINR1bits), W0
	MOV.B	W1, [W0]
;Lab1.c,81 :: 		RPINR1bits.INT3R=  45;
	MOV	#11520, W0
	MOV	W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR	W1, [W0], W1
	MOV	#32512, W0
	AND	W1, W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, RPINR1bits
;Lab1.c,82 :: 		RPINR2bits.INT4R=  44;
	MOV.B	#44, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPINR2bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#127, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPINR2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPINR2bits), W0
	MOV.B	W1, [W0]
;Lab1.c,84 :: 		IPC0bits.INT0IP= 1;
	MOV.B	#1, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC0bits), W0
	MOV.B	W1, [W0]
;Lab1.c,85 :: 		IPC5BITS.INT1IP= 2;
	MOV.B	#2, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC5bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IPC5bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC5bits), W0
	MOV.B	W1, [W0]
;Lab1.c,86 :: 		IPC7bits.INT2IP =3;
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
;Lab1.c,87 :: 		IPC13bits.INT3IP=4;
	MOV.B	#64, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#112, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC13bits), W0
	MOV.B	W1, [W0]
;Lab1.c,88 :: 		IPC13bits.INT4IP=5;
	MOV	#1280, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR	W1, [W0], W1
	MOV	#1792, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC13bits
;Lab1.c,91 :: 		LATB = 0;              // Set PORTB to zero
	CLR	LATB
;Lab1.c,92 :: 		ANSELB = 0;
	CLR	ANSELB
;Lab1.c,93 :: 		TRISB = 0;             // Initialize PORTB as output
	CLR	TRISB
;Lab1.c,95 :: 		}
L_end_config_IO:
	RETURN
; end of _config_IO

_main:
	MOV	#2048, W15
	MOV	#6142, W0
	MOV	WREG, 32
	MOV	#1, W0
	MOV	WREG, 50
	MOV	#4, W0
	IOR	68

;Lab1.c,97 :: 		void main(){
;Lab1.c,98 :: 		config_INT();
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CALL	_config_INT
;Lab1.c,99 :: 		config_IO();
	CALL	_config_IO
;Lab1.c,102 :: 		Glcd_Init();
	CALL	_Glcd_Init
;Lab1.c,103 :: 		Glcd_Set_Font(font5x7 , 5, 7, 32);
	MOV	#___Lib_System_DefaultPage, W0
	MOV.B	#7, W13
	MOV.B	#5, W12
	MOV	#lo_addr(_font5x7), W10
	MOV	W0, W11
	MOV	#32, W0
	PUSH	W0
	CALL	_Glcd_Set_Font
	SUB	#2, W15
;Lab1.c,104 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,105 :: 		while(1){
L_main12:
;Lab1.c,106 :: 		LATB = ~LATB;        // Invert PORTB value
	COM	LATB
;Lab1.c,113 :: 		}
	GOTO	L_main12
;Lab1.c,114 :: 		}
L_end_main:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
