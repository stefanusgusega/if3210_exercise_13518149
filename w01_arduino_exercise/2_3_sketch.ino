const int kNumLed = 8;
const int kPinLeds[kNumLed] = {2,3,4,5,6,7,8,9};

void setup()
{
  for (int i=0; i < kNumLed; i++) {
  	pinMode(kPinLeds[i], OUTPUT);
  }
}

void loop()
{
  int i = 0;
  bool forward = true;
  while(1) {
    if (forward) {
      if (i == kNumLed-1) {
      	forward = !forward;
      }
      digitalWrite(kPinLeds[i], HIGH);
      delay(100);
      digitalWrite(kPinLeds[i], LOW);
      i++;
    }
    else {
      if (i == 0) {
      	forward = !forward;
      }
      digitalWrite(kPinLeds[i], HIGH);
      delay(100);
      digitalWrite(kPinLeds[i], LOW);
      i--;
    }
  }
  
}