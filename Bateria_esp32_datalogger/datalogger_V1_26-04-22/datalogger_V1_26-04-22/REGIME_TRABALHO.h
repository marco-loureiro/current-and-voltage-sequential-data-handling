void le_tensao_corrente_capacidade(void){
    
    current = ina219.getCurrent_mA();
    busVoltage = ina219.getBusVoltage_V();
    capacidade=capacidade+((current*busVoltage)/3600);////////////////voltsr 3600
    
}



void regime_carga(void){
ON_OFF = "On ";
//digitalWrite(rele1, HIGH); 
//digitalWrite(rele2, HIGH);
tempo=0;

capacidade=0.001;
  while(((capacidade)<=(capacidade_input))&&(sair==0)){
   Entrada_serial2();
   le_tensao_corrente_capacidade();
   
   if(capacidade<0){capacidade=-1*capacidade;}

   escreve_serial1();
   grava_cartao_2();

   tempo++;
     delay(segundo); 
   
  
  
  
  }

sair=0;
carga_mWh[i]=capacidade;
carga_mWh[z]=capacidade;


  
}



void regime_descarga(void){
ON_OFF = "Off ";
//digitalWrite(rele1, LOW); 
//digitalWrite(rele2, LOW);
tempo=0;

capacidade=0.001;


  while(((busVoltage*1000)>=(Min_tensao_input))&&(sair==0)){
    
    Entrada_serial2();
    le_tensao_corrente_capacidade();
    
    escreve_serial1();
    grava_cartao_2();
   tempo++;
     delay(segundo); 
   
  
  
  
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
ON_OFF = "desc";
regime_carga();
ON_OFF = "desc";
regime_descarga();
}
