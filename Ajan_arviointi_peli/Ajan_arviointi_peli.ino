const int buttonPin = 2;
volatile bool buttonPushed = false;
int laskuri = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING);
}


void loop() 
{
  if (buttonPushed && laskuri <=4)
  {
    delay(10);  // debounce time
    buttonPushed = false;
    laskuri++;
    // TBD: Button push is detected.  Do the rest of your stuff here

   Serial.println(laskuri);
  }
}

void buttonISR()
{
  buttonPushed = true;
}
