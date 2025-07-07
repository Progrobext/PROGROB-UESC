### Efeito de Iluminação Sequencial com LEDs**

**Introdução:**
Nesta prática, você aprenderá a controlar 10 LEDs de forma sequencial utilizando **arrays no Arduino**, criando um efeito visual semelhante ao do carro **KITT**, da série *A Super Máquina*.

**Componentes Necessários:**

* 1x Placa Arduino Uno
* 1x Cabo USB
* 1x Protoboard
* 10x LEDs (5mm)
* 10x Resistores de 220Ω
* Fios jumper

**Montando o Circuito:**
Monte o circuito conectando os LEDs aos pinos digitais 4 a 13, cada um com um resistor em série.

**(Inserir diagrama do circuito aqui)**

**Código Arduino:**

```cpp
// Projeto 3–1 Efeito de Iluminação Sequencial com LEDs

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};  // Pinos dos LEDs
int ledDelay = 80;                                   // Tempo entre os LEDs
int direction = 1;                                   // Direção da sequência
int currentLED = 0;
unsigned long changeTime;

void setup() {
  for (int x = 0; x < 10; x++) {
    pinMode(ledPin[x], OUTPUT);
  }
  changeTime = millis();
}

void loop() {
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}

void changeLED() {
  for (int x = 0; x < 10; x++) {
    digitalWrite(ledPin[x], LOW); // Apaga todos os LEDs
  }

  digitalWrite(ledPin[currentLED], HIGH); // Acende o LED atual

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

* `ledPin[]`: array com os pinos dos LEDs.
* `ledDelay`: define o tempo entre cada troca de LED.
* `direction`: controla o sentido (avança ou volta).
* `currentLED`: identifica qual LED está aceso.
* `millis()`: retorna o tempo desde o início da execução do programa.
* `changeLED()`: função que troca o LED aceso conforme a direção.

**Executando:**

* Conecte o Arduino ao computador via cabo USB.
* Abra a Arduino IDE, cole o código e faça o upload.
* Observe o efeito de ida e volta dos LEDs.
* Em caso de falha, revise as conexões e os pinos utilizados.

**Desafio:**

* Altere o valor de `ledDelay` para ajustar a velocidade.
* Modifique o código para acender **dois LEDs ao mesmo tempo**.

---
