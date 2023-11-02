// Acá lo que hago es leer uno a uno los sensores y guardarlos en SRAM
//      Termometro Dormitorio>0>PC0(A0)
//		Termometro Living/Comedor/Cocina>1>PC0(A1)
//		Termometro Exterior>2>PC0(A2)
//		Luxómetro Dormitorio>3>PC0(A3)
//		Luxómetro Living/Comedor/Cocina>4>PC0(A4)
//		Luxómetro Exterior>5>PC5(A5)
// Total de mediciones a hacer: 6

Medir:
		Leer0:
			ldi r16,0b01100000 ; 5V del micro como referencia
			sts ADMUX, r16
			CALL InicioADC ;dirijase a:"LecturaAdc.inc"
				STS MedTemperaturaExteriorHH, centena
				STS MedTemperaturaExteriorH, decena
				STS MedTemperaturaExteriorL, unidad
				STS MedTemperaturaExteriorComa, R18 ;guardamos la coma
		Leer1:
			  ldi r16,0b01100001 ; 5V del micro como referencia
			sts ADMUX, r16
			  CALL InicioADC ;dirijase a:"LecturaAdc.inc"
			  STS MedTemperaturaLCCHH, centena
				STS MedTemperaturaLCCH, decena
				STS MedTemperaturaLCCL, unidad
				STS MedTemperaturaLCCComa, R18 
		Leer2:
			 ldi r16,0b01100010 ; 5V del micro como referencia
			sts ADMUX, r16
			  CALL InicioADC ;dirijase a:"LecturaAdc.inc"
			  STS MedTemperaturaDormitorioHH, centena
				STS MedTemperaturaDormitorioH, decena
				STS MedTemperaturaDormitorioL, unidad
				STS MedTemperaturaDormitorioComa, R18 ;guardamos la coma
		Leer3:
			 ldi r16,0b01100011 ; 5V del micro como referencia
			sts ADMUX, r16
			  CALL InicioADC ;dirijase a:"LecturaAdc.inc"
			    STS MedLuzLCCHH, centena
				STS MedLuzLCCH, decena
				STS MedLuzLCCL,unidad 
				STS MedLuzLCCDecena, R18 ;guardamos la coma
		Leer4:
			  ldi r16,0b01100100 ; 5V del micro como referencia
			sts ADMUX, r16
			  CALL InicioADC ;dirijase a:"LecturaAdc.inc"
			  STS MedLuzDormitorioHH, centena
				STS MedLuzDormitorioH, decena
				STS MedLuzDormitorioL,unidad 
				STS MedLuzDormitorioDecena, R18 ;guardamos la coma
		Leer4_medicion:
			  ldi r16,0b0110010 ; 5V del micro como referencia
			sts ADMUX, r16
			  CALL InicioADC ;dirijase a:"LecturaAdc.inc"
			   STS MedLuzExteriorHH, centena
			   STS MedLuzExteriorH, decena
			   STS MedLuzExteriorL,unidad 
			   STS MedLuzExteriorDecena, R18 ;guardamos la coma
	RET
		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
; ANTES DE UTILIZAR LAS FUNCIONES "Reconstruir", se debe cargar el puntero Z con la posición incial de lo que se desea pasar de ASCII a 
; decimal...
 ReconstruirMedicion: ; esta funcion agarra lo que se encuentra en 3 bits ASCII, para guardarle en 1, en decimal.
			 ; Numero:  r18-r19-r20  a guardar en  r17
			 ; Estos registros deben ser cargados por lo que está en Z0, Z1 y Z2, respectivamente
			 LDI R17,0
			 ld r18, Z
			 inc R30 ; Siguiente posición de z
			 ld r19, Z
			 inc R30 ; Siguiente posición de z
			 ld r20, Z
			 ;El procedimiento es el siguiente, explicado mediante un ejemplo:
			 ; '2' - '5' - '5'-> Comparece del 0 al 9,  sumese el valor correspondiente a R17
			 ReconstruirCentena:
			 Cpi R18,'1'
			 BREQ Cien		
			 Cpi R18,'2'
			 BREQ DOSCien
			 Ret
	  DOSCien:
							LDI R16,200
							ADD R17,R16
							rjmp ReconstruirDecena
      Cien:
							LDI R16,100
							ADD R17,R16
							rjmp ReconstruirDecena
			 ReconstruirDecena:
			 Cpi R19,'1'
			 BREQ Diezzz	  
			 Cpi R19,'2'
			 BREQ Veinte	 
			 Cpi R19,'3'
			 BREQ Trenta	 
			 Cpi R19,'4'
			 BREQ Cuarenta	 
			 Cpi R19,'5'
			 BREQ Cincuenta	  
			 Cpi R19,'6'
			 BREQ Sesenta	
			 Cpi R19,'7'
			 BREQ Setenta		
			 Cpi R19,'8'
			 BREQ Ochenta	
			 Cpi R19,'9'
			 BREQ Noventa
			 RET
Noventa:
							LDI R16,90
							ADD R17,R16
							rjmp ReconstruirUnidad
Diezzz:
							LDI R16,10
							ADD R17,R16
							rjmp ReconstruirUnidad
Veinte:
							LDI R16,20
							ADD R17,R16
							rjmp ReconstruirUnidad
Trenta:
							LDI R16,30
							ADD R17,R16
							rjmp ReconstruirUnidad
 Cuarenta:
							LDI R16,40
							ADD R17,R16
							rjmp ReconstruirUnidad
Cincuenta:
							LDI R16,50
							ADD R17,R16
							rjmp ReconstruirUnidad
Sesenta:
							LDI R16,60
							ADD R17,R16
							rjmp ReconstruirUnidad
Setenta:
							LDI R16,70
							ADD R17,R16
							rjmp ReconstruirUnidad
Ochenta:
							LDI R16,80
							ADD R17,R16
							rjmp ReconstruirUnidad
ReconstruirUnidad:
			 Cpi R20,'1'
			 BREQ Diezzzdiv10	  
			 Cpi R20,'2'
			 BREQ Veintediv10 
			 Cpi R20,'3'
			 BREQ Trentadiv10 
			 Cpi R20,'4'
			 BREQ Cuarentadiv10 
			 Cpi R20,'5'
			 BREQ Cincuentadiv10  
			 Cpi R20,'6'
			 BREQ Sesentadiv10
			 Cpi R20,'7'
			 BREQ Setentadiv10		
			 Cpi R20,'8'
			 BREQ Ochentadiv10	
			 Cpi R20,'9'
			 BREQ Noventadiv10
			 RET
Noventadiv10:
							LDI R16,9
							ADD R17,R16
							RET ; LISTO
Diezzzdiv10:
							LDI R16,1
							ADD R17,R16
							RET ; LISTO
Veintediv10:
							LDI R16,2
							ADD R17,R16
						    RET ; LISTO
Trentadiv10:
							LDI R16,3
							ADD R17,R16
							RET ; LISTO
 Cuarentadiv10:
							LDI R16,4
							ADD R17,R16
							RET ; LISTO
Cincuentadiv10:
							LDI R16,5
							ADD R17,R16
						    RET ; LISTO
Sesentadiv10:
							LDI R16,6
							ADD R17,R16
							RET ; LISTO
Setentadiv10:
							LDI R16,7
							ADD R17,R16
							RET ; LISTO
Ochentadiv10:
							LDI R16,5
							ADD R17,R16
							RET ; LISTO
			
ReconstruirConf: ; esta funcion agarra lo que se encuentra en 2 bits ASCII, para guardarle en 1, en decimal.
			 ; Numero:  r19-r20  a guardar en  r25
			  ; Estos registros deben ser cargados por lo que está en Z0 y Z1  respectivamente
			 ld r19, Z
			 inc R30 ; Siguiente posición de z
			 ld r20, Z
			 LDI R25,0			
			 ReconstruirDecena2:
			 Cpi R19,'1'
			 BREQ Diezzz2	  
			 Cpi R19,'2'
			 BREQ Veinte2	 
			 Cpi R19,'3'
			 BREQ Trenta2	 
			 Cpi R19,'4'
			 BREQ Cuarenta2	 
			 Cpi R19,'5'
			 BREQ Cincuenta2 
			 Cpi R19,'6'
			 BREQ Sesenta2	
			 Cpi R19,'7'
			 BREQ Setenta2		
			 Cpi R19,'8'
			 BREQ Ochenta2	
			 Cpi R19,'9'
			 BREQ Noventa2
			 RET
Noventa2:
							LDI R25,90
							ADD R17,R16
							rjmp ReconstruirUnidad2
Diezzz2:
							LDI R16,10
							ADD R25,R16
							rjmp ReconstruirUnidad2
Veinte2:
							LDI R16,20
							ADD R25,R16
							rjmp ReconstruirUnidad2
Trenta2:
							LDI R16,30
							ADD R25,R16
							rjmp ReconstruirUnidad2
 Cuarenta2:
							LDI R16,40
							ADD R25,R16
							rjmp ReconstruirUnidad2
Cincuenta2:
							LDI R16,50
							ADD R25,R16
							rjmp ReconstruirUnidad2
Sesenta2:
							LDI R16,60
							ADD R25,R16
							rjmp ReconstruirUnidad2
Setenta2:
							LDI R16,70
							ADD R25,R16
							rjmp ReconstruirUnidad2
Ochenta2:
							LDI R16,80
							ADD R25,R16
							rjmp ReconstruirUnidad2
ReconstruirUnidad2:
			 Cpi R20,'1'
			 BREQ Diezzzdiv102	  
			 Cpi R20,'2'
			 BREQ Veintediv102
			 Cpi R20,'3'
			 BREQ Trentadiv102 
			 Cpi R20,'4'
			 BREQ Cuarentadiv102 
			 Cpi R20,'5'
			 BREQ Cincuentadiv102  
			 Cpi R20,'6'
			 BREQ Sesentadiv102
			 Cpi R20,'7'
			 BREQ Setentadiv102		
			 Cpi R20,'8'
			 BREQ Ochentadiv102
			 Cpi R20,'9'
			 BREQ Noventadiv102
			 RET
Noventadiv102:
							LDI R16,9
							ADD R25,R16
							RET ; LISTO
Diezzzdiv102:
							LDI R16,1
							ADD R25,R16
							RET ; LISTO
Veintediv102:
							LDI R16,2
							ADD R25,R16
						    RET ; LISTO
Trentadiv102:
							LDI R16,3
							ADD R25,R16
							RET ; LISTO
 Cuarentadiv102:
							LDI R16,4
							ADD R25,R16
							RET ; LISTO
Cincuentadiv102:
							LDI R16,5
							ADD R25,R16
						    RET ; LISTO
Sesentadiv102:
							LDI R16,6
							ADD R25,R16
							RET ; LISTO
Setentadiv102:
							LDI R16,7
							ADD R25,R16
							RET ; LISTO
Ochentadiv102:
							LDI R16,5
							ADD R25,R16
							RET ; LISTO */