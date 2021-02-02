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
LiquidCrystal lcd(12, 11,5, 4, 3, 2);
const int kPinTemp = A2;
const int kPinSpeaker = 7;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Batas: 80 C");
  Serial.begin(9600);
  
  
}
bool text1 = true;
bool text2 = false;
void loop() {
 float curC = getTempC();
  if (curC >= 80) {
    if (text1) {
    	lcd.clear();
      text1 = false;
    }
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(0,1);
    lcd.print("Overheat!");
    text2 = true;
    alarm();
  }
  else {
    if (text2) {
    	lcd.clear();
      text2 = false;
      lcd.print("Batas: 80 C");
    	text1 = true;
    }
  	
  }
  
}

float getTempC() {
	int reading = analogRead(kPinTemp);
  float voltage = (reading * 5.0)/1024;
  return (voltage-0.5)*100;
}

void alarm() {
	tone(kPinSpeaker, 400);
  delay(50);
  noTone(kPinSpeaker);
}
