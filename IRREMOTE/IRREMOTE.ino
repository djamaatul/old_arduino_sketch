#include <IRremote.h>
#define RECV_PIN A1
IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;
void setup() {
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
    pinMode(10,INPUT);
      pinMode(11,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  digitalWrite(9,1);
  digitalWrite(8,1);
}
bool r1,r2,r3;
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
switch(results.value){
case 16507421 :
r1 = !r1;
break; 
case 16506911 :
r2 = ! r2;
break;
default :
break;
 }
 digitalWrite(8,r1);
 digitalWrite(9,r2);
    irrecv.resume();
  }
  if(digitalRead(10) == 1){ 
  for (int i = 0; i < 2; i++) {
    digitalWrite(11, HIGH);
    irsend.sendNEC(0x004eff71, 32);
    digitalWrite(11, LOW);
    delay(40);
  }
  }
}
