
int notes[] = {262, 294, 330, 349, 392, 440, 494}; // Do, Re, Mi, Fa, Sol, La, Si

int buttonPins[] = {2, 3, 4, 5, 6, 7, 8};

const int buzzerPin = 9;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  bool notePlayed = false;
  
  for (int i = 0; i < 7; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      tone(buzzerPin, notes[i]);
      notePlayed = true; 
      break; 
    }
  }
  if (!notePlayed) {
    noTone(buzzerPin);
  }
}
