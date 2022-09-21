Serial.begin(9600);
int pushButton = 2;
void setup()
{
  pinMode(2, INPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(10); // Delay a little bit to improve simulation performance
}
