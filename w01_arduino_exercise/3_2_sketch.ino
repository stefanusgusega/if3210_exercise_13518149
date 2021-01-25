const int kPinLed = 9;
const int kPinPot = A0;
const int kPinButton = 2;

void setup()
{
  pinMode(kPinButton, INPUT);
  digitalWrite(kPinButton, HIGH);
  pinMode(kPinLed, OUTPUT);
}

long lastTime = 0;
int ledState = LOW;
void loop()
{
  int delayTime, potValue;
  if (digitalRead(kPinButton) == LOW) {
    potValue = analogRead(kPinPot);
  	delayTime = map(potValue, 0, 1023, 1023, 0);
  }
  if (lastTime + delayTime <= millis()) {
    	ledState = !ledState;
      	digitalWrite(kPinLed, ledState);
      	lastTime = millis();
  }
}
    