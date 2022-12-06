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
  
    if (aloitusAika && lopetusAika) {
        // minus stop and start for time
        //oikeaAika = lopetusAika - aloitusAika;
        Serial.println(laskuri);
        //Serial.print("Time between presses = ");
        //Serial.println(oikeaAika/1000);
        talletus[oikeaAika] = lopetusAika - aloitusAika;
        aloitusAika = 0;
        lopetusAika = 0;
        laskuri++;
    }
    if (laskuri == 5){
      unsigned int index;
      for(index = 0; index < sizeof(talletus); index++) { 
        summa += talletus[index]; 
        }
      tulosta();
    }
}

void tulosta(){
  
  Serial.print("Tavoiteaika oli 20 s. Sait tulokseksi: ");
  Serial.print(summa);
  Serial.print(" , eli virheesi oli ");
  Serial.print("tulostaa 20sek - yhteenlasketun tuloksen");
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