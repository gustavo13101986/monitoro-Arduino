

// Este modulo cuenta con dos funciones, la primera evalua si hay una peticion por el puerto serial con la letra 'a' y si es asi desde aqui se llama a la segunda funcion donde
// la idea es q la segunda funcion envie los datos de los sensores.

void enviar_data(float temp_equipo, float hum_equipo, float corriente, float voltaje){
  if(entrada =='a'){
    vibracion = cont_vibracion;
    int deteccion_puerta = cont_puerta;
    RS485_Serial.flush();
    // LLAMAMOS A LA FUNCION QUE ENVIA LA DATA
    enviar_Data_sensores(temp_equipo, hum_equipo, corriente, voltaje, deteccion_puerta, vibracion);
    cont_vibracion = 0;
    cont_puerta = 0;
    }
}


/////////////////////////////// FUNCION QUE ENVIA LOS DATOS DE LOS SENSORES POR EL PUERTO SERIAL (RS485) /////////////////

void enviar_Data_sensores(float temp_equipo, float hum_equipo, float corriente, int voltaje, int deteccion_puerta, int vibrando){
  
  digitalWrite(EnTxPin, HIGH);                    //RS485 como receptor                                               
  // VARIABLES A ENVIAR   
  RS485_Serial.print(temp_equipo, 0);      // tem_equipo
  RS485_Serial.print(",");        
  RS485_Serial.print(hum_equipo, 0);       // hum_equipo
  RS485_Serial.print(",");                  
  RS485_Serial.print(corriente, 2);        // corriente
  RS485_Serial.print(",");    
  RS485_Serial.print(voltaje, 1);          // voltaje
  RS485_Serial.print(",");                  
  RS485_Serial.print(deteccion_puerta); // deteccion_puerta
  RS485_Serial.print(",");              
  RS485_Serial.print(vibrando);        // vibración
  }
