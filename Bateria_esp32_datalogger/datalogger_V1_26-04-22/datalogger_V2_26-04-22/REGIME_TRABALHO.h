#define rele_A 14
#define rele_B 27
#define rele_C 13
#define rele_D 12



void regime_carga(void){
ON_OFF = "On ";
digitalWrite(rele_A, LOW);
tempo=0;

capacidade=0.001;
  while(((capacidade)<=(capacidade_input))&&(sair==0)){
   Entrada_serial2();
   le_tensao_corrente_capacidade();
   
  // if(capacidade<0){capacidade=-1*capacidade;}

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
  ON_OFF = "off";
digitalWrite(rele_A, HIGH);
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
