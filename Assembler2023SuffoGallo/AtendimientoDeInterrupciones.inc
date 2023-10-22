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
	ldi ZH, high(C50GesimoDeSegundoo) ;por cada flanco suma un 50°mo de segundo
    ldi ZL, low(C50GesimoDeSegundoo)
	ld r16, Z
	inc r16 
    st Z, r16
	Cpi r16,10
	breq SumarQuinto
	Reti
	SumarQuinto:
	ldi r16,0x00  ; Reiciamos los 50°mos de segundo
    st Z, r16
	ldi ZH, high(QuintoDeSegundo)
    ldi ZL, low(QuintoDeSegundo)
	ld r16, Z
	inc r16 
    st Z, r16
	Cpi r16,5
	breq SumarSegundo
	RETI
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
	;jmp RecibirMediciones
	RETI
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
	RETI
	SumarMinuto:
	ldi r16,'0'  ; Reiciamos los  segundos
    st Z, r16
	ldi ZH, high(UnidadMinuto)
    ldi ZL, low(UnidadMinuto)
	 st Z, r16
	Cpi r16,'9'
	ld r16, Z
	inc r16 
	breq SumarMinuto2
	RETI
	SumarMinuto2:
	ldi r16,'0'  ; Reiciamos las unidades de minuto
    st Z, r16
	ldi ZH, high(DecenaMinuto)
    ldi ZL, low(DecenaMinuto)
	ld r16, Z
	st Z, r16
	Cpi r16,'6'
	breq SumarHora
	inc r16 
	RETI
	SumarHora:
	ldi r16,'0'  ; Reiciamos los minutos
	ldi ZH, high(UnidadHora)
    ldi ZL, low(UnidadHora)
	ld r16, Z
	Cpi r16,10
	breq SumarHora2
	inc r16 
    st Z, r16
	RETI
	SumarHora2:
	ldi ZH, high(DecenaHora)
    ldi ZL, low(DecenaHora)
	ld R18, Z
	CpI R18,'2'
	breq PreguntaDia
	inc r18 
    st Z, r18
	RETI
	 PreguntaDia:
	 cpi r16,4
	 BREQ TerminoElDia
	 RETI
	 TerminoElDia:
	 ldi ZH, high(DecenaHora)
    ldi ZL, low(DecenaHora)
    ldi r16,'0'  ; Reiciamos los 50°mos de segundo
    st Z, r16
	 RET
	 