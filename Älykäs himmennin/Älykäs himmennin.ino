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

void setup(){
    attachInterrupt(digitalPinToInterrupt(b1), painallus, RISING);
    pinMode(led, OUTPUT);
    
  
}
unsigned long vapautettuAika = 0;
//https://arduinogetstarted.com/tutorials/arduino-button-long-press-short-press
//more instructions here

void loop(){

  
}

//keskeytys funktio jota kutsutaan kun nappia b1 painetaan
void kirkastaa(){
  k = true;

}
//keskeytys funktio jota kutsutaan kun nappia b2 painetaan

void himmentaa(){
  h = true;

}