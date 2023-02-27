//Asetetaan arvot pinneille ja antureille
//alustetaan taulukko
const int b1 = 3;
const int valoVastus = A0;
const int led = 10;
int mittausArvot[50];
//alustetaan parametrit
int aika = 0;
int loppuAika = 0;
int kierrosAika = 0;
int kierros = 0;

int valoArvo;
byte arrayIndeksi = 0;

volatile byte napinPainallus;

void setup() {
  Serial.begin(9600);
  pinMode(b1, CHANGE);
  pinMode(valoVastus, INPUT);
  pinMode(led, OUTPUT);
}

/*
//tarkistetaan onko nappia painettu
//jos nappi on painettu, otetaan talteen aika ja aletaan tallentamaan mittausarvot taulukkoon ja tulostetaan tarvittavat
*/
void loop() {
  napinPainallus = digitalRead(b1); 

  if (napinPainallus == LOW){ 
    aika = millis();
   
    for(int i = 0; i < 50; i++){
        mittausArvot[i] = analogRead(valoVastus);
        kierrosAika = millis();
        Serial.print("kierrosaika: ");
        Serial.println(kierrosAika);
        
        Serial.println(mittausArvot[i]);
        delay(100);
    }
     Serial.print("aika: ");
     Serial.println(kierrosAika - aika);
    }  
  delay(500);
    
  

}



