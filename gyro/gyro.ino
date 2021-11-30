#include <MPU6050.h>
#include <Wire.h>
MPU6050 mpu;

class smooth{
public:
int isdata;
int sdata[10];
int ndata =0;
int total =0;
int rata =0;

smooth(int isdata){
  for(byte i = 0;i<=10;i++){
  sdata[i]=0;
}
  this-> isdata = isdata;
  proses();
}
void proses(){
total = total - sdata[ndata];
sdata[ndata] = isdata;
total = total + sdata[ndata];
ndata++;
if(ndata >=10){ndata = 0;}
  rata = total/10;
  read();
}
int read(){
  return  rata;
}
};

void setup() {
  Serial.begin(115200);
mpu.begin();
  mpu.calibrateGyro();
  mpu.setThreshold(3);
  Vector rawGyro = mpu.readRawGyro();
  Vector rawAccel = mpu.readRawAccel();
  

}
smooth xac(rawAccel.XAxis);
void loop() {

 
//  Serial.print("X : ");
//  Serial.println(rawGyro.XAxis);
//  Serial.print("Y : ");
//  Serial.print(rawGyro.YAxis);
//  Serial.print("Z : ");
//  Serial.println(rawGyro.ZAxis);
// 

//Serial.println(xac.read());
//  Serial.print("X : ");
//  Serial.println(rawAccel.XAxis);
//  Serial.print("Y : ");
//  Serial.print(rawAccel.YAxis);
//  Serial.print("Z : ");
//  Serial.println(rawAccel.ZAxis);

}
