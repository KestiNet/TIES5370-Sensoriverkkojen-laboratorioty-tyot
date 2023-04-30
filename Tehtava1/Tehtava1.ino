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
  attachInterrupt(digitalPinToInterrupt(buttonPin), keskeytysISR, RISING);
}

void keskeytysISR(){
  
  Serial.println(painonapinLaskuri);
  
  aikaleima[painonapinLaskuri] = millis();
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
  summa = 0;
  for(int i = 0; i < 4; i ++){
    intervalli[i] = ((aikaleima[i+1])-(aikaleima[i]))/1000.0;
    summa += intervalli[i];
    varianssi = 0;
    varianssi += (intervalli[i] - keskiarvo) * (intervalli[i] - keskiarvo);
    keskiarvo = summa / 5.0;
    varianssi /= 4.0;  // jaetaan n-1
    keskiHajonta = sqrt(varianssi);  // lasketaan keskihajonta ottamalla neliöjuuri varianssista
  }
  for(int i = 0; i < 4; i++){  //lasketaan talletetut ajat
    aikaSumma+= aikaleima[i];
    
      }
  
  Serial.print("Tavoiteaika oli ");
  Serial.print(tavoiteaika);
  Serial.print(" Sait tulokseksi: ");
  Serial.println(tavoiteaika - (aikaSumma/1000.0));
  //Tulostetaan kaikki laskelmat
  //Serial.println("intervalli: ");
  //Serial.println(summa);
  Serial.print("Painallusten keskiarvo oli: " );
  Serial.print(keskiarvo);
  Serial.println(" sekunttia");
  //Serial.println("varianssi: "); 
  //Serial.println(varianssi);
  Serial.print("Painallusten Keskihajonta oli: ");  
  Serial.print(keskiHajonta);
  Serial.println(" sekunttia");

  painonapinLaskuri = 0;
  }
 

  

