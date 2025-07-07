# Fazendo um LED Piscar
[Slides da Aula](https://www.figma.com/slides/oPLEXkBsY8yasrFFyeiz16/Pratica-01---ProjExt?node-id=1-660&t=5TadbJDZJMOzxRAO-1)

**Introdução:**
Bem-vindo ao mundo do Arduino! Nesta primeira prática, vamos montar nosso primeiro circuito eletrônico e escrever um programa simples para fazer um LED (uma pequena luz) piscar.

**Componentes Necessários:**
*   1x Placa Arduino Uno
*   1x Cabo USB
*   1x Protoboard
*   1x LED (qualquer cor)
*   1x Resistor de 220Ω (Vermelho, Vermelho, Marrom) ou 330Ω (Laranja, Laranja, Marrom)
*   2x Fios Jumper

**Montando o Circuito:**
Siga o diagrama abaixo. Lembre-se da polaridade do LED (perna longa +, perna curta -).

![Circuito LED Piscante](https://github.com/Progrobext/PROGROB-UESC/blob/main/Imagens/circuito01.png)

**Passos da Montagem:**
1.  Conecte `GND` do Arduino ao barramento (-) da protoboard.
2.  Conecte `Pino 10` do Arduino a uma linha central da protoboard.
3.  Encaixe o LED: Perna longa (+) na linha do Pino 10, perna curta (-) em outra linha.
4.  Encaixe o Resistor: Uma perna na linha da perna curta (-) do LED, outra perna no barramento (-).

**Escrevendo o Código:**
Abra o Arduino IDE ou o Tinkercad (Código > Texto) e digite:

```c++
// Projeto 1 - LED piscante

int ledPin = 10; // Variável para guardar o número do pino do LED

// A função setup() roda uma vez no início
void setup() {
  // Configura o pino do LED como uma SAÍDA
  pinMode(ledPin, OUTPUT);
}

// A função loop() roda repetidamente
void loop() {
  digitalWrite(ledPin, HIGH); // Liga o LED
  delay(1000);             // Espera 1000 milissegundos (1 segundo)
  digitalWrite(ledPin, LOW);  // Desliga o LED
  delay(1000);             // Espera 1000 milissegundos (1 segundo)
}
```
Entendendo o Código:
-------------------------------------
* int ledPin = 10;: Guarda o número do pino.
* pinMode(ledPin, OUTPUT);: Define o pino como saída. 
* digitalWrite(ledPin, HIGH);: Liga o LED.
* digitalWrite(ledPin, LOW);: Desliga o LED.
* delay(1000);: Pausa por 1000ms.
* setup(): Configuração inicial.
* loop(): Repete para sempre.

Executando:
-------------------------------------
* Faça o upload (IDE) ou clique em "Start Simulation" (Tinkercad). Seu LED deve piscar!

Desafio:
-------------------------------------
* Altere os números no delay() para mudar a velocidade da piscada.

-------------------------------------
(Espaço para Anotações)
