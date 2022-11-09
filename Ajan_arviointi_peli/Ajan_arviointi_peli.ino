int buttonPin =2;
volatile bool buttonPushed = false;
int laskuri = 0;
int aloitusAika;
int lopetusAika;
int oikeaAika;
int talletus[4];
byte timerRunning;

void setup() {
attachInterrupt(digitalPinToInterrupt(2), buttonISR, CHANGE);
}

void loop() {
if (buttonPushed && laskuri <= 4 && timerRunning == 0){
  delay(10);
  aloitusAika = millis();
  timerRunning = 1;
}
if (timerRunning == 1 && buttonPushed){
  timerRunning = 0;
  lopetusAika = millis();
  oikeaAika = lopetusAika - aloitusAika;
  talletus[laskuri] = oikeaAika;
  Serial.println(oikeaAika);
  laskuri++;
  Serial.println(laskuri);
  
  if (laskuri == 5){
    tulostus(); 
  
    }    
  }

buttonPushed = false;
}

void buttonISR(){
  buttonPushed = true;
}

void tulostus(){
  Serial.print("aika oli:   ");
for(int i = 0; i < 5; i++){
  Serial.println(talletus[i]);
}
}