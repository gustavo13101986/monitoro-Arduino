//https://electropeak.com/learn/interfacing-zmpt101b-voltage-sensor-with-arduino/

// LIBRERIAS
#include "DHT.h"                                   // Sensor de corriente y humedad
#include <Arduino.h>
#include <stdio.h>
#include <SoftwareSerial.h>                        // libreria para activar mas puertos seriales
SoftwareSerial RS485_Serial(12, 10);               // RX, TX


//////////////////////////////////// TIEMPOS //////////////////////////

unsigned long previousMillis = 0;  // Tiempo anterior 0
unsigned long timeToAction = 200; // Tiempo de espera entre acciones, 200ms

///////////////////////////////////////////////////// PINES DE LOS SENSORES
const int EnTxPin =  11;                           // PIN PARA RS485
int vibration_Sensor = A1;                         // SENSOR DE VIBRACION
const int sensorPin = 4;                           // SENSOR INFRARROJO
DHT dht(3, DHT11);                                 // SENSOR DE HUM Y TEM PIN3
///////////////////////////////////////////////////////////////////////////


//////////////////////////////////// VARIABLES SENSOR DE VIBRACION ////////
int vibracion = 0;
int cont_vibracion = 0;
int present_condition = 0;
int previous_condition = 0;
/////////////////////////////////////////////////////////////////////////

//////////////////////////////////// VARIABLES SENSOR DE PUERTA /////////
int estado_sensor = 0;
int cont_puerta = 0;
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
int entrada;
/////////////////////////////////////////////////////////////////////////
void setup() 
{ 
  Serial.begin(9600);
  RS485_Serial.begin(9600);                       // INICIAR RS485
  dht.begin();                                    // INICIAR SENSOR DE HUMEDAD Y TEMPERATURA
  pinMode(EnTxPin, OUTPUT);                       // PIN PARA RS485
  digitalWrite(EnTxPin, LOW);                     // RS485 como receptor
  pinMode(vibration_Sensor, INPUT);               // SENSOR VIBRACIÓN
  pinMode(sensorPin , INPUT);                     // SENSOR PUERTA

} 


void loop() { 
  ////////////////////////////////LECTURA DE SENSORES////////////////////////////////////
  
  float temp_equipo = dht.readTemperature();               // LEER TEMPERATURA
  float hum_equipo = dht.readHumidity();                   // LEER HUMEDAD
  float voltaje=sensor_voltaje();                          // SENSOR DE VOLTAJE
  float corriente=get_corriente();                         // LEER CORRIENTE
  sensor_vibracion();                                      // EVALUAR SI VIBRO
  sensor_puerta();                                         // EVALUAR SI ABRIO PUERTA
  
  entrada = RS485_Serial.read();                           // LEER EL PUERTO SERIAL
  comunicacion_con_raspberry();                            // condicion para q raspberry encuentre a arduino

  digitalWrite(EnTxPin, LOW);                              // pin en low para seguir escuchando el puerto serie
    
/////////////////////////////////////////////////////  condicion para para empezar a enviar la data
  enviar_data(temp_equipo, hum_equipo, corriente, voltaje);
}
