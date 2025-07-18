byte ledPin[] = {8, 9, 10, 11, 12, 13};  // Cria um array para os pinos dos LEDs
int ledDelay = 80;                        // Intervalo entre as alterações
int direction = 1;
int currentLED = 0;
unsigned long changeTime;

void setup() {
  // Define todos os pinos como saída
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);
  pinMode(ledPin[3], OUTPUT);
  pinMode(ledPin[4], OUTPUT);
  pinMode(ledPin[5], OUTPUT);
  
  changeTime = millis();
}

void loop() {
  // Verifica se já transcorreram ledDelay ms desde a última alteração
  if ((millis() - changeTime) > ledDelay) {
    // Apaga todos os LEDs
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], LOW);

    // Acende o LED atual
    digitalWrite(ledPin[currentLED], HIGH);

    // Incrementa de acordo com o valor de direction
    currentLED += direction;

    // Altera a direção se tivermos atingido o fim
    if (currentLED == 5) {
      direction = -1;
    }
    if (currentLED == 0) {
      direction = 1;
    }

    // Atualiza o tempo
    changeTime = millis();
  }
}