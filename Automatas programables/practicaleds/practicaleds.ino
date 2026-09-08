const int PIN_STEP = 5, PIN_DIR = 4;

// Pines para los LEDs indicadores
const int LED_0   = 8;   // Indica 0°
const int LED_45  = 9;   // Indica 45°
const int LED_90  = 10;  // Indica 90°
const int LED_180 = 11;  // Indica 180°

int pasoActual = 0;

void setup() {
  pinMode(PIN_STEP, OUTPUT);
  pinMode(PIN_DIR, OUTPUT);

  // Configurar cada LED como salida
  pinMode(LED_0, OUTPUT);
  pinMode(LED_45, OUTPUT);
  pinMode(LED_90, OUTPUT);
  pinMode(LED_180, OUTPUT);
}

void loop() {
  // --------------------------------------------------
  // PARADA 1: 0 Grados (Pin 8)
  // --------------------------------------------------
  moverMotor(0);               // Ir a 0 pasos
  digitalWrite(LED_0, HIGH);   // Enciende el LED de 0°
  digitalWrite(LED_45, LOW);
  digitalWrite(LED_90, LOW);
  digitalWrite(LED_180, LOW);
  delay(1000);                 // Espera 1 segundo

  // --------------------------------------------------
  // PARADA 2: 45 Grados (Pin 9)
  // --------------------------------------------------
  moverMotor(25);              // Ir a 25 pasos (45°)
  digitalWrite(LED_0, LOW);
  digitalWrite(LED_45, HIGH);  // Enciende el LED de 45°
  digitalWrite(LED_90, LOW);
  digitalWrite(LED_180, LOW);
  delay(1000);

  // --------------------------------------------------
  // PARADA 3: 90 Grados (Pin 10)
  // --------------------------------------------------
  moverMotor(50);              // Ir a 50 pasos (90°)
  digitalWrite(LED_0, LOW);
  digitalWrite(LED_45, LOW);
  digitalWrite(LED_90, HIGH);  // Enciende el LED de 90°
  digitalWrite(LED_180, LOW);
  delay(1000);

  // --------------------------------------------------
  // PARADA 4: 180 Grados (Pin 11)
  // --------------------------------------------------
  moverMotor(100);             // Ir a 100 pasos (180°)
  digitalWrite(LED_0, LOW);
  digitalWrite(LED_45, LOW);
  digitalWrite(LED_90, LOW);
  digitalWrite(LED_180, HIGH); // Enciende el LED de 180°
  delay(1000);
}

// Función auxiliar simple para mover el motor a la posición objetivo
void moverMotor(int pasoObjetivo) {
  int diferencia = pasoObjetivo - pasoActual;

  // Dirección: HIGH si el valor aumenta, LOW si el valor disminuye (regreso)
  digitalWrite(PIN_DIR, diferencia > 0 ? HIGH : LOW);
  if (diferencia < 0) diferencia = -diferencia;

  // Pulsos de movimiento
  for (int p = 0; p < diferencia; p++) {
    digitalWrite(PIN_STEP, HIGH);
    delayMicroseconds(2000);
    digitalWrite(PIN_STEP, LOW);
    delayMicroseconds(2000);
  }

  pasoActual = pasoObjetivo; // Guarda la posición actual
}