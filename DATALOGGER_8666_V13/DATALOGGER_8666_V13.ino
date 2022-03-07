#include <SD.h>
#include "Wire.h"
//#include <simpler_INA219.h>
#include "Adafruit_INA219.h"

#define rele1 16
#define rele2 0

//const int chipSelect = D8
File myFile;
float tempo;
char time_stamp[32]; 
float carga_mWh[1000];
float descarga_mWh[1000];

float tensao[1000];
float corrente[1000];
//float capacidade[1000];

float tensao_media_10x;
float corrente_media_10x;
float capacidade_media_10x;

short int indice_med_10x;
short int indice_0_500;

int medx=0;

float current_medx5=0;
float busVoltage_medx5=0;




char descargas_passadas[300];
char cargas_passadas[300];
float capacidade=0;
char stA[32];
char stV[32];
String ON_OFF = "ON";
char C_mWH[32];
char D_mWH[32];
char Num_ciclo[32];
char TC_txt[32];
char TL_txt[32];
int z=0;

float busVoltage = 0;
float current = 0; // Measure in milli amps
float tempo_curto = 0;
float tempo_longo = 0;
int on_off = 1;
int tipo_descarga = 1;
int analog_value,botao_2,botao_1;
int N_ciclo = 0;
int i = 0;
int j = 0;
int automatico=0;
int inputValue=0;
int sair=0;
String input;
int intinput;
int MEDIA=10;
int capacidade_input=600;
int Min_tensao_input=900;
int Max_tensao_input=3000;
//int time_stamp=0;
// the setup function runs once when you press reset or power the board
//simpler_INA219 *sensor219;
Adafruit_INA219 ina219;
#include <E:\bateria dados\DATALOGGER_8666_V13\exibe_grava_dados.h>
#include <E:\bateria dados\DATALOGGER_8666_V13\sd_funcoes_v0.h>
//#include <CE:\bateria dados\DATALOGGER_8666_V00\ina_219_func_v1.h>
#include <E:\bateria dados\DATALOGGER_8666_V13\saida_serial_v0.h>
#include <E:\bateria dados\DATALOGGER_8666_V13\entrada_serial_v0.h>
#include <E:\bateria dados\DATALOGGER_8666_V13\regime_trabalho_v0.h>

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //ina_init();
  //inicia_classe_ina_00();
  SD_init();
//const int analogInput = A0;
Serial.begin(57600);    
  delay(2000);
  Serial.println("Start");
 // Wire.begin();
  Serial.println("Sensor initialization");

  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
   // while (1) { delay(10); }
  }
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); 

  for(z=8;z<509;z++){
carga_mWh[z]=99999;
descarga_mWh[z]=99999;
}

for(z=8;z<15;z++){
carga_mWh[z]=100;
descarga_mWh[z]=100;
}

z=8;
/*
  for(z=250;z<500;z++){

descarga_mAh[z]=4000-8*z;
}*/

}

// the loop function runs over and over again forever
void loop() {
  




inputValue = analogRead(0);
if((inputValue<900)){Serial.println(inputValue);} 


traca_grafico_ultima(); 
carga_descarga();


  delay(1000);  






 N_ciclo++;
                      
}
