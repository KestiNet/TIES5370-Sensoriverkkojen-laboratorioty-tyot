/*
Tämän jälkeen, kun painikkeen painaa alas, niin led lähtee kirkastumaan aina 5% 50 millisekunnin välein niin kauan, kun painike on pohjassa.
Kun painike vapautetaan ja painetaanuudestaan alas, niin led himmenee vastaavasti, eli joka toinen pitkä painallus himmentää ja joka toinen kirkastaa. 
Kun ledi on jossain muussa tilassa kuin sammuksissa niin napin nopea painallus sammuttaa ledinja vastaavasti kun led on sammuksissa niin napin nopea painallus sytyttää ledin siihen 50%:n kirkkauteen.Kommentoi koodisi
*/

const int b1 = 3;
const int led = 10;
const int PITKA_PAINALLUS = 1000;
const int muutos = 5;
int kirkkaus = 0;
int tavoiteKirkkaus = 255;

int viimeinenTila = LOW;
int nykyinenTila;

unsigned long nykyinenPainallus = 0;
unsigned long vapautettuPainallus;
long painonKesto;

bool painaa = false;
bool pitkaPainallusHavaittu = false;
bool kierrattaja = false;

void setup() {
 Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(b1, INPUT);
}

void loop() {
  
  nykyinenTila = digitalRead(b1);
  
  if (viimeinenTila == HIGH && nykyinenTila == LOW){
    nykyinenPainallus = millis();
    painaa = true;
    pitkaPainallusHavaittu = false;

  }else if (viimeinenTila == LOW && nykyinenTila == HIGH){
    painaa = false;

  }

  if (painaa == true && pitkaPainallusHavaittu == false){
    painonKesto = millis() - nykyinenPainallus;

    if (painonKesto > PITKA_PAINALLUS){
      pitkaPainallusHavaittu = true;            
      kirkastaja();
    }       

  }
viimeinenTila = nykyinenTila;
}

/*aliohjelma joka tarkistaa onko nappi pohjassa ja onko pitkaPainallusHavaittu tosi
  for silmukka määrittää kirkkauden muutoksen ja kasvattaa kirkkautta 5% 50millisekunnin välein
*/
void kirkastaja(){

  if ((painonKesto > PITKA_PAINALLUS) && (pitkaPainallusHavaittu == true)){
      kirkkaus = kirkkaus + muutos;
      for (kirkkaus = 0; kirkkaus < tavoiteKirkkaus; kirkkaus++){
      
      analogWrite(led, kirkkaus);
      Serial.println("testi");
      delay(50);
      }

    }  
}
