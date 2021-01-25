const int kPinLed = 9;
const int kPinGas = 2;
const int kPinBrake = 3;

void setup()
{
  pinMode(kPinGas, INPUT);
  pinMode(kPinBrake, INPUT);
  digitalWrite(kPinGas, HIGH);
  digitalWrite(kPinBrake, HIGH);
  pinMode(kPinLed, OUTPUT);
}

int delayTime = 500;
int ledState = LOW;
long lastTime = 0;

void loop()
{
  if (digitalRead(kPinGas) == LOW) {
  	delayTime--;
  }
  else if (digitalRead(kPinBrake) == LOW) {
  	delayTime++;
  }
  
  delayTime = constrain(delayTime, 50, 500);
  
  if (lastTime + delayTime <= millis()) {
  	ledState = !ledState;
    digitalWrite(kPinLed, ledState);
    lastTime = millis();
  }
}