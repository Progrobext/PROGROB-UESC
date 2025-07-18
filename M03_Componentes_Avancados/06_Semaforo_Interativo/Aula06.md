# Semáforo Interativo com Botão para Pedestres

**Introdução:**
Nesta prática, vamos ampliar o projeto do semáforo para criar um semáforo interativo com controle para pedestres. Você irá conectar vários LEDs para simular as luzes do semáforo para carros e pedestres, além de usar um botão para que o pedestre possa solicitar a travessia. O Arduino vai reagir ao botão, alterando as luzes para garantir segurança na travessia.

**Componentes Necessários:**

* 2 LEDs vermelhos
* 1 LED amarelo
* 2 LEDs verdes
* Resistores (150Ω e outros)
* 1 Botão
* Protoboard e fios jumper (sempre necessários)

**Montando o Circuito:**
Siga o diagrama que conecta LEDs aos pinos 9, 10, 11 para o semáforo dos carros, pinos 1 e 2 para o semáforo dos pedestres, e o botão ao pino 3.

**(Inserir aqui o diagrama do circuito)**

**Código Arduino:**

```c++
 // Projeto 2-2 Semáforo Interativo
int carRed = 11;     
int carYellow = 10;
int carGreen = 9;

int pedRed = 2;     
int pedGreen = 1;

int button = 3; // pino do botão     
int crossTime = 5000; // tempo para que os pedestres atravessem
unsigned long changeTime;

void setup() {
 pinMode(carRed, OUTPUT);
 pinMode(carYellow, OUTPUT);
 pinMode(carGreen, OUTPUT);
 pinMode(pedRed, OUTPUT);
 pinMode(pedGreen, OUTPUT);
 pinMode(button, INPUT); // botão no pino 2
 // acende a luz verde
 digitalWrite(carGreen, HIGH);
 digitalWrite(pedRed, HIGH);
}

void loop() {
  int state = digitalRead(button);

  /* verifica se o botão foi pressionado e se transcorreram
  5 segundos desde a última vez que isso ocorreu */
  if (state == HIGH && (millis() - changeTime) > 5000) {
    // Chama a função para alterar as luzes
    changeLights();
  }
}

void changeLights() {
  digitalWrite(carGreen, LOW);     // apaga o verde
  digitalWrite(carYellow, HIGH);   // acende o amarelo
  delay(2000);                     // espera 2 segundos

  digitalWrite(carYellow, LOW);    // apaga o amarelo
  digitalWrite(carRed, HIGH);      // acende o vermelho
  delay(1000);                     // espera 1 segundo, por segurança

  digitalWrite(pedRed, LOW);       // apaga o vermelho dos pedestres
  digitalWrite(pedGreen, HIGH);    // acende o verde dos pedestres
  delay(crossTime);                // espera por um intervalo de tempo predefinido

  // pisca o verde dos pedestres
  for (int x = 0; x < 10; x++) {
    digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
  }

  // acende o vermelho dos pedestres
  digitalWrite(pedRed, HIGH);
  delay(500);

  digitalWrite(carYellow, HIGH);   // acende o amarelo
  digitalWrite(carRed, LOW);       // apaga o vermelho
  delay(1000);

  digitalWrite(carGreen, HIGH);    // acende o verde
  digitalWrite(carYellow, LOW);    // apaga o amarelo

  // registra o tempo desde a última alteração no semáforo
  changeTime = millis();
  // depois retorna para o loop principal do programa
}
```

**Entendendo o Código:**

* `pinMode(..., OUTPUT)`: Define os pinos dos LEDs como saída.
* `pinMode(button, INPUT)`: Configura o botão como entrada digital.
* `digitalRead(button)`: Lê o estado do botão (pressionado ou não).
* `millis()`: Retorna o tempo desde que o Arduino foi ligado para controlar intervalos.
* `changeLights()`: Função que controla a sequência das luzes do semáforo e do farol de pedestres.
* `delay()`: Pausa o programa para controlar os tempos das luzes.
* Laços `for` para piscar o LED verde dos pedestres.

**Executando:**
Faça o upload do código no Arduino ou inicie a simulação no Tinkercad. Pressione o botão e observe como o semáforo muda, permitindo a travessia segura dos pedestres.

**Desafio:**
* Experimente alterar os tempos do semáforo ou implementar uma função para piscar o LED amarelo antes de mudar as luzes.
* Modifique o Semáforo para ficar que nem o padrão brasileiro.

---