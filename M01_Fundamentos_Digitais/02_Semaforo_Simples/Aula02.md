# Semáforo com LEDs e Arduino

[Slides da Aula](https://www.figma.com/slides/s5jNLF4ZcP9EnlOSh17t7u/Pratica-03---ProjExt?node-id=27-188&t=mOUlm4v7F0YT2Reg-1)

[Circuito no TinkerCAD](https://www.tinkercad.com/things/jfaUHLdqSaN-semaforo-normal?sharecode=A6rVPmku4WJfubQlG11RwdZQZYjcIZRK5igHntyRjFs)

**Introdução:**
Nesta prática, vamos simular um semáforo real usando três LEDs e o Arduino. A sequência segue o padrão do Reino Unido, onde há uma transição com luz vermelha e amarela acesas antes de mudar para o verde.

**Componentes Necessários:**

* 1x Arduino Uno
* 1x Protoboard
* 1x LED vermelho difuso
* 1x LED amarelo difuso
* 1x LED verde difuso
* 3x Resistores de 150Ω
* Fios jumper

**Montando o Circuito:**

1. Conecte o LED vermelho ao pino 11, o amarelo ao pino 10 e o verde ao pino 9.
2. Cada LED deve ter um resistor de 150Ω ligado ao seu terminal negativo (cátodo), indo para o GND.
3. Use um barramento de terra comum na protoboard.

![Circuito Semáforo](https://github.com/Progrobext/PROGROB-UESC/blob/main/Imagens/circuito02.png)

**Código Arduino:**

```cpp
// Projeto 2-1 Semáforo Com LEDs

int ledDelay = 3500; // Tempo de espera entre as alterações

int redPin = 11;
int yellowPin = 10;
int greenPin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  digitalWrite(redPin, HIGH);  // Acende a luz vermelha
  delay(ledDelay);             // Espera 3.5 segundos

  digitalWrite(yellowPin, HIGH); // Vermelha + Amarela (transição)
  digitalWrite(redPin, LOW);     // Apaga vermelha
  delay(1500);                   // Espera 1.5 segundos

  digitalWrite(greenPin, HIGH);  // Verde acesa
  digitalWrite(yellowPin, LOW);  // Apaga amarela
  delay(ledDelay);               // Espera 3.5 segundos

  digitalWrite(yellowPin, HIGH); // Amarela acesa
  digitalWrite(greenPin, LOW);   // Apaga verde
  delay(1500);                   // Espera 1.5 segundos

  digitalWrite(yellowPin, LOW);  // Apaga amarela
  // O loop recomeça: vermelho → vermelho+amarelo → verde → amarelo
}
```

**O que aprendemos:**

* Como simular um semáforo real com LEDs.
* Como programar uma sequência com `digitalWrite()` e `delay()`.
* Como nomear pinos e usar variáveis para deixar o código mais organizado.

**Desafio:**

* Modifique o código para adaptar a sinalização ao padrão brasileiro (verde → amarelo → vermelho, sem vermelho+amarelo).

---
