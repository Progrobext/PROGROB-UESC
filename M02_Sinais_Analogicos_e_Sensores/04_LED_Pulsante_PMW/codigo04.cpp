// Projeto 1 Lâmpada pulsante

//Declaração de Variáveis
int ledPin = 11;
float sinVal;
int ledVal;

void setup() {
  //Definindo o Pino do Led
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //Estrutura de repetição
  for (int x = 0; x < 180; x++) {
    // converte graus para radianos e, então, obtém o valor do seno
    sinVal = sin(x * (3.1416 / 180));
    ledVal = int(sinVal * 255);
    analogWrite(ledPin, ledVal); //Escreve no pino
    delay(25);
  }
}