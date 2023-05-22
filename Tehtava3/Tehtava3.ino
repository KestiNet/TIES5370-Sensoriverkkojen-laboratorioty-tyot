int b1 = 3;
int led = 10;
int tila = 0;
int ledinTila = 0;
int maksimi = 255;
int puolikas = 127;
int viive = 20;
int muutos = 8;
signed int kirkasta = 0;
int painike = 2;
int keskeytysViive = 100;

void setup() {
  attachInterrupt(digitalPinToInterrupt(b1), kirkastus, FALLING);
  pinMode(led, OUTPUT);
  pinMode(b1, INPUT);
}

void kirkastus() {
  tila = 1;
  int tuloAika = millis();

  if (kirkasta == 0) {
    kirkasta = 1;
  } else {
    kirkasta = 0;
  }
  delay(nykyinenAika - tuloAika > 100); 
}

void loop() {
  if (tila) {
    if (digitalRead(b1) == LOW && ledinTila == 0) {
      ledinTila = puolikas;
      analogWrite(led, ledinTila);
    }

    if (digitalRead(b1) == LOW && ledinTila > 0) {
      ledinTila = 0;
      analogWrite(led, ledinTila);
    }

    while (digitalRead(b1) == HIGH && ledinTila < 255 && kirkasta == 1) {
      ledinTila += muutos;
      analogWrite(led, ledinTila);
      delay(viive);
    }

    while (digitalRead(b1) == HIGH && ledinTila > 7 && kirkasta == 0) {
      ledinTila -= muutos;
      analogWrite(led, ledinTila);
      delay(viive);
    }
  }
  tila = 0;
}
