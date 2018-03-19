
_animate_charmander:

;paola1.c,33 :: 		void animate_charmander(){
;paola1.c,35 :: 		Glcd_Image(charmander_1);
	PUSH	W10
	PUSH	W11
	MOV	#___Lib_System_DefaultPage, W0
	MOV	#lo_addr(_charmander_1), W10
	MOV	W0, W11
	CALL	_Glcd_Image
;paola1.c,36 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_animate_charmander0:
	DEC	W7
	BRA NZ	L_animate_charmander0
	DEC	W8
	BRA NZ	L_animate_charmander0
;paola1.c,38 :: 		Glcd_Image(charmander_2);
	MOV	#___Lib_System_DefaultPage, W0
	MOV	#lo_addr(_charmander_2), W10
	MOV	W0, W11
	CALL	_Glcd_Image
;paola1.c,39 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_animate_charmander2:
	DEC	W7
	BRA NZ	L_animate_charmander2
	DEC	W8
	BRA NZ	L_animate_charmander2
;paola1.c,40 :: 		}
L_end_animate_charmander:
	POP	W11
	POP	W10
	RETURN
; end of _animate_charmander

_config_IO:

;paola1.c,96 :: 		void config_IO(){
;paola1.c,97 :: 		ANSELB=0;
	CLR	ANSELB
;paola1.c,98 :: 		ANSELC=0;
	CLR	ANSELC
;paola1.c,99 :: 		ANSELD=0;
	CLR	ANSELD
;paola1.c,100 :: 		ANSELE=0;
	CLR	ANSELE
;paola1.c,101 :: 		ANSELG=0;             //ANALOGICO SON B Y F
	CLR	ANSELG
;paola1.c,103 :: 		TRISB = 1;
	MOV	#1, W0
	MOV	WREG, TRISB
;paola1.c,104 :: 		TRISE=0;
	CLR	TRISE
;paola1.c,105 :: 		TRISG=0;
	CLR	TRISG
;paola1.c,108 :: 		}
L_end_config_IO:
	RETURN
; end of _config_IO

_casoC:

;paola1.c,109 :: 		void casoC(){
;paola1.c,110 :: 		Glcd_Write_TEXT("Ultimo Reset",60,0,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr1_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,111 :: 		do{
L_casoC4:
;paola1.c,112 :: 		if (RCONbits.WDTO==1){
	BTSS	RCONbits, #4
	GOTO	L_casoC7
;paola1.c,113 :: 		Glcd_Write_TEXT("WDT",0,1,BLACK);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr2_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,114 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_casoC8:
	DEC	W7
	BRA NZ	L_casoC8
	DEC	W8
	BRA NZ	L_casoC8
;paola1.c,115 :: 		RCONbits.WDTO=0;
	BCLR	RCONbits, #4
;paola1.c,116 :: 		}else if(RCONbits.EXTR==1){
	GOTO	L_casoC10
L_casoC7:
	BTSS	RCONbits, #7
	GOTO	L_casoC11
;paola1.c,117 :: 		Glcd_Write_TEXT("MCLR",0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr3_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,118 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_casoC12:
	DEC	W7
	BRA NZ	L_casoC12
	DEC	W8
	BRA NZ	L_casoC12
;paola1.c,119 :: 		RCONbits.EXTR=0;
	BCLR	RCONbits, #7
;paola1.c,120 :: 		}else if (RCONbits.POR==1){
	GOTO	L_casoC14
L_casoC11:
	BTSS	RCONbits, #0
	GOTO	L_casoC15
;paola1.c,121 :: 		Glcd_Write_TEXT("POR",0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr4_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,122 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_casoC16:
	DEC	W7
	BRA NZ	L_casoC16
	DEC	W8
	BRA NZ	L_casoC16
;paola1.c,123 :: 		RCONbits.POR=0;
	BCLR	RCONbits, #0
;paola1.c,124 :: 		}
L_casoC15:
L_casoC14:
L_casoC10:
;paola1.c,125 :: 		while(Ps2_Key_Read(&keydata, &special, &down));
L_casoC18:
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	CP0	W0
	BRA NZ	L__casoC51
	GOTO	L_casoC19
L__casoC51:
	GOTO	L_casoC18
L_casoC19:
;paola1.c,126 :: 		}while(op!=34);
	MOV	#34, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA Z	L__casoC52
	GOTO	L_casoC4
L__casoC52:
;paola1.c,127 :: 		op='c';
	MOV	#99, W0
	MOV	W0, _op
;paola1.c,128 :: 		}
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

;paola1.c,129 :: 		void main(){
;paola1.c,130 :: 		ANSELB=0;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CLR	ANSELB
;paola1.c,131 :: 		ANSELC=0;
	CLR	ANSELC
;paola1.c,132 :: 		ANSELD=0;
	CLR	ANSELD
;paola1.c,133 :: 		ANSELE=0;
	CLR	ANSELE
;paola1.c,134 :: 		ANSELG=0;             //ANALOGICO SON B Y F
	CLR	ANSELG
;paola1.c,136 :: 		TRISB = 1;
	MOV	#1, W0
	MOV	WREG, TRISB
;paola1.c,137 :: 		TRISE=0;
	CLR	TRISE
;paola1.c,138 :: 		TRISG=0;
	CLR	TRISG
;paola1.c,140 :: 		Glcd_Init();
	CALL	_Glcd_Init
;paola1.c,141 :: 		Glcd_Set_Font(font5x7 , 5, 7, 32);
	MOV	#___Lib_System_DefaultPage, W0
	MOV.B	#7, W13
	MOV.B	#5, W12
	MOV	#lo_addr(_font5x7), W10
	MOV	W0, W11
	MOV	#32, W0
	PUSH	W0
	CALL	_Glcd_Set_Font
	SUB	#2, W15
;paola1.c,142 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;paola1.c,143 :: 		PS2_Config();
	CALL	_Ps2_Config
;paola1.c,144 :: 		animate_charmander();
	CALL	_animate_charmander
;paola1.c,145 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main20:
	DEC	W7
	BRA NZ	L_main20
	DEC	W8
	BRA NZ	L_main20
	NOP
	NOP
	NOP
	NOP
;paola1.c,146 :: 		while(1){
L_main22:
;paola1.c,147 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;paola1.c,148 :: 		Glcd_Write_TEXT("Laboratorio 1",31,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#31, W11
	MOV	#lo_addr(?lstr5_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,149 :: 		Glcd_Write_TEXT("Presione 'A' para Caso 1",0,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr6_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,150 :: 		Glcd_Write_TEXT("Presione 'B' para Caso 2",0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr7_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,151 :: 		Glcd_Write_TEXT("Presione 'C' para Caso 3",0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr8_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,152 :: 		Glcd_Write_TEXT("Presione 'D' para WDT   ",0,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	CLR	W11
	MOV	#lo_addr(?lstr9_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,153 :: 		if(Ps2_Key_Read(&keydata, &special, &down)){
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	CP0	W0
	BRA NZ	L__main54
	GOTO	L_main24
L__main54:
;paola1.c,154 :: 		if(down &&!special){
	MOV	#lo_addr(_down), W0
	CP0.B	[W0]
	BRA NZ	L__main55
	GOTO	L__main47
L__main55:
	MOV	#lo_addr(_special), W0
	CP0.B	[W0]
	BRA Z	L__main56
	GOTO	L__main46
L__main56:
L__main45:
;paola1.c,155 :: 		switch(keydata){
	GOTO	L_main28
;paola1.c,156 :: 		case 'a':
L_main30:
;paola1.c,157 :: 		Glcd_Write_TEXT("Caso A",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr10_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,158 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main31:
	DEC	W7
	BRA NZ	L_main31
	DEC	W8
	BRA NZ	L_main31
	NOP
	NOP
	NOP
	NOP
;paola1.c,160 :: 		break;
	GOTO	L_main29
;paola1.c,162 :: 		case 'b':
L_main33:
;paola1.c,163 :: 		Glcd_Write_TEXT("Caso B ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr11_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,164 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main34:
	DEC	W7
	BRA NZ	L_main34
	DEC	W8
	BRA NZ	L_main34
	NOP
	NOP
	NOP
	NOP
;paola1.c,166 :: 		break;
	GOTO	L_main29
;paola1.c,168 :: 		case 'c':
L_main36:
;paola1.c,169 :: 		Glcd_Write_TEXT("Caso C ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr12_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,170 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main37:
	DEC	W7
	BRA NZ	L_main37
	DEC	W8
	BRA NZ	L_main37
	NOP
	NOP
	NOP
	NOP
;paola1.c,171 :: 		casoC();
	CALL	_casoC
;paola1.c,172 :: 		break;
	GOTO	L_main29
;paola1.c,174 :: 		case 'd':
L_main39:
;paola1.c,175 :: 		Glcd_Write_TEXT("Caso D ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr13_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,176 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main40:
	DEC	W7
	BRA NZ	L_main40
	DEC	W8
	BRA NZ	L_main40
	NOP
	NOP
	NOP
	NOP
;paola1.c,178 :: 		break;
	GOTO	L_main29
;paola1.c,179 :: 		default:
L_main42:
;paola1.c,180 :: 		Glcd_Write_TEXT("Erroneo ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr14_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,181 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main43:
	DEC	W7
	BRA NZ	L_main43
	DEC	W8
	BRA NZ	L_main43
	NOP
	NOP
	NOP
	NOP
;paola1.c,182 :: 		break;
	GOTO	L_main29
;paola1.c,183 :: 		}
L_main28:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#97, W0
	CP.B	W1, W0
	BRA NZ	L__main57
	GOTO	L_main30
L__main57:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#98, W0
	CP.B	W1, W0
	BRA NZ	L__main58
	GOTO	L_main33
L__main58:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#99, W0
	CP.B	W1, W0
	BRA NZ	L__main59
	GOTO	L_main36
L__main59:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#100, W0
	CP.B	W1, W0
	BRA NZ	L__main60
	GOTO	L_main39
L__main60:
	GOTO	L_main42
L_main29:
;paola1.c,154 :: 		if(down &&!special){
L__main47:
L__main46:
;paola1.c,185 :: 		}
L_main24:
;paola1.c,186 :: 		}
	GOTO	L_main22
;paola1.c,187 :: 		}
L_end_main:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
