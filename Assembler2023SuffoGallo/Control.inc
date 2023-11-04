;Las acciones de control van acá
; las mismas se ejecutan en el menu options de "ApartadoGraficoCodes.inc"
; esto quiere decir que se ejecuta siempre y cuando el usuario no este modificando una de las variables de control,
; y que se ejecuta luego de que una se cambia.
; Metemos una equivalencia, para el código sea más comprensible
.equ AbrirCortinaDormitorio=PORTB7
.equ CerrarCortinaDormitorio=PORTB6
.equ AbrirCortinaLCC=PORTB5
.equ CerrarCortinaLCC=PORTB4
.equ CalefacionDormitorio=PORTB3
.equ CalefacionLCC=PORTB2
.equ RefrigeracionDormitorio=PORTB1
.equ RefrigeracionLCC=PORTB0
;------------------------------------------------------------
.equ NAbrirCortinaDormitorio=128
.equ NCerrarCortinaDormitorio=64
.equ NAbrirCortinaLCC=32
.equ NCerrarCortinaLCC=16
.equ NCalefacionDormitorio=8
.equ NCalefacionLCC=4
.equ NRefrigeracionDormitorio=2
.equ NRefrigeracionLCC=1
; Bastará con ponerlas en 1 para que nuestro codigo funcione
Lectura:                  //	Para leer el estado de Bit debemos tener en
		LDS R16,EstadoBit //	R17  el bit que queremos leer; le hacemos
		AND R17,R16		  //	un AND  para averiguar si se encuentra en
		RET				  //	0 o 1 ...
Control:				  //
		Call  IluminacionLCC
		Call  IluminacionDormitorio
		IN	R17, 	PINB
		STS EstadoBit,R17;Actualizamos el estado de bit
		ret

;=================================================
;|	   INCIO DE LAS SUBRUTINAS   DE   CONTROL    |
;=================================================
IluminacionLCC:
	LDS	R5, LuzExteriorMinimaABS
	LDS R18,MedLuzLCCABS
	CP R5,R18 ; Si la luz exterior es menor a la del interior, toodavia no es necesario
	BRLO  TodaviaNo; abrir las cortinas (Afuera está muy oscuro).
	LDS	R5, HoraInicioDiaABS ; si no es así, seguimos preguntando sobre el horario.
	LDS R18,HoraABS
	CP R18,R5
	BRSH ComenzoEldiaLCC ; La hora actual es mayor al Inicio del día? Entonces Inició el DIA
	CP r18,r5
	BRLO TodaviaNo  ; La hora actual es menor al Inicio del día? Entonces todavía no
RET
ComenzoEldiaLCC:
			LDS	R5, HoraFinDiaABS
			LDS R18,HoraABS
			CP r18,r5
			BRSH TodaviaNo ; La hora actual es mayor al fin del día? Entonces no hay que prender nada (Hay que apagar todo), terminó
			CP r18,r5	   ; el día.
			BRLO PreguntaRefrigeracion  ; La hora actual es menor al fin del día? Entonces hay que preguntar si 
			RET
TodaviaNo:
			CBI	PORTB, AbrirCortinaDormitorio ;Apagamos
			CBI	PORTB, AbrirCortinaLCC ;Apagamos 
			SBI	PORTB, CerrarCortinaDormitorio ;Prendemos
			SBI	PORTB, CerrarCortinaLCC ;Prendemos
			RET
PreguntaRefrigeracion:
					  LDI R17,NRefrigeracionLCC
					  Call Lectura
					  Cpi R17,NRefrigeracionLCC
					  BreQ ControlHisterisisIluminacionLCC ; Si el Bit se encuentra en 1,la refrigeración del ambiente esta prendida
					 									   ; y debemos hacer el  Control de  histerisis de su cortina, caso contrario
					  SBI	PORTB, AbrirCortinaLCC		   ;Abrimos  la cortina del Living/Comedor/Cocina
					  CBI	PORTB, CerrarCortinaLCC ; y nos aseguramos de que no se cierre
					  RET

ControlHisterisisIluminacionLCC:
								LDS R16,MedLuzLCCABS
								LDS R17,SetPointLuzLCCABS
								LDS R18,HisterisisLuzLCCABS
								LDI R25,0    ; COLOCAMOS UN 0 EN R25, LO USAREMOS PARA HACER CUENTAS
								ADD R25,R17  ; LE SUMAMOS EL SETPOINT
								ADD R25,R18  ;LE SUMAMOS LA HISTERISIS
								CP R16,R25   ; ¿Es la luz del ambiente  mayor al setpoint y su histerisis?
								BRSH CerrarCortinaLCCAhora ; Entonces hay  que cerrar la cortina
								LDI R25,0   ;Colocamos el 0 en R5
								ADD R25,R17 ; Le sumamos el setpoint
								SUB R25,R18 ; Al setpoint le restamos la Histerisis
								CP R25,R16   ; ¿Es el setpoint menos la histerirsis mayor que la medición actual? o lo que es igual ¿es la 
								            ; medicion menor a el setpoint menos su histerisis?
								BRSH AbrirCortinaLCCAhora; entonces es momento de abrir la cortina
								RET ;Caso contrario, no hacer nada (estamos en la banda diferencial).

CerrarCortinaLCCAhora:
					  CBI	PORTB, AbrirCortinaLCC ;Apagamos 
					  SBI	PORTB, CerrarCortinaLCC ;Prendemos
					  RET
AbrirCortinaLCCAhora:
					 SBI	PORTB, AbrirCortinaLCC ;Prendemos
					 CBI	PORTB, CerrarCortinaLCC ;Apagamos
					 RET

IluminacionDormitorio:
					  LDS	R5, LuzExteriorMinimaABS
					  LDS R18,MedLuzDormitorioABS
					  CP R5,R18 ; Si la luz exterior es menor a la del interior, toodavia no es necesario
					  BRLO  TodaviaNo; abrir las cortinas (Afuera está muy oscuro).
					  LDS	R5, HoraInicioDiaABS ; si no es así, seguimos preguntando sobre el horario.
					  LDS R18,HoraABS
					  CP R18,R5
					  BRSH ComenzoEldiaDormitorio ; La hora actual es mayor al Inicio del día? Entonces Inició el DIA
					  CP r18,r5
					  BRLO TodaviaNo  ; La hora actual es menor al Inicio del día? Entonces todavía no
					  RET
ComenzoEldiaDormitorio:
			LDS	R5, HoraFinDiaABS
			LDS R18,HoraABS
			CP r18,r5
			BRSH TodaviaNo ; La hora actual es mayor al fin del día? Entonces no hay que prender nada (Hay que apagar todo), terminó
			CP r18,r5	   ; el día.
			BRLO PreguntaRefrigeracionD  ; ¿La hora actual es menor al fin del día? Entonces hay que preguntar si 
			RET
PreguntaRefrigeracionD:
					  LDI R17,NRefrigeracionDormitorio
					  Call Lectura
					  Cpi R17,NRefrigeracionDormitorio
					  BreQ ControlHisterisisIluminacionD ; Si el Bit se encuentra en 1,la refrigeración del ambiente esta prendida
														   ; y debemos hacer el  Control de  histerisis de su cortina, caso contrario
					SBI	PORTB, AbrirCortinaDormitorio	   ;Abrimos  la cortina del Living/Comedor/Cocina
					CBI	PORTB, CerrarCortinaDormitorio	   ; y nos aseguramos de que no se cierre
					RET

ControlHisterisisIluminacionD:
								LDS R16,MedLuzDormitorioABS
								LDS R17,SetPointLuzDormitorioABS
								LDS R18,HisterisisLuzDormitorioABS
								LDI R25,0    ; COLOCAMOS UN 0 EN R25, LO USAREMOS PARA HACER CUENTAS
								ADD R25,R17  ; LE SUMAMOS EL SETPOINT
								ADD R25,R18  ;LE SUMAMOS LA HISTERISIS
								CP R16,R25   ; ¿Es la luz del ambiente  mayor al setpoint y su histerisis?
								BRSH CerrarCortinaLCCAhora ; Entonces hay  que cerrar la cortina
								LDI R25,0   ;Colocamos el 0 en R5
								ADD R25,R17 ; Le sumamos el setpoint
								SUB R25,R18 ; Al setpoint le restamos la Histerisis
								CP R25,R16   ; ¿Es el setpoint menos la histerirsis mayor que la medición actual? o lo que es igual ¿es la 
								            ; medicion menor a el setpoint menos su histerisis?
								BRSH AbrirCortinaDAhora; entonces es momento de abrir la cortina
								RET ;Caso contrario, no hacer nada (estamos en la banda diferencial).

CerrarCortinaDAhora:
					  CBI	PORTB, AbrirCortinaDormitorio ;Apagamos 
					  SBI	PORTB, CerrarCortinaDormitorio;Prendemos
					  RET
AbrirCortinaDAhora:
					 SBI	PORTB, AbrirCortinaLCC ;Prendemos
					 CBI	PORTB, CerrarCortinaLCC ;Apagamos
					 RET