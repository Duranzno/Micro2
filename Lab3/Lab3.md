Motores de 6 voltios.
2.1 Control de velocidad de 2 Motores Independientes:
	*La velocidad y cambio de giro de los motores serán controlados por 2 potenciómetros respectivamente utilizando el modo complementario.
	*Deben activarse 2 teclas (matricial ó  PS2) para generar una falla en sus respectivos motores y detenerlos mientras se mantienen pulsados, además debe visualizarse una animación, por 8 segundos, referida a la falla y el tipo de motor
	*El periodo de trabajo será de 2 milisegundos para ambos motores en modo centro alineado.
Nota1: EL muestreo será cada un segundo por disparo de eventos especiales por parte de un temporizador. 
2.2 Visualizar la distancia recorrida, numero de vueltas y sentido del QAD.
	*La primera medida será a partir de los 5000 cm después de activar un pulsador al pin INDEX. Trabaje con los modos de inicialización de POSCNT del QEI
	*Si la distancia sobrepasa el 10% por encima o por debajo de su valor inicial debe visualizar una animación referida a esta situación por 5 segundos, utilice el modo comparación del QEI 
2.3	El diseño debe tener la opción de visualizar en la interfaz gráfica el valor en voltaje de cada uno de los potenciómetros en forma dinámica. 
	*Use al menos 3 dígitos de precisión para cada caso en la interfaz gráfica o LCD y actualice cada 1 segundo. Dibuje una perilla semicircular que simule el movimiento de cada potenciómetro con sus valores inicio y final y al menos cinco subdivisiones.
	*Se actualiza solo,c/u segundo no usar boton
	*3 digitos 
Nota2:Utilice el modo de Latcheo Simultaneo.