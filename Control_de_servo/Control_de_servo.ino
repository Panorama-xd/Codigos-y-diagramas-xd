#include <Servo.h>
Servo pano;

int potenciometro = 0;
int valor_potenciometro;

void setup() {
  pano.attach(2);
}

void loop() {
  valor_potenciometro = analogRead(potenciometro);
  valor_potenciometro = map(valor_potenciometro, 0, 1023, 0, 180);
  pano.write(valor_potenciometro);
  delay(10);
}
