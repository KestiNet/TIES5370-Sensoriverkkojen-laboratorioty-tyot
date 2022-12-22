constexpr uint8_t buttonPin = 2;
constexpr uint8_t painallukset = 1;
volatile uint32_t aloitusAika;
volatile uint32_t lopetusAika;
volatile uint32_t oikeaAika;
int talletus[4];
long summa = 0;

volatile uint8_t laskin = 0;
byte laskuri = 1;

void setup() {
    Serial.begin(9600);
    pinMode(buttonPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, RISING);
}

void loop() {
    if (laskuri < 6 &&(aloitusAika && lopetusAika)) {
        // minus stop and start for time
        //oikeaAika = lopetusAika - aloitusAika;
        Serial.println(laskuri);
        //Serial.print("Time between presses = ");
        //Serial.println(oikeaAika/1000);
        talletus[laskuri] = (lopetusAika - aloitusAika);
        aloitusAika = 0;
        lopetusAika = 0;
        laskuri++;
    
      if (laskuri == 6){
      
      tulosta();
    }
}
}
void tulosta(){
  unsigned int i;
      for(i = 0; i < 5; i++) { 
        summa += talletus[i]; 
        }
     
  Serial.print("Tavoiteaika oli 20 s. Sait tulokseksi: ");
  Serial.print(summa/1000);
  Serial.print(" , eli virheesi oli ");
  Serial.print(20 - summa/1000);
  Serial.println(" Painallusten keskiarvo oli ");
  Serial.print(keskiArvo);
  Serial.print(" sekunttia");

}

float mean = keskiArvo();
float std = keskiHajonta();

//Keskiarvon laskeminen
float keskiArvo() {
  long total = 0;
  for (int i = 0; i < 5; i++) {
    total = total + talletus[i];
  }
  float keskiA = total/(float)5;
  return keskiA;
}

/*
 * Get the standard deviation from an array of ints
 https://forum.arduino.cc/t/get-the-standard-deviation-of-array/477539/8
 */
float keskiHajonta() {
  float keski = keskiArvo();
  long total = 0;
  for (int i = 0; i < 5; i++) {
    total = total + (talletus[i] - keski) * (talletus[i] - keski);
  }

  float variance = total/(float)5;
  float keskiH = sqrt(variance);
  return keskiH;
}



void buttonISR() {
    static uint32_t last_interrupt_time = 0;
    const uint32_t interrupt_time = millis();

    if (interrupt_time - last_interrupt_time > 100) {
        if (!aloitusAika) {
            aloitusAika = millis();
            laskin++;
        }
        else if (laskin == painallukset) {
            lopetusAika = millis();
            laskin = 0;
        }
        else {
            laskin++;
        }

    }

    last_interrupt_time = interrupt_time;
}