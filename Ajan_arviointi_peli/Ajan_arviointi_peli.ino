const int buttonPin = 2;     
unsigned long time2;
int pAika;
int Aaika;
int kesto;
int buttonState = 0;         
unsigned long interval;
int painallus = 0;
int aika [4];
byte ajastin;


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  //buttonState = digitalRead(buttonPin);
  if(ajastin == 0 && digitalRead(buttonPin) == LOW){
  Aaika = millis();
  ajastin = 1;
  }
  
  if (ajastin == 1 && digitalRead(buttonPin) == HIGH && painallus <= 4) {   
    pAika = millis();
    ajastin = 0;
    kesto = Aaika - pAika;
    if(buttonState == LOW) buttonState = digitalRead(buttonPin);
    buttonState = HIGH;
    painallus++;
    Serial.println(painallus);
    Serial.println(kesto);
  } 

}
