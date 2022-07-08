
void SD_init(void){

  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
   // while (1);
  }


    
  Serial.println("initialization done.");
}
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
