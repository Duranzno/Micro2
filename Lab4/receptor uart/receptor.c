char recibido []
void inter_rx () org 0x2A {
IFS0bits.U1RXIF=0;
recibido=U1UART_Read();

}

void main () {
//------------------------config pll----------------------
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
//-----------------------------------------------------------
        config_INT();
        config_LCD();
        U1UART_Init_Advanced(2400,2,1,1);
        config_uart_rx ();
        Glcd_Write_TEXT("Laboratorio 4",31,0,1);
        while(1){        
         if (recibido=="1") {
         Glcd_Write_TEXT("Caso 1",31,0,1);        
         }
         if (recibido=="2") {
         Glcd_Write_TEXT("Caso 2",31,0,1);        
         }
         if (recibido=="3") {
         Glcd_Write_TEXT("Caso 3",31,0,1);        
         }
                     
        }
}