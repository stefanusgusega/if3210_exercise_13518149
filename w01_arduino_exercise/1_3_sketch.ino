const int kStartPinLed = 2;
const int kEndPinLed = 9;

void setup()
{
  for (int i = kStartPinLed; i <= kEndPinLed; i++) {
  	pinMode(i, OUTPUT);
  }
}

void loop()
{
  for (int i = kStartPinLed; i <= kEndPinLed; i++) {
  	digitalWrite(i, HIGH);
  	delay(500);
  }
  for (int i = kStartPinLed; i <= kEndPinLed; i++) {
  	digitalWrite(i, LOW);
  	delay(1000);
  } 
}