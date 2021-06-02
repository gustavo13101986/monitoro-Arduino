

  /////////////////////////////// CUENTA LA CANTIDAD DE VECES QUE VIBRO
void vibro(){
  cont_vibracion+= 1;
  //Serial.println(cont_vibracion);
}


void sensor_vibracion(){
  previous_condition = present_condition;
  long tiem=millis();
    while(millis()-tiem<1000){
      present_condition = digitalRead(A1); // Reading digital data from the A1
      if (previous_condition != present_condition) {
        vibro(); 
    }
  }
}
