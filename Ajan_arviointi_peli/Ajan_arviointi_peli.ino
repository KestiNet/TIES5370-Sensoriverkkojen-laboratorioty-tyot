int pushButton = 2;
int count = 0;
int val;

void setup()
{
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop()
{
 count = digitalRead(pushButton);{
   Serial.println(count);
    count++;
 }
 

 delay(10);
 
  }
