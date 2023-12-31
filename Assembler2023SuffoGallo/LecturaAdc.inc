;"LecturaAdc.inc", documentado y hecho por David Gallo,para todo el que quiera usarlo,
; para el microcontrolador Atmega328p, IDE: Microchip Studio.
; Para incluir esto: >.include "LecturaAdc.inc"<, para llamarlo: >CALL InicioADC <
; Esto esta dise�ado para leer una de las entradas analogicas
; Este algoritmo lo que hace es  ir cargando en las posiciones de Z (tres seguidas)
;  los valores  del adc (Conversor analogico digital) del Atmega328p.
;   Atenci�n, antes de entrar en/llamar a  esto, debes tener cargado:
;			>Z en la posici�n de memoria flash inicial (si ten�s miedo de sobreescritura entre datos us� separadores)
;			>El sensor usado (de 0 a 6) en R5
;           >El ADC configurado de la siguiente manera:
;																ldi r16,0b01100000
;																sts ADMUX, r16
;																ldi r16,0b10000111
;																sts ADCSRA, r16
; Es preciso tambien que los sensores est�n conectados, como m�ximo, a 5V, y m�nimo a 0 V.									
;	Por el resto de los registros no te preocupes, ya que esta dise�ado para que se reestauren al  terminar...
; Prest� atenci�n: Si bien estamos usando "la mayor presici�n posible",
; debe tenerse en cuenta que no se usar�n los n�meros de 0000 a 1024 SINO QUE
;  se usa un sistema para leer, como m�ximo valor 255,7 (5) (el 5 se ha redondeado a 0) o, cambiando la coma  de lugar, 2557;
; si te sirve usalo.
;  Al terminar la ejecuci�n tendremos: Z='centena', Z+1='decena', Z+2='unidad', Z=R18 (la coma); guardados todos
;					   en formato ASCII TEN� EN CUENTA ESO--> Numeros Normales (/ARABIGOS/Decimales)= ASCII - 48
; by: Gallito, aguante el software libre (?)

.def unidad = r20
.def decena = r21
.def centena = r22

InicioADC:

;			jmp GuardarCosasAdc ;Guardamos lo que hac�a el micro
							 ;Setemos todo a 0:
								 InicioADC2:
			ldi unidad,0
			ldi decena, 0
			ldi centena,0
			ldi R18,0
			ldi r16, 0b00000000 ;Opcional, limpiar el puerto D
			out DDRC, r16
			rjmp CICLO_ADC ;Este es nuestro ciclo de conversi�n

CICLO_ADC:
	call LeerADC
	call EsperarADC
	lds r18,ADCL ;Cargamos en R18 la parte Baja del ADC, contiene los dos bits menos significativos o nuestra "COMA"
	lds r19,ADCH ;Cargamos en R18 la parte alta del ADC , contiene los 8 bits m�s significativo, va de 000 a 255
	ldi unidad,0
	ldi decena,0
	ldi centena,0
	mov r16,r19; Metemos a R16 ADCL
	call ASCII		; Llamamos a la funci�n ASCII 
	ldi r17,48		; le sumamos la diferencia entre el ASCII Y DECIMAL, PARA QUE SE GUARDE EN ASCII
	add unidad, r17
	add decena, r17
	add centena,r17
	; Ahora, teniendo todo en ASCII, pasamos a guardarlas una por una en la memoria:

	ret; Que largue todo y volvamos a lo que estaba haciendo el micro

ASCII: ;Vamos a obtener unidad, decena, centena y "Coma":
		L_CENTENA:
				cpi r16,100  ; �El numero es menor a 100?
				BRLO L_DECENA; Vaya a "L_Decena"
				inc centena  ; Si no es as�, incremente en uno las centenas
				subi r16,100 ; Restele 100 al n�mero
				rjmp L_CENTENA ;Repita, hasta que el numero sea menor a 100
				;Si todo fue realizarse correctamente, solamente podr� ejecutarse todo dos veces
				; Recuerde: en 8 bits, el n�mero m�s grande a almacenar es el 256, contando el 0, 255.
		L_DECENA: ;Hace exactamente lo mismo que el anterior, solo que 100 en lugar de 10
				cpi r16,10 
				BRLO L_UNIDAD
				inc decena
				subi r16,10
				rjmp L_DECENA
		L_UNIDAD: ;Idem con 1
				cpi r16,1
				BRLO L_FIN ; Esta indica que se termin� de leer la parte baja del ADC
				inc unidad
				subi r16,1
				rjmp L_UNIDAD
		L_FIN:
				RJMP HCOMA; Leemos lo que est� en la parte alta, nuestra "COMA"
	    HCOMA:  ; Ahora, en la parte alta de la parte alta, tendremos nuestro "cuarto" de numero
				; por lo que lo usaremos para guardar >0,00 >0,25 >0,50 >0,75
				; por simplicidad, se los redonde� hacia abajo: >0,0 >0,2 >0,5 >0,7
				cpi r18,192 ; �El numero es 11 00 00 00?
				breq tres
				cpi r18,128; �El numero es 10 00 00 00?
				breq dos
				cpi r18,64 ; �El numero es 01 00 00 00?
				breq uno
				cpi r18,0 ; �El numero es 00 00 00 00?
				breq cerooo
				jmp Main ; Vuelva a CICLO_ADC
tres:
		ldi r18, '7' ; Guarde el valor correspondiente en ascii ah�
		ret ; Vuelva a CICLO_ADC
dos:
		ldi r18, '5' ; Guarde el valor correspondiente en ascii ah�
		ret ; Vuelva a CICLO_ADC
uno:
		ldi r18, '2' ; Guarde el valor correspondiente en ascii ah�
		ret ; Vuelva a CICLO_ADC
cerooo:
		ldi r18, '0' ; Guarde el valor correspondiente en ascii ah�
		ret ; Vuelva a CICLO_ADC

//////////////////////////////////////////////////////////////////
;		FUNCIONES	DE	CONTROL	DE "INDEPENDENCIA"	VIA	PILA: 
//////////////////////////////////////////////////////////////////
 ;GuardarCosasAdc: ; Para que puedas usar esto sin modificar los registros de tu programa  y que
			   ; sea 'Independiente' guardamos lo que el micro eVolvemos a lo que estaba haciendo el micro 

///////////////////////////////////////////
;		FUNCIONES	DE	CONTROL	DEL	ADC: 
///////////////////////////////////////////

LeerADC:
ldi r16,0b01000000 ; El bit pa' leer siempre debe estar activo
lds r17,ADCSRA
or r17,r16   
sts ADCSRA, r17
ret

EsperarADC:
lds r17, ADCSRA 
sbrs r17,4 ; �Recepci�n del ADC completa?
jmp EsperarADC ; Si no es as�, espere.
ldi r16,0b00010000
lds r17, ADCSRA
or r17,r16
sts ADCSRA, r17
ret
