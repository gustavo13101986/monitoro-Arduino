



// Este funcion permite que la raspberry se pueda comunicar por puerto serie (rs485) con arduino

void comunicacion_con_raspberry(){
  if(entrada=='A'){                               
     RS485_Serial.flush();
     delay(200);
     digitalWrite(EnTxPin, HIGH);
     delay(200);
     Serial.println("C");
     RS485_Serial.println("C");
     delay(200);
  }

}
