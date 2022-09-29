const int buttonPin = 2;     
unsigned long time2;
int pAika;
int lAika;
int kesto;
int buttonState = 0;         
unsigned long interval;
int painallus = 0;
int aika [4];

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  while (buttonState == LOW && painallus <= 4) {   
    
    while(buttonState == LOW) buttonState = digitalRead(buttonPin);
    buttonState = HIGH;
    painallus++;
    Serial.println(painallus);
  } 

}
