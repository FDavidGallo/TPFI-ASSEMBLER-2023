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
			  Lds R5,0
			  ldi ZH, high(MedTemperaturaExteriorHH); Posicionamos Z en la primer variable de medición
			  CALL InicioADC ;dirijase a:"LecturaAdc.inc"
		Leer1:
			  Lds R5,1
			  ldi ZH, high(MedTemperaturaLCCHH); Posicionamos Z en la primer variable de medición
			  CALL InicioADC ;dirijase a:"LecturaAdc.inc"
		Leer2:
			  Lds R5,2
			  ldi ZH, high(MedTemperaturaDormitorioHH); Posicionamos Z en la primer variable de medición
			  CALL InicioADC ;dirijase a:"LecturaAdc.inc"
		Leer3:
			  Lds R5,3
			  ldi ZH, high(MedLuzLCCHH); Posicionamos Z en la primer variable de medición
			  CALL InicioADC ;dirijase a:"LecturaAdc.inc"
		Leer4:
			  Lds R5,4
			  ldi ZH, high(MedLuzDormitorioHH); Posicionamos Z en la primer variable de medición
			  CALL InicioADC ;dirijase a:"LecturaAdc.inc"
		Leer4_medicion:
			  Lds R5,5
			  ldi ZH, high(MedLuzExteriorHH); Posicionamos Z en la primer variable de medición
			  CALL InicioADC ;dirijase a:"LecturaAdc.inc"
		RET