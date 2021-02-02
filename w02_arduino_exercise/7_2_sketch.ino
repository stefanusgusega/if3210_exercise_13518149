const int kPin_Tilt = 3;
const int kPinPiezo = 8;

void setup()
{
pinMode(kPin_Tilt, INPUT);
  digitalWrite(kPin_Tilt, HIGH);
pinMode(kPinPiezo, OUTPUT);  
}

void loop() 
{
  if(digitalRead(kPin_Tilt) == LOW) {
  	alarmSound();
  }
}

void alarmSound() {
  for (float f = 200; f < 4400; f = 1.5*f) {
    if (digitalRead(kPin_Tilt) == HIGH) {
    	break;
    }
  	tone(kPinPiezo, f);
    delay(200);
  }
  noTone(kPinPiezo);
}