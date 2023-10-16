; División por 16 bits
; DIVIDENDO -> R24:R25
; DIVISOR   -> R23:R22
; RESTO		-> R27:R26
; COCIENTE	-> A lo largo del algoritmo se modifica el DIVIDENDO y el COCIENTE queda en R24:R25
; R21 también es modificado en el desarrollo de la operación
/*DIVISION16:
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
		RET 	*/
