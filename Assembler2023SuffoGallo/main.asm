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
.INCLUDE "AtendimientoDeInterrupciones.inc"

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
