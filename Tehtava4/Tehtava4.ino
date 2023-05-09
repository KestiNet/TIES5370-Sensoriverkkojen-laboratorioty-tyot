int painoNappi = 2;
int powerPin = 13;
int analogPin = A0;

byte lippu;

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
  if(lippu == 1){
    Serial.println("iffi toimii");
    aloitusAika = micros();
    digitalWrite(powerPin, HIGH);

    for(int i; i < 50; i++){
      mittausarvot[i]=analogRead(A0);
      delayMicroseconds(30);
      loppuAika = micros();
      Serial.println(loppuAika - aloitusAika);

    }
    

  }
for (int i; i < 50; i++){
  Serial.print("Measurement ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(mittausarvot[i]);
  }
delay(5000);
}
