int napinPainallus = 0;

void setup(){
Serial.begin(9600);
pinMode(2, INPUT);
digitalWrite(2, HIGH);
attachInterrupt(2, painallus, FALLING);
  
}


void loop(){
  
}

void painallus(){
Serial.println(napinPainallus);
if(napinPainallus <= 4){  
  napinPainallus++;
if (napinPainallus == 5){
  Serial.println("lopeta");
}
}
}
