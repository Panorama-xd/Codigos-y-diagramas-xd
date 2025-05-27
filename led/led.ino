void setup() {
  pinMode(8,OUTPUT);//Selección del pin que se usara
}

void loop() {
  digitalWrite(8,HIGH);//Se enciende el led
  delay(2000);//Tiempo de encendido 
  digitalWrite(8,LOW);//Se apaga el led
  delay(2000);//Tiempo de apagado
}
