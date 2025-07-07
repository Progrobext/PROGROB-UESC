
---

# Materiais de Aula - Práticas de Robótica Educacional

---

## Prática 4: Sons e Alarmes com Piezoelétrico

### 1. Roteiro de Aula (Professor)

* **Título da Aula:** Sons e Alarmes com o Buzzer Piezoelétrico
* **Duração Estimada:** 50-60 minutos
* **Objetivos de Aprendizagem:**

  * Apresentar o componente piezoelétrico e suas aplicações em sistemas embarcados.
  * Explorar frequências sonoras e sua relação com a percepção de som.
  * Utilizar a função `tone()` para gerar sons com o Arduino.
  * Criar padrões sonoros que simulem alarmes ou toques musicais.
* **Materiais:**

  * Computador com Arduino IDE ou Tinkercad.
  * Kit Arduino: Arduino Uno, cabo USB, protoboard, buzzer piezoelétrico, resistor de 100Ω (opcional), fios jumper.
* **Procedimento:**

  1. **Introdução:** Mostrar exemplos de uso real do buzzer (alarme de carro, micro-ondas, campainha).
  2. **Componentes e Funcionamento:** Apresentar o buzzer piezoelétrico e como ele gera som com vibração por frequência.
  3. **Montagem do Circuito:** Mostrar o diagrama de ligação simples com o pino digital e GND.
  4. **Código Básico:** Explicar o uso das funções `tone()` e `noTone()`.
  5. **Criação de Alarmes:** Desenvolver um alarme simples com diferentes tons.
  6. **Exploração:** Tocar uma sirene com o piezo.
  7. **Explorando Músicas:** Tocar uma música com o piezo.
* **Avaliação:** Verificar correta montagem do circuito e funcionamento dos sons gerados. Avaliar compreensão de frequências e função `tone()`.
* **Desafios (Opcional/Tarefa):**

  * Criar um toque personalizado.

---

### 2. Esboço dos Slides (Prática 4)

* **Slide 1:** Título: Prática 4 – Sons com Piezoelétrico
* **Slide 2:** Onde usamos sons em dispositivos? (Exemplos do cotidiano)
* **Slide 3:** O que é o Buzzer Piezoelétrico?
* **Slide 4:** Como o som é gerado? (Frequência e vibração)
* **Slide 5:** Componentes Utilizados
* **Slide 6:** Esquema de Montagem (Arduino + Buzzer)
* **Slide 7:** Função tone() e noTone()
* **Slide 8:** Código para tocar sons simples
* **Slide 9:** Código para uma sirene simples
* **Slide 10:** Explicação do código da sirene
* **Slide 11:** Explicação de Teoria Musical: Tempo, Frequência e Pitch (Tabela de notas musicais)
* **Slide 12:** Tocar uma melodia
* **Slide 13:** Hora de Testar!
* **Slide 14:** Desafios Extras: Crie seu som!
* **Slide 15:** Conclusão e Aplicações Futuras

---

### 3. Apostila do Aluno (Prática 4)

**(Cabeçalho: Prática 4 – Sons com o Piezoelétrico)**

**Introdução:**

Nesta prática, você vai conhecer o buzzer piezoelétrico e aprender a gerar sons com o Arduino. Utilizaremos a função `tone()` para controlar a frequência sonora e criaremos alarmes ou melodias simples.

**Componentes Necessários:**

* 1x Placa Arduino Uno
* 1x Cabo USB
* 1x Protoboard
* 1x Buzzer piezoelétrico
* 1x Resistor de 100Ω (opcional)
* Fios jumper

**Montando o Circuito:**

Conecte o pino positivo do buzzer ao pino digital 7 do Arduino, e o pino negativo ao GND. O resistor de 100Ω pode ser colocado em série para limitar corrente (caso necessário).

**(Inserir diagrama do circuito aqui)**

**Código Arduino:**

```cpp
// Projeto 4-1 Sons com o sonorizador piezo
int piezo = 7;

void setup() {
  pinMode(piezo, OUTPUT);
}

void loop() {
  tone(piezo, 200);  // som grave
  delay(1500);
  noTone(piezo);
  delay(300);

  tone(piezo, 1000); // som médio
  delay(1300);
  noTone(piezo);
  delay(200);

  tone(piezo, 3000); // som agudo
  delay(1150);
  noTone(piezo);
  delay(400);

  delay(1000); // pausa final
}
```

**Entendendo o Código:**

* `tone(pino, frequência)`: Toca uma frequência sonora no pino indicado.
* `noTone(pino)`: Para o som.
* `delay()`: Controla o tempo de duração do som e das pausas.

**Alarme sirene:**

```cpp
// Projeto 4-2 Sirene com o sonorizador piezo
float sinVal;
int toneVal;
int piezo = 7;

void setup() {
  pinMode(piezo, OUTPUT);
}

void loop() {
  for (int x = 0; x < 180; x++) {
    sinVal = sin(x * (3.1416 / 180));
    toneVal = 2000 + int(sinVal * 1000); // de 1000 a 3000 Hz
    tone(piezo, toneVal);
    delay(2);
  }
}
```
**Entendendo o Código:**

* `tone(pino, frequência)`: Toca uma frequência sonora no pino indicado.
* `noTone(pino)`: Para o som.

**Tocador de Melodia:**

```cpp
// Projeto 4-3 Tocador de melodia com sonorizador piezo

#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494

#define WHOLE      1
#define HALF       0.5
#define QUARTER    0.25
#define EIGHTH     0.125
#define SIXTEENTH  0.0625

int tune[] = {
  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_A3,
  NOTE_C4, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_F3, NOTE_G3, NOTE_F3,
  NOTE_E3, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_B3,
  NOTE_C4, NOTE_D4
};

float duration[] = {
  EIGHTH, QUARTER + EIGHTH, SIXTEENTH, QUARTER, QUARTER, HALF, HALF,
  HALF, QUARTER, QUARTER, HALF + QUARTER, QUARTER, QUARTER, QUARTER,
  QUARTER + EIGHTH, EIGHTH, QUARTER, QUARTER, QUARTER, EIGHTH, EIGHTH,
  QUARTER, QUARTER, QUARTER, QUARTER, HALF + QUARTER
};

int length;
int piezo = 7;

void setup() {
  pinMode(piezo, OUTPUT);
  length = sizeof(tune) / sizeof(tune[0]);
}

void loop() {
  for (int x = 0; x < length; x++) {
    tone(piezo, tune[x]);
    delay(1500 * duration[x]);
    noTone(8);
  }
  delay(3000); // pausa entre repetições da melodia
}
```
**Entendendo o Código:**

* `tone(pino, frequência)`: Toca uma frequência sonora no pino indicado.
* `noTone(pino)`: Para o som.

**Desafios:**

* Crie uma nova sequência com mais notas.
* Crie uma sirene de emergência com tons diferentes.
* Crie uma musica nova.

---