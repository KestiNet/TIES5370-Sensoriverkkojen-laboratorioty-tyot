int led = 10;
int b1 = 3;
int b2 = 2;
boolean waspressed = false;

int inertia = 10;

void setup (){ 
  pinMode(b1,INPUT);
  pinMode(led,OUTPUT);
  analogWrite(led,0);
}

void loop(){
  if(digitalRead(b1) == HIGH){
    waspressed = true;
  }else{
     if (waspressed == true){
       fadeLed(digitalRead(led), inertia);
       waspressed = false;
     }
  }
}

void fadeLed(boolean input, int inertia){
  for(int state=0;state<256;state++){
    if (input==LOW){
      analogWrite(led, state);
    }else{
      analogWrite(led, 255-state);
    }
    delay(inertia);
  }
}