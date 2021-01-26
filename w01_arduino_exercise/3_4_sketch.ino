const int kPinPotR = A2;
const int kPinPotG = A0;
const int kPinPotB = A1;
const int kPinFromBtn = 2;
const int kPinToBtn = 4;
const int kPinLedR = 6;
const int kPinLedG = 10;
const int kPinLedB = 11;

void setup()
{
  pinMode(kPinLedR, OUTPUT);
  pinMode(kPinLedG, OUTPUT);
  pinMode(kPinLedB, OUTPUT);
  pinMode(kPinFromBtn, INPUT);
  pinMode(kPinToBtn, INPUT);
  digitalWrite(kPinFromBtn, HIGH);
  digitalWrite(kPinToBtn, HIGH);
  Serial.begin(9600);
}
int fromR = 0;
int fromG = 0;
int fromB = 0;
int toR = 255;
int toG = 255;
int toB = 255;
int curr = 0;
int change = 1;
int sumOfTime = 0;
int loopSum = 0;
float avgDur = 0;

void loop()
{
  int start = millis();
  int potValR, potValG, potValB;
  potValR = analogRead(kPinPotR);
  potValG = analogRead(kPinPotG);
  potValB = analogRead(kPinPotB);
  if (digitalRead(kPinFromBtn) == LOW) {
	fromR = map(potValR, 0, 1023, 0, 255);
    fromG = map(potValG, 0, 1023, 0, 255);
    fromB = map(potValB, 0, 1023, 0, 255);
    

  }
  else if (digitalRead(kPinToBtn) == LOW) {
  	toR = map(potValR, 0, 1023, 0, 255);
    toG = map(potValG, 0, 1023, 0, 255);
    toB = map(potValB, 0, 1023, 0, 255);
  }
  else {
    curr += change;
    if (curr == 0) {
    	change = 1;
    }
    if (curr == 255) {
    	change = -1;
    }
    int newValR = map(curr, 0, 255, fromR, toR);
    int newValG = map(curr, 0, 255, fromG, toG);
    int newValB = map(curr, 0, 255, fromB, toB);
    analogWrite(kPinLedR, newValR);
    analogWrite(kPinLedG, newValG);
    analogWrite(kPinLedB, newValB);
	delay((float)1000/(float)255);
  }
  int end = millis();
  int dur = end-start;
  sumOfTime += dur;
  loopSum += 1;
  avgDur = (float)sumOfTime/(float)loopSum;
  Serial.print("Average duration of loop: ");
  Serial.println(avgDur); // after 11 loops, avg: 3.55 ms.
}
    