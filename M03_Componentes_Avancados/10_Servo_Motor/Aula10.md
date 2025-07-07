# Controlando um Servo Motor com Potenciômetro

**Introdução:**
Nesta prática, vamos aprender a controlar a posição exata de um servo motor. Usaremos um potenciômetro (um botão giratório) como um controle manual para dizer ao servo para qual ângulo ele deve se mover. É um dos blocos de construção fundamentais para a robótica!

**Componentes Necessários:**
*   1x Placa Arduino Uno
*   1x Cabo USB
*   1x Protoboard
*   1x Servo Motor (ex: SG90)
*   1x Potenciômetro 10kΩ
*   ~7x Fios Jumper (Macho-Macho)

**Montando o Circuito:**
Siga a tabela de conexões abaixo. Preste atenção especial às cores dos fios do servo motor.

![Circuito Servomotor](https://github.com/T-arcioSantos/projext-robotica-programacao-em/blob/main/Praticas_Tarcio/04/Pratica%2004_%20Manipulando%20um%20servomotor.png)

**Tabela de Conexões:**

**Conexões do Servo Motor**
| Servo | Arduino |
| :--- | :--- |
| Vermelho (VCC) | 5V |
| Marrom ou Preto (GND) | GND |
| Amarelo ou Branco (Sinal) | Pino Digital 9 |

**Conexões do Potenciômetro**
| Pino do Potenciômetro | Arduino |
| :--- | :--- |
| Terminador 1 (VCC) | 5V |
| Limpador (centro) | A0 |
| Terminador 2 (GND) | GND |

**Escrevendo o Código:**
Abra o Arduino IDE ou o Tinkercad (Código > Texto) e digite o código abaixo:

```c++
// Prática 4 - Controlando um Servo Motor com Potenciômetro

// Inclui a biblioteca para controlar o servo
#include <Servo.h>

// Cria um objeto 'servo' para que possamos usar os comandos da biblioteca
Servo myservo;

// Define em qual pino analógico o potenciômetro está conectado
int potPin = A0;

// Variável para armazenar o valor lido do potenciômetro
int potValue = 0;

// A função setup() roda uma vez no início
void setup() {
  // Anexa o nosso objeto 'servo' ao pino 9 do Arduino.
  // A partir de agora, o pino 9 enviará sinais para o servo.
  myservo.attach(9);
}

// A função loop() roda repetidamente
void loop() {
  // 1. Lê o valor do pino analógico A0. O valor varia de 0 a 1023.
  potValue = analogRead(potPin);
  
  // 2. Converte (mapeia) o valor lido (0-1023) para um ângulo (0-180).
  // A função map() faz essa "tradução" para nós.
  int angle = map(potValue, 0, 1023, 0, 180);
  
  // 3. Envia o ângulo calculado para o servo motor.
  myservo.write(angle);
  
  // 4. Pequeno atraso para dar tempo ao servo de se mover e estabilizar.
  delay(15);
}
```

**Entendendo o Código:**
*   `#include <Servo.h>`: Traz as funções prontas para controlar o servo motor.
*   `Servo myservo;`: Cria uma "variável especial" (objeto) do tipo Servo, que chamamos de `myservo`.
*   `myservo.attach(9);`: "Conecta" nosso objeto `myservo` ao pino físico 9 do Arduino.
*   `analogRead(potPin);`: Lê a voltagem no pino A0 e a converte em um número entre 0 (para 0V) e 1023 (para 5V).
*   `map(valor, de_min, de_max, para_min, para_max);`: Uma função muito útil! Ela pega um `valor` que está em uma faixa (de 0 a 1023) e o converte para o número correspondente em outra faixa (de 0 a 180).
*   `myservo.write(angle);`: Envia o comando final para o servo, dizendo a ele para se mover para o ângulo (`angle`) especificado.

**Executando:**
*   Faça o upload (IDE) ou clique em "Start Simulation" (Tinkercad).
*   Gire o botão do potenciômetro. Você deverá ver o braço do servo motor se movendo de acordo, imitando a posição do seu botão!

**Desafio:**
*   O servo motor consegue se mover 180 graus, mas e se você quisesse que ele se movesse apenas em um arco menor, por exemplo, entre 30 e 150 graus? Tente modificar os dois últimos números na função `map()` para limitar o movimento.
    *   *Dica: `map(potValue, 0, 1023, 30, 150);`*

**(Espaço para Anotações)**