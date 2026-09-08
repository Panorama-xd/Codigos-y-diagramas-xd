int DIR = 4;       // pin para giro del motor
int STEP = 5;       // pin para los pasos del motor
int X;
#define LIMSUP 574  // limite medio superior pot 524
#define LIMINF 450  // limite medio inferior pot 500

void setup() {
  pinMode(DIR, OUTPUT);  // salidas de arduino
  pinMode(STEP, OUTPUT);  // salidas de arduino
}

void loop() {
  digitalWrite(DIR, HIGH);          // indica el giro del motor
  X = analogRead(A0);                // lectura del potenciometro
  if(X > LIMSUP)                     // si el valor es mayor a LIMSUP
  {
    digitalWrite(STEP, HIGH);        // instruccion de movimiento
    delayMicroseconds(20500);        // instruccion de velocidad
    digitalWrite(STEP, LOW);
    delayMicroseconds(20500);
  }
  
  digitalWrite(DIR, LOW);           // indica el giro del motor
  X = analogRead(A0);                // lectura del potenciometro
  if (X < LIMINF)                    // si el valor es menor a LIMINF
  {
    digitalWrite(STEP, HIGH);        // instruccion de movimiento
    delayMicroseconds(20500);        // instruccion de velocidad
    digitalWrite(STEP, LOW);
    delayMicroseconds(20500);
  }
  X = analogRead (A0);
  if ( LIMINF < X < LIMSUP)
  {
    digitalWrite(STEP, LOW);
    digitalWrite(STEP, LOW);
  }
  }