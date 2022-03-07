



void traca_grafico_ultima(void){
if(inputValue<100){
for(z=0;z<500;z++){
Serial.print("2000 0 ");
Serial.println(descarga_mWh[z]);
 delay(10); 
}

          input="";
          while(((input==""))){
               Serial.println("fim grafico" );
               input = Serial.readStringUntil('\n');
               Serial.println(input );
               delay(1000);  
               
                 }
                                        

}}

void traca_grafico_corrente(void){
  

 if((input=="g")){
  while((input=="g")||input==""){ input = Serial.readStringUntil('\n'); Serial.println("pressione uma tecla" ); delay(1000); }
   

for(indice_0_500=0;indice_0_500<500;indice_0_500++){
Serial.print("100 -100 ");
Serial.println(corrente[indice_0_500]);
 delay(10); 
}}
delay(1000); 
delay(1000); 
delay(1000); 
delay(1000); 
delay(1000); 
}


void traca_grafico_medx5(void){

//Serial.print("100 -100 ");
//Serial.print(time_stamp);
//Serial.print(" ");
  if(medx<=5){
current_medx5=(current+current_medx5);
}
if(medx==5){
  current_medx5=current_medx5/5;
  Serial.print("100 -100 ");
  Serial.println(current_medx5);
  current_medx5=0;
  medx=0;}
medx++;

}



void traca_grafico_VAR(void){

Serial.print("100 -100 ");
//Serial.print(time_stamp);
//Serial.print(" ");
  if(medx<=MEDIA){
current_medx5=(current+current_medx5);
busVoltage_medx5=(busVoltage+busVoltage_medx5);
}
if(medx>=MEDIA){
  current_medx5=current_medx5/MEDIA;
  busVoltage_medx5=29*busVoltage_medx5/MEDIA;//multiplicador de 31.5 para escalionar o grafico de 0 a 100
  Serial.print("-100 100 ");
  Serial.print(" ");
  Serial.print(busVoltage_medx5);
  Serial.print(" ");
  
  Serial.println(current_medx5);
  current_medx5=0;
  busVoltage_medx5=0;
  medx=0;}
medx++;

}
