//Projeto 3-1 Efeito de Iluminação Sequencial com LEDs

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};  // Cria um array para os pinos dos LEDs
int ledDelay = 80;                                   // Intervalo entre as alterações
int direction = 1;
int currentLED = 0;
unsigned long changeTime;

void setup() {
  // Define todos os pinos como saída
  for (int x = 0; x < 10; x++) {
    pinMode(ledPin[x], OUTPUT);
  }
  changeTime = millis();
}

void loop() {
  // Verifica se já transcorreram ledDelay ms desde a última alteração
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}

void changeLED() {
  // Apaga todos os LEDs
  for (int x = 0; x < 10; x++) {
    digitalWrite(ledPin[x], LOW);
  }

  // Acende o LED atual
  digitalWrite(ledPin[currentLED], HIGH);

  // Incrementa de acordo com o valor de direction
  currentLED += direction;

  // Altera a direção se tivermos atingido o fim
  if (currentLED == 9) {
    direction = -1;
  }
  if (currentLED == 0) {
    direction = 1;
  }
}