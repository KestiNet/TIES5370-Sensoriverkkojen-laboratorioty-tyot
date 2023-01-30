/*
* Muutetaan edellisessä tehtävässä toteutettua himmennintä siten, että nyt käytössä on vain yksi painike(B1). 
Kun systeemi käynnistetään, niin led on sammuksissa ja napin nopea painallus sytyttää ledin 50% kirkkauteen maksimistaan. 
Tämän jälkeen, kun painikkeen painaa alas, niin led lähtee kirkastumaan aina 5% 50 millisekunnin välein niin kauan, kun painike on pohjassa.
Kun painike vapautetaan ja painetaanuudestaan alas, niin led himmenee vastaavasti, eli joka toinen pitkä painallus himmentää ja joka toinen kirkastaa. 
Kun ledi on jossain muussa tilassa kuin sammuksissa niin napin nopea painallus sammuttaa ledinja vastaavasti kun led on sammuksissa niin napin nopea painallus sytyttää ledin siihen 50%:n kirkkauteen.Kommentoi koodisi
*/

// constants won't change. They're used here to set pin numbers:
const int b1 = 3; // the number of the pushbutton pin
const int katko = 500; // 500 milliseconds
int led = 10;

// Variables will change:
int aiempiPainallus = LOW;  // the previous state from the input pin
int nykyinenPainallus;     // the current reading from the input pin
unsigned long painettuAika  = 0;
unsigned long vapautettuAika = 0;


void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(b1), painallus, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  
}
/*
keskeytysfunktio napin painallukselle
Mittaa aikaa napin painalluksesta ja jos on nopea painallus, ledi syttyy 50% kirkkauteen

*/
void painallus(){
  nykyinenPainallus = digitalRead(b1);

  if(aiempiPainallus == HIGH && nykyinenPainallus == LOW)        // button is pressed
    painettuAika = millis();
  else if(aiempiPainallus == LOW && nykyinenPainallus == HIGH) { // button is released
    vapautettuAika = millis();

    long kesto = vapautettuAika - painettuAika;

    if( kesto < katko )
      analogWrite(led, 127);
      Serial.println("painettu");
  }

  aiempiPainallus = nykyinenPainallus;



}

  currentState = digitalRead(BUTTON_PIN);

  if(lastState == HIGH && currentState == LOW) {        // button is pressed
    pressedTime = millis();
    isPressing = true;
    isLongDetected = false;
  } else if(lastState == LOW && currentState == HIGH) { // button is released
    isPressing = false;
  }

  if(isPressing == true && isLongDetected == false) {
    long pressDuration = millis() - pressedTime;

    if( pressDuration > LONG_PRESS_TIME ) {
      Serial.println("A long press is detected");
      isLongDetected = true;
    }
  }

  // save the the last state
  lastState = currentState;