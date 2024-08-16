#define photoDiodePin A0 // Pin donde se conecta el fotodiodo
// Generalmente, debería usar "unsigned long" para variables que contienen tiempo
// El valor será rápidamente demasiado grande para ser almacenado en un int
unsigned long previousMillis = 0;  // almacenará la última vez que se actualizó el LED
const long fs = 20000;
const long interval = 500/fs;  // intervalo de parpadeo (milisegundos)
int lectura; int bit;

int max_lectura = 0;
int min_lectura = 10230;

int threshold = 150; // Umbral ajustable para la luz

void setup() {
  Serial.begin(115200); // Inicializa la comunicación serial
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // guardar la última vez que parpadeó el LED
    
    lectura = analogRead(photoDiodePin)*10; // Lee el valor analógico del fotodiodo
    if (lectura > max_lectura) { max_lectura = lectura; }
    if (lectura < min_lectura) { min_lectura = lectura; }
    
    threshold = (max_lectura + min_lectura)/2;
    if (lectura > threshold) { bit = 1; } else { bit = 0; }
    Serial.print("bit*2550:");
    Serial.print("");
    Serial.print(bit*2550);
    Serial.print(",");
    Serial.print("lectura:");
    Serial.print("");
    Serial.print(lectura);
    Serial.print(",");
    Serial.print("threshold:");
    Serial.print("");
    Serial.print(threshold);
    Serial.print(",");
    Serial.print("max_lectura:"); 
    Serial.print("");
    Serial.print(max_lectura); 
    Serial.print(",");
    Serial.print("min_lectura:");
    Serial.print("");
    Serial.println(min_lectura);
    max_lectura = threshold;
    min_lectura = threshold;
  }
}
