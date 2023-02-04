/*
Tämän jälkeen, kun painikkeen painaa alas, niin led lähtee kirkastumaan aina 5% 50 millisekunnin välein niin kauan, kun painike on pohjassa.
Kun painike vapautetaan ja painetaanuudestaan alas, niin led himmenee vastaavasti, eli joka toinen pitkä painallus himmentää ja joka toinen kirkastaa. 
Kun ledi on jossain muussa tilassa kuin sammuksissa niin napin nopea painallus sammuttaa ledinja vastaavasti kun led on sammuksissa niin napin nopea painallus sytyttää ledin siihen 50%:n kirkkauteen.Kommentoi koodisi
*/

const int b1 = 3;
const int led = 10;

int puoliKirkkaus = 127;
int lyhyt = 500;
int pitkaPainallus = 2000;
int muutos = 5;

//Keskeytyksen parametrit
int aiempiPainallus = LOW;
int nykyinenPainallus;

bool keskeytysTapahtui = false;

int pk = LOW;
int nk = LOW;

unsigned long painettuKirkkaus = 0;

unsigned long painettuAika = 0;
unsigned long vapautettuAika = 0;

void setup() {
 Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(b1), painallus, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  keskeytysTapahtui = false;
  
  
}

/*
keskeytysfunktio napin painallukselle
Mittaa aikaa napin painalluksesta ja jos on nopea painallus, ledi syttyy 50% kirkkauteen
*/

void painallus(){
  keskeytysTapahtui = true;
  nykyinenPainallus = digitalRead(b1);

  if(aiempiPainallus == HIGH && nykyinenPainallus == LOW)        // button is pressed
    painettuAika = millis();
  else if(aiempiPainallus == LOW && nykyinenPainallus == HIGH) { // button is released
    vapautettuAika = millis();

    long kesto = vapautettuAika - painettuAika;

    if( kesto < lyhyt )
      analogWrite(led, puoliKirkkaus);
      Serial.println("painettu");
  }

  aiempiPainallus = nykyinenPainallus;

}