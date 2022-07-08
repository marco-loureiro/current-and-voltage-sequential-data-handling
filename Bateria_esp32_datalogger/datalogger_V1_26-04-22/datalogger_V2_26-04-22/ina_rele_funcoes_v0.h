
  float shuntvoltage = 0;
  float busVoltage = 0;
  float current = 0;
  float loadvoltage = 0;
  float power = 0;

  float shuntvoltage_B = 0;
  float busVoltage_B = 0;
  float current_B = 0;
  float loadvoltage_B = 0;
  float power_B = 0;

  float shuntvoltage_C = 0;
  float busVoltage_C = 0;
  float current_C = 0;
  float loadvoltage_C = 0;
  float power_C = 0;

  float shuntvoltage_D = 0;
  float busVoltage_D = 0;
  float current_D= 0;
  float loadvoltage_D= 0;
  float power_D= 0;

float capacidade=0;
float capacidade_B=0;
float capacidade_C=0;
float capacidade_D=0;




void inicialializa_ina_reles(){

  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
    if (! ina219_B.begin()) {
    Serial.println("Failed to find INA219 chip B");
    while (1) { delay(10); }
  }

        if (! ina219_C.begin()) {
    Serial.println("Failed to find INA219 chip C");
    while (1) { delay(10); }
  }
      if (! ina219_D.begin()) {
    Serial.println("Failed to find INA219 chip D");
    while (1) { delay(10); }
  }

    // Initialize second board with the address 0x41

  Serial.print("BV"); Serial.print("\t"); // Bus Voltage
  Serial.print("SV"); Serial.print("\t"); // Shunt Voltage
  Serial.print("LV"); Serial.print("\t"); // Load Voltage
  Serial.print("C"); Serial.print("\t");  // Current
  Serial.println("P");  // Power

 pinMode(32, OUTPUT);
pinMode(13, OUTPUT);
pinMode(9, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);

pinMode(12, OUTPUT);
pinMode(14, OUTPUT);
pinMode(27, OUTPUT);
pinMode(26, OUTPUT);

//Defina o pino 32 com nivel alto(3.3V).
//A funçao aceita os seguintes opçoes (HIGH ou LOW).
  
    
  
  }


  void le_tensao_corrente_capacidade(void){
  
    Adafruit_INA219(0x40);
    current = ina219.getCurrent_mA();
    busVoltage = ina219.getBusVoltage_V();
    capacidade=capacidade+((current*busVoltage)/3600);////////////////voltsr 3600
    
}


  void le_tensao_corrente_capacidade_B(void){
    
    current_B = ina219_B.getCurrent_mA();
    busVoltage_B = ina219_B.getBusVoltage_V();
    capacidade_B=capacidade_B+((current_B*busVoltage_B)/3600);////////////////voltsr 3600
    
}

  void le_tensao_corrente_capacidade_C(void){
    
    current_C = ina219_C.getCurrent_mA();
    busVoltage_C = ina219_C.getBusVoltage_V();
    capacidade_C=capacidade_C+((current_C*busVoltage_C)/3600);////////////////voltsr 3600
    
}

  void le_tensao_corrente_capacidade_D(void){
    
    current_D = ina219_D.getCurrent_mA();
    busVoltage_D = ina219_D.getBusVoltage_V();
    capacidade_D=capacidade_D+((current_D*busVoltage_D)/3600);////////////////voltsr 3600
    
}
