// Selecciona reloj interno FRC al producirse un POR
_FOSCSEL(FNOSC_FRC & IESO_OFF);
// Habilita por intercambio de reloj y configura modo POSC en XT
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);
int main()
{
// Configura PLL prescaler, PLL postscaler, PLL multiplicador
PLLFBD=46; // M=48
CLKDIVbits.PLLPOST=0; // N2=2
CLKDIVbits.PLLPRE=0; // N1=2
// Inicializa intercambio de reloj a oscilador primario con PLL (NOSC=011)
__builtin_write_OSCCONH(0x03);
__builtin_write_OSCCONL(OSCCON | 0x01);
// Espera que intercambio ocurra
while (OSCCONbits.COSC!= 0b011);
// Espera por desbloqueo del PLL
while (OSCCONbits.LOCK!= 1);