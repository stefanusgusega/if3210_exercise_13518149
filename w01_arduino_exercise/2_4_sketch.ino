const int kNumLed = 7;
const int kPinLeds[kNumLed] = {3,4,5,6,7,8,9};

void setup()
{
  for (int i=0; i < kNumLed; i++) {
  	pinMode(kPinLeds[i], OUTPUT);
  }
}

void loop() {
	int j = kNumLed/2;
  	digitalWrite(kPinLeds[j], HIGH);
  	for (int i = 1; i <= kNumLed/2; i++) {
  		digitalWrite(kPinLeds[j-i],HIGH);
      	digitalWrite(kPinLeds[j+i],HIGH);
      	delay(100);
      	digitalWrite(kPinLeds[j-i],LOW);
      	digitalWrite(kPinLeds[j+i],LOW);
      	delay(100);
  	}
    for (int i = 0;i < kNumLed/2; i++) {
          digitalWrite(kPinLeds[kNumLed-i-1], HIGH);
          digitalWrite(kPinLeds[i], HIGH);
          delay(100);
          digitalWrite(kPinLeds[kNumLed-i-1], HIGH);
          digitalWrite(kPinLeds[i],LOW);
          delay(100);
    	}
}