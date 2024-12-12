#include <LiquidCrystal.h>            // Chama a biblioteca do LCD
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  // Portas usadas pelo shield do LCD
int sensor = A1;                      // Define o pino de leitura do sensor
int buzzer = 2;                       // Define o pino do buzzer
int nivel_umidade;                    // Define a variável que armazenará o valor da umidade lida

void setup() {
  lcd.begin(16, 2);         // Inicia o display lcd 16x2
  pinMode(sensor, INPUT);   // Define o pino do sensor como entrada
  pinMode(buzzer, OUTPUT);  // Define o pino do sensor como saída
}

void loop() {
  nivel_umidade = analogRead(sensor);                   // Realiza a leitura analógica do sensor e armazena na variável nivel_umidade
  nivel_umidade = map(nivel_umidade, 0, 1020, 100, 0);  // Transforma os valores analógicos em uma escala de 0 a 100

  if (nivel_umidade < 30) {                                // Se o nivel de umidade for menor que 30....
    lcd.clear();                                           // Limpa o display
    lcd.print("ESTOU COM SEDE");                           // Escreve a mensagem "ESTOU COM SEDE" na primeira linha
    lcd.setCursor(0, 1);                                   // Seleciona o cursor na segunda linha
    lcd.print("umidade: ");                                // Escreve a mensagem "umidade: "
    lcd.print(nivel_umidade);                              // Escreve o valor da umidade
    lcd.print("%");                                        // Escreve o símbolo % ao lado do valor da umidade
    tone(buzzer, 29);                                      // Emite um som contínuo no buzzer numa frequência de 29 Hertz
  }
   else if (nivel_umidade >= 30 && nivel_umidade < 65) {  // Se o nivel de umidade estiver entre 30 e 65...
    lcd.clear();                                           // Limpa o display
    lcd.print("HIDRATADA");                                // Escreve a mensagem "HIDRATADA" na primeira linha
    lcd.setCursor(0, 1);                                   // Seleciona o cursor na segunda linha
    lcd.print("umidade: ");                                // Escreve a mensagem "umidade: "
    lcd.print(nivel_umidade);                              // Escreve o valor da umidade
    lcd.print("%");                                        // Escreve o símbolo % ao lado do valor da umidade
    tone(buzzer, 29);                                      // Emite um som no buzzer numa frequência de 29 Hertz
    delay(200);                                            // Espera 0,2 segundos
    noTone(buzzer);                                        // Desliga o som do buzzer
    delay(2000);                                           // Espera 2 segundos
  }
   else {
    lcd.clear();               // Se o nivel de umidade não for menor que 30 nem estiver entre 30 e 65 (maior que 65)...
    lcd.print("MUITA AGUA");   // Escreve a mensagem "MUITA AGUA" na primeira linha
    lcd.setCursor(0, 1);       // Seleciona o cursor na segunda linha
    lcd.print("umidade: ");    // Escreve a mensagem "umidade: "
    lcd.print(nivel_umidade);  // Escreve o valor da umidade
    lcd.print("%");            // Escreve o símbolo % ao lado do valor da umidade
    tone(buzzer, 29);          // Emite um som no buzzer numa frequência de 29 Hertz
    delay(100);                // Espera 0,1 segundos
    noTone(buzzer);            // Desliga o som do buzzer
    delay(100);                // Espera 0,1 segundos
  }
  delay(100);  // Espera 0,1 segundos
}
