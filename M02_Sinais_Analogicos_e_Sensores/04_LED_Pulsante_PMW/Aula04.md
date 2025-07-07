# Lâmpada Pulsante com PWM

**Introdução:**
Nesta prática, vamos aprender a controlar o brilho de um LED usando a técnica de PWM (Pulse Width Modulation) e a usar um interruptor deslizante com o Arduino. Vamos montar um circuito com um LED verde e um interruptor, e usaremos matemática para criar um efeito suave de pulsação.

**Componentes Necessários:**

* 1x Placa Arduino Uno
* 1x Cabo USB
* 1x Protoboard
* 1x LED verde difuso de 5 mm
* 1x Resistor de 220Ω ou 330Ω
* 1x Interruptor deslizante
* Fios jumper

**Montando o Circuito:**
Conecte o LED ao pino 11 do Arduino com um resistor em série. Use o interruptor deslizante para controlar a alimentação ou ativação do circuito.

**(Inserir diagrama do circuito aqui)**

**Código Arduino:**

```cpp
// Projeto 1 Lâmpada pulsante

int ledPin = 11;
float sinVal;
int ledVal;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int x = 0; x < 180; x++) {
    sinVal = sin(x * (3.1416 / 180)); // Converte para radianos e obtém o seno
    ledVal = int(sinVal * 255);       // Converte para escala PWM (0 a 255)
    analogWrite(ledPin, ledVal);      // Define brilho do LED
    delay(25);                        // Espera um pouco antes de continuar
  }
}
```

**Entendendo o Código:**

* `analogWrite(pino, valor)`: Controla o brilho via PWM (0 = apagado, 255 = brilho máximo).
* `sin()`: Função matemática para suavizar a variação de brilho.
* `for`: Repete a variação gradualmente de 0 a 180 graus.

**Executando:**

* Faça o upload do código (IDE) ou clique em “Start Simulation” (Tinkercad). O LED deverá pulsar suavemente!

**Desafio:**

* Altere a função matemática ou o tempo de delay para experimentar outros efeitos de brilho.

---