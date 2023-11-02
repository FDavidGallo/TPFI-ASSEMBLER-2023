;.def 
CONFIGURAR:
ldi r21,0
ldi r30,0
    LDI R16, HIGH(RAMEND)	;Configuramos la pila:
	OUT SPH, R16
	LDI R16, LOW(RAMEND)
	OUT SPL, R16
	LDI R16, 0xFF
	LDI R16,(1<<RXEN0)|(1<<TXEN0)|(1<<UCSZ02) ;Se habilita transmision y recepcion de la Uart.
	STS UCSR0B, R16
	LDI R16,(1<<UCSZ01)|(1<UCSZ00) ;Parity deshabilitado, 9 bits,
	STS UCSR0C, R16
	LDI R16, 103	; Baud Rate = 9600
	STS UBRR0L, R16
	; Configurar el ADC para 10 bits, justificación izquierda, poniendo de paso todo el puerto D (usaremos todos para los sensores) en 0
	ldi r16,0b01100000 ; 5V del micro como referencia
	sts ADMUX, r16
	ldi r16,0b10000111 ; lo cargue en binario, para cargar todo de una:
; 10 bits, justificación izquierda, preescaler en 128
	sts ADCSRA, r16
	ldi r16, 0b00000000 ; Limpiamos el puerto C
	out DDRC, r16 
	CALL ConfiguracionPredeterminada ;cargamos la configuración predeterminada
	ldi ZH, high(DecenaHora); Posicionamos Z en la primer variable de medición
    ldi ZL, low(DecenaHora)
	LDI R19,40				; Cargamos en r19 la cantidad de mediciones a "Limpiar"
	Call ReincioMedciones
	LDI	R16, 0B11111111 ; Configuramos todo el puerto B como salida , tenemos 8 salidas, 8 actuadores...
	OUT 	DDRB,	R16
	LDI	R16,(1<<ISC01)|(1<<ISC00) ; cONFIGURAMOS EICRA, POR FLANCO ASCENDENTE
	STS	EICRA,R16
	LDI	R16,(1<<INT0)
	OUT	EIMSK,R16
	;UNA VEZ TODO CONFIGURADO, HABILITAMOS LAS INTERRUPCIONES, INICIANDO EL FUNCIONAMIENTO NORMAL DEL PROGRAMA
	SEI  ; HABILITACIÓN GLOBAL DE INTERRUPCIONES, PARA MAYOR INFORMACIÓN DIRIGIRSE A  "ATENDIMIENTODEINTERRUPCIONES.INC"
	RJMP MAIN  // CONTINUA EN "APARTADOGRAFICOCODES.INC" Y "APARTADOGRAFICOTEXT.INC"
	
	ConfiguracionPredeterminada:
	;-------------------------------------------------------------------------
	;| INICIO DE LA CONDIGURACIÓN PREDETERMINADA DE FUNCIONAMIENTO           |
	;-------------------------------------------------------------------------
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
	;A
	LDI R20, '1'
	STS TemperaturaExteriorMinimaH,R20
	LDI R20, '0'
	ldi ZH, high(TemperaturaExteriorMinimaL)
    ldi ZL, low(TemperaturaExteriorMinimaL)
	ST Z, R20
	;B
	LDI R20, '3'
	ldi ZH, high(TemperaturaExteriorMaximaH)
    ldi ZL, low(TemperaturaExteriorMaximaH)
	ST Z, R20
	LDI R20, '2'
	ldi ZH, high(TemperaturaExteriorMaximaL)
    ldi ZL, low(TemperaturaExteriorMaximaL)
	ST Z, R20
	;C
	LDI R20, '1'
	ldi ZH, high(TemperaturaLCCMinimaH)
    ldi ZL, low(TemperaturaLCCMinimaH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(TemperaturaLCCMinimaL)
    ldi ZL, low(TemperaturaLCCMinimaL)
	ST Z, R20
	;------------------------------------>
	;D
	LDI R20, '2'
	ldi ZH, high(TemperaturaLCCMaximaH)
    ldi ZL, low(TemperaturaLCCMaximaH)
	ST Z, R20
	LDI R20, '6'
	ldi ZH, high(TemperaturaLCCMaximaL)
    ldi ZL, low(TemperaturaLCCMaximaL)
	ST Z, R20
	;E
	ldi r30,0
	LDI R20, '2'
	ldi ZH, high(SetPointTemperaturaLCCH)
    ldi ZL, low(SetPointTemperaturaLCCH)
	ST Z, R20
	LDI R20, '4'
	ldi ZH, high(SetPointTemperaturaLCCL)
    ldi ZL, low(SetPointTemperaturaLCCL)
	ST Z, R20
	;F
	LDI R20, '0'
	ldi ZH, high(HisterisisTemperaturaLCCH)
    ldi ZL, low(HisterisisTemperaturaLCCH)
	ST Z, R20
	LDI R20, '1'
	ldi ZH, high(HisterisisTemperaturaLCCL)
    ldi ZL, low(HisterisisTemperaturaLCCL)
	ST Z, R20
	;G
	LDI R20, '2'
	ldi ZH, high(TemperaturaDormitorioMaximaH)
    ldi ZL, low(TemperaturaDormitorioMaximaH)
	ST Z, R20
	LDI R20, '6'
	ldi ZH, high(TemperaturaDormitorioMaximaL)
    ldi ZL, low(TemperaturaDormitorioMaximaL)
	ST Z, R20
	;------
	;H
	LDI R20, '1'
	ldi ZH, high(TemperaturaDormitorioMinimaH)
    ldi ZL, low(TemperaturaDormitorioMinimaH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(TemperaturaDormitorioMinimaL)
    ldi ZL, low(TemperaturaDormitorioMinimaL)
	ST Z, R20
	;I
	LDI R20, '2'
	ldi ZH, high(SetPointTemperaturaDormitorioH)
    ldi ZL, low(SetPointTemperaturaDormitorioH)
	ST Z, R20
	LDI R20, '4'
	ldi ZH, high(SetPointTemperaturaDormitorioL)
    ldi ZL, low(SetPointTemperaturaDormitorioL)
	ST Z, R20
	;J
	LDI R20, '0'
	ldi ZH, high(HisterisisTemperaturaDormitorioH)
    ldi ZL, low(HisterisisTemperaturaDormitorioH)
	ST Z, R20
	LDI R20, '1'
	ldi ZH, high(HisterisisTemperaturaDormitorioL)
    ldi ZL, low(HisterisisTemperaturaDormitorioL)
	ST Z, R20
	;K
	LDI R20, '0'
	ldi ZH, high(LuzExteriorMinimaH)
    ldi ZL, low(LuzExteriorMinimaH)
	ST Z, R20
	LDI R20, '1' ; 10 luxes son el limite del crepusculo, fuente:
				 ; «Electro-Optics Handbook» (pdf). burle.com. pp. p. 63. Archivado desde el original el 20 de diciembre de 2008. Consultado el 26 de octubre de 2023.
	ldi ZH, high(LuzExteriorMinimaL)
    ldi ZL, low(LuzExteriorMinimaL)
	ST Z, R20
	;J
	LDI R20, '0'
	ldi ZH, high(HisterisisTemperaturaDormitorioH)
    ldi ZL, low(HisterisisTemperaturaDormitorioH)
	ST Z, R20
	LDI R20, '1'
	ldi ZH, high(HisterisisTemperaturaDormitorioL)
    ldi ZL, low(HisterisisTemperaturaDormitorioL)
	ST Z, R20
	;M
	LDI R20, '5'
	ldi ZH, high(SetPointLuzDormitorioH)
    ldi ZL, low(SetPointLuzDormitorioH)
	ST Z, R20
	LDI R20, '0'
	ldi ZH, high(SetPointLuzDormitorioL)
    ldi ZL, low(SetPointLuzDormitorioL)
	ST Z, R20
	;L
	LDI R20, '0'
	ldi ZH, high(HisterisisLuzDormitorioH)
    ldi ZL, low(HisterisisLuzDormitorioH)
	ST Z, R20
	LDI R20, '1'
	ldi ZH, high(HisterisisLuzDormitorioL)
    ldi ZL, low(HisterisisLuzDormitorioL)
	ST Z, R20
	;O
	LDI R20, '5'
	ldi ZH, high(SetPointLuzLCCH)
    ldi ZL, low(SetPointLuzLCCH)
	ST Z, R20
	LDI R20, '0'
	ldi ZH, high(SetPointLuzLCCL)
    ldi ZL, low(SetPointLuzLCCL)
	ST Z, R20
	;P
	LDI R20, '0'
	ldi ZH, high(HisterisisLuzLCCH)
    ldi ZL, low(HisterisisLuzLCCH)
	ST Z, R20
	LDI R20, '7'
	ldi ZH, high(HisterisisLuzLCCL)
    ldi ZL, low(HisterisisLuzLCCL)
	ST Z, R20
		;Q
	LDI R20, '0'
	ldi ZH, high(DecenaHoraInicioDia)
    ldi ZL, low(DecenaHoraInicioDia)
	ST Z, R20
	LDI R20, '5'
	ldi ZH, high(UnidadHoraInicioDia)
    ldi ZL, low(UnidadHoraInicioDia)
	ST Z, R20
	LDI R20, '3'
	ldi ZH, high(DecenaMinutoInicioDia)
    ldi ZL, low(DecenaMinutoInicioDia)
	ST Z, R20
	LDI R20, '0'
	ldi ZH, high(UnidadMinutoInicioDia)
    ldi ZL, low(UnidadMinutoInicioDia)
	ST Z, R20
		;R
	LDI R20, '1'
	ldi ZH, high(DecenaHoraFinDia)
    ldi ZL, low(DecenaHoraFinDia)
	ST Z, R20
	LDI R20, '9'
	ldi ZH, high(UnidadHoraFinDia)
    ldi ZL, low(UnidadHoraFinDia)
	ST Z, R20
	LDI R20, '3'
	ldi ZH, high(DecenaMinutoFinDia)
    ldi ZL, low(DecenaMinutoFinDia)
	ST Z, R20
	LDI R20, '0'
	ldi ZH, high(UnidadMinutoFinDia)
    ldi ZL, low(UnidadMinutoFinDia)
	ST Z, R20
	RET
	ReincioMedciones:
	
	;-------------------------------------------------------------------------
	;| "LIMPIEZA"      	DE		LAS		OTRAS		VARIABLES	DE	LA SRAM  |
	;-------------------------------------------------------------------------
	CPI R19,00
	BREQ FinLimpieza
	LDI R20, '0' ; POR DEFECTO NUESTRAS MEDICIONES COMIENZAN POR 0
	
	ST Z, R20
	INC ZL
	DEC R19
	rjmp ReincioMedciones
	
	
	FinLimpieza:
		RET





















