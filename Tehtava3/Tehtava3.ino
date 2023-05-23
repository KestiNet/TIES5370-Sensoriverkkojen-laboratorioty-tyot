#include <Arduino.h>

const int b1 = 3;
int led = 10;
int tila = 0;
int ledinTila = 0;
int maksimi = 255;
int puolikas = 127;
int viive = 20;
int muutos = 8;
volatile signed int kirkasta = 0;
int painike = 2;
int keskeytysViive = 100;

void setup() {
  Serial.begin(9600);
  pinMode(b1, INPUT);
  attachInterrupt(digitalPinToInterrupt(b1), kirkastus, FALLING);
  pinMode(led, OUTPUT);
}

void kirkastus() {
  Serial.println("Keskeytys");
  tila = 1;
  int tuloAika = millis();

  if (kirkasta == 0) {
    kirkasta = 1;
    Serial.println("Kirkasta on 1");
  } else {
    kirkasta = 0;
    Serial.println("Kirkasta on 0");
  }
}

void loop() {
  if (tila == 1) {
    delay(100);
    int napinTila = digitalRead(b1);
    if (napinTila == LOW && kirkasta == 0) {
      Serial.println("eka iffi");
      ledinTila = puolikas;
      analogWrite(led, 255);
    }

    if (napinTila == LOW && kirkasta == 1) {
      Serial.println("toka iffi");
      ledinTila = 0;
      analogWrite(led, 127);
    }

    while (digitalRead(b1) == LOW && ledinTila < 255 && kirkasta == 1) {
      Serial.println("eka while");
      ledinTila += muutos;
      analogWrite(led, ledinTila);
      delay(viive);
    }
    

    while (digitalRead(b1) == LOW && ledinTila > 7 && kirkasta == 0) {
      Serial.println("toka while");
      ledinTila -= muutos;
      analogWrite(led, ledinTila);
      delay(viive);
    }
  }
  tila = 0;
}
