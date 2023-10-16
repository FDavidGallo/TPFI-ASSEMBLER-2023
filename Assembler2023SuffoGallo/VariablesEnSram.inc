;Inicio de los menús, en su parte de texto
; Definir las variables que usaremos en la RAM
;=================================================
;|	   INCIO DE LAS VARIABLES DE MEDICIONES      |
;=================================================
.dseg
.org 0x0100
DecenaHora: .byte 1 ;org 0x101
UnidadHora: .byte 1	;org 0x102
DecenaMinuto: .byte 1 ;org 0x103
UnidadMinuto: .byte 1 ;org 0x104
SeparadorMinuto: .byte 1 ;org 0x105
DecenaSegundo: .byte 1 ;org 0x106
UnidadSegundo: .byte 1 ;org 0x107
C50GesimoDeSegundoo: .byte 2 ;org 0x108
MedTemperaturaExterior: .byte 2 ;org 0x110
MedTemperaturaLCC: .byte 2 ;org 0x112
MedTemperaturaDormitorio: .byte 2 ;org 0x114
MedLuzExterior: .byte 2 ;org 0x116


;=================================================
;|	  INCIO DE LAS VARIABLES DE CONFIGURACIÓN    |
;=================================================
.org 0x0170

TemperaturaExteriorMinimaH: .byte 2 ;org 0x172
TemperaturaExteriorMinimaL: .byte 2 ;org 0x174
Separador1: .BYTE 2 ;org 0x176
TemperaturaExteriorMaximaH: .byte 2;org 0x178
TemperaturaExteriorMaximaL: .byte 2 ;org 0x180
Separador2: .BYTE 2 ;org 0x182
TemperaturaLCCMinimaH:.byte 2 ;org 0x184
TemperaturaLCCMinimaL:.byte 2 ;org 0x186
Separador3: .BYTE 2 ;org 0x188
TemperaturaLCCMaximaH: .byte 2 ;org 0x190 
TemperaturaLCCMaximaL: .byte 2 ;org 0x192
Separador4: .byte 2 ;org 0x194
/*
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
*/