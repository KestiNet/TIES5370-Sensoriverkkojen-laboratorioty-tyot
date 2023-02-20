const int b1 = 3; // napin pinni
const int led = 10; // ledin pinni
int kirkkaus = 0; // ledin kirkkaus
int himmennys = 5; // paljonko himmennetään
int himmennysKesto = 50; // himmentimen ajastin aika
unsigned long viimeinenDebounceAika = 0; // viimeinen kerta kun nappia painettiin
unsigned long debounceKesto = 5; //debounce ajastin
bool ledPaalla = false; 


void setup() {
  pinMode(b1, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  //tarkistaa onko nappia painettu
  int buttonState = digitalRead(b1);
  if (buttonState == LOW) {
    
    if (millis() - viimeinenDebounceAika > debounceKesto) {
      // jos ledi on pois päältä, laitetaan se 50% kirkkauteen
      if (!ledPaalla) {
        kirkkaus = 128;
        ledPaalla = true;
      }
      //jos ledi on päällä, sammuta se
      else {
        kirkkaus = 0;
        ledPaalla = false;
      }
      //päivitetään ledin kirkkaus
      analogWrite(led, kirkkaus);
      viimeinenDebounceAika = millis();
    }
  }
  else {
    //jos ledi on päällä, himmennä
    if (ledPaalla) {
      kirkkaus = kirkkaus + himmennys;
      kirkkaus = constrain(kirkkaus, 0, 255);
      analogWrite(led, kirkkaus);
      delay(himmennysKesto);
      
     
    }
    // 
    else if (kirkkaus > 0) {
      kirkkaus = kirkkaus - himmennys;
      kirkkaus = constrain(kirkkaus, 0, 255);
      analogWrite(led, kirkkaus);
      delay(himmennysKesto);
      // jos kirkkaus on 0 niin sammuta ledi
      if (kirkkaus == 0) {
        ledPaalla = false;
      }
    }
  }
}
