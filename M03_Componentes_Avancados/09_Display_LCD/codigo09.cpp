// Inclui a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

// Define os pinos do Arduino conectados ao LCD
// LiquidCrystal lcd(RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Inicializa o LCD com 16 colunas e 2 linhas
  lcd.begin(16, 2);

  // Limpa qualquer texto anterior
  lcd.clear();

  // Escreve na primeira linha, primeira coluna (0,0)
  lcd.setCursor(0, 0); // Coluna 0, Linha 0
  lcd.print("Ola, bot!");
}

void loop() {
  // Codigo dentro do loop para atualizar o texto dinamicamente
  // Exemplo: um contador
  lcd.setCursor(0, 1); // Posiciona na segunda linha
  lcd.print("Cont: ");
  lcd.print(millis() / 1000); // Mostra segundos desde o início
  delay(500); // Pequena pausa
}