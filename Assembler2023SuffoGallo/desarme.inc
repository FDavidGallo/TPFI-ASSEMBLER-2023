.def unidad = r23
.def decena = r22
.def centena = r24

LeerADC0:
	ldi R16,0b01000000
	lds R17,ADCSRA
	or R17,R16 
	sts ADCSRA,R17 
	ret	
EsperarADC:
	lds R17,ADCSRA
	sbrs R17,4
	jmp EsperarADC
	ldi R16,0b00010000
	lds R17,ADCSRA
	or R17,R16
	sts ADCSRA, R17
	RET

CicloLecturaADC0:
	call LeerADC 
	call EsperarADC
	lds r18,ADCL
	lds r19,ADCH
	ldi unidad,0
	ldi decena,0
	ldi centena,0
	mov R16,R11
	CALL ASCII
	ldi R26,48 
	add unidad,R26
	add decena,R26
	add centena,R26
	mov r16,centena
  /* ACA EMPEZARIMOS A CARGAR LOS DATOS.......................  STS */
ASCII:   ;Convertir los datos obtenidos a ASCII
	L_CENTENA:
		cpi r16,100
		BRLO L_DECENA
		inc centena
		subi r16,100
		rjmp L_CENTENA
	L_DECENA:
		cpi r16,10
		BRLO L_UNIDAD
		inc decena
		subi r16,10
		rjmp L_DECENA
	L_UNIDAD:
		cpi r16,1
		BRLO L_FIN
		inc unidad
		subi r16,1
		rjmp L_UNIDAD
	L_FIN:
		ret

	LeerADC:
			JMP LeerADC0