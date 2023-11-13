;Las acciones de control van acá
; las mismas se ejecutan en el menu options de "ApartadoGraficoCodes.inc"
; esto quiere decir que se ejecuta siempre y cuando el usuario no este modificando una de las variables de control,
; y que se ejecuta luego de que una se cambia.
; Metemos una equivalencia, para el código sea más comprensible
.equ AbrirCortinaDormitorio=PORTD6
.equ CerrarCortinaDormitorio=PORTD5
.equ AbrirCortinaLCC=PORTD4
.equ CerrarCortinaLCC=PORTD3
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
ControlLuz:	
			LDS R5, HoraABS
			LDS R16,HoraInicioDiaABS
		    CP r5,r16	
			Brsh InicioDia
            RET
InicioDia:
			LDS R5, MedLuzExteriorABS
			LDS R16,LuzExteriorMinimaABS
		    CP r5,r16	
			Brsh IluminacionOk
			RET
FinDia:
			CBI	PORTD, AbrirCortinaDormitorio ;Apagamos
			CBI	PORTD, AbrirCortinaLCC ;Apagamos 
			SBI	PORTD, CerrarCortinaDormitorio ;Prendemos
			SBI	PORTD, CerrarCortinaLCC ;Prendemos
			RET
IluminacionOk:
			SBI	PORTD, AbrirCortinaDormitorio ;Apagamos
			sBI	PORTD, AbrirCortinaLCC ;Apagamos 
			cBI	PORTD, CerrarCortinaDormitorio ;Prendemos
			cBI	PORTD, CerrarCortinaLCC ;Prendemos
				CALL PreguntarRefrigeracion
				CALL  ssalva 
			LDS R5, HoraABS
			LDS R16,HoraFinDiaABS
		    CP R5,R16	
			BrSH FinDia
			RET

			Frio:
; por defecto, cuando hay frio se prende la calefaccion, luego, si corresponde apagamos algo
SBI PORTB, CalefacionDormitorio
SBI PORTB, CalefacionLCC
CBI PORTB, RefrigeracionDormitorio
CBI PORTB, RefrigeracionLCC
LDI R17,'8'
STS IRefrigeracionDormitorio,R17
STS IRefrigeracionLCC,R17
Call CalorHDormitorio
Call  CalorHLCC
RET
Caloo:
; por defecto, cuando hay calor se prende la refrigeracion, luego, si corresponde apagamos algo
CBI PORTB, CalefacionDormitorio
CBI PORTB, CalefacionLCC
SBI PORTB, RefrigeracionDormitorio
SBI PORTB, RefrigeracionLCC
LDI R17,'F'
STS IRefrigeracionDormitorio,R17
STS IRefrigeracionLCC,R17
CALL FrioHDormitorio
CALL FrioHLCC 
RET
						
ControlTemp:
			LDS R5, MedTemperaturaExteriorABS
			LDS R16,TemperaturaExteriorMinimaABS
		    CP R5,R16	
			BrLO Frio
			LDS R5, MedTemperaturaExteriorABS
			LDS R16,TemperaturaExteriorMaximaABS
			 CP r16,R5
			BrLO Caloo
            RET
			RET
			RET


CalorHLCC:
								LDS R16,MedTemperaturaLCCABS
								LDS R17,SetPointTemperaturaLCCABS
								LDS R18,HisterisisTemperaturaLCCABS
								LDI R25,0    ; COLOCAMOS UN 0 EN R25, LO USAREMOS PARA HACER CUENTAS
								ADD R25,R17  ; LE SUMAMOS EL SETPOINT
								ADD R25,R18  ;LE SUMAMOS LA HISTERISIS
								CP R16,R25   ; ¿Es la TEMP del ambiente  mayor al setpoint y su histerisis?
								BRSH NOCalentarLCC ; Entonces hay  que apagar la calefaccion
								LDI R25,0   ;Colocamos el 0 en R5
								ADD R25,R17 ; Le sumamos el setpoint
								SUB R25,R18 ; Al setpoint le restamos la Histerisis
								CP R25,R16   ; ¿Es el setpoint menos la histerirsis mayor que la medición actual? o lo que es igual ¿es la 
								            ; medicion menor al setpoint menos su histerisis?
								BRSH CalentarLCC; Entonces hay que prender la calefaccion
								RET ;Caso contrario, no hacer nada (estamos en la banda diferencial).

CalentarLCC:
					  SBI	PORTB,CalefacionLCC  ;Prendemos
					  CBI	PORTB, RefrigeracionLCC ;Apagamos ¡No tiene sentido tener la calefaccion y el aire prendido!
					  LDI R17,'8'
					  STS IRefrigeracionLCC,R17
					  RET
NOCalentarLCC:
					 CBI	PORTB, CalefacionLCC ;Apagamos
					 RET
						
FrioHLCC:
LDS R16,MedTemperaturaLCCABS
								LDS R17,SetPointTemperaturaLCCABS
								LDS R18,HisterisisTemperaturaLCCABS
								LDI R25,0    ; COLOCAMOS UN 0 EN R25, LO USAREMOS PARA HACER CUENTAS
								ADD R25,R17  ; LE SUMAMOS EL SETPOINT
								ADD R25,R18  ;LE SUMAMOS LA HISTERISIS
								CP R16,R25   ; ¿Es la TEMP del ambiente  mayor al setpoint y su histerisis?
								BRSH PRefriLCC ; Entonces hay  que apagar la calefaccion
								LDI R25,0   ;Colocamos el 0 en R5
								ADD R25,R17 ; Le sumamos el setpoint
								SUB R25,R18 ; Al setpoint le restamos la Histerisis
								CP R25,R16   ; ¿Es el setpoint menos la histerirsis mayor que la medición actual? o lo que es igual ¿es la 
								            ; medicion menor a el setpoint menos su histerisis?
								BRSH ApagarRefriLCC; entonces es momento de abrir la cortina
								RET ;Caso contrario, no hacer nada (estamos en la banda diferencial).

PRefriLCC:
					  SBI	PORTB, RefrigeracionLCC ;Prendemos
					  CBI	PORTB, CalefacionLCC ;Apagamos ¡No tiene sentido tener la calefaccion y el aire prendido!
					  LDI R17,'F'
					  STS IRefrigeracionLCC,R17
					  RET
ApagarRefriLCC:
					 CBI	PORTB, RefrigeracionLCC ;Apagamos
					 LDI R17,'8'
				      STS IRefrigeracionLCC,R17
					 RET
	
				RET
FrioHDormitorio:

								LDS R16,MedTemperaturaDormitorioABS
								LDS R17,SetPointTemperaturaDormitorioABS
								LDS R18,HisterisisTemperaturaDormitorioABS
								LDI R25,0    ; COLOCAMOS UN 0 EN R25, LO USAREMOS PARA HACER CUENTAS
								ADD R25,R17  ; LE SUMAMOS EL SETPOINT
								ADD R25,R18  ;LE SUMAMOS LA HISTERISIS
								CP R16,R25   ; ¿Es la TEMP del ambiente  mayor al setpoint y su histerisis?
								BRSH PRefriDormitorio ; Entonces hay  que prender el aire
								LDI R25,0   ;Colocamos el 0 en R5
								ADD R25,R17 ; Le sumamos el setpoint
								SUB R25,R18 ; Al setpoint le restamos la Histerisis
								CP R25,R16   ; ¿Es el setpoint menos la histerirsis mayor que la medición actual? o lo que es igual ¿es la 
								            ; medicion menor al setpoint menos su histerisis?
								BRSH ApagarRefriDormitorio; entonces es momento de abrir la cortina
								RET ;Caso contrario, no hacer nada (estamos en la banda diferencial).

PRefriDormitorio:
					  SBI	PORTB,RefrigeracionDormitorio  ;Prendemos
					  CBI	PORTB, CalefacionDormitorio ;Apagamos ¡No tiene sentido tener la calefaccion y el aire prendido!
					  LDI R17,'F'
STS IRefrigeracionDormitorio,R17
					  RET
ApagarRefriDormitorio:
					 CBI	PORTB, RefrigeracionDormitorio ;Apagamos
					 LDI R17,'8'
STS IRefrigeracionDormitorio,R17
					 RET
 CalorHDormitorio:
								 LDS R16,MedTemperaturaDormitorioABS
								LDS R17,SetPointTemperaturaDormitorioABS
								LDS R18,HisterisisTemperaturaDormitorioABS
								LDI R25,0    ; COLOCAMOS UN 0 EN R25, LO USAREMOS PARA HACER CUENTAS
								ADD R25,R17  ; LE SUMAMOS EL SETPOINT
								ADD R25,R18  ;LE SUMAMOS LA HISTERISIS
								CP R16,R25   ; ¿Es la TEMP del ambiente  mayor al setpoint y su histerisis?
								BRSH NOCalentarDormitorio ; Entonces hay  que apagar la calefaccion
								LDI R25,0   ;Colocamos el 0 en R5
								ADD R25,R17 ; Le sumamos el setpoint
								SUB R25,R18 ; Al setpoint le restamos la Histerisis
								CP R16,R25   ; ¿Es el setpoint menos la histerirsis mayor que la medición actual? o lo que es igual ¿es la 
								            ; medicion menor al setpoint menos su histerisis?
								BRLO CalentarDormitorio; Entonces hay que prender la calefaccion
								RET ;Caso contrario, no hacer nada (estamos en la banda diferencial).
			
			NOCalentarDormitorio:
			CBI PORTB, CalefacionDormitorio
			RET
			CalentarDormitorio:
			sBI PORTB, CalefacionDormitorio
			CBI	PORTB,RefrigeracionDormitorio  ; APGAMOS
			LDI R17,'8'
			STS IRefrigeracionDormitorio,R17
			RET
	
	PreguntarRefrigeracion:
	lds r17,IRefrigeracionDormitorio
	cpi r17,'F'
	BREQ LuzHDormitorio
	ssalva:
	lds r17,IRefrigeracionLCC
	cpi r17,'F'
	BREQ LuzHLCC
	RET				


	LuzHDormitorio:
	LDS R16,MedLuzDormitorioABS
								LDS R17,SetPointLuzDormitorioABS
								LDS R18,HisterisisLuzDormitorioABS
								LDI R25,0    ; COLOCAMOS UN 0 EN R25, LO USAREMOS PARA HACER CUENTAS
								ADD R25,R17  ; LE SUMAMOS EL SETPOINT
								ADD R25,R18  ;LE SUMAMOS LA HISTERISIS
								CP R25,R16   ; ¿Es la luz del ambiente  mayor al setpoint y su histerisis?
								BRLO CerrarCortinaDAhora ; Entonces hay  que cerrar la cortina
								LDI R25,0   ;Colocamos el 0 en R5
								ADD R25,R17 ; Le sumamos el setpoint
								SUB R25,R18 ; Al setpoint le restamos la Histerisis
								CP R25,R16   ; ¿Es el setpoint menos la histerirsis mayor que la medición actual? o lo que es igual ¿es la 
								            ; medicion menor a el setpoint menos su histerisis?
								BRSH AbrirCortinaDAhora; entonces es momento de abrir la cortina
								rjmp ssalva ;Caso contrario, no hacer nada (estamos en la banda diferencial).

CerrarCortinaDAhora:
					  CBI	PORTD, AbrirCortinaDormitorio ;Apagamos 
					  SBI	PORTD, CerrarCortinaDormitorio;Prendemos
					  rjmp ssalva 
AbrirCortinaDAhora:
					 SBI	PORTD, AbrirCortinaLCC ;Prendemos
					 CBI	PORTD, CerrarCortinaLCC ;Apagamos
					 RET
					rjmp ssalva 

    LuzHLCC:
								LDS R16,MedLuzLCCABS
								LDS R17,SetPointLuzLCCABS
								LDS R18,HisterisisLuzLCCABS
								LDI R25,0    ; COLOCAMOS UN 0 EN R25, LO USAREMOS PARA HACER CUENTAS
								ADD R25,R17  ; LE SUMAMOS EL SETPOINT
								ADD R25,R18  ;LE SUMAMOS LA HISTERISIS
								CP R25,R16   ; ¿Es la luz del ambiente  mayor al setpoint y su histerisis?
								BRLO CerrarCortinaLCCAhora ; Entonces hay  que cerrar la cortina
								LDI R25,0   ;Colocamos el 0 en R5
								ADD R25,R17 ; Le sumamos el setpoint
								SUB R25,R18 ; Al setpoint le restamos la Histerisis
								CP R25,R16   ; ¿Es el setpoint menos la histerirsis mayor que la medición actual? o lo que es igual ¿es la 
								            ; medicion menor a el setpoint menos su histerisis?
								BRSH AbrirCortinaLCCAhora; entonces es momento de abrir la cortina
								RET ;Caso contrario, no hacer nada (estamos en la banda diferencial).

CerrarCortinaLCCAhora:
					  CBI	PORTD, AbrirCortinaLCC ;Apagamos 
					  SBI	PORTD, CerrarCortinaLCC ;Prendemos
					  RET
AbrirCortinaLCCAhora:
					 SBI	PORTD, AbrirCortinaLCC ;Prendemos
					 CBI	PORTD, CerrarCortinaLCC ;Apagamos
					 RET

			 RET