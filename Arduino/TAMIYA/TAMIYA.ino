#include <SoftwareSerial.h> //library untuk Software Serial
SoftwareSerial BT(2,3); //objek Software Serial untuk SerialBT ,pin 9 untuk RX ,pin 10 untuk TX
#define motor1 A0
#define motor2 A1
#define pwmpin 9
void setup() {
pinMode(motor1,OUTPUT);
pinMode(pwmpin,OUTPUT);
pinMode(motor2,OUTPUT);
Serial.begin(9600); 
BT.begin(9600);
}
int masukan;
int data[3]={0,0,0};
byte indexdata;
int x,y;
uint8_t pwm;
void loop() {

if(BT.available() > 0){ //membaca Serial Bluetooth kemudian 
masukan = BT.read();

if(masukan == 255){
  indexdata = 0;
}
data[indexdata] = masukan;
indexdata ++;

}


x = data[1];
y = data[2]; 

if(x== 100 && y == 100){

  Stop();

}
  if(y >= 0 && y <100){   
       maju();  
}

  if(y >= 100 && y <200){
mundur();

}
}
void maju(){

    y = map(y,100,0,0,255);
           analogWrite(pwmpin,y);
           Serial.println(y);
digitalWrite(motor1,1);
digitalWrite(motor2,0);
  
}
void mundur(){

    y = map(y,100,200,0,255);
               analogWrite(pwmpin,y);
                   Serial.println(y);
digitalWrite(motor1,0);
digitalWrite(motor2,1);
}

void Stop(){
  digitalWrite(motor1,0);
  digitalWrite(motor2,0);
}
