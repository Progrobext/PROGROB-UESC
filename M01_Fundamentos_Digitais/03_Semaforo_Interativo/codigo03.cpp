 // Projeto 2-2 Semáforo Interativo
int carRed = 11;     
int carYellow = 10;
int carGreen = 9;

int pedRed = 2;     
int pedGreen = 1;

int button = 3; // pino do botão     
int crossTime = 5000; // tempo para que os pedestres atravessem
unsigned long changeTime;

void setup() {
 pinMode(carRed, OUTPUT);
 pinMode(carYellow, OUTPUT);
 pinMode(carGreen, OUTPUT);
 pinMode(pedRed, OUTPUT);
 pinMode(pedGreen, OUTPUT);
 pinMode(button, INPUT); // botão no pino 2
 // acende a luz verde
 digitalWrite(carGreen, HIGH);
 digitalWrite(pedRed, HIGH);
}

void loop() {
  int state = digitalRead(button);

  /* verifica se o botão foi pressionado e se transcorreram
  5 segundos desde a última vez que isso ocorreu */
  if (state == HIGH && (millis() - changeTime) > 5000) {
    // Chama a função para alterar as luzes
    changeLights();
  }
}

void changeLights() {
  digitalWrite(carGreen, LOW);     // apaga o verde
  digitalWrite(carYellow, HIGH);   // acende o amarelo
  delay(2000);                     // espera 2 segundos

  digitalWrite(carYellow, LOW);    // apaga o amarelo
  digitalWrite(carRed, HIGH);      // acende o vermelho
  delay(1000);                     // espera 1 segundo, por segurança

  digitalWrite(pedRed, LOW);       // apaga o vermelho dos pedestres
  digitalWrite(pedGreen, HIGH);    // acende o verde dos pedestres
  delay(crossTime);                // espera por um intervalo de tempo predefinido

  // pisca o verde dos pedestres
  for (int x = 0; x < 10; x++) {
    digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
  }

  // acende o vermelho dos pedestres
  digitalWrite(pedRed, HIGH);
  delay(500);

  digitalWrite(carYellow, HIGH);   // acende o amarelo
  digitalWrite(carRed, LOW);       // apaga o vermelho
  delay(1000);

  digitalWrite(carGreen, HIGH);    // acende o verde
  digitalWrite(carYellow, LOW);    // apaga o amarelo

  // registra o tempo desde a última alteração no semáforo
  changeTime = millis();
  // depois retorna para o loop principal do programa
}