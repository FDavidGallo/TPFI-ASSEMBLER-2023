
CONFIGURAR:
    LDI R16, HIGH(RAMEND)	
	OUT SPH, R16
	LDI R16, LOW(RAMEND)
	OUT SPL, R16
	LDI R16, 0xFF
	LDI R16,(1<<RXEN0)|(1<<TXEN0)|(1<<UCSZ02) ;Se habilita transmision y recepcion
	STS UCSR0B, R16
	LDI R16,(1<<UCSZ01)|(1<UCSZ00) ;Parity deshabilitado, 9 bits,
	STS UCSR0C, R16
	LDI R16, 103	; Baud Rate = 9600
	STS UBRR0L, R16
	; Configurar el ADC para 10 bits
	ldi r16,0b01100000
	sts ADMUX,r16
	ldi r16,0b10000111
	sts ADCSRA,r16
	CALL ConfiguracionPredeterminada
	;-------------------------------------------------------------------------
	;| "LIMPIEZA"      	DE		LAS		OTRAS		VARIABLES	DE	LA SRAM  |
	;-------------------------------------------------------------------------
	;UNA VEZ TODO CONFIGURADO, HABILITAMOS LAS INTERRUPCIONES, INICIANDO EL FUNCIONAMIENTO NORMAL DEL PROGRAMA
	SEI  ; HABILITACIÓN GLOBAL DE INTERRUPCIONES, PARA MAYOR INFORMACIÓN DIRIGIRSE A  ATENDIMIENTODEINTERRUPCIONES.INC
	RJMP MAIN  // CONTINUA EN "APARTADOGRAFICOCODES.INC" Y "APARTADOGRAFICOTEXT.INC"
	



	ConfiguracionPredeterminada:
	;-------------------------------------------------------------------------
	;| INICIO DE LA CONDIGURACIÓN PREDETERMINADA DE FUNCIONAMIENTO           |
	;-------------------------------------------------------------------------
	;A
	LDI R20, '1'
	STS TemperaturaExteriorMinimaH,R20
	LDI R20, '2'
	ldi ZH, high(TemperaturaExteriorMinimaL)
    ldi ZL, low(TemperaturaExteriorMinimaL)
	ST Z, R20
	;B
	LDI R20, '3'
	ldi ZH, high(TemperaturaExteriorMaximaH)
    ldi ZL, low(TemperaturaExteriorMaximaH)
	ST Z, R20
	LDI R20, '8'
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
	LDI R20, '3'
	ldi ZH, high(TemperaturaLCCMaximaH)
    ldi ZL, low(TemperaturaLCCMaximaH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(TemperaturaLCCMaximaL)
    ldi ZL, low(TemperaturaLCCMaximaL)
	ST Z, R20
	;E
	LDI R20, '1'
	ldi ZH, high(SetPointTemperaturaLCCH)
    ldi ZL, low(SetPointTemperaturaLCCH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(SetPointTemperaturaLCCL)
    ldi ZL, low(SetPointTemperaturaLCCL)
	ST Z, R20
	;F
	LDI R20, '3'
	ldi ZH, high(HisterisisTemperaturaLCCH)
    ldi ZL, low(HisterisisTemperaturaLCCH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(HisterisisTemperaturaLCCL)
    ldi ZL, low(HisterisisTemperaturaLCCL)
	ST Z, R20
	;G
	LDI R20, '1'
	ldi ZH, high(TemperaturaDormitorioMaximaH)
    ldi ZL, low(TemperaturaDormitorioMaximaH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(TemperaturaDormitorioMaximaL)
    ldi ZL, low(TemperaturaDormitorioMaximaL)
	ST Z, R20
	;------
	;H
	LDI R20, '3'
	ldi ZH, high(TemperaturaDormitorioMinimaH)
    ldi ZL, low(TemperaturaDormitorioMinimaH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(TemperaturaDormitorioMinimaL)
    ldi ZL, low(TemperaturaDormitorioMinimaL)
	ST Z, R20
	;I
	LDI R20, '1'
	ldi ZH, high(SetPointTemperaturaDormitorioH)
    ldi ZL, low(SetPointTemperaturaDormitorioH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(SetPointTemperaturaDormitorioL)
    ldi ZL, low(SetPointTemperaturaDormitorioL)
	ST Z, R20
	;J
	LDI R20, '3'
	ldi ZH, high(HisterisisTemperaturaDormitorioH)
    ldi ZL, low(HisterisisTemperaturaDormitorioH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(HisterisisTemperaturaDormitorioL)
    ldi ZL, low(HisterisisTemperaturaDormitorioL)
	ST Z, R20
	;K
	LDI R20, '1'
	ldi ZH, high(LuzExteriorMinimaH)
    ldi ZL, low(LuzExteriorMinimaH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(LuzExteriorMinimaL)
    ldi ZL, low(LuzExteriorMinimaL)
	ST Z, R20
	;J
	LDI R20, '3'
	ldi ZH, high(HisterisisTemperaturaDormitorioH)
    ldi ZL, low(HisterisisTemperaturaDormitorioH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(HisterisisTemperaturaDormitorioL)
    ldi ZL, low(HisterisisTemperaturaDormitorioL)
	ST Z, R20
	;M
	LDI R20, '1'
	ldi ZH, high(SetPointLuzDormitorioH)
    ldi ZL, low(SetPointLuzDormitorioH)
	ST Z, R20
	LDI R20, '8'
	ldi ZH, high(SetPointLuzDormitorioL)
    ldi ZL, low(SetPointLuzDormitorioL)
	ST Z, R20
	RET


























/*
;CONFIGURACION DE LA INTERRUPCION EXTERNA (cruce por cero) - CONFIGURACION DE LA INTERRUPCION EXTERNA (pulsador SET)
	CONFIGURACION_INT0:
	   LDI  R16,(1<<ISC01)|(1<<ISC00)|(0<<ISC11)|(0<<ISC10)
	   STS  EICRA,R16						; flanco ascendente INT0, nivel bajo INT1
	   LDI  R16,(1<<INT0)|(1<<INT1)
	   OUT  EIMSK,R16						;activo la INT0 y la INT1
	   SEI									;habilitacion general de interrupciones
	RET
	
;CONFIGURACION DEL PERIFERICO UART
	CONFIGURACION_UART:
	   ;Configuracion de la velocidad a 9.600db
	   LDI  R16,103
	   STS  UBRR0L,R16
	   LDI  R16,0
	   STS  UBRR0H,R16
	   ;Configuracion del registro A
	   LDI  R16,0
	   STS  UCSR0A,R16 
	   ;Configuracion del registro B
	   LDI  R16,(1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0)
	   STS  UCSR0B,R16
	   ;Configuracion del registro C 
	   LDI  R16,(1<<UCSZ01)|(1<<UCSZ00); 8 bit
	   STS  UCSR0C,R16
	RET

;CONGIGURACION VALORES INICIALES DEL RELOJ
	CONFIGURACION_VALORES_INICIALES_RELOJ:
       LDI  R20,0
	   STS  CONTADOR_DE_PULSOS,R20
	   LDI  R17,0
	   STS  SEGUNDOS,R17
	   STS  MINUTOS,R17
	   STS  HORAS,R17
	   LDI  R17,'R'
	   STS  CARACTER_ENTRADA_UART,R17
	   LDI  R17,0
	   STS  BOTON_DE_SETEO,R17
	   LDI  R17,0
	   STS  ALARMA,R17
	   LDI  R17,1
	   STS  TIEMPO_DEL_LED,R17
	RET

;CONFIGURACION DEL ADC
	CONFIGURACION_ADC:
	   LDI	R16,(1<<REFS0)|(1<<MUX0)|(1<<ADLAR);tension de referencia de alimentacion / selecionamos como entrada ADC1 / resolucion del conversor (8 bits)
	   STS	ADMUX,R16
	   LDI	R16,(1<<ADEN)|(1<<ADSC)|(1<<ADPS2)|(1<<ADPS1);encendemos el periferico / inicio de conversion (manual) / prescaler en 64    
	   STS	ADCSRA,R16
       LDI	R16,0
	   STS	ADCSRB,R16
	   LDI	R16,(1<<ADC1D);desactiva el buffer digital del pin que se esta utilizando
	   STS	DIDR0,R16
	RET

;CONFIGURACION SETEO RELOJ	 
	CONFIGURACION_SETEO_RELOJ:
      LDI  R16,(1<<PORTD3)
	  OUT  PORTD,R16; configuro como entrada el pulsador SETEAR
	  LDI  R16,(1<<PORTB0)
	  OUT  PORTB,R16; configuro como entrada el pulsador SUBIR
	  LDI  R16,(1<<PORTB1)
	  OUT  PORTB,R16; configuro como entrada el pulsador BAJAR
	  LDI  R16,(1<<DDB5);led alarma
	  OUT  DDRB,R16
	RET

;CONFIGURACION TIMER 1
	CONFIGURACION_TIMER1:
	   LDI  R16,0
	   STS  TCCR1A,R16 ;modo normal
	   LDI  R16,(1<<CS12)
	   STS  TCCR1B,R16 ;prescaler 256
	   LDI  R16,0
	   STS  TCCR1C,R16
	   LDI  R16,0
	   STS  TIMSK1,R16
	   LDI  R16,HIGH(3036)
	   STS  TCNT1H,R16
	   LDI  R16,LOW(3036)
	   STS  TCNT1L,R16
	RET

;Configuraciones Seteo de H M S

	  UART_RELOJ:
	  LDI R20, 'R'
	  CALL ESPERAR_TX
	  LDI R20, 'e'
	  CALL ESPERAR_TX
	  LDI R20, 'l'
	  CALL ESPERAR_TX
	  LDI R20, 'o'
	  CALL ESPERAR_TX
	  LDI R20, 'j'
	  CALL ESPERAR_TX
	  LDI R20, ':'
	  CALL ESPERAR_TX
	  LDI R20, ' '
	  CALL ESPERAR_TX
	  LDI R20, ' '
	  RET

	  UART_MOSTRAR_ALARMA:
	  LDI R20, 'A'
	  CALL ESPERAR_TX
	  LDI R20, 'l'
	  CALL ESPERAR_TX
	  LDI R20, 'a'
	  CALL ESPERAR_TX
	  LDI R20, 'r'
	  CALL ESPERAR_TX
	  LDI R20, 'm'
	  CALL ESPERAR_TX
	  LDI R20, 'a'
	  CALL ESPERAR_TX
	  LDI R20, ':'
	  CALL ESPERAR_TX
	  LDI R20, ' '
	  CALL ESPERAR_TX
	  RET

	 UART_MOSTRAR_SET:
	 LDI R20, 'S'
	 CALL ESPERAR_TX
	 LDI R20, 'e'
	 CALL ESPERAR_TX
	 LDI R20, 't'
	 CALL ESPERAR_TX
	 LDI R20, ' '
	 CALL ESPERAR_TX
	 RET


	;Configuracion Inicio SDIV
	  UART_MOSTRAR_INICIO:
	  LDI R20, 'R'
	  CALL ESPERAR_TX	  	
	  LDI R20, 'e'
	  CALL ESPERAR_TX
	  LDI R20, 'l'
	  CALL ESPERAR_TX
	  LDI R20, 'o'
	  CALL ESPERAR_TX
	  LDI R20, 'j'
	  CALL ESPERAR_TX
	  LDI R20, ' '
	  CALL ESPERAR_TX
	  LDI R20, 'S'
      CALL ESPERAR_TX
	  LDI R20, 'D'
	  CALL ESPERAR_TX
	  LDI R20, ' '
	  CALL ESPERAR_TX
	  LDI R20, 'I'
	  CALL ESPERAR_TX
  	  LDI R20, 'V'
	  CALL ESPERAR_TX
	  
  	  LDI R20, 13
	  CALL ESPERAR_TX
	  RET
	  */