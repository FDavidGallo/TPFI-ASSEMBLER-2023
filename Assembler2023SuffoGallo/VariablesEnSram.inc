;Inicio de los menús, en su parte de texto
; Definir las variables que usaremos en la RAM
; _____      ______    ____       __  __      ____       ______      _____       __  __           
;/\  _  \    /\__  _\  /\  _`\    /\ \/\ \    /\  _`\    /\__  _\    /\  __`\    /\ \/\ \           EN SU MAYORIA, LAS VARIABLES EN SRAM
;\ \ \L\ \   \/_/\ \/  \ \ \L\_\  \ \ `\\ \   \ \ \/\_\  \/_/\ \/    \ \ \/\ \   \ \ `\\ \    __    NO SE GUARDARÁN EN FORMATO "NUMERICO",
; \ \  __ \     \ \ \   \ \  _\L   \ \ , ` \   \ \ \/_/_    \ \ \     \ \ \ \ \   \ \ , ` \  /\_\   SINO QUE EN ASCII, ESTO TIENE POR FINALIDAD
;  \ \ \/\ \     \ \ \   \ \ \L\ \  \ \ \`\ \   \ \ \L\ \    \_\ \__   \ \ \_\ \   \ \ \`\ \ \/_/_  UNICA PODER VISUALIZARLOS MAS FACILMENTE SUS 
;   \ \_\ \_\     \ \_\   \ \____/   \ \_\ \_\   \ \____/    /\_____\   \ \_____\   \ \_\ \_\  /\_\ VALORES, ESTO ES ESPECIALMENTE SI AL SIMULARSE
;    \/_/\/_/      \/_/    \/___/     \/_/\/_/    \/___/     \/_____/    \/_____/    \/_/\/_/  \/_/ SE DESEA VER EL COMPORTAMIENTO DE LA SRAM

;=================================================
;|	   INCIO DE LAS VARIABLES DE MEDICIONES      |
;=================================================
.dseg
.org 0x0150
C50GesimoDeSegundoo: .byte 1 ;
DecenaHora: .byte 1 
HoraABS: .BYTE 1
UnidadHora: .byte 1	
SeparadorHora: .byte 1; ESTOS SEPARADOS TIENEN COMO FINALIDAD UNICA SEPARAR CADA "VARIABLE", SOLAMENTE ESTÁN DE GUIA
DecenaMinuto: .byte 1 
UnidadMinuto: .byte 1 
SeparadorMinuto: .byte 1 
DecenaSegundo: .byte 1 
UnidadSegundo: .byte 1 
QuintoDeSegundo: .BYTE 1; 

MedTemperaturaExteriorHH: .byte 1 ;
MedTemperaturaExteriorH: .byte 1 ;
MedTemperaturaExteriorL: .byte 1 ;
MedTemperaturaExteriorComa: .byte 5 ;
separadorA: .byte 1 ;
MedTemperaturaLCCHH: .byte 1 ;
MedTemperaturaLCCH: .byte 1 ;
MedTemperaturaLCCL: .byte 1 ;
MedTemperaturaLCCComa: .byte 5 ;
separadorB: .byte 1 ;
MedTemperaturaDormitorioHH: .byte 1 ;
MedTemperaturaDormitorioH: .byte 1 ;
MedTemperaturaDormitorioL: .byte 1 ;
MedTemperaturaDormitorioComa: .byte 1;
separadorC: .byte 4 ;
MedLuzLCCHH: .byte 1 ;
MedLuzLCCH: .byte 1 ;
MedLuzLCCL: .byte 1 ;
MedLuzLCCDecena: .byte 1;
separadorD: .byte 5 
MedLuzDormitorioHH: .byte 1 ;
MedLuzDormitorioH: .byte 1 ;
MedLuzDormitorioL: .byte 1 ;
MedLuzDormitorioDecena: .byte 1 ;
separadorE: .byte 5 
MedLuzExteriorHH: .byte 1 ;
MedLuzExteriorH: .byte 1 ;
MedLuzExteriorL: .byte 1 ;
MedLuzExteriorDecena: .byte 1 ;
SeparadorConfiguracion: .byte 1 ;
.dseg
;=================================================
;|	  INCIO DE LAS VARIABLES DE CONFIGURACIÓN    |
;=================================================
/*PARA TENER EN CUENTA, EL MENU DE SELECCION ES EL SIGUIENTE:
"A-Temperatura Exterior Minima", 13,10
"B-Temperatura Exterior Maxima", 13,10
"C-Temperatura Living/Comedor/Cocina Minima", 13,10
"D-Temperatura Living/Comedor/Cocina Maxima", 13,10 
"E-Temperatura Living/Comedor/Cocina deseada", 13,10 
"F-Histerisis de la temperatura del Living/Comedor/Cocina:", 13, 10
"G-Temperatura Dormitorio Maxima", 13, 10
"H-Temperatura Dormitorio Minima", 13, 10
"I-Temperatura Dormitorio Deseada", 13, 10
"J-Histerisis de la temperatura del Dormitorio", 13, 10
"K-Luz Exterior Minima", 13, 10
"M-Valor deseado de la Iluminacion del dormitorio ",13, 10
"L-Histerisis de la luz del dormitorio", 13, 10
"O-Valor deseado de la Iluminacion del Living/Comedor/Cocina ",13, 10
"P-Histerisis de la luz del Living/Comedor/Cocina", 13, 10
"Q-Hora de Inicio del Dia", 13, 10
"R-Hora de Fin del Dia", 13, 10
"S-Configurar Hora Actual/Actualizar Reloj", 13, 10*/

.org 0x0212
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
HisterisisLuzLCCH: .byte 1;				P
HisterisisLuzLCCL: .byte 1;				P
Separador17: .byte 2
DecenaHoraInicioDia: .byte 1;			Q
UnidadHoraInicioDia: .byte 1;			Q
Separador16: .byte 2
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

; _____      ______    ____       __  __      ____       ______      _____       __  __           
;/\  _  \    /\__  _\  /\  _`\    /\ \/\ \    /\  _`\    /\__  _\    /\  __`\    /\ \/\ \           ESTAS ESTAN EN FORMATO DECIMAL
;\ \ \L\ \   \/_/\ \/  \ \ \L\_\  \ \ `\\ \   \ \ \/\_\  \/_/\ \/    \ \ \/\ \   \ \ `\\ \    __    SON ABSOLUTAS
; \ \  __ \     \ \ \   \ \  _\L   \ \ , ` \   \ \ \/_/_    \ \ \     \ \ \ \ \   \ \ , ` \  /\_\   SU FIN ES DE CONTROL
;  \ \ \/\ \     \ \ \   \ \ \L\ \  \ \ \`\ \   \ \ \L\ \    \_\ \__   \ \ \_\ \   \ \ \`\ \ \/_/_  
;   \ \_\ \_\     \ \_\   \ \____/   \ \_\ \_\   \ \____/    /\_____\   \ \_____\   \ \_\ \_\  /\_\ 
;    \/_/\/_/      \/_/    \/___/     \/_/\/_/    \/___/     \/_____/    \/_____/    \/_/\/_/  \/_/

;================================================================
;|	   INCIO DE LAS VARIABLES DE MEDICIONES  PARA EL CONTROL    |
;================================================================
.dseg
.org 0x0315
MedTemperaturaExteriorABS: .byte 1 ;
separador21: .byte 1 ;
MedTemperaturaLCCABS: .byte 1 ;
separador22: .byte 1 ;
MedTemperaturaDormitorioABS: .byte 1 ;
separador23: .byte 4 ;
MedLuzLCCABS: .byte 1 ;
separador24: .byte 5 
MedLuzDormitorioABS: .byte 1 ;
separador25: .byte 5 
MedLuzExteriorABS: .byte 1 ;
Separador26: .byte 1 ;

;=====================================================================
;|	   INCIO DE LAS VARIABLES DE CONFIGURACIONES  PARA EL CONTROL    |
;=====================================================================
.org 0x0375
Separador27: .BYTE 1 ;org 0x176
TemperaturaExteriorMinimaABS: .byte 1 ;	A
Separador28: .BYTE 1 ;org 0x173
TemperaturaExteriorMaximaABS: .byte 1;	B
Separador29: .BYTE 1 ;org 0x182
TemperaturaLCCMinimaABS:.byte 1 ;		C
Separador30: .BYTE 2 ;org 0x188
TemperaturaLCCMaximaABS: .byte 1 ;		D 
Separador31: .byte 2
SetPointTemperaturaLCCABS: .byte 1;		E
Separador32: .byte 2
HisterisisTemperaturaLCCABS: .byte 1;	F
Separador33: .byte 2
TemperaturaDormitorioMaximaABS: .byte 1;G
Separador34: .byte 2
TemperaturaDormitorioMinimaABS: .byte 1;H
Separador35: .byte 2
;--------------------------------------------------------------------------------------------------
SetPointTemperaturaDormitorioABS: .byte 1 ;	I
Separador36: .BYTE 1 ;org 0x173
HisterisisTemperaturaDormitorioABS: .byte 1;J
Separador37: .BYTE 1 ;org 0x182
LuzExteriorMinimaABS:.byte 1 ;			K
Separador38: .BYTE 2 ;org 0x188
SetPointLuzDormitorioABS: .byte 1 ;		M
Separador39: .byte 2
HisterisisLuzDormitorioABS: .byte 1;	L
Separador40: .byte 2
SetPointLuzLCCABS: .byte 1;				O
Separador41: .byte 2
HisterisisLuzLCCABS: .byte 1;			P
Separador42: .byte 2
HoraInicioDiaABS: .byte 1;		    	Q
Separador43: .byte 2
HoraFinDiaABS: .byte 1;		     	    R
Separador44: .byte 2
.org 0x0425
EstadoBit: .byte 1