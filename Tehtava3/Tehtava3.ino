// määäritellään kaikki pinnit ja painikkeet

int led = 10;
int kirkkaus = 0;
int muutos = 5;
volatile bool lippu1 = false;
int b1 = 3;
int b2 = 2;
const unsigned long intervalli = 50;
unsigned long aiempiAika = 0;
int napinTila = 0;

//määritellään keskeytykset ja pinmode ledille
void setup(){
    attachInterrupt(digitalPinToInterrupt(b1), kirkastus , FALLING);
    pinMode(led, OUTPUT);
    
  
}

void kirkastus(){
  lippu1 = true;

}



void loop() {

//Serial.println(napinTila);
if (digitalRead(b1) == LOW){
  if(millis() - aiempiAika < 1000){
    kirkkaus += 128;
    Serial.println("nopea paino toimii");
    if(kirkkaus > 255){
      kirkkaus = 255;
    }
  }
}
/*
  //Jos keskeytys on tosi ja nappi b1 pohjassa kirkastaa ledia
  if ((lippu1 == true) && (digitalRead(b1) == LOW )){
    kirkkaus += muutos;
    if (kirkkaus >250){
      kirkkaus = 255;
    }

    analogWrite(led,kirkkaus);
    Serial.println(kirkkaus);
    delay(50);
  } else {
    lippu1 = false;
  }
*/
  
 
}
