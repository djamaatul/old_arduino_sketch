#include <Servo.h>;
Servo servo;
#define trig 2
#define echo 3
long waktu;
int jarak;
bool tarik=0;

const int nscan=10;
int scan[nscan],total=0,rata=0,terbaca=0;
void setup() {
  servo.attach(4);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
    for (int thisReading = 0; thisReading < nscan; thisReading++) {
    scan[thisReading] = 0;
  }
}
int tahan=0;
void loop() {  
    digitalWrite(2,0);
  delayMicroseconds(2);
    digitalWrite(2,1);
  delayMicroseconds(10);
      digitalWrite(2,0);
waktu = pulseIn(echo,HIGH);
jarak = waktu*0.034/2;

total = total- scan[terbaca];
scan[terbaca] = jarak;
total = total + scan[terbaca]; 
terbaca++;
if(terbaca >= nscan){
  terbaca=0;
}
rata=total/nscan;
Serial.println(rata);
delay(1);
if(rata<=5){
    servo.write(180);
}else{servo.write(0);}
}
