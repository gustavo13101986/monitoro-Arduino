
/////////////////// SENSOR DE CORRIENTE ///////////////////////////////

float get_corriente()
{
  float voltajeSensor;
  float corriente=0;
  float Sumatoria=0;
  long tiempo=millis();
  int N=0;
  while(millis()-tiempo<500)//Duración 0.5 segundos(Aprox. 30 ciclos de 60Hz)
  { 
    float voltios = analogRead(A5);
    if(voltios <= 1.00){
      voltios = 0;
    }
    voltajeSensor = voltios * (1.1 / 1023.0);////voltaje del sensor
    corriente=voltajeSensor*100; //corriente=VoltajeSensor*(30A/1V)
    Sumatoria=Sumatoria+sq(corriente);//Sumatoria de Cuadrados
    N=N+1;
    delay(1);
  }
  Sumatoria=Sumatoria*2;//Para compensar los cuadrados de los semiciclos negativos.
  corriente=sqrt((Sumatoria)/N); //ecuación del RMS
  return(corriente*1.2);
}
