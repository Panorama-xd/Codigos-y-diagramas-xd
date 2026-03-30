#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
#include <Servo.h> 

#define TRIG_PIN 9 
#define ECHO_PIN 10 
#define LED_VERDE 2 
#define LED_ROJO 3 
#define BUZZER 4 
#define SERVO_PIN 6 

LiquidCrystal_I2C lcd(0x27, 16, 2); 

Servo myServo; 

int pos = 0; 
int direction = 1;  

void setup() { 
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT); 
  pinMode(LED_VERDE, OUTPUT); 
  pinMode(LED_ROJO, OUTPUT); 
  pinMode(BUZZER, OUTPUT); 
  myServo.attach(SERVO_PIN); 
  myServo.write(pos); 
  lcd.init();
  lcd.backlight(); 
  lcd.clear(); 
} 

long readDistance() { 
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIG_PIN, LOW); 
  long duration = pulseIn(ECHO_PIN, HIGH); 
  return duration * 0.034 / 2; 
} 

void loop() { 
  long distance = readDistance(); 
  if (distance > 20 || distance == 0) { 
    digitalWrite(LED_VERDE, HIGH); 
    digitalWrite(LED_ROJO, LOW); 
    digitalWrite(BUZZER, LOW); 
    lcd.setCursor(0, 0); 
    lcd.print("Escaneando area"); 
    lcd.setCursor(0, 1); 
    lcd.print("                "); 
    myServo.write(pos); 
    delay(10); 
    pos += direction; 
    if (pos >= 180 || pos <= 0) { 
      direction = -direction; 
    } 
  } else { 
    digitalWrite(LED_VERDE, LOW); 
    digitalWrite(LED_ROJO, HIGH); 
    digitalWrite(BUZZER, HIGH); 
    lcd.setCursor(0, 0); 
    lcd.print("    Peligro!     "); 
    lcd.setCursor(0, 1); 
    lcd.print("objeto detectado"); 
    myServo.write(pos); 
  } 
} 

 