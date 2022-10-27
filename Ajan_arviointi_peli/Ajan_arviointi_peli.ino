const int buttonPin = 2;
volatile bool buttonPushed = false;
int laskuri = 0;
int aloitusAika;
int lopetusAika;
int kesto;

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
    aloitusAika = millis();
    buttonPushed = false;
    laskuri++;

   Serial.println(laskuri);
  }
  if (laskuri == 4){
    tulostus();
  }
}

void buttonISR()
{
  buttonPushed = true;
}
void tulostus(){
  Serial.println("Tavoiteaika oli 20 s.");
}
