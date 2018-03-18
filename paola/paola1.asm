
_casoC:

;paola1.c,60 :: 		void casoC(){
;paola1.c,61 :: 		Glcd_Write_TEXT("Ultimo Reset",60,0,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr1_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,62 :: 		do{
L_casoC0:
;paola1.c,63 :: 		if (RCONbits.WDTO==1){
	BTSS	RCONbits, #4
	GOTO	L_casoC3
;paola1.c,64 :: 		Glcd_Write_TEXT("WDT",0,1,BLACK);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr2_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,65 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_casoC4:
	DEC	W7
	BRA NZ	L_casoC4
	DEC	W8
	BRA NZ	L_casoC4
;paola1.c,66 :: 		RCONbits.WDTO=0;
	BCLR	RCONbits, #4
;paola1.c,67 :: 		}else if(RCONbits.EXTR==1){
	GOTO	L_casoC6
L_casoC3:
	BTSS	RCONbits, #7
	GOTO	L_casoC7
;paola1.c,68 :: 		Glcd_Write_TEXT("MCLR",0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr3_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,69 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_casoC8:
	DEC	W7
	BRA NZ	L_casoC8
	DEC	W8
	BRA NZ	L_casoC8
;paola1.c,70 :: 		RCONbits.EXTR=0;
	BCLR	RCONbits, #7
;paola1.c,71 :: 		}else if (RCONbits.POR==1){
	GOTO	L_casoC10
L_casoC7:
	BTSS	RCONbits, #0
	GOTO	L_casoC11
;paola1.c,72 :: 		Glcd_Write_TEXT("POR",0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr4_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,73 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_casoC12:
	DEC	W7
	BRA NZ	L_casoC12
	DEC	W8
	BRA NZ	L_casoC12
;paola1.c,74 :: 		RCONbits.POR=0;
	BCLR	RCONbits, #0
;paola1.c,75 :: 		}
L_casoC11:
L_casoC10:
L_casoC6:
;paola1.c,76 :: 		while(Ps2_Key_Read(&keydata, &special, &down));
L_casoC14:
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	CP0	W0
	BRA NZ	L__casoC48
	GOTO	L_casoC15
L__casoC48:
	GOTO	L_casoC14
L_casoC15:
;paola1.c,77 :: 		}while(op!=34);
	MOV	#34, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA Z	L__casoC49
	GOTO	L_casoC0
L__casoC49:
;paola1.c,78 :: 		op='c';
	MOV	#99, W0
	MOV	W0, _op
;paola1.c,79 :: 		}
L_end_casoC:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _casoC

_main:
	MOV	#2048, W15
	MOV	#6142, W0
	MOV	WREG, 32
	MOV	#1, W0
	MOV	WREG, 50
	MOV	#4, W0
	IOR	68

;paola1.c,80 :: 		void main(){
;paola1.c,81 :: 		ANSELC=0; ANSELD=0; ANSELE=0;                  //ANALOGICO SON B Y F
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CLR	ANSELC
	CLR	ANSELD
	CLR	ANSELE
;paola1.c,85 :: 		LATB = 0;              // Set PORTB to zero
	CLR	LATB
;paola1.c,86 :: 		ANSELB = 0;
	CLR	ANSELB
;paola1.c,87 :: 		TRISB = 0;             // Initialize PORTB as output
	CLR	TRISB
;paola1.c,88 :: 		Glcd_Init();
	CALL	_Glcd_Init
;paola1.c,89 :: 		Glcd_Set_Font(font5x7 , 5, 7, 32);
	MOV.B	#7, W13
	MOV.B	#5, W12
	MOV	#lo_addr(_font5x7), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	MOV	#32, W0
	PUSH	W0
	CALL	_Glcd_Set_Font
	SUB	#2, W15
;paola1.c,90 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;paola1.c,91 :: 		PS2_Config();
	CALL	_Ps2_Config
;paola1.c,92 :: 		Glcd_Write_TEXT("Laboratorio 1",31,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#31, W11
	MOV	#lo_addr(?lstr5_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,93 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main16:
	DEC	W7
	BRA NZ	L_main16
	DEC	W8
	BRA NZ	L_main16
	NOP
	NOP
	NOP
	NOP
;paola1.c,94 :: 		while(1){
L_main18:
;paola1.c,95 :: 		LATB = ~LATB; // Invert PORTB value
	COM	LATB
;paola1.c,96 :: 		Glcd_Write_TEXT("Laboratorio 1",31,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#31, W11
	MOV	#lo_addr(?lstr6_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,97 :: 		Glcd_Image(camion);
	MOV	#lo_addr(_camion), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	CALL	_Glcd_Image
;paola1.c,98 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main20:
	DEC	W7
	BRA NZ	L_main20
	DEC	W8
	BRA NZ	L_main20
	NOP
	NOP
	NOP
	NOP
;paola1.c,99 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;paola1.c,100 :: 		Glcd_Write_TEXT("Presione 'A' para Caso 1",0,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr7_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,101 :: 		Glcd_Write_TEXT("Presione 'B' para Caso 2",0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr8_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,102 :: 		Glcd_Write_TEXT("Presione 'C' para Caso 3",0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr9_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,103 :: 		Glcd_Write_TEXT("Presione 'D' para WDT   ",0,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	CLR	W11
	MOV	#lo_addr(?lstr10_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,104 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main22:
	DEC	W7
	BRA NZ	L_main22
	DEC	W8
	BRA NZ	L_main22
	NOP
	NOP
	NOP
	NOP
;paola1.c,106 :: 		while(op!=34){
L_main24:
	MOV	#34, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main51
	GOTO	L_main25
L__main51:
;paola1.c,107 :: 		if(Ps2_Key_Read(&keydata, &special, &down)){
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	CP0	W0
	BRA NZ	L__main52
	GOTO	L_main26
L__main52:
;paola1.c,108 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;paola1.c,109 :: 		switch(op){
	GOTO	L_main27
;paola1.c,110 :: 		case 'a':
L_main29:
;paola1.c,111 :: 		Glcd_Write_TEXT("Caso A",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr11_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,112 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main30:
	DEC	W7
	BRA NZ	L_main30
	DEC	W8
	BRA NZ	L_main30
	NOP
	NOP
	NOP
	NOP
;paola1.c,113 :: 		op=keydata;
	MOV	#lo_addr(_keydata), W0
	ZE	[W0], W0
	MOV	W0, _op
;paola1.c,114 :: 		break;
	GOTO	L_main28
;paola1.c,116 :: 		case 'b':
L_main32:
;paola1.c,117 :: 		Glcd_Write_TEXT("Caso B ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr12_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,118 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main33:
	DEC	W7
	BRA NZ	L_main33
	DEC	W8
	BRA NZ	L_main33
	NOP
	NOP
	NOP
	NOP
;paola1.c,119 :: 		op=keydata;
	MOV	#lo_addr(_keydata), W0
	ZE	[W0], W0
	MOV	W0, _op
;paola1.c,120 :: 		break;
	GOTO	L_main28
;paola1.c,122 :: 		case 'c':
L_main35:
;paola1.c,123 :: 		Glcd_Write_TEXT("Caso C ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr13_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,124 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main36:
	DEC	W7
	BRA NZ	L_main36
	DEC	W8
	BRA NZ	L_main36
	NOP
	NOP
	NOP
	NOP
;paola1.c,125 :: 		casoC();
	CALL	_casoC
;paola1.c,126 :: 		op=keydata;
	MOV	#lo_addr(_keydata), W0
	ZE	[W0], W0
	MOV	W0, _op
;paola1.c,127 :: 		break;
	GOTO	L_main28
;paola1.c,129 :: 		case 'd':
L_main38:
;paola1.c,130 :: 		Glcd_Write_TEXT("Caso D ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr14_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,131 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main39:
	DEC	W7
	BRA NZ	L_main39
	DEC	W8
	BRA NZ	L_main39
	NOP
	NOP
	NOP
	NOP
;paola1.c,132 :: 		op=keydata;
	MOV	#lo_addr(_keydata), W0
	ZE	[W0], W0
	MOV	W0, _op
;paola1.c,133 :: 		break;
	GOTO	L_main28
;paola1.c,135 :: 		case 34:
L_main41:
;paola1.c,136 :: 		Glcd_Write_TEXT("Menu Principal ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr15_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,137 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main42:
	DEC	W7
	BRA NZ	L_main42
	DEC	W8
	BRA NZ	L_main42
	NOP
	NOP
	NOP
	NOP
;paola1.c,138 :: 		op=keydata;
	MOV	#lo_addr(_keydata), W0
	ZE	[W0], W0
	MOV	W0, _op
;paola1.c,139 :: 		break;
	GOTO	L_main28
;paola1.c,140 :: 		default:
L_main44:
;paola1.c,141 :: 		Glcd_Write_TEXT("Erroneo ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr16_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,142 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main45:
	DEC	W7
	BRA NZ	L_main45
	DEC	W8
	BRA NZ	L_main45
	NOP
	NOP
	NOP
	NOP
;paola1.c,143 :: 		break;
	GOTO	L_main28
;paola1.c,144 :: 		}
L_main27:
	MOV	#97, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main53
	GOTO	L_main29
L__main53:
	MOV	#98, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main54
	GOTO	L_main32
L__main54:
	MOV	#99, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main55
	GOTO	L_main35
L__main55:
	MOV	#100, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main56
	GOTO	L_main38
L__main56:
	MOV	#34, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main57
	GOTO	L_main41
L__main57:
	GOTO	L_main44
L_main28:
;paola1.c,145 :: 		}
L_main26:
;paola1.c,146 :: 		}
	GOTO	L_main24
L_main25:
;paola1.c,147 :: 		}
	GOTO	L_main18
;paola1.c,148 :: 		}
L_end_main:
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
