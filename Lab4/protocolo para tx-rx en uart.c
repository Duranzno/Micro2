protocolo para tx-rx en uart
caracteres a mandar
1= caso 1
2= caso 2
3= caso 3
// tx para el caso 1-------------------------------------------
----------trabajan desde micro caroni a orinoco--------------
0x2A= pot para el motor 1 (a partir de timer y adc IMPORTANTE)
0x2B= pot para el motor 2 (a partir de timer y adc IMPORTANTE)
-----------trabajan desde micro orinoco a caroni------------
0x2C= mensaje de stop motor 1 (HID)
0x2D= mensaje de stop motor 2  (HID)
0x2E= velocidad motor 1 (HID)
0x2F = velocidad motor 2 (HID)
// tx para el caso 2--------------------------------------
---------------trabajan desde micro orinoco a caroni----
0x3A = animacion por limite superior
0x3B= animacion por limite inferior
// tx para el caso 3--------------------------------
valor numerico entre 0 y 16 para elegir salida del DAC