#include <DHT.h>
#include <LiquidCrystal_I2C.h>

const int caliente = 5; 
const int frio = 4; 
const int ventilador = 3;
const int sensorDHT = A2;

float temp, humedad;

DHT dht(sensorDHT, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(frio, OUTPUT);
  pinMode(caliente, OUTPUT);
  pinMode(ventilador, OUTPUT);
}

void loop() {

  humedad = dht.readHumidity();
  temp = dht.readTemperature();

  if (isnan(humedad) || isnan(temp)) {
    lcd.setCursor(0, 0);
    lcd.print("Error Sensor");
    delay(2000);
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Humedad: ");
  lcd.print(humedad);
  lcd.print(" %");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");

  if (temp >= 34) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  TEMP. MAXIMA  ");
    lcd.setCursor(0, 1);
    lcd.print("    EXCEDIDA  ");

    digitalWrite(frio, LOW);
    digitalWrite(caliente, HIGH);
    digitalWrite(ventilador, HIGH);

  } else {
    digitalWrite(frio, HIGH);
    digitalWrite(caliente, LOW);
    digitalWrite(ventilador, LOW);
  }

  delay(2000);
}

