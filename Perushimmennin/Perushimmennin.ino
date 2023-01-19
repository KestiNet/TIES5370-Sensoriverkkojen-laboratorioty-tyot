int led = 10;
int kirkkaus = 0;
int muutos = 5;
volatile bool k = false;
volatile bool h = false;
int b1 = 3;
int b2 = 2;


void setup(){
    attachInterrupt(digitalPinToInterrupt(b1), kirkastaa, RISING);
    attachInterrupt(digitalPinToInterrupt(b2), himmentaa, RISING);
    pinMode(led, OUTPUT);
    //Serial.begin(9600);
    
  
}

void loop(){
  while(k == true){
    analogWrite(led, kirkkaus);
    delay(100);
    kirkkaus = kirkkaus + muutos;
    if(kirkkaus >= 255){
      kirkkaus = 255;
    }
  }
  if (h == true){
    analogWrite(led, kirkkaus);
    delay(100);
    kirkkaus = kirkkaus - muutos;
      
  }
}
void kirkastaa(){
  k = true;

}

void himmentaa(){
  h = true;

}