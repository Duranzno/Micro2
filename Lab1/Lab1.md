#Laboratorio
2.1.- Si se pulsa la primera opción todos los pulsadores serán atendidos por interrupción (pines INTx) y se visualizara en la interfaz tanto el número de veces que se pulsa con un contador como una barra tipo histograma. El número máximo a contar y visualizar es 25 luego de esto la barra se resetea pero no el conteo. 
Nota: El pulsador 0 es el más prioritario y el 4 el menos

2.2.- Si se pulsa la segunda opción cuatro Dip-Switch permitirán, de manera individual, generar una animación diferente que se visualizarán en la interfaz gráfica.  
2.3.- Si se pulsa la tercera opción el diseño debe ser capaz de visualizar por 20 segundos (usar una animación) cual fue el último elemento que provocó un reset.
	2.3.1: Solo se trabajará con el POR, MCLR y el WDT. 
	2.3.2: Se utilizará el quinto Dip-Switch para habilitar y deshabilitar el perro guardian por software.
	2.3.3: Se sugiere un tiempo de desbordamiento para el perro guardián mayor de 1 minuto. 2.3.4.- Por cada reset detectado se encenderá un LED respectivo que indicara por hardware quien lo provocó.