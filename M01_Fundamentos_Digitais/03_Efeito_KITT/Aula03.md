# Efeito de Iluminação Sequencial com LEDs**

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
```

**Entendendo o Código:**

* `ledPin[]`: array com os pinos dos LEDs.
* `ledDelay`: define o tempo entre cada troca de LED.
* `direction`: controla o sentido (avança ou volta).
* `currentLED`: identifica qual LED está aceso.
* `millis()`: retorna o tempo desde o início da execução do programa.

**Executando:**

* Conecte o Arduino ao computador via cabo USB.
* Abra a Arduino IDE, cole o código e faça o upload.
* Observe o efeito de ida e volta dos LEDs.
* Em caso de falha, revise as conexões e os pinos utilizados.

**Desafio:**

* Altere o valor de `ledDelay` para ajustar a velocidade.
* Modifique o código para acender **dois LEDs ao mesmo tempo**.

---
