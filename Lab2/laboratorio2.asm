
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
;config.h,50 :: 		TRISFbits.TRISF3=0;  // salida paola
	BCLR.B	TRISFbits, #3
;config.h,51 :: 		TRISEbits.TRISE5=0;
	BCLR.B	TRISEbits, #5
;config.h,52 :: 		TRISEbits.TRISE7=0;
	BCLR.B	TRISEbits, #7
;config.h,53 :: 		TRISGbits.TRISG6=0;
	BCLR	TRISGbits, #6
;config.h,54 :: 		TRISGbits.TRISG8=0;
	BCLR	TRISGbits, #8
;config.h,55 :: 		RPOR6bits.RP85R =0b010000;     //pin comparador 1  RE5
	MOV.B	#16, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPOR6bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#63, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPOR6bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPOR6bits), W0
	MOV.B	W1, [W0]
;config.h,56 :: 		RPOR6bits.RP87R =0b010001;    //pin comparador 2  RE7
	MOV	#4352, W0
	MOV	W0, W1
	MOV	#lo_addr(RPOR6bits), W0
	XOR	W1, [W0], W1
	MOV	#16128, W0
	AND	W1, W0, W1
	MOV	#lo_addr(RPOR6bits), W0
	XOR	W1, [W0], W1
	MOV	W1, RPOR6bits
;config.h,57 :: 		RPOR13bits.RP118R=0b010010;  //pin comparador 3 RG6
	MOV	#4608, W0
	MOV	W0, W1
	MOV	#lo_addr(RPOR13bits), W0
	XOR	W1, [W0], W1
	MOV	#16128, W0
	AND	W1, W0, W1
	MOV	#lo_addr(RPOR13bits), W0
	XOR	W1, [W0], W1
	MOV	W1, RPOR13bits
;config.h,58 :: 		RPOR14bits.RP120R=0b010011;//Las entradas del teclado y las salidas de la pantalla son manejadas por las librerias;
	MOV.B	#19, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPOR14bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#63, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPOR14bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPOR14bits), W0
	MOV.B	W1, [W0]
;config.h,59 :: 		RPOR0bits.RP64R=0b010100;
	MOV.B	#20, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPOR0bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#63, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPOR0bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPOR0bits), W0
	MOV.B	W1, [W0]
;config.h,61 :: 		}
L_end_config_IO:
	RETURN
; end of _config_IO

_config_LCD:

;config.h,62 :: 		void config_LCD(){
;config.h,63 :: 		Glcd_Init();
	PUSH	W10
	PUSH	W12
	PUSH	W13
	CALL	_Glcd_Init
;config.h,64 :: 		Glcd_set_Font(font5x7 , 5, 7, 32);
	MOV.B	#7, W13
	MOV.B	#5, W12
	MOV	#lo_addr(_font5x7), W10
	MOV	#___Lib_System_DefaultPage, W0
	MOV	W0, W11
	MOV	#32, W0
	PUSH	W0
	CALL	_Glcd_Set_Font
	SUB	#2, W15
;config.h,65 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;config.h,66 :: 		}
L_end_config_LCD:
	POP	W13
	POP	W12
	POP	W10
	RETURN
; end of _config_LCD

_config_pin:

;config.h,67 :: 		void config_pin () {
;config.h,68 :: 		TRISDbits.TRISD11=1; // pin D11 como entrada
	BSET	TRISDbits, #11
;config.h,69 :: 		RPINR7bits.IC1R=75; //captura 1 por el D11
	MOV.B	#75, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPINR7bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#127, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPINR7bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPINR7bits), W0
	MOV.B	W1, [W0]
;config.h,70 :: 		TRISDbits.TRISD10=1;// pin D10 como entrada
	BSET	TRISDbits, #10
;config.h,71 :: 		RPINR8bits.IC3R=74; // captura 3 por el d10
	MOV.B	#74, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPINR8bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#127, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPINR8bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPINR8bits), W0
	MOV.B	W1, [W0]
;config.h,72 :: 		TRISDbits.TRISD9=1; // pin d09 como entrada
	BSET	TRISDbits, #9
;config.h,73 :: 		RPINR9bits.IC5R=73; // captura 5 por el d09
	MOV.B	#73, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPINR9bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#127, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPINR9bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPINR9bits), W0
	MOV.B	W1, [W0]
;config.h,74 :: 		TRISDbits.TRISD8=1; // pin D08 como entrada
	BSET	TRISDbits, #8
;config.h,75 :: 		RPINR34bits.IC11R=72; //captura 7 por el d08
	MOV.B	#72, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPINR34bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#127, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPINR34bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPINR34bits), W0
	MOV.B	W1, [W0]
;config.h,77 :: 		}
L_end_config_pin:
	RETURN
; end of _config_pin

_config_captura:

;config.h,78 :: 		void config_captura (){
;config.h,80 :: 		TMR2=0;
	CLR	TMR2
;config.h,81 :: 		T2CONbits.TCKPS=2; // Prescaler 64:1, modo timer
	MOV.B	#32, W0
	MOV.B	W0, W1
	MOV	#lo_addr(T2CONbits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#48, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(T2CONbits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(T2CONbits), W0
	MOV.B	W1, [W0]
;config.h,82 :: 		T2CONbits.TGATE=0;
	BCLR	T2CONbits, #6
;config.h,83 :: 		T2CONbits.TCS=0;
	BCLR	T2CONbits, #1
;config.h,84 :: 		PR2=31250; //1000ms
	MOV	#31250, W0
	MOV	WREG, PR2
;config.h,85 :: 		IEC0bits.T2IE=1;//enable interrupcion
	BSET	IEC0bits, #7
;config.h,86 :: 		IFS0bits.T2IF=0;//limpia bandera
	BCLR	IFS0bits, #7
;config.h,88 :: 		IC2CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
	MOV	IC2CON1bits, W1
	MOV	#7168, W0
	IOR	W1, W0, W0
	MOV	WREG, IC2CON1bits
;config.h,89 :: 		IC2CON1bits.ICM=5; // captura cada 4 flancos positivos
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC2CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC2CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC2CON1bits), W0
	MOV.B	W1, [W0]
;config.h,91 :: 		IC2CON2bits.IC32=1; //configuracion 32 bits
	BSET	IC2CON2bits, #8
;config.h,93 :: 		IC1CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
	MOV	IC1CON1bits, W1
	MOV	#7168, W0
	IOR	W1, W0, W0
	MOV	WREG, IC1CON1bits
;config.h,94 :: 		IC1CON1bits.ICM=5; // captura cada 4 flancos positivos
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC1CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC1CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC1CON1bits), W0
	MOV.B	W1, [W0]
;config.h,96 :: 		IEC0bits.IC1IE=1; //habilita interrupciÃ³n del IC1
	BSET	IEC0bits, #1
;config.h,97 :: 		IFS0bits.IC1IF=0; //limpia la bandera de interrupciÃ³n
	BCLR	IFS0bits, #1
;config.h,99 :: 		IC1CON2bits.IC32=1; //configuracion 32 bits;
	BSET	IC1CON2bits, #8
;config.h,102 :: 		IC4CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
	MOV	IC4CON1bits, W1
	MOV	#7168, W0
	IOR	W1, W0, W0
	MOV	WREG, IC4CON1bits
;config.h,103 :: 		IC4CON1bits.ICM=5; // captura cada 4 flancos positivos
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC4CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC4CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC4CON1bits), W0
	MOV.B	W1, [W0]
;config.h,105 :: 		IC4CON2bits.IC32=1; //configuracion 32 bits
	BSET	IC4CON2bits, #8
;config.h,107 :: 		IC3CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
	MOV	IC3CON1bits, W1
	MOV	#7168, W0
	IOR	W1, W0, W0
	MOV	WREG, IC3CON1bits
;config.h,108 :: 		IC3CON1bits.ICM=5; // captura cada 4 flancos positivos
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC3CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC3CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC3CON1bits), W0
	MOV.B	W1, [W0]
;config.h,110 :: 		IEC2bits.IC3IE=1; //habilita interrupciÃ³n del IC1
	BSET	IEC2bits, #5
;config.h,111 :: 		IFS2bits.IC3IF=0; //limpia la bandera de interrupciÃ³n
	BCLR	IFS2bits, #5
;config.h,113 :: 		IC3CON2bits.IC32=1; //configuracion 32 bits;
	BSET	IC3CON2bits, #8
;config.h,116 :: 		IC6CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
	MOV	IC6CON1bits, W1
	MOV	#7168, W0
	IOR	W1, W0, W0
	MOV	WREG, IC6CON1bits
;config.h,117 :: 		IC6CON1bits.ICM=5; // captura cada 4 flancos positivos
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC6CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC6CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC6CON1bits), W0
	MOV.B	W1, [W0]
;config.h,119 :: 		IC6CON2bits.IC32=1; //configuracion 32 bits
	BSET	IC6CON2bits, #8
;config.h,121 :: 		IC5CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
	MOV	IC5CON1bits, W1
	MOV	#7168, W0
	IOR	W1, W0, W0
	MOV	WREG, IC5CON1bits
;config.h,122 :: 		IC5CON1bits.ICM=5; // captura cada 4 flancos positivos
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC5CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC5CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC5CON1bits), W0
	MOV.B	W1, [W0]
;config.h,124 :: 		IEC2bits.IC5IE=1; //habilita interrupciÃ³n del IC1
	BSET	IEC2bits, #7
;config.h,125 :: 		IFS2bits.IC5IF=0; //limpia la bandera de interrupciÃ³n
	BCLR	IFS2bits, #7
;config.h,127 :: 		IC5CON2bits.IC32=1; //configuracion 32 bits
	BSET	IC5CON2bits, #8
;config.h,129 :: 		IC12CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
	MOV	IC12CON1bits, W1
	MOV	#7168, W0
	IOR	W1, W0, W0
	MOV	WREG, IC12CON1bits
;config.h,130 :: 		IC12CON1bits.ICM=5; // captura cada 4 flancos positivos
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC12CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC12CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC12CON1bits), W0
	MOV.B	W1, [W0]
;config.h,132 :: 		IC12CON2bits.IC32=1; //configuracion 32 bits
	BSET	IC12CON2bits, #8
;config.h,134 :: 		IC11CON1bits.ICTSEL=7; //usa como fuente de reloj el timer1
	MOV	IC11CON1bits, W1
	MOV	#7168, W0
	IOR	W1, W0, W0
	MOV	WREG, IC11CON1bits
;config.h,135 :: 		IC11CON1bits.ICM=5; // captura cada 4 flancos positivos
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC11CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC11CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC11CON1bits), W0
	MOV.B	W1, [W0]
;config.h,137 :: 		IEC7bits.IC11IE=1; //habilita interrupciÃ³n del IC1
	BSET	IEC7bits, #15
;config.h,138 :: 		IFS7bits.IC11IF=0; //limpia la bandera de interrupciÃ³n
	BCLR	IFS7bits, #15
;config.h,140 :: 		IC5CON2bits.IC32=1; //configuracion 32 bits;
	BSET	IC5CON2bits, #8
;config.h,141 :: 		}
L_end_config_captura:
	RETURN
; end of _config_captura

_config_TMR_1:

;config.h,142 :: 		void config_TMR_1(){
;config.h,144 :: 		TMR1=0;
	CLR	TMR1
;config.h,145 :: 		PR1=31250; //1000ms
	MOV	#31250, W0
	MOV	WREG, PR1
;config.h,146 :: 		IEC0bits.T1IE=1;//enable interrupcion
	BSET	IEC0bits, #3
;config.h,147 :: 		IFS0bits.T1IF=0;//limpia bandera
	BCLR	IFS0bits, #3
;config.h,149 :: 		T1CON=0;
	CLR	T1CON
;config.h,150 :: 		T1CONBits.TCKPS= 2;   //Preescalador 64
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
;config.h,151 :: 		T1CONBits.TON=0;
	BCLR	T1CONbits, #15
;config.h,153 :: 		}
L_end_config_TMR_1:
	RETURN
; end of _config_TMR_1

_config_TMR_45:

;config.h,154 :: 		void config_TMR_45(){
;config.h,155 :: 		IEC1bits.T4IE=1;
	BSET	IEC1bits, #11
;config.h,156 :: 		IEC1bits.T5IE=1;
	BSET	IEC1bits, #12
;config.h,157 :: 		IFS1bits.T4IF=0;
	BCLR	IFS1bits, #11
;config.h,158 :: 		IFS1bits.T5IF=0;
	BCLR	IFS1bits, #12
;config.h,159 :: 		T4CONbits.TCKPS=0;            //preescaler 1:1
	MOV	#lo_addr(T4CONbits), W0
	MOV.B	[W0], W1
	MOV.B	#207, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(T4CONbits), W0
	MOV.B	W1, [W0]
;config.h,160 :: 		T4CONbits.TCS=0;
	BCLR	T4CONbits, #1
;config.h,161 :: 		TMR4=0;
	CLR	TMR4
;config.h,162 :: 		PR4=2000;                    // timer a 1ms
	MOV	#2000, W0
	MOV	WREG, PR4
;config.h,163 :: 		T5CONbits.TCKPS=5;            //prescaler 256:1
	MOV.B	#80, W0
	MOV.B	W0, W1
	MOV	#lo_addr(T5CONbits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#48, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(T5CONbits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(T5CONbits), W0
	MOV.B	W1, [W0]
;config.h,164 :: 		T5CONbits.TCS=0;
	BCLR	T5CONbits, #1
;config.h,165 :: 		TMR5=0;
	CLR	TMR5
;config.h,166 :: 		PR5=39062; // timer a 5s
	MOV	#39062, W0
	MOV	WREG, PR5
;config.h,168 :: 		}
L_end_config_TMR_45:
	RETURN
; end of _config_TMR_45

_config_OC:

;config.h,169 :: 		void config_OC(){
;config.h,170 :: 		OC5CON1bits.OCTSEL=7;
	MOV	OC5CON1bits, W1
	MOV	#7168, W0
	IOR	W1, W0, W0
	MOV	WREG, OC5CON1bits
;config.h,171 :: 		OC1CON1bits.OCTSEL=2;        // T4CLK fuente de reloj
	MOV	#2048, W0
	MOV	W0, W1
	MOV	#lo_addr(OC1CON1bits), W0
	XOR	W1, [W0], W1
	MOV	#7168, W0
	AND	W1, W0, W1
	MOV	#lo_addr(OC1CON1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, OC1CON1bits
;config.h,172 :: 		OC2CON1bits.OCTSEL=2;
	MOV	#2048, W0
	MOV	W0, W1
	MOV	#lo_addr(OC2CON1bits), W0
	XOR	W1, [W0], W1
	MOV	#7168, W0
	AND	W1, W0, W1
	MOV	#lo_addr(OC2CON1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, OC2CON1bits
;config.h,173 :: 		OC3CON1bits.OCTSEL=2;
	MOV	#2048, W0
	MOV	W0, W1
	MOV	#lo_addr(OC3CON1bits), W0
	XOR	W1, [W0], W1
	MOV	#7168, W0
	AND	W1, W0, W1
	MOV	#lo_addr(OC3CON1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, OC3CON1bits
;config.h,174 :: 		OC4CON1bits.OCTSEL=2;
	MOV	#2048, W0
	MOV	W0, W1
	MOV	#lo_addr(OC4CON1bits), W0
	XOR	W1, [W0], W1
	MOV	#7168, W0
	AND	W1, W0, W1
	MOV	#lo_addr(OC4CON1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, OC4CON1bits
;config.h,175 :: 		OC1CON2bits.OCTRIS=1;
	BSET	OC1CON2bits, #5
;config.h,176 :: 		OC2CON2bits.OCTRIS=1;
	BSET	OC2CON2bits, #5
;config.h,177 :: 		OC3CON2bits.OCTRIS=1;
	BSET	OC3CON2bits, #5
;config.h,178 :: 		OC4CON2bits.OCTRIS=1;
	BSET	OC4CON2bits, #5
;config.h,179 :: 		OC5CON2bits.OCTRIS=1;
	BSET	OC5CON2bits, #5
;config.h,181 :: 		OC5CON1bits.OCM=5;
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(OC5CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(OC5CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(OC5CON1bits), W0
	MOV.B	W1, [W0]
;config.h,182 :: 		OC1CON1bits.OCM=5;          //MODO COMPARADOR DUAL DE PULSOS CONTINUOS
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(OC1CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(OC1CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(OC1CON1bits), W0
	MOV.B	W1, [W0]
;config.h,183 :: 		OC2CON1bits.OCM=5;
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(OC2CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(OC2CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(OC2CON1bits), W0
	MOV.B	W1, [W0]
;config.h,184 :: 		OC3CON1bits.OCM=5;
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(OC3CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(OC3CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(OC3CON1bits), W0
	MOV.B	W1, [W0]
;config.h,185 :: 		OC4CON1bits.OCM=5;
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(OC4CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(OC4CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(OC4CON1bits), W0
	MOV.B	W1, [W0]
;config.h,186 :: 		OC5R=306; OC5RS=2047;
	MOV	#306, W0
	MOV	WREG, OC5R
	MOV	#2047, W0
	MOV	WREG, OC5RS
;config.h,187 :: 		OC1R=306; OC1RS=2047;     //CICLO UTIL 15%
	MOV	#306, W0
	MOV	WREG, OC1R
	MOV	#2047, W0
	MOV	WREG, OC1RS
;config.h,188 :: 		OC2R=921; OC2RS=2047;     //CICLO UTIL 45%
	MOV	#921, W0
	MOV	WREG, OC2R
	MOV	#2047, W0
	MOV	WREG, OC2RS
;config.h,189 :: 		OC3R=1227; OC3RS=2047;     //CICLO UTIL 60%
	MOV	#1227, W0
	MOV	WREG, OC3R
	MOV	#2047, W0
	MOV	WREG, OC3RS
;config.h,190 :: 		OC4R=1637; OC4RS=2047;     //CICLO UTIL 80%
	MOV	#1637, W0
	MOV	WREG, OC4R
	MOV	#2047, W0
	MOV	WREG, OC4RS
;config.h,191 :: 		OC1CON2bits.SYNCSEL=0b01111;    //disparo con el OC 5
	MOV.B	#15, W0
	MOV.B	W0, W1
	MOV	#lo_addr(OC1CON2bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #31, W1
	MOV	#lo_addr(OC1CON2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(OC1CON2bits), W0
	MOV.B	W1, [W0]
;config.h,192 :: 		OC2CON2bits.SYNCSEL=0b00101;
	MOV.B	#5, W0
	MOV.B	W0, W1
	MOV	#lo_addr(OC2CON2bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #31, W1
	MOV	#lo_addr(OC2CON2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(OC2CON2bits), W0
	MOV.B	W1, [W0]
;config.h,193 :: 		OC3CON2bits.SYNCSEL=0b01111;
	MOV.B	#15, W0
	MOV.B	W0, W1
	MOV	#lo_addr(OC3CON2bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #31, W1
	MOV	#lo_addr(OC3CON2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(OC3CON2bits), W0
	MOV.B	W1, [W0]
;config.h,194 :: 		OC4CON2bits.SYNCSEL=0b01111;
	MOV.B	#15, W0
	MOV.B	W0, W1
	MOV	#lo_addr(OC4CON2bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #31, W1
	MOV	#lo_addr(OC4CON2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(OC4CON2bits), W0
	MOV.B	W1, [W0]
;config.h,195 :: 		OC5CON2bits.SYNCSEL=0b01111;
	MOV.B	#15, W0
	MOV.B	W0, W1
	MOV	#lo_addr(OC5CON2bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #31, W1
	MOV	#lo_addr(OC5CON2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(OC5CON2bits), W0
	MOV.B	W1, [W0]
;config.h,196 :: 		}
L_end_config_OC:
	RETURN
; end of _config_OC

_config_INT:

;config.h,197 :: 		void config_INT(){
;config.h,198 :: 		SRbits.IPL =0;// iNTERRUPCION DE CPU ES DE NIVEL 0
	MOV	#lo_addr(SRbits), W0
	MOV.B	[W0], W1
	MOV.B	#31, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(SRbits), W0
	MOV.B	W1, [W0]
;config.h,199 :: 		INTCON1bits.NSTDIS =0;// INTERRUPCION ANIDADAS ACTIVADAS
	BCLR	INTCON1bits, #15
;config.h,200 :: 		INTCON2bits.GIE=1; //interrupciones habilitadas
	BSET	INTCON2bits, #15
;config.h,201 :: 		CORCONbits.IPL3 = 0; // El nivel del cpu es de nivel 0, las interrupciones por perifericos habilitadas
	BCLR	CORCONbits, #3
;config.h,203 :: 		IPC0bits.T1IP=2;
	MOV	#8192, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR	W1, [W0], W1
	MOV	#28672, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC0bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC0bits
;config.h,204 :: 		IPC1bits.T2IP=4;
	MOV	#16384, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC1bits), W0
	XOR	W1, [W0], W1
	MOV	#28672, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC1bits
;config.h,205 :: 		IPC6bits.T4IP=2;
	MOV	#8192, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC6bits), W0
	XOR	W1, [W0], W1
	MOV	#28672, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC6bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC6bits
;config.h,206 :: 		IPC7bits.T5IP=3;
	MOV.B	#3, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC7bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IPC7bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC7bits), W0
	MOV.B	W1, [W0]
;config.h,207 :: 		IPC0bits.IC1IP=2;
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
;config.h,208 :: 		IPC9bits.IC3IP=2;
	MOV.B	#32, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IPC9bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#112, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IPC9bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IPC9bits), W0
	MOV.B	W1, [W0]
;config.h,209 :: 		IPC9bits.IC5IP=2;
	MOV	#8192, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC9bits), W0
	XOR	W1, [W0], W1
	MOV	#28672, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC9bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC9bits
;config.h,210 :: 		IPC31bits.IC11IP=2;
	MOV	#8192, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC31bits), W0
	XOR	W1, [W0], W1
	MOV	#28672, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC31bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC31bits
;config.h,212 :: 		}
L_end_config_INT:
	RETURN
; end of _config_INT

_config_ic:

;config.h,216 :: 		void config_ic() {
;config.h,217 :: 		IC1CON1bits.ICTSEL=1; // reloj timer 3
	MOV	#1024, W0
	MOV	W0, W1
	MOV	#lo_addr(IC1CON1bits), W0
	XOR	W1, [W0], W1
	MOV	#7168, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IC1CON1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IC1CON1bits
;config.h,218 :: 		IC2CON1bits.ICTSEL=1 ; // reloj timer 3
	MOV	#1024, W0
	MOV	W0, W1
	MOV	#lo_addr(IC2CON1bits), W0
	XOR	W1, [W0], W1
	MOV	#7168, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IC2CON1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IC2CON1bits
;config.h,219 :: 		IC1CON1bits.ICM=2; //captura
	MOV.B	#2, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC1CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC1CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC1CON1bits), W0
	MOV.B	W1, [W0]
;config.h,220 :: 		IC2CON1bits.ICM=2; // captura
	MOV.B	#2, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC2CON1bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #7, W1
	MOV	#lo_addr(IC2CON1bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC2CON1bits), W0
	MOV.B	W1, [W0]
;config.h,221 :: 		IC1CON2bits.IC32=1; // modo 32 bits
	BSET	IC1CON2bits, #8
;config.h,222 :: 		IC2CON2bits.IC32=1; // modo 32 bits
	BSET	IC2CON2bits, #8
;config.h,224 :: 		IC1CON2bits.SYNCSEL=13; // sincronismo timer 3
	MOV.B	#13, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC1CON2bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #31, W1
	MOV	#lo_addr(IC1CON2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC1CON2bits), W0
	MOV.B	W1, [W0]
;config.h,225 :: 		IC2CON2bits.SYNCSEL=13; // sincronismo timer 3
	MOV.B	#13, W0
	MOV.B	W0, W1
	MOV	#lo_addr(IC2CON2bits), W0
	XOR.B	W1, [W0], W1
	AND.B	W1, #31, W1
	MOV	#lo_addr(IC2CON2bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(IC2CON2bits), W0
	MOV.B	W1, [W0]
;config.h,226 :: 		IEC0bits.IC1IE=1; // habilita interrupciones modulo 1
	BSET	IEC0bits, #1
;config.h,227 :: 		IEC0bits.IC2IE=1; // habilita interrupciones modulo 2
	BSET	IEC0bits, #5
;config.h,228 :: 		IFS0bits.IC1IF=0; // borra bandera
	BCLR	IFS0bits, #1
;config.h,229 :: 		IFS0bits.IC2IF=0; // borra bandera
	BCLR	IFS0bits, #5
;config.h,230 :: 		IC1CON2bits.ICTRIG=0;
	BCLR	IC1CON2bits, #7
;config.h,231 :: 		IC2CON2bits.ICTRIG=0;
	BCLR	IC2CON2bits, #7
;config.h,232 :: 		}
L_end_config_ic:
	RETURN
; end of _config_ic

_config_timeric:

;config.h,233 :: 		void config_timeric ()  {
;config.h,234 :: 		T3CONbits.TSIDL=1;
	BSET	T3CONbits, #13
;config.h,235 :: 		T2CON= 0x8020; // config 64:1 prescaler
	MOV	#32800, W0
	MOV	WREG, T2CON
;config.h,236 :: 		PR2=31250; //1000 ms
	MOV	#31250, W0
	MOV	WREG, PR2
;config.h,237 :: 		T2CONbits.T32=1; // Modo 32 bits
	BSET	T2CONbits, #3
;config.h,238 :: 		IPC1bits.T2IP=3;
	MOV	#12288, W0
	MOV	W0, W1
	MOV	#lo_addr(IPC1bits), W0
	XOR	W1, [W0], W1
	MOV	#28672, W0
	AND	W1, W0, W1
	MOV	#lo_addr(IPC1bits), W0
	XOR	W1, [W0], W1
	MOV	W1, IPC1bits
;config.h,239 :: 		}
L_end_config_timeric:
	RETURN
; end of _config_timeric

_clean_PS2:

;ui.h,11 :: 		void clean_PS2(){ keydata = 0, special = 0, down = 0;}
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

;ui.h,13 :: 		void cursor_animation(int it){
;ui.h,15 :: 		for(i=1; i < 6; i++ ){
	PUSH	W11
	PUSH	W12
	PUSH	W13
; i start address is: 0 (W0)
	MOV	#1, W0
; i end address is: 0 (W0)
	MOV	W0, W12
L_cursor_animation0:
; i start address is: 24 (W12)
	CP	W12, #6
	BRA LT	L__cursor_animation186
	GOTO	L_cursor_animation1
L__cursor_animation186:
;ui.h,16 :: 		if(i==it){
	CP	W12, W10
	BRA Z	L__cursor_animation187
	GOTO	L_cursor_animation3
L__cursor_animation187:
;ui.h,17 :: 		Glcd_Write_Text("*",0,i,1);
	PUSH	W12
	PUSH	W10
	MOV.B	#1, W13
	CLR	W11
	MOV	#lo_addr(?lstr1_laboratorio2), W10
	CALL	_Glcd_Write_Text
	POP	W10
	POP	W12
;ui.h,18 :: 		}else{
	GOTO	L_cursor_animation4
L_cursor_animation3:
;ui.h,19 :: 		Glcd_Write_Text(" ",0,i,1);
	PUSH	W12
	PUSH	W10
	MOV.B	#1, W13
	CLR	W11
	MOV	#lo_addr(?lstr2_laboratorio2), W10
	CALL	_Glcd_Write_Text
	POP	W10
	POP	W12
;ui.h,20 :: 		}
L_cursor_animation4:
;ui.h,15 :: 		for(i=1; i < 6; i++ ){
	INC	W12
;ui.h,21 :: 		}
; i end address is: 24 (W12)
	GOTO	L_cursor_animation0
L_cursor_animation1:
;ui.h,22 :: 		}
L_end_cursor_animation:
	POP	W13
	POP	W12
	POP	W11
	RETURN
; end of _cursor_animation

_cursor_menu:
	LNK	#2

;ui.h,23 :: 		int cursor_menu(int max_n_options){
;ui.h,28 :: 		int it=1;
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV	#1, W0
	MOV	W0, [W14+0]
;ui.h,29 :: 		while(keydata!=ENTER){
L_cursor_menu5:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W0
	CP.B	W0, #13
	BRA NZ	L__cursor_menu189
	GOTO	L_cursor_menu6
L__cursor_menu189:
;ui.h,30 :: 		cursor_animation(it);
	PUSH	W10
	MOV	[W14+0], W10
	CALL	_cursor_animation
;ui.h,31 :: 		if(Ps2_Key_Read(&keydata, &special, &down)){
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	POP	W10
	CP0	W0
	BRA NZ	L__cursor_menu190
	GOTO	L_cursor_menu7
L__cursor_menu190:
;ui.h,32 :: 		if(down){
	MOV	#lo_addr(_down), W0
	CP0.B	[W0]
	BRA NZ	L__cursor_menu191
	GOTO	L_cursor_menu8
L__cursor_menu191:
;ui.h,33 :: 		if(keydata==DOWN_ARROW||keydata==UP_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#108, W0
	CP.B	W1, W0
	BRA NZ	L__cursor_menu192
	GOTO	L__cursor_menu149
L__cursor_menu192:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#111, W0
	CP.B	W1, W0
	BRA NZ	L__cursor_menu193
	GOTO	L__cursor_menu148
L__cursor_menu193:
	GOTO	L_cursor_menu11
L__cursor_menu149:
L__cursor_menu148:
;ui.h,34 :: 		if(keydata==DOWN_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#108, W0
	CP.B	W1, W0
	BRA Z	L__cursor_menu194
	GOTO	L_cursor_menu12
L__cursor_menu194:
;ui.h,35 :: 		it=it+1;
	MOV	[W14+0], W0
	INC	W0
	MOV	W0, [W14+0]
;ui.h,36 :: 		if(it>max_n_options){it=1;}
	CP	W0, W10
	BRA GT	L__cursor_menu195
	GOTO	L_cursor_menu13
L__cursor_menu195:
	MOV	#1, W0
	MOV	W0, [W14+0]
L_cursor_menu13:
;ui.h,37 :: 		clean_PS2();
	CALL	_clean_PS2
;ui.h,38 :: 		}
L_cursor_menu12:
;ui.h,39 :: 		if(keydata==UP_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#111, W0
	CP.B	W1, W0
	BRA Z	L__cursor_menu196
	GOTO	L_cursor_menu14
L__cursor_menu196:
;ui.h,40 :: 		it=it-1;
	MOV	[W14+0], W0
	DEC	W0
	MOV	W0, [W14+0]
;ui.h,41 :: 		if(it==0){it=max_n_options;}
	CP	W0, #0
	BRA Z	L__cursor_menu197
	GOTO	L_cursor_menu15
L__cursor_menu197:
	MOV	W10, [W14+0]
L_cursor_menu15:
;ui.h,42 :: 		clean_PS2();
	CALL	_clean_PS2
;ui.h,43 :: 		}
L_cursor_menu14:
;ui.h,44 :: 		cursor_animation(it);
	PUSH	W10
	MOV	[W14+0], W10
	CALL	_cursor_animation
	POP	W10
;ui.h,45 :: 		} else if(keydata==ESC){
	GOTO	L_cursor_menu16
L_cursor_menu11:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#118, W0
	CP.B	W1, W0
	BRA Z	L__cursor_menu198
	GOTO	L_cursor_menu17
L__cursor_menu198:
;ui.h,46 :: 		Glcd_Write_TEXT("ESC" ,60,7,1);delay_ms(500);
	PUSH	W10
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr3_laboratorio2), W10
	CALL	_Glcd_Write_Text
	POP	W10
	MOV	#8, W8
	MOV	#41252, W7
L_cursor_menu18:
	DEC	W7
	BRA NZ	L_cursor_menu18
	DEC	W8
	BRA NZ	L_cursor_menu18
;ui.h,47 :: 		break;
	GOTO	L_cursor_menu6
;ui.h,48 :: 		} else{
L_cursor_menu17:
;ui.h,49 :: 		Glcd_Write_TEXT("ERR" ,60,7,1);delay_ms(500);
	PUSH	W10
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr4_laboratorio2), W10
	CALL	_Glcd_Write_Text
	POP	W10
	MOV	#8, W8
	MOV	#41252, W7
L_cursor_menu21:
	DEC	W7
	BRA NZ	L_cursor_menu21
	DEC	W8
	BRA NZ	L_cursor_menu21
;ui.h,50 :: 		}
L_cursor_menu16:
;ui.h,51 :: 		}
L_cursor_menu8:
;ui.h,52 :: 		}
L_cursor_menu7:
;ui.h,53 :: 		}
	GOTO	L_cursor_menu5
L_cursor_menu6:
;ui.h,54 :: 		return it;
	MOV	[W14+0], W0
;ui.h,55 :: 		}
;ui.h,54 :: 		return it;
;ui.h,55 :: 		}
L_end_cursor_menu:
	POP	W13
	POP	W12
	POP	W11
	ULNK
	RETURN
; end of _cursor_menu

_texto_menu:

;ui.h,59 :: 		void texto_menu(){
;ui.h,60 :: 		Glcd_Write_TEXT("Laboratorio 2",60,0,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr5_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,61 :: 		Glcd_Write_TEXT("1) Cronometro",SANGRIA,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr6_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,62 :: 		Glcd_Write_TEXT("1) Captura"   ,SANGRIA,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr7_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,63 :: 		Glcd_Write_TEXT("3) PWM  "     ,SANGRIA,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr8_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,64 :: 		}
L_end_texto_menu:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _texto_menu

_texto_caso_1:

;ui.h,65 :: 		void texto_caso_1(){
;ui.h,67 :: 		Glcd_Write_Text("Cronometro",60,0,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr9_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,68 :: 		Glcd_Write_Text("1) Programar Hora",SANGRIA,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr10_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,69 :: 		Glcd_Write_Text("2) PLAY"  ,SANGRIA,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr11_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,70 :: 		Glcd_Write_Text("3) PAUSE"  ,SANGRIA,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr12_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,71 :: 		Glcd_Write_Text("4) RESET  "  ,SANGRIA,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr13_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,72 :: 		Glcd_Write_Text("5) Alarma",SANGRIA,5,1);
	MOV.B	#1, W13
	MOV.B	#5, W12
	MOV.B	#6, W11
	MOV	#lo_addr(?lstr14_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,73 :: 		}
L_end_texto_caso_1:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _texto_caso_1

_texto_caso_2:

;ui.h,74 :: 		void texto_caso_2(){
;ui.h,75 :: 		GLCD_FILL(0);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CLR	W10
	CALL	_Glcd_Fill
;ui.h,76 :: 		Glcd_Write_Text("Puerto de Entrada",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr15_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,77 :: 		Glcd_Write_Text("RP75/RD11"  ,0,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr16_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,78 :: 		Glcd_Write_Text("RP74/RD10"  ,0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr17_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,79 :: 		Glcd_Write_Text("RP73/RD09"  ,0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr18_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,80 :: 		Glcd_Write_Text("RP72/RD8"  ,0,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	CLR	W11
	MOV	#lo_addr(?lstr19_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,81 :: 		}
L_end_texto_caso_2:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _texto_caso_2

_texto_caso_3:

;ui.h,82 :: 		void texto_caso_3(){
;ui.h,83 :: 		GLCD_FILL(0);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CLR	W10
	CALL	_Glcd_Fill
;ui.h,84 :: 		Glcd_Write_Text("Puerto de Entrada",60,0,1);
	MOV.B	#1, W13
	CLR	W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr20_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,85 :: 		Glcd_Write_Text("RP101/RG8 80%"  ,0,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	CLR	W11
	MOV	#lo_addr(?lstr21_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,86 :: 		Glcd_Write_Text("RP85 /RE5 15%"  ,0,1,1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr22_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,87 :: 		Glcd_Write_Text("RP87 /RE7 45%"  ,0,2,1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	CLR	W11
	MOV	#lo_addr(?lstr23_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,88 :: 		Glcd_Write_Text("RP87 /RG6 60%"  ,0,3,1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	CLR	W11
	MOV	#lo_addr(?lstr24_laboratorio2), W10
	CALL	_Glcd_Write_Text
;ui.h,89 :: 		}
L_end_texto_caso_3:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _texto_caso_3

_page2pos:

;extras.h,6 :: 		int page2pos(int page_num){
;extras.h,7 :: 		switch(page_num){
	GOTO	L_page2pos23
;extras.h,8 :: 		case 0:
L_page2pos25:
;extras.h,9 :: 		return 0;
	CLR	W0
	GOTO	L_end_page2pos
;extras.h,11 :: 		case 1:
L_page2pos26:
;extras.h,12 :: 		return 8;
	MOV	#8, W0
	GOTO	L_end_page2pos
;extras.h,14 :: 		case 2:
L_page2pos27:
;extras.h,15 :: 		return 16;
	MOV	#16, W0
	GOTO	L_end_page2pos
;extras.h,17 :: 		case 3:
L_page2pos28:
;extras.h,18 :: 		return 24;
	MOV	#24, W0
	GOTO	L_end_page2pos
;extras.h,20 :: 		case 4:
L_page2pos29:
;extras.h,21 :: 		return 32;
	MOV	#32, W0
	GOTO	L_end_page2pos
;extras.h,23 :: 		case 5:
L_page2pos30:
;extras.h,24 :: 		return 40;
	MOV	#40, W0
	GOTO	L_end_page2pos
;extras.h,26 :: 		case 6:
L_page2pos31:
;extras.h,27 :: 		return 48;
	MOV	#48, W0
	GOTO	L_end_page2pos
;extras.h,29 :: 		case 7:
L_page2pos32:
;extras.h,30 :: 		return 56;
	MOV	#56, W0
	GOTO	L_end_page2pos
;extras.h,32 :: 		}
L_page2pos23:
	CP	W10, #0
	BRA NZ	L__page2pos204
	GOTO	L_page2pos25
L__page2pos204:
	CP	W10, #1
	BRA NZ	L__page2pos205
	GOTO	L_page2pos26
L__page2pos205:
	CP	W10, #2
	BRA NZ	L__page2pos206
	GOTO	L_page2pos27
L__page2pos206:
	CP	W10, #3
	BRA NZ	L__page2pos207
	GOTO	L_page2pos28
L__page2pos207:
	CP	W10, #4
	BRA NZ	L__page2pos208
	GOTO	L_page2pos29
L__page2pos208:
	CP	W10, #5
	BRA NZ	L__page2pos209
	GOTO	L_page2pos30
L__page2pos209:
	CP	W10, #6
	BRA NZ	L__page2pos210
	GOTO	L_page2pos31
L__page2pos210:
	CP	W10, #7
	BRA NZ	L__page2pos211
	GOTO	L_page2pos32
L__page2pos211:
;extras.h,33 :: 		}
L_end_page2pos:
	RETURN
; end of _page2pos

_intToAscii:
	LNK	#2

;extras.h,34 :: 		char intToAscii(int fn){
;extras.h,35 :: 		char t=0;
	PUSH	W11
	MOV	#0, W0
	MOV.B	W0, [W14+0]
;extras.h,36 :: 		if(fn>0&&fn<=9){
	CP	W10, #0
	BRA GT	L__intToAscii213
	GOTO	L__intToAscii152
L__intToAscii213:
	CP	W10, #9
	BRA LE	L__intToAscii214
	GOTO	L__intToAscii151
L__intToAscii214:
L__intToAscii150:
;extras.h,37 :: 		intToStr(fn,t);
	ADD	W14, #0, W0
	ZE	[W0], W11
	CALL	_IntToStr
;extras.h,38 :: 		}else if(fn==10){
	GOTO	L_intToAscii36
;extras.h,36 :: 		if(fn>0&&fn<=9){
L__intToAscii152:
L__intToAscii151:
;extras.h,38 :: 		}else if(fn==10){
	CP	W10, #10
	BRA Z	L__intToAscii215
	GOTO	L_intToAscii37
L__intToAscii215:
;extras.h,39 :: 		intToStr(0,t);
	ADD	W14, #0, W0
	PUSH	W10
	ZE	[W0], W11
	CLR	W10
	CALL	_IntToStr
	POP	W10
;extras.h,40 :: 		}else{
	GOTO	L_intToAscii38
L_intToAscii37:
;extras.h,41 :: 		t='0';
	MOV.B	#48, W0
	MOV.B	W0, [W14+0]
;extras.h,42 :: 		}
L_intToAscii38:
L_intToAscii36:
;extras.h,43 :: 		return t;
	MOV.B	[W14+0], W0
;extras.h,44 :: 		}
;extras.h,43 :: 		return t;
;extras.h,44 :: 		}
L_end_intToAscii:
	POP	W11
	ULNK
	RETURN
; end of _intToAscii

_oscilador_usado:

;extras.h,46 :: 		void oscilador_usado(){
;extras.h,47 :: 		switch(OSCCONBits.COSC){
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	GOTO	L_oscilador_usado39
;extras.h,48 :: 		case 0:
L_oscilador_usado41:
;extras.h,49 :: 		glcd_write_text("FRC",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr25_laboratorio2), W10
	CALL	_Glcd_Write_Text
;extras.h,50 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado42:
	DEC	W7
	BRA NZ	L_oscilador_usado42
	DEC	W8
	BRA NZ	L_oscilador_usado42
	NOP
	NOP
	NOP
	NOP
;extras.h,51 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,52 :: 		break;
	GOTO	L_oscilador_usado40
;extras.h,53 :: 		case 1:
L_oscilador_usado44:
;extras.h,54 :: 		glcd_write_text("FRCPLL",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr26_laboratorio2), W10
	CALL	_Glcd_Write_Text
;extras.h,55 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado45:
	DEC	W7
	BRA NZ	L_oscilador_usado45
	DEC	W8
	BRA NZ	L_oscilador_usado45
	NOP
	NOP
	NOP
	NOP
;extras.h,56 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,57 :: 		break;
	GOTO	L_oscilador_usado40
;extras.h,58 :: 		case 2:
L_oscilador_usado47:
;extras.h,59 :: 		glcd_write_text("posc",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr27_laboratorio2), W10
	CALL	_Glcd_Write_Text
;extras.h,60 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado48:
	DEC	W7
	BRA NZ	L_oscilador_usado48
	DEC	W8
	BRA NZ	L_oscilador_usado48
	NOP
	NOP
	NOP
	NOP
;extras.h,61 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,62 :: 		break;
	GOTO	L_oscilador_usado40
;extras.h,63 :: 		case 3:
L_oscilador_usado50:
;extras.h,64 :: 		glcd_write_text("posc_pll",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr28_laboratorio2), W10
	CALL	_Glcd_Write_Text
;extras.h,65 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado51:
	DEC	W7
	BRA NZ	L_oscilador_usado51
	DEC	W8
	BRA NZ	L_oscilador_usado51
	NOP
	NOP
	NOP
	NOP
;extras.h,66 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,67 :: 		break;
	GOTO	L_oscilador_usado40
;extras.h,68 :: 		case 4:
L_oscilador_usado53:
;extras.h,69 :: 		glcd_write_text("sosc",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr29_laboratorio2), W10
	CALL	_Glcd_Write_Text
;extras.h,70 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado54:
	DEC	W7
	BRA NZ	L_oscilador_usado54
	DEC	W8
	BRA NZ	L_oscilador_usado54
	NOP
	NOP
	NOP
	NOP
;extras.h,71 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,72 :: 		break;
	GOTO	L_oscilador_usado40
;extras.h,73 :: 		case 5:
L_oscilador_usado56:
;extras.h,74 :: 		glcd_write_text("lprc",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr30_laboratorio2), W10
	CALL	_Glcd_Write_Text
;extras.h,75 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado57:
	DEC	W7
	BRA NZ	L_oscilador_usado57
	DEC	W8
	BRA NZ	L_oscilador_usado57
	NOP
	NOP
	NOP
	NOP
;extras.h,76 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,77 :: 		break;
	GOTO	L_oscilador_usado40
;extras.h,78 :: 		case 6:
L_oscilador_usado59:
;extras.h,79 :: 		glcd_write_text("frcdiv16",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr31_laboratorio2), W10
	CALL	_Glcd_Write_Text
;extras.h,80 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado60:
	DEC	W7
	BRA NZ	L_oscilador_usado60
	DEC	W8
	BRA NZ	L_oscilador_usado60
	NOP
	NOP
	NOP
	NOP
;extras.h,81 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,82 :: 		break;
	GOTO	L_oscilador_usado40
;extras.h,83 :: 		case 7:
L_oscilador_usado62:
;extras.h,84 :: 		glcd_write_text("frcdivn",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr32_laboratorio2), W10
	CALL	_Glcd_Write_Text
;extras.h,85 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado63:
	DEC	W7
	BRA NZ	L_oscilador_usado63
	DEC	W8
	BRA NZ	L_oscilador_usado63
	NOP
	NOP
	NOP
	NOP
;extras.h,86 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,87 :: 		break;
	GOTO	L_oscilador_usado40
;extras.h,88 :: 		default:
L_oscilador_usado65:
;extras.h,89 :: 		glcd_write_text("none",0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(?lstr33_laboratorio2), W10
	CALL	_Glcd_Write_Text
;extras.h,90 :: 		delay_ms(2000);
	MOV	#31, W8
	MOV	#33937, W7
L_oscilador_usado66:
	DEC	W7
	BRA NZ	L_oscilador_usado66
	DEC	W8
	BRA NZ	L_oscilador_usado66
	NOP
	NOP
	NOP
	NOP
;extras.h,91 :: 		glcd_fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;extras.h,92 :: 		break;
	GOTO	L_oscilador_usado40
;extras.h,93 :: 		}
L_oscilador_usado39:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #0
	BRA NZ	L__oscilador_usado217
	GOTO	L_oscilador_usado41
L__oscilador_usado217:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #1
	BRA NZ	L__oscilador_usado218
	GOTO	L_oscilador_usado44
L__oscilador_usado218:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #2
	BRA NZ	L__oscilador_usado219
	GOTO	L_oscilador_usado47
L__oscilador_usado219:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #3
	BRA NZ	L__oscilador_usado220
	GOTO	L_oscilador_usado50
L__oscilador_usado220:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #4
	BRA NZ	L__oscilador_usado221
	GOTO	L_oscilador_usado53
L__oscilador_usado221:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #5
	BRA NZ	L__oscilador_usado222
	GOTO	L_oscilador_usado56
L__oscilador_usado222:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #6
	BRA NZ	L__oscilador_usado223
	GOTO	L_oscilador_usado59
L__oscilador_usado223:
	MOV	OSCCONbits, WREG
	MOV	W0, W1
	MOV	#28672, W0
	AND	W1, W0, W1
	LSR	W1, #12, W1
	CP	W1, #7
	BRA NZ	L__oscilador_usado224
	GOTO	L_oscilador_usado62
L__oscilador_usado224:
	GOTO	L_oscilador_usado65
L_oscilador_usado40:
;extras.h,94 :: 		}
L_end_oscilador_usado:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _oscilador_usado

_TIMER1:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;laboratorio2.c,17 :: 		void TIMER1() org 0x1A{
;laboratorio2.c,18 :: 		u_seg++;
	PUSH	W10
	MOV.B	#1, W1
	MOV	#lo_addr(_u_seg), W0
	ADD.B	W1, [W0], [W0]
;laboratorio2.c,19 :: 		if(u_seg==10)
	MOV	#lo_addr(_u_seg), W0
	MOV.B	[W0], W0
	CP.B	W0, #10
	BRA Z	L__TIMER1226
	GOTO	L_TIMER168
L__TIMER1226:
;laboratorio2.c,20 :: 		{ u_seg=0;
	MOV	#lo_addr(_u_seg), W1
	CLR	W0
	MOV.B	W0, [W1]
;laboratorio2.c,21 :: 		d_seg++;
	MOV.B	#1, W1
	MOV	#lo_addr(_d_seg), W0
	ADD.B	W1, [W0], [W0]
;laboratorio2.c,22 :: 		if(d_seg==6)
	MOV	#lo_addr(_d_seg), W0
	MOV.B	[W0], W0
	CP.B	W0, #6
	BRA Z	L__TIMER1227
	GOTO	L_TIMER169
L__TIMER1227:
;laboratorio2.c,23 :: 		{ d_seg=0;
	MOV	#lo_addr(_d_seg), W1
	CLR	W0
	MOV.B	W0, [W1]
;laboratorio2.c,24 :: 		u_min++;
	MOV.B	#1, W1
	MOV	#lo_addr(_u_min), W0
	ADD.B	W1, [W0], [W0]
;laboratorio2.c,25 :: 		if(u_min==10)
	MOV	#lo_addr(_u_min), W0
	MOV.B	[W0], W0
	CP.B	W0, #10
	BRA Z	L__TIMER1228
	GOTO	L_TIMER170
L__TIMER1228:
;laboratorio2.c,26 :: 		{ u_min=0;
	MOV	#lo_addr(_u_min), W1
	CLR	W0
	MOV.B	W0, [W1]
;laboratorio2.c,27 :: 		d_min++;
	MOV.B	#1, W1
	MOV	#lo_addr(_d_min), W0
	ADD.B	W1, [W0], [W0]
;laboratorio2.c,28 :: 		if(d_min==6)
	MOV	#lo_addr(_d_min), W0
	MOV.B	[W0], W0
	CP.B	W0, #6
	BRA Z	L__TIMER1229
	GOTO	L_TIMER171
L__TIMER1229:
;laboratorio2.c,29 :: 		{ d_min=0;
	MOV	#lo_addr(_d_min), W1
	CLR	W0
	MOV.B	W0, [W1]
;laboratorio2.c,30 :: 		u_hora++;
	MOV.B	#1, W1
	MOV	#lo_addr(_u_hora), W0
	ADD.B	W1, [W0], [W0]
;laboratorio2.c,31 :: 		if(u_hora==10 && d_hora==0)
	MOV	#lo_addr(_u_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #10
	BRA Z	L__TIMER1230
	GOTO	L__TIMER1157
L__TIMER1230:
	MOV	#lo_addr(_d_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #0
	BRA Z	L__TIMER1231
	GOTO	L__TIMER1156
L__TIMER1231:
L__TIMER1155:
;laboratorio2.c,32 :: 		{ u_hora=0;
	MOV	#lo_addr(_u_hora), W1
	CLR	W0
	MOV.B	W0, [W1]
;laboratorio2.c,33 :: 		d_hora++;
	MOV.B	#1, W1
	MOV	#lo_addr(_d_hora), W0
	ADD.B	W1, [W0], [W0]
;laboratorio2.c,34 :: 		}
	GOTO	L_TIMER175
;laboratorio2.c,31 :: 		if(u_hora==10 && d_hora==0)
L__TIMER1157:
L__TIMER1156:
;laboratorio2.c,35 :: 		else if(u_hora==3 && d_hora==1)
	MOV	#lo_addr(_u_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #3
	BRA Z	L__TIMER1232
	GOTO	L__TIMER1159
L__TIMER1232:
	MOV	#lo_addr(_d_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #1
	BRA Z	L__TIMER1233
	GOTO	L__TIMER1158
L__TIMER1233:
L__TIMER1154:
;laboratorio2.c,36 :: 		{ u_hora=1;
	MOV	#lo_addr(_u_hora), W1
	MOV.B	#1, W0
	MOV.B	W0, [W1]
;laboratorio2.c,37 :: 		d_hora=0;
	MOV	#lo_addr(_d_hora), W1
	CLR	W0
	MOV.B	W0, [W1]
;laboratorio2.c,35 :: 		else if(u_hora==3 && d_hora==1)
L__TIMER1159:
L__TIMER1158:
;laboratorio2.c,38 :: 		}
L_TIMER175:
;laboratorio2.c,39 :: 		}
L_TIMER171:
;laboratorio2.c,40 :: 		}
L_TIMER170:
;laboratorio2.c,41 :: 		}
L_TIMER169:
;laboratorio2.c,42 :: 		}
L_TIMER168:
;laboratorio2.c,43 :: 		if(ENALARM&&Alarma[0]==HORA[0]&&Alarma[1]==HORA[1]&&Alarma[3]==HORA[3]&&Alarma[4]==HORA[4]){
	MOV	#lo_addr(_ENALARM), W0
	CP0	[W0]
	BRA NZ	L__TIMER1234
	GOTO	L__TIMER1164
L__TIMER1234:
	MOV	#lo_addr(_alarma), W0
	MOV.B	[W0], W1
	MOV	#lo_addr(_hora), W0
	CP.B	W1, [W0]
	BRA Z	L__TIMER1235
	GOTO	L__TIMER1163
L__TIMER1235:
	MOV	#lo_addr(_alarma+1), W0
	MOV.B	[W0], W1
	MOV	#lo_addr(_hora+1), W0
	CP.B	W1, [W0]
	BRA Z	L__TIMER1236
	GOTO	L__TIMER1162
L__TIMER1236:
	MOV	#lo_addr(_alarma+3), W0
	MOV.B	[W0], W1
	MOV	#lo_addr(_hora+3), W0
	CP.B	W1, [W0]
	BRA Z	L__TIMER1237
	GOTO	L__TIMER1161
L__TIMER1237:
	MOV	#lo_addr(_alarma+4), W0
	MOV.B	[W0], W1
	MOV	#lo_addr(_hora+4), W0
	CP.B	W1, [W0]
	BRA Z	L__TIMER1238
	GOTO	L__TIMER1160
L__TIMER1238:
L__TIMER1153:
;laboratorio2.c,44 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;laboratorio2.c,46 :: 		ENALARM=0;
	CLR	W0
	MOV	W0, _ENALARM
;laboratorio2.c,43 :: 		if(ENALARM&&Alarma[0]==HORA[0]&&Alarma[1]==HORA[1]&&Alarma[3]==HORA[3]&&Alarma[4]==HORA[4]){
L__TIMER1164:
L__TIMER1163:
L__TIMER1162:
L__TIMER1161:
L__TIMER1160:
;laboratorio2.c,48 :: 		HORA[0]=d_hora+'0';
	MOV	#lo_addr(_d_hora), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora), W0
	ADD.B	W2, W1, [W0]
;laboratorio2.c,49 :: 		HORA[1]=u_hora+'0';
	MOV	#lo_addr(_u_hora), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+1), W0
	ADD.B	W2, W1, [W0]
;laboratorio2.c,50 :: 		HORA[2]=':';
	MOV	#lo_addr(_hora+2), W1
	MOV.B	#58, W0
	MOV.B	W0, [W1]
;laboratorio2.c,51 :: 		HORA[3]=d_min+'0';
	MOV	#lo_addr(_d_min), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+3), W0
	ADD.B	W2, W1, [W0]
;laboratorio2.c,52 :: 		HORA[4]=u_min+'0';
	MOV	#lo_addr(_u_min), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+4), W0
	ADD.B	W2, W1, [W0]
;laboratorio2.c,53 :: 		HORA[5]=':';
	MOV	#lo_addr(_hora+5), W1
	MOV.B	#58, W0
	MOV.B	W0, [W1]
;laboratorio2.c,54 :: 		HORA[6]=d_seg+'0';
	MOV	#lo_addr(_d_seg), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+6), W0
	ADD.B	W2, W1, [W0]
;laboratorio2.c,55 :: 		HORA[7]=u_seg+'0';
	MOV	#lo_addr(_u_seg), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+7), W0
	ADD.B	W2, W1, [W0]
;laboratorio2.c,56 :: 		HORA[8]=':';
	MOV	#lo_addr(_hora+8), W1
	MOV.B	#58, W0
	MOV.B	W0, [W1]
;laboratorio2.c,57 :: 		HORA[9]=d_mseg+'0';
	MOV	#lo_addr(_d_mseg), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+9), W0
	ADD.B	W2, W1, [W0]
;laboratorio2.c,58 :: 		HORA[10]=u_mseg+'0';
	MOV	#lo_addr(_u_mseg), W0
	MOV.B	[W0], W2
	MOV.B	#48, W1
	MOV	#lo_addr(_hora+10), W0
	ADD.B	W2, W1, [W0]
;laboratorio2.c,59 :: 		HORA[11]='\0';
	MOV	#lo_addr(_hora+11), W1
	CLR	W0
	MOV.B	W0, [W1]
;laboratorio2.c,60 :: 		cron_write();
	CALL	_cron_write
;laboratorio2.c,61 :: 		IFS0bits.T1IF=0;
	BCLR	IFS0bits, #3
;laboratorio2.c,62 :: 		}
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

_captura_onda_ic1:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;laboratorio2.c,63 :: 		void captura_onda_ic1() org 0x16{
;laboratorio2.c,64 :: 		pulso++;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV	#1, W1
	MOV	#lo_addr(_pulso), W0
	ADD	W1, [W0], [W0]
;laboratorio2.c,65 :: 		inttostr(pulso,txt);
	MOV	#lo_addr(_txt), W11
	MOV	_pulso, W10
	CALL	_IntToStr
;laboratorio2.c,66 :: 		glcd_write_text(txt,0,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	CLR	W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,67 :: 		IFS0bits.IC1IF=0;
	BCLR	IFS0bits, #1
;laboratorio2.c,69 :: 		}
L_end_captura_onda_ic1:
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
; end of _captura_onda_ic1

_captura_onda_ic3:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;laboratorio2.c,72 :: 		void captura_onda_ic3() org 0x5E{
;laboratorio2.c,73 :: 		pulso2++;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV	#1, W1
	MOV	#lo_addr(_pulso2), W0
	ADD	W1, [W0], [W0]
;laboratorio2.c,74 :: 		inttostr(pulso2,txt);
	MOV	#lo_addr(_txt), W11
	MOV	_pulso2, W10
	CALL	_IntToStr
;laboratorio2.c,75 :: 		glcd_write_text(txt,10,5,1);
	MOV.B	#1, W13
	MOV.B	#5, W12
	MOV.B	#10, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,76 :: 		Glcd_Write_Text("c3",60,5,1);
	MOV.B	#1, W13
	MOV.B	#5, W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr34_laboratorio2), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,77 :: 		IFS2bits.IC3IF=0;
	BCLR	IFS2bits, #5
;laboratorio2.c,79 :: 		}
L_end_captura_onda_ic3:
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
; end of _captura_onda_ic3

_captura_onda_ic5:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;laboratorio2.c,80 :: 		void captura_onda_ic5() org 0x62{
;laboratorio2.c,81 :: 		pulso3++;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV	#1, W1
	MOV	#lo_addr(_pulso3), W0
	ADD	W1, [W0], [W0]
;laboratorio2.c,82 :: 		inttostr(pulso3,txt);
	MOV	#lo_addr(_txt), W11
	MOV	_pulso3, W10
	CALL	_IntToStr
;laboratorio2.c,83 :: 		glcd_write_text(txt,20,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#20, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,84 :: 		Glcd_Write_Text("c5",65,4,1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	MOV.B	#65, W11
	MOV	#lo_addr(?lstr35_laboratorio2), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,85 :: 		IFS2bits.IC5IF=0;
	BCLR	IFS2bits, #7
;laboratorio2.c,87 :: 		}
L_end_captura_onda_ic5:
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
; end of _captura_onda_ic5

_captura_onda_ic11:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;laboratorio2.c,88 :: 		void captura_onda_ic11() org 0x112{
;laboratorio2.c,89 :: 		pulso4++;
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV	#1, W1
	MOV	#lo_addr(_pulso4), W0
	ADD	W1, [W0], [W0]
;laboratorio2.c,90 :: 		inttostr(pulso4,txt);
	MOV	#lo_addr(_txt), W11
	MOV	_pulso4, W10
	CALL	_IntToStr
;laboratorio2.c,91 :: 		glcd_write_text(txt,40,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#40, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,93 :: 		IFS7bits.IC11IF=0;
	BCLR	IFS7bits, #15
;laboratorio2.c,95 :: 		}
L_end_captura_onda_ic11:
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
; end of _captura_onda_ic11

_int_timer2:
	LNK	#4
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;laboratorio2.c,103 :: 		void int_timer2 () org 0x22{
;laboratorio2.c,104 :: 		IC1CON1bits.ICM=0;
	MOV	#lo_addr(IC1CON1bits), W0
	MOV.B	[W0], W1
	MOV.B	#248, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IC1CON1bits), W0
	MOV.B	W1, [W0]
;laboratorio2.c,105 :: 		IC3CON1bits.ICM=0;
	MOV	#lo_addr(IC3CON1bits), W0
	MOV.B	[W0], W1
	MOV.B	#248, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IC3CON1bits), W0
	MOV.B	W1, [W0]
;laboratorio2.c,106 :: 		IC5CON1bits.ICM=0;
	MOV	#lo_addr(IC5CON1bits), W0
	MOV.B	[W0], W1
	MOV.B	#248, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IC5CON1bits), W0
	MOV.B	W1, [W0]
;laboratorio2.c,107 :: 		IC11CON1bits.ICM=0;
	MOV	#lo_addr(IC11CON1bits), W0
	MOV.B	[W0], W1
	MOV.B	#248, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(IC11CON1bits), W0
	MOV.B	W1, [W0]
;laboratorio2.c,108 :: 		T2CONbits.TON=1;
	BSET	T2CONbits, #15
;laboratorio2.c,109 :: 		IFS0bits.T2IF=0; // limpia bandera de interrupcion
	BCLR	IFS0bits, #7
;laboratorio2.c,110 :: 		frecuencia=pulso*4*2;
	MOV	_pulso, W0
	SL	W0, #2, W0
	SL	W0, #1, W0
	ASR	W0, #15, W1
	SETM	W2
	CALL	__Long2Float
	MOV	W0, [W14+0]
	MOV	W1, [W14+2]
	MOV	W0, _frecuencia
	MOV	W1, _frecuencia+2
;laboratorio2.c,111 :: 		frecuencia2=pulso2*4*2;
	MOV	_pulso2, W0
	SL	W0, #2, W0
	SL	W0, #1, W0
	ASR	W0, #15, W1
	SETM	W2
	CALL	__Long2Float
	MOV	W0, _frecuencia2
	MOV	W1, _frecuencia2+2
;laboratorio2.c,112 :: 		frecuencia3=pulso3*4*2;
	MOV	_pulso3, W0
	SL	W0, #2, W0
	SL	W0, #1, W0
	ASR	W0, #15, W1
	SETM	W2
	CALL	__Long2Float
	MOV	W0, _frecuencia3
	MOV	W1, _frecuencia3+2
;laboratorio2.c,113 :: 		frecuencia4=pulso4*4*2;
	MOV	_pulso4, W0
	SL	W0, #2, W0
	SL	W0, #1, W0
	ASR	W0, #15, W1
	SETM	W2
	CALL	__Long2Float
	MOV	W0, _frecuencia4
	MOV	W1, _frecuencia4+2
;laboratorio2.c,114 :: 		T1=(1/frecuencia)*1000000;
	MOV	[W14+0], W2
	MOV	[W14+2], W3
	MOV	#0, W0
	MOV	#16256, W1
	CALL	__Div_FP
	MOV	#9216, W2
	MOV	#18804, W3
	CALL	__Mul_FP
	MOV	W0, _T1
	MOV	W1, _T1+2
;laboratorio2.c,115 :: 		T2=(1/frecuencia2)*1000000;
	MOV	_frecuencia2, W2
	MOV	_frecuencia2+2, W3
	MOV	#0, W0
	MOV	#16256, W1
	CALL	__Div_FP
	MOV	#9216, W2
	MOV	#18804, W3
	CALL	__Mul_FP
	MOV	W0, _T2
	MOV	W1, _T2+2
;laboratorio2.c,116 :: 		T3=(1/frecuencia3)*1000000;
	MOV	_frecuencia3, W2
	MOV	_frecuencia3+2, W3
	MOV	#0, W0
	MOV	#16256, W1
	CALL	__Div_FP
	MOV	#9216, W2
	MOV	#18804, W3
	CALL	__Mul_FP
	MOV	W0, _T3
	MOV	W1, _T3+2
;laboratorio2.c,117 :: 		T4=(1/frecuencia4)*1000000;
	MOV	_frecuencia4, W2
	MOV	_frecuencia4+2, W3
	MOV	#0, W0
	MOV	#16256, W1
	CALL	__Div_FP
	MOV	#9216, W2
	MOV	#18804, W3
	CALL	__Mul_FP
	MOV	W0, _T4
	MOV	W1, _T4+2
;laboratorio2.c,118 :: 		}
L_end_int_timer2:
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	50
	POP	DSWPAG
	ULNK
	RETFIE
; end of _int_timer2

_Timer4:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;laboratorio2.c,119 :: 		void Timer4() org 0x4A{
;laboratorio2.c,120 :: 		IFS1bits.T4IF=0;
	BCLR	IFS1bits, #11
;laboratorio2.c,121 :: 		}
L_end_Timer4:
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	50
	POP	DSWPAG
	RETFIE
; end of _Timer4

_Timer5:
	PUSH	DSWPAG
	PUSH	50
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;laboratorio2.c,122 :: 		void Timer5() org 0x4C{
;laboratorio2.c,123 :: 		IFS1bits.T5IF=0;
	BCLR	IFS1bits, #12
;laboratorio2.c,124 :: 		}
L_end_Timer5:
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	50
	POP	DSWPAG
	RETFIE
; end of _Timer5

_arreglo_hora_militar_up:

;laboratorio2.c,130 :: 		unsigned short arreglo_hora_militar_up(int i,unsigned int valor_nuevo){
;laboratorio2.c,131 :: 		if(i==decena_hora){
	CP	W10, #0
	BRA Z	L__arreglo_hora_militar_up247
	GOTO	L_arreglo_hora_militar_up82
L__arreglo_hora_militar_up247:
;laboratorio2.c,132 :: 		if(valor_nuevo==4){//Decena de hora solo puede ser 0,1 o 2 2->0
	CP	W11, #4
	BRA Z	L__arreglo_hora_militar_up248
	GOTO	L_arreglo_hora_militar_up83
L__arreglo_hora_militar_up248:
;laboratorio2.c,133 :: 		return 0;
	CLR	W0
	GOTO	L_end_arreglo_hora_militar_up
;laboratorio2.c,134 :: 		}
L_arreglo_hora_militar_up83:
;laboratorio2.c,135 :: 		}
L_arreglo_hora_militar_up82:
;laboratorio2.c,136 :: 		if(i==unidad_hora){
	CP	W10, #1
	BRA Z	L__arreglo_hora_militar_up249
	GOTO	L_arreglo_hora_militar_up84
L__arreglo_hora_militar_up249:
;laboratorio2.c,137 :: 		if(HORA[decena_hora]==2&&valor_nuevo>3){//Arreglo Hora 23->00
	MOV	#lo_addr(_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #2
	BRA Z	L__arreglo_hora_militar_up250
	GOTO	L__arreglo_hora_militar_up167
L__arreglo_hora_militar_up250:
	CP	W11, #3
	BRA GTU	L__arreglo_hora_militar_up251
	GOTO	L__arreglo_hora_militar_up166
L__arreglo_hora_militar_up251:
L__arreglo_hora_militar_up165:
;laboratorio2.c,138 :: 		HORA[decena_hora]=0;
	MOV	#lo_addr(_hora), W1
	CLR	W0
	MOV.B	W0, [W1]
;laboratorio2.c,139 :: 		return 0;
	CLR	W0
	GOTO	L_end_arreglo_hora_militar_up
;laboratorio2.c,137 :: 		if(HORA[decena_hora]==2&&valor_nuevo>3){//Arreglo Hora 23->00
L__arreglo_hora_militar_up167:
L__arreglo_hora_militar_up166:
;laboratorio2.c,141 :: 		if(valor_nuevo>=9){return 0;}//Arreglo Unidad Hora && Unidad Minuto 9->0
	CP	W11, #9
	BRA GEU	L__arreglo_hora_militar_up252
	GOTO	L_arreglo_hora_militar_up88
L__arreglo_hora_militar_up252:
	CLR	W0
	GOTO	L_end_arreglo_hora_militar_up
L_arreglo_hora_militar_up88:
;laboratorio2.c,142 :: 		}
L_arreglo_hora_militar_up84:
;laboratorio2.c,143 :: 		if(i==decena_minuto){
	CP	W10, #3
	BRA Z	L__arreglo_hora_militar_up253
	GOTO	L_arreglo_hora_militar_up89
L__arreglo_hora_militar_up253:
;laboratorio2.c,144 :: 		if(valor_nuevo>5){//Decena minuto llega hasta 5->0
	CP	W11, #5
	BRA GTU	L__arreglo_hora_militar_up254
	GOTO	L_arreglo_hora_militar_up90
L__arreglo_hora_militar_up254:
;laboratorio2.c,145 :: 		return 0;
	CLR	W0
	GOTO	L_end_arreglo_hora_militar_up
;laboratorio2.c,146 :: 		}
L_arreglo_hora_militar_up90:
;laboratorio2.c,147 :: 		}
L_arreglo_hora_militar_up89:
;laboratorio2.c,148 :: 		if(i==unidad_minuto){
	CP	W10, #4
	BRA Z	L__arreglo_hora_militar_up255
	GOTO	L_arreglo_hora_militar_up91
L__arreglo_hora_militar_up255:
;laboratorio2.c,149 :: 		if(valor_nuevo>9){return 0;}//Arreglo Unidad Hora && Unidad Minuto 9->0
	CP	W11, #9
	BRA GTU	L__arreglo_hora_militar_up256
	GOTO	L_arreglo_hora_militar_up92
L__arreglo_hora_militar_up256:
	CLR	W0
	GOTO	L_end_arreglo_hora_militar_up
L_arreglo_hora_militar_up92:
;laboratorio2.c,150 :: 		}
L_arreglo_hora_militar_up91:
;laboratorio2.c,151 :: 		}
L_end_arreglo_hora_militar_up:
	RETURN
; end of _arreglo_hora_militar_up

_arreglo_hora_militar_dw:

;laboratorio2.c,152 :: 		unsigned short arreglo_hora_militar_dw(int i,unsigned int valor_nuevo){
;laboratorio2.c,153 :: 		if(i==decena_hora){
	CP	W10, #0
	BRA Z	L__arreglo_hora_militar_dw258
	GOTO	L_arreglo_hora_militar_dw93
L__arreglo_hora_militar_dw258:
;laboratorio2.c,154 :: 		if(valor_nuevo==-1){//Decena de hora solo puede ser 0,1 o 2 2->0;
	MOV	#65535, W0
	CP	W11, W0
	BRA Z	L__arreglo_hora_militar_dw259
	GOTO	L_arreglo_hora_militar_dw94
L__arreglo_hora_militar_dw259:
;laboratorio2.c,155 :: 		return 2;
	MOV.B	#2, W0
	GOTO	L_end_arreglo_hora_militar_dw
;laboratorio2.c,156 :: 		}
L_arreglo_hora_militar_dw94:
;laboratorio2.c,157 :: 		}
L_arreglo_hora_militar_dw93:
;laboratorio2.c,158 :: 		if(i==unidad_hora){
	CP	W10, #1
	BRA Z	L__arreglo_hora_militar_dw260
	GOTO	L_arreglo_hora_militar_dw95
L__arreglo_hora_militar_dw260:
;laboratorio2.c,159 :: 		if(HORA[decena_hora]==0&&valor_nuevo<0){//Arreglo Hora 23->00
	MOV	#lo_addr(_hora), W0
	MOV.B	[W0], W0
	CP.B	W0, #0
	BRA Z	L__arreglo_hora_militar_dw261
	GOTO	L__arreglo_hora_militar_dw170
L__arreglo_hora_militar_dw261:
	CP	W11, #0
	BRA LTU	L__arreglo_hora_militar_dw262
	GOTO	L__arreglo_hora_militar_dw169
L__arreglo_hora_militar_dw262:
L__arreglo_hora_militar_dw168:
;laboratorio2.c,160 :: 		HORA[decena_hora]=2;
	MOV	#lo_addr(_hora), W1
	MOV.B	#2, W0
	MOV.B	W0, [W1]
;laboratorio2.c,161 :: 		return 3;
	MOV.B	#3, W0
	GOTO	L_end_arreglo_hora_militar_dw
;laboratorio2.c,159 :: 		if(HORA[decena_hora]==0&&valor_nuevo<0){//Arreglo Hora 23->00
L__arreglo_hora_militar_dw170:
L__arreglo_hora_militar_dw169:
;laboratorio2.c,162 :: 		}else if(valor_nuevo<0){return 9;}//Arreglo Unidad Hora && Unidad Minuto 9->0
	CP	W11, #0
	BRA LTU	L__arreglo_hora_militar_dw263
	GOTO	L_arreglo_hora_militar_dw100
L__arreglo_hora_militar_dw263:
	MOV.B	#9, W0
	GOTO	L_end_arreglo_hora_militar_dw
L_arreglo_hora_militar_dw100:
;laboratorio2.c,163 :: 		}
L_arreglo_hora_militar_dw95:
;laboratorio2.c,164 :: 		if(i==decena_minuto){
	CP	W10, #3
	BRA Z	L__arreglo_hora_militar_dw264
	GOTO	L_arreglo_hora_militar_dw101
L__arreglo_hora_militar_dw264:
;laboratorio2.c,165 :: 		if(valor_nuevo<0){//Decena minuto llega hasta 5
	CP	W11, #0
	BRA LTU	L__arreglo_hora_militar_dw265
	GOTO	L_arreglo_hora_militar_dw102
L__arreglo_hora_militar_dw265:
;laboratorio2.c,166 :: 		return 5;
	MOV.B	#5, W0
	GOTO	L_end_arreglo_hora_militar_dw
;laboratorio2.c,167 :: 		}
L_arreglo_hora_militar_dw102:
;laboratorio2.c,168 :: 		}
L_arreglo_hora_militar_dw101:
;laboratorio2.c,169 :: 		if(i==unidad_minuto){
	CP	W10, #4
	BRA Z	L__arreglo_hora_militar_dw266
	GOTO	L_arreglo_hora_militar_dw103
L__arreglo_hora_militar_dw266:
;laboratorio2.c,170 :: 		if(valor_nuevo<0){return 9;}//Arreglo Unidad Hora && Unidad Minuto 9->0
	CP	W11, #0
	BRA LTU	L__arreglo_hora_militar_dw267
	GOTO	L_arreglo_hora_militar_dw104
L__arreglo_hora_militar_dw267:
	MOV.B	#9, W0
	GOTO	L_end_arreglo_hora_militar_dw
L_arreglo_hora_militar_dw104:
;laboratorio2.c,171 :: 		}
L_arreglo_hora_militar_dw103:
;laboratorio2.c,172 :: 		}
L_end_arreglo_hora_militar_dw:
	RETURN
; end of _arreglo_hora_militar_dw

_cron_write:

;laboratorio2.c,174 :: 		void cron_write(){
;laboratorio2.c,175 :: 		Glcd_Write_TEXT("                                              ",60,7,1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#60, W11
	MOV	#lo_addr(?lstr36_laboratorio2), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,176 :: 		i=0;
	CLR	W0
	MOV	W0, _i
;laboratorio2.c,177 :: 		for(i=0;i<12;i++){
	CLR	W0
	MOV	W0, _i
L_cron_write105:
	MOV	_i, W0
	CP	W0, #12
	BRA LT	L__cron_write269
	GOTO	L_cron_write106
L__cron_write269:
;laboratorio2.c,178 :: 		Glcd_Write_Char(HORA[i],50+i*5,7,1);
	MOV	_i, W1
	MOV	#5, W0
	MUL.UU	W1, W0, W2
	MOV	#50, W0
	ADD	W0, W2, W4
	MOV	#lo_addr(_hora), W1
	MOV	#lo_addr(_i), W0
	ADD	W1, [W0], W0
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	W4, W11
	MOV.B	[W0], W10
	CALL	_Glcd_Write_Char
;laboratorio2.c,177 :: 		for(i=0;i<12;i++){
	MOV	#1, W1
	MOV	#lo_addr(_i), W0
	ADD	W1, [W0], [W0]
;laboratorio2.c,179 :: 		}
	GOTO	L_cron_write105
L_cron_write106:
;laboratorio2.c,180 :: 		}
L_end_cron_write:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _cron_write

_num_update:

;laboratorio2.c,181 :: 		void num_update(int it,int x_pos,int page){
;laboratorio2.c,182 :: 		Glcd_Write_Char(it+'0',x_pos,page,1);
	PUSH	W10
	PUSH	W13
	MOV	#48, W0
	ADD	W10, W0, W0
	MOV.B	#1, W13
	MOV.B	W0, W10
	CALL	_Glcd_Write_Char
;laboratorio2.c,183 :: 		}
L_end_num_update:
	POP	W13
	POP	W10
	RETURN
; end of _num_update

_num_selector:
	LNK	#2

;laboratorio2.c,185 :: 		int  num_selector(int x_pos,int indice){
;laboratorio2.c,186 :: 		int it=0;
	PUSH	W12
	MOV	#0, W0
	MOV	W0, [W14+0]
;laboratorio2.c,187 :: 		num_update(it,x_pos,7);
	PUSH.D	W10
	MOV	#7, W12
	MOV	W10, W11
	MOV	[W14+0], W10
	CALL	_num_update
	POP.D	W10
;laboratorio2.c,188 :: 		clean_PS2();
	CALL	_clean_PS2
;laboratorio2.c,189 :: 		while(keydata!=ENTER){
L_num_selector108:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W0
	CP.B	W0, #13
	BRA NZ	L__num_selector272
	GOTO	L_num_selector109
L__num_selector272:
;laboratorio2.c,190 :: 		if(Ps2_Key_Read(&keydata, &special, &down)){
	PUSH.D	W10
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
	POP.D	W10
	CP0	W0
	BRA NZ	L__num_selector273
	GOTO	L_num_selector110
L__num_selector273:
;laboratorio2.c,191 :: 		if(down){
	MOV	#lo_addr(_down), W0
	CP0.B	[W0]
	BRA NZ	L__num_selector274
	GOTO	L_num_selector111
L__num_selector274:
;laboratorio2.c,192 :: 		if(keydata==DOWN_ARROW||keydata==UP_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#108, W0
	CP.B	W1, W0
	BRA NZ	L__num_selector275
	GOTO	L__num_selector173
L__num_selector275:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#111, W0
	CP.B	W1, W0
	BRA NZ	L__num_selector276
	GOTO	L__num_selector172
L__num_selector276:
	GOTO	L_num_selector114
L__num_selector173:
L__num_selector172:
;laboratorio2.c,193 :: 		if(keydata==UP_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#111, W0
	CP.B	W1, W0
	BRA Z	L__num_selector277
	GOTO	L_num_selector115
L__num_selector277:
;laboratorio2.c,194 :: 		it=it+1;
	MOV	[W14+0], W0
	INC	W0
;laboratorio2.c,195 :: 		it=arreglo_hora_militar_up(indice,it);
	PUSH.D	W10
	MOV	W11, W10
	MOV	W0, W11
	CALL	_arreglo_hora_militar_up
	POP.D	W10
	ZE	W0, W0
	MOV	W0, [W14+0]
;laboratorio2.c,196 :: 		clean_PS2();
	CALL	_clean_PS2
;laboratorio2.c,197 :: 		}
L_num_selector115:
;laboratorio2.c,198 :: 		if(keydata==DOWN_ARROW){
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#108, W0
	CP.B	W1, W0
	BRA Z	L__num_selector278
	GOTO	L_num_selector116
L__num_selector278:
;laboratorio2.c,199 :: 		it=it-1;
	MOV	[W14+0], W0
	DEC	W0
;laboratorio2.c,200 :: 		it=arreglo_hora_militar_dw(indice,it);
	PUSH.D	W10
	MOV	W11, W10
	MOV	W0, W11
	CALL	_arreglo_hora_militar_dw
	POP.D	W10
	ZE	W0, W0
	MOV	W0, [W14+0]
;laboratorio2.c,201 :: 		clean_PS2();
	CALL	_clean_PS2
;laboratorio2.c,202 :: 		}
L_num_selector116:
;laboratorio2.c,203 :: 		num_update(it,x_pos,7);
	PUSH.D	W10
	MOV	#7, W12
	MOV	W10, W11
	MOV	[W14+0], W10
	CALL	_num_update
	POP.D	W10
;laboratorio2.c,204 :: 		clean_PS2();
	CALL	_clean_PS2
;laboratorio2.c,205 :: 		}
L_num_selector114:
;laboratorio2.c,206 :: 		clean_PS2();
	CALL	_clean_PS2
;laboratorio2.c,207 :: 		}
L_num_selector111:
;laboratorio2.c,208 :: 		}
L_num_selector110:
;laboratorio2.c,209 :: 		}
	GOTO	L_num_selector108
L_num_selector109:
;laboratorio2.c,210 :: 		return it;
	MOV	[W14+0], W0
;laboratorio2.c,211 :: 		}
;laboratorio2.c,210 :: 		return it;
;laboratorio2.c,211 :: 		}
L_end_num_selector:
	POP	W12
	ULNK
	RETURN
; end of _num_selector

_cron_cursor:

;laboratorio2.c,212 :: 		void cron_cursor(){
;laboratorio2.c,213 :: 		int x_pos=50,i,j;
	PUSH	W10
	PUSH	W11
;laboratorio2.c,215 :: 		clean_PS2();
	CALL	_clean_PS2
;laboratorio2.c,216 :: 		for(i=0;i<5;i++){
; i start address is: 24 (W12)
	CLR	W12
; i end address is: 24 (W12)
L_cron_cursor117:
; i start address is: 24 (W12)
	CP	W12, #5
	BRA LT	L__cron_cursor280
	GOTO	L_cron_cursor118
L__cron_cursor280:
;laboratorio2.c,217 :: 		if(i!=2){
	CP	W12, #2
	BRA NZ	L__cron_cursor281
	GOTO	L_cron_cursor120
L__cron_cursor281:
;laboratorio2.c,218 :: 		j=num_selector(50+i*5,i)+'0';
	MOV	#5, W0
	MUL.SS	W12, W0, W2
	MOV	#50, W0
	ADD	W0, W2, W0
	MOV	W12, W11
	MOV	W0, W10
	CALL	_num_selector
	MOV	#48, W1
	ADD	W0, W1, W1
;laboratorio2.c,219 :: 		HORA[i]=j;
	MOV	#lo_addr(_hora), W0
	ADD	W0, W12, W0
	MOV.B	W1, [W0]
;laboratorio2.c,220 :: 		}else if(i==2){
	GOTO	L_cron_cursor121
L_cron_cursor120:
	CP	W12, #2
	BRA Z	L__cron_cursor282
	GOTO	L_cron_cursor122
L__cron_cursor282:
;laboratorio2.c,221 :: 		HORA[2]=':' ;
	MOV	#lo_addr(_hora+2), W1
	MOV.B	#58, W0
	MOV.B	W0, [W1]
;laboratorio2.c,222 :: 		}
L_cron_cursor122:
L_cron_cursor121:
;laboratorio2.c,223 :: 		clean_PS2();
	CALL	_clean_PS2
;laboratorio2.c,224 :: 		cron_write();
	CALL	_cron_write
;laboratorio2.c,216 :: 		for(i=0;i<5;i++){
	INC	W12
;laboratorio2.c,225 :: 		}
; i end address is: 24 (W12)
	GOTO	L_cron_cursor117
L_cron_cursor118:
;laboratorio2.c,226 :: 		}
L_end_cron_cursor:
	POP	W11
	POP	W10
	RETURN
; end of _cron_cursor

_caso_1:

;laboratorio2.c,227 :: 		void caso_1(){
;laboratorio2.c,228 :: 		while(keydata!=ESC){
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
L_caso_1123:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#118, W0
	CP.B	W1, W0
	BRA NZ	L__caso_1284
	GOTO	L_caso_1124
L__caso_1284:
;laboratorio2.c,229 :: 		selected=cursor_menu(5);
	MOV	#5, W10
	CALL	_cursor_menu
	MOV	W0, _selected
;laboratorio2.c,230 :: 		switch(selected){
	GOTO	L_caso_1125
;laboratorio2.c,231 :: 		case 1:
L_caso_1127:
;laboratorio2.c,232 :: 		cron_cursor();
	CALL	_cron_cursor
;laboratorio2.c,233 :: 		clean_PS2();
	CALL	_clean_PS2
;laboratorio2.c,234 :: 		break;
	GOTO	L_caso_1126
;laboratorio2.c,235 :: 		case 2:
L_caso_1128:
;laboratorio2.c,236 :: 		Glcd_Write_Text("PLAY",30,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#30, W11
	MOV	#lo_addr(?lstr37_laboratorio2), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,237 :: 		T1CONBits.TON=1;
	BSET	T1CONbits, #15
;laboratorio2.c,238 :: 		break;
	GOTO	L_caso_1126
;laboratorio2.c,239 :: 		case 3:
L_caso_1129:
;laboratorio2.c,240 :: 		Glcd_Write_Text("pause",30,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#30, W11
	MOV	#lo_addr(?lstr38_laboratorio2), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,241 :: 		T1CONBits.TON=0;
	BCLR	T1CONbits, #15
;laboratorio2.c,242 :: 		break;
	GOTO	L_caso_1126
;laboratorio2.c,243 :: 		case 4:
L_caso_1130:
;laboratorio2.c,244 :: 		Glcd_Write_Text("RESET",30,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#30, W11
	MOV	#lo_addr(?lstr39_laboratorio2), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,246 :: 		break;
	GOTO	L_caso_1126
;laboratorio2.c,247 :: 		case 5:
L_caso_1131:
;laboratorio2.c,248 :: 		Glcd_Write_Text("ALARM",30,7,1);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#30, W11
	MOV	#lo_addr(?lstr40_laboratorio2), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,250 :: 		break;
	GOTO	L_caso_1126
;laboratorio2.c,251 :: 		}
L_caso_1125:
	MOV	_selected, W0
	CP	W0, #1
	BRA NZ	L__caso_1285
	GOTO	L_caso_1127
L__caso_1285:
	MOV	_selected, W0
	CP	W0, #2
	BRA NZ	L__caso_1286
	GOTO	L_caso_1128
L__caso_1286:
	MOV	_selected, W0
	CP	W0, #3
	BRA NZ	L__caso_1287
	GOTO	L_caso_1129
L__caso_1287:
	MOV	_selected, W0
	CP	W0, #4
	BRA NZ	L__caso_1288
	GOTO	L_caso_1130
L__caso_1288:
	MOV	_selected, W0
	CP	W0, #5
	BRA NZ	L__caso_1289
	GOTO	L_caso_1131
L__caso_1289:
L_caso_1126:
;laboratorio2.c,252 :: 		}
	GOTO	L_caso_1123
L_caso_1124:
;laboratorio2.c,253 :: 		}
L_end_caso_1:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _caso_1

_frecuencia_pantalla:

;laboratorio2.c,255 :: 		void frecuencia_pantalla (){
;laboratorio2.c,256 :: 		Glcd_Write_Text("Frecu.(hz)", 0, 1, 1);
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	MOV.B	#1, W13
	MOV.B	#1, W12
	CLR	W11
	MOV	#lo_addr(?lstr41_laboratorio2), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,257 :: 		Glcd_Write_Text("Periodo(us)", 65, 1, 1);
	MOV.B	#1, W13
	MOV.B	#1, W12
	MOV.B	#65, W11
	MOV	#lo_addr(?lstr42_laboratorio2), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,258 :: 		floattostr(frecuencia,txt);
	MOV	#lo_addr(_txt), W12
	MOV	_frecuencia, W10
	MOV	_frecuencia+2, W11
	CALL	_FloatToStr
;laboratorio2.c,259 :: 		Glcd_Write_Text(txt,5, 2, 1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	MOV.B	#5, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,260 :: 		floattostr(frecuencia2,txt);
	MOV	#lo_addr(_txt), W12
	MOV	_frecuencia2, W10
	MOV	_frecuencia2+2, W11
	CALL	_FloatToStr
;laboratorio2.c,261 :: 		Glcd_Write_Text(txt,5, 3, 1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	MOV.B	#5, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,262 :: 		floattostr(frecuencia3,txt);
	MOV	#lo_addr(_txt), W12
	MOV	_frecuencia3, W10
	MOV	_frecuencia3+2, W11
	CALL	_FloatToStr
;laboratorio2.c,263 :: 		Glcd_Write_Text(txt,5, 4, 1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	MOV.B	#5, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,264 :: 		floattostr(frecuencia4,txt);
	MOV	#lo_addr(_txt), W12
	MOV	_frecuencia4, W10
	MOV	_frecuencia4+2, W11
	CALL	_FloatToStr
;laboratorio2.c,265 :: 		Glcd_Write_Text(txt,5, 5, 1);
	MOV.B	#1, W13
	MOV.B	#5, W12
	MOV.B	#5, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,266 :: 		floattostr(T1,txt);
	MOV	#lo_addr(_txt), W12
	MOV	_T1, W10
	MOV	_T1+2, W11
	CALL	_FloatToStr
;laboratorio2.c,267 :: 		Glcd_Write_Text(txt,65, 2, 1);
	MOV.B	#1, W13
	MOV.B	#2, W12
	MOV.B	#65, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,268 :: 		floattostr(T2,txt);
	MOV	#lo_addr(_txt), W12
	MOV	_T2, W10
	MOV	_T2+2, W11
	CALL	_FloatToStr
;laboratorio2.c,269 :: 		Glcd_Write_Text(txt,65, 3, 1);
	MOV.B	#1, W13
	MOV.B	#3, W12
	MOV.B	#65, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,270 :: 		floattostr(T3,txt);
	MOV	#lo_addr(_txt), W12
	MOV	_T3, W10
	MOV	_T3+2, W11
	CALL	_FloatToStr
;laboratorio2.c,271 :: 		Glcd_Write_Text(txt,65, 4, 1);
	MOV.B	#1, W13
	MOV.B	#4, W12
	MOV.B	#65, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,272 :: 		floattostr(T4,txt);
	MOV	#lo_addr(_txt), W12
	MOV	_T4, W10
	MOV	_T4+2, W11
	CALL	_FloatToStr
;laboratorio2.c,273 :: 		Glcd_Write_Text(txt,65, 5, 1);
	MOV.B	#1, W13
	MOV.B	#5, W12
	MOV.B	#65, W11
	MOV	#lo_addr(_txt), W10
	CALL	_Glcd_Write_Text
;laboratorio2.c,274 :: 		}
L_end_frecuencia_pantalla:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _frecuencia_pantalla

_caso_2:

;laboratorio2.c,275 :: 		void caso_2(){
;laboratorio2.c,276 :: 		config_captura();
	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	CALL	_config_captura
;laboratorio2.c,277 :: 		T2CONbits.TON=1; //enciende timer 1
	BSET	T2CONbits, #15
;laboratorio2.c,278 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;laboratorio2.c,279 :: 		while(keydata!=ESC){
L_caso_2132:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#118, W0
	CP.B	W1, W0
	BRA NZ	L__caso_2292
	GOTO	L_caso_2133
L__caso_2292:
;laboratorio2.c,280 :: 		frecuencia_pantalla();
	CALL	_frecuencia_pantalla
;laboratorio2.c,281 :: 		Glcd_Write_TEXT("c2" ,10,7,1);delay_ms(1000);
	MOV.B	#1, W13
	MOV.B	#7, W12
	MOV.B	#10, W11
	MOV	#lo_addr(?lstr43_laboratorio2), W10
	CALL	_Glcd_Write_Text
	MOV	#16, W8
	MOV	#16968, W7
L_caso_2134:
	DEC	W7
	BRA NZ	L_caso_2134
	DEC	W8
	BRA NZ	L_caso_2134
	NOP
	NOP
	NOP
	NOP
;laboratorio2.c,286 :: 		Ps2_Key_Read(&keydata, &special, &down);
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
;laboratorio2.c,287 :: 		}
	GOTO	L_caso_2132
L_caso_2133:
;laboratorio2.c,288 :: 		}
L_end_caso_2:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _caso_2

_caso_3:

;laboratorio2.c,290 :: 		void caso_3(){
;laboratorio2.c,291 :: 		texto_caso_3();
	PUSH	W10
	PUSH	W11
	PUSH	W12
	CALL	_texto_caso_3
;laboratorio2.c,292 :: 		T5CONbits.TON=1;
	BSET	T5CONbits, #15
;laboratorio2.c,293 :: 		T4CONbits.TON=1;
	BSET	T4CONbits, #15
;laboratorio2.c,294 :: 		delay_ms(300);
	MOV	#5, W8
	MOV	#37858, W7
L_caso_3136:
	DEC	W7
	BRA NZ	L_caso_3136
	DEC	W8
	BRA NZ	L_caso_3136
	NOP
;laboratorio2.c,295 :: 		while(keydata!=ESC){
L_caso_3138:
	MOV	#lo_addr(_keydata), W0
	MOV.B	[W0], W1
	MOV.B	#118, W0
	CP.B	W1, W0
	BRA NZ	L__caso_3294
	GOTO	L_caso_3139
L__caso_3294:
;laboratorio2.c,296 :: 		Ps2_Key_Read(&keydata, &special, &down);
	MOV	#lo_addr(_down), W12
	MOV	#lo_addr(_special), W11
	MOV	#lo_addr(_keydata), W10
	CALL	_Ps2_Key_Read
;laboratorio2.c,297 :: 		}
	GOTO	L_caso_3138
L_caso_3139:
;laboratorio2.c,298 :: 		T5CONbits.TON=0;
	BCLR	T5CONbits, #15
;laboratorio2.c,299 :: 		T4CONbits.TON=0;
	BCLR	T4CONbits, #15
;laboratorio2.c,300 :: 		}
L_end_caso_3:
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _caso_3

_main:
	MOV	#2048, W15
	MOV	#6142, W0
	MOV	WREG, 32
	MOV	#1, W0
	MOV	WREG, 50
	MOV	#4, W0
	IOR	68

;laboratorio2.c,302 :: 		void main(){
;laboratorio2.c,303 :: 		config_IO();  config_LCD();
	PUSH	W10
	CALL	_config_IO
	CALL	_config_LCD
;laboratorio2.c,304 :: 		config_INT();
	CALL	_config_INT
;laboratorio2.c,306 :: 		config_OC();
	CALL	_config_OC
;laboratorio2.c,307 :: 		config_TMR_45();
	CALL	_config_TMR_45
;laboratorio2.c,309 :: 		config_pin();
	CALL	_config_pin
;laboratorio2.c,312 :: 		Glcd_Fill(0);
	CLR	W10
	CALL	_Glcd_Fill
;laboratorio2.c,314 :: 		PS2_Config();  Glcd_Fill(0);
	CALL	_Ps2_Config
	CLR	W10
	CALL	_Glcd_Fill
;laboratorio2.c,315 :: 		while(1){
L_main140:
;laboratorio2.c,316 :: 		texto_menu();
	CALL	_texto_menu
;laboratorio2.c,317 :: 		selected=cursor_menu(3);
	MOV	#3, W10
	CALL	_cursor_menu
	MOV	W0, _selected
;laboratorio2.c,318 :: 		switch(selected){
	GOTO	L_main142
;laboratorio2.c,319 :: 		case 1:
L_main144:
;laboratorio2.c,320 :: 		clean_PS2();
	CALL	_clean_PS2
;laboratorio2.c,321 :: 		texto_caso_1();
	CALL	_texto_caso_1
;laboratorio2.c,322 :: 		caso_1();
	CALL	_caso_1
;laboratorio2.c,323 :: 		break;
	GOTO	L_main143
;laboratorio2.c,324 :: 		case 2:
L_main145:
;laboratorio2.c,325 :: 		clean_PS2();
	CALL	_clean_PS2
;laboratorio2.c,327 :: 		caso_2();
	CALL	_caso_2
;laboratorio2.c,328 :: 		break;
	GOTO	L_main143
;laboratorio2.c,329 :: 		case 3:
L_main146:
;laboratorio2.c,330 :: 		clean_PS2();
	CALL	_clean_PS2
;laboratorio2.c,331 :: 		texto_caso_3();
	CALL	_texto_caso_3
;laboratorio2.c,332 :: 		caso_3();
	CALL	_caso_3
;laboratorio2.c,333 :: 		break;
	GOTO	L_main143
;laboratorio2.c,334 :: 		}
L_main142:
	MOV	_selected, W0
	CP	W0, #1
	BRA NZ	L__main296
	GOTO	L_main144
L__main296:
	MOV	_selected, W0
	CP	W0, #2
	BRA NZ	L__main297
	GOTO	L_main145
L__main297:
	MOV	_selected, W0
	CP	W0, #3
	BRA NZ	L__main298
	GOTO	L_main146
L__main298:
L_main143:
;laboratorio2.c,335 :: 		}
	GOTO	L_main140
;laboratorio2.c,336 :: 		}
L_end_main:
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
