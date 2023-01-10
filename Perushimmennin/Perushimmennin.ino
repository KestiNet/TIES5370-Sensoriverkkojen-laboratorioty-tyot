int led = 10;
int b1 = 3;
int b2 = 2;
int himmennys = 5;
int kirkastuu = 5;
int kirkkaus = 0;


void setup (){ 
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(led,OUTPUT);
  
}

void loop(){
  analogWrite(led, kirkkaus);
  if(digitalRead(b1) == HIGH){
    kirkkaus = kirkkaus + kirkastuu;
    delay(50);
  }
}
  
//https://arduino.stackexchange.com/questions/22128/led-fading-effect-using-a-push-button
//https://wiki-content.arduino.cc/en/Tutorial/BuiltInExamples/Fade

//void fadeLed(boolean input, int inertia){
  //for(int state=0;state<256;state++){
    //if (input==LOW){
      //analogWrite(led, state);
    //}else{
      //analogWrite(led, 255-state);
    //}
    //delay(inertia);
  //}
//}