//Pinos ligado no botão
int btn1 = 18;

//Pinos que são ligados no módulo de relés
int rele1 = 33;
int rele2 = 32;

//variável para guardar o estado do segundo relé
boolean rele2_Ativo = false;

//A função setup() é executada uma vez antes do loop
void setup()
{
  //Seta os pinos dos botões como entrada
  pinMode(btn1, INPUT);

  //Seta os pinos dos relés como saída
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);

  //Abre a porta serial, definindo a taxa de dados para 9600 bps
  Serial.begin(9600);
}

//A função loop() é executada após o setup e é repetida continuamente
void loop()
{
  Serial.println("funcionando");
  delay(1000);
  if (digitalRead(btn1) == HIGH) //Caso o botão 1 foi pressionado
  {
    //Exibe no monitor serial a mensagem entre aspas
    Serial.println("Botão pressionado");

    //Ligamos o relé 1
    digitalWrite(rele1, HIGH);

    //Invertemos o estado da variável rele2_Ativo
    rele2_Ativo = !rele2_Ativo;

    //Mudamos o estado do relé 2
    digitalWrite(rele2, rele2_Ativo );

    //Aguardamos 1 segundo (1000 ms)
    delay(1000);

    //Desligamos o relé 1
    digitalWrite(rele1, LOW);
  }
}
