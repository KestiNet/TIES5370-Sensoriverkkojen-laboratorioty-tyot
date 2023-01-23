// määäritellään kaikki pinnit ja painikkeet

int led = 10;
int kirkkaus = 0;
int muutos = 5;
volatile bool k = false;
volatile bool h = false;
int b1 = 3;
const unsigned long intervalli = 50;
unsigned long aiempiAika = 0;

//määritellään keskeytykset ja pinmode ledille
void setup(){
    attachInterrupt(digitalPinToInterrupt(b1), kirkastaa, RISING);
    pinMode(led, OUTPUT);
    
  
}
// Tehdään looppiin määritykset joiden mukaan aletaan joko kirkastamaan tai himmentämään lediä
// otetaan alusta millis() ja määritetään se nykyinenAika 
//Jos nykyinenAika on suurempi tai yhtäsuuri kuin intervalli ja b1 nappia on painettu, aletaan kirkastamaan 
//Jos nykyinenAika on suurempi tai yhtäsuuri kuin intervalli ja b2 nappia on painettu, aletaan himmentämään 

void loop(){
  unsigned long nykyinenAika = millis();
  if((nykyinenAika - aiempiAika >= intervalli) &&  (k == true)){
    analogWrite(led, kirkkaus);
    delay(100);
    kirkkaus = kirkkaus + muutos;
    
  aiempiAika = nykyinenAika;
  }
  if ((nykyinenAika - aiempiAika >= intervalli) && (h == true)){
    analogWrite(led, kirkkaus);
    delay(100);
    kirkkaus = kirkkaus - muutos;
    aiempiAika = nykyinenAika;   
  }
  
}

//keskeytys funktio jota kutsutaan kun nappia b1 painetaan
void kirkastaa(){
  k = true;

}
//keskeytys funktio jota kutsutaan kun nappia b2 painetaan

void himmentaa(){
  h = true;

}