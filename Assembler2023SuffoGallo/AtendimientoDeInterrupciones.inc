.cseg
EXT_INT0:
  JMP EntroUnFlanco
EXT_INT1:
PC_INT0:
PC_INT1:
PC_INT2:
WDT:
TIM2_COMPA:
TIM2_COMPB:
TIM2_OVF:
TIM1_CAPT:
TIM1_COMPA:
TIM1_COMPB:
TIM1_OVF:
TIM0_COMPA:
TIM0_COMPB:
TIM0_OVF:
SPI_STC:
USART_RXC:
USART_UDRE:
USART_TXC:
ADC_RDY:
EE_RDY:
ANA_COMP:
TWI:
SPM_RDY:
reti
EntroUnFlanco:
	ldI R21,'F'; F DE FLANCO
	jmp GuardarCosas

 GuardarCosas: ; Resulta de particular importancia que cuando se genere una interrupcion se guarde todo lo que el micro estaba
		PUSH R5    ; haciendo antes, para que, al momento de volver no se generen errroes
		PUSH R12
		PUSH R16
		PUSH R17
		PUSH R18
		PUSH R19
		PUSH R20
		PUSH R30 ; Estos dos resultan  de particular importancia, ya que: ZH:ZL son  R31:R30
		PUSH R31 ; puntero que se usa mucho en mi programa
		IN	R17,SREG ;
		PUSH	R17	 ; GUARDAMOS EN PILA EL REGISTRO DE ESTADO
		;Procedemos a preguntar que se guardó en R21, para ver a que parte de la interrrupción toca volver
		; ¿Porque no usar un call?  Porque modificaria la pila y es algo que no queremos.
		CPI R21,'F'
		BREQ VolverF
					VolverF:
							JMP EntroUnFlancoContinuacion ;Continuamos con "Entró un flanco"
 EscupirTodo: ;Es la función contraria a "Guardar cosas", como su  nombre indica devolvemos todo a su lugar
		POP R17
		OUT SREG,R17 ; DEVOLVEMOS EL REGISTRO DE ESTADO A SU LUGAR 
		POP R31 ; Por la naturaleza de la pila, se devuelven las cosas en orden inverso 
		POP R30
		POP R20
		POP R19
		POP R18
		POP R17
		POP R16
		POP R12
		POP R5
		RETI
	EntroUnFlancoContinuacion:
		 ldi ZH, high(C50GesimoDeSegundoo) ;por cada flanco suma un 50°mo de segundo
		 ldi ZL, low(C50GesimoDeSegundoo)
		ld r16, Z
		inc r16 
		st Z, r16
		Cpi r16,10
		breq SumarQuinto
		JMP EscupirTodo
	SumarQuinto:
		ldi r16,0x00  ; Reiciamos los 50°mos de segundo
	    st Z, r16
		ldi ZH, high(QuintoDeSegundo)
		ldi ZL, low(QuintoDeSegundo)
		ld r16, Z
		inc r16 
		st Z, r16
		Cpi r16,1    ; Considerando una freuencia de 50Hz, se ejecutarán cada 200ms las variables de control,
		breq _control ; razonable si se tiene en cuenta que una medición se hace cada un segundo.
		Cpi r16,5
		breq SumarSegundo
		JMP EscupirTodo
		_control:
				call Control_Int
	SumarSegundo:
		ldi r16,0x00  ; Reiciamos los 5°tos de segundo
		st Z, r16
		ldi ZH, high(UnidadSegundo)
		ldi ZL, low(UnidadSegundo)
		ld r16, Z
		Cpi r16,'9'
		breq SumarSegundo2
		inc r16 
		st Z, r16
        Call Medir; Para mejor información, dirijase a "desarme.inc"
		JMP EscupirTodo
	SumarSegundo2:
		ldi r16,'0'  ; Reiciamos las unidades de segundo
		st Z, r16
		ldi ZH, high(DecenaSegundo)
		ldi ZL, low(DecenaSegundo)
		ld r16, Z
		Cpi r16,'6'
		breq SumarMinuto
		inc r16 
		st Z, r16
		JMP EscupirTodo
	SumarMinuto:
		ldi r16,'0'  ; Reiciamos los  segundos
		st Z, r16
		ldi ZH, high(UnidadMinuto)
		ldi ZL, low(UnidadMinuto)
		ld r16, Z
		Cpi r16,'9'
		breq SumarMinuto2
		inc r16 
		st Z, r16
		JMP EscupirTodo
	SumarMinuto2:
		ldi r16,'0'  ; Reiciamos las unidades de minuto
		st Z, r16
		ldi ZH, high(DecenaMinuto)
		ldi ZL, low(DecenaMinuto)
		ld r16, Z
		Cpi r16,'6'
		breq SumarHora
		st Z, r16
		inc r16 
		JMP EscupirTodo
	SumarHora:
		ldi r16,'0'  ; Reiciamos los minutos
		ldi ZH, high(UnidadHora)
		ldi ZL, low(UnidadHora)
		ld r16, Z
		Cpi r16,'1'
		breq SumarHora2
		inc r16 
		st Z, r16
		JMP EscupirTodo
	SumarHora2:
		ldi ZH, high(DecenaHora)
		ldi ZL, low(DecenaHora)
		ld R18, Z
		CpI R18,'2'
		breq PreguntaDia
		inc r18 
		st Z, r18
		JMP EscupirTodo
	 PreguntaDia:
		cpi r16,'4'
		BREQ TerminoElDia
		JMP EscupirTodo
	 TerminoElDia:
		ldi ZH, high(DecenaHora)
		ldi ZL, low(DecenaHora)
		ldi r16,'0'  ; Reiciamos las decena de hora
		st Z, r16
		JMP EscupirTodo

	