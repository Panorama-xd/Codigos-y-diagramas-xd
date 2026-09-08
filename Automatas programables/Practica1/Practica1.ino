const int PIN_STEP = 5, PIN_DIR = 4;
int pasoActual = 0;

void setup() {
  pinMode(PIN_STEP, OUTPUT);
  pinMode(PIN_DIR, OUTPUT);
}

void loop() {
  // --------------------------------------------------
  // PARADA 1: 0 Grados (0 pasos)
  // --------------------------------------------------
  moverMotor(0);
  delay(1000); // Espera 1 segundo en 0°

  // --------------------------------------------------
  // PARADA 2: 45 Grados (25 pasos)
  // --------------------------------------------------
  moverMotor(25);
  delay(1000); // Espera 1 segundo en 45°

  // --------------------------------------------------
  // PARADA 3: 90 Grados (50 pasos)
  // --------------------------------------------------
  moverMotor(50);
  delay(1000); // Espera 1 segundo en 90°

  // --------------------------------------------------
  // PARADA 4: 180 Grados (100 pasos)
  // --------------------------------------------------
  moverMotor(100);
  delay(1000); // Espera 1 segundo en 180°
}

// Función auxiliar para mover el motor a la posición en pasos
void moverMotor(int pasoObjetivo) {
  int diferencia = pasoObjetivo - pasoActual;

  // Dirección: HIGH para avanzar, LOW para retroceder
  digitalWrite(PIN_DIR, diferencia > 0 ? HIGH : LOW);
  if (diferencia < 0) diferencia = -diferencia;

  // Pulsos de movimiento
  for (int p = 0; p < diferencia; p++) {
    digitalWrite(PIN_STEP, HIGH);
    delayMicroseconds(2000);
    digitalWrite(PIN_STEP, LOW);
    delayMicroseconds(2000);
  }

  pasoActual = pasoObjetivo; // Guarda la nueva posición actual
}