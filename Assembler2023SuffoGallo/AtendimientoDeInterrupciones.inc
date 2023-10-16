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
	ldi ZH, high(C50GesimoDeSegundoo)
    ldi ZL, low(C50GesimoDeSegundoo)
	ld r16, Z
	inc r16 
    st Z, r16
	Cpi r16,10
	breq SumarQuinto
	Reti
	SumarQuinto:
	ldi ZH, high(QuintoDeSegundo)
    ldi ZL, low(QuintoDeSegundo)
	ld r16, Z
	inc r16 
    st Z, r16
	Cpi r16,5
	breq SumarSegundo
	RETI
	SumarSegundo:
	ldi ZH, high(UnidadSegundo)
    ldi ZL, low(UnidadSegundo)
	ld r16, Z
	inc r16 
    st Z, r16
	Cpi r16,10
	breq SumarSegundo2
	RETI
	SumarSegundo2:
	ldi ZH, high(DecenaSegundo)
    ldi ZL, low(DecenaSegundo)
	ld r16, Z
	inc r16 
    st Z, r16
	Cpi r16,6
	breq SumarMinuto
	RETI
	SumarMinuto:
	ldi ZH, high(UnidadMinuto)
    ldi ZL, low(UnidadMinuto)
	ld r16, Z
	inc r16 
    st Z, r16
	Cpi r16,6
	breq SumarMinuto2
	RETI
	SumarMinuto2: