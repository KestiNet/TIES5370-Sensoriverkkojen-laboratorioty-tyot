int buttonPin = 2;
int buttonValue;


void setup(){
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  buttonValue = digitalRead(buttonPin);
  Serial.println(buttonValue);
  delay(500);
}
