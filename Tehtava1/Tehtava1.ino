const int buttonPin = 2;
volatile int painonapinLaskuri = 1;
volatile unsigned long  aikaleima[5];
float intervalli[4];
float aikaSumma;
float summa;
float keskiarvo;
float varianssi; 
float keskiHajonta;        
float virhe;
float tavoiteaika = 20.0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), keskeytysISR, FALLING);
}

void keskeytysISR(){
  
  Serial.println(painonapinLaskuri);
  
  aikaleima[painonapinLaskuri-1] = millis();
  painonapinLaskuri++;
}
//tarkistetaan 
void loop() {


  if(painonapinLaskuri == 6){
    tulosta();
  }
}

//tulostetaan ja lasketaan kaikki arvot
void tulosta(){
  varianssi = 0;// siirsin tähän eli ennen for-silmukkaa
  keskiarvo = (aikaleima[4] - aikaleima[0])/1000.0/4.0; //samoin keskiarvo lasketaan helpoiten näin ennen for-silmukkaa

  for(int i = 0; i < 4; i ++){ 
    intervalli[i] = ((aikaleima[i+1])-(aikaleima[i]))/1000.0;
    //Serial.println(intervalli[i]); //tulostus testausta ja tarkistusta varten
    varianssi += (intervalli[i] - keskiarvo) * (intervalli[i] - keskiarvo);  //tämä osa varianssin laskentaa for-silmukan sisällä    
  }

  varianssi /= 4.0;  // jaetaan n-1  // ja tämä osa laskentaa for-silmukan ulkopuolella
  keskiHajonta = sqrt(varianssi);  // lasketaan keskihajonta ottamalla neliöjuuri varianssista

//Tulostetaan kaikki laskelmat
  Serial.print("Tavoiteaika oli ");
  Serial.print(tavoiteaika);
  Serial.print(" Sait tulokseksi: ");
  Serial.println((aikaleima[4]/1000.0 - aikaleima[0]/1000.0));
  Serial.print("Virheesi oli ");
  Serial.println(tavoiteaika - ((aikaleima[4]/1000.0 - aikaleima[0]/1000.0)));
  Serial.print("Painallusten keskiarvo oli: " );
  Serial.print(keskiarvo);
  Serial.println(" sekunttia");
  Serial.print("Painallusten Keskihajonta oli: ");  
  Serial.print(keskiHajonta);
  Serial.println(" sekunttia");

  painonapinLaskuri = 1;
  }
 

  

