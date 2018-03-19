
_barras:

;barras.h,14 :: 		void barras(int INTx,int contador_barra) {
;barras.h,16 :: 		bar_drawer(BARS_H_LOCATIONS[INTx],contador_barra);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	SL	W10, #1, W1
	MOV	#lo_addr(_BARS_H_LOCATIONS), W0
	ADD	W0, W1, W1
	MOV	#___Lib_System_DefaultPage, W0
	MOV	WREG, 50
	MOV	[W1], W0
	PUSH.D	W10
	MOV.B	W0, W10
	CALL	_bar_drawer
	POP.D	W10
;barras.h,17 :: 		IntToStr(contador_barra,txt);
	PUSH	W10
	MOV	W11, W10
	MOV	#lo_addr(_txt), W11
	CALL	_IntToStr
	POP	W10
;barras.h,18 :: 		Glcd_Write_Text(txt,BARS_H_LOCATIONS[INTx],0,1);
	SL	W10, #1, W1
	MOV	#lo_addr(_BARS_H_LOCATIONS), W0
	ADD	W0, W1, W1
	MOV	#___Lib_System_DefaultPage, W0
	MOV	WREG, 50
	MOV	[W1], W0
	MOV.B	#1, W13
	CLR	W12
	MOV.B	W0, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;barras.h,19 :: 		}
L_end_barras:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _barras

_bar_drawer:

;barras.h,21 :: 		void bar_drawer(unsigned short x_left,unsigned short contador_barra){
;barras.h,24 :: 		x_right=x_left+BAR_WIDTH;
	PUSH	W11
	PUSH	W12
	PUSH	W13
	ZE	W10, W1
	MOV	#lo_addr(_x_right), W0
	ADD	W1, #20, [W0]
;barras.h,25 :: 		contador_reset=DrawableBars(contador_barra);
	PUSH.D	W10
	ZE	W11, W10
	CALL	_DrawableBars
	POP.D	W10
	MOV	W0, _contador_reset
;barras.h,26 :: 		if(contador_barra>1){
	CP.B	W11, #1
	BRA GTU	L__bar_drawer149
	GOTO	L_bar_drawer0
L__bar_drawer149:
;barras.h,27 :: 		if (contador_reset==1){
	MOV	_contador_reset, W0
	CP	W0, #1
	BRA Z	L__bar_drawer150
	GOTO	L_bar_drawer1
L__bar_drawer150:
;barras.h,29 :: 		Glcd_Box(x_left,MAX_BAR_HEIGHT,x_right,BAR_HEIGHT,WHITE);
	MOV.B	#2, W13
	MOV	_x_right, W12
	MOV.B	#50, W11
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
;barras.h,30 :: 		}
	GOTO	L_bar_drawer2
L_bar_drawer1:
;barras.h,33 :: 		y_bottom=DrawableBars(contador_barra)*BAR_HEIGHT;
	PUSH	W10
	ZE	W11, W10
	CALL	_DrawableBars
	POP	W10
	SL	W0, #1, W1
	MOV	W1, _y_bottom
;barras.h,34 :: 		y_top=y_bottom+BAR_HEIGHT;
	ADD	W1, #2, W0
	MOV	W0, _y_top
;barras.h,35 :: 		Glcd_Box(x_left,y_top,x_right,y_bottom,BLACK);
	MOV.B	W1, W13
	MOV	_x_right, W12
	MOV.B	W0, W11
	MOV.B	#1, W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
;barras.h,36 :: 		}
L_bar_drawer2:
;barras.h,37 :: 		}
L_bar_drawer0:
;barras.h,38 :: 		}
L_end_bar_drawer:
	POP	W13
	POP	W12
	POP	W11
	RETURN
; end of _bar_drawer

_DrawableBars:

;barras.h,39 :: 		int DrawableBars(int real_number_of_bars){
;barras.h,42 :: 		if(real_number_of_bars>25){
	PUSH	W11
	CP	W10, #25
	BRA GT	L__DrawableBars152
	GOTO	L_DrawableBars3
L__DrawableBars152:
;barras.h,43 :: 		quotient=real_number_of_bars/25;
	MOV	#25, W2
	REPEAT	#17
	DIV.S	W10, W2
	MOV	W0, _quotient
;barras.h,44 :: 		quotient=floor(quotient);
	PUSH	W10
	ASR	W0, #15, W1
	SETM	W2
	CALL	__Long2Float
	MOV.D	W0, W10
	CALL	_floor
	CALL	__Float2Longint
	POP	W10
	MOV	W0, _quotient
;barras.h,45 :: 		return real_number_of_bars-25*quotient;
	MOV	#25, W1
	MUL.SS	W1, W0, W0
	SUB	W10, W0, W0
	GOTO	L_end_DrawableBars
;barras.h,46 :: 		}else{
L_DrawableBars3:
;barras.h,47 :: 		return real_number_of_bars;
	MOV	W10, W0
;barras.h,49 :: 		}
;barras.h,47 :: 		return real_number_of_bars;
;barras.h,49 :: 		}
L_end_DrawableBars:
	POP	W11
	RETURN
; end of _DrawableBars

_animate_charmander:

;sprites.h,33 :: 		void animate_charmander(){
;sprites.h,35 :: 		Glcd_Image(charmander_1);
	PUSH	W10
	MOV	#lo_addr(_charmander_1), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	CALL	_Glcd_Image
;sprites.h,36 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_animate_charmander5:
	DEC	W7
	BRA NZ	L_animate_charmander5
	DEC	W8
	BRA NZ	L_animate_charmander5
;sprites.h,38 :: 		Glcd_Image(charmander_2);
	MOV	#lo_addr(_charmander_2), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	CALL	_Glcd_Image
;sprites.h,39 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_animate_charmander7:
	DEC	W7
	BRA NZ	L_animate_charmander7
	DEC	W8
	BRA NZ	L_animate_charmander7
;sprites.h,40 :: 		}
L_end_animate_charmander:
	POP	W10
	RETURN
; end of _animate_charmander

_animate_blooper_20s:

;sprites.h,73 :: 		void animate_blooper_20s(){
;sprites.h,74 :: 		Glcd_Fill(0xFF);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#255, W10
	CALL	_Glcd_Fill
;sprites.h,75 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_animate_blooper_20s9:
	DEC	W7
	BRA NZ	L_animate_blooper_20s9
	DEC	W8
	BRA NZ	L_animate_blooper_20s9
	NOP
	NOP
	NOP
	NOP
;sprites.h,76 :: 		Glcd_PartialImage(63,16,35,34,35,34,blooper_1);
	MOV	#34, W13
	MOV	#35, W12
	MOV	#16, W11
	MOV	#63, W10
	MOV	#lo_addr(_blooper_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#34, W0
	PUSH	W0
	MOV	#35, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,77 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_animate_blooper_20s11:
	DEC	W7
	BRA NZ	L_animate_blooper_20s11
	DEC	W8
	BRA NZ	L_animate_blooper_20s11
	NOP
	NOP
	NOP
	NOP
;sprites.h,78 :: 		Glcd_Fill(0xFF);
	MOV.B	#255, W10
	CALL	_Glcd_Fill
;sprites.h,79 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_animate_blooper_20s13:
	DEC	W7
	BRA NZ	L_animate_blooper_20s13
	DEC	W8
	BRA NZ	L_animate_blooper_20s13
	NOP
	NOP
	NOP
	NOP
;sprites.h,80 :: 		Glcd_PartialImage(63,16,35,34,35,34,blooper_2);
	MOV	#34, W13
	MOV	#35, W12
	MOV	#16, W11
	MOV	#63, W10
	MOV	#lo_addr(_blooper_2), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#34, W0
	PUSH	W0
	MOV	#35, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,81 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_animate_blooper_20s15:
	DEC	W7
	BRA NZ	L_animate_blooper_20s15
	DEC	W8
	BRA NZ	L_animate_blooper_20s15
	NOP
	NOP
	NOP
	NOP
;sprites.h,82 :: 		Glcd_Fill(0xFF);
	MOV.B	#255, W10
	CALL	_Glcd_Fill
;sprites.h,83 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_animate_blooper_20s17:
	DEC	W7
	BRA NZ	L_animate_blooper_20s17
	DEC	W8
	BRA NZ	L_animate_blooper_20s17
	NOP
	NOP
	NOP
	NOP
;sprites.h,84 :: 		Glcd_PartialImage(63,16,35,34,35,34,blooper_3);
	MOV	#34, W13
	MOV	#35, W12
	MOV	#16, W11
	MOV	#63, W10
	MOV	#lo_addr(_blooper_3), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#34, W0
	PUSH	W0
	MOV	#35, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,85 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_animate_blooper_20s19:
	DEC	W7
	BRA NZ	L_animate_blooper_20s19
	DEC	W8
	BRA NZ	L_animate_blooper_20s19
	NOP
	NOP
	NOP
	NOP
;sprites.h,86 :: 		Glcd_Fill(0xFF);
	MOV.B	#255, W10
	CALL	_Glcd_Fill
;sprites.h,87 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_animate_blooper_20s21:
	DEC	W7
	BRA NZ	L_animate_blooper_20s21
	DEC	W8
	BRA NZ	L_animate_blooper_20s21
	NOP
	NOP
	NOP
	NOP
;sprites.h,88 :: 		Glcd_PartialImage(63,16,35,34,35,34,blooper_4);
	MOV	#34, W13
	MOV	#35, W12
	MOV	#16, W11
	MOV	#63, W10
	MOV	#lo_addr(_blooper_4), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#34, W0
	PUSH	W0
	MOV	#35, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,89 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_animate_blooper_20s23:
	DEC	W7
	BRA NZ	L_animate_blooper_20s23
	DEC	W8
	BRA NZ	L_animate_blooper_20s23
	NOP
	NOP
	NOP
	NOP
;sprites.h,90 :: 		Glcd_Fill(0xFF);
	MOV.B	#255, W10
	CALL	_Glcd_Fill
;sprites.h,91 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_animate_blooper_20s25:
	DEC	W7
	BRA NZ	L_animate_blooper_20s25
	DEC	W8
	BRA NZ	L_animate_blooper_20s25
	NOP
	NOP
	NOP
	NOP
;sprites.h,92 :: 		Glcd_PartialImage(63,16,35,34,35,34,blooper_1);
	MOV	#34, W13
	MOV	#35, W12
	MOV	#16, W11
	MOV	#63, W10
	MOV	#lo_addr(_blooper_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#34, W0
	PUSH	W0
	MOV	#35, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,93 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_animate_blooper_20s27:
	DEC	W7
	BRA NZ	L_animate_blooper_20s27
	DEC	W8
	BRA NZ	L_animate_blooper_20s27
	NOP
	NOP
	NOP
	NOP
;sprites.h,94 :: 		}
L_end_animate_blooper_20s:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _animate_blooper_20s

_animate_bullet:

;sprites.h,105 :: 		void animate_bullet(){
;sprites.h,108 :: 		Glcd_Fill(0);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CLR	W10
	CALL	_Glcd_Fill
;sprites.h,109 :: 		Glcd_PartialImage(120,24,18,18,18,18,bullet);
	MOV	#18, W13
	MOV	#18, W12
	MOV	#24, W11
	MOV	#120, W10
	MOV	#lo_addr(_bullet), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,110 :: 		delay_ms(250);
	MOV	#4, W8
	MOV	#53393, W7
L_animate_bullet29:
	DEC	W7
	BRA NZ	L_animate_bullet29
	DEC	W8
	BRA NZ	L_animate_bullet29
	NOP
	NOP
	NOP
;sprites.h,111 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;sprites.h,112 :: 		Glcd_PartialImage(115,24,18,18,18,18,bullet);
	MOV	#18, W13
	MOV	#18, W12
	MOV	#24, W11
	MOV	#115, W10
	MOV	#lo_addr(_bullet), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,113 :: 		delay_ms(250);
	MOV	#4, W8
	MOV	#53393, W7
L_animate_bullet31:
	DEC	W7
	BRA NZ	L_animate_bullet31
	DEC	W8
	BRA NZ	L_animate_bullet31
	NOP
	NOP
	NOP
;sprites.h,114 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;sprites.h,115 :: 		Glcd_PartialImage(100,24,18,18,18,18,bullet);
	MOV	#18, W13
	MOV	#18, W12
	MOV	#24, W11
	MOV	#100, W10
	MOV	#lo_addr(_bullet), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,116 :: 		delay_ms(250);
	MOV	#4, W8
	MOV	#53393, W7
L_animate_bullet33:
	DEC	W7
	BRA NZ	L_animate_bullet33
	DEC	W8
	BRA NZ	L_animate_bullet33
	NOP
	NOP
	NOP
;sprites.h,117 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;sprites.h,118 :: 		Glcd_PartialImage(80,24,18,18,18,18,bullet);
	MOV	#18, W13
	MOV	#18, W12
	MOV	#24, W11
	MOV	#80, W10
	MOV	#lo_addr(_bullet), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,119 :: 		delay_ms(250);
	MOV	#4, W8
	MOV	#53393, W7
L_animate_bullet35:
	DEC	W7
	BRA NZ	L_animate_bullet35
	DEC	W8
	BRA NZ	L_animate_bullet35
	NOP
	NOP
	NOP
;sprites.h,120 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;sprites.h,121 :: 		Glcd_PartialImage(60,24,18,18,18,18,bullet);
	MOV	#18, W13
	MOV	#18, W12
	MOV	#24, W11
	MOV	#60, W10
	MOV	#lo_addr(_bullet), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,122 :: 		delay_ms(250);
	MOV	#4, W8
	MOV	#53393, W7
L_animate_bullet37:
	DEC	W7
	BRA NZ	L_animate_bullet37
	DEC	W8
	BRA NZ	L_animate_bullet37
	NOP
	NOP
	NOP
;sprites.h,123 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;sprites.h,124 :: 		Glcd_PartialImage(20,24,18,18,18,18,bullet);
	MOV	#18, W13
	MOV	#18, W12
	MOV	#24, W11
	MOV	#20, W10
	MOV	#lo_addr(_bullet), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,125 :: 		delay_ms(250);
	MOV	#4, W8
	MOV	#53393, W7
L_animate_bullet39:
	DEC	W7
	BRA NZ	L_animate_bullet39
	DEC	W8
	BRA NZ	L_animate_bullet39
	NOP
	NOP
	NOP
;sprites.h,127 :: 		}
L_end_animate_bullet:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _animate_bullet

_animate_shell_20s:

;sprites.h,152 :: 		void animate_shell_20s(){
;sprites.h,153 :: 		Glcd_Rectangle(0,8,127,64,0);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,154 :: 		Glcd_PartialImage(125,56,16,16,16,16,shell_1);
	MOV	#16, W13
	MOV	#16, W12
	MOV	#56, W11
	MOV	#125, W10
	MOV	#lo_addr(_shell_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#16, W0
	PUSH	W0
	MOV	#16, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,155 :: 		delay_ms(400);
	MOV	#7, W8
	MOV	#6787, W7
L_animate_shell_20s41:
	DEC	W7
	BRA NZ	L_animate_shell_20s41
	DEC	W8
	BRA NZ	L_animate_shell_20s41
	NOP
	NOP
;sprites.h,156 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,157 :: 		Glcd_PartialImage(100,56,16,16,16,16,shell_2);
	MOV	#16, W13
	MOV	#16, W12
	MOV	#56, W11
	MOV	#100, W10
	MOV	#lo_addr(_shell_2), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#16, W0
	PUSH	W0
	MOV	#16, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,158 :: 		delay_ms(400);
	MOV	#7, W8
	MOV	#6787, W7
L_animate_shell_20s43:
	DEC	W7
	BRA NZ	L_animate_shell_20s43
	DEC	W8
	BRA NZ	L_animate_shell_20s43
	NOP
	NOP
;sprites.h,159 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,160 :: 		Glcd_PartialImage(75,56,16,16,16,16,shell_3);
	MOV	#16, W13
	MOV	#16, W12
	MOV	#56, W11
	MOV	#75, W10
	MOV	#lo_addr(_shell_3), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#16, W0
	PUSH	W0
	MOV	#16, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,161 :: 		delay_ms(400);
	MOV	#7, W8
	MOV	#6787, W7
L_animate_shell_20s45:
	DEC	W7
	BRA NZ	L_animate_shell_20s45
	DEC	W8
	BRA NZ	L_animate_shell_20s45
	NOP
	NOP
;sprites.h,162 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,163 :: 		Glcd_PartialImage(50,56,16,16,16,16,shell_1);
	MOV	#16, W13
	MOV	#16, W12
	MOV	#56, W11
	MOV	#50, W10
	MOV	#lo_addr(_shell_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#16, W0
	PUSH	W0
	MOV	#16, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,164 :: 		delay_ms(400);
	MOV	#7, W8
	MOV	#6787, W7
L_animate_shell_20s47:
	DEC	W7
	BRA NZ	L_animate_shell_20s47
	DEC	W8
	BRA NZ	L_animate_shell_20s47
	NOP
	NOP
;sprites.h,165 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,166 :: 		Glcd_PartialImage(25,56,16,16,16,16,shell_2);
	MOV	#16, W13
	MOV	#16, W12
	MOV	#56, W11
	MOV	#25, W10
	MOV	#lo_addr(_shell_2), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#16, W0
	PUSH	W0
	MOV	#16, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,167 :: 		delay_ms(400);
	MOV	#7, W8
	MOV	#6787, W7
L_animate_shell_20s49:
	DEC	W7
	BRA NZ	L_animate_shell_20s49
	DEC	W8
	BRA NZ	L_animate_shell_20s49
	NOP
	NOP
;sprites.h,169 :: 		}
L_end_animate_shell_20s:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _animate_shell_20s

_animate_dog_20s:

;sprites.h,206 :: 		void animate_dog_20s(){
;sprites.h,207 :: 		Glcd_Rectangle(0,8,127,64,0);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,208 :: 		Glcd_PartialImage(45,16,31,40,31,40,dog_1);
	MOV	#40, W13
	MOV	#31, W12
	MOV	#16, W11
	MOV	#45, W10
	MOV	#lo_addr(_dog_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#40, W0
	PUSH	W0
	MOV	#31, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,209 :: 		delay_ms(400);
	MOV	#7, W8
	MOV	#6787, W7
L_animate_dog_20s51:
	DEC	W7
	BRA NZ	L_animate_dog_20s51
	DEC	W8
	BRA NZ	L_animate_dog_20s51
	NOP
	NOP
;sprites.h,210 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,211 :: 		Glcd_PartialImage(45,16,31,40,31,40,dog_2);
	MOV	#40, W13
	MOV	#31, W12
	MOV	#16, W11
	MOV	#45, W10
	MOV	#lo_addr(_dog_2), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#40, W0
	PUSH	W0
	MOV	#31, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,212 :: 		delay_ms(400);
	MOV	#7, W8
	MOV	#6787, W7
L_animate_dog_20s53:
	DEC	W7
	BRA NZ	L_animate_dog_20s53
	DEC	W8
	BRA NZ	L_animate_dog_20s53
	NOP
	NOP
;sprites.h,213 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,214 :: 		Glcd_PartialImage(45,16,31,40,31,40,dog_3);
	MOV	#40, W13
	MOV	#31, W12
	MOV	#16, W11
	MOV	#45, W10
	MOV	#lo_addr(_dog_3), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#40, W0
	PUSH	W0
	MOV	#31, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,215 :: 		delay_ms(400);
	MOV	#7, W8
	MOV	#6787, W7
L_animate_dog_20s55:
	DEC	W7
	BRA NZ	L_animate_dog_20s55
	DEC	W8
	BRA NZ	L_animate_dog_20s55
	NOP
	NOP
;sprites.h,216 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,217 :: 		Glcd_PartialImage(45,16,31,40,31,40,dog_1);
	MOV	#40, W13
	MOV	#31, W12
	MOV	#16, W11
	MOV	#45, W10
	MOV	#lo_addr(_dog_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#40, W0
	PUSH	W0
	MOV	#31, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,218 :: 		delay_ms(400);
	MOV	#7, W8
	MOV	#6787, W7
L_animate_dog_20s57:
	DEC	W7
	BRA NZ	L_animate_dog_20s57
	DEC	W8
	BRA NZ	L_animate_dog_20s57
	NOP
	NOP
;sprites.h,219 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,220 :: 		Glcd_PartialImage(45,16,31,40,31,40,dog_2);
	MOV	#40, W13
	MOV	#31, W12
	MOV	#16, W11
	MOV	#45, W10
	MOV	#lo_addr(_dog_2), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#40, W0
	PUSH	W0
	MOV	#31, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,221 :: 		delay_ms(400);
	MOV	#7, W8
	MOV	#6787, W7
L_animate_dog_20s59:
	DEC	W7
	BRA NZ	L_animate_dog_20s59
	DEC	W8
	BRA NZ	L_animate_dog_20s59
	NOP
	NOP
;sprites.h,222 :: 		}
L_end_animate_dog_20s:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _animate_dog_20s

_animate_kirby:

;sprites.h,284 :: 		void animate_kirby(){
;sprites.h,285 :: 		Glcd_Rectangle(0,8,127,64,0);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,286 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_1);
	MOV	#19, W13
	MOV	#21, W12
	MOV	#20, W11
	MOV	#21, W10
	MOV	#lo_addr(_kirby_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#19, W0
	PUSH	W0
	MOV	#21, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,287 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby61:
	DEC	W7
	BRA NZ	L_animate_kirby61
	DEC	W8
	BRA NZ	L_animate_kirby61
	NOP
;sprites.h,288 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,289 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_2);
	MOV	#19, W13
	MOV	#21, W12
	MOV	#20, W11
	MOV	#21, W10
	MOV	#lo_addr(_kirby_2), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#19, W0
	PUSH	W0
	MOV	#21, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,290 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby63:
	DEC	W7
	BRA NZ	L_animate_kirby63
	DEC	W8
	BRA NZ	L_animate_kirby63
	NOP
;sprites.h,291 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,292 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_3);
	MOV	#19, W13
	MOV	#21, W12
	MOV	#20, W11
	MOV	#21, W10
	MOV	#lo_addr(_kirby_3), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#19, W0
	PUSH	W0
	MOV	#21, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,293 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby65:
	DEC	W7
	BRA NZ	L_animate_kirby65
	DEC	W8
	BRA NZ	L_animate_kirby65
	NOP
;sprites.h,294 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,295 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_4);
	MOV	#19, W13
	MOV	#21, W12
	MOV	#20, W11
	MOV	#21, W10
	MOV	#lo_addr(_kirby_4), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#19, W0
	PUSH	W0
	MOV	#21, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,296 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby67:
	DEC	W7
	BRA NZ	L_animate_kirby67
	DEC	W8
	BRA NZ	L_animate_kirby67
	NOP
;sprites.h,297 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,298 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_5);
	MOV	#19, W13
	MOV	#21, W12
	MOV	#20, W11
	MOV	#21, W10
	MOV	#lo_addr(_kirby_5), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#19, W0
	PUSH	W0
	MOV	#21, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,299 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby69:
	DEC	W7
	BRA NZ	L_animate_kirby69
	DEC	W8
	BRA NZ	L_animate_kirby69
	NOP
;sprites.h,300 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,301 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_6);
	MOV	#19, W13
	MOV	#21, W12
	MOV	#20, W11
	MOV	#21, W10
	MOV	#lo_addr(_kirby_6), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#19, W0
	PUSH	W0
	MOV	#21, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,302 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby71:
	DEC	W7
	BRA NZ	L_animate_kirby71
	DEC	W8
	BRA NZ	L_animate_kirby71
	NOP
;sprites.h,303 :: 		}
L_end_animate_kirby:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _animate_kirby

_animate_charmander_10s:

;MyProject.c,40 :: 		void animate_charmander_10s(){
;MyProject.c,41 :: 		Glcd_Image(charmander_1);
	PUSH	W10
	MOV	#lo_addr(_charmander_1), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	CALL	_Glcd_Image
;MyProject.c,42 :: 		delay_ms(5000);
	MOV	#77, W8
	MOV	#19309, W7
L_animate_charmander_10s73:
	DEC	W7
	BRA NZ	L_animate_charmander_10s73
	DEC	W8
	BRA NZ	L_animate_charmander_10s73
	NOP
	NOP
;MyProject.c,43 :: 		Glcd_Image(charmander_2);
	MOV	#lo_addr(_charmander_2), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	CALL	_Glcd_Image
;MyProject.c,44 :: 		delay_ms(5000);
	MOV	#77, W8
	MOV	#19309, W7
L_animate_charmander_10s75:
	DEC	W7
	BRA NZ	L_animate_charmander_10s75
	DEC	W8
	BRA NZ	L_animate_charmander_10s75
	NOP
	NOP
;MyProject.c,45 :: 		}
L_end_animate_charmander_10s:
	POP	W10
	RETURN
; end of _animate_charmander_10s

_log2:

;MyProject.c,61 :: 		void log2(char *TXT){
;MyProject.c,62 :: 		Glcd_Write_TEXT(TXT,0,7,1);
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	CALL	_Glcd_Write_Text
;MyProject.c,63 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_log277:
	DEC	W7
	BRA NZ	L_log277
	DEC	W8
	BRA NZ	L_log277
;MyProject.c,64 :: 		}
L_end_log2:
	POP	W13
	POP	W12
	POP	W11
	RETURN
; end of _log2

_INT0:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;MyProject.c,67 :: 		void INT0() org 0x14{
;MyProject.c,68 :: 		InterrAdapter(0);
	PUSH	W10
	CLR	W10
	CALL	_InterrAdapter
;MyProject.c,69 :: 		}
L_end_INT0:
	POP	W10
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	50
	POP	DSWPAG
	RETFIE
; end of _INT0

_INT1:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;MyProject.c,70 :: 		void INT1() org 0x3C{
;MyProject.c,71 :: 		InterrAdapter(1);
	PUSH	W10
	MOV	#1, W10
	CALL	_InterrAdapter
;MyProject.c,72 :: 		}
L_end_INT1:
	POP	W10
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	50
	POP	DSWPAG
	RETFIE
; end of _INT1

_INT2:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;MyProject.c,73 :: 		void INT2() org 0x4E{
;MyProject.c,74 :: 		InterrAdapter(2);
	PUSH	W10
	MOV	#2, W10
	CALL	_InterrAdapter
;MyProject.c,75 :: 		}
L_end_INT2:
	POP	W10
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	50
	POP	DSWPAG
	RETFIE
; end of _INT2

_INT3:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;MyProject.c,76 :: 		void INT3() org 0x7E{
;MyProject.c,77 :: 		InterrAdapter(3);
	PUSH	W10
	MOV	#3, W10
	CALL	_InterrAdapter
;MyProject.c,78 :: 		}
L_end_INT3:
	POP	W10
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	50
	POP	DSWPAG
	RETFIE
; end of _INT3

_INT4:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;MyProject.c,79 :: 		void INT4() org 0x80{
;MyProject.c,80 :: 		InterrAdapter(4);
	PUSH	W10
	MOV	#4, W10
	CALL	_InterrAdapter
;MyProject.c,81 :: 		}
L_end_INT4:
	POP	W10
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	50
	POP	DSWPAG
	RETFIE
; end of _INT4

_INT_CN:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;MyProject.c,82 :: 		void INT_CN() org 0x3A{
;MyProject.c,83 :: 		IFS1bits.CNIF = 0;
	PUSH	W10
	BCLR	IFS1bits, #3
;MyProject.c,84 :: 		if(PORTBbits.RB0 ==1){
	BTSS	PORTBbits, #0
	GOTO	L_INT_CN79
;MyProject.c,85 :: 		log2("INT CN0");  delay_ms(1000);
	MOV	#lo_addr(?lstr1_MyProject), W10
	CALL	_log2
	MOV	#16, W8
	MOV	#16968, W7
L_INT_CN80:
	DEC	W7
	BRA NZ	L_INT_CN80
	DEC	W8
	BRA NZ	L_INT_CN80
	NOP
	NOP
	NOP
	NOP
;MyProject.c,86 :: 		valores_cn[0]=1;
	MOV	#1, W0
	MOV	W0, _valores_cn
;MyProject.c,87 :: 		valores_cn[1]=0;
	CLR	W0
	MOV	W0, _valores_cn+2
;MyProject.c,88 :: 		valores_cn[2]=0;
	CLR	W0
	MOV	W0, _valores_cn+4
;MyProject.c,89 :: 		valores_cn[3]=0;
	CLR	W0
	MOV	W0, _valores_cn+6
;MyProject.c,91 :: 		}else if(PORTDbits.RD0==1){
	GOTO	L_INT_CN82
L_INT_CN79:
	BTSS	PORTDbits, #0
	GOTO	L_INT_CN83
;MyProject.c,92 :: 		log2("INT CN1");
	MOV	#lo_addr(?lstr2_MyProject), W10
	CALL	_log2
;MyProject.c,93 :: 		valores_cn[0]=0;
	CLR	W0
	MOV	W0, _valores_cn
;MyProject.c,94 :: 		valores_cn[1]=1;
	MOV	#1, W0
	MOV	W0, _valores_cn+2
;MyProject.c,95 :: 		valores_cn[2]=0;
	CLR	W0
	MOV	W0, _valores_cn+4
;MyProject.c,96 :: 		valores_cn[3]=0;
	CLR	W0
	MOV	W0, _valores_cn+6
;MyProject.c,97 :: 		}else if(PORTDbits.RD11==1){
	GOTO	L_INT_CN84
L_INT_CN83:
	BTSS	PORTDbits, #11
	GOTO	L_INT_CN85
;MyProject.c,98 :: 		log2("INT CN2");
	MOV	#lo_addr(?lstr3_MyProject), W10
	CALL	_log2
;MyProject.c,99 :: 		valores_cn[0]=0;
	CLR	W0
	MOV	W0, _valores_cn
;MyProject.c,100 :: 		valores_cn[1]=0;
	CLR	W0
	MOV	W0, _valores_cn+2
;MyProject.c,101 :: 		valores_cn[2]=1;
	MOV	#1, W0
	MOV	W0, _valores_cn+4
;MyProject.c,102 :: 		valores_cn[3]=0;
	CLR	W0
	MOV	W0, _valores_cn+6
;MyProject.c,103 :: 		}else if(PORTDbits.RD10==1){
	GOTO	L_INT_CN86
L_INT_CN85:
	BTSS	PORTDbits, #10
	GOTO	L_INT_CN87
;MyProject.c,104 :: 		log2("INT CN3");
	MOV	#lo_addr(?lstr4_MyProject), W10
	CALL	_log2
;MyProject.c,105 :: 		valores_cn[0]=0;
	CLR	W0
	MOV	W0, _valores_cn
;MyProject.c,106 :: 		valores_cn[1]=0;
	CLR	W0
	MOV	W0, _valores_cn+2
;MyProject.c,107 :: 		valores_cn[2]=0;
	CLR	W0
	MOV	W0, _valores_cn+4
;MyProject.c,108 :: 		valores_cn[3]=1;
	MOV	#1, W0
	MOV	W0, _valores_cn+6
;MyProject.c,109 :: 		}
L_INT_CN87:
L_INT_CN86:
L_INT_CN84:
L_INT_CN82:
;MyProject.c,111 :: 		log2("salida cn_int");
	MOV	#lo_addr(?lstr5_MyProject), W10
	CALL	_log2
;MyProject.c,112 :: 		}
L_end_INT_CN:
	POP	W10
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	50
	POP	DSWPAG
	RETFIE
; end of _INT_CN

_InterrAdapter:

;MyProject.c,113 :: 		void InterrAdapter(int INTx){
;MyProject.c,114 :: 		counters[INTx]++;
	SL	W10, #1, W1
	MOV	#lo_addr(_counters), W0
	ADD	W0, W1, W1
	MOV	[W1], W0
	INC	W0
	MOV	W0, [W1]
;MyProject.c,116 :: 		}
L_end_InterrAdapter:
	RETURN
; end of _InterrAdapter

_config_IO:

;MyProject.c,120 :: 		void config_IO(){
;MyProject.c,121 :: 		ANSELB=0;
	CLR	ANSELB
;MyProject.c,122 :: 		ANSELC=0;
	CLR	ANSELC
;MyProject.c,123 :: 		ANSELD=0;
	CLR	ANSELD
;MyProject.c,124 :: 		ANSELE=0;
	CLR	ANSELE
;MyProject.c,125 :: 		ANSELG=0;             //ANALOGICO SON B Y F
	CLR	ANSELG
;MyProject.c,126 :: 		TRISB=0xffff;
	MOV	#65535, W0
	MOV	WREG, TRISB
;MyProject.c,127 :: 		TRISDbits.TRISD0=1;
	BSET	TRISDbits, #0
;MyProject.c,128 :: 		TRISDbits.TRISD11=1;
	BSET	TRISDbits, #11
;MyProject.c,129 :: 		TRISDbits.TRISD10=1;
	BSET	TRISDbits, #10
;MyProject.c,130 :: 		TRISDbits.TRISD9=1;
	BSET	TRISDbits, #9
;MyProject.c,131 :: 		TRISE=0;
	CLR	TRISE
;MyProject.c,132 :: 		TRISG=0;
	CLR	TRISG
;MyProject.c,135 :: 		}
L_end_config_IO:
	RETURN
; end of _config_IO

_config_LCD:

;MyProject.c,136 :: 		void config_LCD(){
;MyProject.c,137 :: 		Glcd_Init();
	PUSH	W10
	PUSH	W12
	PUSH	W13
	CALL	_Glcd_Init
;MyProject.c,138 :: 		Glcd_Set_Font(font5x7 , 5, 7, 32);
	MOV.B	#7, W13
	MOV.B	#5, W12
	MOV	#lo_addr(_font5x7), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	MOV	#32, W0
	PUSH	W0
	CALL	_Glcd_Set_Font
	SUB	#2, W15
;MyProject.c,139 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;MyProject.c,140 :: 		}
L_end_config_LCD:
	POP	W13
	POP	W12
	POP	W10
	RETURN
; end of _config_LCD

_config_CN:

;MyProject.c,141 :: 		void config_CN(){
;MyProject.c,144 :: 		CNENBbits.CNIEB0=1;
	BSET	CNENBbits, #0
;MyProject.c,145 :: 		CNENDbits.CNIED11=1;
	BSET	CNENDbits, #11
;MyProject.c,146 :: 		CNENDbits.CNIED10=1;
	BSET	CNENDbits, #10
;MyProject.c,147 :: 		CNENDbits.CNIED9=1;
	BSET	CNENDbits, #9
;MyProject.c,148 :: 		CNENDbits.CNIED0=1;
	BSET	CNENDbits, #0
;MyProject.c,150 :: 		CNPUBbits.CNPUB0=1;
	BSET	CNPUBbits, #0
;MyProject.c,151 :: 		CNPUDbits.CNPUD11=1;
	BSET	CNPUDbits, #11
;MyProject.c,152 :: 		CNPUDbits.CNPUD10=1;
	BSET	CNPUDbits, #10
;MyProject.c,153 :: 		CNPUDbits.CNPUD9=1;
	BSET	CNPUDbits, #9
;MyProject.c,154 :: 		CNPUDbits.CNPUD0=1;
	BSET	CNPUDbits, #0
;MyProject.c,159 :: 		IPC4bits.CNIP=7;
	MOV	IPC4bits, W1
	MOV	#28672, W0
	IOR	W1, W0, W0
	MOV	WREG, IPC4bits
;MyProject.c,160 :: 		IFS1bits.CNIF=0;
	BCLR	IFS1bits, #3
;MyProject.c,161 :: 		IEC1bits.CNIE=1;//Resset Interrupcion
	BSET	IEC1bits, #3
;MyProject.c,163 :: 		}
L_end_config_CN:
	RETURN
; end of _config_CN

_config_INT:

;MyProject.c,164 :: 		void config_INT(){
;MyProject.c,165 :: 		SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
	MOV	#lo_addr(SRbits), W0
	MOV.B	[W0], W1
	MOV.B	#31, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(SRbits), W0
	MOV.B	W1, [W0]
;MyProject.c,166 :: 		INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
	BCLR	INTCON1bits, #15
;MyProject.c,167 :: 		INTCON2bits.GIE=1; //interrupciones habilitadas
	BSET	INTCON2bits, #15
;MyProject.c,168 :: 		CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
	BCLR	CORCONbits, #3
;MyProject.c,170 :: 		IEC0bits.INT0IE=1; //HABILITA INTERRUPCION POR INT0
	BSET	IEC0bits, #0
;MyProject.c,171 :: 		IEC1bits.INT1IE=1; //HABILITA
	BSET	IEC1bits, #4
;MyProject.c,172 :: 		IEC1bits.INT2IE=1;
	BSET	IEC1bits, #13
;MyProject.c,173 :: 		IEC3bits.INT3IE=1;
	BSET	IEC3bits, #5
;MyProject.c,174 :: 		IEC3bits.INT4IE=1;
	BSET	IEC3bits, #6
;MyProject.c,177 :: 		IFS0bits.INT0IF=0; //interrupcion de INT0 ACTIVADA
	BCLR	IFS0bits, #0
;MyProject.c,178 :: 		IFS1bits.INT2IF =0; // interrupcion de INT1 ACTIVADA
	BCLR	IFS1bits, #13
;MyProject.c,179 :: 		IFS1bits.INT2IF =0 ; // INTERRIPCION DE INT2 ACTVADA
	BCLR	IFS1bits, #13
;MyProject.c,180 :: 		IFS3bits.INT3IF =0; //INTERRUPCION DE INT3 ACTIVADA
	BCLR	IFS3bits, #5
;MyProject.c,181 :: 		IFS3bits.INT4IF =0; // INTERRUPCION DE INT4 ACTIVADA
	BCLR	IFS3bits, #6
;MyProject.c,183 :: 		counters[0]=0;
	CLR	W0
	MOV	W0, _counters
;MyProject.c,184 :: 		counters[1]=0;
	CLR	W0
	MOV	W0, _counters+2
;MyProject.c,185 :: 		counters[2]=0;
	CLR	W0
	MOV	W0, _counters+4
;MyProject.c,186 :: 		counters[3]=0;
	CLR	W0
	MOV	W0, _counters+6
;MyProject.c,187 :: 		counters[4]=0;
	CLR	W0
	MOV	W0, _counters+8
;MyProject.c,189 :: 		INTCON2bits.INT0EP=0;
	BCLR	INTCON2bits, #0
;MyProject.c,190 :: 		INTCON2bits.INT1EP=0;
	BCLR	INTCON2bits, #1
;MyProject.c,191 :: 		INTCON2bits.INT2EP=0;
	BCLR	INTCON2bits, #2
;MyProject.c,192 :: 		INTCON2bits.INT3EP=0;
	BCLR	INTCON2bits, #3
;MyProject.c,193 :: 		INTCON2bits.INT4EP =0;
	BCLR	INTCON2bits, #4
;MyProject.c,194 :: 		}
L_end_config_INT:
	RETURN
; end of _config_INT

_disable_INT:

;MyProject.c,195 :: 		void disable_INT(){
;MyProject.c,196 :: 		IPC0bits.INT0IP= 0;
	MOV	#lo_addr(IPC0bits), W0
	MOV.B	[W0], W1
	MOV.B	#248, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC0bits), W0
	MOV.B	W1, [W0]
;MyProject.c,197 :: 		IPC5BITS.INT1IP=0;
	MOV	#lo_addr(IPC5bits), W0
	MOV.B	[W0], W1
	MOV.B	#248, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC5bits), W0
	MOV.B	W1, [W0]
;MyProject.c,198 :: 		IPC7bits.INT2IP =0;
	MOV	#lo_addr(IPC7bits), W0
	MOV.B	[W0], W1
	MOV.B	#143, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC7bits), W0
	MOV.B	W1, [W0]
;MyProject.c,199 :: 		IPC13bits.INT3IP=0;
	MOV	#lo_addr(IPC13bits), W0
	MOV.B	[W0], W1
	MOV.B	#143, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC13bits), W0
	MOV.B	W1, [W0]
;MyProject.c,200 :: 		IPC13bits.INT4IP=0;
	MOV	IPC13bits, W1
	MOV	#63743, W0
	AND	W1, W0, W0
	MOV	WREG, IPC13bits
;MyProject.c,201 :: 		counters[0]=0;
	CLR	W0
	MOV	W0, _counters
;MyProject.c,202 :: 		counters[1]=0;
	CLR	W0
	MOV	W0, _counters+2
;MyProject.c,203 :: 		counters[2]=0;
	CLR	W0
	MOV	W0, _counters+4
;MyProject.c,204 :: 		counters[3]=0;
	CLR	W0
	MOV	W0, _counters+6
;MyProject.c,205 :: 		counters[4]=0;
	CLR	W0
	MOV	W0, _counters+8
;MyProject.c,206 :: 		}
L_end_disable_INT:
	RETURN
; end of _disable_INT

_casoB:

;MyProject.c,209 :: 		void casoB(){
;MyProject.c,210 :: 		valores_cn[0]=0;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CLR	W0
	MOV	W0, _valores_cn
;MyProject.c,211 :: 		valores_cn[1]=0;
	CLR	W0
	MOV	W0, _valores_cn+2
;MyProject.c,212 :: 		valores_cn[2]=0;
	CLR	W0
	MOV	W0, _valores_cn+4
;MyProject.c,213 :: 		valores_cn[3]=0;
	CLR	W0
	MOV	W0, _valores_cn+6
;MyProject.c,214 :: 		Glcd_Fill(WHITE)   ;
	CLR	W10
	CALL	_Glcd_Fill
;MyProject.c,215 :: 		Glcd_Write_TEXT("Caso 2",0,0,1);
	MOV.B	#1, W13
	CLR	W12
	CLR	W11
	MOV	#lo_addr(?lstr6_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,216 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_casoB88:
	DEC	W7
	BRA NZ	L_casoB88
	DEC	W8
	BRA NZ	L_casoB88
	NOP
	NOP
	NOP
	NOP
;MyProject.c,217 :: 		do{
L_casoB90:
;MyProject.c,218 :: 		Glcd_Write_TEXT("do CASO",0,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr7_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,219 :: 		down=0;
	MOV	#lo_addr(_down), W1
	CLR	W0
	MOV.B	W0, [W1]
;MyProject.c,220 :: 		special=0;
	MOV	#lo_addr(_special), W1
	CLR	W0
	MOV.B	W0, [W1]
;MyProject.c,221 :: 		if(valores_cn[0]==1){
	MOV	_valores_cn, W0
	CP	W0, #1
	BRA Z	L__casoB174
	GOTO	L_casoB93
L__casoB174:
;MyProject.c,222 :: 		log2("cn0");
	MOV	#lo_addr(?lstr8_MyProject), W10
	CALL	_log2
;MyProject.c,223 :: 		Glcd_Image(charmander_2);delay_ms(500);
	MOV	#lo_addr(_charmander_2), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	CALL	_Glcd_Image
	MOV	#8, W8
	MOV	#41252, W7
L_casoB94:
	DEC	W7
	BRA NZ	L_casoB94
	DEC	W8
	BRA NZ	L_casoB94
;MyProject.c,226 :: 		}else if(valores_cn[1]==1){
	GOTO	L_casoB96
L_casoB93:
	MOV	_valores_cn+2, W0
	CP	W0, #1
	BRA Z	L__casoB175
	GOTO	L_casoB97
L__casoB175:
;MyProject.c,227 :: 		log2("cn1");
	MOV	#lo_addr(?lstr9_MyProject), W10
	CALL	_log2
;MyProject.c,228 :: 		Glcd_Image(charmander_1);delay_ms(500);
	MOV	#lo_addr(_charmander_1), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	CALL	_Glcd_Image
	MOV	#8, W8
	MOV	#41252, W7
L_casoB98:
	DEC	W7
	BRA NZ	L_casoB98
	DEC	W8
	BRA NZ	L_casoB98
;MyProject.c,230 :: 		}else if(valores_cn[2]==1){
	GOTO	L_casoB100
L_casoB97:
	MOV	_valores_cn+4, W0
	CP	W0, #1
	BRA Z	L__casoB176
	GOTO	L_casoB101
L__casoB176:
;MyProject.c,231 :: 		log2("cn2");
	MOV	#lo_addr(?lstr10_MyProject), W10
	CALL	_log2
;MyProject.c,232 :: 		Glcd_PartialImage(60,24,18,18,18,18,bullet);delay_ms(500);
	MOV	#18, W13
	MOV	#18, W12
	MOV	#24, W11
	MOV	#60, W10
	MOV	#lo_addr(_bullet), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	MOV	#18, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
	MOV	#8, W8
	MOV	#41252, W7
L_casoB102:
	DEC	W7
	BRA NZ	L_casoB102
	DEC	W8
	BRA NZ	L_casoB102
;MyProject.c,234 :: 		}else if(valores_cn[3]==1){
	GOTO	L_casoB104
L_casoB101:
	MOV	_valores_cn+6, W0
	CP	W0, #1
	BRA Z	L__casoB177
	GOTO	L_casoB105
L__casoB177:
;MyProject.c,235 :: 		log2("cn3");
	MOV	#lo_addr(?lstr11_MyProject), W10
	CALL	_log2
;MyProject.c,236 :: 		Glcd_PartialImage(45,16,31,40,31,40,dog_1);delay_ms(500);
	MOV	#40, W13
	MOV	#31, W12
	MOV	#16, W11
	MOV	#45, W10
	MOV	#lo_addr(_dog_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#40, W0
	PUSH	W0
	MOV	#31, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
	MOV	#8, W8
	MOV	#41252, W7
L_casoB106:
	DEC	W7
	BRA NZ	L_casoB106
	DEC	W8
	BRA NZ	L_casoB106
;MyProject.c,238 :: 		}
L_casoB105:
L_casoB104:
L_casoB100:
L_casoB96:
;MyProject.c,240 :: 		Ps2_Key_Read(&keydata, &special, &down);
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
;MyProject.c,241 :: 		}while(keydata!=34 && !down & !special);
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#34, W0
	CP.B	W1, W0
	BRA NZ	L__casoB178
	GOTO	L__casoB139
L__casoB178:
	MOV	#lo_addr(_down), W0
	MOV.B	[W0], W0
	CP0.B	W0
	CLR.B	W1
	BRA NZ	L__casoB179
	INC.B	W1
L__casoB179:
	MOV	#lo_addr(_special), W0
	MOV.B	[W0], W0
	CP0.B	W0
	CLR.B	W0
	BRA NZ	L__casoB180
	INC.B	W0
L__casoB180:
	ZE	W1, W1
	ZE	W0, W0
	AND	W1, W0, W0
	BRA NZ	L__casoB181
	GOTO	L__casoB138
L__casoB181:
	GOTO	L_casoB90
L__casoB139:
L__casoB138:
;MyProject.c,243 :: 		}
L_end_casoB:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _casoB

_casoC:

;MyProject.c,256 :: 		void casoC(){
;MyProject.c,258 :: 		do{
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
L_casoC110:
;MyProject.c,260 :: 		down=0;
	MOV	#lo_addr(_down), W1
	CLR	W0
	MOV.B	W0, [W1]
;MyProject.c,261 :: 		special=0;
	MOV	#lo_addr(_special), W1
	CLR	W0
	MOV.B	W0, [W1]
;MyProject.c,262 :: 		if (RCONbits.WDTO==1){
	BTSS	RCONbits, #4
	GOTO	L_casoC113
;MyProject.c,263 :: 		Glcd_Write_TEXT("WDT",0,1,BLACK);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr12_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,264 :: 		RCONbits.WDTO=0;
	BCLR	RCONbits, #4
;MyProject.c,265 :: 		PORTEbits.RE5=1;
	BSET.B	PORTEbits, #5
;MyProject.c,266 :: 		}else if(RCONbits.EXTR==1){
	GOTO	L_casoC114
L_casoC113:
	BTSS	RCONbits, #7
	GOTO	L_casoC115
;MyProject.c,267 :: 		Glcd_Write_TEXT("MCLR",0,2,BLACK);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr13_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,268 :: 		RCONbits.EXTR=0;
	BCLR	RCONbits, #7
;MyProject.c,269 :: 		RCONbits.POR=0;
	BCLR	RCONbits, #0
;MyProject.c,270 :: 		PORTEbits.RE7=1;
	BSET.B	PORTEbits, #7
;MyProject.c,271 :: 		}else if (RCONbits.POR==1){
	GOTO	L_casoC116
L_casoC115:
	BTSS	RCONbits, #0
	GOTO	L_casoC117
;MyProject.c,272 :: 		Glcd_Write_TEXT("POR",0,3,BLACK);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr14_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,273 :: 		RCONbits.POR=0;
	BCLR	RCONbits, #0
;MyProject.c,274 :: 		PORTGbits.RG6=1;
	BSET	PORTGbits, #6
;MyProject.c,275 :: 		}
L_casoC117:
L_casoC116:
L_casoC114:
;MyProject.c,276 :: 		Ps2_Key_Read(&keydata, &special, &down);
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
;MyProject.c,277 :: 		}while(keydata!=34&&!down&&!special);
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#34, W0
	CP.B	W1, W0
	BRA NZ	L__casoC183
	GOTO	L__casoC143
L__casoC183:
	MOV	#lo_addr(_down), W0
	CP0.B	[W0]
	BRA Z	L__casoC184
	GOTO	L__casoC142
L__casoC184:
	MOV	#lo_addr(_special), W0
	CP0.B	[W0]
	BRA Z	L__casoC185
	GOTO	L__casoC141
L__casoC185:
	GOTO	L_casoC110
L__casoC143:
L__casoC142:
L__casoC141:
;MyProject.c,281 :: 		LATEbits.LATE6=0;
	BCLR.B	LATEbits, #6
;MyProject.c,282 :: 		LATEbits.LATE7=0;
	BCLR.B	LATEbits, #7
;MyProject.c,283 :: 		LATGbits.LATG6=0;
	BCLR	LATGbits, #6
;MyProject.c,285 :: 		}
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

;MyProject.c,287 :: 		void main(){
;MyProject.c,288 :: 		config_IO();
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CALL	_config_IO
;MyProject.c,289 :: 		config_LCD();
	CALL	_config_LCD
;MyProject.c,290 :: 		config_INT();
	CALL	_config_INT
;MyProject.c,291 :: 		config_CN();
	CALL	_config_CN
;MyProject.c,292 :: 		animate_charmander();
	CALL	_animate_charmander
;MyProject.c,293 :: 		PS2_Config();
	CALL	_Ps2_Config
;MyProject.c,294 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;MyProject.c,296 :: 		while(1){
L_main120:
;MyProject.c,297 :: 		Glcd_Write_TEXT("Laboratorio 1",31,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#31, W11
	MOV	#lo_addr(?lstr15_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,298 :: 		Glcd_Write_TEXT("'1' para Caso Q",0,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr16_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,299 :: 		Glcd_Write_TEXT("'2' para Caso W",0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr17_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,300 :: 		Glcd_Write_TEXT("'3' para Caso R",0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr18_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,301 :: 		Glcd_Write_TEXT("'4' para T   ",0,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	CLR	W11
	MOV	#lo_addr(?lstr19_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,302 :: 		if(Ps2_Key_Read(&keydata, &special, &down)){
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	CP0	W0
	BRA NZ	L__main187
	GOTO	L_main122
L__main187:
;MyProject.c,303 :: 		log2(keydata);
	MOV	#lo_addr(_keydata), W0
	ZE	[W0], W10
	CALL	_log2
;MyProject.c,304 :: 		if(down &&!special){
	MOV	#lo_addr(_down), W0
	CP0.B	[W0]
	BRA NZ	L__main188
	GOTO	L__main146
L__main188:
	MOV	#lo_addr(_special), W0
	CP0.B	[W0]
	BRA Z	L__main189
	GOTO	L__main145
L__main189:
L__main144:
;MyProject.c,305 :: 		switch(keydata){
	GOTO	L_main126
;MyProject.c,306 :: 		case 'q':
L_main128:
;MyProject.c,307 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;MyProject.c,312 :: 		break;
	GOTO	L_main127
;MyProject.c,314 :: 		case 'w':
L_main129:
;MyProject.c,315 :: 		Glcd_Write_TEXT("Caso W",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr20_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,316 :: 		casoB();
	CALL	_casoB
;MyProject.c,317 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;MyProject.c,318 :: 		break;
	GOTO	L_main127
;MyProject.c,320 :: 		case 'e':
L_main130:
;MyProject.c,321 :: 		Glcd_Write_TEXT("Caso E",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr21_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,322 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_main131:
	DEC	W7
	BRA NZ	L_main131
	DEC	W8
	BRA NZ	L_main131
;MyProject.c,323 :: 		Glcd_Fill(WHITE);
	CLR	W10
	CALL	_Glcd_Fill
;MyProject.c,324 :: 		Glcd_Write_TEXT("Ultimo Reset",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr22_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,325 :: 		casoC();
	CALL	_casoC
;MyProject.c,326 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;MyProject.c,327 :: 		break;
	GOTO	L_main127
;MyProject.c,329 :: 		case 'r':
L_main133:
;MyProject.c,330 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;MyProject.c,331 :: 		Glcd_Write_TEXT("Caso R ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr23_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,334 :: 		animate_kirby();
	CALL	_animate_kirby
;MyProject.c,335 :: 		RCONbits.SWDTEN=PORTDbits.RD9;
	BTSS	PORTDbits, #9
	BCLR	RCONbits, #5
	BTSC	PORTDbits, #9
	BSET	RCONbits, #5
;MyProject.c,336 :: 		Glcd_Write_TEXT("WDT ACTIVO",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr24_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,338 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;MyProject.c,339 :: 		break;
	GOTO	L_main127
;MyProject.c,341 :: 		default:
L_main134:
;MyProject.c,342 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;MyProject.c,343 :: 		Glcd_Write_TEXT("Erroneo ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr25_MyProject), W10
	CALL	_Glcd_Write_Text
;MyProject.c,344 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main135:
	DEC	W7
	BRA NZ	L_main135
	DEC	W8
	BRA NZ	L_main135
	NOP
	NOP
	NOP
	NOP
;MyProject.c,345 :: 		break;
	GOTO	L_main127
;MyProject.c,346 :: 		}
L_main126:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#113, W0
	CP.B	W1, W0
	BRA NZ	L__main190
	GOTO	L_main128
L__main190:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#119, W0
	CP.B	W1, W0
	BRA NZ	L__main191
	GOTO	L_main129
L__main191:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#101, W0
	CP.B	W1, W0
	BRA NZ	L__main192
	GOTO	L_main130
L__main192:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#114, W0
	CP.B	W1, W0
	BRA NZ	L__main193
	GOTO	L_main133
L__main193:
	GOTO	L_main134
L_main127:
;MyProject.c,304 :: 		if(down &&!special){
L__main146:
L__main145:
;MyProject.c,348 :: 		}
L_main122:
;MyProject.c,349 :: 		}
	GOTO	L_main120
;MyProject.c,350 :: 		}
L_end_main:
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
