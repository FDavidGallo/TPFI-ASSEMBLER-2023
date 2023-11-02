.cseg

EXT_INT1:
reti
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
reti
TWI:
reti
SPM_RDY:
reti
PC_INT0:
EXT_INT0:
 GuardarCosas: ; Resulta de particular importancia que cuando se genere una interrupcion se guarde todo lo que el micro estaba
		PUSH R25    ; haciendo antes, para que, al momento de volver no se generen errroes
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
		
		lds r17,C50GesimoDeSegundoo
	
		inc r17
			cpi R17,50
			Breq UnSegundo
		sts C50GesimoDeSegundoo,r17
		cpi R17,40   ; El control se realiza por cada 0,8 segundos, ligeramente más rapido que las mediciones
			Breq Controlar
			Jmp  EscupirTodo
			Controlar:
		;Call Control >>>> En desarrollo
		jmp EscupirTodo
		UnSegundo:
		call Medir
		ldi r17,0
		sts C50GesimoDeSegundoo,r17
		lds r17,UnidadSegundo
		inc r17
	    cpi R17,60
		Breq SumarMinuto
		sts UnidadSegundo,r17
		 ;jmp VERDADERO
		;call medir
		Jmp  EscupirTodo

		SumarMinuto:
		ldi r17,0
		sts UnidadSegundo,r17
		lds r17,UnidadMinuto
		inc r17
	    cpi R17,'9'
		Breq SumarMinuto2
		sts UnidadMinuto,r17
		Jmp  EscupirTodo
		SumarMinuto2:
		ldi r17,'0'
		sts UnidadMinuto,r17
		 
		lds r17,DecenaMinuto
		cpi R17,'5'
		Breq SumarHora
		inc r17
		sts DecenaMinuto,r17
		Jmp  EscupirTodo
SumarHora:
		ldi r17,'0'
		sts DecenaMinuto,r17
		lds r17,HoraABS
		 INC R17
		 cpi r17,24
		 Brsh Finn
		 STS HoraABS,R17
		lds r17,UnidadHora
		cpi R17,'9'
		Breq SumarHora2
		inc r17
		sts UnidadHora,r17
		Jmp  EscupirTodo

SumarHora2:
		ldi r17,'0'
		sts UnidadHora,r17
		lds r17,DecenaHora
		inc r17
		sts DecenaHora,r17
		Jmp  EscupirTodo
		Finn:
		lds r17,UnidadHora
		ldi r17,'0'
		sts UnidadHora,r17
		ldi r17,'0'
		sts DecenaHora,r17
				ldi r17,0
		sts HoraABS,r17
		Jmp  EscupirTodo

//	JMP VolverF
					
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
		POP R25
		RETI
		
		