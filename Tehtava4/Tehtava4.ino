int painoNappi = 2;
int powerPin = 13;
int analogPin = A0;

byte lippu;

unsigned long mittausarvot[50];
float aloitusAika;
float loppuAika;
float kokonaisAika;


void setup() {
  Serial.begin(9600);
  pinMode(painoNappi, INPUT);
  pinMode(powerPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(painoNappi), keskeytysISR, FALLING);
}


void keskeytysISR(){
  lippu = 1;
}

void loop() {
  // put your main code here, to run repeatedly:

}
