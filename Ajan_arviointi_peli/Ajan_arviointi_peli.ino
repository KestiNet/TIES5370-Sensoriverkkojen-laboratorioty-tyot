const int buttonPin = 2;     
unsigned long time1;
unsigned long time2;
int buttonState = 0;         
unsigned long interval;
int painallus = 0;
//bool x = 0; //control

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW && painallus <= 4) {   //if button IS pushed
   // x = 1;
    time1 = millis();
    while(buttonState == LOW) buttonState = digitalRead(buttonPin);
    buttonState = HIGH;
    painallus++;
    Serial.println(painallus);
  } 
 // if (buttonState == LOW && x == 1) {   //if button IS pushed
   // x = 0;
    //time2 = millis();
    //while(buttonState == LOW) buttonState = digitalRead(buttonPin);
    //buttonState = HIGH;
    //interval = time2 - time1;
    //Serial.print("Interval:");
    //Serial.println(interval);
  
}
