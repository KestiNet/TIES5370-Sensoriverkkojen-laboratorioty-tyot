/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int led = 10;           // the PWM pin the LED is attached to
int kirkkaus = 0;    // how bright the LED is
int muutos = 5;    // how many points to fade the LED by
int b1 = 3;
int b2 = 2;

// the setup routine runs once when you press reset:
void setup() {
    attachInterrupt(digitalPinToInterrupt(b1), kirkastaa, RISING);
    attachInterrupt(digitalPinToInterrupt(b2), himmentaa, RISING);
    pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
}

void kirkastaa(){
  analogWrite(led, kirkkaus);

  // change the brightness for next time through the loop:
  kirkkaus = kirkkaus + muutos;
}

void himmentaa(){

}
