void le_tensao_corrente_capacidade(void){
    inputValue = analogRead(0);
    if((inputValue<900)){
    Serial.println(inputValue);}
    current = ina219.getCurrent_mA();
    busVoltage = ina219.getBusVoltage_V();
    capacidade=capacidade+((current*busVoltage)/3600);////////////////voltsr 3600
    
}



void regime_carga(void){
ON_OFF = "On ";
digitalWrite(rele1, HIGH); 
digitalWrite(rele2, HIGH);
tempo=0;

capacidade=0.001;
  while(((capacidade)<=(capacidade_input))&&(sair==0)){
   Entrada_serial2();
   le_tensao_corrente_capacidade();
   
   if(capacidade<0){capacidade=-1*capacidade;}

   escolhe_impressao();
   grava_cartao_2();

   tempo++;
     delay(1000); 
   
  
  
  
  }

sair=0;
carga_mWh[i]=capacidade;
carga_mWh[z]=capacidade;


  
}



void regime_descarga(void){
ON_OFF = "Off ";
digitalWrite(rele1, LOW); 
digitalWrite(rele2, LOW);
tempo=0;

capacidade=0.001;
indice_0_500=0;

  while(((busVoltage*1000)>=(Min_tensao_input))&&(sair==0)){
    
    Entrada_serial2();
    le_tensao_corrente_capacidade();
    
    escolhe_impressao();
    grava_cartao_2();
   tempo++;
     delay(1000); 
   
  
  
  
  }

descarga_mWh[i]=capacidade;
descarga_mWh[z]=capacidade;
i++;
z++;
if(z>500){z=8;}
if(i>7){i=0;}
sair=0;
  
}




void carga_descarga(void){
if(inputValue>100){
ON_OFF = "desc";
regime_carga();
ON_OFF = "desc";
regime_descarga();
ON_OFF = "desc";}
}
