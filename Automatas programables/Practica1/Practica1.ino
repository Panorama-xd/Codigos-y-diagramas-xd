const int PIN_STEP = 5, PIN_DIR = 4;

// Pasos según el ángulo (200 pasos = 360°): 0°=0, 45°=25, 90°=50, 180°=100
int secuencia[] = {0, 25, 50, 100}; 
int pasoActual = 0;

void setup() {
  pinMode(PIN_STEP, OUTPUT);
  pinMode(PIN_DIR, OUTPUT);
}

void loop() {
  // Recorre cada posición de la secuencia una por una
  for (int i = 0; i < 4; i++) {
    int pasoObjetivo = secuencia[i];
    int diferencia = pasoObjetivo - pasoActual;

    // Dirección: HIGH para avanzar, LOW para retroceder
    digitalWrite(PIN_DIR, diferencia > 0 ? HIGH : LOW);
    if (diferencia < 0) diferencia = -diferencia;

    // Mueve los pasos necesarios
    for (int p = 0; p < diferencia; p++) {
      digitalWrite(PIN_STEP, HIGH);
      delayMicroseconds(2000); // Modificar para cambiar la velocidad
      digitalWrite(PIN_STEP, LOW);
      delayMicroseconds(2000);
    }

    pasoActual = pasoObjetivo;
    delay(1000); // Pausa de 1 segundo en cada ángulo
  }
}