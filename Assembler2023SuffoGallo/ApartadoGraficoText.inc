;Inicio de los men�s, en su parte de texto
; Definir una cadena en la ROM, son constantes

.cseg
.ORG 0X150
TABLA_ROM_MSJ: .DB 13,10, 0b00001010, "***>>>Seleccione la accion a realizar<<< ***", 0b00001010,13,10
TABLA_ROM_OPT: .DB 13,10, "1-Mostrar Valores...", 13,10,"2-Configurar Valores...", 13, 0b00001010, "3-Datos Del proyecto... ",2
TABLA_ROM_MSJ2: .DB 13,10, "*** MEDICIONES ***",13,10
TABLA_ROM_MSJ22: .DB "< Busque cada medicion segun su Letra  >",13,10
TABLA_ROM_OPT2: .DB "Hora de las mediciones: T "," Temperatura Exterior: U",13,10," Temperatura Living/Comedor/Cocina: V  ", "  Temperatura Dormitorio: W ",13,10," Luz Dormitorio:  X "," Luz Exterior:  Y "," Luz Living/Cocina/Comedor:  Z ",13,10,"	1-Refrescarar Valores... 5-VOLVER AL MENU ANTERIOR ", 13, 10
TABLA_ROM_MSJ212: .DB "VALORES >",2
;ACA VAN LAS MEDICIONES
TABLA_ROM_MSJ3: .DB 0b00001010, "ADVERTENCIA!", 0b00001010
.DB " SI VA A CAMBIAR ALGO TENGA EL CUIDADO DE HACERLO DE FORMA COHERENTE, ",13,10
.DB "TENIENDO EN CUENTA QUE: LA TEMPERATURA MINIMA A INGRESAR ES 00 *F  Y LA MAXIMA 99 *F; LAS HORAS VAN DE 00 A 24 HORAS",13,10
.DB "EN CUANTO LOS LUXOMETROS, SU PRECISION ES DE 10 LUXES, POR LO QUE SOLO SE CONFIGURAN DE 10 EN DIEZ,",13,10,0
.db " SIENDO EL VALOR MINIMO 010 Luxs Y EL MAXIMO 640 Luxs,(esto basado en la norma IRAM-AADL J 20-06) ",13,10
.DB 13,10
.DB "*** Ahora si, seleccione el valor a cambiar  ***",13,10
Menu2_1: .DB  "Temperaturas en Grados Fahrenheit  ",13,10,0
; ACA VAN LOS VALORES DE TEMPERATURA
Menu2_2: .DB "A-Temperatura Exterior Minima ", 13,10
Menu2_3: .DB "B-Temperatura Exterior Maxima ", 13,10
Menu2_4: .DB "C-Temperatura Living/Comedor/Cocina Minima", 13,10
Menu2_5_0: .DB "D-Temperatura Living/Comedor/Cocina Maxima", 13,10 
Menu2_5: .DB "E-Temperatura Living/Comedor/Cocina deseada ", 13,10 
Menu2_6: .DB "F-Histerisis de la temperatura del Living/Comedor/Cocina:",0,13, 10
Menu2_7: .DB "G-Temperatura Dormitorio Maxima ", 13, 10
Menu2_8: .DB "H-Temperatura Dormitorio Minima ", 13, 10
Menu2_8_1: .DB "I-Temperatura Dormitorio Deseada", 13, 10
Menu2_9: .db "J-Histerisis de la temperatura del Dormitorio ", 13, 10
Menu2_A: .DB "Luces en Luxs:", 13, 10
	;ACA VAN LOS VALORES DE LA LUZ
Menu2_B: .DB "K-Luz Exterior Minima ", 13, 10
Menu2_C: .DB "M-Valor deseado de la Iluminacion del dormitorio",13, 10
Menu2_D: .DB "L-Histerisis de la luz del dormitorio",0, 13, 10
Menu2_C1: .DB "O-Valor deseado de la Iluminacion del Living/Comedor/Cocina ",13, 10
Menu2_D66: .DB "P-Histerisis de la luz del Living/Comedor/Cocina", 13, 10
 Menu2_E: .DB "Esquema horario:", 13, 10
	;ACA VAN LOS VALORES DE LOS HORARIOS
Menu2_F: .DB "Q-Hora de Inicio del Dia", 13, 10
Menu2_10: .DB "R-Hora de Fin del Dia ", 13, 10
Menu2_11: .DB "S-Configurar Hora Actual/Actualizar Reloj ", 13, 10
Menu2_12: .DB "5-VOLVER AL MENU ANTERIOR ", 13, 10
Menu2_13: .db "Valores Actuales: (Segun cada letra) ",2
; ACA SE MUESTRAN LAS CONFIGURACIONES
CambioDeValor:
.DB "  Cambiado! Desea cambiar algo mas?", 13, 10, "5-NO, Volver Al menu principal", 13, 10, "2-Si, volver al menu anterior ", 13, 10,2
;Mensaje de cambio de valor
CTEXTO:
.DB "Ingrese el nuevo valor:	",2,0
; EN CASO DE HABER ERROR:
ERROR:
.db "	Existe una configuraci�n no v�lida. NO SE EJECUTAR� NADA	"
.db "	Por favor, ingrese una configuraci�n v�lida o reinicie	",2,0
;      ^SI LLEGO, LE IMPLEMENTO CONTROL DE ERRORES^
































































;Datos del proyecto
Datos:
.DB 13,10,13,10,13,10
.DB "                                             ____||____",13,10,0
.DB"DOMOTICA DE DOS AMBIENTES:                  ///////////\",13,10
.DB" Es un proyecto, en que con se controlan   ///////////  \",13,10,0
.DB"      luz y temperatura de dos ambientes,  |    _    |  |",13,10,0
.DB"  el dormitorio y el living/               |[] | | []|[]|",13,10,0
.DB"comedor/cocina                             |   | |   |  |",13,10,0
.DB 13,10,13,10,13,10
.DB "                                 .*########+    ",13,10      
.DB "                                =@@++++++++-    ",13,10      
.DB "                              -%@*.              ",13,10,0
.DB "                             -**-                ",13,10,0  
.DB "                  ..............                 ",13,10,0    
.DB "               :*@@@@@@@@@@@@@@@@*:                 ",13,10  
.DB "               %@@@@@@@@@@@@@@@@@@%               HECHO POR: FABRICIO DAVID GALLO  ",13,10,0
.DB "               ********************                    ",13,10,0           
.DB "             +@@@@@@@@@@@@@@@@@@@@@@+              A MODO DE TRABAJO FINAL PARA LA CATEDRA:",13,10,0
.DB "            =@@@@@@@@@@@@@@@@@@@@@@@@=              SISTEMAS DIGITALES IV  ",13,10,0
.DB "           :@@@@@@@@@@@@@@@@@@@@@@@@@@:             ",13,10  
.DB "           #@@@@@@@@@@@@@@@@@@@@@@@@@@#               ",13,10
.DB "          :@@@@@@@@@@@@@@@@@@@@@@@@@@@@:             PROFESORES: LIC. JULIAN MINATEL ",13,10,0
.DB "          =@@@@@@@@@@@@@@@@@@@@@@@@@@@@=			   ING. VELAZQUEZ EDUARDO",13,10
.DB "          =@@@@@@@@@@@@@@@@@@@@@@@@@@@@-              ",13,10
.DB "          .@@@@@@@@@@@@@@@@@@@@@@@@@@@@.              ",13,10
.DB "           +@@@@@@@@@@@@@@@@@@@@@@@@@@+             CICLO LECTIVO 2023  ",13,10
.DB "            *@@@@@@@@@@@@@@@@@@@@@@@@*                 ",13,10,0
.DB "             =@@@@@@@@@@@@@@@@@@@@@%=                 ",13,10
.DB "              .=%@@@@@@@@@@@@@@@@%=.                  ",13,10
.DB "                 .-=+++++++++++=-.                     ",13,10,0
.DB 13,10,13,10,13,10  
.DB "888     888        d8888  8888888b.   8888888888  8888888b.      8888888888  .d8888b.  Y88b   d88P 88888888888",13,10
.DB "888     888       d88888  888   Y88b  888         888   Y88b     888        d88P  Y88b  Y88b d88P      888",13,10
.DB "888     888      d88P888  888    888  888         888    888     888        888    888   Y88o88P       888",13,10
.DB "888     888     d88P 888  888    888  8888888     888   d88P     8888888    888           Y888P        888",13,10
.DB "888     888    d88P  888  888    888  888         8888888P       888        888            888         888",13,10
.DB "888     888   d88P   888  888    888  888         888 T88b       888        888    888     888         888",13,10
.DB "Y88b. .d88P  d8888888888  888  .d88P  888         888  T88b      888        Y88b  d88P     888         888",13,10
.DB "  Y88888P   d88P     888  8888888P    8888888888  888   T88b     888          Y8888P       888         888",13,10
.DB 13,10,13,10,13,10                                                                                                                
.DB "			5- Volver Al menu principal					",13,10,2
/*
ADORNOS CREADOS MEDIANTE https://es.rakko.tools/tools/68/ Y https://www.topster.es/texto-ascii/larry3d.html, CREDITOS 
Y MUCHAS GRACIAS A SUS RESPECTIVOS CREADORES
*/