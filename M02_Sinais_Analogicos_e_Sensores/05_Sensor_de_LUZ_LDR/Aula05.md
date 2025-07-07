# Sentindo o Ambiente: Sensor de Luz e Som
[Slides da Aula](https://www.figma.com/slides/YSVpbJFXwkHVURdGHEZ4nB/Pratica-05---ProjExt?t=rj0gnQzaCUDPYbNN-1)
**Introdução:**
Nesta prática, vamos fazer o Arduino interagir com o ambiente! Usaremos um sensor de luz (LDR) para medir a luminosidade e um buzzer piezo para criar um som. O interessante é que a velocidade dos bipes do buzzer vai mudar dependendo de quanta luz o sensor detecta. É como um pequeno "contador Geiger" para luz!

**Componentes Necessários:**
*   1x Placa Arduino Uno (ou similar)
*   1x Cabo USB
*   1x Protoboard (Matriz de Contato)
*   1x LDR (Fotorresistor)
*   1x Resistor de 10kΩ (Cores: Marrom, Preto, Laranja)
*   1x Buzzer Piezoelétrico (Piezo)
*   Pelo menos 5x Fios Jumper (macho-macho)

**Entendendo os Componentes:**
*   **LDR (Light Dependent Resistor - Resistor Dependente de Luz):** É um tipo especial de resistor que muda sua resistência elétrica dependendo da quantidade de luz que o atinge.
    *   Com **muita luz**, a resistência do LDR diminui.
    *   Com **pouca luz**, a resistência do LDR aumenta.
*   **Buzzer Piezoelétrico:** É um pequeno dispositivo que produz som quando uma corrente elétrica passa por ele de uma certa maneira.
*   **Resistor de 10kΩ:** Usaremos este resistor junto com o LDR para criar um "divisor de tensão". Isso nos permite ler a mudança de resistência do LDR como uma mudança de voltagem, que o Arduino pode entender.

**Montando o Circuito:**
Siga o diagrama abaixo com atenção. O LDR não tem uma "perna certa" para conectar (não tem polaridade). O Piezo geralmente tem um terminal marcado com `+` (positivo) ou um fio vermelho, que deve ser conectado ao pino do Arduino, e o outro terminal (negativo ou fio preto) ao GND.

![Circuito Sensor de Luz](https://github.com/Progrobext/PROGROB-UESC/blob/main/Imagens/circuito05.png)

**Passos da Montagem:**
1.  Conecte o pino `5V` do Arduino a uma das linhas vermelhas (+) da protoboard (barramento de alimentação positivo).
2.  Conecte o pino `GND` do Arduino a uma das linhas azuis (-) da protoboard (barramento de alimentação negativo/terra).
3.  Encaixe o LDR na protoboard.
4.  Conecte um terminal do LDR ao barramento (+) (5V).
5.  Conecte o outro terminal do LDR ao pino analógico `A0` do Arduino.
6.  **Importante:** Na mesma linha da protoboard onde você conectou o pino A0 e o LDR, conecte uma perna do resistor de 10kΩ.
7.  Conecte a outra perna do resistor de 10kΩ ao barramento (-) (GND).
8.  Encaixe o Piezo na protoboard.
9.  Conecte o terminal positivo (+) do Piezo ao pino digital `8` do Arduino.
10. Conecte o terminal negativo (-) do Piezo ao barramento (-) (GND).

**Escrevendo o Código:**
1.  Conecte o Arduino ao computador com o cabo USB.
2.  Abra o Arduino IDE (ou crie um novo circuito no Tinkercad e vá para a aba Código > Texto).
3.  Digite (ou copie e cole) o seguinte código:

```c++
// Projeto 14 – Sensor de luz

// Define o pino digital onde o sonorizador piezo está conectado
int piezoPin = 8;
// Define o pino analógico onde o LDR (e o divisor de tensão) está conectado
int ldrPin = 0; // Pino Analógico A0
// Variável para armazenar o valor lido do LDR (0 a 1023)
int ldrValue = 0;

// A função setup() é executada uma vez no início.
void setup() {
  // Para este projeto, não precisamos de nenhuma configuração inicial aqui.
  // O comando tone() e analogRead() não exigem pinMode() para estes usos.
}

// A função loop() é executada repetidamente.
void loop() {
  // Lê o valor da voltagem no pino analógico 'ldrPin' (A0).
  // O valor será entre 0 (0V) e 1023 (5V).
  // Mais luz = menor resistência do LDR = menor voltagem em A0 = menor ldrValue.
  // Pouca luz = maior resistência do LDR = maior voltagem em A0 = maior ldrValue.
  ldrValue = analogRead(ldrPin);

  // Emite um tom de frequência fixa (1000 Hz) no 'piezoPin' (pino 8).
  tone(piezoPin, 1000);

  // Pequena pausa de 25 milissegundos para que o tom seja audível (bip curto).
  delay(25);

  // Interrompe o tom que está tocando no 'piezoPin'.
  noTone(piezoPin);

  // Pausa a execução pelo número de milissegundos lido do LDR ('ldrValue').
  // Se há muita luz, 'ldrValue' será baixo, e a pausa será curta (bipes rápidos).
  // Se há pouca luz, 'ldrValue' será alto, e a pausa será longa (bipes lentos).
  delay(ldrValue);

  // O loop recomeça, lendo o sensor e emitindo outro bip.
}
```

**Entendendo o Código:**
*   `int piezoPin = 8;`: Guarda o número do pino do buzzer.
*   `int ldrPin = 0;`: Guarda o número do pino analógico A0, onde o LDR está conectado.
*   `int ldrValue = 0;`: Uma "caixinha" para guardar o valor que o Arduino lê do LDR.
*   `void setup() { }`: A função `setup` está vazia porque os comandos que usamos (`analogRead` e `tone`) não precisam de configuração prévia com `pinMode` para este circuito específico.
*   `ldrValue = analogRead(ldrPin);`: O Arduino lê a voltagem no pino `ldrPin` (A0) e converte para um número entre 0 e 1023. Esse número é guardado em `ldrValue`.
*   `tone(piezoPin, 1000);`: Faz o buzzer no `piezoPin` (pino 8) começar a tocar um som com frequência de 1000 Hertz (Hz).
*   `delay(25);`: O programa espera por 25 milissegundos, então o som toca por esse tempinho.
*   `noTone(piezoPin);`: Para o som no `piezoPin`.
*   `delay(ldrValue);`: O programa espera por um tempo igual ao valor que foi lido do LDR. Se `ldrValue` for pequeno (muita luz), a espera é curta. Se `ldrValue` for grande (pouca luz), a espera é longa.

**Executando:**
*   **No IDE:** Clique no botão de Verificação (✓) e depois no botão de Upload (→).
*   **No Tinkercad:** Clique em "Start Simulation".
*   Você deverá ouvir bipes curtos.
*   **Teste:**
    1.  Cubra o LDR com sua mão. Os bipes devem ficar mais lentos (o intervalo entre eles aumenta).
    2.  Aponte uma luz (como a lanterna do seu celular) para o LDR. Os bipes devem ficar mais rápidos (o intervalo diminui).
    3.  **No Tinkercad:** Durante a simulação, clique no componente LDR. Um controle deslizante aparecerá. Mova-o para simular mais ou menos luz e observe o que acontece com o som.

**Desafio (Para Explorar Mais):**
1.  **Monitorando os Valores:** Adicione os seguintes comandos ao seu código para ver os valores que o LDR está lendo:
    *   No `setup()`: `Serial.begin(9600);`
    *   No `loop()`, logo após `ldrValue = analogRead(ldrPin);`: `Serial.println(ldrValue);`
    *   Faça o upload e abra o "Monitor Serial" (ícone de lupa no canto superior direito do IDE). Veja como os números mudam quando você cobre ou ilumina o LDR.
2.  **Mudando o Tom:** Em vez de mudar o *intervalo* entre os bipes, tente mudar a *frequência* (o tom) do som com base na leitura do LDR. Você pode precisar usar a função `map()` para converter o `ldrValue` (0-1023) para uma faixa de frequências que soem bem (por exemplo, de 200Hz a 2000Hz).
    *   Exemplo de como usar `map()`: `int frequenciaDoSom = map(ldrValue, 0, 1023, 200, 2000);`
    *   Depois, use `frequenciaDoSom` no comando `tone()`.

**(Espaço para Anotações do Aluno)**
```