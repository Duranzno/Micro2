void InitMCU(){
	ANSELC=0x0000; //Configuracion de E/S digitales
	ANSELD=0x0000; //Configuracion de E/S digitales
	ANSELE=0x0040; //RE6 como entrada analogica
	ANSELB=0x0000; //Configuracion de E/S digitales
	//CONFIGURACION DEL PLL PARA ALCANZAR UNA VELOCIDAD DE 30MHZ
	PLLFBD = 58; //M = 60
	CLKDIVbits.PLLPOST = 0; // N1 = 2
	CLKDIVbits.PLLPRE = 0; // N2 = 2
	OSCTUN = 0;
	OSCCON=0x0301;
while (OSCCONbits.COSC != 0x3);
	//CONFIGURACION DEL PLL AUXILIAR PARA EL USB
	//SE REQUIEREN 48MHZ
	ACLKCON3 = 0x24C0;
	ACLKDIV3 = 0x7;
	ACLKCON3bits.ENAPLL = 1;
	while(ACLKCON3bits.APLLCK != 1);
}