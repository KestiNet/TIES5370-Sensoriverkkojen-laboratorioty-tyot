int napinPainallus = 0;
long aloitus;
long lopetus;
byte ajastin;
long kesto;

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
aloitus = millis();
ajastin = 1;
if(napinPainallus <= 4){  
  napinPainallus++;
if (napinPainallus == 5){
  lopetus=millis();
  ajastin = 0;
  kesto = lopetus - aloitus;
  Serial.println("lopeta");
  Serial.println(kesto);
}
}
}
