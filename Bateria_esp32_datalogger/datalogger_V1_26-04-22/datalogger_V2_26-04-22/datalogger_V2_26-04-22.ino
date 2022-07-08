#include "Wire.h"
#include "Adafruit_INA219.h"
#include <SPI.h>
#include <SD.h>
#include <FS.h>

Adafruit_INA219 ina219;
Adafruit_INA219 ina219_B(0x41);
Adafruit_INA219 ina219_C(0x44);
Adafruit_INA219 ina219_D(0x45);


//Adafruit_INA219(uint8_t addr = INA219_ADDRESS);
const int chipSelect = SS;
#define segundo 903
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

char descargas_passadas_1[300];
char descargas_passadas_2[300];
char cargas_passadas_1[300];
char cargas_passadas_2[300];

char stA[32];
char stV[32];
String ON_OFF = "ON";
char C_mWH[32];
char D_mWH[32];
char Num_ciclo[32];
char TC_txt[32];
char TL_txt[32];
int z=0;

//float busVoltage = 0;
//float current = 0; // Measure in milli amps
float tempo_curto = 0;
float tempo_longo = 0;
int on_off = 1;
int tipo_descarga = 1;
int N_ciclo = 0;
int i = 0;
int j = 0;
int automatico=0;
int inputValue=0;
int sair=0;
String input;
int capacidade_input=100;
int Min_tensao_input=900;
int Max_tensao_input=3000;
//int time_stamp=0;
// the setup function runs once when you press reset or power the board
//simpler_INA219 *sensor219;

#include <C:\Bateria_esp32_datalogger\datalogger_V1_26-04-22\datalogger_V2_26-04-22\ina_rele_funcoes_v0.h>
#include <C:\Bateria_esp32_datalogger\datalogger_V1_26-04-22\datalogger_V2_26-04-22\sd_funcoes_v0.h>
#include <C:\Bateria_esp32_datalogger\datalogger_V1_26-04-22\datalogger_V2_26-04-22\saida_serial_v0.h>
#include <C:\Bateria_esp32_datalogger\datalogger_V1_26-04-22\datalogger_V2_26-04-22\ENTRADA_SERIAL.h>
#include <C:\Bateria_esp32_datalogger\datalogger_V1_26-04-22\datalogger_V2_26-04-22\REGIME_TRABALHO.h>





void setup() {
inicialializa_ina_reles();
SD_init();
    delay(2000);

  for(z=8;z<509;z++){
carga_mWh[z]=99999;
descarga_mWh[z]=99999;

}
SD_init();
for(z=8;z<15;z++){
carga_mWh[z]=100;
descarga_mWh[z]=100;
}

z=8;


}

void loop() {

carga_descarga();
N_ciclo++;
  delay(150);

}
