
---

# Materiais de Aula - Práticas de Robótica Educacional

---

## Prática 3 - Parte 2: Controle de Velocidade com Potenciômetro

### 1. Roteiro de Aula (Professor)

* **Título da Aula:** Controle da Velocidade dos LEDs com Potenciômetro
* **Duração Estimada:** 50-60 minutos
* **Objetivos de Aprendizagem:**

  * Compreender o funcionamento do potenciômetro como divisor de tensão.
  * Integrar entradas analógicas ao código Arduino com `analogRead()`.
  * Modificar dinamicamente o comportamento do sistema com base em entradas do usuário.
  * Controlar a velocidade de LEDs sequenciais com leitura analógica.

* **Materiais:**

  * Computador com Arduino IDE ou acesso ao Tinkercad.
  * Kit Arduino: Placa Arduino Uno, cabo USB.
  * Protoboard com circuito do Projeto 5 já montado (10 LEDs com resistores).
  * 1 potenciômetro giratório de 4,7kΩ.
  * Fios jumper.

* **Procedimento:**

  1. **Introdução:** Relembrar o efeito de LEDs sequenciais (efeito KITT). Introduzir o conceito de controle de velocidade com potenciômetro.
  2. **Componentes e Conexão:** Explicar o funcionamento do potenciômetro, demonstrar ligação correta (5V, GND e A2).
  3. **Explicação do Código:** Apresentar modificações no código anterior para usar `analogRead()` e variar o `ledDelay`.
  4. **Montagem e Testes:** Alunos conectam o potenciômetro ao circuito e testam a variação da velocidade.
  5. **Discussão Final:** Comentar aplicações práticas de entradas analógicas.

* **Avaliação:** Montagem correta do potenciômetro, variação funcional da velocidade, entendimento de `analogRead()`.

* **Desafios (Opcional/Tarefa):** Ajustar o código para inverter o sentido da sequência com um botão ou sensor.

---

### 2. Esboço dos Slides (Prática 3 - Parte 2)

* **Slide 1:** Título: Prática 3 - Parte 2: Controle com Potenciômetro
* **Slide 2:** Relembrando: LEDs sequenciais (Projeto 5)
* **Slide 3:** O que é um Potenciômetro? (Imagem + explicação como divisor de tensão)
* **Slide 4:** Conexão do Potenciômetro (Esquema simples: 5V - A2 - GND)
* **Slide 5:** Leitura Analógica com `analogRead()`
* **Slide 6:** Atualizando o Código (destaque na linha do `ledDelay = analogRead(potPin);`)
* **Slide 7:** Testando o Controle de Velocidade (Simulação ou montagem)
* **Slide 8:** Experimente: Gire o potenciômetro!
* **Slide 9:** Discussão: O que mais podemos controlar com um potenciômetro?

---

### 3. Apostila do Aluno (Prática 3 - Parte 2)

**(Cabeçalho: Prática 3 – Parte 2: Controle de Velocidade com Potenciômetro)**

**Introdução:**
Nesta continuação do Projeto 5, vamos adicionar um **potenciômetro** ao circuito dos 10 LEDs. Com isso, poderemos **controlar a velocidade** das luzes enquanto o programa estiver rodando!

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