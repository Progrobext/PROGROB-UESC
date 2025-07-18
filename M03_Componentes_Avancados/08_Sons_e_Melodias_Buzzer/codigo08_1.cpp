// Este código toca sons com diferentes frequências e durações, incluindo pausas variadas

int piezo = 7; // Pino conectado ao buzzer piezoelétrico

void setup() {
  pinMode(piezo, OUTPUT); // Define o pino do buzzer como saída
}

void loop() {
  // Toca som grave (ex: 200 Hz) por 500ms
  tone(piezo, 200);        // Frequência grave
  delay(1500);              // Duração do som
  noTone(piezo);           // Para o som
  delay(300);              // Pausa de 300ms

  // Toca som médio (ex: 1000 Hz) por 300ms
  tone(piezo, 1000);       // Frequência média
  delay(1300);              // Duração do som
  noTone(piezo);           // Para o som
  delay(200);              // Pausa de 200ms

  // Toca som agudo (ex: 3000 Hz) por 150ms
  tone(piezo, 3000);       // Frequência aguda
  delay(1150);              // Duração do som
  noTone(piezo);           // Para o som
  delay(400);              // Pausa de 400ms

  delay(1000);             // Pausa de 1 segundo antes de repetir o loop
}