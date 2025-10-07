#include <Servo.h>
Servo pano;
int trig = 5;
int echo = 6;
int tiempo;
int distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pano.attach(7);
}

void loop() {
  digitalWrite(trig, HIGH);
  delay(500);
  digitalWrite(trig, LOW);
  tiempo=pulseIn(echo, HIGH);
  distancia=tiempo/58.2;
  delay(500);
{
  if (distancia <=10)
  (pano.write(120));
  delay(2000); 
  } 
  {
  if (distancia >10);
  pano.write(0);
 } 
}