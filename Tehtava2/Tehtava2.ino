// määäritellään kaikki pinnit ja painikkeet

int led = 10;
int kirkkaus = 0;
int muutos = 5;
volatile bool lippu1 = false;
volatile bool lippu2 = false;
int b1 = 3;
int b2 = 2;
const unsigned long intervalli = 50;
unsigned long aiempiAika = 0;

//määritellään keskeytykset ja pinmode ledille
void setup(){
    attachInterrupt(digitalPinToInterrupt(b1), kirkastus , FALLING);
    attachInterrupt(digitalPinToInterrupt(b2), himmennys, FALLING);
    pinMode(led, OUTPUT);
    
  
}

void kirkastus(){
  lippu1 = true;

}

void himmennys(){
  lippu2 = true;
  

}

void loop() {
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

  
    //Jos keskeytys on tosi ja nappi b2 pohjassa kirkastaa ledia

  if((lippu2 == true) && (digitalRead(b2)== LOW)){
    kirkkaus -= muutos;
    if (kirkkaus < 0){
      kirkkaus = 0;
    }
    analogWrite(led,kirkkaus);
    Serial.println(kirkkaus);
    delay(50);
  }else{
    lippu2 = false;
  }
}
