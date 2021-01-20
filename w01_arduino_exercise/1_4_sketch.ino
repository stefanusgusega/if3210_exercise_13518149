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
    for (int j = i; j <= kEndPinLed; j++) {
    	digitalWrite(j, HIGH);
  		delay(500);	
    }
    for (int k = kEndPinLed; k > i; k--) {
    	digitalWrite(k, LOW);
      	delay(500);
    }
  	
    
  }
}