#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int Sensorpin = A0;

void setup() {
   lcd.init();
   lcd.backlight();
   lcd.clear();
   pinMode(7,OUTPUT);
   Serial.begin(9600);
}

void loop() {
  int humedad = analogRead(Sensorpin);
  Serial.println(humedad);

  if(humedad>=460)
  {
    digitalWrite(7,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Necesito agua :c");
    lcd.setCursor(0,1);
    lcd.print("");
    delay(3000);
    digitalWrite(7,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Regando :D");
    lcd.setCursor(0,1);
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
  }
  else
  {
    digitalWrite(7,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Feli :3");
    lcd.setCursor(0,1);
    lcd.print("");
  }
  delay(500);
}