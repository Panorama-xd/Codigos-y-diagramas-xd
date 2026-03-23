#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 7     
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
 dht.begin();
 lcd.init();
 lcd.backlight();
 lcd.setCursor(0, 0);
 lcd.print("   Humedad &");
 lcd.setCursor(0, 1);
 lcd.print("   Temperatura");
 delay(3000);
 lcd.clear();
}


void loop() {
 float humedad = dht.readHumidity();
 float temperatura = dht.readTemperature();
 if (isnan(humedad) || isnan(temperatura)) {
  lcd.setCursor(0, 0);
  lcd.print("Error  ");
 } else {
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperatura, 1);
  lcd.print(" C ");
  
  lcd.setCursor(0, 0);
  lcd.print("Humedad: ");
  lcd.print(humedad, 1);
  lcd.print(" % ");
 }
 delay(500);
}

