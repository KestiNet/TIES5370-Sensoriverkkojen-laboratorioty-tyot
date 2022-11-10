constexpr uint8_t buttonPin = 2;
constexpr uint8_t desired_presses = 1;
volatile uint32_t aloitusAika;
volatile uint32_t lopetusAika;
volatile uint32_t oikeaAika;
int talletus[4];

volatile uint8_t counter = 0;
int laskuri = 0;

void setup() {
    Serial.begin(9600);
    pinMode(buttonPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING);
}

void loop() {
    if (aloitusAika && lopetusAika) {
        // minus stop and start for time
        oikeaAika = lopetusAika - aloitusAika;
        Serial.println(laskuri);
        Serial.print("Time between presses = ");
        Serial.println(oikeaAika);
        aloitusAika = 0;
        lopetusAika = 0;
        laskuri++;
    }
}

void buttonISR() {
    static uint32_t last_interrupt_time = 0;
    const uint32_t interrupt_time = millis();

    if (interrupt_time - last_interrupt_time > 100) {
        if (!aloitusAika) {
            aloitusAika = millis();
            counter++;
        }
        else if (counter == desired_presses) {
            lopetusAika = millis();
            counter = 0;
        }
        else {
            counter++;
        }

    }

    last_interrupt_time = interrupt_time;
}