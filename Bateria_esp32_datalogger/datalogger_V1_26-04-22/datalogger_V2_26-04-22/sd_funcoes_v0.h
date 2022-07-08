/*
void SD_init(void){

  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
   // while (1);
  }



    
  Serial.println("initialization done.");
}*/

void le_cartao(void){

  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}





  void grava_cartao_2(void){
   myFile = SD.open("/test.txt", FILE_APPEND);

  // if the file opened okay, write to it:
  if (myFile) {
    

  sprintf(stV,"%.3f",busVoltage);
  sprintf(stA,"%.2f",current); // get accuracy with current scale
  sprintf(C_mWH,"%.3f",capacidade);
  sprintf(time_stamp,"%.0f",tempo); 
  sprintf(Num_ciclo,"%d",N_ciclo);

   
    myFile.print(time_stamp);
    myFile.print(", ");
    myFile.print(stA);
    myFile.print(", ");
    myFile.print(stV);
    myFile.print(", ");
    myFile.print(Num_ciclo);
    myFile.print(", ");
    myFile.println(C_mWH);
    




    // close the file:
    myFile.close();
 //  Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");

  }}



  void grava_fim_regime(void){
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
   

    myFile.println("$$$$$");
    

    // close the file:
    myFile.close();
    //Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");

  }}

  void grava_cartao_capacidades(void){
  myFile = SD.open("capacidades.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {



 for(z=8;carga_mWh[z]<99999;z++){
  
              sprintf(C_mWH,"%.3f",carga_mWh[z]);
              sprintf(D_mWH,"%.3f",descarga_mWh[z]);
              
              myFile.print(z);
              myFile.print("   ");
              myFile.print(C_mWH);
              myFile.print(" ");
              myFile.println(D_mWH);

              delay(10); }
                  myFile.println("$$$$$");
    


    // close the file:
    myFile.close();
    //Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening capacidades.txt");

  }}







  void SD_init(void){


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


}
