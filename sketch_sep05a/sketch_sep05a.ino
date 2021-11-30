#include <SoftwareSerial.h> //library untuk Software Serial
SoftwareSerial SerialBT(2,3); //objek Software Serial untuk SerialBT ,pin 9 untuk RX ,pin 10 untuk TX
void setup() {
  Serial.begin(9600); //Memulai Serial Arduino
  SerialBT.begin(9600); //Memulai Serial Bluetooth
Serial.setTimeout(1);
}
String terima; //penampung data Serial Arduino
String dataInt[1];
byte di=0;
void loop() {

if(SerialBT.available() > 0 ){
  terima = SerialBT.readString();
Serial.println(terima);
}

}
