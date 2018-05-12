void config_uart_tx () {
U1MODEbits.STSEL = 0;// 1 Bit de parada
U1MODEbits.PDSEL = 0;// No hay paridad, 8 bits de datos
U1MODEbits.ABAUD = 0;// Auto-Bauddisabilitado
U1MODEbits.BRGH = 0;// Modo de velocidad standard
<<<<<<< HEAD
U1BRG = 12;// 9600 baudios
=======
U1BRG = 52;// 9600 baudios
>>>>>>> a3135530578779bb57902b1f133061a97fa515c2
U1STAbits.UTXISEL0 = 0;// Interrupción al transmitir un caracter
U1STAbits.UTXISEL1 = 0;
IEC0bits.U1TXIE = 1;// habilita interrupción por transmisión
U1MODEbits.UARTEN = 1;// Habilita UART
UARTU1STAbits.UTXEN = 1;// Habilita transmisor del UART
IEC0bits.U1RXIE=1;  // habilita interrupcion
IFS0bits.U1TXIF=0;  // borra bandera de int
IPC3bits.U1TXIP=5;  // nivel 5 de int
}



void config_uart_rx () {
U1MODEbits.STSEL = 0;// 1 bit de parada
U1MODEbits.PDSEL = 0;// No paridad, 8-bits de datos
U1MODEbits.ABAUD = 0;// Auto-Bauddesabilitado
U1MODEbits.BRGH = 0;// velocidad estándar
U1BRG = 12;// 9600 baudios
U1STAbits.URXISEL = 0;// Interrupción al recibir un carácter por RX ;
U1MODEbits.UARTEN = 1;// Habilita UART
IEC0bits.U1RXIE=1;  // habilita interrupcion
IFS0bits.U1RXIF=0;  // borra bandera de int
IPC2bits.U1RXIP=5;  // nivel 5 de int
}