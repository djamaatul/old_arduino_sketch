#include <Servo.h>
Servo servo;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  servo.attach(3);
}
void loop() {
  Serial.println(analogRead(A0));
  if(analogRead(A0)<=170){
    servo.write(180);
    delay(200);
  }else{
  
    servo.write(0);
    delay(100);
  }
}
