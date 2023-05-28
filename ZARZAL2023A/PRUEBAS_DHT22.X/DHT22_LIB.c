#include "DHT22_LIB.h"

uint8_t DHT22_ReadData(float *temperature, float *humidity) {
	
	uint8_t time_out=0;
	
	//CONFIGURAR EL PIN COMO SALIDA Y ESTABLECER EN ALTO 
	DHT22_DDR  |= (1 << DHT22_BIT);
	DHT22_PORT |= (1 << DHT22_BIT);
	
	// ESPERAMOS A QUE TERMINE DE INICIAR BIEN EL SENSOR
	_delay_ms(250);
	
	//SINCRONIZAMOS EL SENSOR DANDO EL PRIMER CERO
	DHT22_PORT &= ~(1 << DHT22_BIT);
	_delay_ms(18);
	
	//LUEGO ENVIAMOS EL PRIMER 1  Y ESPERAMOS QUE EL SENSOR RESPONDA
	DHT22_PORT |= (1 << DHT22_BIT);
	_delay_us(40);

	//COLOCAMOS EL PIN EN MODO ENTRADA PARA RECIBIR DATOS
	DHT22_DDR &= ~(1 << DHT22_BIT);
	
	//ESPERAMOS EL PRIMER 0 DE SINCRO
	while(  (DHT22_PIN & (1 << DHT22_BIT)  ) ){
		if(time_out>90){
			return ERROR_SINCRO1;
		}
		time_out++;
		_delay_us(1);	
	}
	time_out =0;
	
	//ESPERAMOS EL SEGUNDO 1 DE SINCRO
	while( !( DHT22_PIN & (1 << DHT22_BIT) ) ){
		if(time_out>90){
			return ERROR_SINCRO2;
		}
		time_out++;
		_delay_us(1);
	}
	
	//ESPERAMOS PARA COMENZAR A LEER EL DATO
	_delay_us(80);
	

	uint8_t data[5] = {0};
	uint8_t i, j;
			
	  for (j=0; j<5; j++){
		  uint8_t result=0;
		  for (i=0; i<8; i++){
			  while (!( DHT22_PIN & (1 << DHT22_BIT) ));
			  _delay_us(35);

			  if ( ( DHT22_PIN & (1 << DHT22_BIT) ))
			  result |= (1<<(7-i));
			  
			  while( ( DHT22_PIN & (1 << DHT22_BIT) ) );
		  }
		  data[j] = result;
	  }
	
	
	//REINICIAMOS LOS PINES PARA UNA PROXIMA LECTURA
	DHT22_DDR  |= (1 << DHT22_BIT);
	DHT22_PORT |= (1 << DHT22_BIT);
			
	// VERIFICAMOS EL CHECKSUM
	if ( (data[0] + data[1] + data[2] + data[3]) == data[4]) {
		uint16_t rawhumidity    = data[0] <<8 | data[1];
		uint16_t rawtemperature = data[2] <<8 | data[3];
		
		if (rawtemperature & 0x8000) 
			*temperature = (float)((rawtemperature & 0x7fff) / 10.0)* -1.0; 
		else
			*temperature = (float)(rawtemperature)/10.0;
		
		*humidity = (float)((rawhumidity)/10.0);			
		return SUCESS;  //LECTURA EXITOSA
	}
	return ERROR_CHECKSUM;  //ERROR DE CHECKSUM
}
