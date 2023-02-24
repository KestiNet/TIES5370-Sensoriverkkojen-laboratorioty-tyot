/*
Eli tee mittaussovellus, joka toimii seuraavasti:
- pääohjelmassa tarkistat, onko nappia B1 painettu
- jos on niin kytke virrat anturiin
- lue alkuaika muistiin
- lue 50 mittausarvoa silmukassa array –tyyppiseen muuttujaan
- lue loppuaika muistiin
- tulosta array-tyyppisen muuttujan mittaustiedot for-silmukassa sarjamonitoriin
- laske mittausjakson kokonaisaika ja siitä sitten yksittäisen mittauksen aika, tulosta myös nämä
Kopioi sarjamonitorin ikkunasta mittausarvosi ja vie ne Exceliin. 
Muodosta alla olevan kuvan näköinen xy-kaavio, eli ADC-arvon riippuvuus ajasta. Kuvasta (tai taulukon arvoista) voit määritellä sensorille aikavakion (=aika-arvo, jossa mittaustulos on saavuttanut 63,2% maksimiarvosta) 
ja asettumisajan (=aika, jolloin mittausarvo on asettunut +/- 2%:n sisään lopullisesta arvostaan). Kommentoi koodisi.
*/

const int b1 = 3;
const int valoVastus = A0;
const int led = 10;
int mittausArvot[50];

int aika = 0;
int loppuAika = 0;
int kierrosAika = 0;
int kierros = 0;

int valoArvo;
byte arrayIndeksi = 0;

volatile byte napinPainallus;

void setup() {
  Serial.begin(9600);
  pinMode(b1, CHANGE);
  pinMode(valoVastus, INPUT);
  pinMode(led, OUTPUT);
}

/*
//tarkistetaan onko nappia painettu
//jos nappi on painettu, otetaan talteen aika ja aletaan tallentamaan mittausarvot taulukkoon ja tulostetaan tarvittavat
*/
void loop() {
  napinPainallus = digitalRead(b1); 

  if (napinPainallus == LOW){ 
    aika = millis();
   
    for(int i = 0; i < 50; i++){
        mittausArvot[i] = analogRead(valoVastus);
        kierrosAika = millis();
        Serial.print("kierrosaika: ");
        Serial.println(kierrosAika);
        
        Serial.println(mittausArvot[i]);
        delay(100);
    }
     Serial.print("aika: ");
     Serial.println(kierrosAika - aika);
    }  
  delay(500);
    
  

}



