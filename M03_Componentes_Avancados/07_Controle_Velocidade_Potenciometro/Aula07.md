# Controle de Velocidade com Potenciômetro

**Introdução:**
Nesta continuação do Projeto 6, vamos adicionar um **potenciômetro** ao circuito dos 10 LEDs. Com isso, poderemos **controlar a velocidade** das luzes enquanto o programa estiver rodando!

**Componentes Necessários:**

* 1x Potenciômetro de 4,7kΩ
* Circuito anterior com:

  * 10x LEDs
  * 10x Resistores de 220Ω ou 330Ω
* Arduino Uno + Protoboard
* 3x Fios Jumper

**Montagem do Potenciômetro:**

* **Terminal esquerdo → 5V do Arduino**
* **Terminal do meio → Pino A2**
* **Terminal direito → GND (terra)**

**Escrevendo o Código:**

```cpp
// Projeto 3-2 Controle de Velocidade com Potenciômetro
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int ledDelay;
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = A2;

void setup() {
  for (int x = 0; x < 10; x++) {
    pinMode(ledPin[x], OUTPUT);
  }
  changeTime = millis();
}

void loop() {
  ledDelay = analogRead(potPin);

  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}

void changeLED() {
  for (int x = 0; x < 10; x++) {
    digitalWrite(ledPin[x], LOW);
  }

  digitalWrite(ledPin[currentLED], HIGH);
  currentLED += direction;

  if (currentLED == 9) {
    direction = -1;
  }
  if (currentLED == 0) {
    direction = 1;
  }
}
```

**Entendendo o Código:**

* `analogRead(potPin);` → Lê o valor do potenciômetro (0 a 1023).
* O valor lido é usado diretamente como `delay`, controlando a velocidade dos LEDs.
* Quanto menor o valor, mais rápido as luzes piscam.

**Testando:**

1. Monte o circuito com o potenciômetro.
2. Faça o upload do código para o Arduino.
3. Gire o botão do potenciômetro e veja a velocidade mudar!

**Desafio:**

* E se usássemos o potenciômetro para controlar a **intensidade de um LED**? Tente!
* Modifique para ao invés de aumentar a velocidade, ele diminuir.

---
