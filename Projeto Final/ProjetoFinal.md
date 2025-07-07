# **Prática 5 – Construindo um Radar SONAR com Arduino**

**Introdução:**
Nesta prática, vamos construir um incrível radar que usa ondas sonoras para detectar objetos, assim como um submarino. O sistema usará um servo motor para girar um sensor ultrassônico, escaneando o ambiente. Os dados coletados serão enviados para o computador, que desenhará um mapa visual do que foi detectado em uma tela de radar!

**Componentes Necessários:**
*   1x Placa Arduino Uno
*   1x Servo Motor SG90
*   1x Sensor Ultrassônico HC-SR04
*   Protoboard e Fios Jumper

**Link para Download:**
[Download Processing](https://processing.org/download)

**Montando o Circuito:**
Conecte os componentes conforme o diagrama. O ideal é prender o sensor ultrassônico ao servo motor para que ele possa girar.

**Tabela de Conexões:**
| Componente | Pino do Componente | Conectar no Arduino |
| :--- | :--- | :--- |
| **Servo Motor** | Vermelho (VCC) | 5V |
| | Marrom/Preto (GND) | GND |
| | Laranja (Sinal) | Pino Digital 12 |
| **Sensor Ultrassônico** | VCC | 5V |
| | GND | GND |
| | Trig | Pino Digital 10 |
| | Echo | Pino Digital 11 |

**Programando o Sistema:**
Este projeto tem duas partes: o código que vai no Arduino e o código que roda no computador para desenhar o radar (usando Processing).

**Passo 1: Código do Arduino (O Cérebro)**
Este código é responsável por controlar os componentes e enviar os dados.

```c++
// Código para Arduino IDE
// Baseado no projeto de Dejan Nedelkovski - HowToMechatronics.com

// Inclui a biblioteca do servo
#include <Servo.h> 

// Define os pinos do Sensor Ultrassônico
const int trigPin = 10;
const int echoPin = 11;

// Variáveis para calcular a distância
long duration;
int distance;

Servo myServo; // Cria um objeto para controlar o servo

void setup() {
  pinMode(trigPin, OUTPUT); // Define o pino de gatilho como saída
  pinMode(echoPin, INPUT); // Define o pino de eco como entrada
  Serial.begin(9600); // Inicia a comunicação com o computador
  myServo.attach(12); // Anexa o servo ao pino 12
}

void loop() {
  // Gira o servo de 15 a 165 graus
  for(int i = 15; i <= 165; i++){  
    myServo.write(i);
    delay(30);
    distance = calculateDistance(); // Mede a distância na posição atual
    
    Serial.print(i); // Envia o ângulo atual
    Serial.print(","); // Envia um separador
    Serial.print(distance); // Envia a distância medida
    Serial.print("."); // Envia um marcador de fim de mensagem
  }
  // Gira de volta de 165 para 15 graus
  for(int i = 165; i > 15; i--){  
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

// Função que mede a distância
int calculateDistance(){
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Envia um pulso de 10 microssegundos no pino Trig
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); // Mede o tempo que o som levou para voltar
  
  distance = duration * 0.034 / 2; // Converte o tempo em centímetros
  return distance;
}
```

**Passo 2: Código do Processing (A Interface Gráfica)**
Este código cria a janela do radar no seu computador. Ele escuta os dados que o Arduino envia e os usa para desenhar.

```java
// Código para Processing IDE

import processing.serial.*;
import java.awt.event.KeyEvent;
import java.io.IOException;

Serial myPort; 

String angle="";
String distance="";
String data="";
String noObject;
float pixsDistance;
int iAngle, iDistance;
int index1=0;
PFont orcFont;

void setup() {
  
  size (1920, 1080); // <<< MUDE AQUI PARA A RESOLUÇÃO DA SUA TELA
  
  smooth();
  // MUITO IMPORTANTE: Mude "COM4" para a porta serial que seu Arduino está usando.
  myPort = new Serial(this,"COM4", 9600); 
  myPort.bufferUntil('.'); 
}

void draw() { 
  fill(98,245,31);
  // Desenhando o fundo com um leve "rastro"
  noStroke();
  fill(0,4); 
  rect(0, 0, width, height-height*0.065); 
  
  fill(98,245,31); // Cor verde para o texto
  
  drawRadar(); 
  drawLine();
  drawObject();
  drawText();
}

void serialEvent (Serial myPort) { 
  data = myPort.readStringUntil('.');
  data = data.substring(0,data.length()-1);
  
  index1 = data.indexOf(","); 
  angle= data.substring(0, index1); 
  distance= data.substring(index1+1, data.length()); 
  
  iAngle = int(angle);
  iDistance = int(distance);
}

void drawRadar() {
  pushMatrix();
  translate(width/2,height-height*0.074); 
  noFill();
  strokeWeight(2);
  stroke(98,245,31);
  // Desenha os arcos do radar
  arc(0,0,(width-width*0.0625),(width-width*0.0625),PI,TWO_PI);
  arc(0,0,(width-width*0.27),(width-width*0.27),PI,TWO_PI);
  arc(0,0,(width-width*0.479),(width-width*0.479),PI,TWO_PI);
  arc(0,0,(width-width*0.687),(width-width*0.687),PI,TWO_PI);
  popMatrix();
}

void drawObject() {
  pushMatrix();
  translate(width/2,height-height*0.074);
  strokeWeight(9);
  stroke(255,10,10); // Cor vermelha para o objeto
  pixsDistance = iDistance*((height-height*0.1666)*0.025); 
  
  // Limita a detecção para 40 cm
  if(iDistance<40){
    // Desenha uma linha do centro até o limite do radar na direção do objeto
    line(pixsDistance*cos(radians(iAngle)),-pixsDistance*sin(radians(iAngle)),(width-width*0.505)*cos(radians(iAngle)),-(width-width*0.505)*sin(radians(iAngle)));
  }
  popMatrix();
}

void drawLine() {
  pushMatrix();
  strokeWeight(9);
  stroke(30,250,60);
  translate(width/2,height-height*0.074);
  // Desenha a linha que "varre" a tela
  line(0,0,(height-height*0.12)*cos(radians(iAngle)),-(height-height*0.12)*sin(radians(iAngle)));
  popMatrix();
}

void drawText() {
  // Escreve as informações na tela
  pushMatrix();
  if(iDistance>40) {
    noObject = "Out of Range";
  } else {
    noObject = "In Range";
  }
  fill(0,0,0);
  noStroke();
  rect(0, height-height*0.0648, width, height);
  fill(98,245,31);
  textSize(40);
  
  text("Object: " + noObject, width-width*0.875, height-height*0.0277);
  text("Angle: " + iAngle +" °", width-width*0.48, height-height*0.0277);
  text("Distance: " + iDistance + " cm", width-width*0.26, height-height*0.0277);
  popMatrix();
}
```

**Como Executar:**
1.  **Carregue o Código 1** na sua placa Arduino usando o Arduino IDE.
2.  Feche o Monitor Serial do Arduino.
3.  **Abra o Código 2** no Processing. **Edite a linha** `myPort = new Serial(this,"COM4", 9600);` para usar a porta serial correta do seu Arduino.
4.  Clique em **Executar (Play)** no Processing.
5.  A tela do radar aparecerá e começará a funcionar