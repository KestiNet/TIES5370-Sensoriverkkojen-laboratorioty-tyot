const int buttonPin = 2;
volatile bool buttonPushed = false;
int laskuri = 0;
int aloitusAika;
int lopetusAika;
int jakso;
int kesto;
int kestoAika;
int sekuntti;
int talletus[4];
byte indeksi =0;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING);

  for(int i = 0; i < 4; i++){
    talletus[i] = 0;
  }
}


void loop() {
  if (buttonPushed && laskuri <=4)
  {
    delay(10);  // debounce time
    aloitusAika = millis();
    kestoAika = aloitusAika - lopetusAika;
    talletus[laskuri] = kestoAika;
    if(kesto >= jakso){
      lopetusAika = lopetusAika + kesto;
     // talletus[] = talletus +1;
     
    }
    buttonPushed = false;
    laskuri++;

   Serial.println(laskuri);
   tulostus();
  }  
}
void laskin(){
  
}

void buttonISR()
{
  buttonPushed = true;
}
void tulostus(){
  sekuntti = aloitusAika / 1000;
  kesto = 20-sekuntti;
  if(laskuri == 5){
  Serial.print("Tavoiteaika oli 20 s. Sait tuloksesti ");
  Serial.print(sekuntti);
  Serial.print(" sekunttia, eli virheesi oli  ");
  Serial.print(kesto);
  Serial.print(" sekunttia.");

for(int i = 0; i < 5; i++)
{
  Serial.println("new print:   ");
  Serial.println(talletus[i]);
}
}
}
