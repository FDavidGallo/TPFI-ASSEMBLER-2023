.cseg

EXT_INT1:

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
PC_INT0:
EXT_INT0:
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
		JMP VolverF
					
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
VolverF:
		INC R21
		CPI R21,50
		breq SumarSegundo
		JMP EscupirTodo
	
	SumarSegundo:
		ldi r21,0  ; Reiciamos los 50°tos de segundo
		inc r29
		Call Medir; Para mejor información, dirijase a "desarme.inc"
		Cpi r29,60
		breq SumarMinuto
		JMP EscupirTodo

	SumarMinuto:
		Call Medir
		ldi r29,0
		lds r16,UnidadMinuto
		inc r16 
		sts UnidadMinuto, r16
		Cpi r16,'9'
		breq SumarMinuto2
		
		JMP EscupirTodo
	SumarMinuto2:
		ldi r16,'0'  ; Reiciamos las unidades de minuto
		sts DecenaMinuto, r16
	;	ldi ZH, high(DecenaMinuto)
	;	ldi ZL, low(DecenaMinuto)
	;	ld r16, Z
		Cpi r16,'6'
		breq SumarHora
		st Z, r16
		inc r16 
		JMP EscupirTodo
	SumarHora:
	Call Medir
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
	Call Medir
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

	