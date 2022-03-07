void traca_grafico_descargas(void) {


  if (input == "grafico") {
    Serial.println("inicio grafico" );
    grava_cartao_capacidades();
    for (z = 8; carga_mWh[z] < 99999; z++) {

              sprintf(C_mWH,"%.3f",carga_mWh[z]);
              sprintf(D_mWH,"%.3f",descarga_mWh[z]);


      Serial.print(C_mWH);
      Serial.print(" ");
      Serial.println(D_mWH);
      delay(10);
    }

    while (((input == "grafico") || (input == ""))) {
      Serial.println("fim grafico" );
      input = Serial.readStringUntil('\n');
    }
    z = 8;
    delay(1000);

  }


}



void serial_MEDIA(void) {

  if (input == "media") {
    while ((input == "media") || (input == "")) {
      Serial.println("media: " );
      delay(1000);
      input = Serial.readStringUntil('\n');

      if (!(input == "media")) {
        MEDIA = input.toInt();
        Serial.println(MEDIA);

      }
    }
  }


}






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



void Entrada_serial(void) {


  if ((0 < inputValue) && (inputValue < 100)) {
    Serial.println("parametros Debug:");
    Serial.print("capacidade: " );
    Serial.print(capacidade_input);
    Serial.println("mAh " );
    Serial.print("tensao minima: " );
    Serial.print(Min_tensao_input);
    Serial.print("mV  " );
    Serial.print("tensao maxima: " );
    Serial.print(Max_tensao_input);
    Serial.println("mV  " );
    if (Serial.available()) {


      intinput = input.toInt();

    }
  }

  if ((101 < inputValue) && (inputValue < 200)) {
    Serial.println("capacida entrada");
    Serial.print("capacidade: " );
    capacidade_input = 1 * capacidade_input;
    Serial.print(capacidade_input);
    Serial.println("mAh" );
    if (Serial.available()) {

      input = Serial.readStringUntil('\n');
      capacidade_input = input.toInt();

    }
  }

  if ((201 < inputValue) && (inputValue < 300)) {

    Serial.println("Tensao minima");
    Serial.print("Tensao minima: " );
    Serial.print(Min_tensao_input);
    Serial.println("mV" );
    if (Serial.available()) {
      input = Serial.readStringUntil('\n');
      Min_tensao_input = input.toInt();


    }
  }
  if ((301 < inputValue) && (inputValue < 400)) {
    Serial.println("Tensao maxima");
    Min_tensao_input = input.toInt();
    Serial.print("Tensao maxima: " );
    Serial.print(Max_tensao_input);
    Serial.println("mV" );
    if (Serial.available()) {

      input = Serial.readStringUntil('\n');
      Min_tensao_input = input.toInt();


    }
  }

  if ((401 < inputValue) && (inputValue < 500)) {
    Serial.println("parametros Debug:");
    Serial.print("capacidade: " );
    Serial.print(capacidade_input);
    Serial.println("mAh " );
    Serial.print("tensao minima: " );
    Serial.print(Min_tensao_input);
    Serial.print("mV  " );
    Serial.print("tensao maxima: " );
    Serial.print(Max_tensao_input);
    Serial.println("mV  " );
    if (Serial.available()) {
      input = "0";
      input = Serial.readStringUntil('\n');


      serial_capacidade();
      serial_tensao_minima();
      serial_tensao_maxima();
      finaliza_ciclo();





    }
  }




}

void Entrada_serial2(void) {

  if (Serial.available()) {
    input = "0";
    input = Serial.readStringUntil('\n');
    serial_MEDIA();
    traca_grafico_descargas();
    serial_capacidade();
    serial_tensao_minima();
    serial_tensao_maxima();
    traca_grafico_corrente();
    finaliza_ciclo();
    if ((inputValue < 900)) {
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





  }
}
