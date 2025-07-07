// Projeto 4-2 Sirene com o sonorizador piezo

float sinVal;
int toneVal;
int piezo=7;

void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  for (int x = 0; x < 180; x++) {
    // converte graus para radianos, e depois obtém o valor do seno
    sinVal = sin(x * (3.1416 / 180)); //valores entre -1 e 1

    // Gera uma frequência entre 1000 e 3000 Hz (média com variação)
    int toneVal = 2000 + int(sinVal * 1000); // Resultado: 1000 Hz a 3000 Hz

    tone(piezo, toneVal);  // Toca frequência calculada
    delay(2);              // Pequeno intervalo para criar efeito de transição
  }
}