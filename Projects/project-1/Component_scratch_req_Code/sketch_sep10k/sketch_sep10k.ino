#include <Wire.h>

#include <Adafruit_Sensor.h>

#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified BSens = Adafruit_ADXL345_Unified(1);
void displaySensorDetails(void)
{
  sensor_t sensor;
  accel.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" m/s^2");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" m/s^2");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" m/s^2");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}
  void setup(void) 
{
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(13,OUTPUT);
#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif
  Serial.begin(9600);
  Serial.println("Accelerometer Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }

  /* Set the range to whatever is appropriate for your project */
  accel.setRange(ADXL345_RANGE_16_G);
  // accel.setRange(ADXL345_RANGE_8_G);
  // accel.setRange(ADXL345_RANGE_4_G);
  // accel.setRange(ADXL345_RANGE_2_G);
  
  /* Display some basic information on this sensor */
  displaySensorDetails();
  
  /* Display additional settings (outside the scope of sensor_t) */
  displayDataRate();
  displayRange();
  Serial.println("");
  // Initialize ASK Object
  rf_driver.init();
  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop() {
   /* Get a new sensor event */ 
  sensors_event_t event; 
  accel.getEvent(&event);
 
  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");
  delay(500);
  
  sensors_event_t event;
  BSens.getEvent(&event);
  Serial.println(event.acceleration.x);
   if (event.acceleration.x>5)
  {
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    delay(500);
    digitalWrite(9,LOW);
    Serial.println("Need Water");
  }
  }
  else 
  { Serial.println("");
  digitalWrite(10,LOW);
  }
    sensors_event_t event;
  BSens.getEvent(&event);
  Serial.println(event.acceleration.y);
   if (event.acceleration.y>5)
  {
    digitalWrite(11,HIGH);
    digitalWrite(9,HIGH);
    delay(500);
    digitalWrite(9,LOW);
    Serial.println("Need food");
  }
  else 
  {Serial.println("");
  digitalWrite(11,LOW);} 
    sensors_event_t event;
  BSens.getEvent(&event);
  Serial.println(event.acceleration.x);
  if (event.acceleration.x<-5)
  {
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    delay(500);
    digitalWrite(9,LOW);
    Serial.println("Need med");
  }
  else 
  { Serial.println("");
  digitalWrite(8,LOW);}
  sensors_event_t event;
  BSens.getEvent(&event);
  Serial.println(event.acceleration.y);
if (event.acceleration.y<-5)
  {
    digitalWrite(13,HIGH);
    digitalWrite(9,HIGH);
    delay(500);
    digitalWrite(9,LOW);
    Serial.println("Need help");
  }
  else 
  {Serial.println("");
  digitalWrite(13,LOW);}
  }
  
