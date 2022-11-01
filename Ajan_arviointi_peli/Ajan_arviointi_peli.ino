const int buttonPin = 2;
volatile bool buttonPushed = false;
int laskuri = 0;
int aloitusAika;
int lopetusAika;
int kesto;
int sekuntti;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING);
}


void loop() {
  if (buttonPushed && laskuri <=4)
  {
    delay(10);  // debounce time
    aloitusAika = millis();
    buttonPushed = false;
    laskuri++;

   Serial.println(laskuri);
   tulostus();
  }  
}
void laskin(){
  
}

void buttonISR()
{
  buttonPushed = true;
}
void tulostus(){
  sekuntti = aloitusAika / 1000;
  kesto = 20-sekuntti;
  if(laskuri == 5){
  Serial.print("Tavoiteaika oli 20 s. Sait tuloksesti ");
  Serial.print(sekuntti);
  Serial.print(" sekunttia, eli virheesi oli  ");
  Serial.print(kesto);
  Serial.print(" sekunttia.");

}
}
