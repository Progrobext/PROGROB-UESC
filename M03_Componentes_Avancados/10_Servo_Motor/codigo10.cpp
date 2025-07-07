#include <Servo.h>

Servo myservo;
int potPin = A0;      // Pino onde o potenciômetro está conectado.
int potValue = 0;

void setup() {
  myservo.attach(9);   // Anexa o servo ao pino 9.
}

void loop() {
  potValue = analogRead(potPin);             // Lê valor de 0 a 1023.
  int angle = map(potValue, 0, 1023, 0, 180);  // Mapeia para 0 a 180°.
  myservo.write(angle);                        // Move o servo para o ângulo.
  delay(15);                                   // Pequeno atraso para estabilidade.
}