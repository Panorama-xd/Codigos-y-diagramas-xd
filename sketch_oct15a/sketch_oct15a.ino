 const int pinIN3 = 27;  
const int pinIN4 = 14;  
const int pinENB = 12;  
const int photoPin = 32;
const int pump1Pin = 33; 
const int pump2Pin = 25; 

void setup() {
  pinMode(pinIN3, OUTPUT);
  pinMode(pinIN4, OUTPUT);
  pinMode(pinENB, OUTPUT);
  pinMode(pump1Pin, OUTPUT); 
  pinMode(pump2Pin, OUTPUT); 
}

void loop()
{
  digitalWrite(pinIN3, LOW);
  digitalWrite(pinIN4, LOW);
  digitalWrite(pump1Pin, LOW);
  digitalWrite(pump2Pin, LOW);
  delay(2000);
 
  digitalWrite(pinIN3, LOW);
  digitalWrite(pinIN4, HIGH);
  digitalWrite(pump1Pin, LOW);
  digitalWrite(pump2Pin, LOW);
  analogWrite(pinENB, 130);  
  delay(1280);
  
  digitalWrite(pinIN3, LOW);
  digitalWrite(pinIN4, LOW);
  digitalWrite(pump1Pin, HIGH);
  digitalWrite(pump2Pin, LOW);
  delay(2300);
 
  digitalWrite(pinIN3, LOW);
  digitalWrite(pinIN4, HIGH);
  digitalWrite(pump1Pin, LOW);
  digitalWrite(pump2Pin, LOW);
  analogWrite(pinENB, 130);  
  delay(1800);
  
  digitalWrite(pinIN3, LOW);
  digitalWrite(pinIN4, LOW);
  digitalWrite(pump1Pin, LOW);
  digitalWrite(pump2Pin, HIGH);
  delay(1500);

  digitalWrite(pinIN3, HIGH);
  digitalWrite(pinIN4, LOW);
  digitalWrite(pump1Pin, LOW);
  digitalWrite(pump2Pin, LOW);
  analogWrite(pinENB, 130);  
  delay(5000);

  digitalWrite(pinIN3, LOW);
  digitalWrite(pinIN4, LOW);
  digitalWrite(pump1Pin, LOW);
  digitalWrite(pump2Pin, LOW);
  delay(700000);
}

