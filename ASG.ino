#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int ccc = 1;
int sensorPin = A0;
int sensorValue = 0;
int freq = 0;
const int buzzer = 7;

void playTone(int freqq){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Freq");
  lcd.setCursor(0, 1);
  tone(buzzer, freqq);
  lcd.print(freqq);
}

void setup() {
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Testing...");
  delay(1000);
  for (int freqq = 256; freqq <= 512; freqq++) {
    playTone(freqq);
    delay(10);
  }
  for (int freqq = 512; freqq >= 256; freqq--) {
    playTone(freqq);
    delay(10);
  }
  noTone(buzzer);
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("Ready in 3");
  delay(1000);
  lcd.clear();
  lcd.print("Ready in 2");
  delay(1000);
  lcd.clear();
  lcd.print("Ready in 1");
  delay(1000);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  freq = ceil(sensorValue/5)*5*2;
  if (freq>2000) {
    freq = 2000;
  }
  if (freq<20) {
    freq = 20;
  }
  playTone(freq);
  delay(20);
}
