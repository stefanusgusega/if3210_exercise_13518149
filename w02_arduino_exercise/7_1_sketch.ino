const int kPin_Photocell = A0;
const int kPinLED = 9;

void setup()
{
Serial.begin(9600);
pinMode(kPinLED, OUTPUT);  
}

void loop() 
{
	int value = analogRead(kPin_Photocell);
  int brightness = map(value,54,974,0,255);
  Serial.println(brightness);
  analogWrite(kPinLED, brightness);
}