/* ------------------------------------------------------------------------------- */
// character LCD example code
// www.hacktronics.com

#include <LiquidCrystal.h>

// Connections:
// rs (LCD pin 4) to Arduino pin 12
// rw (LCD pin 5) to Arduino pin 11
// enable (LCD pin 6) to Arduino pin 10
// LCD pin 15 to Arduino pin 13
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

//byte smiley[8] = {
  //B00000,
  //B10001,
  //B00000,
  //B00000,
  //B10001,
  //B01110,
  //B00000,
//};

int backLight = 13;    // pin 13 will control the backlight
const int kPinTemp = A0;
void setup()
{
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();                  // start with a blank screen
  // change text to whatever you like. keep it clean!
  //lcd.setCursor(0,1);           // set cursor to column 0, row 1
  //lcd.print("arduino lcd  ");
  
  //lcd.createChar(0, smiley);
  //lcd.setCursor(15, 1);  
  //lcd.write(byte(0));
  
  // inicializa la comunicación serial en 9600 bits por segundo
  Serial.begin(9600);
  
  
}
float maxF = -200;
long lastMax;
float minF = 200;
long lastMin;

void loop()
{
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("Temp (F)");
  lcd.setCursor(0,1);
  
  if (getFahrenheit() > maxF) {
  	maxF = getFahrenheit();
    lastMax = millis();
  }
  if (getFahrenheit() < minF) {
  	minF = getFahrenheit();
    lastMin = millis();
  }
  lcd.print(String(getFahrenheit())+" Fahrenheit");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("Min F: "+String(minF));
  lcd.setCursor(0,1);
  lcd.print("Max F: ");
  lcd.print(String(maxF));
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("LastSeenMin: "+String(millis() - lastMin));
  lcd.setCursor(0,1);
  lcd.print("LastSeenMax: ");
  lcd.print(String(millis() - lastMax));
  delay(1000);
  lcd.clear();
}

float getCelsius() {
	int reading = analogRead(kPinTemp);
  	float voltage = reading * 5.0 /1024;
  	return (voltage - 0.5)*100;
}

float getFahrenheit() {
	return (9.0/5.0)*getCelsius() + 32;
}