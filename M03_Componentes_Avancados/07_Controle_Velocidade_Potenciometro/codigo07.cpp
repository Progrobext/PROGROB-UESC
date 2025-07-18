byte ledPin[] = {8, 9, 10, 11, 12, 13};  // Array para os pinos dos LEDs
int ledDelay;                                       // Intervalo entre as alterações
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 5;                                     // Pino de entrada para o potenciômetro

void setup() {
  for (int x = 0; x < 6; x++) {
    pinMode(ledPin[x], OUTPUT);                    // Define todos os pinos como saída
  }
  changeTime = millis();
}

void loop() {
  ledDelay = analogRead(potPin);                   // Lê o valor do potenciômetro

  // Verifica se transcorreram ledDelay milissegundos desde a última alteração
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}

void changeLED() {
  // Apaga todos os LEDs
  for (int x = 0; x < 6; x++) {
    digitalWrite(ledPin[x], LOW);
  }

  // Acende o LED atual
  digitalWrite(ledPin[currentLED], HIGH);

  // Incrementa de acordo com a direção
  currentLED += direction;

  // Altera a direção se tiver atingido o fim
  if (currentLED == 5) {
    direction = -1;
  }
  if (currentLED == 0) {
    direction = 1;
  }
}
