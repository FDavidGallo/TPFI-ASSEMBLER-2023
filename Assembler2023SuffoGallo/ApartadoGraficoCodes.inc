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
;JMP Controll ;>>>> EN DESARROLLO   TODAVIA  
;LA SIGUIENTE SECCIÓN CONTIENE EL "CORAZÓN" DEL PROGRAMA
; CON READ SE LEE SI SE ENVIÓ ALGO POR LA UART, OPTIONS 
READ:
	LDS R16,UCSR0A  
	SBRS R16,RXC0	    ;Verifico si se recibio algun mensaje	
	RJMP READ			
OPTIONS:         
	LDS R18,UDR0        ;Leo el dato recibido y comparo  
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
	CPI R18,'Q'
	BREQ PresionoQ
	CPI R18,'R'
	BREQ PresionoR		
	CPI R18,'S'
	BREQ PresionoS
	CPI R18,'P'
	BREQ PresionoP
	RJMP READ
	ENCENDER_UNO:
	JMP ENCENDER_UNOLEJOS	
	ENCENDER_DOS:
	JMP ENCENDER_DOSLEJOS
	ENCENDER_TRES:
	JMP ENCENDER_TRESLejos
	ENCENDER_CUATRO:
	JMP ENCENDER_CUATROLEJOS
	;JMP Controll ;>>>> EN DESARROLLO   TODAVIA  
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
	PresionoP:
	JMP PresionoPLejos
	PresionoQ:
	JMP PresionoQLejos
	PresionoR:
	JMP PresionoRLejos
	PresionoS:
	JMP PresionoSLejos
	END_MESSAGE1:
	JMP Options
ENCENDER_UNOLEJOS:	
	LDI ZH, HIGH(TABLA_ROM_MSJ2 <<1)	;Apunto hacia la tabla con MENSAJE
	LDI ZL, LOW(TABLA_ROM_MSJ2 <<1)
	
LOOP_1:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
   	;Si termino la lectura se manda el siguiente mensaje
	BREQ MMM
TRANSMIT1:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT1		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOP_1	
	MMM:
	 jmp MostrarMediciones

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
	 Call Guion
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
	 CALL Espacio
	 LDI R20, 'B'; Hasta aca bien
	 CALL ESPERAR_TX
	 CALL Guion
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
	 ; SEGUIMOS CON EL RESTO (?)
	 CALL Espacio
	 LDI R20, 'C'; 
	 CALL ESPERAR_TX
	 CALL Guion
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
	 CALL Salto
	  LDI R20, 'D'; Hasta aca bien                                   BIEN
	 CALL ESPERAR_TX
	 Call Guion
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
	 Call Espacio
	 ;-----------------------------------------------------------------------------------------
	  LDI R20, 'E'; Hasta aca bien
	 CALL ESPERAR_TX
	 Call Guion
	 ldi ZH, high(SetPointTemperaturaLCCH)
     ldi ZL, low(SetPointTemperaturaLCCH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(SetPointTemperaturaLCCL)
     ldi ZL, low(SetPointTemperaturaLCCL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 CALL Espacio
	 LDI R20, 'F';
	 CALL ESPERAR_TX
	 CALL Guion
	 ldi ZH, high(HisterisisTemperaturaLCCH)
     ldi ZL, low(HisterisisTemperaturaLCCH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(HisterisisTemperaturaLCCL)
     ldi ZL, low(HisterisisTemperaturaLCCL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 CALL Espacio
	 LDI R20, 'G'; 
	 CALL ESPERAR_TX
	 CALL Guion
	ldi ZH, high(TemperaturaDormitorioMaximaH)
     ldi ZL, low(TemperaturaDormitorioMaximaH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(TemperaturaDormitorioMaximaL)
     ldi ZL, low(TemperaturaDormitorioMaximaL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 CALL Salto
	  LDI R20, 'H'; 
	 CALL ESPERAR_TX
	 Call Guion
	ldi ZH, high(TemperaturaDormitorioMinimaH)
     ldi ZL, low(TemperaturaDormitorioMinimaH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(TemperaturaDormitorioMinimaL)
     ldi ZL, low(TemperaturaDormitorioMinimaL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 CALL Espacio
	   LDI R20, 'I'; 
	 CALL ESPERAR_TX
	 Call Guion
	 ldi ZH, high(SetPointTemperaturaDormitorioH)
     ldi ZL, low(SetPointTemperaturaDormitorioH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(TemperaturaExteriorMinimaL)
     ldi ZL, low(TemperaturaExteriorMinimaL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 CALL Espacio
	 LDI R20, 'J'; Hasta aca bien
	 CALL ESPERAR_TX
	 CALL Guion
	 ldi ZH, high(HisterisisTemperaturaDormitorioH)
     ldi ZL, low(HisterisisTemperaturaDormitorioH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(HisterisisTemperaturaDormitorioL)
     ldi ZL, low(HisterisisTemperaturaDormitorioL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 CALL Espacio
	 LDI R20, 'K'; 
	 CALL ESPERAR_TX
	 CALL Guion
	ldi ZH, high(LuzExteriorMinimaH)
     ldi ZL, low(LuzExteriorMinimaH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(LuzExteriorMinimaL)
     ldi ZL, low(LuzExteriorMinimaL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 CALL Cero
	 ; SEGUIMOS CON EL RESTo (?)
	 CALL Salto
	  LDI R20, 'M'; Hasta aca bien   
	 CALL ESPERAR_TX
	 Call Guion
	ldi ZH, high(SetPointLuzDormitorioH)
     ldi ZL, low(SetPointLuzDormitorioH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(SetPointLuzDormitorioL)
     ldi ZL, low(SetPointLuzDormitorioL)
	 ld r20, Z
	 sts UDR0, r20
	  CALL ESPERAR_TX
	  CALL Cero
	 Call Espacio
	   LDI R20, 'L'; 
	 CALL ESPERAR_TX
	 Call Guion
	ldi ZH, high(HisterisisLuzDormitorioH)
     ldi ZL, low(HisterisisLuzDormitorioH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(HisterisisLuzDormitorioL)
     ldi ZL, low(HisterisisLuzDormitorioL)
	 ld r20, Z
	 sts UDR0, r20
	  CALL ESPERAR_TX
	  CALL Cero
	  Call Espacio
	   LDI R20, 'O'; 
	 CALL ESPERAR_TX
	 Call Guion
	ldi ZH, high(SetPointLuzLCCH)
     ldi ZL, low(SetPointLuzLCCH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(SetPointLuzLCCL)
     ldi ZL, low(SetPointLuzLCCL)
	 ld r20, Z
	 sts UDR0, r20
	  CALL ESPERAR_TX
	  CALL Cero
	 Call Espacio
	  LDI R20, 'P';
	 CALL ESPERAR_TX
	 Call Guion
	ldi ZH, high(HisterisisLuzLCCH)
     ldi ZL, low(HisterisisLuzLCCH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(HisterisisLuzLCCL)
     ldi ZL, low(HisterisisLuzLCCL)
	 ld r20, Z
	 sts UDR0, r20
	  CALL ESPERAR_TX
	 CALL Cero
	 Call Espacio
	  LDI R20, 'Q'; 
	 CALL ESPERAR_TX
	 Call Guion
	ldi ZH, high(DecenaHoraInicioDia)
     ldi ZL, low(DecenaHoraInicioDia)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(UnidadHoraInicioDia)
     ldi ZL, low(UnidadHoraInicioDia)
	 ld r20, Z
	 sts UDR0, r20
	  CALL ESPERAR_TX
	  	  LDI R20, ':'; 
	 CALL ESPERAR_TX
	ldi ZH, high(DecenaMinutoInicioDia)
     ldi ZL, low(DecenaMinutoInicioDia)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(UnidadMinutoInicioDia)
     ldi ZL, low(UnidadMinutoInicioDia)
	 ld r20, Z
	 sts UDR0, r20
	  CALL ESPERAR_TX
	 Call Espacio
	  Call Espacio
	  LDI R20, 'R'; 
	 CALL ESPERAR_TX
	 Call Guion
	ldi ZH, high(DecenaHoraFinDia)
     ldi ZL, low(DecenaHoraFinDia)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(UnidadHoraFinDia)
     ldi ZL, low(UnidadHoraFinDia)
	 ld r20, Z
	 sts UDR0, r20
	  CALL ESPERAR_TX
	  LDI R20, ':'; 
	 CALL ESPERAR_TX
	 ldi ZH, high(DecenaMinutoFinDia)
     ldi ZL, low(DecenaMinutoFinDia)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(UnidadMinutoFinDia)
     ldi ZL, low(UnidadMinutoFinDia)
	 ld r20, Z
	 sts UDR0, r20
	  CALL ESPERAR_TX
	  CALL Salto
	    LDI R20, 'S'; 
	 CALL ESPERAR_TX
	 Call Guion
	 ldi ZH, high(DecenaHora)
     ldi ZL, low(DecenaHora)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(UnidadHora)
     ldi ZL, low(UnidadHora)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 LDI R20, ':'; 
	 CALL ESPERAR_TX
	ldi ZH, high(DecenaMinuto)
     ldi ZL, low(DecenaMinuto)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(UnidadMinuto)
     ldi ZL, low(UnidadMinuto)
	 ld r20, Z
	 sts UDR0, r20
	  CALL ESPERAR_TX
	 Call Espacio
	 jmp READ
ESPERAR_TX:
	  LDS  R16,UCSR0A
	  SBRS R16,UDRE0
	  RJMP ESPERAR_TX
	  STS  UDR0,R20
	  RET
ENCENDER_TRESLejos:	

	LDI ZH, HIGH(Datos <<1)	;
	LDI ZL, LOW(Datos <<1)
LOOP3D:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE3D	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT3D:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT3D		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOP3D
	RET
END_MESSAGE3D:
	JMP Options

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
 ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts TemperaturaExteriorMinimaABS,r5
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
 ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
LDS R16,TemperaturaExteriorMinimaABS
ADD R5,R16
 sts TemperaturaExteriorMinimaABS,r5
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
 ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts TemperaturaExteriorMaximaABS,r5
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
	ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
LDS R16,TemperaturaExteriorMaximaABS
ADD R5,R16
 sts TemperaturaExteriorMaximaABS,r5
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
	RJMP TRANSMIT2C		;Si no lo esta, se espera
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
	 ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts TemperaturaLCCMinimaABS,r5
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
	ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,TemperaturaLCCMinimaABS
	ADD R5,R16
	sts TemperaturaLCCMinimaABS,r5
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
  ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts TemperaturaLCCMaximaABS,r5
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
	ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,TemperaturaLCCMaximaABS
	ADD R5,R16
	sts TemperaturaLCCMaximaABS,r5
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
	ldi ZH, high(SetPointTemperaturaLCCH)
	ldi ZL, low(SetPointTemperaturaLCCH)
	st Z, r5
  ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts SetPointTemperaturaLCCABS,r5
READPresionoEH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoEH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	ldi ZH, high(SetPointTemperaturaLCCL)
	ldi ZL, low(SetPointTemperaturaLCCL)
	st Z, r5
	ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,HisterisisTemperaturaLCCABS
	ADD R5,R16
	sts HisterisisTemperaturaLCCABS,r5
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
    RJMP READPresionoFL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	ldi ZH, high(HisterisisTemperaturaLCCH)
	ldi ZL, low(HisterisisTemperaturaLCCH)
	st Z, r5
	;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts HisterisisTemperaturaLCCABS,r5
READPresionoFH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoFH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	ldi ZH, high(HisterisisTemperaturaLCCL)
	ldi ZL, low(HisterisisTemperaturaLCCL)
	st Z, r5
	;Guardamos la parte baja absoluta
	ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,HisterisisTemperaturaLCCABS
	ADD R5,R16
	sts HisterisisTemperaturaLCCABS,r5
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
	ldi ZH, high(TemperaturaDormitorioMaximaH)
	ldi ZL, low(TemperaturaDormitorioMaximaH)
	st Z, r5
	;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts TemperaturaDormitorioMaximaABS,r5
READPresionoGH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoGH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	ldi ZH, high(TemperaturaDormitorioMaximaL)
	ldi ZL, low(TemperaturaDormitorioMaximaL)
	st Z, r5
	
;Guardamos la parte baja absoluta
ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,TemperaturaDormitorioMaximaABS
	ADD R5,R16
	sts TemperaturaDormitorioMaximaABS,r5
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
	ldi ZH, high(TemperaturaDormitorioMinimaH)
	ldi ZL, low(TemperaturaDormitorioMinimaH)
	st Z, r5
	;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts TemperaturaDormitorioMinimaABS,r5

READPresionoHH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoHH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	ldi ZH, high(TemperaturaDormitorioMinimaL)
	ldi ZL, low(TemperaturaDormitorioMinimaL)
	st Z, r5
	;Guardamos la parte baja absoluta
    ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,TemperaturaDormitorioMinimaABS
	ADD R5,R16
	sts TemperaturaDormitorioMinimaABS,r5
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
	STS SetPointTemperaturaDormitorioH,R5
	;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts SetPointTemperaturaDormitorioABS,r5

READPresionoIH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoIH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	STS SetPointTemperaturaDormitorioL,R5
;Guardamos la parte baja absoluta
ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,SetPointTemperaturaDormitorioABS
	ADD R5,R16
	sts SetPointTemperaturaDormitorioABS,r5
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
   STS HisterisisTemperaturaDormitorioH,R5
   ;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts HisterisisTemperaturaDormitorioABS,r5

READPresionoJH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoJH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	STS HisterisisTemperaturaDormitorioL,R5
;Guardamos la parte baja absoluta
ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,HisterisisTemperaturaDormitorioABS
	ADD R5,R16
	sts HisterisisTemperaturaDormitorioABS,r5
	JMP MensajeFinalDeCambiodevalor
PresionoKLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPK

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
	STS LuzExteriorMinimaH,R5
;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts LuzExteriorMinimaABS,r5


READPresionoKH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoKH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	STS LuzExteriorMinimaL,R5
	
;Guardamos la parte baja absoluta
ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,LuzExteriorMinimaABS
	ADD R5,R16
	sts LuzExteriorMinimaABS,r5
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
	STS SetPointLuzDormitorioH,R5
	;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts SetPointLuzDormitorioABS,r5
READPresionoMH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoMH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	STS SetPointLuzDormitorioL,R5
	;Guardamos la parte baja absoluta
ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,SetPointLuzDormitorioABS
	ADD R5,R16
	sts SetPointLuzDormitorioABS,r5
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
	STS HisterisisLuzDormitorioH,R5
	;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts HisterisisLuzDormitorioABS,r5
READPresionoLH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoLH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	STS HisterisisLuzDormitorioL,R5
	;Guardamos la parte baja absoluta
ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,HisterisisLuzDormitorioABS
	ADD R5,R16
	sts HisterisisLuzDormitorioABS,r5
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
    RJMP READPresionoOL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
    ; Guardar R5 en la dirección de memoria 0x312.
	STS SetPointLuzLCCH,R5
	;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts SetPointLuzLCCABS,r5

READPresionoOH: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoOH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
    ; Guardar R5 en la dirección de memoria 0x312.
	STS SetPointLuzLCCL,R5
	;Guardamos la parte baja absoluta
	ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,SetPointLuzLCCABS
	ADD R5,R16
	sts SetPointLuzLCCABS,r5
	JMP Options
PresionoPLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LP

LP:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_P	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2P:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2P		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LP
	
END_P: ;despues de mandar ese adorno:
READPresionoPL: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoPL   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS HisterisisLuzLCCH,R5
	;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts HisterisisLuzLCCABS,r5
READPresionoPH:
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART.
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READPresionoPH   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART.
	; R5 contiene el valor que deseas guardar en la posición de memoria 0x312.
; Guardar R5 en la dirección de memoria 0x312.
	LDI ZH, 0x03    ; Carga el byte alto (0x03) en el registro ZH
    STS HisterisisLuzLCCL,R5
	;Guardamos la parte baja absoluta
ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,HisterisisLuzLCCABS
	ADD R5,R16
	sts HisterisisLuzLCCABS,r5
	JMP MensajeFinalDeCambiodevalor
	;<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<HORAS<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
PresionoQLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPQ

LOOPQ:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2Q	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2Q:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2Q		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPQ
	
END_MESSAGE2Q: ;despues de mandar ese adorno:
READDecenaHoraInicioDia: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READDecenaHoraInicioDia   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS DecenaHoraInicioDia,R5
	;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts HoraInicioDiaABS,r5
READUnidadHoraInicioDia: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READUnidadHoraInicioDia   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS UnidadHoraInicioDia,R5
	;Guardamos la parte baja absoluta
ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,HoraInicioDiaABS
	ADD R5,R16
	sts HoraInicioDiaABS,r5
	JMP MensajeFinalDeCambiodevalor
/*READDecenaMinutoInicioDia: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READDecenaMinutoInicioDia   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS DecenaMinutoInicioDia,R5
READUnidadMinutoInicioDia: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READUnidadMinutoInicioDia   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS UnidadMinutoInicioDia,R5
	JMP MensajeFinalDeCambiodevalor
	*/
PresionoRLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPR

LOOPR:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_MESSAGE2R	;Si termino la lectura se manda el siguiente mensaje

TRANSMIT2R:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMIT2R		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPR
	
END_MESSAGE2R: ;despues de mandar ese adorno:
READDecenaHoraFinDia: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READDecenaHoraFinDia   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS DecenaHoraFinDia,r5;Guardamos la parte alta absoluta
ldi r16,48
SUB r5, r16 ; lo quitamos de ASCII
 ldi r30,10
 mul r5,r30
 mov r5,r0
 sts HoraFinDiaABS,r5


READUnidadHoraFinDia: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READUnidadHoraFinDia   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS UnidadHoraFinDia,R5
	
;Guardamos la parte baja absoluta
ldi r16,48
	SUB r5, r16 ; lo quitamos de ASCII
	LDS R16,HoraFinDiaABS
	ADD R5,R16
	sts HoraFinDiaABS,r5
	JMP MensajeFinalDeCambiodevalor
/*READDecenaMinutoFinDia: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READDecenaMinutoFinDia   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS DecenaMinutoFinDia,R5
READUnidadMinutoFinDia: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READUnidadMinutoFinDia   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS UnidadMinutoFinDia,R5
	JMP MensajeFinalDeCambiodevalor
	*/
PresionoSLejos:
	LDI ZH, HIGH(CTEXTO <<1)	;Mandamos  que mande el numero 
	LDI ZL, LOW(CTEXTO <<1)
	RJMP LOOPSS

LOOPSS:
	LPM R17, Z+		;Se almacena el valor de la tabla ROM en R17
	CPI R17, 2	;Se compara con el caracter final
	BREQ END_SS	;Si termino la lectura se manda el siguiente mensaje

TRANSMITSS:
	LDS R16,UCSR0A
	SBRS R16,UDRE0		;Esta el buffer listo para transmitir?
	RJMP TRANSMITSS		;Si no lo esta, se espera
	STS UDR0,R17	
	RJMP LOOPSS
	
END_SS: ;despues de mandar ese adorno:
READDecenaHora: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READDecenaHora   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS DecenaHora,R5
	ldi r16,10
	mul r5,r16
	STS HoraABS,R1
READUnidadHora: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READUnidadHora ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS UnidadHora,R5
	lds r16,HoraABS
	ADD R16,R5
	STS HoraABS,R16
READDecenaMinuto: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READDecenaMinuto   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS DecenaMinuto,R5
READUnidadMinuto: ; leeemos
    LDS R16, UCSR0A   ; Cargar el registro de estado de la UART
    SBRS R16, RXC0    ; ¿Se ha recibido un carácter?
    RJMP READUnidadMinuto   ; Si no se ha recibido, espera.
    LDS R5, UDR0      ; Cargar el byte recibido en R5.
	STS UDR0, R5  ; Transmite el valor en R5 a través de la UART, para que veamos que metio el usuario
	; R5 contiene el valor q  ue deseas guardar en la posición de memoria 0x312
; Guardar R5 en la dirección de memoria 0x312.
	STS UnidadMinuto,R5
	JMP MensajeFinalDeCambiodevalor
END_MESSAGE2:
MensajeFinalDeCambiodevalor:
	LDI ZH, HIGH(CambioDeValor <<1)	;
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
	RJMP READ
APAGAR4:
	RJMP READ
	END_MESSAGE3:
	LDS R16,UCSR0A  
	SBRS R16,RXC0	    ;Verifico si se recibio algun mensaje	
	RJMP END_MESSAGE3			
	JMP Options
	jmp READ
MostrarMediciones:
	 LDI R20, 'T'; 
	 CALL ESPERAR_TX
	 Call Guion
	 ldi ZH, high(DecenaHora)
     ldi ZL, low(DecenaHora)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(UnidadHora)
     ldi ZL, low(UnidadHora)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 LDI R20, ':'; 
	 CALL ESPERAR_TX
	ldi ZH, high(DecenaMinuto)
     ldi ZL, low(DecenaMinuto)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(UnidadMinuto)
     ldi ZL, low(UnidadMinuto)
	 ld r20, Z
	 sts UDR0, r20
	  CALL ESPERAR_TX
	 Call Espacio
	 CALL Salto
	 LDI R20, 'U'; Hasta aca bien
	 CALL ESPERAR_TX
	 Call Guion
	  ldi ZH, high(MedTemperaturaExteriorHH)
     ldi ZL, low(MedTemperaturaExteriorHH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedTemperaturaExteriorH)
     ldi ZL, low(MedTemperaturaExteriorH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedTemperaturaExteriorL)
     ldi ZL, low(MedTemperaturaExteriorL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 Call Coma
	 ldi ZH, high(MedTemperaturaExteriorComa)
     ldi ZL, low(MedTemperaturaExteriorComa)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 CALL Espacio
	 Call Salto
	 LDI R20, 'V'; Hasta aca bien
	 CALL ESPERAR_TX
	 CALL Guion
	 ldi ZH, high(MedTemperaturaLCCHH)
     ldi ZL, low(MedTemperaturaLCCHH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedTemperaturaLCCH)
     ldi ZL, low(MedTemperaturaLCCH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedTemperaturaLCCL)
     ldi ZL, low(MedTemperaturaLCCL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 Call Coma
	 ldi ZH, high(MedTemperaturaLCCComa)
     ldi ZL, low(MedTemperaturaLCCComa)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 CALL Espacio
	 CALL Salto
	 ;---------------------------------------------------------->
	  LDI R20, 'W'; Hasta aca bien
	 CALL ESPERAR_TX
	 Call Guion
	 ldi ZH, high(MedTemperaturaDormitorioHH)
     ldi ZL, low(MedTemperaturaDormitorioHH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedTemperaturaDormitorioH)
     ldi ZL, low(MedTemperaturaDormitorioH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedTemperaturaDormitorioL)
     ldi ZL, low(MedTemperaturaDormitorioL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 Call Coma
	 ldi ZH, high(MedTemperaturaDormitorioComa)
     ldi ZL, low(MedTemperaturaDormitorioComa)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 CALL Salto
	 LDI R20, 'X'; Hasta aca bien
	 CALL ESPERAR_TX
	 CALL Guion
	  ldi ZH, high(MedLuzDormitorioHH)
     ldi ZL, low(MedLuzDormitorioHH)
	 ld r20, Z+
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedLuzDormitorioL)
     ldi ZL, low(MedLuzDormitorioL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedLuzDormitorioDecena)
     ldi ZL, low(MedLuzDormitorioDecena)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ;CALL Cero
	 CALL Espacio
	 Call Salto
	 LDI R20, 'Y'; Hasta aca bien
	 CALL ESPERAR_TX
	 CALL Guion
	  ldi ZH, high(MedLuzExteriorHH)
     ldi ZL, low(MedLuzExteriorHH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedLuzExteriorH)
     ldi ZL, low(MedLuzExteriorH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedLuzExteriorL)
     ldi ZL, low(MedLuzExteriorL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedLuzExteriorDecena)
     ldi ZL, low(MedLuzExteriorDecena)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ;CALL Cero
	 CALL Espacio
	 Call Salto
	 LDI R20, 'Z'; Hasta aca bien
	 CALL ESPERAR_TX
	 CALL Guion
	 ldi ZH, high(MedLuzLCCHH)
     ldi ZL, low(MedLuzLCCHH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedLuzLCCH)
     ldi ZL, low(MedLuzLCCH)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedLuzLCCL)
     ldi ZL, low(MedLuzLCCL)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ldi ZH, high(MedLuzLCCDecena)
     ldi ZL, low(MedLuzLCCDecena)
	 ld r20, Z
	 sts UDR0, r20
	 CALL ESPERAR_TX
	 ;CALL Cero
	 CALL Espacio
	 JMP Options
DELAY:
; Delay 60 000 cycles
; 3.75ms at 16.0 MHz
   LDI  R20, 60
   RET
;===========================================
;|    Elementos			gráficos		   |
;===========================================
Espacio:
     LDI R20, 32 
	 CALL ESPERAR_TX
	 LDI R20, 32
	 CALL ESPERAR_TX
   RET
Salto:
	 LDI R20, 13
	 CALL ESPERAR_TX
	 LDI R20, 10
	 CALL ESPERAR_TX
   RET
Guion:
	 LDI R20, '_'
	 CALL ESPERAR_TX
	 RET
Cero:
	 LDI R20, '0'
	 CALL ESPERAR_TX
	 RET
Coma:
	 LDI R20, ','
	 CALL ESPERAR_TX
	 RET