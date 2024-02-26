#include <Wire.h>

#include <Adafruit_Sensor.h>

#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified BSens = Adafruit_ADXL345_Unified(1);

//the above are the libraries of the ADXL345. Spec sheet can be found here: https://www.adafruit.com/products/1231 and drivers and libraries can be found here: https://github.com/adafruit/Adafruit_ADXL345

int led=9;              //led at pin 9
int ledValue;           //value of led
int ledFadeAmount = 5;  //value when led is fading

void setup() {

pinMode(led, OUTPUT);                 //led specified as output
Serial.begin(2400);                   //starting serial at 2400 baud
BSens.begin();                        //initialize the ADXL345
sensors_event_t event;                //collect data from ADXL345
BSens.getEvent(&event);               //read data from ADXL345
float pos = event.acceleration.x;     //test purpose for determining position of x. Future use.

}

void ledFadeIn(){                     //function of fade from 16 to 255

  sensors_event_t event;              //collect data from ADXL345
  BSens.getEvent(&event);             //read data from ADXL345
 
  if (event.acceleration.x > -8.50 | event.acceleration.x < -10.00){  //if x position is greater than -8.50 or x is smaller than -10.00
    ledValue = ledValue + ledFadeAmount;                              //set led value to the sum of led value and fade amount
    if(ledValue > 255)                                                //if led value is greather than 255
     ledValue = 255;                                                  //set led value to 255. Stops looping between led value 16 and 255. Thanks PaulS!
    analogWrite(led, ledValue);                                       //analog write of led value to led (pin 9)
    delay(30);                                                        //delay of 30 ms then start the ledfadein again
    }

}

void ledFadeOut(){                    //function of fade from 255 to 16

  sensors_event_t event;              //collect data from ADXL345
  BSens.getEvent(&event);             //read data from ADXL345

  if (event.acceleration.x < -8.50 | event.acceleration.x > -10.00){  //if x position is smaller than -8.50 or x is larger than -10.00
    ledValue = ledValue - ledFadeAmount;                              //set led value to the sum of led value minus the fade amount
    if(ledValue < 16)                                                 //if led value is smaller than 255
      ledValue = 16;                                                  //set led value to 16. Stops looping between led value 255 and 16. Thanks PaulS!
    analogWrite(led, ledValue);                                       //analog write of led value to led (pin 9)
    delay(30);                                                        //delay of 30 ms then start the ledfadeout again
    }
   
}

void loop() {
 
  sensors_event_t event;              //collect data from ADXL345
  BSens.getEvent(&event);             //read data from ADXL345
  float pos = event.acceleration.x;   //test purpose for determining position of x. Future use.
  Serial.println(ledValue);           //print value of led in the Serial Monitor

  if (event.acceleration.x > -8.50 | event.acceleration.x < -10.00)    //if x position is greater than -8.50 or x is smaller than -10.00
    ledFadeIn();                                                       //goto the ledFadeIn function
  else                                                                 
    ledFadeOut();                                                      //goto the ledFadeIn function
 
}
