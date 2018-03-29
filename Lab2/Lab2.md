2.1.- Se diseñará un sistema de control de acceso por código de teclado través del teclado matricial o PS2, con las siguientes características:
2.1.1.- El código será de 4 dígitos.
2.1.2.- Los dígitos de acceso serán 2 definidos por el estudiante.
2.1.3.- Si el digito es correcto se enviará, luego de 5 segundos, una señal PWM de 90% de ciclo útil durante un segundo, luego 75% durante dos segundos, luego 50% durante 3 segundos y luego se apagará al exterior, en caso contrario solo se verá en la interfaz una animación que indique que no se tiene acceso al local. 
Nota1: Usar el modulo de comparación para generar el PWM y temporizadores para los segundos, no usar librerías de demora.
Nota2: Use el modo de disparo para arrancar el PWM y resetearlo.
2.1.4.- Debe tener la opción de visualizar un histórico de al menos los últimos 5 datos de la siguiente forma:
CODIGO	ACCESO	HORA REAL.
2.2.- El laboratorio tendrá la opción de medir el tiempo que tarda en introducir los 4 números del código (al menos 3 dígitos de precisión) utilizando para esto los módulos de captura. Sugerencia: utilice el modo 32 bits.
2.3.- Se sugiere el uso de un menú principal para escoger el modo de trabajo del diseño.
