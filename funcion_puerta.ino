
/////////////////////////////// CUENTA LA CANTIDAD DE VECES QUE CAMBIO DE ESTADO DEL SENSOR
void abrio_puerta(){
  cont_puerta+= 1;
}

void sensor_puerta(){
  estado_sensor = digitalRead(sensorPin );  //lectura digital de pin
  if (estado_sensor == HIGH) {
    abrio_puerta(); 
  }
}
