const int buttonPin = 2;
volatile int painonapinLaskuri = 0;
volatile unsigned long  aikaleima[5];
float intervalli[4];
float summa;
float keskiarvo;
float virhe;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), keskeytysISR, RISING);

}

void keskeytysISR(){
  aikaleima[painonapinLaskuri] = millis();
  painonapinLaskuri++;
}

void loop() {
if(painonapinLaskuri == 5){
  tulosta();
}
}

void tulosta(){

  for(int i = 0; i < 5; i ++){
    intervalli[i] = ((aikaleima[i+1])-(aikaleima[i]))/1000.0;
    summa += intervalli[i];
   
  }
  for(int i = 0; i < 5; i++){
    keskiarvo = (aikaleima[4] - aikaleima[0])/1000.0/4.0;
  
  }
    Serial.println("intervalli: ");
    Serial.println(summa);
    Serial.println("keskiarvo: ");
    Serial.println(keskiarvo);
  painonapinLaskuri = 0;
}
