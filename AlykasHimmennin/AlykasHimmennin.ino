#include <Toggle.h>

const int b1 = 3;
const int led = 10;
byte kirkkaus;

int sammuttaja;

bool himmentaa;

Toggle nappi = (b1);

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(b1, INPUT);
  }


void loop(){

  nappi.poll(); //alustaa napin käyttöön
  if (nappi.onPress()) himmentaa = !himmentaa; // Jos nappia on painettu tarkistaa himmennetäänkö vai ei
  if (nappi.isPressed()) {
    (himmentaa) ? kirkkaus++ : kirkkaus--; //Riippuen painokerrasta aletaan kirkastamaan tai himmentämään
    if (kirkkaus == 255) kirkkaus = 0; // määritellään mitä tehdään tiettyinä kirkkauksina
    else if (kirkkaus >= 253) kirkkaus = 253;
    delay(50); //tehdään 50 millisekunnin kesto
  }
  analogWrite(led, kirkkaus);


}



/*
nykyinenTila = digitalRead(b1);

if (nykyinenTila != viimeinenTila) {
    debounce = millis();
    viimeinenTila = nykyinenTila;
  }

  if ((millis() - debounce) > DEBOUNCE_HIDASTUS) {
    if (viimeinTasainenTila == HIGH && nykyinenTila == LOW){
      nykyinenPainallus = millis();
      painaa = true;
      pitkaPainallusHavaittu = false;
      Serial.println("painettu");
    }else if (viimeinTasainenTila == LOW && nykyinenTila == HIGH){
      painaa = false;
      Serial.println("irroitettu");
    }

    if (painaa == true && pitkaPainallusHavaittu == false){
      painonKesto = millis() - nykyinenPainallus;
      if (painonKesto > PITKA_PAINALLUS){
        pitkaPainallusHavaittu = true;

        kirkastajaTaiHimmentaja();
        vaihtaja++;
        Serial.println(vaihtaja);
      }
    }
    viimeinTasainenTila = nykyinenTila;
  }
}
void kirkastajaTaiHimmentaja(){

  if ((painonKesto > PITKA_PAINALLUS) && (pitkaPainallusHavaittu == true) && (vaihtaja % 2 == 0)){
    
      kirkkaus = kirkkaus + muutos;
      for (kirkkaus = 0; kirkkaus < tavoiteKirkkaus; kirkkaus++){
      
      analogWrite(led, kirkkaus);
      Serial.println(vaihtaja);
      delay(50);
      }

    }  
  
  if((painonKesto > PITKA_PAINALLUS) && (pitkaPainallusHavaittu == true) && (vaihtaja % 2 == 1)){
    kirkkaus = kirkkaus - muutos;
      for (kirkkaus = 255; kirkkaus > tavoiteKirkkaus; kirkkaus--){
      
      analogWrite(led, kirkkaus);
      Serial.println(vaihtaja);
      delay(50);
  }
  }
}


*/