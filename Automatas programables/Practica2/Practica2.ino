const int PIN_STEP = 5, PIN_DIR = 4, PIN_BOTON = 2;

int posicionActual = 0;  // Posición actual en pasos
int anguloActual = 0;    // 0 = 0°, 1 = 45°, 2 = 90°, 3 = 180°
bool ultimoBoton = HIGH;

void setup() {
  pinMode(PIN_STEP, OUTPUT);
  pinMode(PIN_DIR, OUTPUT);
  pinMode(PIN_BOTON, INPUT_PULLUP);
}

void loop() {
  bool boton = digitalRead(PIN_BOTON);

  // Al presionar el botón
  if (boton == LOW && ultimoBoton == HIGH) {
    
    // 1. Cambiar al siguiente ángulo
    anguloActual = anguloActual + 1;
    if (anguloActual > 3) anguloActual = 0; // Si pasa de 180°, vuelve a 0°

    // 2. Definir los pasos objetivo
    int posicionObjetivo = 0;
    if (anguloActual == 1) posicionObjetivo = 25;   // 45°
    if (anguloActual == 2) posicionObjetivo = 50;   // 90°
    if (anguloActual == 3) posicionObjetivo = 100;  // 180°

    // 3. Definir dirección de giro
    if (posicionObjetivo > posicionActual) {
      digitalWrite(PIN_DIR, HIGH); // Avanzar
    } else {
      digitalWrite(PIN_DIR, LOW);  // Regresar a 0°
    }

    // 4. Calcular cuántos pasos dar
    int pasos = posicionObjetivo - posicionActual;
    if (pasos < 0) pasos = -pasos; // Convertir a positivo para el for

    // 5. Mover el motor
    for (int i = 0; i < pasos; i++) {
      digitalWrite(PIN_STEP, HIGH);
      delayMicroseconds(2000);
      digitalWrite(PIN_STEP, LOW);
      delayMicroseconds(2000);
    }

    // 6. Guardar la nueva posición
    posicionActual = posicionObjetivo;
    delay(200); // Evitar falsos toques del botón
  }

  ultimoBoton = boton;
}