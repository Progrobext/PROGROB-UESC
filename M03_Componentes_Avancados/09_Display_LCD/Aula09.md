# Exibindo Mensagens no Display LCD

**Introdução:**
Nesta prática, vamos aprender a usar um Display de Cristal Líquido (LCD) 16x2 com o Arduino. Com ele, podemos mostrar textos, números e informações dos nossos projetos!

**Componentes Necessários:**
*   1x Placa Arduino Uno
*   1x Cabo USB
*   1x Protoboard
*   1x Display LCD 16x2
*   1x Potenciômetro 10kΩ
*   1x Resistor de 220Ω (Vermelho, Vermelho, Marrom) ou 330Ω (Laranja, Laranja, Marrom)
*   ~16x Fios Jumper (Macho-Macho)

**Montando o Circuito:**
A montagem do LCD exige atenção! Siga o diagrama e as conexões abaixo com cuidado.

**(Inserir aqui o diagramado circuito LCD)**

**Conexões Principais:**
*(Confira os nomes dos pinos no seu LCD, podem variar um pouco)*
1.  **LCD VSS (Pino 1)** -> **GND** do Arduino
2.  **LCD VDD (Pino 2)** -> **5V** do Arduino
3.  **LCD VO / V0 (Pino 3)** -> **Pino Central** do Potenciômetro
4.  **Potenciômetro (Terminal 1)** -> **GND** do Arduino
5.  **Potenciômetro (Terminal 2)** -> **5V** do Arduino
6.  **LCD RS (Pino 4)** -> **Pino Digital 12** do Arduino
7.  **LCD R/W (Pino 5)** -> **GND** do Arduino
8.  **LCD E (Pino 6)** -> **Pino Digital 11** do Arduino
9.  **LCD D4 (Pino 11)** -> **Pino Digital 5** do Arduino
10. **LCD D5 (Pino 12)** -> **Pino Digital 4** do Arduino
11. **LCD D6 (Pino 13)** -> **Pino Digital 3** do Arduino
12. **LCD D7 (Pino 14)** -> **Pino Digital 2** do Arduino
13. **LCD A / LED+ (Pino 15)** -> Uma perna do **Resistor**
14. **Outra perna do Resistor** -> **5V** do Arduino
15. **LCD K / LED- (Pino 16)** -> **GND** do Arduino

**Escrevendo o Código:**
Abra o Arduino IDE ou o Tinkercad (Código > Texto) e digite:

```c++
// Prática 2 - Exibindo Texto no LCD

// Inclui a biblioteca para controlar o LCD
#include <LiquidCrystal.h>

// Define quais pinos do Arduino estão conectados ao LCD
// LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// A função setup() roda uma vez no início
void setup() {
  // Inicializa o LCD com 16 colunas e 2 linhas
  lcd.begin(16, 2);

  // Limpa qualquer texto anterior (boa prática)
  lcd.clear();

  // Posiciona o cursor na Coluna 0, Linha 0 (canto superior esquerdo)
  lcd.setCursor(0, 0);
  // Escreve na primeira linha
  lcd.print("Ola, Arduino!");

  // Posiciona o cursor na Coluna 0, Linha 1 (segunda linha)
  lcd.setCursor(0, 1);
  // Escreve na segunda linha
  lcd.print("LCD 16x2 OK!");
}

// A função loop() roda repetidamente (pode ficar vazia por enquanto)
void loop() {
  // O texto já foi escrito no setup() e permanecerá na tela.
  // Poderíamos adicionar código aqui para atualizar o texto depois.
}
```

**Entendendo o Código:**
*   `#include <LiquidCrystal.h>`: Traz as funções para usar o LCD.
*   `LiquidCrystal lcd(12, 11, 5, 4, 3, 2);`: Cria o "objeto" LCD, dizendo quais pinos do Arduino estão conectados (RS, E, D4-D7).
*   `lcd.begin(16, 2);`: Informa que nosso LCD tem 16 colunas e 2 linhas.
*   `lcd.clear();`: Limpa tudo que estiver escrito no LCD.
*   `lcd.setCursor(coluna, linha);`: Move o cursor para onde o próximo texto será escrito (começa em 0,0).
*   `lcd.print("Seu texto");`: Escreve o texto no LCD na posição atual do cursor.

**Executando:**
*   Faça o upload (IDE) ou clique em "Start Simulation" (Tinkercad).
*   **IMPORTANTE:** Se você não vir texto ou vir apenas blocos pretos, **gire o botão do potenciômetro lentamente** para ajustar o contraste até o texto ficar nítido! Verifique também se a luz de fundo (backlight) acendeu.

**Desafio:**
*   Mude as mensagens escritas no LCD.
*   Faça o Arduino escrever uma mensagem na primeira linha e um número (contador) que aumenta na segunda linha dentro do `loop()`. (Dica: use `lcd.print(variavel);` e `delay();`).

**(Espaço para Anotações)**