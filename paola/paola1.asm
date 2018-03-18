
_barras:

;barras.h,16 :: 		void barras(int INTx,int contador_barra) {
;barras.h,18 :: 		bar_drawer(BARS_H_LOCATIONS[INTx],contador_barra);
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
;barras.h,19 :: 		IntToStr(contador_barra,txt);
	PUSH	W10
	MOV	W11, W10
	MOV	#lo_addr(_txt), W11
	CALL	_IntToStr
	POP	W10
;barras.h,20 :: 		Glcd_Write_Text(txt,BARS_H_LOCATIONS[INTx],0,1);
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
;barras.h,21 :: 		}
L_end_barras:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _barras

_bar_drawer:
	LNK	#2

;barras.h,23 :: 		void bar_drawer(unsigned short x_left,unsigned short contador_barra){
;barras.h,26 :: 		int x_right=x_left+BAR_WIDTH;
	PUSH	W11
	PUSH	W12
	PUSH	W13
	ZE	W10, W1
	ADD	W14, #0, W0
	ADD	W1, #5, [W0]
;barras.h,28 :: 		int contador_reset=DrawableBars(contador_barra);
	PUSH.D	W10
	ZE	W11, W10
	CALL	_DrawableBars
	POP.D	W10
; contador_reset start address is: 0 (W0)
;barras.h,29 :: 		if(contador_barra>1){
	CP.B	W11, #1
	BRA GTU	L__bar_drawer113
	GOTO	L_bar_drawer0
L__bar_drawer113:
;barras.h,30 :: 		if (contador_reset==1){
	CP	W0, #1
	BRA Z	L__bar_drawer114
	GOTO	L_bar_drawer1
L__bar_drawer114:
; contador_reset end address is: 0 (W0)
;barras.h,32 :: 		Glcd_Box(x_left,MAX_BAR_HEIGHT,x_right,BAR_HEIGHT,WHITE);
	MOV.B	#4, W13
	MOV.B	[W14+0], W12
	MOV.B	#100, W11
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
;barras.h,33 :: 		}
	GOTO	L_bar_drawer2
L_bar_drawer1:
;barras.h,36 :: 		y_bottom=DrawableBars(contador_barra)*BAR_HEIGHT;
	PUSH	W10
	ZE	W11, W10
	CALL	_DrawableBars
	POP	W10
	SL	W0, #2, W1
;barras.h,37 :: 		y_top=y_bottom+BAR_HEIGHT;
	ADD	W1, #4, W0
;barras.h,38 :: 		Glcd_Box(x_left,y_top,x_right,y_bottom,BLACK);
	MOV.B	W1, W13
	MOV.B	[W14+0], W12
	MOV.B	W0, W11
	MOV.B	#1, W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
;barras.h,39 :: 		}
L_bar_drawer2:
;barras.h,40 :: 		}
L_bar_drawer0:
;barras.h,41 :: 		}
L_end_bar_drawer:
	POP	W13
	POP	W12
	POP	W11
	ULNK
	RETURN
; end of _bar_drawer

_DrawableBars:

;barras.h,42 :: 		int DrawableBars(int real_number_of_bars){
;barras.h,45 :: 		if(real_number_of_bars>25){
	PUSH	W11
	CP	W10, #25
	BRA GT	L__DrawableBars116
	GOTO	L_DrawableBars3
L__DrawableBars116:
;barras.h,46 :: 		int quotient=real_number_of_bars/25;
	MOV	#25, W2
	REPEAT	#17
	DIV.S	W10, W2
;barras.h,47 :: 		quotient=floor(quotient);
	PUSH	W10
	ASR	W0, #15, W1
	SETM	W2
	CALL	__Long2Float
	MOV.D	W0, W10
	CALL	_floor
	CALL	__Float2Longint
	POP	W10
;barras.h,48 :: 		return real_number_of_bars-25*quotient;
	MOV	#25, W1
	MUL.SS	W1, W0, W0
	SUB	W10, W0, W0
	GOTO	L_end_DrawableBars
;barras.h,49 :: 		}else{
L_DrawableBars3:
;barras.h,50 :: 		return real_number_of_bars;
	MOV	W10, W0
;barras.h,52 :: 		}
;barras.h,50 :: 		return real_number_of_bars;
;barras.h,52 :: 		}
L_end_DrawableBars:
	POP	W11
	RETURN
; end of _DrawableBars

_animate_charmander:

;sprites.h,33 :: 		void animate_charmander(){
;sprites.h,35 :: 		Glcd_Image(charmander_1);
	PUSH	W10
	PUSH	W11
	MOV	#___Lib_System_DefaultPage, W0
	MOV	#lo_addr(_charmander_1), W10
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
	MOV	#___Lib_System_DefaultPage, W0
	MOV	#lo_addr(_charmander_2), W10
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
	POP	W11
	POP	W10
	RETURN
; end of _animate_charmander

_animate_blooper_20s:

;sprites.h,73 :: 		void animate_blooper_20s(){
;sprites.h,74 :: 		Glcd_Rectangle(0,8,127,64,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	MOV	#1, W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,75 :: 		Glcd_PartialImage(63,16,35,34,35,34,blooper_1);
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
;sprites.h,76 :: 		delay_ms(5000);
	MOV	#77, W8
	MOV	#19309, W7
L_animate_blooper_20s9:
	DEC	W7
	BRA NZ	L_animate_blooper_20s9
	DEC	W8
	BRA NZ	L_animate_blooper_20s9
	NOP
	NOP
;sprites.h,77 :: 		Glcd_Rectangle(0,8,127,64,1);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	MOV	#1, W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,78 :: 		Glcd_PartialImage(63,16,35,34,35,34,blooper_2);
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
;sprites.h,79 :: 		delay_ms(5000);
	MOV	#77, W8
	MOV	#19309, W7
L_animate_blooper_20s11:
	DEC	W7
	BRA NZ	L_animate_blooper_20s11
	DEC	W8
	BRA NZ	L_animate_blooper_20s11
	NOP
	NOP
;sprites.h,80 :: 		Glcd_Rectangle(0,8,127,64,1);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	MOV	#1, W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,81 :: 		Glcd_PartialImage(63,16,35,34,35,34,blooper_3);
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
;sprites.h,82 :: 		delay_ms(5000);
	MOV	#77, W8
	MOV	#19309, W7
L_animate_blooper_20s13:
	DEC	W7
	BRA NZ	L_animate_blooper_20s13
	DEC	W8
	BRA NZ	L_animate_blooper_20s13
	NOP
	NOP
;sprites.h,83 :: 		Glcd_Rectangle(0,8,127,64,1);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	MOV	#1, W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,84 :: 		Glcd_PartialImage(63,16,35,34,35,34,blooper_4);
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
;sprites.h,85 :: 		delay_ms(5000);
	MOV	#77, W8
	MOV	#19309, W7
L_animate_blooper_20s15:
	DEC	W7
	BRA NZ	L_animate_blooper_20s15
	DEC	W8
	BRA NZ	L_animate_blooper_20s15
	NOP
	NOP
;sprites.h,86 :: 		}
L_end_animate_blooper_20s:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _animate_blooper_20s

_animate_bullet:

;sprites.h,97 :: 		void animate_bullet(){
;sprites.h,99 :: 		for(i=108;i-10;i<19){
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
; i start address is: 22 (W11)
	MOV	#108, W11
; i end address is: 22 (W11)
L_animate_bullet17:
; i start address is: 22 (W11)
	SUB	W11, #10, W0
	BRA NZ	L__animate_bullet120
	GOTO	L_animate_bullet18
L__animate_bullet120:
;sprites.h,100 :: 		Glcd_Fill(00);
	CLR	W10
	CALL	_Glcd_Fill
;sprites.h,101 :: 		Glcd_PartialImage(i,24,18,18,18,18,bullet);
	PUSH	W11
	MOV	#18, W13
	MOV	#18, W12
	MOV	W11, W10
	MOV	#24, W11
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
	POP	W11
;sprites.h,102 :: 		delay_ms(250);
	MOV	#4, W8
	MOV	#53393, W7
L_animate_bullet20:
	DEC	W7
	BRA NZ	L_animate_bullet20
	DEC	W8
	BRA NZ	L_animate_bullet20
	NOP
	NOP
	NOP
;sprites.h,103 :: 		}
; i end address is: 22 (W11)
	GOTO	L_animate_bullet17
L_animate_bullet18:
;sprites.h,104 :: 		}
L_end_animate_bullet:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _animate_bullet

_animate_shell_20s:

;sprites.h,129 :: 		void animate_shell_20s(){
;sprites.h,130 :: 		Glcd_Rectangle(0,8,127,64,0);
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
;sprites.h,131 :: 		Glcd_PartialImage(125,56,16,16,16,16,shell_1);
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
;sprites.h,132 :: 		delay_ms(4000);
	MOV	#62, W8
	MOV	#2340, W7
L_animate_shell_20s22:
	DEC	W7
	BRA NZ	L_animate_shell_20s22
	DEC	W8
	BRA NZ	L_animate_shell_20s22
	NOP
	NOP
;sprites.h,133 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,134 :: 		Glcd_PartialImage(100,56,16,16,16,16,shell_2);
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
;sprites.h,135 :: 		delay_ms(4000);
	MOV	#62, W8
	MOV	#2340, W7
L_animate_shell_20s24:
	DEC	W7
	BRA NZ	L_animate_shell_20s24
	DEC	W8
	BRA NZ	L_animate_shell_20s24
	NOP
	NOP
;sprites.h,136 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,137 :: 		Glcd_PartialImage(75,56,16,16,16,16,shell_3);
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
;sprites.h,138 :: 		delay_ms(4000);
	MOV	#62, W8
	MOV	#2340, W7
L_animate_shell_20s26:
	DEC	W7
	BRA NZ	L_animate_shell_20s26
	DEC	W8
	BRA NZ	L_animate_shell_20s26
	NOP
	NOP
;sprites.h,139 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,140 :: 		Glcd_PartialImage(50,56,16,16,16,16,shell_1);
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
;sprites.h,141 :: 		delay_ms(4000);
	MOV	#62, W8
	MOV	#2340, W7
L_animate_shell_20s28:
	DEC	W7
	BRA NZ	L_animate_shell_20s28
	DEC	W8
	BRA NZ	L_animate_shell_20s28
	NOP
	NOP
;sprites.h,142 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,143 :: 		Glcd_PartialImage(25,56,16,16,16,16,shell_2);
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
;sprites.h,144 :: 		delay_ms(4000);
	MOV	#62, W8
	MOV	#2340, W7
L_animate_shell_20s30:
	DEC	W7
	BRA NZ	L_animate_shell_20s30
	DEC	W8
	BRA NZ	L_animate_shell_20s30
	NOP
	NOP
;sprites.h,146 :: 		}
L_end_animate_shell_20s:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _animate_shell_20s

_animate_dog_20s:

;sprites.h,183 :: 		void animate_dog_20s(){
;sprites.h,184 :: 		Glcd_Rectangle(0,8,127,64,0);
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
;sprites.h,185 :: 		Glcd_PartialImage(45,16,31,40,31,40,dog_1);
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
;sprites.h,186 :: 		delay_ms(4000);
	MOV	#62, W8
	MOV	#2340, W7
L_animate_dog_20s32:
	DEC	W7
	BRA NZ	L_animate_dog_20s32
	DEC	W8
	BRA NZ	L_animate_dog_20s32
	NOP
	NOP
;sprites.h,187 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,188 :: 		Glcd_PartialImage(45,16,31,40,31,40,dog_2);
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
;sprites.h,189 :: 		delay_ms(4000);
	MOV	#62, W8
	MOV	#2340, W7
L_animate_dog_20s34:
	DEC	W7
	BRA NZ	L_animate_dog_20s34
	DEC	W8
	BRA NZ	L_animate_dog_20s34
	NOP
	NOP
;sprites.h,190 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,191 :: 		Glcd_PartialImage(45,16,31,40,31,40,dog_3);
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
;sprites.h,192 :: 		delay_ms(4000);
	MOV	#62, W8
	MOV	#2340, W7
L_animate_dog_20s36:
	DEC	W7
	BRA NZ	L_animate_dog_20s36
	DEC	W8
	BRA NZ	L_animate_dog_20s36
	NOP
	NOP
;sprites.h,193 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,194 :: 		Glcd_PartialImage(45,16,31,40,31,40,dog_1);
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
;sprites.h,195 :: 		delay_ms(4000);
	MOV	#62, W8
	MOV	#2340, W7
L_animate_dog_20s38:
	DEC	W7
	BRA NZ	L_animate_dog_20s38
	DEC	W8
	BRA NZ	L_animate_dog_20s38
	NOP
	NOP
;sprites.h,196 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,197 :: 		Glcd_PartialImage(45,16,31,40,31,40,dog_2);
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
;sprites.h,198 :: 		delay_ms(4000);
	MOV	#62, W8
	MOV	#2340, W7
L_animate_dog_20s40:
	DEC	W7
	BRA NZ	L_animate_dog_20s40
	DEC	W8
	BRA NZ	L_animate_dog_20s40
	NOP
	NOP
;sprites.h,199 :: 		}
L_end_animate_dog_20s:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _animate_dog_20s

_animate_kirby:

;sprites.h,261 :: 		void animate_kirby(){
;sprites.h,262 :: 		Glcd_Rectangle(0,8,127,64,0);
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
;sprites.h,263 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_1);
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
;sprites.h,264 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby42:
	DEC	W7
	BRA NZ	L_animate_kirby42
	DEC	W8
	BRA NZ	L_animate_kirby42
	NOP
;sprites.h,265 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,266 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_2);
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
;sprites.h,267 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby44:
	DEC	W7
	BRA NZ	L_animate_kirby44
	DEC	W8
	BRA NZ	L_animate_kirby44
	NOP
;sprites.h,268 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,269 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_3);
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
;sprites.h,270 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby46:
	DEC	W7
	BRA NZ	L_animate_kirby46
	DEC	W8
	BRA NZ	L_animate_kirby46
	NOP
;sprites.h,271 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,272 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_4);
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
;sprites.h,273 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby48:
	DEC	W7
	BRA NZ	L_animate_kirby48
	DEC	W8
	BRA NZ	L_animate_kirby48
	NOP
;sprites.h,274 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,275 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_5);
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
;sprites.h,276 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby50:
	DEC	W7
	BRA NZ	L_animate_kirby50
	DEC	W8
	BRA NZ	L_animate_kirby50
	NOP
;sprites.h,277 :: 		Glcd_Rectangle(0,8,127,64,0);
	MOV.B	#64, W13
	MOV.B	#127, W12
	MOV.B	#8, W11
	CLR	W10
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Rectangle
	SUB	#2, W15
;sprites.h,278 :: 		Glcd_PartialImage(21,20,21,19,21,19,kirby_6);
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
;sprites.h,279 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_animate_kirby52:
	DEC	W7
	BRA NZ	L_animate_kirby52
	DEC	W8
	BRA NZ	L_animate_kirby52
	NOP
;sprites.h,280 :: 		}
L_end_animate_kirby:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _animate_kirby

_casoC:

;paola1.c,59 :: 		void casoC(){
;paola1.c,60 :: 		Glcd_Write_TEXT("Ultimo Reset",60,0,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr1_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,61 :: 		do{
L_casoC54:
;paola1.c,62 :: 		if (RCONbits.WDTO==1){
	BTSS	RCONbits, #4
	GOTO	L_casoC57
;paola1.c,63 :: 		Glcd_Write_TEXT("WDT",0,1,BLACK);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr2_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,64 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_casoC58:
	DEC	W7
	BRA NZ	L_casoC58
	DEC	W8
	BRA NZ	L_casoC58
;paola1.c,65 :: 		RCONbits.WDTO=0;
	BCLR	RCONbits, #4
;paola1.c,66 :: 		}else if(RCONbits.EXTR==1){
	GOTO	L_casoC60
L_casoC57:
	BTSS	RCONbits, #7
	GOTO	L_casoC61
;paola1.c,67 :: 		Glcd_Write_TEXT("MCLR",0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr3_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,68 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_casoC62:
	DEC	W7
	BRA NZ	L_casoC62
	DEC	W8
	BRA NZ	L_casoC62
;paola1.c,69 :: 		RCONbits.EXTR=0;
	BCLR	RCONbits, #7
;paola1.c,70 :: 		}else if (RCONbits.POR==1){
	GOTO	L_casoC64
L_casoC61:
	BTSS	RCONbits, #0
	GOTO	L_casoC65
;paola1.c,71 :: 		Glcd_Write_TEXT("POR",0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr4_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,72 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_casoC66:
	DEC	W7
	BRA NZ	L_casoC66
	DEC	W8
	BRA NZ	L_casoC66
;paola1.c,73 :: 		RCONbits.POR=0;
	BCLR	RCONbits, #0
;paola1.c,74 :: 		}
L_casoC65:
L_casoC64:
L_casoC60:
;paola1.c,75 :: 		while(Ps2_Key_Read(&keydata, &special, &down));
L_casoC68:
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	CP0	W0
	BRA NZ	L__casoC125
	GOTO	L_casoC69
L__casoC125:
	GOTO	L_casoC68
L_casoC69:
;paola1.c,76 :: 		}while(op!=34);
	MOV	#34, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA Z	L__casoC126
	GOTO	L_casoC54
L__casoC126:
;paola1.c,77 :: 		op='c';
	MOV	#99, W0
	MOV	W0, _op
;paola1.c,78 :: 		}
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

;paola1.c,79 :: 		void main(){
;paola1.c,80 :: 		ANSELC=0; ANSELD=0; ANSELE=0;                  //ANALOGICO SON B Y F
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CLR	ANSELC
	CLR	ANSELD
	CLR	ANSELE
;paola1.c,84 :: 		LATB = 0;              // Set PORTB to zero
	CLR	LATB
;paola1.c,85 :: 		ANSELB = 0;
	CLR	ANSELB
;paola1.c,86 :: 		TRISB = 0;             // Initialize PORTB as output
	CLR	TRISB
;paola1.c,87 :: 		Glcd_Init();
	CALL	_Glcd_Init
;paola1.c,88 :: 		Glcd_Set_Font(font5x7 , 5, 7, 32);
	MOV	#___Lib_System_DefaultPage, W0
	MOV.B	#7, W13
	MOV.B	#5, W12
	MOV	#lo_addr(_font5x7), W10
	MOV	W0, W11
	MOV	#32, W0
	PUSH	W0
	CALL	_Glcd_Set_Font
	SUB	#2, W15
;paola1.c,89 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;paola1.c,90 :: 		PS2_Config();
	CALL	_Ps2_Config
;paola1.c,91 :: 		Glcd_Write_TEXT("Laboratorio 1",31,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#31, W11
	MOV	#lo_addr(?lstr5_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,92 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main70:
	DEC	W7
	BRA NZ	L_main70
	DEC	W8
	BRA NZ	L_main70
	NOP
	NOP
	NOP
	NOP
;paola1.c,93 :: 		while(1){
L_main72:
;paola1.c,94 :: 		LATB = ~LATB; // Invert PORTB value
	COM	LATB
;paola1.c,95 :: 		Glcd_Write_TEXT("Laboratorio 1",31,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#31, W11
	MOV	#lo_addr(?lstr6_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,96 :: 		Glcd_Image(camion);
	MOV	#___Lib_System_DefaultPage, W0
	MOV	#lo_addr(_camion), W10
	MOV	W0, W11
	CALL	_Glcd_Image
;paola1.c,97 :: 		animate_kirby();
	CALL	_animate_kirby
;paola1.c,98 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main74:
	DEC	W7
	BRA NZ	L_main74
	DEC	W8
	BRA NZ	L_main74
	NOP
	NOP
	NOP
	NOP
;paola1.c,99 :: 		animate_bullet();
	CALL	_animate_bullet
;paola1.c,100 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main76:
	DEC	W7
	BRA NZ	L_main76
	DEC	W8
	BRA NZ	L_main76
	NOP
	NOP
	NOP
	NOP
;paola1.c,101 :: 		animate_blooper_20s();
	CALL	_animate_blooper_20s
;paola1.c,102 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main78:
	DEC	W7
	BRA NZ	L_main78
	DEC	W8
	BRA NZ	L_main78
	NOP
	NOP
	NOP
	NOP
;paola1.c,103 :: 		animate_dog_20s();
	CALL	_animate_dog_20s
;paola1.c,104 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main80:
	DEC	W7
	BRA NZ	L_main80
	DEC	W8
	BRA NZ	L_main80
	NOP
	NOP
	NOP
	NOP
;paola1.c,105 :: 		animate_shell_20s();
	CALL	_animate_shell_20s
;paola1.c,106 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main82:
	DEC	W7
	BRA NZ	L_main82
	DEC	W8
	BRA NZ	L_main82
	NOP
	NOP
	NOP
	NOP
;paola1.c,107 :: 		animate_charmander();
	CALL	_animate_charmander
;paola1.c,108 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main84:
	DEC	W7
	BRA NZ	L_main84
	DEC	W8
	BRA NZ	L_main84
	NOP
	NOP
	NOP
	NOP
;paola1.c,109 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;paola1.c,110 :: 		Glcd_Write_TEXT("Presione 'A' para Caso 1",0,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr7_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,111 :: 		Glcd_Write_TEXT("Presione 'B' para Caso 2",0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr8_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,112 :: 		Glcd_Write_TEXT("Presione 'C' para Caso 3",0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr9_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,113 :: 		Glcd_Write_TEXT("Presione 'D' para WDT   ",0,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	CLR	W11
	MOV	#lo_addr(?lstr10_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,114 :: 		delay_ms(3000);
	MOV	#46, W8
	MOV	#50906, W7
L_main86:
	DEC	W7
	BRA NZ	L_main86
	DEC	W8
	BRA NZ	L_main86
	NOP
	NOP
	NOP
	NOP
;paola1.c,116 :: 		while(op!=34){
L_main88:
	MOV	#34, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main128
	GOTO	L_main89
L__main128:
;paola1.c,117 :: 		if(Ps2_Key_Read(&keydata, &special, &down)){
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	CP0	W0
	BRA NZ	L__main129
	GOTO	L_main90
L__main129:
;paola1.c,118 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;paola1.c,119 :: 		switch(op){
	GOTO	L_main91
;paola1.c,120 :: 		case 'a':
L_main93:
;paola1.c,121 :: 		Glcd_Write_TEXT("Caso A",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr11_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,122 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main94:
	DEC	W7
	BRA NZ	L_main94
	DEC	W8
	BRA NZ	L_main94
	NOP
	NOP
	NOP
	NOP
;paola1.c,123 :: 		op=keydata;
	MOV	#lo_addr(_keydata), W0
	ZE	[W0], W0
	MOV	W0, _op
;paola1.c,124 :: 		break;
	GOTO	L_main92
;paola1.c,126 :: 		case 'b':
L_main96:
;paola1.c,127 :: 		Glcd_Write_TEXT("Caso B ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr12_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,128 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main97:
	DEC	W7
	BRA NZ	L_main97
	DEC	W8
	BRA NZ	L_main97
	NOP
	NOP
	NOP
	NOP
;paola1.c,129 :: 		op=keydata;
	MOV	#lo_addr(_keydata), W0
	ZE	[W0], W0
	MOV	W0, _op
;paola1.c,130 :: 		break;
	GOTO	L_main92
;paola1.c,132 :: 		case 'c':
L_main99:
;paola1.c,133 :: 		Glcd_Write_TEXT("Caso C ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr13_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,134 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main100:
	DEC	W7
	BRA NZ	L_main100
	DEC	W8
	BRA NZ	L_main100
	NOP
	NOP
	NOP
	NOP
;paola1.c,135 :: 		casoC();
	CALL	_casoC
;paola1.c,136 :: 		op=keydata;
	MOV	#lo_addr(_keydata), W0
	ZE	[W0], W0
	MOV	W0, _op
;paola1.c,137 :: 		break;
	GOTO	L_main92
;paola1.c,139 :: 		case 'd':
L_main102:
;paola1.c,140 :: 		Glcd_Write_TEXT("Caso D ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr14_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,141 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main103:
	DEC	W7
	BRA NZ	L_main103
	DEC	W8
	BRA NZ	L_main103
	NOP
	NOP
	NOP
	NOP
;paola1.c,142 :: 		op=keydata;
	MOV	#lo_addr(_keydata), W0
	ZE	[W0], W0
	MOV	W0, _op
;paola1.c,143 :: 		break;
	GOTO	L_main92
;paola1.c,145 :: 		case 34:
L_main105:
;paola1.c,146 :: 		Glcd_Write_TEXT("Menu Principal ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr15_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,147 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main106:
	DEC	W7
	BRA NZ	L_main106
	DEC	W8
	BRA NZ	L_main106
	NOP
	NOP
	NOP
	NOP
;paola1.c,148 :: 		op=keydata;
	MOV	#lo_addr(_keydata), W0
	ZE	[W0], W0
	MOV	W0, _op
;paola1.c,149 :: 		break;
	GOTO	L_main92
;paola1.c,150 :: 		default:
L_main108:
;paola1.c,151 :: 		Glcd_Write_TEXT("Erroneo ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr16_paola1), W10
	CALL	_Glcd_Write_Text
;paola1.c,152 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_main109:
	DEC	W7
	BRA NZ	L_main109
	DEC	W8
	BRA NZ	L_main109
	NOP
	NOP
	NOP
	NOP
;paola1.c,153 :: 		break;
	GOTO	L_main92
;paola1.c,154 :: 		}
L_main91:
	MOV	#97, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main130
	GOTO	L_main93
L__main130:
	MOV	#98, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main131
	GOTO	L_main96
L__main131:
	MOV	#99, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main132
	GOTO	L_main99
L__main132:
	MOV	#100, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main133
	GOTO	L_main102
L__main133:
	MOV	#34, W1
	MOV	#lo_addr(_op), W0
	CP	W1, [W0]
	BRA NZ	L__main134
	GOTO	L_main105
L__main134:
	GOTO	L_main108
L_main92:
;paola1.c,155 :: 		}
L_main90:
;paola1.c,156 :: 		}
	GOTO	L_main88
L_main89:
;paola1.c,157 :: 		}
	GOTO	L_main72
;paola1.c,158 :: 		}
L_end_main:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
