/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int kPinTemp = A0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Welcome!");
}
float maxF = -200;
float minF = 200;
void loop() {
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("Temp (F)");
  lcd.setCursor(0,1);
  
  if (getFahrenheit() > maxF) {
  	maxF = getFahrenheit();

  }
  if (getFahrenheit() < minF) {
  	minF = getFahrenheit();

  }
  lcd.print(String(getFahrenheit())+" Fahrenheit");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("Min F: ");
  lcd.print(minF);
  lcd.setCursor(0,1);
  lcd.print("Max F: ");
  lcd.print(maxF);
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