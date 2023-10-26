;Las acciones de control van acá
; las mismas se ejecutan en el menu options de "ApartadoGraficoCodes.inc"
; esto quiere decir que se ejecuta siempre y cuando el usuario no este modificando una de las variables de control,
; y que se ejecuta luego de que una se cambia.
Controll:
	    PUSH R5    ; ANTES DE HACER CUALQUIER COSA, GUARDAMOS EN PILA LO QUE SEA QUE ESTABA HACIENDO EL MICRO
		PUSH R12   ; ESTO LO HAGO EXCLUSIVAMENTE PARA PODER EMPLEAR LO MISMOS REGISTROS DE FORMA "INDEPENDIENTE"
		PUSH R16   ; ENTRE LA PARTE GRAFICA Y LA PARTE DE CONTROL
		PUSH R17
		PUSH R18
		PUSH R19
		PUSH R20
		PUSH R30 ; Estos dos resultan  de particular importancia, ya que: ZH:ZL son  R31:R30
		PUSH R31 ; puntero que se usa mucho en mi programa
		IN	R17,SREG ;
		PUSH	R17	 ; GUARDAMOS EN PILA EL REGISTRO DE ESTADO
		;ACA SENTENCIAS DE CONTROL ;) ---> EN DESARROLLO
		;	Devolvemos todo a su lugar
		POP R17
		OUT SREG,R17 ; DEVOLVEMOS EL REGISTRO DE ESTADO A SU LUGAR 
		POP R31 ; Por la naturaleza de la pila, se devuelven las cosas en orden inverso 
		POP R30
		POP R20
		POP R19
		POP R18
		POP R16
		POP R12
		POP R5
		JMP READ ;Volvemos al apartado gráfico

Control_Int:
	    PUSH R5    ; ANTES DE HACER CUALQUIER COSA, GUARDAMOS EN PILA LO QUE SEA QUE ESTABA HACIENDO EL MICRO
		PUSH R12   ; ESTO LO HAGO EXCLUSIVAMENTE PARA PODER EMPLEAR LO MISMOS REGISTROS DE FORMA "INDEPENDIENTE"
		PUSH R16   ; ENTRE LA PARTE GRAFICA Y LA PARTE DE CONTROL
		PUSH R17
		PUSH R18
		PUSH R19
		PUSH R20
		PUSH R30 ; Estos dos resultan  de particular importancia, ya que: ZH:ZL son  R31:R30
		PUSH R31 ; puntero que se usa mucho en mi programa
		IN	R17,SREG ;
		PUSH	R17	 ; GUARDAMOS EN PILA EL REGISTRO DE ESTADO
		;ACA SENTENCIAS DE CONTROL ;) ---> EN DESARROLLO
		;	Devolvemos todo a su lugar
		POP R17
		OUT SREG,R17 ; DEVOLVEMOS EL REGISTRO DE ESTADO A SU LUGAR 
		POP R31 ; Por la naturaleza de la pila, se devuelven las cosas en orden inverso 
		POP R30
		POP R20
		POP R19
		POP R18
		POP R16
		POP R12
		POP R5
		ret