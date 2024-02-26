const int buzzer=9;//buzzer to ardrino pin 9

void setup() {
 pinMode(buzzer,OUTPUT);//set buzzer-pin 9 as an output 

}

void loop() {
 tone(buzzer,1000);//send 1KHZ sound signal....
 delay(1000);    //....for 1 sec
 noTone(buzzer); //stop sound....
 delay(1000);  //....for 1 sec
}
