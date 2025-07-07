// Projeto 14 – Sensor de luz (Capítulo 4, Arduino Básico)

// Define o pino digital onde o sonorizador piezo está conectado
int piezoPin = 8;
// Define o pino analógico onde o LDR (e o divisor de tensão) está conectado
int ldrPin = 0; // Pino Analógico A0
// Variável para armazenar o valor lido do LDR (0 a 1023)
int ldrValue = 0;

// A função setup() é executada uma vez no início.
void setup() {
 
}

// A função loop() é executada repetidamente.
void loop() {
  // Lê o valor da voltagem no pino analógico 'ldrPin' (A0).
  // O valor será entre 0 (0V) e 1023 (5V), dependendo da resistência do LDR
  // (mais luz = menor resistência = menor voltagem = menor valor lido).
  ldrValue = analogRead(ldrPin);

  // Emite um tom de frequência fixa (1000 Hz) no 'piezoPin' (pino 8).
  // A duração do tom não é especificada aqui, então ele tocaria continuamente
  // se não fosse interrompido.
  tone(piezoPin, 1000);

  // Pequena pausa de 25 milissegundos para que o tom seja audível (bip curto).
  delay(25);

  // Interrompe o tom que está tocando no 'piezoPin'.
  noTone(piezoPin);

  // Pausa a execução pelo número de milissegundos lido do LDR ('ldrValue').
  // Se há muita luz, 'ldrValue' será baixo, e a pausa será curta (bipes rápidos).
  // Se há pouca luz, 'ldrValue' será alto, e a pausa será longa (bipes lentos).
  delay(ldrValue);

  // O loop recomeça, lendo o sensor e emitindo outro bip.
}