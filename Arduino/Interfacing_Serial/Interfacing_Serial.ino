/* 
 by djamaatul anbiya
 3 September 2020
*/
#include <SoftwareSerial.h> //library untuk Software Serial
SoftwareSerial SerialBT(2,3); //objek Software Serial untuk SerialBT ,pin 9 untuk RX ,pin 10 untuk TX
void setup() {
  Serial.begin(9600); //Memulai Serial Arduino
   /* Baudrate harus sama antara Serial Arduino dan Serial Bluetooth */
  SerialBT.begin(9600); //Memulai Serial Bluetooth
SerialBT.setTimeout(10); //maksimal menunggu Serial 10ms,agar proses cepat
Serial.setTimeout(10); //maksimal menunggu Serial 10ms,agar proses cepat
}
String databt;  //penampung data Serial BT
String dataar; //penampung data Serial Arduino
void loop() {
if(Serial.available() > 0){  //membaca kemudian mengirim ke Serial Bluetooth
  dataar = Serial.readString();
  SerialBT.println(dataar); //mengirim ke Serial Bluetooth
}
if(SerialBT.available() > 0){ //membaca Serial Bluetooth kemudian 
  databt = SerialBT.readString();
  Serial.println(databt); //mengirim ke Serial Aeduino
}
}
