int MIC = 2;
int RELAY = 3;
int VALOR;
int ESTADO;
void setup() {
  pinMode(MIC,INPUT);
  pinMode(RELAY,OUTPUT);
}

void loop() {
 VALOR = digitalRead(MIC);
 if (VALOR == HIGH){
  ESTADO = digitalRead(RELAY);
  digitalWrite(RELAY, !ESTADO);
  delay(500);
 }

}
