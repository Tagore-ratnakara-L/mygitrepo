/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 13
 * LCD Enable pin to digital pin 12
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
#include <RH_ASK.h> // Include RadioHead Amplitude Shift Keying Library
#include <SPI.h> // Include dependant SPI Library

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13,12, 5, 4, 3, 2);
int buz = 9;
const int lowrange = 2000;   
const int highrange = 4000; 

void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Initialize ASK Object
rf_driver.init();
// Setup Serial Monitor
Serial.begin(9600);
pinMode(buz,OUTPUT);
}

void loop() 
{ 
  lcd.setCursor(0,0);
// Set buffer to size of expected message
uint8_t buf[10];
uint8_t buflen = sizeof(buf);
// Check if received packet is correct size
if (rf_driver.recv(buf, &buflen))
{
// Message received with valid che-cksum
Serial.println("Message Received: ");
Serial.println((char*)buf);
lcd.println((char*)buf);

     for (int i = lowrange; i <= highrange; i++)
    {
      tone (buz, i, 200);
    }
   
    for (int i = highrange; i >= lowrange; i--)
    {
      tone (buz, i, 200);
    }
for (int i = lowrange; i <= highrange; i++)
    {
      tone (buz, i, 200);
    }
   
    for (int i = highrange; i >= lowrange; i--)
    {
      tone (buz, i, 200);
    }
    for (int i = lowrange; i <= highrange; i++)
    {
      tone (buz, i, 200);
    }
   
    for (int i = highrange; i >= lowrange; i--)
    {
      tone (buz, i, 200);
    }
delay(3000);
lcd.clear();
}
}
