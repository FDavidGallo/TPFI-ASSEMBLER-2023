/*
ENVIO_UART:
        	LDI	R16,48
        	ADD	R20,R16
ESPERAR_TXTTTT:
	LDS	R16,UCSR0A
	SBRS	R16,UDRE0
	RJMP	ESPERAR_TXTTTT
	STS	UDR0,R20
	RET

VERDADERO:       
     CLR R16
;	 STS CONTADOR,R16
;	 call horario
;	 call rangoHorario 
    ;call cortinas   
;ADC0:
    Ldi R16, (0<<MUX0)|(0<<MUX1)|(0<<MUX2)
    STS ADMUX,R16
    call conversion

;ADC1:
;    LDI R16,(1<<MUX0)|(0<<MUX1)|(0<<MUX2)
 ;   STS ADMUX,R16
  ;  call conversion

;ADC2:
   ; LDI R16,(0<<MUX0)|(1<<MUX1)|(0<<MUX2)
    ;STS ADMUX,R16
    ;call conversion

;ADC3:
    ;LDI R16,(1<<MUX0)|(1<<MUX1)|(0<<MUX2)
    ;STS ADMUX,R16
    call conversion

;ADC4:
    ;LDI R16,(0<<MUX0)|(0<<MUX1)|(1<<MUX2)
    ;STS ADMUX,R16
    ;call conversion

;ADC5:
    ;LDI R16,(1<<MUX0)|(0<<MUX1)|(1<<MUX2)    ;Vuelve al conversor 0
    ;STS ADMUX,R16

Seguir:
;Va a hacer las conversiones desde adc1 y va a terminar en adc0, 
;se puede hacer un contador para contar las 6 conversiones y de ahí recién enviar los datos por la uart. 

CONVERSION:                
        PUSH	R17
          IN	R17,SREG
        PUSH	R17
	
         LDS	R17,ADCSRA
         SBR	R17,(1<<ADSC)
         STS	ADCSRA,R17
ESPERAR_ADC:
         LDS    R17,ADCSRA
        SBRC	R17,ADSC
        RJMP	ESPERAR_ADC
        Ldi     r16,admux          ;hay que saber cuál convirtió para guardar la conversión en diferentes registros
        Cpi     r16, 0b01100000
        Breq    guardarADC0
        Cpi     r16, 0b01100001
     ;   Breq    guardarADC1
     ;   Cpi     r16, 0b01100010
     ;   Breq    guardarADC2
     ;   Cpi     r16, 0b01100011
     ;   Breq    guardarADC3
      ;  Cpi     r16, 0b01100100
      ;  Breq    guardarADC4
      ;  Cpi     r16, 0b01100110
       ; Breq    guardarADC5

guardarADC0:		;ADC0 ES EL TERMOMETRO DEL DORMITORIO
          LDS	R16,ADCL	;hay que cambiar los registros para no sobrescribirlos
          LDS	R17,ADCH
	      
          MOVW	R24,R16	;SIGUE EL VALOR EN R16 DESPUES DE CARGARLO EN LA VARIABLE?


		  LDI	R23,HIGH(25)	;Division por 25
		  LDI	R22,LOW(25)
		  CALL	DIVISION16
	      MOVW	R16,R24

          Ldi zh,high(MedTemperaturaDormitorioHH)	;Guarda el valor ya dividido
          Ldi zl,low(MedTemperaturaDormitorioHH)
          St z+,r17
          St z,r16

          CALL	DESARMAR_ENVIAR
		Jmp  EscupirTodo
	   ;   RJMP FinGuardar
		  
guardarADC1:		;ADC1 TERMOMETRO DE ESTAR, COCINA, COMEDOR
         LDS	R18,ADCL
         LDS	R19,ADCH
	     MOVW	R24,R18
		 LDI	R23,HIGH(25)	;Division por 25
		 LDI	R22,LOW(25)
		 CALL	DIVISION16		;en r24 queda el resultado para desarmar enviar
         MOVW	R16,R24

       ;  Ldi zh,high(TermoCocinaComedor)	
         Ldi zl,low(TermoCocinaComedor)
         St z+,r1+7
         St z,r16
         CALL	DESARMAR_ENVIAR
         RJMP FinGuardar
guardarADC2:		;ADC2 TERMOMETRO EXTERIOR
	     LDS	R20,ADCL
         LDS	R21,ADCH
         MOVW	R24,R20
		 LDI	R23,HIGH(25)	;Division por 25
		 LDI	R22,LOW(25)
	     CALL	DIVISION16

         MOVW	R16,R24

         Ldi zh,high(TermoExterior)	
         Ldi zl,low(TermoExterior)
         St z+,r17
         St z,r16
         CALL	DESARMAR_ENVIAR
         RJMP FinGuardar


guardarADC3:		;ADC3 LUXOMETRO DORMITORIO
	     LDS	R22,ADCL	;ADC3, ADC4 y ADC5 son para el luxometro
         LDS	R23,ADCH
         MOVW	R16,R22

         Ldi zh,high(LuxoDormi)	
         Ldi zl,low(LuxoDormi)
         St z+,r17
         St z,r16

         MOVW	R24,R16

         CALL	DESARMAR_ENVIAR
         RJMP FinGuardar


guardarADC4:		;ADC4 LUXOMETRO ESTAR, COCINA, COMEDOR
	     LDS	R24,ADCL
         LDS	R25,ADCH
         MOVW	R16,R24

         Ldi zh,high(LuxoCocinaComedor)	
         St z+,r17
         St z,r16

         MOVW	R24,R16

         CALL	DESARMAR_ENVIAR
         RJMP FinGuardar

guardarADC5:		;ADC5 LUXOMETRO EXTERIOR
         LDS	R26,ADCL
         LDS	R27,ADCH
     
         MOVW	R16,R26

         Ldi zh,high(LuxoExterior)	
         Ldi zl,low(LuxoExterior)
         St z+,r17
         St z,r16

         MOVW	R24,R16

         CALL	DESARMAR_ENVIAR
		 */
/*DESARMAR_ENVIAR:
LDI	R23,HIGH(1000)
LDI	R22,LOW(1000)
CALL	DIVISION16
MOV	R20,R24
CALL	ENVIO_UART
MOVW	R24,R26
LDI	R23,HIGH(100)
LDI	R22,LOW(100)
CALL	DIVISION16
MOV	R20,R24
CALL	ENVIO_UART
MOVW	R24,R26
LDI	R23,0
LDI	R22,10
CALL	DIVISION16
MOV	R20,R24
CALL	ENVIO_UART
MOV	R20,R26
CALL	ENVIO_UART
LDI	R20,10
CALL	ESPERAR_TX
LDI	R20,13
CALL	ESPERAR_TX
RET
; División por 16 bits
; DIVIDENDO -> R24:R25
; DIVISOR   -> R23:R22
; RESTO		-> R27:R26
; COCIENTE	-> A lo largo del algoritmo se modifica el DIVIDENDO y el COCIENTE queda en R24:R25
; R21 también es modificado en el desarrollo de la operación
DIVISION16:
		SUB		R26,R26		
		SUB		R27,R27		
		LDI		R21,0x11		 
		RJMP	SEGUIR16		 
VOLVER16:		
		ROL		R26		
		ROL		R27		
		CP		R26,R22		 
		CPC		R27,R23		 
		BRCS	SEGUIR16		
		SUB		R26,R22		 
		SBC		R27,R23		 
SEGUIR16:
		ROL		R24		 
		ROL		R25		 
		DEC		R21		 
		BRNE	VOLVER16		 
		COM		R24		 
		COM		R25		 
		RET 	
		*/