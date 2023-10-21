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
QuintoDeSegundo: .BYTE 1; ORGX0108
C50GesimoDeSegundoo: .byte 1 ;org 0x109
MedTemperaturaExteriorH: .byte 1 ;org 0x111
MedTemperaturaExteriorL: .byte 1 ;org 0x111
MedTemperaturaLCCH: .byte 1 ;org 0x113
MedTemperaturaLCCL: .byte 1 ;org 0x113
MedTemperaturaDormitorioH: .byte 1 ;org 0x115
MedTemperaturaDormitorioL: .byte 1 ;org 0x115
MedLuzLCCH: .byte 1 ;org 0x117
MedLuzLCCL: .byte 1 ;org 0x117
MedLuzDormitorioH: .byte 1 ;org 0x117
MedLuzDormitorioL: .byte 1 ;org 0x117
MedLuzExteriorH: .byte 1 ;org 0x117
MedLuzExteriorL: .byte 1 ;org 0x117
.dseg
;=================================================
;|	  INCIO DE LAS VARIABLES DE CONFIGURACIÓN    |
;=================================================
.org 0x0169
Separador0: .BYTE 1 ;org 0x176
TemperaturaExteriorMinimaH: .byte 1 ;	A
TemperaturaExteriorMinimaL: .byte 1 ;	A
Separador1: .BYTE 1 ;org 0x173
TemperaturaExteriorMaximaH: .byte 1;	B
TemperaturaExteriorMaximaL: .byte 1 ;	B
Separador2: .BYTE 1 ;org 0x182
TemperaturaLCCMinimaH:.byte 1 ;			C
TemperaturaLCCMinimaL:.byte 1 ;			C
Separador3: .BYTE 2 ;org 0x188
TemperaturaLCCMaximaH: .byte 1 ;		D 
TemperaturaLCCMaximaL: .byte 1 ;		D
Separador5: .byte 2
SetPointTemperaturaLCCH: .byte 1;		E
SetPointTemperaturaLCCL: .byte 1;		E
Separador6: .byte 2
HisterisisTemperaturaLCCH: .byte 1;		F
HisterisisTemperaturaLCCL: .byte 1;		F
Separador7: .byte 2
TemperaturaDormitorioMaximaH: .byte 1;	G
TemperaturaDormitorioMaximaL:.byte 1;	G
Separador8: .byte 2
TemperaturaDormitorioMinimaH: .byte 1;	H
TemperaturaDormitorioMinimaL: .byte 1;	H
Separador9: .byte 2
;--------------------------------------------------------------------------------------------------
SetPointTemperaturaDormitorioH: .byte 1 ;	I
SetPointTemperaturaDormitorioL: .byte 1 ;	I
Separador10: .BYTE 1 ;org 0x173
HisterisisTemperaturaDormitorioH: .byte 1;	J
HisterisisTemperaturaDormitorioL: .byte 1 ;	J
Separador11: .BYTE 1 ;org 0x182
LuzExteriorMinimaH:.byte 1 ;			K
LuzExteriorMinimaL:.byte 1 ;			K
Separador12: .BYTE 2 ;org 0x188
SetPointLuzDormitorioH: .byte 1 ;		M
SetPointLuzDormitorioL: .byte 1 ;		M
Separador13: .byte 2
HisterisisLuzDormitorioH: .byte 1;		L
HisterisisLuzDormitorioL: .byte 1;		L
Separador14: .byte 2
SetPointLuzLCCH: .byte 1;				O
SetPointLuzLCCL: .byte 1;				O
Separador15: .byte 2
Separador16: .byte 2
HisterisisLuzLCCH: .byte 1;				P
HisterisisLuzLCCL: .byte 1;				P
Separador17: .byte 2
DecenaHoraInicioDia: .byte 1;			Q
UnidadHoraInicioDia: .byte 1;			Q
DecenaMinutoInicioDia: .byte 1;			Q
UnidadMinutoInicioDia: .byte 1;			Q
Separador18: .byte 2
DecenaHoraFinDia: .byte 1;			    R
UnidadHoraFinDia: .byte 1;			    R
DecenaMinutoFinDia: .byte 1;			R
UnidadMinutoFinDia: .byte 1;			R
Separador19: .byte 2
ConfiguracionesValidas: .byte 1;	'0'=Valido  'A'=Existe algo mal 
Separador20: .byte 2
/*PARA TENER EN CUENTA, EL MENU DE SELECCION ES EL SIGUIENTE:
 ; ACA VAN LOS VALORES DE TEMPERATURA
Menu2_2: .DB "A-Temperatura Exterior Minima", 13,10
Menu2_3: .DB "B-Temperatura Exterior Maxima", 13,10
Menu2_4: .DB "C-Temperatura Living/Comedor/Cocina Minima", 13,10
Menu2_5: .DB "D-Temperatura Living/Comedor/Cocina Maxima", 13,10 
Menu2_5: .DB "E-Temperatura Living/Comedor/Cocina deseada", 13,10 
Menu2_6: .DB "F-Histerisis de la temperatura del Living/Comedor/Cocina:", 13, 10
Menu2_7: .DB "G-Temperatura Dormitorio Maxima", 13, 10
Menu2_8: .DB "H-Temperatura Dormitorio Minima", 13, 10
Menu2_8: .DB "I-Temperatura Dormitorio Deseada", 13, 10
Menu2_9: .db "J-Histerisis de la temperatura del Dormitorio", 13, 10
Menu2_A: .DB "Luces en Luxs:", 13, 10
	;ACA VAN LOS VALORES DE LA LUZ
Menu2_B: .DB "K-Luz Exterior Minima", 13, 10
Menu2_C: .DB "M-Valor deseado de la Iluminacion del dormitorio ",13, 10
Menu2_D: .DB "L-Histerisis de la luz del dormitorio", 13, 10
Menu2_C: .DB "O-Valor deseado de la Iluminacion del Living/Comedor/Cocina ",13, 10
Menu2_D: .DB "P-Histerisis de la luz del Living/Comedor/Cocina", 13, 10
 Menu2_E: .DB "Esquema horario:", 13, 10
	;ACA VAN LOS VALORES DE LOS HORARIOS
Menu2_F: .DB " Q-Hora de Inicio del Dia", 13, 10
Menu2_10: .DB "R-Hora de Fin del Dia", 13, 10
Menu2_11: .DB "S-Configurar Hora Actual/Actualizar Reloj", 13, 10
  */
;================================================
;|			INCIO	  DE   	EQUIVALENCIAS  	    |
;================================================
