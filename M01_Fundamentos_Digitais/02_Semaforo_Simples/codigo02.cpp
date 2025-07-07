//Projeto 2-1 Semáforo Com LEDs

int ledDelay = 3500; //Espera entre as alterações

int redPin = 11;
int yellowPin = 10;
int greenPin = 9;

void setup() {
  // configura os pinos como saída
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  
  digitalWrite(redPin, HIGH); // acende a luz vermelha
  delay(ledDelay); // espera 3.5 segundos

  
  digitalWrite(yellowPin, HIGH); // acende a luz amarela
  digitalWrite(redPin, LOW); // apaga a luz vermelha
  delay(1500);  // espera 1.5 segundos
  
  digitalWrite(greenPin, HIGH); // acende a luz verde
  digitalWrite(yellowPin, LOW); // apaga a luz amarela
  delay(ledDelay);  // espera 3.5 segundos

  digitalWrite(yellowPin, HIGH); // acende a luz amarela
  digitalWrite(greenPin, LOW); // apaga a luz verde
  delay(1500);// espera 1.5 segundos

  digitalWrite(yellowPin, LOW); // apaga a luz amarela

  // agora nosso loop se repete
}