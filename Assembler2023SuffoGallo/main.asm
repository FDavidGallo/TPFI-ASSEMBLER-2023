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
RJMP CONFIGURAR

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
	RJMP MAIN
	