/*
Hyvin usein mikrokontrolleripohjaiset mittaussovellukset ovat paristokäyttöisiä ja tämän takia paristosta saatavaa virtaa koetetaan säästää. 
Monet mittaussovellukset toimivat niin, että niiden mittaussekvenssi on hyvin harva, esim. kerran tunnissa. Tällöin sensorista kannattaa katkaista sähköt pois, jotta se ei turhaan kuluttaisi paristoa ja kytkeä virrat päälle vain mitattaessa. 
Mutta kun kytketään sensoriin virrat päälle, niin kuinka nopeasti voidaan mittaus aloittaa? Sitä tutkitaan tässä harjoituksessa.
Työssä käytetään valovastusta (analoginen anturi), jonka vastusarvo siis muuttuu valoisuuden mukaan. Valovastuksen kanssa on sarjassa vakio 10kΩ vastus ja sen rinnalla on 100nF kondensaattori. 
Kun kontrollerin linja nr 13 asetetaan ykköstilaan (HIGH) niin silloin anturillemme kytkeytyy 5V:n jännite, ja virta kulkee vakiovastuksen ja valovastuksen läpi. Vakiovastuksen ja valovastuksen liitoskohdsata mitataan jännitettä kontrollerin A0 pinnin kautta. 
Tätä jännitettä verrataan Arduinon referenssijännitteeseen ja lasketaan sille digitaalinen arvo, joka on välillä 0-1023 (arvo 1023 vastaa 5V ja esim. arvo 512 vastaa 2.5V).
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

const int B1 = 3;
const int valoVastus = A0;
const int led = 10;



void setup() {
  pinMode(valoVastus, INPUT);
  pinMode(led, OUTPUT)
}

void loop() {
  value = analogRead(valoVastus);

  if (value > 25){
    digitalWrite(led, LOW);
  }else{
    digitalWrite(led, HIGH);
  }
  delay(500);
}
