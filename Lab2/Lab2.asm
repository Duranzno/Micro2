
_animate_bell_5s:

;sprites.h,77 :: 		void animate_bell_5s(){
;sprites.h,78 :: 		Glcd_PartialImage(32,2,60,60,60,60,bell_1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV	#60, W13
	MOV	#60, W12
	MOV	#2, W11
	MOV	#32, W10
	MOV	#lo_addr(_bell_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#60, W0
	PUSH	W0
	MOV	#60, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,79 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_animate_bell_5s0:
	DEC	W7
	BRA NZ	L_animate_bell_5s0
	DEC	W8
	BRA NZ	L_animate_bell_5s0
;sprites.h,80 :: 		Glcd_PartialImage(32,2,60,60,60,60,bell_2);
	MOV	#60, W13
	MOV	#60, W12
	MOV	#2, W11
	MOV	#32, W10
	MOV	#lo_addr(_bell_2), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#60, W0
	PUSH	W0
	MOV	#60, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,81 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_animate_bell_5s2:
	DEC	W7
	BRA NZ	L_animate_bell_5s2
	DEC	W8
	BRA NZ	L_animate_bell_5s2
;sprites.h,82 :: 		Glcd_PartialImage(32,2,60,60,60,60,bell_1);
	MOV	#60, W13
	MOV	#60, W12
	MOV	#2, W11
	MOV	#32, W10
	MOV	#lo_addr(_bell_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#60, W0
	PUSH	W0
	MOV	#60, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,83 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_animate_bell_5s4:
	DEC	W7
	BRA NZ	L_animate_bell_5s4
	DEC	W8
	BRA NZ	L_animate_bell_5s4
;sprites.h,84 :: 		Glcd_PartialImage(32,2,60,60,60,60,bell_3);
	MOV	#60, W13
	MOV	#60, W12
	MOV	#2, W11
	MOV	#32, W10
	MOV	#lo_addr(_bell_3), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#60, W0
	PUSH	W0
	MOV	#60, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,85 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_animate_bell_5s6:
	DEC	W7
	BRA NZ	L_animate_bell_5s6
	DEC	W8
	BRA NZ	L_animate_bell_5s6
;sprites.h,86 :: 		Glcd_PartialImage(32,2,60,60,60,60,bell_1);
	MOV	#60, W13
	MOV	#60, W12
	MOV	#2, W11
	MOV	#32, W10
	MOV	#lo_addr(_bell_1), W0
	PUSH	W0
	MOV	#___Lib_System_DefaultPage, W0
	PUSH	W0
	MOV	#60, W0
	PUSH	W0
	MOV	#60, W0
	PUSH	W0
	CALL	_Glcd_PartialImage
	SUB	#4, W15
;sprites.h,87 :: 		}
L_end_animate_bell_5s:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _animate_bell_5s

_animate_charmander_5s:

;sprites.h,89 :: 		void animate_charmander_5s(){
;sprites.h,90 :: 		Glcd_Image(charmander_1);
	PUSH	W10
	MOV	#lo_addr(_charmander_1), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	CALL	_Glcd_Image
;sprites.h,91 :: 		delay_ms(250);
	MOV	#4, W8
	MOV	#53393, W7
L_animate_charmander_5s8:
	DEC	W7
	BRA NZ	L_animate_charmander_5s8
	DEC	W8
	BRA NZ	L_animate_charmander_5s8
	NOP
	NOP
	NOP
;sprites.h,93 :: 		Glcd_Image(charmander_2);
	MOV	#lo_addr(_charmander_2), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	CALL	_Glcd_Image
;sprites.h,94 :: 		delay_ms(250);
	MOV	#4, W8
	MOV	#53393, W7
L_animate_charmander_5s10:
	DEC	W7
	BRA NZ	L_animate_charmander_5s10
	DEC	W8
	BRA NZ	L_animate_charmander_5s10
	NOP
	NOP
	NOP
;sprites.h,95 :: 		}
L_end_animate_charmander_5s:
	POP	W10
	RETURN
; end of _animate_charmander_5s

_animate_charmander_20s:

;sprites.h,96 :: 		void animate_charmander_20s(){
;sprites.h,97 :: 		animate_charmander_5s();
	CALL	_animate_charmander_5s
;sprites.h,98 :: 		animate_charmander_5s();
	CALL	_animate_charmander_5s
;sprites.h,99 :: 		animate_charmander_5s();
	CALL	_animate_charmander_5s
;sprites.h,100 :: 		animate_charmander_5s();
	CALL	_animate_charmander_5s
;sprites.h,101 :: 		}
L_end_animate_charmander_20s:
	RETURN
; end of _animate_charmander_20s

_page2pos:

;extras.h,1 :: 		int page2pos(int page_num){
;extras.h,2 :: 		switch(page_num){
	GOTO	L_page2pos12
;extras.h,3 :: 		case 0:
L_page2pos14:
;extras.h,4 :: 		return 0;
	CLR	W0
	GOTO	L_end_page2pos
;extras.h,6 :: 		case 1:
L_page2pos15:
;extras.h,7 :: 		return 8;
	MOV	#8, W0
	GOTO	L_end_page2pos
;extras.h,9 :: 		case 2:
L_page2pos16:
;extras.h,10 :: 		return 16;
	MOV	#16, W0
	GOTO	L_end_page2pos
;extras.h,12 :: 		case 3:
L_page2pos17:
;extras.h,13 :: 		return 24;
	MOV	#24, W0
	GOTO	L_end_page2pos
;extras.h,15 :: 		case 4:
L_page2pos18:
;extras.h,16 :: 		return 32;
	MOV	#32, W0
	GOTO	L_end_page2pos
;extras.h,18 :: 		case 5:
L_page2pos19:
;extras.h,19 :: 		return 40;
	MOV	#40, W0
	GOTO	L_end_page2pos
;extras.h,21 :: 		case 6:
L_page2pos20:
;extras.h,22 :: 		return 48;
	MOV	#48, W0
	GOTO	L_end_page2pos
;extras.h,24 :: 		case 7:
L_page2pos21:
;extras.h,25 :: 		return 56;
	MOV	#56, W0
	GOTO	L_end_page2pos
;extras.h,27 :: 		}
L_page2pos12:
	CP	W10, #0
	BRA NZ	L__page2pos163
	GOTO	L_page2pos14
L__page2pos163:
	CP	W10, #1
	BRA NZ	L__page2pos164
	GOTO	L_page2pos15
L__page2pos164:
	CP	W10, #2
	BRA NZ	L__page2pos165
	GOTO	L_page2pos16
L__page2pos165:
	CP	W10, #3
	BRA NZ	L__page2pos166
	GOTO	L_page2pos17
L__page2pos166:
	CP	W10, #4
	BRA NZ	L__page2pos167
	GOTO	L_page2pos18
L__page2pos167:
	CP	W10, #5
	BRA NZ	L__page2pos168
	GOTO	L_page2pos19
L__page2pos168:
	CP	W10, #6
	BRA NZ	L__page2pos169
	GOTO	L_page2pos20
L__page2pos169:
	CP	W10, #7
	BRA NZ	L__page2pos170
	GOTO	L_page2pos21
L__page2pos170:
;extras.h,28 :: 		}
L_end_page2pos:
	RETURN
; end of _page2pos

_intToAscii:
	LNK	#2

;extras.h,29 :: 		char intToAscii(int fn){
;extras.h,30 :: 		char t=0;
	PUSH	W11
	MOV	#0, W0
	MOV.B	W0, [W14+0]
;extras.h,31 :: 		if(fn>0&&fn<=9){
	CP	W10, #0
	BRA GT	L__intToAscii172
	GOTO	L__intToAscii140
L__intToAscii172:
	CP	W10, #9
	BRA LE	L__intToAscii173
	GOTO	L__intToAscii139
L__intToAscii173:
L__intToAscii138:
;extras.h,32 :: 		intToStr(fn,t);
	ADD	W14, #0, W0
	ZE	[W0], W11
	CALL	_IntToStr
;extras.h,33 :: 		}else if(fn==10){
	GOTO	L_intToAscii25
;extras.h,31 :: 		if(fn>0&&fn<=9){
L__intToAscii140:
L__intToAscii139:
;extras.h,33 :: 		}else if(fn==10){
	CP	W10, #10
	BRA Z	L__intToAscii174
	GOTO	L_intToAscii26
L__intToAscii174:
;extras.h,34 :: 		intToStr(0,t);
	ADD	W14, #0, W0
	PUSH	W10
	ZE	[W0], W11
	CLR	W10
	CALL	_IntToStr
	POP	W10
;extras.h,35 :: 		}else{
	GOTO	L_intToAscii27
L_intToAscii26:
;extras.h,36 :: 		t='0';
	MOV.B	#48, W0
	MOV.B	W0, [W14+0]
;extras.h,37 :: 		}
L_intToAscii27:
L_intToAscii25:
;extras.h,38 :: 		return t;
	MOV.B	[W14+0], W0
;extras.h,39 :: 		}
;extras.h,38 :: 		return t;
;extras.h,39 :: 		}
L_end_intToAscii:
	POP	W11
	ULNK
	RETURN
; end of _intToAscii

_oscilador_usado:

;extras.h,40 :: 		void oscilador_usado(){
;extras.h,41 :: 		switch(OSCCONBits.COSC){
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	GOTO	L_oscilador_usado28
;extras.h,42 :: 		case 0:
L_oscilador_usado30:
;extras.h,43 :: 		glcd_write_text("FRC",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr1_Lab2), W10
	CALL	_Glcd_Write_Text
;extras.h,44 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado31:
	DEC	W7
	BRA NZ	L_oscilador_usado31
	DEC	W8
	BRA NZ	L_oscilador_usado31
	NOP
	NOP
	NOP
	NOP
;extras.h,45 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,46 :: 		break;
	GOTO	L_oscilador_usado29
;extras.h,47 :: 		case 1:
L_oscilador_usado33:
;extras.h,48 :: 		glcd_write_text("FRCPLL",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr2_Lab2), W10
	CALL	_Glcd_Write_Text
;extras.h,49 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado34:
	DEC	W7
	BRA NZ	L_oscilador_usado34
	DEC	W8
	BRA NZ	L_oscilador_usado34
	NOP
	NOP
	NOP
	NOP
;extras.h,50 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,51 :: 		break;
	GOTO	L_oscilador_usado29
;extras.h,52 :: 		case 2:
L_oscilador_usado36:
;extras.h,53 :: 		glcd_write_text("posc",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr3_Lab2), W10
	CALL	_Glcd_Write_Text
;extras.h,54 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado37:
	DEC	W7
	BRA NZ	L_oscilador_usado37
	DEC	W8
	BRA NZ	L_oscilador_usado37
	NOP
	NOP
	NOP
	NOP
;extras.h,55 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,56 :: 		break;
	GOTO	L_oscilador_usado29
;extras.h,57 :: 		case 3:
L_oscilador_usado39:
;extras.h,58 :: 		glcd_write_text("posc_pll",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr4_Lab2), W10
	CALL	_Glcd_Write_Text
;extras.h,59 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado40:
	DEC	W7
	BRA NZ	L_oscilador_usado40
	DEC	W8
	BRA NZ	L_oscilador_usado40
	NOP
	NOP
	NOP
	NOP
;extras.h,60 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,61 :: 		break;
	GOTO	L_oscilador_usado29
;extras.h,62 :: 		case 4:
L_oscilador_usado42:
;extras.h,63 :: 		glcd_write_text("sosc",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr5_Lab2), W10
	CALL	_Glcd_Write_Text
;extras.h,64 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado43:
	DEC	W7
	BRA NZ	L_oscilador_usado43
	DEC	W8
	BRA NZ	L_oscilador_usado43
	NOP
	NOP
	NOP
	NOP
;extras.h,65 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,66 :: 		break;
	GOTO	L_oscilador_usado29
;extras.h,67 :: 		case 5:
L_oscilador_usado45:
;extras.h,68 :: 		glcd_write_text("lprc",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr6_Lab2), W10
	CALL	_Glcd_Write_Text
;extras.h,69 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado46:
	DEC	W7
	BRA NZ	L_oscilador_usado46
	DEC	W8
	BRA NZ	L_oscilador_usado46
	NOP
	NOP
	NOP
	NOP
;extras.h,70 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,71 :: 		break;
	GOTO	L_oscilador_usado29
;extras.h,72 :: 		case 6:
L_oscilador_usado48:
;extras.h,73 :: 		glcd_write_text("frcdiv16",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr7_Lab2), W10
	CALL	_Glcd_Write_Text
;extras.h,74 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado49:
	DEC	W7
	BRA NZ	L_oscilador_usado49
	DEC	W8
	BRA NZ	L_oscilador_usado49
	NOP
	NOP
	NOP
	NOP
;extras.h,75 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,76 :: 		break;
	GOTO	L_oscilador_usado29
;extras.h,77 :: 		case 7:
L_oscilador_usado51:
;extras.h,78 :: 		glcd_write_text("frcdivn",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr8_Lab2), W10
	CALL	_Glcd_Write_Text
;extras.h,79 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado52:
	DEC	W7
	BRA NZ	L_oscilador_usado52
	DEC	W8
	BRA NZ	L_oscilador_usado52
	NOP
	NOP
	NOP
	NOP
;extras.h,80 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,81 :: 		break;
	GOTO	L_oscilador_usado29
;extras.h,82 :: 		default:
L_oscilador_usado54:
;extras.h,83 :: 		glcd_write_text("none",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr9_Lab2), W10
	CALL	_Glcd_Write_Text
;extras.h,84 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado55:
	DEC	W7
	BRA NZ	L_oscilador_usado55
	DEC	W8
	BRA NZ	L_oscilador_usado55
	NOP
	NOP
	NOP
	NOP
;extras.h,85 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,86 :: 		break;
	GOTO	L_oscilador_usado29
;extras.h,87 :: 		}
L_oscilador_usado28:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #0
	BRA NZ	L__oscilador_usado176
	GOTO	L_oscilador_usado30
L__oscilador_usado176:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #1
	BRA NZ	L__oscilador_usado177
	GOTO	L_oscilador_usado33
L__oscilador_usado177:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #2
	BRA NZ	L__oscilador_usado178
	GOTO	L_oscilador_usado36
L__oscilador_usado178:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #3
	BRA NZ	L__oscilador_usado179
	GOTO	L_oscilador_usado39
L__oscilador_usado179:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #4
	BRA NZ	L__oscilador_usado180
	GOTO	L_oscilador_usado42
L__oscilador_usado180:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #5
	BRA NZ	L__oscilador_usado181
	GOTO	L_oscilador_usado45
L__oscilador_usado181:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #6
	BRA NZ	L__oscilador_usado182
	GOTO	L_oscilador_usado48
L__oscilador_usado182:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #7
	BRA NZ	L__oscilador_usado183
	GOTO	L_oscilador_usado51
L__oscilador_usado183:
	GOTO	L_oscilador_usado54
L_oscilador_usado29:
;extras.h,88 :: 		}
L_end_oscilador_usado:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _oscilador_usado

_clean_PS2:

;text.h,11 :: 		void clean_PS2(){ keydata = 0, special = 0, down = 0;}
	MOV	#lo_addr(_keydata), W1
	CLR	W0
	MOV.B	W0, [W1]
	MOV	#lo_addr(_special), W1
	CLR	W0
	MOV.B	W0, [W1]
	MOV	#lo_addr(_down), W1
	CLR	W0
	MOV.B	W0, [W1]
L_end_clean_PS2:
	RETURN
; end of _clean_PS2

_cursor_animation:

;text.h,15 :: 		void cursor_animation(int it){
;text.h,17 :: 		for(i=1; i < 6; i++ ){
	PUSH	W11
	PUSH	W12
	PUSH	W13
; i start address is: 0 (W0)
	MOV	#1, W0
; i end address is: 0 (W0)
	MOV	W0, W12
L_cursor_animation57:
; i start address is: 24 (W12)
	CP	W12, #6
	BRA LT	L__cursor_animation186
	GOTO	L_cursor_animation58
L__cursor_animation186:
;text.h,18 :: 		if(i==it){
	CP	W12, W10
	BRA Z	L__cursor_animation187
	GOTO	L_cursor_animation60
L__cursor_animation187:
;text.h,19 :: 		Glcd_Write_Text("*",0,i,1);
	PUSH	W12
	PUSH	W10
	MOV.B	#1, W13
	CLR	W11
	MOV	#lo_addr(?lstr10_Lab2), W10
	CALL	_Glcd_Write_Text
	POP	W10
	POP	W12
;text.h,20 :: 		}else{
	GOTO	L_cursor_animation61
L_cursor_animation60:
;text.h,21 :: 		Glcd_Write_Text(" ",0,i,1);
	PUSH	W12
	PUSH	W10
	MOV.B	#1, W13
	CLR	W11
	MOV	#lo_addr(?lstr11_Lab2), W10
	CALL	_Glcd_Write_Text
	POP	W10
	POP	W12
;text.h,22 :: 		}
L_cursor_animation61:
;text.h,17 :: 		for(i=1; i < 6; i++ ){
	INC	W12
;text.h,23 :: 		}
; i end address is: 24 (W12)
	GOTO	L_cursor_animation57
L_cursor_animation58:
;text.h,24 :: 		}
L_end_cursor_animation:
	POP	W13
	POP	W12
	POP	W11
	RETURN
; end of _cursor_animation

_cursor_menu:
	LNK	#2

;text.h,25 :: 		int cursor_menu(){
;text.h,29 :: 		int it=1;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV	#1, W0
	MOV	W0, [W14+0]
;text.h,30 :: 		while(keydata!=ENTER){
L_cursor_menu62:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W0
	CP.B	W0, #13
	BRA NZ	L__cursor_menu189
	GOTO	L_cursor_menu63
L__cursor_menu189:
;text.h,31 :: 		cursor_animation(it);
	MOV	[W14+0], W10
	CALL	_cursor_animation
;text.h,32 :: 		if(Ps2_Key_Read(&keydata, &special, &down)){
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	CP0	W0
	BRA NZ	L__cursor_menu190
	GOTO	L_cursor_menu64
L__cursor_menu190:
;text.h,33 :: 		if(down){
	MOV	#lo_addr(_down), W0
	CP0.B	[W0]
	BRA NZ	L__cursor_menu191
	GOTO	L_cursor_menu65
L__cursor_menu191:
;text.h,34 :: 		if(keydata==DOWN_ARROW||keydata==UP_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#108, W0
	CP.B	W1, W0
	BRA NZ	L__cursor_menu192
	GOTO	L__cursor_menu143
L__cursor_menu192:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#111, W0
	CP.B	W1, W0
	BRA NZ	L__cursor_menu193
	GOTO	L__cursor_menu142
L__cursor_menu193:
	GOTO	L_cursor_menu68
L__cursor_menu143:
L__cursor_menu142:
;text.h,35 :: 		if(keydata==DOWN_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#108, W0
	CP.B	W1, W0
	BRA Z	L__cursor_menu194
	GOTO	L_cursor_menu69
L__cursor_menu194:
;text.h,36 :: 		it=it+1;
	MOV	[W14+0], W0
	INC	W0
	MOV	W0, [W14+0]
;text.h,37 :: 		if(it==6){it=1;}
	CP	W0, #6
	BRA Z	L__cursor_menu195
	GOTO	L_cursor_menu70
L__cursor_menu195:
	MOV	#1, W0
	MOV	W0, [W14+0]
L_cursor_menu70:
;text.h,38 :: 		clean_PS2();
	CALL	_clean_PS2
;text.h,39 :: 		}
L_cursor_menu69:
;text.h,40 :: 		if(keydata==UP_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#111, W0
	CP.B	W1, W0
	BRA Z	L__cursor_menu196
	GOTO	L_cursor_menu71
L__cursor_menu196:
;text.h,41 :: 		it=it-1;
	MOV	[W14+0], W0
	DEC	W0
	MOV	W0, [W14+0]
;text.h,42 :: 		if(it==0){it=5;}
	CP	W0, #0
	BRA Z	L__cursor_menu197
	GOTO	L_cursor_menu72
L__cursor_menu197:
	MOV	#5, W0
	MOV	W0, [W14+0]
L_cursor_menu72:
;text.h,43 :: 		clean_PS2();
	CALL	_clean_PS2
;text.h,44 :: 		}
L_cursor_menu71:
;text.h,45 :: 		cursor_animation(it);
	MOV	[W14+0], W10
	CALL	_cursor_animation
;text.h,46 :: 		}
L_cursor_menu68:
;text.h,47 :: 		if(keydata==ESC){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#34, W0
	CP.B	W1, W0
	BRA Z	L__cursor_menu198
	GOTO	L_cursor_menu73
L__cursor_menu198:
;text.h,48 :: 		Glcd_Write_TEXT("ESC" ,60,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr12_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,49 :: 		break;
	GOTO	L_cursor_menu63
;text.h,50 :: 		}
L_cursor_menu73:
;text.h,51 :: 		}
L_cursor_menu65:
;text.h,52 :: 		}
L_cursor_menu64:
;text.h,53 :: 		}
	GOTO	L_cursor_menu62
L_cursor_menu63:
;text.h,54 :: 		return it;
	MOV	[W14+0], W0
;text.h,55 :: 		}
;text.h,54 :: 		return it;
;text.h,55 :: 		}
L_end_cursor_menu:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	ULNK
	RETURN
; end of _cursor_menu

_num_update:

;text.h,57 :: 		void num_update(int it,int x_pos,int page){
;text.h,58 :: 		intToStr(it,t);
	PUSH	W10
	PUSH	W13
	PUSH	W11
	MOV	#lo_addr(_t), W11
	CALL	_IntToStr
	POP	W11
;text.h,59 :: 		Glcd_Write_Text(t,x_pos,page,1);
	MOV.B	#1, W13
	MOV	#lo_addr(_t), W10
	CALL	_Glcd_Write_Text
;text.h,60 :: 		}
L_end_num_update:
	POP	W13
	POP	W10
	RETURN
; end of _num_update

_parpadeo_barra:

;text.h,61 :: 		void parpadeo_barra(int x_pos){
;text.h,65 :: 		}
L_end_parpadeo_barra:
	RETURN
; end of _parpadeo_barra

_texto_menu:

;text.h,68 :: 		void texto_menu(){
;text.h,69 :: 		Glcd_Write_TEXT("Laboratorio 2",31,0,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#31, W11
	MOV	#lo_addr(?lstr13_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,70 :: 		Glcd_Write_TEXT("'Q' Cronometro",0,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr14_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,71 :: 		Glcd_Write_TEXT("'W' Captura",0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr15_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,72 :: 		Glcd_Write_TEXT("'E' PWM  ",0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr16_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,73 :: 		}
L_end_texto_menu:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _texto_menu

_texto_caso_1:

;text.h,74 :: 		void texto_caso_1(){
;text.h,76 :: 		Glcd_Write_Text("Cronometro",60,0,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr17_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,77 :: 		Glcd_Write_Text("1) Programar Hora",SANGRIA,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr18_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,78 :: 		Glcd_Write_Text("2) PLAY"  ,SANGRIA,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr19_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,80 :: 		Glcd_Write_Text("3) PAUSE"  ,SANGRIA,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr20_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,82 :: 		Glcd_Write_Text("4) RESET  "  ,SANGRIA,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr21_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,84 :: 		Glcd_Write_Text("5) Alarma",SANGRIA,5,1);
	MOV.B	#1, W13
	MOV.B	#5, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr22_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,85 :: 		}
L_end_texto_caso_1:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _texto_caso_1

_texto_caso_2:

;text.h,86 :: 		void texto_caso_2(){
;text.h,88 :: 		Glcd_Write_Text("Puerto de Entrada",SANGRIA,0,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr23_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,89 :: 		Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr24_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,90 :: 		Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr25_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,91 :: 		Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr26_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,92 :: 		Glcd_Write_Text("RPx/PORTxy"  ,SANGRIA,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr27_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,93 :: 		Glcd_Write_Text("5) Volver"   ,SANGRIA,5,1);
	MOV.B	#1, W13
	MOV.B	#5, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr28_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,94 :: 		}
L_end_texto_caso_2:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _texto_caso_2

_texto_caso_3:

;text.h,95 :: 		void texto_caso_3(){
;text.h,97 :: 		Glcd_Write_Text("Elegir Ciclo Util:",0,0,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	CLR	W12
	CLR	W11
	MOV	#lo_addr(?lstr29_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,98 :: 		Glcd_Write_Text("1) 15%"  ,SANGRIA,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr30_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,99 :: 		Glcd_Write_Text("2) 45%"  ,SANGRIA,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr31_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,100 :: 		Glcd_Write_Text("3) 60%"  ,SANGRIA,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr32_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,101 :: 		Glcd_Write_Text("4) 80%"  ,SANGRIA,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr33_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,102 :: 		Glcd_Write_Text("5) 100%"  ,SANGRIA,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr34_Lab2), W10
	CALL	_Glcd_Write_Text
;text.h,103 :: 		}
L_end_texto_caso_3:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _texto_caso_3

_config_IO:

;config.h,37 :: 		void config_IO(){
;config.h,38 :: 		ANSELB=0;
	CLR	ANSELB
;config.h,39 :: 		ANSELC=0;
	CLR	ANSELC
;config.h,40 :: 		ANSELD=0;
	CLR	ANSELD
;config.h,41 :: 		ANSELE=0;
	CLR	ANSELE
;config.h,42 :: 		ANSELG=0;             //ANA//logiCO SON B Y F
	CLR	ANSELG
;config.h,43 :: 		TRISB=0xffff;
	MOV	#65535, W0
	MOV	WREG, TRISB
;config.h,44 :: 		TRISE=0;
	CLR	TRISE
;config.h,45 :: 		TRISG=0;
	CLR	TRISG
;config.h,46 :: 		TRISDbits.TRISD11=1;  // desde rd11 a rd8 son  entradas del modulo captura
	BSET	TRISDbits, #11
;config.h,47 :: 		TRISDbits.TRISD10=1;
	BSET	TRISDbits, #10
;config.h,48 :: 		TRISDbits.TRISD9=1;
	BSET	TRISDbits, #9
;config.h,49 :: 		TRISDbits.TRISD8=1;
	BSET	TRISDbits, #8
;config.h,52 :: 		}
L_end_config_IO:
	RETURN
; end of _config_IO

_config_LCD:

;config.h,53 :: 		void config_LCD(){
;config.h,54 :: 		Glcd_Init();
	PUSH	W10
	PUSH	W12
	PUSH	W13
	CALL	_Glcd_Init
;config.h,55 :: 		Glcd_set_Font(font5x7 , 5, 7, 32);
	MOV.B	#7, W13
	MOV.B	#5, W12
	MOV	#lo_addr(_font5x7), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	MOV	#32, W0
	PUSH	W0
	CALL	_Glcd_Set_Font
	SUB	#2, W15
;config.h,56 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;config.h,57 :: 		}
L_end_config_LCD:
	POP	W13
	POP	W12
	POP	W10
	RETURN
; end of _config_LCD

_config_TMR:

;config.h,58 :: 		void config_TMR(){
;config.h,60 :: 		TMR1=0;
	CLR	TMR1
;config.h,61 :: 		PR1=31250; //1000ms
	MOV	#31250, W0
	MOV	WREG, PR1
;config.h,62 :: 		IEC0bits.T1IE=1;//enable interrupcion
	BSET	IEC0bits, #3
;config.h,63 :: 		IFS0bits.T1IF=0;//limpia bandera
	BCLR	IFS0bits, #3
;config.h,64 :: 		IPC0bits.T1IP=3;//prioridad interrupcion
	MOV	#12288, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR	W1, [W0], W1
	MOV	#28672, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC0bits
;config.h,65 :: 		T1CON=0;
	CLR	T1CON
;config.h,66 :: 		T1CONBits.TCKPS= 2;   //Preescalador 64
	MOV.B	#32, W0
	MOV.B	W0, W1
	MOV	#lo_addr(T1CONbits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#48, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(T1CONbits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(T1CONbits), W0
	MOV.B	W1, [W0]
;config.h,67 :: 		T1CONBits.TON=0;
	BCLR	T1CONbits, #15
;config.h,69 :: 		}
L_end_config_TMR:
	RETURN
; end of _config_TMR

_config_INT:

;config.h,70 :: 		void config_INT(){
;config.h,71 :: 		SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
	MOV	#lo_addr(SRbits), W0
	MOV.B	[W0], W1
	MOV.B	#31, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(SRbits), W0
	MOV.B	W1, [W0]
;config.h,72 :: 		INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
	BCLR	INTCON1bits, #15
;config.h,73 :: 		INTCON2bits.GIE=1; //interrupciones habilitadas
	BSET	INTCON2bits, #15
;config.h,74 :: 		CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
	BCLR	CORCONbits, #3
;config.h,76 :: 		}
L_end_config_INT:
	RETURN
; end of _config_INT

_config_ic:

;config.h,80 :: 		void config_ic() {
;config.h,82 :: 		IC1CON1bits.ICTSEL=1; // reloj timer 3
	MOV	#1024, W0
	MOV	W0, W1
	MOV	#lo_addr(IC1CON1bits), W0
	XOR	W1, [W0], W1
	MOV	#7168, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IC1CON1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IC1CON1bits
;config.h,83 :: 		IC2CON1bits.ICTSEL=1 ; // reloj timer 3
	MOV	#1024, W0
	MOV	W0, W1
	MOV	#lo_addr(IC2CON1bits), W0
	XOR	W1, [W0], W1
	MOV	#7168, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IC2CON1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IC2CON1bits
;config.h,84 :: 		IC1CON1bits.ICM=2; //captura
	MOV.B	#2, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC1CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC1CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC1CON1bits), W0
	MOV.B	W1, [W0]
;config.h,85 :: 		IC2CON1bits.ICM=2; // captura
	MOV.B	#2, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC2CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC2CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC2CON1bits), W0
	MOV.B	W1, [W0]
;config.h,86 :: 		IC1CON2bits.IC32=1; // modo 32 bits
	BSET	IC1CON2bits, #8
;config.h,87 :: 		IC2CON2bits.IC32=1; // modo 32 bits
	BSET	IC2CON2bits, #8
;config.h,89 :: 		IC1CON2bits.SYNCSEL=13; // sincronismo timer 3
	MOV.B	#13, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC1CON2bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #31, W1
	MOV	#lo_addr(IC1CON2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC1CON2bits), W0
	MOV.B	W1, [W0]
;config.h,90 :: 		IC2CON2bits.SYNCSEL=13; // sincronismo timer 3
	MOV.B	#13, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC2CON2bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #31, W1
	MOV	#lo_addr(IC2CON2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC2CON2bits), W0
	MOV.B	W1, [W0]
;config.h,91 :: 		IEC0bits.IC1IE=1; // habilita interrupciones modulo 1
	BSET	IEC0bits, #1
;config.h,92 :: 		IEC0bits.IC2IE=1; // habilita interrupciones modulo 2
	BSET	IEC0bits, #5
;config.h,93 :: 		IFS0bits.IC1IF=0; // borra bandera
	BCLR	IFS0bits, #1
;config.h,94 :: 		IFS0bits.IC2IF=0; // borra bandera
	BCLR	IFS0bits, #5
;config.h,95 :: 		IC1CON2bits.ICTRIG=0;
	BCLR	IC1CON2bits, #7
;config.h,96 :: 		IC2CON2bits.ICTRIG=0;
	BCLR	IC2CON2bits, #7
;config.h,97 :: 		IPC0bits.IC1IP=2;
	MOV.B	#32, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#112, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC0bits), W0
	MOV.B	W1, [W0]
;config.h,98 :: 		IPC0bits.IC1IP=2;
	MOV.B	#32, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#112, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC0bits), W0
	MOV.B	W1, [W0]
;config.h,100 :: 		}
L_end_config_ic:
	RETURN
; end of _config_ic

_config_timeric:

;config.h,102 :: 		void config_timeric ()  {
;config.h,103 :: 		T3CONbits.TSIDL=1;
	BSET	T3CONbits, #13
;config.h,104 :: 		T2CON= 0x8020; // config 64:1 prescaler
	MOV	#32800, W0
	MOV	WREG, T2CON
;config.h,105 :: 		PR2=31250; //1000 ms
	MOV	#31250, W0
	MOV	WREG, PR2
;config.h,106 :: 		T2CONbits.T32=1; // Modo 32 bits
	BSET	T2CONbits, #3
;config.h,107 :: 		IPC1bits.T2IP=3;
	MOV	#12288, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC1bits), W0
	XOR	W1, [W0], W1
	MOV	#28672, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC1bits
;config.h,108 :: 		}
L_end_config_timeric:
	RETURN
; end of _config_timeric

_clean_line:

;Lab2.c,21 :: 		void clean_line(int page){
;Lab2.c,22 :: 		y=page2pos(page)         ;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CALL	_page2pos
	MOV	#lo_addr(_y), W1
	MOV.B	W0, [W1]
;Lab2.c,23 :: 		glcd_write_text("                                                                                 ",0,y,1);
	MOV.B	#1, W13
	MOV.B	W0, W12
	CLR	W11
	MOV	#lo_addr(?lstr35_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,24 :: 		}
L_end_clean_line:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _clean_line

_TIMER1:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;Lab2.c,26 :: 		void TIMER1() org 0x1A
;Lab2.c,28 :: 		u_seg++;
	PUSH	W10
	MOV.B	#1, W1
	MOV	#lo_addr(_u_seg), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,29 :: 		if(u_seg==10)
	MOV	#lo_addr(_u_seg), W0
	MOV.B	[W0], W0
	CP.B	W0, #10
	BRA Z	L__TIMER1213
	GOTO	L_TIMER174
L__TIMER1213:
;Lab2.c,30 :: 		{ u_seg=0;
	MOV	#lo_addr(_u_seg), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,31 :: 		d_seg++;
	MOV.B	#1, W1
	MOV	#lo_addr(_d_seg), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,32 :: 		if(d_seg==6)
	MOV	#lo_addr(_d_seg), W0
	MOV.B	[W0], W0
	CP.B	W0, #6
	BRA Z	L__TIMER1214
	GOTO	L_TIMER175
L__TIMER1214:
;Lab2.c,33 :: 		{ d_seg=0;
	MOV	#lo_addr(_d_seg), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,34 :: 		u_min++;
	MOV.B	#1, W1
	MOV	#lo_addr(_u_min), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,35 :: 		if(u_min==10)
	MOV	#lo_addr(_u_min), W0
	MOV.B	[W0], W0
	CP.B	W0, #10
	BRA Z	L__TIMER1215
	GOTO	L_TIMER176
L__TIMER1215:
;Lab2.c,36 :: 		{ u_min=0;
	MOV	#lo_addr(_u_min), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,37 :: 		d_min++;
	MOV.B	#1, W1
	MOV	#lo_addr(_d_min), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,38 :: 		if(d_min==6)
	MOV	#lo_addr(_d_min), W0
	MOV.B	[W0], W0
	CP.B	W0, #6
	BRA Z	L__TIMER1216
	GOTO	L_TIMER177
L__TIMER1216:
;Lab2.c,39 :: 		{ d_min=0;
	MOV	#lo_addr(_d_min), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,40 :: 		u_hora++;
	MOV.B	#1, W1
	MOV	#lo_addr(_u_hora), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,41 :: 		if(u_hora==10 && d_hora==0)
	MOV	#lo_addr(_u_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #10
	BRA Z	L__TIMER1217
	GOTO	L__TIMER1148
L__TIMER1217:
	MOV	#lo_addr(_d_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #0
	BRA Z	L__TIMER1218
	GOTO	L__TIMER1147
L__TIMER1218:
L__TIMER1146:
;Lab2.c,42 :: 		{ u_hora=0;
	MOV	#lo_addr(_u_hora), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,43 :: 		d_hora++;
	MOV.B	#1, W1
	MOV	#lo_addr(_d_hora), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,44 :: 		}
	GOTO	L_TIMER181
;Lab2.c,41 :: 		if(u_hora==10 && d_hora==0)
L__TIMER1148:
L__TIMER1147:
;Lab2.c,45 :: 		else if(u_hora==3 && d_hora==1)
	MOV	#lo_addr(_u_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #3
	BRA Z	L__TIMER1219
	GOTO	L__TIMER1150
L__TIMER1219:
	MOV	#lo_addr(_d_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #1
	BRA Z	L__TIMER1220
	GOTO	L__TIMER1149
L__TIMER1220:
L__TIMER1145:
;Lab2.c,46 :: 		{ u_hora=1;
	MOV	#lo_addr(_u_hora), W1
	MOV.B	#1, W0
	MOV.B	W0, [W1]
;Lab2.c,47 :: 		d_hora=0;
	MOV	#lo_addr(_d_hora), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,45 :: 		else if(u_hora==3 && d_hora==1)
L__TIMER1150:
L__TIMER1149:
;Lab2.c,48 :: 		}
L_TIMER181:
;Lab2.c,49 :: 		}
L_TIMER177:
;Lab2.c,50 :: 		}
L_TIMER176:
;Lab2.c,51 :: 		}
L_TIMER175:
;Lab2.c,52 :: 		}
L_TIMER174:
;Lab2.c,53 :: 		if(ENALARM&&Alarma[0]==HORA[0]&&Alarma[1]==HORA[1]&&Alarma[3]==HORA[3]&&Alarma[4]==HORA[4]){
	MOV	#lo_addr(_ENALARM), W0
	CP0	[W0]
	BRA NZ	L__TIMER1221
	GOTO	L__TIMER1155
L__TIMER1221:
	MOV	#lo_addr(_alarma), W0
	MOV.B	[W0], W1
	MOV	#lo_addr(_hora), W0
	CP.B	W1, [W0]
	BRA Z	L__TIMER1222
	GOTO	L__TIMER1154
L__TIMER1222:
	MOV	#lo_addr(_alarma+1), W0
	MOV.B	[W0], W1
	MOV	#lo_addr(_hora+1), W0
	CP.B	W1, [W0]
	BRA Z	L__TIMER1223
	GOTO	L__TIMER1153
L__TIMER1223:
	MOV	#lo_addr(_alarma+3), W0
	MOV.B	[W0], W1
	MOV	#lo_addr(_hora+3), W0
	CP.B	W1, [W0]
	BRA Z	L__TIMER1224
	GOTO	L__TIMER1152
L__TIMER1224:
	MOV	#lo_addr(_alarma+4), W0
	MOV.B	[W0], W1
	MOV	#lo_addr(_hora+4), W0
	CP.B	W1, [W0]
	BRA Z	L__TIMER1225
	GOTO	L__TIMER1151
L__TIMER1225:
L__TIMER1144:
;Lab2.c,54 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,55 :: 		animate_bell_5s();
	CALL	_animate_bell_5s
;Lab2.c,56 :: 		ENALARM=0;
	CLR	W0
	MOV	W0, _ENALARM
;Lab2.c,53 :: 		if(ENALARM&&Alarma[0]==HORA[0]&&Alarma[1]==HORA[1]&&Alarma[3]==HORA[3]&&Alarma[4]==HORA[4]){
L__TIMER1155:
L__TIMER1154:
L__TIMER1153:
L__TIMER1152:
L__TIMER1151:
;Lab2.c,58 :: 		HORA[0]=d_hora+'0';
	MOV	#lo_addr(_d_hora), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,59 :: 		HORA[1]=u_hora+'0';
	MOV	#lo_addr(_u_hora), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+1), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,60 :: 		HORA[2]=':';
	MOV	#lo_addr(_hora+2), W1
	MOV.B	#58, W0
	MOV.B	W0, [W1]
;Lab2.c,61 :: 		HORA[3]=d_min+'0';
	MOV	#lo_addr(_d_min), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+3), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,62 :: 		HORA[4]=u_min+'0';
	MOV	#lo_addr(_u_min), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+4), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,63 :: 		HORA[5]=':';
	MOV	#lo_addr(_hora+5), W1
	MOV.B	#58, W0
	MOV.B	W0, [W1]
;Lab2.c,64 :: 		HORA[6]=d_seg+'0';
	MOV	#lo_addr(_d_seg), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+6), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,65 :: 		HORA[7]=u_seg+'0';
	MOV	#lo_addr(_u_seg), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+7), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,66 :: 		HORA[8]=':';
	MOV	#lo_addr(_hora+8), W1
	MOV.B	#58, W0
	MOV.B	W0, [W1]
;Lab2.c,67 :: 		HORA[9]=d_mseg+'0';
	MOV	#lo_addr(_d_mseg), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+9), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,68 :: 		HORA[10]=u_mseg+'0';
	MOV	#lo_addr(_u_mseg), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+10), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,69 :: 		HORA[11]='\0';
	MOV	#lo_addr(_hora+11), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,70 :: 		cron_write();
	CALL	_cron_write
;Lab2.c,71 :: 		IFS0bits.T1IF=0;
	BCLR	IFS0bits, #3
;Lab2.c,72 :: 		}
L_end_TIMER1:
	POP	W10
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	50
	POP	DSWPAG
	RETFIE
; end of _TIMER1

_intercaso2ic1:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;Lab2.c,73 :: 		void intercaso2ic1() org 0x16{
;Lab2.c,74 :: 		conta1++;
	MOV	#1, W1
	MOV	#lo_addr(_conta1), W0
	ADD	W1, [W0], [W0]
;Lab2.c,75 :: 		IFS0bits.IC1IF=0; // borra bandera
	BCLR	IFS0bits, #1
;Lab2.c,76 :: 		}
L_end_intercaso2ic1:
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	50
	POP	DSWPAG
	RETFIE
; end of _intercaso2ic1

_num_selector:
	LNK	#2

;Lab2.c,86 :: 		int  num_selector(int x_pos){
;Lab2.c,87 :: 		int it=0;
	PUSH	W11
	PUSH	W12
	MOV	#0, W0
	MOV	W0, [W14+0]
;Lab2.c,88 :: 		num_update(it,x_pos,7);
	PUSH	W10
	MOV	#7, W12
	MOV	W10, W11
	MOV	[W14+0], W10
	CALL	_num_update
	POP	W10
;Lab2.c,89 :: 		clean_PS2();
	CALL	_clean_PS2
;Lab2.c,90 :: 		while(keydata!=ENTER){
L_num_selector88:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W0
	CP.B	W0, #13
	BRA NZ	L__num_selector228
	GOTO	L_num_selector89
L__num_selector228:
;Lab2.c,91 :: 		if(Ps2_Key_Read(&keydata, &special, &down)){
	PUSH	W10
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	POP	W10
	CP0	W0
	BRA NZ	L__num_selector229
	GOTO	L_num_selector90
L__num_selector229:
;Lab2.c,92 :: 		if(down){
	MOV	#lo_addr(_down), W0
	CP0.B	[W0]
	BRA NZ	L__num_selector230
	GOTO	L_num_selector91
L__num_selector230:
;Lab2.c,93 :: 		if(keydata==DOWN_ARROW||keydata==UP_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#108, W0
	CP.B	W1, W0
	BRA NZ	L__num_selector231
	GOTO	L__num_selector158
L__num_selector231:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#111, W0
	CP.B	W1, W0
	BRA NZ	L__num_selector232
	GOTO	L__num_selector157
L__num_selector232:
	GOTO	L_num_selector94
L__num_selector158:
L__num_selector157:
;Lab2.c,94 :: 		if(keydata==UP_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#111, W0
	CP.B	W1, W0
	BRA Z	L__num_selector233
	GOTO	L_num_selector95
L__num_selector233:
;Lab2.c,95 :: 		it=it+1;
	MOV	[W14+0], W0
	INC	W0
	MOV	W0, [W14+0]
;Lab2.c,96 :: 		if(it==10){it=0;}
	CP	W0, #10
	BRA Z	L__num_selector234
	GOTO	L_num_selector96
L__num_selector234:
	CLR	W0
	MOV	W0, [W14+0]
L_num_selector96:
;Lab2.c,97 :: 		clean_PS2();
	CALL	_clean_PS2
;Lab2.c,98 :: 		}
L_num_selector95:
;Lab2.c,99 :: 		if(keydata==DOWN_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#108, W0
	CP.B	W1, W0
	BRA Z	L__num_selector235
	GOTO	L_num_selector97
L__num_selector235:
;Lab2.c,100 :: 		it=it-1;
	MOV	[W14+0], W0
	SUB	W0, #1, W1
	MOV	W1, [W14+0]
;Lab2.c,101 :: 		if(it==-1){it=9;}
	MOV	#65535, W0
	CP	W1, W0
	BRA Z	L__num_selector236
	GOTO	L_num_selector98
L__num_selector236:
	MOV	#9, W0
	MOV	W0, [W14+0]
L_num_selector98:
;Lab2.c,102 :: 		clean_PS2();
	CALL	_clean_PS2
;Lab2.c,103 :: 		}
L_num_selector97:
;Lab2.c,104 :: 		num_update(it,x_pos,7);
	PUSH	W10
	MOV	#7, W12
	MOV	W10, W11
	MOV	[W14+0], W10
	CALL	_num_update
	POP	W10
;Lab2.c,105 :: 		clean_PS2();
	CALL	_clean_PS2
;Lab2.c,106 :: 		}
L_num_selector94:
;Lab2.c,107 :: 		clean_PS2();
	CALL	_clean_PS2
;Lab2.c,108 :: 		}
L_num_selector91:
;Lab2.c,109 :: 		}
L_num_selector90:
;Lab2.c,110 :: 		}
	GOTO	L_num_selector88
L_num_selector89:
;Lab2.c,111 :: 		return it;
	MOV	[W14+0], W0
;Lab2.c,112 :: 		}
;Lab2.c,111 :: 		return it;
;Lab2.c,112 :: 		}
L_end_num_selector:
	POP	W12
	POP	W11
	ULNK
	RETURN
; end of _num_selector

_cron_cursor:
	LNK	#2

;Lab2.c,113 :: 		void cron_cursor(){
;Lab2.c,114 :: 		int x_pos=60,i;
	PUSH	W10
;Lab2.c,117 :: 		for(i=0;i<5;i++){
; i start address is: 24 (W12)
	CLR	W12
; i end address is: 24 (W12)
L_cron_cursor99:
; i start address is: 24 (W12)
	CP	W12, #5
	BRA LT	L__cron_cursor238
	GOTO	L_cron_cursor100
L__cron_cursor238:
;Lab2.c,119 :: 		if(i!=2){
	CP	W12, #2
	BRA NZ	L__cron_cursor239
	GOTO	L_cron_cursor102
L__cron_cursor239:
;Lab2.c,120 :: 		HORA[i]='0'+num_selector(60+i*5);
	MOV	#lo_addr(_hora), W0
	ADD	W0, W12, W0
	MOV	W0, [W14+0]
	MOV	#5, W0
	MUL.SS	W12, W0, W2
	MOV	#60, W0
	ADD	W0, W2, W0
	MOV	W0, W10
	CALL	_num_selector
	MOV	#48, W1
	ADD	W1, W0, W1
	MOV	[W14+0], W0
	MOV.B	W1, [W0]
;Lab2.c,121 :: 		}else if(i==2){
	GOTO	L_cron_cursor103
L_cron_cursor102:
	CP	W12, #2
	BRA Z	L__cron_cursor240
	GOTO	L_cron_cursor104
L__cron_cursor240:
;Lab2.c,122 :: 		HORA[2]=':' ;
	MOV	#lo_addr(_hora+2), W1
	MOV.B	#58, W0
	MOV.B	W0, [W1]
;Lab2.c,123 :: 		}
L_cron_cursor104:
L_cron_cursor103:
;Lab2.c,124 :: 		clean_PS2();
	CALL	_clean_PS2
;Lab2.c,125 :: 		cron_write();
	CALL	_cron_write
;Lab2.c,117 :: 		for(i=0;i<5;i++){
	INC	W12
;Lab2.c,126 :: 		}
; i end address is: 24 (W12)
	GOTO	L_cron_cursor99
L_cron_cursor100:
;Lab2.c,127 :: 		}
L_end_cron_cursor:
	POP	W10
	ULNK
	RETURN
; end of _cron_cursor

_cron_write:

;Lab2.c,129 :: 		void cron_write(){
;Lab2.c,130 :: 		Glcd_Write_TEXT("                                              ",60,7,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr36_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,131 :: 		Glcd_Write_TEXT(HORA,60,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#60, W11
	MOV	#lo_addr(_hora), W10
	CALL	_Glcd_Write_Text
;Lab2.c,132 :: 		}
L_end_cron_write:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _cron_write

_caso_1:

;Lab2.c,135 :: 		void caso_1(){
;Lab2.c,136 :: 		while(keydata!=ESC){
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
L_caso_1105:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#34, W0
	CP.B	W1, W0
	BRA NZ	L__caso_1243
	GOTO	L_caso_1106
L__caso_1243:
;Lab2.c,137 :: 		selected=cursor_menu();
	CALL	_cursor_menu
	MOV	W0, _selected
;Lab2.c,138 :: 		switch(selected){
	GOTO	L_caso_1107
;Lab2.c,139 :: 		case 1:
L_caso_1109:
;Lab2.c,140 :: 		cron_cursor();
	CALL	_cron_cursor
;Lab2.c,141 :: 		clean_PS2();
	CALL	_clean_PS2
;Lab2.c,142 :: 		break;
	GOTO	L_caso_1108
;Lab2.c,143 :: 		case 2:
L_caso_1110:
;Lab2.c,144 :: 		Glcd_Write_Text("PLAY",30,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#30, W11
	MOV	#lo_addr(?lstr37_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,145 :: 		break;
	GOTO	L_caso_1108
;Lab2.c,146 :: 		case 3:
L_caso_1111:
;Lab2.c,147 :: 		Glcd_Write_Text("pause",30,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#30, W11
	MOV	#lo_addr(?lstr38_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,148 :: 		break;
	GOTO	L_caso_1108
;Lab2.c,149 :: 		case 4:
L_caso_1112:
;Lab2.c,150 :: 		Glcd_Write_Text("RESET",30,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#30, W11
	MOV	#lo_addr(?lstr39_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,151 :: 		break;
	GOTO	L_caso_1108
;Lab2.c,152 :: 		case 5:
L_caso_1113:
;Lab2.c,153 :: 		Glcd_Write_Text("ALARM",30,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#30, W11
	MOV	#lo_addr(?lstr40_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,154 :: 		break;
	GOTO	L_caso_1108
;Lab2.c,155 :: 		}
L_caso_1107:
	MOV	_selected, W0
	CP	W0, #1
	BRA NZ	L__caso_1244
	GOTO	L_caso_1109
L__caso_1244:
	MOV	_selected, W0
	CP	W0, #2
	BRA NZ	L__caso_1245
	GOTO	L_caso_1110
L__caso_1245:
	MOV	_selected, W0
	CP	W0, #3
	BRA NZ	L__caso_1246
	GOTO	L_caso_1111
L__caso_1246:
	MOV	_selected, W0
	CP	W0, #4
	BRA NZ	L__caso_1247
	GOTO	L_caso_1112
L__caso_1247:
	MOV	_selected, W0
	CP	W0, #5
	BRA NZ	L__caso_1248
	GOTO	L_caso_1113
L__caso_1248:
L_caso_1108:
;Lab2.c,156 :: 		}
	GOTO	L_caso_1105
L_caso_1106:
;Lab2.c,157 :: 		}
L_end_caso_1:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _caso_1

_caso_2:

;Lab2.c,158 :: 		void caso_2(){
;Lab2.c,159 :: 		while(keydata!=ESC){
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
L_caso_2114:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#34, W0
	CP.B	W1, W0
	BRA NZ	L__caso_2250
	GOTO	L_caso_2115
L__caso_2250:
;Lab2.c,160 :: 		if(!FloatToStr(T1,txt)){Glcd_Write_Text(txt,65,1,1);}
	MOV	#lo_addr(_txt), W12
	MOV	_T1, W10
	MOV	_T1+2, W11
	CALL	_FloatToStr
	CP0.B	W0
	BRA Z	L__caso_2251
	GOTO	L_caso_2116
L__caso_2251:
	MOV.B	#1, W13
	MOV.B	#1, W12
	MOV.B	#65, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
L_caso_2116:
;Lab2.c,161 :: 		if(!FloatToStr(T2,txt)){Glcd_Write_Text(txt,65,2,1);}
	MOV	#lo_addr(_txt), W12
	MOV	_T2, W10
	MOV	_T2+2, W11
	CALL	_FloatToStr
	CP0.B	W0
	BRA Z	L__caso_2252
	GOTO	L_caso_2117
L__caso_2252:
	MOV.B	#1, W13
	MOV.B	#2, W12
	MOV.B	#65, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
L_caso_2117:
;Lab2.c,162 :: 		if(!FloatToStr(T3,txt)){Glcd_Write_Text(txt,65,3,1);}
	MOV	#lo_addr(_txt), W12
	MOV	_T3, W10
	MOV	_T3+2, W11
	CALL	_FloatToStr
	CP0.B	W0
	BRA Z	L__caso_2253
	GOTO	L_caso_2118
L__caso_2253:
	MOV.B	#1, W13
	MOV.B	#3, W12
	MOV.B	#65, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
L_caso_2118:
;Lab2.c,163 :: 		if(!FloatToStr(T4,txt)){Glcd_Write_Text(txt,65,4,1);}
	MOV	#lo_addr(_txt), W12
	MOV	_T4, W10
	MOV	_T4+2, W11
	CALL	_FloatToStr
	CP0.B	W0
	BRA Z	L__caso_2254
	GOTO	L_caso_2119
L__caso_2254:
	MOV.B	#1, W13
	MOV.B	#4, W12
	MOV.B	#65, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
L_caso_2119:
;Lab2.c,164 :: 		Ps2_Key_Read(&keydata, &special, &down);
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
;Lab2.c,165 :: 		}
	GOTO	L_caso_2114
L_caso_2115:
;Lab2.c,166 :: 		}
L_end_caso_2:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _caso_2

_main:
	MOV	#2048, W15
	MOV	#6142, W0
	MOV	WREG, 32
	MOV	#1, W0
	MOV	WREG, 50
	MOV	#4, W0
	IOR	68

;Lab2.c,168 :: 		void main(){
;Lab2.c,169 :: 		config_IO();  config_LCD();
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CALL	_config_IO
	CALL	_config_LCD
;Lab2.c,170 :: 		config_INT(); config_TMR();
	CALL	_config_INT
	CALL	_config_TMR
;Lab2.c,172 :: 		animate_charmander_5s(); Glcd_Fill(0);
	CALL	_animate_charmander_5s
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,174 :: 		PS2_Config();  Glcd_Fill(0);
	CALL	_Ps2_Config
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,175 :: 		while(1){
L_main120:
;Lab2.c,176 :: 		texto_menu();
	CALL	_texto_menu
;Lab2.c,177 :: 		if(Ps2_Key_Read(&keydata, &special, &down)){
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	CP0	W0
	BRA NZ	L__main256
	GOTO	L_main122
L__main256:
;Lab2.c,178 :: 		if(down){
	MOV	#lo_addr(_down), W0
	CP0.B	[W0]
	BRA NZ	L__main257
	GOTO	L_main123
L__main257:
;Lab2.c,179 :: 		Glcd_Write_TEXT("Entrar",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr41_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,180 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_main124:
	DEC	W7
	BRA NZ	L_main124
	DEC	W8
	BRA NZ	L_main124
;Lab2.c,181 :: 		Glcd_Write_TEXT("        ",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr42_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,183 :: 		op=0;
	MOV	#lo_addr(_op), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,184 :: 		switch(keydata){
	GOTO	L_main126
;Lab2.c,185 :: 		case 'x':
L_main128:
;Lab2.c,187 :: 		clean_PS2();
	CALL	_clean_PS2
;Lab2.c,188 :: 		texto_caso_1();
	CALL	_texto_caso_1
;Lab2.c,189 :: 		caso_1();
	CALL	_caso_1
;Lab2.c,190 :: 		break;
	GOTO	L_main127
;Lab2.c,192 :: 		case 'W':
L_main129:
;Lab2.c,194 :: 		clean_PS2();
	CALL	_clean_PS2
;Lab2.c,195 :: 		texto_caso_2();
	CALL	_texto_caso_2
;Lab2.c,196 :: 		caso_2();
	CALL	_caso_2
;Lab2.c,197 :: 		break;
	GOTO	L_main127
;Lab2.c,200 :: 		case UP_ARROW:
L_main130:
;Lab2.c,201 :: 		Glcd_Write_TEXT("AR",60,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr43_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,202 :: 		break;
	GOTO	L_main127
;Lab2.c,204 :: 		case DOWN_ARROW:
L_main131:
;Lab2.c,205 :: 		Glcd_Write_TEXT("AB",60,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr44_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,206 :: 		break;
	GOTO	L_main127
;Lab2.c,208 :: 		case 'd':
L_main132:
;Lab2.c,209 :: 		cron_write();
	CALL	_cron_write
;Lab2.c,210 :: 		delay_ms(500);
	MOV	#8, W8
	MOV	#41252, W7
L_main133:
	DEC	W7
	BRA NZ	L_main133
	DEC	W8
	BRA NZ	L_main133
;Lab2.c,211 :: 		break;
	GOTO	L_main127
;Lab2.c,212 :: 		default:
L_main135:
;Lab2.c,213 :: 		Glcd_Write_TEXT("Erroneo ",60,7,1); delay_ms(500);Glcd_Write_TEXT("        ",60,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr45_Lab2), W10
	CALL	_Glcd_Write_Text
	MOV	#8, W8
	MOV	#41252, W7
L_main136:
	DEC	W7
	BRA NZ	L_main136
	DEC	W8
	BRA NZ	L_main136
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr46_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,214 :: 		break;
	GOTO	L_main127
;Lab2.c,216 :: 		}
L_main126:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#120, W0
	CP.B	W1, W0
	BRA NZ	L__main258
	GOTO	L_main128
L__main258:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#87, W0
	CP.B	W1, W0
	BRA NZ	L__main259
	GOTO	L_main129
L__main259:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#111, W0
	CP.B	W1, W0
	BRA NZ	L__main260
	GOTO	L_main130
L__main260:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#108, W0
	CP.B	W1, W0
	BRA NZ	L__main261
	GOTO	L_main131
L__main261:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#100, W0
	CP.B	W1, W0
	BRA NZ	L__main262
	GOTO	L_main132
L__main262:
	GOTO	L_main135
L_main127:
;Lab2.c,218 :: 		}
L_main123:
;Lab2.c,219 :: 		}
L_main122:
;Lab2.c,220 :: 		}
	GOTO	L_main120
;Lab2.c,221 :: 		}
L_end_main:
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
