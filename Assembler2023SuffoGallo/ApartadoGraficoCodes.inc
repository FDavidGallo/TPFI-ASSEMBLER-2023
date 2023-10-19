;Inicio de los menús, en su funcionamiento
.CSEG
MAIN:
	LDI ZH, HIGH(TABLA_ROM_MSJ <<1)	;Apunto hacia la tabla con MENSAJE
	LDI ZL, LOW(TABLA_ROM_MSJ <<1)


LOOP:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOP	
	RET
END_MESSAGE:


READ:
	LDS R16,UCSR0A  
	SBRS R16,RXC0	    ;Verifico si se recibio algun mensaje	
	RJMP READ			
OPTIONS:                
	LDS R18,UDR0        ;Leo el dato recibido y comparo
	LDI R17,1
	STS UCSR0A,R17
	CPI R18, 0x31			
	BREQ ENCENDER_UNO		
	CPI R18, 0x32			
	BREQ ENCENDER_DOS		
	CPI R18, 0x33			
	BREQ ENCENDER_TRES	
	CPI R18, 0x34			
	BREQ ENCENDER_CUATRO	
	CPI R18, 0x35			
	BREQ MAIN
	CPI R18,'A'
	BREQ PresionoA
	CPI R18,'B'
	BREQ PresionoB
	CPI R18,'C'
	BREQ PresionoC
	CPI R18,'D'
	BREQ PresionoD
	CPI R18,'E'
	BREQ PresionoE
	CPI R18,'F'
	BREQ PresionoF
	CPI R18,'G'
	BREQ PresionoG
	CPI R18,'H'
	BREQ PresionoH
	CPI R18,'I'
	BREQ PresionoI
	CPI R18,'J'
	BREQ PresionoJ
	CPI R18,'K'
	BREQ PresionoK
	CPI R18,'M'
	BREQ PresionoM
	CPI R18,'L'
	BREQ PresionoL
	CPI R18,'O'
	BREQ PresionoO
	RJMP READ			
	ENCENDER_UNO:
	JMP ENCENDER_UNOLEJOS	
	ENCENDER_DOS:
	JMP ENCENDER_DOSLEJOS
	ENCENDER_TRES:
	JMP ENCENDER_TRESLejos
	ENCENDER_CUATRO:
	JMP ENCENDER_CUATROLEJOS
	PresionoA:
	JMP PresionoALejos
	PresionoB:
	JMP PresionoBLejos
	PresionoC:
	JMP PresionoCLejos
	PresionoD:
	JMP PresionoDLejos
	PresionoE:
	JMP PresionoELejos
	PresionoF:
	JMP PresionoFLejos
	PresionoG:
	JMP PresionoGLejos
	PresionoH:
	JMP PresionoHLejos
	PresionoI:
	JMP PresionoILejos
	PresionoJ:
	JMP PresionoJLejos
	PresionoK:
	JMP PresionoKLejos
	PresionoM:
	JMP PresionoMLejos
	PresionoL:
	JMP PresionoLLejos
	PresionoO:
	JMP PresionoOLejos
	END_MESSAGE1:
	JMP Options
ENCENDER_UNOLEJOS:	
	LDI ZH, HIGH(TABLA_ROM_MSJ2 <<1)	;Apunto hacia la tabla con MENSAJE
	LDI ZL, LOW(TABLA_ROM_MSJ2 <<1)
	
LOOP_1:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE1	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT1:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT1		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOP_1	
	

ENCENDER_CUATROLEJOS:
	JMP ENCENDER4		
	JMP APAGAR4

ENCENDER_DOSLEJOS:
    LDI ZH, HIGH(TABLA_ROM_MSJ3 <<1)	;Apunto hacia la tabla con MENSAJE
	LDI ZL, LOW(TABLA_ROM_MSJ3 <<1)
	CALL LOOP2
LOOP2:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ MostrarConfiguraciones	;Si termino la lectura se manda el siguiente mensaje
TRANSMI2T:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMI2T		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOP2
MostrarConfiguraciones:
	 LDI R20, 'A'; Hasta aca bien
	 CALL ESPERAR_TX
	 LDI R20, '_'
	 CALL ESPERAR_TX
	 ldi ZH, high(TemperaturaExteriorMinimaH)
     ldi ZL, low(TemperaturaExteriorMinimaH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(TemperaturaExteriorMinimaL)
     ldi ZL, low(TemperaturaExteriorMinimaL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 LDI R20, 13
	 CALL ESPERAR_TX
	 LDI R20, 10
	 CALL ESPERAR_TX
	 LDI R20, 'B'; Hasta aca bien
	 CALL ESPERAR_TX
	 LDI R20, '_'
	 CALL ESPERAR_TX
	 ldi ZH, high(TemperaturaExteriorMaximaH)
     ldi ZL, low(TemperaturaExteriorMaximaH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(TemperaturaExteriorMaximaL)
     ldi ZL, low(TemperaturaExteriorMaximaL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ; SEGUIMOS CON EL RESTo (?)
	 LDI R20, 32 
	 CALL ESPERAR_TX
	 LDI R20, 32
	 CALL ESPERAR_TX
	 LDI R20, 'C'; ACA ERROR DE SOBREESCRITURA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	 CALL ESPERAR_TX
	 LDI R20, '_'
	 CALL ESPERAR_TX
	ldi ZH, high(TemperaturaLCCMinimaH)
     ldi ZL, low(TemperaturaLCCMinimaH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(TemperaturaLCCMinimaL)
     ldi ZL, low(TemperaturaLCCMinimaL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ; SEGUIMOS CON EL RESTo (?)
	 LDI R20, 32 
	 CALL ESPERAR_TX
	 LDI R20, 32
	 CALL ESPERAR_TX
	  LDI R20, 'D'; Hasta aca bien                                   BIEN
	 CALL ESPERAR_TX
	 LDI R20, '_'
	 CALL ESPERAR_TX
	ldi ZH, high(TemperaturaLCCMaximaH)
     ldi ZL, low(TemperaturaLCCMaximaH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(TemperaturaLCCMaximaL)
     ldi ZL, low(TemperaturaLCCMaximaL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 jmp READ
ESPERAR_TX:
	  LDS  R16,UCSR0A
	  SBRS R16,UDRE0
	  RJMP ESPERAR_TX
	  STS  UDR0,R20
	  RET

/*ENCENDER2:
	RJMP READ
APAGAR2:
	RJMP READ*/
	/*MostrarConfiguracion:
	 LDI R20, 'A'
	 CALL ESPERAR_TX
	 LDI R20, '_'
	 CALL ESPERAR_TX
	 ldi ZH, high(TemperaturaExteriorMinimaH)
     ldi ZL, low(TemperaturaExteriorMinimaH)
	 ld r16, Z
	 sts UDR0, r16
	 CALL TRANSMMITF
	 ldi ZH, high(TemperaturaExteriorMinimaL)
     ldi ZL, low(TemperaturaExteriorMinimaL)
	 ld r16, Z
	 sts UDR0, r16
	 CALL TRANSMMITF
	 ; SEGUIMOS CON EL RESTo (?)*/
ENCENDER_TRESLejos:	
	RJMP ENCENDER3			
	RJMP APAGAR3
ENCENDER3:
	CALL DELAY
	RJMP READ
APAGAR3:
	CALL DELAY
	RJMP READ
PresionoALejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPA

LOOPA:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2A	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPA
	
END_MESSAGE2A: ;despues de mandar ese adorno:
READPresionoAL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoAL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
; Configura Z para apuntar a la dirección de memoria 0x0157.
 ldi ZH, high(TemperaturaExteriorMinimaH)
 ldi ZL, low(TemperaturaExteriorMinimaH)
 st Z, r5; Almacena el valor de R5 en la dirección de memoria 0x0157.

READPresionoAH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoAH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
ldi ZH, high(TemperaturaExteriorMinimaL)
 ldi ZL, low(TemperaturaExteriorMinimaL)
 st Z, r5
JMP MensajeFinalDeCambiodevalor
PresionoBLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOP3

LOOP3:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2B	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT_A:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT_A		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOP3	
END_MESSAGE2B:	
 ;despues de mandar ese adorno:
READPresionoBL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoBL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
ldi ZH, high(TemperaturaExteriorMaximaH)
 ldi ZL, low(TemperaturaExteriorMaximaH)
 st Z, r5
READPresionoBH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoBH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	ldi ZH, high(TemperaturaExteriorMaximaL)
	ldi ZL, low(TemperaturaExteriorMaximaL)
	st Z, r5
	JMP MensajeFinalDeCambiodevalor
	PresionoCLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPC

LOOPC:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2C	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2C:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPC
	
END_MESSAGE2C: ;despues de mandar ese adorno:
READPresionoCL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoCL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	ldi ZH, high(TemperaturaLCCMinimaH)
	ldi ZL, low(TemperaturaLCCMinimaH)
	st Z, r5
READPresionoCH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoCH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	ldi ZH, high(TemperaturaLCCMinimaL)
	ldi ZL, low(TemperaturaLCCMinimaL)
	st Z, r5
	JMP MensajeFinalDeCambiodevalor
PresionoDLejos:
LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPD

LOOPD:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2D	;Si termino la lectura se manda el siguiente mensaje

TRANSMITD:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMITD		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPD
	
END_MESSAGE2D: ;despues de mandar ese adorno:
READPresionoDL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoDL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
ldi ZH, high(TemperaturaLCCMaximaH)
ldi ZL, low(TemperaturaLCCMaximaH)
 st Z, r5
READPresionoDH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoDH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
ldi ZH, high(TemperaturaLCCMaximaL)
ldi ZL, low(TemperaturaLCCMaximaL)
 st Z, r5
JMP MensajeFinalDeCambiodevalor
PresionoELejos:
LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPE

LOOPE:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2E	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2E:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2E		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPE
	
END_MESSAGE2E: ;despues de mandar ese adorno:
READPresionoEL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoEL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
ST Y, R5
READPresionoEH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoEH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
ST Y, R5
JMP MensajeFinalDeCambiodevalor
PresionoFLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPF

LOOPF:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2F	;Si termino la lectura se manda el siguiente mensaje

TRANSMITF:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMITF		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPF
	
END_MESSAGE2F: ;despues de mandar ese adorno:
READPresionoFL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoAL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
ST Y, R5
READPresionoFH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoFH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
ST Y, R5
JMP MensajeFinalDeCambiodevalor
PresionoGLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPG

LOOPG:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2G	;Si termino la lectura se manda el siguiente mensaje

TRANSMITG:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMITG		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPG
	
END_MESSAGE2G: ;despues de mandar ese adorno:
READPresionoGL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoGL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
ST Y, R5
READPresionoGH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoGH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
ST Y, R5
JMP MensajeFinalDeCambiodevalor
PresionoHLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPH

LOOPH:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2H	;Si termino la lectura se manda el siguiente mensaje

TRANSMITH:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMITH		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPH
	
END_MESSAGE2H: ;despues de mandar ese adorno:
READPresionoHL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoHL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
ST Y, R5
READPresionoHH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoHH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
ST Y, R5
JMP MensajeFinalDeCambiodevalor
PresionoILejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPI

LOOPI:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2I	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2I:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2I		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPI
	
END_MESSAGE2I: ;despues de mandar ese adorno:
READPresionoIL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoIL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	ST Y, R5
READPresionoIH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoIH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	ST Y, R5
	JMP MensajeFinalDeCambiodevalor
PresionoJLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPJ
LOOPJ:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2J	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2J:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2J		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPJ
	
END_MESSAGE2J: ;despues de mandar ese adorno:
READPresionoJL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoJL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	ST Y, R5
READPresionoJH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoJH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	ST Y, R5
	JMP MensajeFinalDeCambiodevalor
PresionoKLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPI

LOOPK:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2K	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2K:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2K		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPK
	
END_MESSAGE2K: ;despues de mandar ese adorno:
READPresionoKL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoKL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	ST Y, R5
READPresionoKH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoKH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	ST Y, R5
	JMP MensajeFinalDeCambiodevalor
PresionoMLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPM

LOOPM:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2M	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2M:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2M		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPM
	
END_MESSAGE2M: ;despues de mandar ese adorno:
READPresionoML: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoML   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	ST Y, R5
READPresionoMH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoMH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	ST Y, R5
	JMP MensajeFinalDeCambiodevalor
PresionoLLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPL

LOOPL:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2L	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2L:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2L		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPL
	
END_MESSAGE2L: ;despues de mandar ese adorno:
READPresionoLL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoLL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	ST Y, R5
READPresionoLH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoLH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	ST Y, R5
	JMP MensajeFinalDeCambiodevalor
PresionoOLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPO

LOOPO:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2O	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2O:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2O		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPO
	
END_MESSAGE2O: ;despues de mandar ese adorno:
READPresionoOL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoIL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	ST Y, R5
READPresionoOH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoOH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	LDI ZH, 0x03    ; Carga el byte alto (0x03) en el registro ZH
    LDI ZL, 0x78    ; Carga el byte bajo (0x78) en el registro ZL
	MOV R0,R5
	MOV R1,R5
	SPM

	JMP MensajeFinalDeCambiodevalor
END_MESSAGE2:
MensajeFinalDeCambiodevalor:
	LDI ZH, HIGH(CambioDeValor <<1)	;Apunto hacia la tabla con MENSAJEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	LDI ZL, LOW(CambioDeValor <<1)
	RJMP LOOP4

LOOP4:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE3	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT3:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT3		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOP4
	RET
READ4:
	LDS R16,UCSR0A  
	SBRS R16,RXC0	    ;Verifico si se recibio algun mensaje	
	RJMP READ4			
	JMP Options

ENCENDER4:
    CALL DELAY
	RJMP READ
APAGAR4:
	RJMP READ
	END_MESSAGE3:
	LDS R16,UCSR0A  
	SBRS R16,RXC0	    ;Verifico si se recibio algun mensaje	
	RJMP END_MESSAGE3			
	JMP Options

DELAY:
; Delay 60 000 cycles
; 3.75ms at 16.0 MHz
   LDI  R20, 60
   RET

