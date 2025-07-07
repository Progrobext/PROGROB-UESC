// Projeto 1 - LED piscante (Capítulo 2, Arduino Básico)

// Declara uma variável inteira chamada 'ledPin' e atribui a ela o valor 10.
// Isso significa que conectaremos o LED ao pino digital 10 do Arduino.
// Usar uma variável torna o código mais fácil de ler e modificar.
int ledPin = 10;

// A função setup() é executada uma vez quando o Arduino liga ou é resetado.
// É usada para configurações iniciais.
void setup() {
  // Configura o pino digital definido pela variável 'ledPin' (pino 10) como SAÍDA (OUTPUT).
  // Isso significa que o Arduino enviará sinais (voltagem) através deste pino para controlar o LED.
  pinMode(ledPin, OUTPUT);
}

// A função loop() é executada repetidamente após a função setup() terminar.
// É onde a lógica principal do programa fica.
void loop() {
  // Define o pino 'ledPin' (pino 10) como HIGH (alto/ligado).
  // Isso envia 5V para o pino, acendendo o LED.
  digitalWrite(ledPin, HIGH);

  // Pausa a execução do programa por 1000 milissegundos (1 segundo).
  // O LED permanecerá aceso durante essa pausa.
  delay(1000);

  // Define o pino 'ledPin' (pino 10) como LOW (baixo/desligado).
  // Isso envia 0V para o pino, apagando o LED.
  digitalWrite(ledPin, LOW);

  // Pausa a execução do programa por mais 1000 milissegundos (1 segundo).
  // O LED permanecerá apagado durante essa pausa.
  delay(1000);

  // O loop() termina aqui e recomeça imediatamente do início,
  // fazendo o LED piscar continuamente.
}