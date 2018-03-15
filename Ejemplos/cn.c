void configure CN(void)
{
CNENBbits.CNIB3 = 1; // Habilita el pin RB3 para interrupción
IEC1bits.CNIE = 1; // Habilita Interrupción CN
IFS1bits.CNIF = 0; // Resetea interrupción CN
}
void __attribute__ ((__interrupt__)) _CNInterrupt(void)
{
// Código aqui
IFS1bits.CNIF = 0; // Borra bandera interrupción CN