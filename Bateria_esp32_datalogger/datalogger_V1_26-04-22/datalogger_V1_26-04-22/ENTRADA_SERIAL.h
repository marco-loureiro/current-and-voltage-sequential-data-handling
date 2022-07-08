


void serial_capacidade(void) {

  if (input == "c") {
    while ((input == "c") || (input == "")) {
      Serial.println("capacidade: " );
      delay(1000);
      input = Serial.readStringUntil('\n');

      if (!(input == "c")) {
        capacidade_input = input.toInt();
        if (capacidade_input > 0) {
          capacidade_input = 1 * capacidade_input;
        }
      }
    }
  }


}

void serial_tensao_minima(void) {

  if (input == "t") {
    while ((input == "t") || (input == "")) {
      Serial.println("setup tensao minima: " );
      delay(1000);
      input = Serial.readStringUntil('\n');

      if (!(input == "t")) {
        Min_tensao_input = input.toInt();

      }
    }
  }


}

void finaliza_ciclo(void) {

  if ((input == "f")) {
    Serial.println("fim ciclo manual " );
    delay(1000);
    input = "1";
    sair = 1;
  }

}

void serial_tensao_maxima(void) {

  if ((input == "m")) {
    while ((input == "m") || (input == "")) {
      Serial.println("setup tensao maxima: " );
      delay(1000);
      input = Serial.readStringUntil('\n');

      if (!(input == "m")) {
        Max_tensao_input = input.toInt();

      }
    }
  }


}




void Entrada_serial2(void) {

  if (Serial.available()) { 
     input = Serial.readStringUntil('\n');
    

    serial_capacidade();
    serial_tensao_minima();
    serial_tensao_maxima();
    finaliza_ciclo();
    Serial.println("parametros Debug:");
    Serial.print("capacidade:" );
    Serial.print(capacidade_input);
    Serial.println("mAh " );
    Serial.print("tensao minima:" );
    Serial.print(Min_tensao_input);
    Serial.print("mV  " );
    Serial.print("tensao maxima:" );
    Serial.print(Max_tensao_input);
    Serial.println("mV  " );
    }
    input="ppp";





  }
