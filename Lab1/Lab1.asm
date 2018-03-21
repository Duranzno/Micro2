
_barra:

;barras.h,14 :: 		void barra(int INTx,int contador_barra) {
;barras.h,16 :: 		box(BARS_H_LOCATIONS[INTx],contador_barra);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV	#lo_addr(_BARS_H_LOCATIONS), W0
	ADD	W0, W10, W0
	PUSH.D	W10
	ZE	[W0], W10
	CALL	_box
	POP.D	W10
;barras.h,17 :: 		ShortToStr(contador_barra,txt);
	PUSH	W10
	MOV.B	W11, W10
	MOV	#lo_addr(_txt), W11
	CALL	_ShortToStr
	POP	W10
;barras.h,19 :: 		Glcd_Write_Text(txt,BARS_H_LOCATIONS[INTx],0,1);
	MOV	#lo_addr(_BARS_H_LOCATIONS), W0
	ADD	W0, W10, W0
	MOV.B	#1, W13
	CLR	W12
	MOV.B	[W0], W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;barras.h,20 :: 		}
L_end_barra:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _barra

_box:

;barras.h,21 :: 		void box(int x_left,int count){
;barras.h,22 :: 		y_top=64-DrawableBars(count)*2;
	PUSH	W11
	PUSH	W12
	PUSH	W13
	PUSH.D	W10
	MOV	W11, W10
	CALL	_DrawableBars
	POP.D	W10
	SL	W0, #1, W2
	MOV.B	#64, W1
	MOV	#lo_addr(_y_top), W0
	SUB.B	W1, W2, [W0]
;barras.h,23 :: 		y_bottom=y_top+2;
	MOV	#lo_addr(_y_top), W0
	MOV.B	[W0], W1
	MOV	#lo_addr(_y_bottom), W0
	ADD.B	W1, #2, [W0]
;barras.h,25 :: 		x_right=x_left+20;
	MOV	#lo_addr(_x_right), W0
	ADD.B	W10, #20, [W0]
;barras.h,26 :: 		contador_reset=DrawableBars(count);
	PUSH.D	W10
	MOV	W11, W10
	CALL	_DrawableBars
	POP.D	W10
	MOV	#lo_addr(_contador_reset), W1
	MOV.B	W0, [W1]
;barras.h,27 :: 		if(count>1){
	CP	W11, #1
	BRA GT	L__box167
	GOTO	L_box0
L__box167:
;barras.h,28 :: 		if (contador_reset==1){
	MOV	#lo_addr(_contador_reset), W0
	MOV.B	[W0], W0
	CP.B	W0, #1
	BRA Z	L__box168
	GOTO	L_box1
L__box168:
;barras.h,30 :: 		Glcd_Box(x_left,7,x_right,64,0);
	MOV.B	#64, W13
	MOV	#lo_addr(_x_right), W0
	MOV.B	[W0], W12
	MOV.B	#7, W11
	CLR	W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
;barras.h,32 :: 		}  else {
	GOTO	L_box2
L_box1:
;barras.h,33 :: 		Glcd_Box(x_left,y_top,x_right,y_bottom, 1);}
	MOV	#lo_addr(_y_bottom), W0
	MOV.B	[W0], W13
	MOV	#lo_addr(_x_right), W0
	MOV.B	[W0], W12
	MOV	#lo_addr(_y_top), W0
	MOV.B	[W0], W11
	MOV	#1, W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
L_box2:
;barras.h,34 :: 		}else {
	GOTO	L_box3
L_box0:
;barras.h,35 :: 		Glcd_Box(x_left,y_top,x_right,y_bottom, 1);
	MOV	#lo_addr(_y_bottom), W0
	MOV.B	[W0], W13
	MOV	#lo_addr(_x_right), W0
	MOV.B	[W0], W12
	MOV	#lo_addr(_y_top), W0
	MOV.B	[W0], W11
	MOV	#1, W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
;barras.h,36 :: 		}
L_box3:
;barras.h,37 :: 		}
L_end_box:
	POP	W13
	POP	W12
	POP	W11
	RETURN
; end of _box

_funcionPractica:

;barras.h,38 :: 		void funcionPractica(){
;barras.h,39 :: 		Glcd_Fill(0);
	PUSH	W10
	PUSH	W11
	CLR	W10
	CALL	_Glcd_Fill
;barras.h,40 :: 		delay_ms(5000);
	MOV	#77, W8
	MOV	#19309, W7
L_funcionPractica4:
	DEC	W7
	BRA NZ	L_funcionPractica4
	DEC	W8
	BRA NZ	L_funcionPractica4
	NOP
	NOP
;barras.h,46 :: 		for(count=1;count<61;count=count++){
	MOV	#lo_addr(_count), W1
	MOV.B	#1, W0
	MOV.B	W0, [W1]
L_funcionPractica6:
	MOV	#lo_addr(_count), W0
	MOV.B	[W0], W1
	MOV.B	#61, W0
	CP.B	W1, W0
	BRA LTU	L__funcionPractica170
	GOTO	L_funcionPractica7
L__funcionPractica170:
;barras.h,47 :: 		for(Ix=0;Ix<5;Ix++){
	MOV	#lo_addr(_Ix), W1
	CLR	W0
	MOV.B	W0, [W1]
L_funcionPractica9:
	MOV	#lo_addr(_Ix), W0
	MOV.B	[W0], W0
	CP.B	W0, #5
	BRA LTU	L__funcionPractica171
	GOTO	L_funcionPractica10
L__funcionPractica171:
;barras.h,48 :: 		x_left=BARS_H_LOCATIONS[Ix];
	MOV	#lo_addr(_Ix), W0
	ZE	[W0], W1
	MOV	#lo_addr(_BARS_H_LOCATIONS), W0
	ADD	W0, W1, W0
	MOV.B	[W0], W1
	MOV	#lo_addr(_x_left), W0
	MOV.B	W1, [W0]
;barras.h,61 :: 		box(x_left,count);
	MOV	#lo_addr(_count), W0
	ZE	[W0], W11
	ZE	W1, W10
	CALL	_box
;barras.h,63 :: 		delay_ms(500)  ;
	MOV	#8, W8
	MOV	#41252, W7
L_funcionPractica12:
	DEC	W7
	BRA NZ	L_funcionPractica12
	DEC	W8
	BRA NZ	L_funcionPractica12
;barras.h,47 :: 		for(Ix=0;Ix<5;Ix++){
	MOV.B	#1, W1
	MOV	#lo_addr(_Ix), W0
	ADD.B	W1, [W0], [W0]
;barras.h,66 :: 		}
	GOTO	L_funcionPractica9
L_funcionPractica10:
;barras.h,46 :: 		for(count=1;count<61;count=count++){
	MOV.B	#1, W1
	MOV	#lo_addr(_count), W0
	ADD.B	W1, [W0], [W0]
;barras.h,67 :: 		}
	GOTO	L_funcionPractica6
L_funcionPractica7:
;barras.h,68 :: 		}
L_end_funcionPractica:
	POP	W11
	POP	W10
	RETURN
; end of _funcionPractica

_DrawableBars:

;barras.h,71 :: 		int DrawableBars(int real_number_of_bars){
;barras.h,74 :: 		if(real_number_of_bars>25){
	PUSH	W11
	CP	W10, #25
	BRA GT	L__DrawableBars173
	GOTO	L_DrawableBars14
L__DrawableBars173:
;barras.h,75 :: 		quotient=real_number_of_bars/25;
	MOV	#25, W2
	REPEAT	#17
	DIV.S	W10, W2
	MOV	W0, _quotient
;barras.h,76 :: 		quotient=floor(quotient);
	PUSH	W10
	ASR	W0, #15, W1
	SETM	W2
	CALL	__Long2Float
	MOV.D	W0, W10
	CALL	_floor
	CALL	__Float2Longint
	POP	W10
	MOV	W0, _quotient
;barras.h,77 :: 		return real_number_of_bars-25*quotient;
	MOV	#25, W1
	MUL.SS	W1, W0, W0
	SUB	W10, W0, W0
	GOTO	L_end_DrawableBars
;barras.h,78 :: 		}else{
L_DrawableBars14:
;barras.h,79 :: 		return real_number_of_bars;
	MOV	W10, W0
;barras.h,81 :: 		}
;barras.h,79 :: 		return real_number_of_bars;
;barras.h,81 :: 		}
L_end_DrawableBars:
	POP	W11
	RETURN
; end of _DrawableBars

_animate_charmander_5s:

;sprites.h,194 :: 		void animate_charmander_5s(){
;sprites.h,195 :: 		Glcd_Image(charmander_1);
	PUSH	W10
	MOV	#lo_addr(_charmander_1), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	CALL	_Glcd_Image
;sprites.h,196 :: 		delay_ms(2500);
	MOV	#39, W8
	MOV	#9654, W7
L_animate_charmander_5s16:
	DEC	W7
	BRA NZ	L_animate_charmander_5s16
	DEC	W8
	BRA NZ	L_animate_charmander_5s16
	NOP
	NOP
	NOP
;sprites.h,198 :: 		Glcd_Image(charmander_2);
	MOV	#lo_addr(_charmander_2), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	CALL	_Glcd_Image
;sprites.h,199 :: 		delay_ms(2500);
	MOV	#39, W8
	MOV	#9654, W7
L_animate_charmander_5s18:
	DEC	W7
	BRA NZ	L_animate_charmander_5s18
	DEC	W8
	BRA NZ	L_animate_charmander_5s18
	NOP
	NOP
	NOP
;sprites.h,200 :: 		}
L_end_animate_charmander_5s:
	POP	W10
	RETURN
; end of _animate_charmander_5s

_animate_charmander_20s:

;sprites.h,201 :: 		void animate_charmander_20s(){
;sprites.h,202 :: 		animate_charmander_5s();
	CALL	_animate_charmander_5s
;sprites.h,203 :: 		animate_charmander_5s();
	CALL	_animate_charmander_5s
;sprites.h,204 :: 		animate_charmander_5s();
	CALL	_animate_charmander_5s
;sprites.h,205 :: 		animate_charmander_5s();
	CALL	_animate_charmander_5s
;sprites.h,206 :: 		}
L_end_animate_charmander_20s:
	RETURN
; end of _animate_charmander_20s

_animate_bullet:

;sprites.h,208 :: 		void animate_bullet(unsigned int x_left){
;sprites.h,209 :: 		Glcd_PartialImage(x_left,23,18,18,18,18,bullet);
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV	#18, W13
	MOV	#18, W12
	MOV	#23, W11
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
;sprites.h,210 :: 		}
L_end_animate_bullet:
	POP	W13
	POP	W12
	POP	W11
	RETURN
; end of _animate_bullet

_animate_bullet_5s:

;sprites.h,212 :: 		void animate_bullet_5s(){
;sprites.h,213 :: 		animate_bullet(109);delay_ms(1000);
	PUSH	W10
	MOV	#109, W10
	CALL	_animate_bullet
	MOV	#16, W8
	MOV	#16968, W7
L_animate_bullet_5s20:
	DEC	W7
	BRA NZ	L_animate_bullet_5s20
	DEC	W8
	BRA NZ	L_animate_bullet_5s20
	NOP
	NOP
	NOP
	NOP
;sprites.h,214 :: 		animate_bullet(91) ;delay_ms(1000);
	MOV	#91, W10
	CALL	_animate_bullet
	MOV	#16, W8
	MOV	#16968, W7
L_animate_bullet_5s22:
	DEC	W7
	BRA NZ	L_animate_bullet_5s22
	DEC	W8
	BRA NZ	L_animate_bullet_5s22
	NOP
	NOP
	NOP
	NOP
;sprites.h,215 :: 		animate_bullet(73) ;delay_ms(1000);
	MOV	#73, W10
	CALL	_animate_bullet
	MOV	#16, W8
	MOV	#16968, W7
L_animate_bullet_5s24:
	DEC	W7
	BRA NZ	L_animate_bullet_5s24
	DEC	W8
	BRA NZ	L_animate_bullet_5s24
	NOP
	NOP
	NOP
	NOP
;sprites.h,216 :: 		animate_bullet(55) ;delay_ms(1000);
	MOV	#55, W10
	CALL	_animate_bullet
	MOV	#16, W8
	MOV	#16968, W7
L_animate_bullet_5s26:
	DEC	W7
	BRA NZ	L_animate_bullet_5s26
	DEC	W8
	BRA NZ	L_animate_bullet_5s26
	NOP
	NOP
	NOP
	NOP
;sprites.h,217 :: 		animate_bullet(37) ;delay_ms(1000);
	MOV	#37, W10
	CALL	_animate_bullet
	MOV	#16, W8
	MOV	#16968, W7
L_animate_bullet_5s28:
	DEC	W7
	BRA NZ	L_animate_bullet_5s28
	DEC	W8
	BRA NZ	L_animate_bullet_5s28
	NOP
	NOP
	NOP
	NOP
;sprites.h,218 :: 		animate_bullet(19) ;delay_ms(1000);
	MOV	#19, W10
	CALL	_animate_bullet
	MOV	#16, W8
	MOV	#16968, W7
L_animate_bullet_5s30:
	DEC	W7
	BRA NZ	L_animate_bullet_5s30
	DEC	W8
	BRA NZ	L_animate_bullet_5s30
	NOP
	NOP
	NOP
	NOP
;sprites.h,219 :: 		animate_bullet(1)  ;delay_ms(1000);
	MOV	#1, W10
	CALL	_animate_bullet
	MOV	#16, W8
	MOV	#16968, W7
L_animate_bullet_5s32:
	DEC	W7
	BRA NZ	L_animate_bullet_5s32
	DEC	W8
	BRA NZ	L_animate_bullet_5s32
	NOP
	NOP
	NOP
	NOP
;sprites.h,220 :: 		}
L_end_animate_bullet_5s:
	POP	W10
	RETURN
; end of _animate_bullet_5s

_animate_shell:

;sprites.h,221 :: 		void animate_shell(unsigned int x_left, unsigned int y_top,code const far char * image){
;sprites.h,222 :: 		Glcd_PartialImage(x_left,y_top,16,16,16,16,image);
	PUSH	W12
	PUSH	W13
	PUSH.D	W12
	MOV	#16, W0
	PUSH	W0
	MOV	#16, W0
	PUSH	W0
	MOV	#16, W13
	MOV	#16, W12
	CALL	_Glcd_PartialImage
	SUB	#8, W15
;sprites.h,223 :: 		}
L_end_animate_shell:
	POP	W13
	POP	W12
	RETURN
; end of _animate_shell

_animate_shell_5s:

;sprites.h,224 :: 		void animate_shell_5s(unsigned int x_left, unsigned int y_top){
;sprites.h,225 :: 		Glcd_Fill(0);
	PUSH	W12
	PUSH	W10
	CLR	W10
	CALL	_Glcd_Fill
	POP	W10
;sprites.h,226 :: 		animate_shell(x_left,y_top,shell_1);
	PUSH	W10
	MOV	#lo_addr(_shell_1), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_shell
	POP	W10
;sprites.h,227 :: 		delay_ms(1667);
	MOV	#26, W8
	MOV	#28614, W7
L_animate_shell_5s34:
	DEC	W7
	BRA NZ	L_animate_shell_5s34
	DEC	W8
	BRA NZ	L_animate_shell_5s34
	NOP
	NOP
	NOP
	NOP
;sprites.h,228 :: 		animate_shell(x_left,y_top,shell_2);
	PUSH	W10
	MOV	#lo_addr(_shell_2), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_shell
	POP	W10
;sprites.h,229 :: 		delay_ms(1667);
	MOV	#26, W8
	MOV	#28614, W7
L_animate_shell_5s36:
	DEC	W7
	BRA NZ	L_animate_shell_5s36
	DEC	W8
	BRA NZ	L_animate_shell_5s36
	NOP
	NOP
	NOP
	NOP
;sprites.h,230 :: 		animate_shell(x_left,y_top,shell_1);
	MOV	#lo_addr(_shell_1), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_shell
;sprites.h,231 :: 		delay_ms(1667);
	MOV	#26, W8
	MOV	#28614, W7
L_animate_shell_5s38:
	DEC	W7
	BRA NZ	L_animate_shell_5s38
	DEC	W8
	BRA NZ	L_animate_shell_5s38
	NOP
	NOP
	NOP
	NOP
;sprites.h,232 :: 		}
L_end_animate_shell_5s:
	POP	W12
	RETURN
; end of _animate_shell_5s

_animate_dog:

;sprites.h,233 :: 		void animate_dog(unsigned int x_left, unsigned int y_top,code const far char * image){
;sprites.h,234 :: 		Glcd_PartialImage(x_left,y_top,31,40,31,40,image);
	PUSH	W12
	PUSH	W13
	PUSH.D	W12
	MOV	#40, W0
	PUSH	W0
	MOV	#31, W0
	PUSH	W0
	MOV	#40, W13
	MOV	#31, W12
	CALL	_Glcd_PartialImage
	SUB	#8, W15
;sprites.h,235 :: 		}
L_end_animate_dog:
	POP	W13
	POP	W12
	RETURN
; end of _animate_dog

_animate_dog_5s:

;sprites.h,236 :: 		void animate_dog_5s(unsigned int x_left, unsigned int y_top){
;sprites.h,237 :: 		Glcd_Fill(0);
	PUSH	W12
	PUSH	W10
	CLR	W10
	CALL	_Glcd_Fill
	POP	W10
;sprites.h,238 :: 		animate_shell(x_left,y_top,shell_1);
	PUSH	W10
	MOV	#lo_addr(_shell_1), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_shell
	POP	W10
;sprites.h,239 :: 		delay_ms(1667);
	MOV	#26, W8
	MOV	#28614, W7
L_animate_dog_5s40:
	DEC	W7
	BRA NZ	L_animate_dog_5s40
	DEC	W8
	BRA NZ	L_animate_dog_5s40
	NOP
	NOP
	NOP
	NOP
;sprites.h,240 :: 		animate_dog(x_left,y_top,dog_2);
	PUSH	W10
	MOV	#lo_addr(_dog_2), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_dog
	POP	W10
;sprites.h,241 :: 		delay_ms(1667);
	MOV	#26, W8
	MOV	#28614, W7
L_animate_dog_5s42:
	DEC	W7
	BRA NZ	L_animate_dog_5s42
	DEC	W8
	BRA NZ	L_animate_dog_5s42
	NOP
	NOP
	NOP
	NOP
;sprites.h,242 :: 		animate_dog(x_left,y_top,dog_2);
	MOV	#lo_addr(_dog_2), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_dog
;sprites.h,243 :: 		delay_ms(1667);
	MOV	#26, W8
	MOV	#28614, W7
L_animate_dog_5s44:
	DEC	W7
	BRA NZ	L_animate_dog_5s44
	DEC	W8
	BRA NZ	L_animate_dog_5s44
	NOP
	NOP
	NOP
	NOP
;sprites.h,244 :: 		}
L_end_animate_dog_5s:
	POP	W12
	RETURN
; end of _animate_dog_5s

_animate_dog_20s:

;sprites.h,245 :: 		void animate_dog_20s(){
;sprites.h,246 :: 		animate_dog_5s(48,12);animate_dog_5s(48,12);animate_dog_5s(48,12);animate_dog_5s(48,12);
	PUSH	W10
	PUSH	W11
	MOV	#12, W11
	MOV	#48, W10
	CALL	_animate_dog_5s
	MOV	#12, W11
	MOV	#48, W10
	CALL	_animate_dog_5s
	MOV	#12, W11
	MOV	#48, W10
	CALL	_animate_dog_5s
	MOV	#12, W11
	MOV	#48, W10
	CALL	_animate_dog_5s
;sprites.h,247 :: 		}
L_end_animate_dog_20s:
	POP	W11
	POP	W10
	RETURN
; end of _animate_dog_20s

_animate_kirby:

;sprites.h,248 :: 		void animate_kirby(unsigned int x_left, unsigned int y_top,code const far char * image){
;sprites.h,249 :: 		Glcd_PartialImage(x_left,y_top,21,19,19,21,image);
	PUSH	W12
	PUSH	W13
	PUSH.D	W12
	MOV	#21, W0
	PUSH	W0
	MOV	#19, W0
	PUSH	W0
	MOV	#19, W13
	MOV	#21, W12
	CALL	_Glcd_PartialImage
	SUB	#8, W15
;sprites.h,250 :: 		}
L_end_animate_kirby:
	POP	W13
	POP	W12
	RETURN
; end of _animate_kirby

_animate_kirby_5s:

;sprites.h,251 :: 		void animate_kirby_5s(int x_left,int y_top){
;sprites.h,252 :: 		Glcd_Fill(0);
	PUSH	W12
	PUSH	W10
	CLR	W10
	CALL	_Glcd_Fill
	POP	W10
;sprites.h,253 :: 		animate_kirby(x_left,y_top,kirby_1);delay_ms(833);
	PUSH	W10
	MOV	#lo_addr(_kirby_1), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_kirby
	POP	W10
	MOV	#13, W8
	MOV	#46575, W7
L_animate_kirby_5s46:
	DEC	W7
	BRA NZ	L_animate_kirby_5s46
	DEC	W8
	BRA NZ	L_animate_kirby_5s46
;sprites.h,254 :: 		animate_kirby(x_left,y_top,kirby_2) ;delay_ms(833);
	PUSH	W10
	MOV	#lo_addr(_kirby_2), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_kirby
	POP	W10
	MOV	#13, W8
	MOV	#46575, W7
L_animate_kirby_5s48:
	DEC	W7
	BRA NZ	L_animate_kirby_5s48
	DEC	W8
	BRA NZ	L_animate_kirby_5s48
;sprites.h,255 :: 		animate_kirby(x_left,y_top,kirby_3) ;delay_ms(833);
	PUSH	W10
	MOV	#lo_addr(_kirby_3), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_kirby
	POP	W10
	MOV	#13, W8
	MOV	#46575, W7
L_animate_kirby_5s50:
	DEC	W7
	BRA NZ	L_animate_kirby_5s50
	DEC	W8
	BRA NZ	L_animate_kirby_5s50
;sprites.h,256 :: 		animate_kirby(x_left,y_top,kirby_4) ;delay_ms(833);
	PUSH	W10
	MOV	#lo_addr(_kirby_4), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_kirby
	POP	W10
	MOV	#13, W8
	MOV	#46575, W7
L_animate_kirby_5s52:
	DEC	W7
	BRA NZ	L_animate_kirby_5s52
	DEC	W8
	BRA NZ	L_animate_kirby_5s52
;sprites.h,257 :: 		animate_kirby(x_left,y_top,kirby_5) ;delay_ms(833);
	PUSH	W10
	MOV	#lo_addr(_kirby_5), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_kirby
	POP	W10
	MOV	#13, W8
	MOV	#46575, W7
L_animate_kirby_5s54:
	DEC	W7
	BRA NZ	L_animate_kirby_5s54
	DEC	W8
	BRA NZ	L_animate_kirby_5s54
;sprites.h,258 :: 		animate_kirby(x_left,y_top,kirby_6);delay_ms(833);
	MOV	#lo_addr(_kirby_6), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_kirby
	MOV	#13, W8
	MOV	#46575, W7
L_animate_kirby_5s56:
	DEC	W7
	BRA NZ	L_animate_kirby_5s56
	DEC	W8
	BRA NZ	L_animate_kirby_5s56
;sprites.h,259 :: 		}
L_end_animate_kirby_5s:
	POP	W12
	RETURN
; end of _animate_kirby_5s

_animate_blooper:

;sprites.h,261 :: 		void animate_blooper(unsigned int x_left, unsigned int y_top,code const far char * blooper){
;sprites.h,262 :: 		Glcd_PartialImage(x_left,y_top,35,34,35,34,blooper);
	PUSH	W12
	PUSH	W13
	PUSH.D	W12
	MOV	#34, W0
	PUSH	W0
	MOV	#35, W0
	PUSH	W0
	MOV	#34, W13
	MOV	#35, W12
	CALL	_Glcd_PartialImage
	SUB	#8, W15
;sprites.h,263 :: 		}
L_end_animate_blooper:
	POP	W13
	POP	W12
	RETURN
; end of _animate_blooper

_animate_blooper_5s:

;sprites.h,264 :: 		void animate_blooper_5s(int x_left,int y_top){
;sprites.h,265 :: 		Glcd_Fill(1);
	PUSH	W12
	PUSH	W10
	MOV.B	#1, W10
	CALL	_Glcd_Fill
	POP	W10
;sprites.h,266 :: 		animate_blooper(x_left,y_top,blooper_1);
	PUSH	W10
	MOV	#lo_addr(_blooper_1), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_blooper
	POP	W10
;sprites.h,267 :: 		delay_ms(2500);
	MOV	#39, W8
	MOV	#9654, W7
L_animate_blooper_5s58:
	DEC	W7
	BRA NZ	L_animate_blooper_5s58
	DEC	W8
	BRA NZ	L_animate_blooper_5s58
	NOP
	NOP
	NOP
;sprites.h,268 :: 		animate_blooper(x_left,y_top,blooper_2);
	MOV	#lo_addr(_blooper_2), W12
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W13
	CALL	_animate_blooper
;sprites.h,269 :: 		delay_ms(2500);
	MOV	#39, W8
	MOV	#9654, W7
L_animate_blooper_5s60:
	DEC	W7
	BRA NZ	L_animate_blooper_5s60
	DEC	W8
	BRA NZ	L_animate_blooper_5s60
	NOP
	NOP
	NOP
;sprites.h,270 :: 		}
L_end_animate_blooper_5s:
	POP	W12
	RETURN
; end of _animate_blooper_5s

_animate_blooper_20s:

;sprites.h,271 :: 		void animate_blooper_20s(){
;sprites.h,272 :: 		animate_blooper_5s(46,15);
	PUSH	W10
	PUSH	W11
	MOV	#15, W11
	MOV	#46, W10
	CALL	_animate_blooper_5s
;sprites.h,273 :: 		animate_blooper_5s(46,15);
	MOV	#15, W11
	MOV	#46, W10
	CALL	_animate_blooper_5s
;sprites.h,274 :: 		animate_blooper_5s(46,15);
	MOV	#15, W11
	MOV	#46, W10
	CALL	_animate_blooper_5s
;sprites.h,275 :: 		animate_blooper_5s(46,15);
	MOV	#15, W11
	MOV	#46, W10
	CALL	_animate_blooper_5s
;sprites.h,276 :: 		}
L_end_animate_blooper_20s:
	POP	W11
	POP	W10
	RETURN
; end of _animate_blooper_20s

_INT0:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;Lab1.c,108 :: 		void INT0() org 0x14{
;Lab1.c,110 :: 		InterrAdapter(0);
	PUSH	W10
	CLR	W10
	CALL	_InterrAdapter
;Lab1.c,111 :: 		delay_ms(600);
	MOV	#10, W8
	MOV	#10181, W7
L_INT062:
	DEC	W7
	BRA NZ	L_INT062
	DEC	W8
	BRA NZ	L_INT062
	NOP
;Lab1.c,112 :: 		IFS0bits.INT0IF=0;
	BCLR	IFS0bits, #0
;Lab1.c,113 :: 		}
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

;Lab1.c,114 :: 		void INT1() org 0x3C{
;Lab1.c,116 :: 		InterrAdapter(1);
	PUSH	W10
	MOV	#1, W10
	CALL	_InterrAdapter
;Lab1.c,117 :: 		delay_ms(600);
	MOV	#10, W8
	MOV	#10181, W7
L_INT164:
	DEC	W7
	BRA NZ	L_INT164
	DEC	W8
	BRA NZ	L_INT164
	NOP
;Lab1.c,118 :: 		IFS1bits.INT1IF=0;
	BCLR	IFS1bits, #4
;Lab1.c,119 :: 		}
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

;Lab1.c,120 :: 		void INT2() org 0x4E{
;Lab1.c,122 :: 		InterrAdapter(2);
	PUSH	W10
	MOV	#2, W10
	CALL	_InterrAdapter
;Lab1.c,123 :: 		delay_ms(600);
	MOV	#10, W8
	MOV	#10181, W7
L_INT266:
	DEC	W7
	BRA NZ	L_INT266
	DEC	W8
	BRA NZ	L_INT266
	NOP
;Lab1.c,124 :: 		IFS1bits.INT2IF=0;
	BCLR	IFS1bits, #13
;Lab1.c,125 :: 		}
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

;Lab1.c,126 :: 		void INT3() org 0x7E{
;Lab1.c,128 :: 		InterrAdapter(3);
	PUSH	W10
	MOV	#3, W10
	CALL	_InterrAdapter
;Lab1.c,129 :: 		delay_ms(600);
	MOV	#10, W8
	MOV	#10181, W7
L_INT368:
	DEC	W7
	BRA NZ	L_INT368
	DEC	W8
	BRA NZ	L_INT368
	NOP
;Lab1.c,130 :: 		IFS3bits.INT3IF=0;
	BCLR	IFS3bits, #5
;Lab1.c,131 :: 		}
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

;Lab1.c,132 :: 		void INT4() org 0x80{
;Lab1.c,134 :: 		InterrAdapter(4);
	PUSH	W10
	MOV	#4, W10
	CALL	_InterrAdapter
;Lab1.c,135 :: 		delay_ms(600);
	MOV	#10, W8
	MOV	#10181, W7
L_INT470:
	DEC	W7
	BRA NZ	L_INT470
	DEC	W8
	BRA NZ	L_INT470
	NOP
;Lab1.c,136 :: 		IFS3bits.INT4IF=0;
	BCLR	IFS3bits, #6
;Lab1.c,137 :: 		}
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

;Lab1.c,138 :: 		void INT_CN() org 0x3A{
;Lab1.c,139 :: 		IFS1bits.CNIF = 0;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	BCLR	IFS1bits, #3
;Lab1.c,140 :: 		if(PORTBbits.RB5 ==1){
	BTSS	PORTBbits, #5
	GOTO	L_INT_CN72
;Lab1.c,142 :: 		valores_cn[0]=1;
	MOV	#1, W0
	MOV	W0, _valores_cn
;Lab1.c,143 :: 		valores_cn[1]=0;
	CLR	W0
	MOV	W0, _valores_cn+2
;Lab1.c,144 :: 		valores_cn[2]=0;
	CLR	W0
	MOV	W0, _valores_cn+4
;Lab1.c,145 :: 		valores_cn[3]=0;
	CLR	W0
	MOV	W0, _valores_cn+6
;Lab1.c,147 :: 		}else if(PORTBbits.RB4==1){
	GOTO	L_INT_CN73
L_INT_CN72:
	BTSS	PORTBbits, #4
	GOTO	L_INT_CN74
;Lab1.c,149 :: 		valores_cn[0]=0;
	CLR	W0
	MOV	W0, _valores_cn
;Lab1.c,150 :: 		valores_cn[1]=1;
	MOV	#1, W0
	MOV	W0, _valores_cn+2
;Lab1.c,151 :: 		valores_cn[2]=0;
	CLR	W0
	MOV	W0, _valores_cn+4
;Lab1.c,152 :: 		valores_cn[3]=0;
	CLR	W0
	MOV	W0, _valores_cn+6
;Lab1.c,153 :: 		}else if(PORTBbits.RB3==1){
	GOTO	L_INT_CN75
L_INT_CN74:
	BTSS	PORTBbits, #3
	GOTO	L_INT_CN76
;Lab1.c,155 :: 		valores_cn[0]=0;
	CLR	W0
	MOV	W0, _valores_cn
;Lab1.c,156 :: 		valores_cn[1]=0;
	CLR	W0
	MOV	W0, _valores_cn+2
;Lab1.c,157 :: 		valores_cn[2]=1;
	MOV	#1, W0
	MOV	W0, _valores_cn+4
;Lab1.c,158 :: 		valores_cn[3]=0;
	CLR	W0
	MOV	W0, _valores_cn+6
;Lab1.c,159 :: 		}else if(PORTBbits.RB2==1){
	GOTO	L_INT_CN77
L_INT_CN76:
	BTSS	PORTBbits, #2
	GOTO	L_INT_CN78
;Lab1.c,161 :: 		valores_cn[0]=0;
	CLR	W0
	MOV	W0, _valores_cn
;Lab1.c,162 :: 		valores_cn[1]=0;
	CLR	W0
	MOV	W0, _valores_cn+2
;Lab1.c,163 :: 		valores_cn[2]=0;
	CLR	W0
	MOV	W0, _valores_cn+4
;Lab1.c,164 :: 		valores_cn[3]=1;
	MOV	#1, W0
	MOV	W0, _valores_cn+6
;Lab1.c,165 :: 		}
L_INT_CN78:
L_INT_CN77:
L_INT_CN75:
L_INT_CN73:
;Lab1.c,166 :: 		if(PORTBbits.RB1==1){
	BTSS	PORTBbits, #1
	GOTO	L_INT_CN79
;Lab1.c,168 :: 		RCONbits.SWDTEN=1;
	BSET	RCONbits, #5
;Lab1.c,169 :: 		Glcd_Write_TEXT("INT WDT",0,0,1);
	MOV.B	#1, W13
	CLR	W12
	CLR	W11
	MOV	#lo_addr(?lstr1_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,170 :: 		}
L_INT_CN79:
;Lab1.c,171 :: 		delay_ms(1000);
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
;Lab1.c,172 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,174 :: 		}
L_end_INT_CN:
	POP	W13
	POP	W12
	POP	W11
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

;Lab1.c,175 :: 		void InterrAdapter(int Ix){
;Lab1.c,176 :: 		if(casoQactivo==1){
	PUSH	W11
	MOV	#lo_addr(_casoQactivo), W0
	MOV.B	[W0], W0
	CP.B	W0, #1
	BRA Z	L__InterrAdapter195
	GOTO	L_InterrAdapter82
L__InterrAdapter195:
;Lab1.c,177 :: 		counters[Ix]++;
	SL	W10, #1, W1
	MOV	#lo_addr(_counters), W0
	ADD	W0, W1, W1
	MOV	[W1], W0
	INC	W0
	MOV	W0, [W1]
;Lab1.c,178 :: 		barra(Ix,counters[Ix]);
	SL	W10, #1, W1
	MOV	#lo_addr(_counters), W0
	ADD	W0, W1, W0
	MOV	[W0], W11
	CALL	_barra
;Lab1.c,179 :: 		}
L_InterrAdapter82:
;Lab1.c,180 :: 		}
L_end_InterrAdapter:
	POP	W11
	RETURN
; end of _InterrAdapter

_config_IO:

;Lab1.c,184 :: 		void config_IO(){
;Lab1.c,185 :: 		ANSELB=0;
	CLR	ANSELB
;Lab1.c,186 :: 		ANSELC=0;
	CLR	ANSELC
;Lab1.c,187 :: 		ANSELD=0;
	CLR	ANSELD
;Lab1.c,188 :: 		ANSELE=0;
	CLR	ANSELE
;Lab1.c,189 :: 		ANSELG=0;             //ANA//logiCO SON B Y F
	CLR	ANSELG
;Lab1.c,190 :: 		TRISB=0xffff;
	MOV	#65535, W0
	MOV	WREG, TRISB
;Lab1.c,191 :: 		TRISDbits.TRISD0=1;
	BSET	TRISDbits, #0
;Lab1.c,192 :: 		TRISDbits.TRISD11=1;
	BSET	TRISDbits, #11
;Lab1.c,193 :: 		TRISDbits.TRISD10=1;
	BSET	TRISDbits, #10
;Lab1.c,194 :: 		TRISDbits.TRISD9=1;
	BSET	TRISDbits, #9
;Lab1.c,195 :: 		TRISE=0;
	CLR	TRISE
;Lab1.c,196 :: 		TRISG=0;
	CLR	TRISG
;Lab1.c,199 :: 		}
L_end_config_IO:
	RETURN
; end of _config_IO

_config_LCD:

;Lab1.c,200 :: 		void config_LCD(){
;Lab1.c,201 :: 		Glcd_Init();
	PUSH	W10
	PUSH	W12
	PUSH	W13
	CALL	_Glcd_Init
;Lab1.c,202 :: 		Glcd_Set_Font(font5x7 , 5, 7, 32);
	MOV.B	#7, W13
	MOV.B	#5, W12
	MOV	#lo_addr(_font5x7), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	MOV	#32, W0
	PUSH	W0
	CALL	_Glcd_Set_Font
	SUB	#2, W15
;Lab1.c,203 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,204 :: 		}
L_end_config_LCD:
	POP	W13
	POP	W12
	POP	W10
	RETURN
; end of _config_LCD

_config_CN:

;Lab1.c,205 :: 		void config_CN(){//CNENx, CNPUx,CNIEx
;Lab1.c,206 :: 		CNENBbits.CNIEB5=1;
	BSET	CNENBbits, #5
;Lab1.c,207 :: 		CNENBbits.CNIEB4=1;
	BSET	CNENBbits, #4
;Lab1.c,208 :: 		CNENBbits.CNIEB3=1;
	BSET	CNENBbits, #3
;Lab1.c,209 :: 		CNENBbits.CNIEB2=1;
	BSET	CNENBbits, #2
;Lab1.c,210 :: 		CNENBbits.CNIEB1=1;
	BSET	CNENBbits, #1
;Lab1.c,212 :: 		CNPUBbits.CNPUB5=1;//CNPU RB1-rb5, rpi33-37
	BSET	CNPUBbits, #5
;Lab1.c,213 :: 		CNPUBbits.CNPUB4=1;
	BSET	CNPUBbits, #4
;Lab1.c,214 :: 		CNPUBbits.CNPUB3=1;
	BSET	CNPUBbits, #3
;Lab1.c,215 :: 		CNPUBbits.CNPUB2=1;
	BSET	CNPUBbits, #2
;Lab1.c,216 :: 		CNPUBbits.CNPUB1=1;
	BSET	CNPUBbits, #1
;Lab1.c,218 :: 		IPC4bits.CNIP=7;//Prioridad
	MOV	IPC4bits, W1
	MOV	#28672, W0
	IOR	W1, W0, W0
	MOV	WREG, IPC4bits
;Lab1.c,219 :: 		IFS1bits.CNIF=0;
	BCLR	IFS1bits, #3
;Lab1.c,220 :: 		IEC1bits.CNIE=1;//Resset Interrupcion
	BSET	IEC1bits, #3
;Lab1.c,221 :: 		}
L_end_config_CN:
	RETURN
; end of _config_CN

_config_INT:

;Lab1.c,222 :: 		void config_INT(){
;Lab1.c,223 :: 		SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
	MOV	#lo_addr(SRbits), W0
	MOV.B	[W0], W1
	MOV.B	#31, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(SRbits), W0
	MOV.B	W1, [W0]
;Lab1.c,224 :: 		INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
	BCLR	INTCON1bits, #15
;Lab1.c,225 :: 		INTCON2bits.GIE=1; //interrupciones habilitadas
	BSET	INTCON2bits, #15
;Lab1.c,226 :: 		CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
	BCLR	CORCONbits, #3
;Lab1.c,228 :: 		IEC0bits.INT0IE=1; //HABILITA INTERRUPCION POR INT0
	BSET	IEC0bits, #0
;Lab1.c,229 :: 		IEC1bits.INT1IE=1; //HABILITA
	BSET	IEC1bits, #4
;Lab1.c,230 :: 		IEC1bits.INT2IE=1;
	BSET	IEC1bits, #13
;Lab1.c,231 :: 		IEC3bits.INT3IE=1;
	BSET	IEC3bits, #5
;Lab1.c,232 :: 		IEC3bits.INT4IE=1;
	BSET	IEC3bits, #6
;Lab1.c,235 :: 		IFS0bits.INT0IF=0; //interrupcion de INT0 ACTIVADA
	BCLR	IFS0bits, #0
;Lab1.c,236 :: 		IFS1bits.INT2IF =0; // interrupcion de INT1 ACTIVADA
	BCLR	IFS1bits, #13
;Lab1.c,237 :: 		IFS1bits.INT2IF =0 ; // INTERRIPCION DE INT2 ACTVADA
	BCLR	IFS1bits, #13
;Lab1.c,238 :: 		IFS3bits.INT3IF =0; //INTERRUPCION DE INT3 ACTIVADA
	BCLR	IFS3bits, #5
;Lab1.c,239 :: 		IFS3bits.INT4IF =0; // INTERRUPCION DE INT4 ACTIVADA
	BCLR	IFS3bits, #6
;Lab1.c,241 :: 		counters[0]=0;
	CLR	W0
	MOV	W0, _counters
;Lab1.c,242 :: 		counters[1]=0;
	CLR	W0
	MOV	W0, _counters+2
;Lab1.c,243 :: 		counters[2]=0;
	CLR	W0
	MOV	W0, _counters+4
;Lab1.c,244 :: 		counters[3]=0;
	CLR	W0
	MOV	W0, _counters+6
;Lab1.c,245 :: 		counters[4]=0;
	CLR	W0
	MOV	W0, _counters+8
;Lab1.c,247 :: 		INTCON2bits.INT0EP=0;
	BCLR	INTCON2bits, #0
;Lab1.c,248 :: 		INTCON2bits.INT1EP=0;
	BCLR	INTCON2bits, #1
;Lab1.c,249 :: 		INTCON2bits.INT2EP=0;
	BCLR	INTCON2bits, #2
;Lab1.c,250 :: 		INTCON2bits.INT3EP=0;
	BCLR	INTCON2bits, #3
;Lab1.c,251 :: 		INTCON2bits.INT4EP =0;
	BCLR	INTCON2bits, #4
;Lab1.c,253 :: 		RPINR0bits.INT1R=75;
	MOV	#19200, W0
	MOV	W0, W1
	MOV	#lo_addr(RPINR0bits), W0
	XOR	W1, [W0], W1
	MOV	#32512, W0
	AND	W1, W0, W1
	MOV	#lo_addr(RPINR0bits), W0
	XOR	W1, [W0], W1
	MOV	W1, RPINR0bits
;Lab1.c,254 :: 		RPINR1bits.INT2R=74;
	MOV.B	#74, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#127, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPINR1bits), W0
	MOV.B	W1, [W0]
;Lab1.c,255 :: 		RPINR1bits.INT3R=73;
	MOV	#18688, W0
	MOV	W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR	W1, [W0], W1
	MOV	#32512, W0
	AND	W1, W0, W1
	MOV	#lo_addr(RPINR1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, RPINR1bits
;Lab1.c,256 :: 		RPINR2bits.INT4R=72;
	MOV.B	#72, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPINR2bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#127, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPINR2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPINR2bits), W0
	MOV.B	W1, [W0]
;Lab1.c,257 :: 		}
L_end_config_INT:
	RETURN
; end of _config_INT

_disable_INT:

;Lab1.c,258 :: 		void disable_INT(){
;Lab1.c,259 :: 		IPC0bits.INT0IP= 0;
	MOV	#lo_addr(IPC0bits), W0
	MOV.B	[W0], W1
	MOV.B	#248, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC0bits), W0
	MOV.B	W1, [W0]
;Lab1.c,260 :: 		IPC5BITS.INT1IP=0;
	MOV	#lo_addr(IPC5bits), W0
	MOV.B	[W0], W1
	MOV.B	#248, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC5bits), W0
	MOV.B	W1, [W0]
;Lab1.c,261 :: 		IPC7bits.INT2IP =0;
	MOV	#lo_addr(IPC7bits), W0
	MOV.B	[W0], W1
	MOV.B	#143, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC7bits), W0
	MOV.B	W1, [W0]
;Lab1.c,262 :: 		IPC13bits.INT3IP=0;
	MOV	#lo_addr(IPC13bits), W0
	MOV.B	[W0], W1
	MOV.B	#143, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC13bits), W0
	MOV.B	W1, [W0]
;Lab1.c,263 :: 		IPC13bits.INT4IP=0;
	MOV	IPC13bits, W1
	MOV	#63743, W0
	AND	W1, W0, W0
	MOV	WREG, IPC13bits
;Lab1.c,264 :: 		counters[0]=0;
	CLR	W0
	MOV	W0, _counters
;Lab1.c,265 :: 		counters[1]=0;
	CLR	W0
	MOV	W0, _counters+2
;Lab1.c,266 :: 		counters[2]=0;
	CLR	W0
	MOV	W0, _counters+4
;Lab1.c,267 :: 		counters[3]=0;
	CLR	W0
	MOV	W0, _counters+6
;Lab1.c,268 :: 		counters[4]=0;
	CLR	W0
	MOV	W0, _counters+8
;Lab1.c,269 :: 		casoQactivo=0;
	MOV	#lo_addr(_casoQactivo), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab1.c,270 :: 		}
L_end_disable_INT:
	RETURN
; end of _disable_INT

_casoExtra:

;Lab1.c,273 :: 		void casoExtra(){
;Lab1.c,275 :: 		Glcd_Fill(0) ;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,276 :: 		for(count=0;count<25;count++){
; count start address is: 10 (W5)
	CLR	W5
; count end address is: 10 (W5)
L_casoExtra83:
; count start address is: 10 (W5)
	CP	W5, #25
	BRA LT	L__casoExtra202
	GOTO	L_casoExtra84
L__casoExtra202:
;Lab1.c,277 :: 		for(Ix=0;Ix<5;Ix++){
; Ix start address is: 12 (W6)
	CLR	W6
; Ix end address is: 12 (W6)
; count end address is: 10 (W5)
L_casoExtra86:
; Ix start address is: 12 (W6)
; count start address is: 10 (W5)
	CP	W6, #5
	BRA LT	L__casoExtra203
	GOTO	L_casoExtra87
L__casoExtra203:
;Lab1.c,278 :: 		x_right=BARS_H_LOCATIONS[Ix]+20;
	MOV	#lo_addr(_BARS_H_LOCATIONS), W0
	ADD	W0, W6, W2
	MOV.B	[W2], W1
	MOV	#lo_addr(_x_right), W0
	ADD.B	W1, #20, [W0]
;Lab1.c,279 :: 		y_bottom=count*2;
	SL	W5, #1, W1
	MOV	#lo_addr(_y_bottom), W0
	MOV.B	W1, [W0]
;Lab1.c,280 :: 		y_top=y_bottom+2;
	MOV	#lo_addr(_y_top), W0
	ADD.B	W1, #2, [W0]
;Lab1.c,281 :: 		Glcd_Box(BARS_H_LOCATIONS[ix],y_top,x_right,y_bottom, 1);
	MOV.B	W1, W13
	MOV	#lo_addr(_x_right), W0
	MOV.B	[W0], W12
	MOV	#lo_addr(_y_top), W0
	MOV.B	[W0], W11
	MOV.B	[W2], W10
	MOV	#1, W0
	PUSH	W0
	CALL	_Glcd_Box
	SUB	#2, W15
;Lab1.c,282 :: 		delay_ms(750);
	MOV	#12, W8
	MOV	#29110, W7
L_casoExtra89:
	DEC	W7
	BRA NZ	L_casoExtra89
	DEC	W8
	BRA NZ	L_casoExtra89
	NOP
	NOP
;Lab1.c,277 :: 		for(Ix=0;Ix<5;Ix++){
	INC	W6
;Lab1.c,283 :: 		}
; Ix end address is: 12 (W6)
	GOTO	L_casoExtra86
L_casoExtra87:
;Lab1.c,284 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_casoExtra91:
	DEC	W7
	BRA NZ	L_casoExtra91
	DEC	W8
	BRA NZ	L_casoExtra91
	NOP
	NOP
	NOP
	NOP
;Lab1.c,276 :: 		for(count=0;count<25;count++){
	INC	W5
;Lab1.c,285 :: 		}
; count end address is: 10 (W5)
	GOTO	L_casoExtra83
L_casoExtra84:
;Lab1.c,286 :: 		}
L_end_casoExtra:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _casoExtra

_casoQ:

;Lab1.c,287 :: 		void casoQ(){
;Lab1.c,288 :: 		IPC0bits.INT0IP= 6;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	MOV.B	#6, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC0bits), W0
	MOV.B	W1, [W0]
;Lab1.c,289 :: 		IPC5BITS.INT1IP=5;
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC5bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IPC5bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC5bits), W0
	MOV.B	W1, [W0]
;Lab1.c,290 :: 		IPC7bits.INT2IP =4;
	MOV.B	#64, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC7bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#112, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC7bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC7bits), W0
	MOV.B	W1, [W0]
;Lab1.c,291 :: 		IPC13bits.INT3IP=3;
	MOV.B	#48, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#112, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC13bits), W0
	MOV.B	W1, [W0]
;Lab1.c,292 :: 		IPC13bits.INT4IP=2;
	MOV	#512, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR	W1, [W0], W1
	MOV	#1792, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC13bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC13bits
;Lab1.c,293 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,294 :: 		casoQactivo=1;
	MOV	#lo_addr(_casoQactivo), W1
	MOV.B	#1, W0
	MOV.B	W0, [W1]
;Lab1.c,295 :: 		do{
L_casoQ93:
;Lab1.c,296 :: 		down=0;special=0;keydata=0;
	MOV	#lo_addr(_down), W1
	CLR	W0
	MOV.B	W0, [W1]
	MOV	#lo_addr(_special), W1
	CLR	W0
	MOV.B	W0, [W1]
	MOV	#lo_addr(_keydata), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab1.c,297 :: 		Ps2_Key_Read(&keydata, &special, &down);
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
;Lab1.c,298 :: 		}while(keydata!=34 && !down & !special);
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#34, W0
	CP.B	W1, W0
	BRA NZ	L__casoQ205
	GOTO	L__casoQ154
L__casoQ205:
	MOV	#lo_addr(_down), W0
	MOV.B	[W0], W0
	CP0.B	W0
	CLR.B	W1
	BRA NZ	L__casoQ206
	INC.B	W1
L__casoQ206:
	MOV	#lo_addr(_special), W0
	MOV.B	[W0], W0
	CP0.B	W0
	CLR.B	W0
	BRA NZ	L__casoQ207
	INC.B	W0
L__casoQ207:
	ZE	W1, W1
	ZE	W0, W0
	AND	W1, W0, W0
	BRA NZ	L__casoQ208
	GOTO	L__casoQ153
L__casoQ208:
	GOTO	L_casoQ93
L__casoQ154:
L__casoQ153:
;Lab1.c,299 :: 		disable_INT();
	CALL	_disable_INT
;Lab1.c,300 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,301 :: 		disable_INT();
	CALL	_disable_INT
;Lab1.c,302 :: 		}
L_end_casoQ:
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _casoQ

_casoW:

;Lab1.c,303 :: 		void casoW(){
;Lab1.c,304 :: 		valores_cn[0]=0;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CLR	W0
	MOV	W0, _valores_cn
;Lab1.c,305 :: 		valores_cn[1]=0;
	CLR	W0
	MOV	W0, _valores_cn+2
;Lab1.c,306 :: 		valores_cn[2]=0;
	CLR	W0
	MOV	W0, _valores_cn+4
;Lab1.c,307 :: 		valores_cn[3]=0;
	CLR	W0
	MOV	W0, _valores_cn+6
;Lab1.c,308 :: 		Glcd_Fill(0)   ;
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,309 :: 		Glcd_Write_TEXT("Caso 2",0,0,1);
	MOV.B	#1, W13
	CLR	W12
	CLR	W11
	MOV	#lo_addr(?lstr2_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,310 :: 		delay_ms(1000);
	MOV	#16, W8
	MOV	#16968, W7
L_casoW98:
	DEC	W7
	BRA NZ	L_casoW98
	DEC	W8
	BRA NZ	L_casoW98
	NOP
	NOP
	NOP
	NOP
;Lab1.c,311 :: 		do{
L_casoW100:
;Lab1.c,312 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,314 :: 		down=0;special=0;keydata=0;
	MOV	#lo_addr(_down), W1
	CLR	W0
	MOV.B	W0, [W1]
	MOV	#lo_addr(_special), W1
	CLR	W0
	MOV.B	W0, [W1]
	MOV	#lo_addr(_keydata), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab1.c,315 :: 		if(valores_cn[0]==1){
	MOV	_valores_cn, W0
	CP	W0, #1
	BRA Z	L__casoW210
	GOTO	L_casoW103
L__casoW210:
;Lab1.c,317 :: 		animate_charmander_5s();
	CALL	_animate_charmander_5s
;Lab1.c,318 :: 		}
	GOTO	L_casoW104
L_casoW103:
;Lab1.c,319 :: 		else if(valores_cn[1]==1){
	MOV	_valores_cn+2, W0
	CP	W0, #1
	BRA Z	L__casoW211
	GOTO	L_casoW105
L__casoW211:
;Lab1.c,322 :: 		animate_kirby_5s(0,0);
	CLR	W11
	CLR	W10
	CALL	_animate_kirby_5s
;Lab1.c,323 :: 		}
	GOTO	L_casoW106
L_casoW105:
;Lab1.c,324 :: 		else if(valores_cn[2]==1){
	MOV	_valores_cn+4, W0
	CP	W0, #1
	BRA Z	L__casoW212
	GOTO	L_casoW107
L__casoW212:
;Lab1.c,327 :: 		animate_shell_5s(0,0);
	CLR	W11
	CLR	W10
	CALL	_animate_shell_5s
;Lab1.c,328 :: 		}
	GOTO	L_casoW108
L_casoW107:
;Lab1.c,329 :: 		else if(valores_cn[3]==1){
	MOV	_valores_cn+6, W0
	CP	W0, #1
	BRA Z	L__casoW213
	GOTO	L_casoW109
L__casoW213:
;Lab1.c,333 :: 		Glcd_PartialImage(100,23,18,18,18,18,bullet);  delay_ms(500);Glcd_Fill(0);
	MOV	#18, W13
	MOV	#18, W12
	MOV	#23, W11
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
	MOV	#8, W8
	MOV	#41252, W7
L_casoW110:
	DEC	W7
	BRA NZ	L_casoW110
	DEC	W8
	BRA NZ	L_casoW110
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,334 :: 		Glcd_PartialImage(80,23,18,18,18,18,bullet);  delay_ms(500);Glcd_Fill(0);
	MOV	#18, W13
	MOV	#18, W12
	MOV	#23, W11
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
	MOV	#8, W8
	MOV	#41252, W7
L_casoW112:
	DEC	W7
	BRA NZ	L_casoW112
	DEC	W8
	BRA NZ	L_casoW112
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,335 :: 		Glcd_PartialImage(60,23,18,18,18,18,bullet);  delay_ms(500);Glcd_Fill(0);
	MOV	#18, W13
	MOV	#18, W12
	MOV	#23, W11
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
L_casoW114:
	DEC	W7
	BRA NZ	L_casoW114
	DEC	W8
	BRA NZ	L_casoW114
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,336 :: 		Glcd_PartialImage(40,23,18,18,18,18,bullet);  delay_ms(500);Glcd_Fill(0);
	MOV	#18, W13
	MOV	#18, W12
	MOV	#23, W11
	MOV	#40, W10
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
L_casoW116:
	DEC	W7
	BRA NZ	L_casoW116
	DEC	W8
	BRA NZ	L_casoW116
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,337 :: 		}
L_casoW109:
L_casoW108:
L_casoW106:
L_casoW104:
;Lab1.c,338 :: 		Ps2_Key_Read(&keydata, &special, &down);
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
;Lab1.c,339 :: 		}while(keydata!=34 && !down & !special);
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#34, W0
	CP.B	W1, W0
	BRA NZ	L__casoW214
	GOTO	L__casoW157
L__casoW214:
	MOV	#lo_addr(_down), W0
	MOV.B	[W0], W0
	CP0.B	W0
	CLR.B	W1
	BRA NZ	L__casoW215
	INC.B	W1
L__casoW215:
	MOV	#lo_addr(_special), W0
	MOV.B	[W0], W0
	CP0.B	W0
	CLR.B	W0
	BRA NZ	L__casoW216
	INC.B	W0
L__casoW216:
	ZE	W1, W1
	ZE	W0, W0
	AND	W1, W0, W0
	BRA NZ	L__casoW217
	GOTO	L__casoW156
L__casoW217:
	GOTO	L_casoW100
L__casoW157:
L__casoW156:
;Lab1.c,340 :: 		}
L_end_casoW:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _casoW

_casoE:

;Lab1.c,342 :: 		void casoE(){
;Lab1.c,343 :: 		Glcd_Fill(0);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,344 :: 		Glcd_Write_TEXT("Caso E",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr3_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,345 :: 		do{
L_casoE120:
;Lab1.c,348 :: 		down=0;
	MOV	#lo_addr(_down), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab1.c,349 :: 		special=0;
	MOV	#lo_addr(_special), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab1.c,350 :: 		if (RCONbits.WDTO==1){
	BTSS	RCONbits, #4
	GOTO	L_casoE123
;Lab1.c,351 :: 		Glcd_Write_TEXT("WDT",0,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr4_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,352 :: 		RCONbits.WDTO=0;
	BCLR	RCONbits, #4
;Lab1.c,353 :: 		PORTEbits.RE5=1;
	BSET.B	PORTEbits, #5
;Lab1.c,354 :: 		animate_dog_20s();
	CALL	_animate_dog_20s
;Lab1.c,355 :: 		}else if(RCONbits.EXTR==1){
	GOTO	L_casoE124
L_casoE123:
	BTSS	RCONbits, #7
	GOTO	L_casoE125
;Lab1.c,356 :: 		Glcd_Write_TEXT("MCLR",0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr5_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,357 :: 		RCONbits.EXTR=0;
	BCLR	RCONbits, #7
;Lab1.c,358 :: 		RCONbits.POR=0;
	BCLR	RCONbits, #0
;Lab1.c,359 :: 		PORTEbits.RE7=1;
	BSET.B	PORTEbits, #7
;Lab1.c,360 :: 		animate_blooper_20s();
	CALL	_animate_blooper_20s
;Lab1.c,361 :: 		continue;
	GOTO	L_casoE122
;Lab1.c,362 :: 		}else if (RCONbits.POR==1){
L_casoE125:
	BTSS	RCONbits, #0
	GOTO	L_casoE127
;Lab1.c,363 :: 		Glcd_Write_TEXT("POR",0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr6_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,364 :: 		RCONbits.POR=0;
	BCLR	RCONbits, #0
;Lab1.c,365 :: 		PORTGbits.RG6=1;
	BSET	PORTGbits, #6
;Lab1.c,366 :: 		animate_charmander_20s();
	CALL	_animate_charmander_20s
;Lab1.c,367 :: 		break;
	GOTO	L_casoE121
;Lab1.c,368 :: 		}
L_casoE127:
L_casoE124:
;Lab1.c,370 :: 		Ps2_Key_Read(&keydata, &special, &down);
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
;Lab1.c,371 :: 		}while(keydata!=34&&!down&&!special);
L_casoE122:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#34, W0
	CP.B	W1, W0
	BRA NZ	L__casoE219
	GOTO	L__casoE161
L__casoE219:
	MOV	#lo_addr(_down), W0
	CP0.B	[W0]
	BRA Z	L__casoE220
	GOTO	L__casoE160
L__casoE220:
	MOV	#lo_addr(_special), W0
	CP0.B	[W0]
	BRA Z	L__casoE221
	GOTO	L__casoE159
L__casoE221:
	GOTO	L_casoE120
L__casoE161:
L__casoE160:
L__casoE159:
L_casoE121:
;Lab1.c,372 :: 		LATEbits.LATE5=0;
	BCLR.B	LATEbits, #5
;Lab1.c,374 :: 		LATEbits.LATE7=0;
	BCLR.B	LATEbits, #7
;Lab1.c,375 :: 		LATGbits.LATG6=0;
	BCLR	LATGbits, #6
;Lab1.c,379 :: 		}
L_end_casoE:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _casoE

_main:
	MOV	#2048, W15
	MOV	#6142, W0
	MOV	WREG, 32
	MOV	#1, W0
	MOV	WREG, 50
	MOV	#4, W0
	IOR	68

;Lab1.c,381 :: 		void main(){
;Lab1.c,382 :: 		config_IO();
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CALL	_config_IO
;Lab1.c,383 :: 		config_LCD();
	CALL	_config_LCD
;Lab1.c,384 :: 		config_INT();
	CALL	_config_INT
;Lab1.c,385 :: 		config_CN();
	CALL	_config_CN
;Lab1.c,386 :: 		animate_charmander_5s();
	CALL	_animate_charmander_5s
;Lab1.c,387 :: 		PS2_Config();
	CALL	_Ps2_Config
;Lab1.c,388 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,390 :: 		while(1){
L_main130:
;Lab1.c,391 :: 		Glcd_Write_TEXT("Laboratorio 1",31,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#31, W11
	MOV	#lo_addr(?lstr7_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,392 :: 		Glcd_Write_TEXT("'Q' para Caso Q",0,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr8_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,393 :: 		Glcd_Write_TEXT("'W' para Caso W",0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr9_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,394 :: 		Glcd_Write_TEXT("'E' para Caso E",0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr10_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,395 :: 		Glcd_Write_TEXT("'R' para WDT   ",0,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	CLR	W11
	MOV	#lo_addr(?lstr11_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,396 :: 		if(Ps2_Key_Read(&keydata, &special, &down)){
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	CP0	W0
	BRA NZ	L__main223
	GOTO	L_main132
L__main223:
;Lab1.c,398 :: 		if(down &&!special){
	MOV	#lo_addr(_down), W0
	CP0.B	[W0]
	BRA NZ	L__main224
	GOTO	L__main164
L__main224:
	MOV	#lo_addr(_special), W0
	CP0.B	[W0]
	BRA Z	L__main225
	GOTO	L__main163
L__main225:
L__main162:
;Lab1.c,399 :: 		switch(keydata){
	GOTO	L_main136
;Lab1.c,400 :: 		case 'q':
L_main138:
;Lab1.c,401 :: 		case 'Q':
L_main139:
;Lab1.c,402 :: 		Glcd_Write_TEXT("Caso Q",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr12_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,403 :: 		casoQ();
	CALL	_casoQ
;Lab1.c,404 :: 		break;
	GOTO	L_main137
;Lab1.c,406 :: 		case 'w':
L_main140:
;Lab1.c,407 :: 		case 'W':
L_main141:
;Lab1.c,408 :: 		Glcd_Write_TEXT("Caso W",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr13_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,409 :: 		casoW();
	CALL	_casoW
;Lab1.c,410 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,411 :: 		break;
	GOTO	L_main137
;Lab1.c,413 :: 		case 'e':
L_main142:
;Lab1.c,414 :: 		case 'E':
L_main143:
;Lab1.c,415 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,416 :: 		Glcd_Write_TEXT("Ultimo Reset",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr14_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,417 :: 		casoE();
	CALL	_casoE
;Lab1.c,418 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,419 :: 		break;
	GOTO	L_main137
;Lab1.c,421 :: 		case 'r':
L_main144:
;Lab1.c,422 :: 		case 'R':
L_main145:
;Lab1.c,423 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,424 :: 		Glcd_Write_TEXT("Caso R ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr15_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,426 :: 		break;
	GOTO	L_main137
;Lab1.c,427 :: 		case 't':
L_main146:
;Lab1.c,428 :: 		case 'T':
L_main147:
;Lab1.c,435 :: 		funcionPractica();
	CALL	_funcionPractica
;Lab1.c,461 :: 		break;
	GOTO	L_main137
;Lab1.c,462 :: 		case 'C':
L_main148:
;Lab1.c,463 :: 		break;
	GOTO	L_main137
;Lab1.c,466 :: 		default:
L_main149:
;Lab1.c,467 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab1.c,468 :: 		Glcd_Write_TEXT("Erroneo ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr17_Lab1), W10
	CALL	_Glcd_Write_Text
;Lab1.c,469 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_main150:
	DEC	W7
	BRA NZ	L_main150
	DEC	W8
	BRA NZ	L_main150
	NOP
	NOP
	NOP
	NOP
;Lab1.c,470 :: 		break;
	GOTO	L_main137
;Lab1.c,471 :: 		}
L_main136:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#113, W0
	CP.B	W1, W0
	BRA NZ	L__main226
	GOTO	L_main138
L__main226:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#81, W0
	CP.B	W1, W0
	BRA NZ	L__main227
	GOTO	L_main139
L__main227:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#119, W0
	CP.B	W1, W0
	BRA NZ	L__main228
	GOTO	L_main140
L__main228:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#87, W0
	CP.B	W1, W0
	BRA NZ	L__main229
	GOTO	L_main141
L__main229:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#101, W0
	CP.B	W1, W0
	BRA NZ	L__main230
	GOTO	L_main142
L__main230:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#69, W0
	CP.B	W1, W0
	BRA NZ	L__main231
	GOTO	L_main143
L__main231:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#114, W0
	CP.B	W1, W0
	BRA NZ	L__main232
	GOTO	L_main144
L__main232:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#82, W0
	CP.B	W1, W0
	BRA NZ	L__main233
	GOTO	L_main145
L__main233:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#116, W0
	CP.B	W1, W0
	BRA NZ	L__main234
	GOTO	L_main146
L__main234:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#84, W0
	CP.B	W1, W0
	BRA NZ	L__main235
	GOTO	L_main147
L__main235:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#67, W0
	CP.B	W1, W0
	BRA NZ	L__main236
	GOTO	L_main148
L__main236:
	GOTO	L_main149
L_main137:
;Lab1.c,398 :: 		if(down &&!special){
L__main164:
L__main163:
;Lab1.c,473 :: 		}
L_main132:
;Lab1.c,474 :: 		}
	GOTO	L_main130
;Lab1.c,475 :: 		}
L_end_main:
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
