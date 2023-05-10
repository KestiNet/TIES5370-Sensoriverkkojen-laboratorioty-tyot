int painoNappi = 2;
int powerPin = 13;
int analogPin = A0;

byte lippu;
unsigned long mittausAika[50];
unsigned long mittausarvot[50];
float aloitusAika;
float loppuAika;
float kokonaisAika;


void setup() {
  Serial.begin(9600);
  pinMode(painoNappi, INPUT);
  pinMode(powerPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(painoNappi), keskeytysISR, FALLING);
}


void keskeytysISR(){
  lippu = 1;
  Serial.println("lippu toimii");
}

void loop() {
   if (lippu == 1) {
    Serial.println("iffi toimii");
    aloitusAika = millis();
    digitalWrite(powerPin, HIGH);

    for (int i = 0; i < 50; i++) {
      mittausarvot[i] = analogRead(A0);
      loppuAika = millis();
      mittausAika[i] = loppuAika - aloitusAika;
      //Serial.println(mittausAika[i]);
      delay(50);
    }
    
 

    for (int i = 0; i < 50; i++) {
      Serial.print(i);
      Serial.print(": ");
      Serial.print(mittausarvot[i]);
      Serial.print(", ");
      Serial.print(mittausAika[i]);
      Serial.println(" ms");
    }
    unsigned long summa = 0;
    for (int i = 0; i < 50; i++) {
      summa += mittausAika[i];
    }
    Serial.print("Yksittäisten mittausten summa: ");
    Serial.println(summa);
   /* for (int i = 0; i < 50; i++) {
      Serial.print(i);
      Serial.print(": ");
      Serial.println(mittausarvot[i]);
    }*/
    digitalWrite(powerPin, LOW);
    lippu = 0; 
  }
}
