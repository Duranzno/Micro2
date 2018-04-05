
_TIMER1:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;Lab2.c,46 :: 		void TIMER1() org 0x1A
;Lab2.c,48 :: 		u_seg++;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W1
	MOV	#lo_addr(_u_seg), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,49 :: 		if(u_seg==10)
	MOV	#lo_addr(_u_seg), W0
	MOV.B	[W0], W0
	CP.B	W0, #10
	BRA Z	L__TIMER165
	GOTO	L_TIMER10
L__TIMER165:
;Lab2.c,50 :: 		{ u_seg=0;
	MOV	#lo_addr(_u_seg), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,51 :: 		d_seg++;
	MOV.B	#1, W1
	MOV	#lo_addr(_d_seg), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,52 :: 		if(d_seg==6)
	MOV	#lo_addr(_d_seg), W0
	MOV.B	[W0], W0
	CP.B	W0, #6
	BRA Z	L__TIMER166
	GOTO	L_TIMER11
L__TIMER166:
;Lab2.c,53 :: 		{ d_seg=0;
	MOV	#lo_addr(_d_seg), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,54 :: 		u_min++;
	MOV.B	#1, W1
	MOV	#lo_addr(_u_min), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,55 :: 		if(u_min==10)
	MOV	#lo_addr(_u_min), W0
	MOV.B	[W0], W0
	CP.B	W0, #10
	BRA Z	L__TIMER167
	GOTO	L_TIMER12
L__TIMER167:
;Lab2.c,56 :: 		{ u_min=0;
	MOV	#lo_addr(_u_min), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,57 :: 		d_min++;
	MOV.B	#1, W1
	MOV	#lo_addr(_d_min), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,58 :: 		if(d_min==6)
	MOV	#lo_addr(_d_min), W0
	MOV.B	[W0], W0
	CP.B	W0, #6
	BRA Z	L__TIMER168
	GOTO	L_TIMER13
L__TIMER168:
;Lab2.c,59 :: 		{ d_min=0;
	MOV	#lo_addr(_d_min), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,60 :: 		u_hora++;
	MOV.B	#1, W1
	MOV	#lo_addr(_u_hora), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,61 :: 		if(u_hora==10 && d_hora==0)
	MOV	#lo_addr(_u_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #10
	BRA Z	L__TIMER169
	GOTO	L__TIMER158
L__TIMER169:
	MOV	#lo_addr(_d_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #0
	BRA Z	L__TIMER170
	GOTO	L__TIMER157
L__TIMER170:
L__TIMER156:
;Lab2.c,62 :: 		{ u_hora=0;
	MOV	#lo_addr(_u_hora), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,63 :: 		d_hora++;
	MOV.B	#1, W1
	MOV	#lo_addr(_d_hora), W0
	ADD.B	W1, [W0], [W0]
;Lab2.c,64 :: 		}
	GOTO	L_TIMER17
;Lab2.c,61 :: 		if(u_hora==10 && d_hora==0)
L__TIMER158:
L__TIMER157:
;Lab2.c,65 :: 		else if(u_hora==3 && d_hora==1)
	MOV	#lo_addr(_u_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #3
	BRA Z	L__TIMER171
	GOTO	L__TIMER160
L__TIMER171:
	MOV	#lo_addr(_d_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #1
	BRA Z	L__TIMER172
	GOTO	L__TIMER159
L__TIMER172:
L__TIMER155:
;Lab2.c,66 :: 		{ u_hora=1;
	MOV	#lo_addr(_u_hora), W1
	MOV.B	#1, W0
	MOV.B	W0, [W1]
;Lab2.c,67 :: 		d_hora=0;
	MOV	#lo_addr(_d_hora), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,65 :: 		else if(u_hora==3 && d_hora==1)
L__TIMER160:
L__TIMER159:
;Lab2.c,68 :: 		}
L_TIMER17:
;Lab2.c,69 :: 		}
L_TIMER13:
;Lab2.c,70 :: 		}
L_TIMER12:
;Lab2.c,71 :: 		}
L_TIMER11:
;Lab2.c,72 :: 		}
L_TIMER10:
;Lab2.c,73 :: 		HORA[0]=d_hora+'0';
	MOV	#lo_addr(_d_hora), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,74 :: 		HORA[1]=u_hora+'0';
	MOV	#lo_addr(_u_hora), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+1), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,75 :: 		HORA[2]=':';
	MOV	#lo_addr(_hora+2), W1
	MOV.B	#58, W0
	MOV.B	W0, [W1]
;Lab2.c,76 :: 		HORA[3]=d_min+'0';
	MOV	#lo_addr(_d_min), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+3), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,77 :: 		HORA[4]=u_min+'0';
	MOV	#lo_addr(_u_min), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+4), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,78 :: 		HORA[5]=':';
	MOV	#lo_addr(_hora+5), W1
	MOV.B	#58, W0
	MOV.B	W0, [W1]
;Lab2.c,79 :: 		HORA[6]=d_seg+'0';
	MOV	#lo_addr(_d_seg), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+6), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,80 :: 		HORA[7]=u_seg+'0';
	MOV	#lo_addr(_u_seg), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+7), W0
	ADD.B	W2, W1, [W0]
;Lab2.c,81 :: 		HORA[8]='\0';
	MOV	#lo_addr(_hora+8), W1
	CLR	W0
	MOV.B	W0, [W1]
;Lab2.c,82 :: 		Glcd_Write_Text(HORA,30,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	MOV.B	#30, W11
	MOV	#lo_addr(_hora), W10
	CALL	_Glcd_Write_Text
;Lab2.c,83 :: 		IFS0bits.T1IF=0;
	BCLR	IFS0bits, #3
;Lab2.c,84 :: 		}
L_end_TIMER1:
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
; end of _TIMER1

_config_IO:

;Lab2.c,86 :: 		void config_IO(){
;Lab2.c,87 :: 		ANSELB=0;
	CLR	ANSELB
;Lab2.c,88 :: 		ANSELC=0;
	CLR	ANSELC
;Lab2.c,89 :: 		ANSELD=0;
	CLR	ANSELD
;Lab2.c,90 :: 		ANSELE=0;
	CLR	ANSELE
;Lab2.c,91 :: 		ANSELG=0;             //ANA//logiCO SON B Y F
	CLR	ANSELG
;Lab2.c,92 :: 		TRISB=0xffff;
	MOV	#65535, W0
	MOV	WREG, TRISB
;Lab2.c,93 :: 		TRISE=0;
	CLR	TRISE
;Lab2.c,94 :: 		TRISG=0;
	CLR	TRISG
;Lab2.c,97 :: 		}
L_end_config_IO:
	RETURN
; end of _config_IO

_config_LCD:

;Lab2.c,98 :: 		void config_LCD(){
;Lab2.c,99 :: 		Glcd_Init();
	PUSH	W10
	PUSH	W12
	PUSH	W13
	CALL	_Glcd_Init
;Lab2.c,100 :: 		Glcd_set_Font(font5x7 , 5, 7, 32);
	MOV.B	#7, W13
	MOV.B	#5, W12
	MOV	#lo_addr(_font5x7), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	MOV	#32, W0
	PUSH	W0
	CALL	_Glcd_Set_Font
	SUB	#2, W15
;Lab2.c,101 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,102 :: 		}
L_end_config_LCD:
	POP	W13
	POP	W12
	POP	W10
	RETURN
; end of _config_LCD

_config_TMR:

;Lab2.c,103 :: 		void config_TMR(){
;Lab2.c,105 :: 		TMR1=0;
	CLR	TMR1
;Lab2.c,106 :: 		PR1=57343; //1000ms
	MOV	#57343, W0
	MOV	WREG, PR1
;Lab2.c,107 :: 		IEC0bits.T1IE=1;//enable interrupcion
	BSET	IEC0bits, #3
;Lab2.c,108 :: 		IFS0bits.T1IF=0;//limpia bandera
	BCLR	IFS0bits, #3
;Lab2.c,109 :: 		IPC0bits.T1IP=3;//prioridad interrupcion
	MOV	#12288, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR	W1, [W0], W1
	MOV	#28672, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC0bits
;Lab2.c,110 :: 		T1CON=0;
	CLR	T1CON
;Lab2.c,111 :: 		T1CONBits.TCKPS= 2;   //Preescalador 256
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
;Lab2.c,113 :: 		}
L_end_config_TMR:
	RETURN
; end of _config_TMR

_config_INT:

;Lab2.c,114 :: 		void config_INT(){
;Lab2.c,115 :: 		SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
	MOV	#lo_addr(SRbits), W0
	MOV.B	[W0], W1
	MOV.B	#31, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(SRbits), W0
	MOV.B	W1, [W0]
;Lab2.c,116 :: 		INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
	BCLR	INTCON1bits, #15
;Lab2.c,117 :: 		INTCON2bits.GIE=1; //interrupciones habilitadas
	BSET	INTCON2bits, #15
;Lab2.c,118 :: 		CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
	BCLR	CORCONbits, #3
;Lab2.c,124 :: 		}
L_end_config_INT:
	RETURN
; end of _config_INT

_oscilador_usado:

;Lab2.c,126 :: 		void oscilador_usado(){
;Lab2.c,127 :: 		switch(OSCCONBits.COSC){
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	GOTO	L_oscilador_usado11
;Lab2.c,128 :: 		case 0:
L_oscilador_usado13:
;Lab2.c,129 :: 		glcd_write_text("FRC",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr1_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,130 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado14:
	DEC	W7
	BRA NZ	L_oscilador_usado14
	DEC	W8
	BRA NZ	L_oscilador_usado14
	NOP
	NOP
	NOP
	NOP
;Lab2.c,131 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,132 :: 		break;
	GOTO	L_oscilador_usado12
;Lab2.c,133 :: 		case 1:
L_oscilador_usado16:
;Lab2.c,134 :: 		glcd_write_text("FRCPLL",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr2_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,135 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado17:
	DEC	W7
	BRA NZ	L_oscilador_usado17
	DEC	W8
	BRA NZ	L_oscilador_usado17
	NOP
	NOP
	NOP
	NOP
;Lab2.c,136 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,137 :: 		break;
	GOTO	L_oscilador_usado12
;Lab2.c,138 :: 		case 2:
L_oscilador_usado19:
;Lab2.c,139 :: 		glcd_write_text("posc",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr3_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,140 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado20:
	DEC	W7
	BRA NZ	L_oscilador_usado20
	DEC	W8
	BRA NZ	L_oscilador_usado20
	NOP
	NOP
	NOP
	NOP
;Lab2.c,141 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,142 :: 		break;
	GOTO	L_oscilador_usado12
;Lab2.c,143 :: 		case 3:
L_oscilador_usado22:
;Lab2.c,144 :: 		glcd_write_text("posc_pll",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr4_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,145 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado23:
	DEC	W7
	BRA NZ	L_oscilador_usado23
	DEC	W8
	BRA NZ	L_oscilador_usado23
	NOP
	NOP
	NOP
	NOP
;Lab2.c,146 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,147 :: 		break;
	GOTO	L_oscilador_usado12
;Lab2.c,148 :: 		case 4:
L_oscilador_usado25:
;Lab2.c,149 :: 		glcd_write_text("sosc",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr5_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,150 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado26:
	DEC	W7
	BRA NZ	L_oscilador_usado26
	DEC	W8
	BRA NZ	L_oscilador_usado26
	NOP
	NOP
	NOP
	NOP
;Lab2.c,151 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,152 :: 		break;
	GOTO	L_oscilador_usado12
;Lab2.c,153 :: 		case 5:
L_oscilador_usado28:
;Lab2.c,154 :: 		glcd_write_text("lprc",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr6_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,155 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado29:
	DEC	W7
	BRA NZ	L_oscilador_usado29
	DEC	W8
	BRA NZ	L_oscilador_usado29
	NOP
	NOP
	NOP
	NOP
;Lab2.c,156 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,157 :: 		break;
	GOTO	L_oscilador_usado12
;Lab2.c,158 :: 		case 6:
L_oscilador_usado31:
;Lab2.c,159 :: 		glcd_write_text("frcdiv16",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr7_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,160 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado32:
	DEC	W7
	BRA NZ	L_oscilador_usado32
	DEC	W8
	BRA NZ	L_oscilador_usado32
	NOP
	NOP
	NOP
	NOP
;Lab2.c,161 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,162 :: 		break;
	GOTO	L_oscilador_usado12
;Lab2.c,163 :: 		case 7:
L_oscilador_usado34:
;Lab2.c,164 :: 		glcd_write_text("frcdivn",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr8_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,165 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado35:
	DEC	W7
	BRA NZ	L_oscilador_usado35
	DEC	W8
	BRA NZ	L_oscilador_usado35
	NOP
	NOP
	NOP
	NOP
;Lab2.c,166 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,167 :: 		break;
	GOTO	L_oscilador_usado12
;Lab2.c,168 :: 		default:
L_oscilador_usado37:
;Lab2.c,169 :: 		glcd_write_text("none",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr9_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,170 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado38:
	DEC	W7
	BRA NZ	L_oscilador_usado38
	DEC	W8
	BRA NZ	L_oscilador_usado38
	NOP
	NOP
	NOP
	NOP
;Lab2.c,171 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,172 :: 		break;
	GOTO	L_oscilador_usado12
;Lab2.c,173 :: 		}
L_oscilador_usado11:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #0
	BRA NZ	L__oscilador_usado78
	GOTO	L_oscilador_usado13
L__oscilador_usado78:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #1
	BRA NZ	L__oscilador_usado79
	GOTO	L_oscilador_usado16
L__oscilador_usado79:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #2
	BRA NZ	L__oscilador_usado80
	GOTO	L_oscilador_usado19
L__oscilador_usado80:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #3
	BRA NZ	L__oscilador_usado81
	GOTO	L_oscilador_usado22
L__oscilador_usado81:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #4
	BRA NZ	L__oscilador_usado82
	GOTO	L_oscilador_usado25
L__oscilador_usado82:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #5
	BRA NZ	L__oscilador_usado83
	GOTO	L_oscilador_usado28
L__oscilador_usado83:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #6
	BRA NZ	L__oscilador_usado84
	GOTO	L_oscilador_usado31
L__oscilador_usado84:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #7
	BRA NZ	L__oscilador_usado85
	GOTO	L_oscilador_usado34
L__oscilador_usado85:
	GOTO	L_oscilador_usado37
L_oscilador_usado12:
;Lab2.c,174 :: 		}
L_end_oscilador_usado:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _oscilador_usado

_main:
	MOV	#2048, W15
	MOV	#6142, W0
	MOV	WREG, 32
	MOV	#1, W0
	MOV	WREG, 50
	MOV	#4, W0
	IOR	68

;Lab2.c,175 :: 		void main(){
;Lab2.c,176 :: 		config_IO();  config_LCD();
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CALL	_config_IO
	CALL	_config_LCD
;Lab2.c,177 :: 		config_INT(); config_TMR();
	CALL	_config_INT
	CALL	_config_TMR
;Lab2.c,179 :: 		PS2_Config();  Glcd_Fill(0);
	CALL	_Ps2_Config
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,180 :: 		while(1){
L_main40:
;Lab2.c,181 :: 		Glcd_Write_TEXT("Laboratorio 2",31,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#31, W11
	MOV	#lo_addr(?lstr10_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,182 :: 		Glcd_Write_TEXT("'Q' Cronometro",0,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr11_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,183 :: 		oscilador_usado();
	CALL	_oscilador_usado
;Lab2.c,184 :: 		if(Ps2_Key_Read(&keydata, &special, &down)){
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	CP0	W0
	BRA NZ	L__main87
	GOTO	L_main42
L__main87:
;Lab2.c,185 :: 		if(down &&!special){
	MOV	#lo_addr(_down), W0
	CP0.B	[W0]
	BRA NZ	L__main88
	GOTO	L__main63
L__main88:
	MOV	#lo_addr(_special), W0
	CP0.B	[W0]
	BRA Z	L__main89
	GOTO	L__main62
L__main89:
L__main61:
;Lab2.c,186 :: 		switch(keydata){
	GOTO	L_main46
;Lab2.c,187 :: 		case 'q':
L_main48:
;Lab2.c,188 :: 		case 'Q':
L_main49:
;Lab2.c,189 :: 		T1CONbits.TON=1;
	BSET	T1CONbits, #15
;Lab2.c,190 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,191 :: 		Glcd_Write_Text("HORA:",0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr12_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,192 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_main50:
	DEC	W7
	BRA NZ	L_main50
	DEC	W8
	BRA NZ	L_main50
	NOP
	NOP
	NOP
	NOP
;Lab2.c,193 :: 		break;
	GOTO	L_main47
;Lab2.c,194 :: 		default:
L_main52:
;Lab2.c,195 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;Lab2.c,196 :: 		Glcd_Write_TEXT("Erroneo ",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr13_Lab2), W10
	CALL	_Glcd_Write_Text
;Lab2.c,197 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_main53:
	DEC	W7
	BRA NZ	L_main53
	DEC	W8
	BRA NZ	L_main53
	NOP
	NOP
	NOP
	NOP
;Lab2.c,198 :: 		break;
	GOTO	L_main47
;Lab2.c,199 :: 		}
L_main46:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#113, W0
	CP.B	W1, W0
	BRA NZ	L__main90
	GOTO	L_main48
L__main90:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#81, W0
	CP.B	W1, W0
	BRA NZ	L__main91
	GOTO	L_main49
L__main91:
	GOTO	L_main52
L_main47:
;Lab2.c,185 :: 		if(down &&!special){
L__main63:
L__main62:
;Lab2.c,201 :: 		}
L_main42:
;Lab2.c,202 :: 		}
	GOTO	L_main40
;Lab2.c,203 :: 		}
L_end_main:
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
