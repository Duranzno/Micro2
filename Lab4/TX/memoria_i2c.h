unsigned valor=0,adres=0;
void escribir_24lc256(unsigned char valor,unsigned char adres)
{ I2C1_Start(); // emitir señal de inicio I2C
I2C1_Write(0xA0); // enviar byte a través de (dirección del dispositivo + W)
I2C1_Write(0x00); // direccion sin usar
I2C1_Write(adres); // enviar byte (dirección de ubicación EEPROM)
I2C1_Write(valor); // enviar datos (los datos se escriban)
I2C1_Stop();
Delay_ms(50);
} 
unsigned leer_24lc256(unsigned char adres)
{ unsigned char valor;
I2C1_Start(); // emitir señal de inicio I2C
I2C1_Write(0xA0); // enviar byte a través de (dirección del dispositivo + W)
I2C1_Write(0x00); // enviar byte (dirección de datos)
I2C1_Write(direccion); // enviar byte (dirección de datos)
I2C1_Restart(); // emitir señal repetida para iniciar I2C
I2C1_Write(0xA1); // enviar byte (dirección del dispositivo + R)
valor = I2C1_Read(1); // Leer los datos
I2C1_Stop();
Delay_ms(50);
return valor;
} 
unsigned char potsave[10]={0,0,0,0,0,0,0,0,0,0};
unsigned potval[5]={0,0,0,0,0}
void valores (){
    adres=0;
	while(adres<10){
      potsave[adres]=leer_24lc256(adres);
      adres++;
      potsave[adres]=leer_24lc256(adres);
      adres++;
	}
}
