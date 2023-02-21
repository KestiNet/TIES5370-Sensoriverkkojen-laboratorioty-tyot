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
//https://reference.arduino.cc/reference/en/language/variables/data-types/array/
int mittausArvot[50];

int aika = 0;

int valoArvo;

volatile byte napinPainallus;

void setup() {
  Serial.begin(9600);
  pinMode(b1, CHANGE);
  pinMode(valoVastus, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  napinPainallus = digitalRead(b1);

  if (napinPainallus == LOW){
    aika = millis();
    valoArvo = analogRead(valoVastus);
    Serial.println(valoArvo);

    if (valoArvo > 25){
    digitalWrite(led, LOW);
  }else{
    digitalWrite(led, HIGH);
    Serial.print("Intensity= ");
    Serial.println(valoArvo);
  }
  delay(500);
    
  }
}
  




