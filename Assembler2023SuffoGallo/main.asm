;
; arrreglate.asm
;
; Created: 7/10/2023 15:22:21
; Author : Usuario
;
;Incluimos nuestras librerias
.cseg
 .INCLUDE "division.inc"
 .INCLUDE "ApartadoGraficoText.inc"
 .INCLUDE "division.inc"
 .INCLUDE "ApartadoGraficoCodes.inc"
.INCLUDE "Configuraciones.inc"
.INCLUDE "VariablesEnSram.inc"


;Esto lo tenemos que ver si lo dejamos o no, sólo prende leds 
.cseg
.ORG 0x00
JMP CONFIGURAR
jmp EXT_INT0 ; IRQ0 Handler
jmp EXT_INT1 ; IRQ1 Handler
jmp PC_INT0 ; PCINT0 Handler
jmp PC_INT1 ; PCINT1 Handler
jmp PC_INT2 ; PCINT2 Handler
jmp WDT ; Watchdog Timer Handler
jmp TIM2_COMPA ; Timer2 Compare A Handler
jmp TIM2_COMPB ; Timer2 Compare B Handler
rjmp TIM2_OVF ; Timer2 Overflow Handler
rjmp TIM1_CAPT ; Timer1 Capture Handler
rjmp TIM1_COMPA ; Timer1 Compare A Handler
rjmp TIM1_COMPB ; Timer1 Compare B Handler
rjmp TIM1_OVF ; Timer1 Overflow Handler
rjmp TIM0_COMPA ; Timer0 Compare A Handler
rjmp TIM0_COMPB ; Timer0 Compare B Handler
rjmp TIM0_OVF ; Timer0 Overflow Handler
rjmp SPI_STC ; SPI Transfer Complete Handler
rjmp USART_RXC ; USART, RX Complete Handler
rjmp USART_UDRE ; USART, UDR Empty Handler
rjmp USART_TXC ; USART, TX Complete Handler
rjmp ADC_RDY ; ADC Conversion Complete Handler
rjmp EE_RDY ; EEPROM Ready Handler
rjmp ANA_COMP ; Analog Comparator Handler
rjmp TWI ; 2-wire Serial Interface Handler
rjmp SPM_RDY ; Store Program Memory Ready Handler
EXT_INT0:
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
	SEI
	RJMP MAIN
	