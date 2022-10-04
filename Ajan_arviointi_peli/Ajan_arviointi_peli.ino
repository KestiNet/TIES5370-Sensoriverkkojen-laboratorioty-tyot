int buttonp = 0;

void setup(){
  Serial.begin(9600);
  pinMode(2, INPUT);
  digitalWrite(2, LOW);
  attachInterrupt(2, button1, FALLING);
}

void loop(){
  
}

void button1(){
  
  while(buttonp <=4){
    buttonp++;
    Serial.println(buttonp);
  }
}
