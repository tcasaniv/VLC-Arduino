const int ledPin = LED_BUILTIN;  // el número del pin del LED | PIN 13
int ledState = LOW;  // ledState used to set the LED
// Generalmente, debería usar "unsigned long" para variables que contienen tiempo
// El valor será rápidamente demasiado grande para ser almacenado en un int
unsigned long previousMillis = 0;  // almacenará la última vez que se actualizó el LED
const long fs = 5000;
const long interval = 500/fs;  // intervalo de parpadeo (milisegundos)

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT); // establece el pin digital como salida:
}

void loop() {
  Serial.println(ledState);
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // guardar la última vez que parpadeó el LED
    
    if (ledState == LOW) { ledState = HIGH; } else { ledState = LOW; }
    digitalWrite(ledPin, ledState); Serial.println(ledState);
  }
}
