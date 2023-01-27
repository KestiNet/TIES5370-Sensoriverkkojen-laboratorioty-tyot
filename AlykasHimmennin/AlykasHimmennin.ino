// määäritellään kaikki pinnit ja painikkeet

int led = 10;
int kirkkaus = 0;
int muutos = 5;
volatile bool k = false;
volatile bool h = false;
int b1 = 3;
const unsigned long intervalli = 50;
unsigned long aiempiAika = 0;
const int nopeaPainallus = 500;

unsigned long painettuAika = 0;
unsigned long vapautettuAika = 0;
int nykyinen;
int viimeinenTila = LOW;

void setup(){
    attachInterrupt(digitalPinToInterrupt(b1), painallus, INPUT_PULLUP);
    pinMode(led, OUTPUT);
    
  
}

//https://arduinogetstarted.com/tutorials/arduino-button-long-press-short-press
//more instructions here

void loop(){

   //nykyinen = digitalRead(BUTTON_PIN);

  if((k == true)&&(viimeinenTila == HIGH && nykyinen == LOW))        // button is pressed
    painettuAika = millis();
  else if(viimeinenTila == LOW && nykyinen == HIGH) { // button is released
    vapautettuAika = millis();

    long painoAika = vapautettuAika - painettuAika;

    if( painoAika < nopeaPainallus ){
      analogWrite(led, 127);
    }
}
}
//keskeytys funktio jota kutsutaan kun nappia b1 painetaan
void painallus(){
  k = true;

}
//keskeytys funktio jota kutsutaan kun nappia b2 painetaan

void himmentaa(){
  h = true;

}