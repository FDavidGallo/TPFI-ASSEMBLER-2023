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
MedTemperaturaExterior: .byte 2 ;org 0x111
MedTemperaturaLCC: .byte 2 ;org 0x113
MedTemperaturaDormitorio: .byte 2 ;org 0x115
MedLuzExterior: .byte 2 ;org 0x117

.dseg
;=================================================
;|	  INCIO DE LAS VARIABLES DE CONFIGURACIÓN    |
;=================================================
.org 0x0169
Separador0: .BYTE 1 ;org 0x176
TemperaturaExteriorMinimaH: .byte 1 ;org 0x171
TemperaturaExteriorMinimaL: .byte 1 ;org 0x172
Separador1: .BYTE 1 ;org 0x173
TemperaturaExteriorMaximaH: .byte 1;org 0x174
TemperaturaExteriorMaximaL: .byte 1 ;org 0x175
Separador2: .BYTE 2 ;org 0x182
TemperaturaLCCMinimaH:.byte 2 ;org 0x184
TemperaturaLCCMinimaL:.byte 2 ;org 0x186
Separador3: .BYTE 2 ;org 0x188
TemperaturaLCCMaximaH: .byte 2 ;org 0x190 
TemperaturaLCCMaximaL: .byte 2 ;org 0x192
Separador4: .byte 2 ;org 0x194
HisterisisTemperaturaLCCH: .byte 1
HisterisisTemperaturaLCCL: .byte 1
Separador5: .byte 2
TemperaturaDormitorioMinimaH: .byte 1
TemperaturaDormitorioMinimaL: .byte 1
Separador6: .byte 2
TemperaturaDormitorioMaximaH: .byte 1
TemperaturaDormitorioMaximaL:.byte 1
Separador7: .byte 2
/*PARA TENER EN CUENTA, EL MENU DE SELECCION ES EL SIGUIENTE:
 "A-Temperatura Exterior Minima"
 "B-Temperatura Exterior Maxima"
"C-Temperatura Living/Comedor/Cocina Minima"
"D-Temperatura Living/Comedor/Cocina Maxima"
 "E-Histerisis de la temperatura del Living/Comedor/Cocina:"
 "F-Temperatura Dormitorio Maxima"
 "G-Temperatura Dormitorio Minima"
 " H-Histerisis de la temperatura del Dormitorio"
 "I-Luz Exterior Minima"
 "J-Valor deseado de la Iluminacion Interior "
 "K-Histerisis de la luz interior"
" L-Hora de Inicio del Dia"
"M-Hora de Fin del Dia"
"O-Configurar Hora Actual/Actualizar Reloj"
  */
;================================================
;|			INCIO	  DE   	EQUIVALENCIAS  	    |
;================================================
