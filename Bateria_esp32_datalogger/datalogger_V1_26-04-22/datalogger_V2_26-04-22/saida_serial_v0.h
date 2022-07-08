


//int incremento=0;
 void escreve_serial1(void){
 
 

sprintf(descargas_passadas_1,"d1=%.3f d2=%.3f d3=%.3f d4=%.3f",descarga_mWh[0],descarga_mWh[1],descarga_mWh[2],descarga_mWh[3]);
sprintf(descargas_passadas_2,"d5=%.3f d6=%.3f d7=%.3f",descarga_mWh[4],descarga_mWh[5],descarga_mWh[6]);
sprintf(cargas_passadas_1,"c1=%.3f c2=%.3f c3=%.3f c4=%.3f",carga_mWh[0],carga_mWh[1],carga_mWh[2],carga_mWh[3]);
sprintf(cargas_passadas_2,"c5=%.3f c6=%.3f c7=%.3f",carga_mWh[4],carga_mWh[5],carga_mWh[6]);
// incremento=incremento+1;
 //float2str(stV,busVoltage,"V");  

  sprintf(stV,"%.3f",busVoltage);
  sprintf(stA,"%.2f",current); // get accuracy with current scale
  sprintf(C_mWH,"%.3f",capacidade);
  sprintf(time_stamp,"%.0f",tempo); 
  sprintf(Num_ciclo,"%d",N_ciclo);
  sprintf(TC_txt,"%.0f",tempo_curto);
  sprintf(TL_txt,"%.0f",tempo_longo);


  Serial.print("Ciclo=");
  Serial.print(Num_ciclo);
  Serial.print(" c_ant=");
  Serial.print(carga_mWh[i]);
  Serial.print(" d_ant=");
  Serial.println(descarga_mWh[i]);

  
  Serial.print(ON_OFF);
  //Serial.print("C=,"); 
  //Serial.print(on_off);
 
  Serial.print(" TS=");
  Serial.print(time_stamp);
   Serial.print(" ");
  Serial.print(stA);
  Serial.print("mA ");
  Serial.print(stV);
  Serial.print("V ");
  
  Serial.print(C_mWH);
  Serial.println("=mWH  ");
  

  Serial.println(descargas_passadas_1);
  Serial.println(descargas_passadas_2);
  Serial.println(cargas_passadas_1);
  Serial.println(cargas_passadas_2);
  Serial.println("-----------------\n");}

  /*
  sprintf(descargas_passadas,"d1=%.3f d2=%.3f d3=%.3f d4=%.3f d5=%.3f d6=%.3f d7=%.3f||",descarga_mAh[0],descarga_mAh[1],descarga_mAh[2],descarga_mAh[3],descarga_mAh[4],descarga_mAh[5],descarga_mAh[6]);
  sprintf(cargas_passadas,"c1=%.3f c2=%.3f c3=%.3f c4=%.3f c5=%.3f c6=%.3f c7=%.3f",carga_mAh[0],carga_mAh[1],carga_mAh[2],carga_mAh[3],carga_mAh[4],carga_mAh[5],carga_mAh[6]);
  Serial.print(descargas_passadas);
  Serial.println(cargas_passadas);
  Serial.print(",,,,,,,,,");
  Serial.print(regime_descarga);
  Serial.print("=D,");

  Serial.print(" TC=");
  Serial.print(TC_txt);
    Serial.print(TL_txt);
  Serial.print("=TL,");
  
  */
