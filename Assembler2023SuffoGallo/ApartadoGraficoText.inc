;Inicio de los menús, en su parte de texto
; Definir una cadena en la ROM, son constantes

.cseg
.ORG 0X150
TABLA_ROM_MSJ: .DB 0b00001010, "***  Seleccione la accion a realizar ***", 0b00001010
TABLA_ROM_OPT: .DB 0b00001010, "1-Mostrar Valores...", 13,0b00001010 , " 2-Configurar Valores...", 13, 0b00001010, "3-Datos Del proyecto... ",2

TABLA_ROM_MSJ2: .DB 0b00001010, "*** MEDICIONES ***", 0b00001010
TABLA_ROM_OPT2: .DB 0b00001010,"Hora de las mediciones __:__",0b00001010," Temperatura Exterior: _ _",0b00001010," Temperatura Living/Comedor/Cocina: __ ",0b00001010," Temperatura Dormitorio: __ ",0b00001010," Luz Dormitorio: __0  "," Luz Exterior: __0 "," Luz Living/Cocina/Comedor: __0 ",0b00001010,"	1-Refrescarar Valores... 5-VOLVER AL MENU ANTERIOR ", 13, 10,2
TABLA_ROM_MSJ3: .DB 0b00001010, "*** Seleccione el valor a cambiar ***", 0b00001010
Menu2_1: .DB 0b00001010, "		Temperaturas en Grados Centigrados		", 0b00001010
	;ACA VA LA TEMPERATURA EXTER
Menu2_2: .DB "A-Temperatura Exterior Minima __ ", 13,10
Menu2_3: .DB "B-Temperatura Exterior Maxima __ ", 13,10
Menu2_4: .DB "C-Temperatura Living/Comedor/Cocina Minima __ ", 13,10
Menu2_5: .DB "D-Temperatura Living/Comedor/Cocina Maxima __", 13,10 
Menu2_6: .DB "E-Histerisis de la temperatura del Living/Comedor/Cocina: __", 13, 10
Menu2_7: .DB "F-Temperatura Dormitorio Maxima __ ", 13, 10
Menu2_8: .DB "G-Temperatura Dormitorio Minima __", 13, 10
Menu2_9: .db " H-Histerisis de la temperatura del Dormitorio __", 13, 10
Menu2_A: .DB "Luces en Luxs:", 13, 10
	;ACA VAN LOS VALORES DE LA LUZ
Menu2_B: .DB "I-Luz Exterior Minima __0 ", 13, 10
Menu2_C: .DB "J-Valor deseado de la Iluminacion Interior __0 ",13, 10
Menu2_D: .DB "K-Histerisis de la luz interior  __0", 13, 10
 Menu2_E: .DB "Esquema horario:", 13, 10
	;ACA VAN LOS VALORES DE LOS HORARIOS
Menu2_F: .DB " L-Hora de Inicio del Dia __:__ ", 13, 10
Menu2_10: .DB "M-Hora de Fin del Dia __:__ ", 13, 10
Menu2_11: .DB "O-Configurar Hora Actual/Actualizar Reloj __:__ ", 13, 10
Menu2_12: .DB "5-VOLVER AL MENU ANTERIOR ", 13, 10,2
CambioDeValor:
.DB "	Cambiado! Desea cambiar algo mas?", 13, 10, "5-NO, Volver Al menu principal", 13, 10, "2-Si, volver al menu anterior ", 13, 10,2

CTEXTO:
.DB "Ingrese el nuevo valor:	",2