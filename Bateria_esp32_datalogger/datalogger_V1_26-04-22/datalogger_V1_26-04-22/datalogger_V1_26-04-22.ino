#include "Wire.h"
#include "Adafruit_INA219.h"
#include <SPI.h>
#include <SD.h>
#include <FS.h>

Adafruit_INA219 ina219;

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


#include <C:\Bateria_esp32_datalogger\datalogger_V1_26-04-22\datalogger_V1_26-04-22\sd_funcoes_v0.h>
#include <C:\Bateria_esp32_datalogger\datalogger_V1_26-04-22\datalogger_V1_26-04-22\saida_serial_v0.h>
#include <C:\Bateria_esp32_datalogger\datalogger_V1_26-04-22\datalogger_V1_26-04-22\ENTRADA_SERIAL.h>
#include <C:\Bateria_esp32_datalogger\datalogger_V1_26-04-22\datalogger_V1_26-04-22\REGIME_TRABALHO.h>





void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }

    Serial.print("\nInitializing SD card...");

    Serial.print("\nInitializing SD card...");
 
  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!SD.begin(SS)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    while (1);
  } else {
    Serial.println("Wiring is correct and a card is present.");
  }
 
  // print the type of card
  Serial.println();
  Serial.print("Card type:         ");
  switch (SD.cardType()) {
    case CARD_NONE:
      Serial.println("NONE");
      break;
    case CARD_MMC:
      Serial.println("MMC");
      break;
    case CARD_SD:
      Serial.println("SD");
      break;
    case CARD_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
      // print the type and size of the first FAT-type volume
//  uint32_t volumesize;
//  Serial.print("Volume type is:    FAT");
//  Serial.println(SDFS.usefatType(), DEC);
 
  Serial.print("Card size:  ");
  Serial.println((float)SD.cardSize()/1000);
 
  Serial.print("Total bytes: ");
  Serial.println(SD.totalBytes());
 
  Serial.print("Used bytes: ");
  Serial.println(SD.usedBytes());
 
  //File dir =  SD.open("/");
 // printDirectory(dir, 0);
  }
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
  delay(150);

}
