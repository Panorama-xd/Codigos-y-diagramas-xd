// Definición de pines
const int PIN_STEP = 5;      // Pulso de paso para el DRV8825
const int PIN_DIR = 4;       // Dirección de giro
const int PIN_POT = A0;      // Entrada analógica del potenciómetro
const int PIN_BOTON = 2;     // Botón para cambiar sentido de giro

// Variables globales
bool sentidoGiro = true;     // true = Horario, false = Antihorario
bool ultimoEstadoBoton = HIGH;

void setup() {
  pinMode(PIN_STEP, OUTPUT);
  pinMode(PIN_DIR, OUTPUT);
  
  // Usamos la resistencia PULLUP interna: el botón debe conectar el pin 2 a GND
  pinMode(PIN_BOTON, INPUT_PULLUP);

  // Estado inicial de dirección
  digitalWrite(PIN_DIR, sentidoGiro ? HIGH : LOW);
}

void loop() {
  // 1. Lectura y detección de pulsación del botón (flanco de bajada)
  bool estadoBoton = digitalRead(PIN_BOTON);
  if (estadoBoton == LOW && ultimoEstadoBoton == HIGH) {
    sentidoGiro = !sentidoGiro; // Cambia el sentido
    digitalWrite(PIN_DIR, sentidoGiro ? HIGH : LOW);
    delay(50); // Antirrebote simple por software
  }
  ultimoEstadoBoton = estadoBoton;

  // 2. Lectura del potenciómetro (0 a 1023)
  int valorPot = analogRead(PIN_POT);

  // 3. Mapeo a retardo en microsegundos (mayor valor = menor tiempo = mayor velocidad)
  int delayMicros = map(valorPot, 0, 1023, 4000, 500);

  // 4. Generación del pulso de paso
  digitalWrite(PIN_STEP, HIGH);
  delayMicroseconds(delayMicros);
  digitalWrite(PIN_STEP, LOW);
  delayMicroseconds(delayMicros);
}