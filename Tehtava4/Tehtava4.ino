int painoNappi = 2;
int powerPin = 13;
int analogPin = A0;

byte lippu;
unsigned long mittausAika;
unsigned long mittausarvot[50];
float aloitusAika;
float loppuAika;
float kokonaisAika;

//Alustetaan laitteet ja keskeytys 
void setup() {
  Serial.begin(9600);
  pinMode(painoNappi, INPUT);
  pinMode(powerPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(painoNappi), keskeytysISR, FALLING);
}

//Keskeytys aliohjelma joka havaitsee napin painalluksen
void keskeytysISR(){
  lippu = 1;
  Serial.println("lippu toimii");
}

void loop() {
   if (lippu == 1) {   //Jos keskeytys on tapahtunut, lippu on 1 
    digitalWrite(powerPin, HIGH); // jos lippu on 1, laitetaan virrat laitteeseen
    aloitusAika = micros(); //otetaan aloitus aika ylös
    

    for (int i = 0; i < 50; i++) {
      mittausarvot[i] = analogRead(A0); //tallennetaan mittausarvot taulukkoon
    
      loppuAika = micros(); //otetaan jokaisen mittauksen loppu aika talteen
      mittausAika = loppuAika - aloitusAika; //lasketaan jokaisen mittauksen kesto
     // Serial.print("mittausajat: ");
      Serial.println(mittausAika/50); //tulostetaan jokaisen mittausken aika
    }
    Serial.println("mittausarvot: ");
      //Serial.println(mittausAika[i]);
      delay(50);
      for (int i = 0; i < 50; i++) {  //tulostetaan mittausarvot taulukosta
        Serial.println(mittausarvot[i]);
      
    }
     
    Serial.print("Kokonaisaika: ");
    Serial.println(mittausAika);
    //Serial.print("Yksittäisten mittausten summa: ");
    Serial.println(mittausAika/50);
 
    digitalWrite(powerPin, LOW);
    lippu = 0; 
    delay(50);
  }
}

  

