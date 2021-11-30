/* 
 by djamaatul anbiya
 3 September 2020
*/
#define Selenoid 8 //Selenoid adalah pin 8
#define ON 0    //ON = 0/LOW karena Relay Active LOW
#define OFF 1   //OFF = 1/HIGH karena Relay Active LOW
#include <SoftwareSerial.h> //library untuk Software Serial
SoftwareSerial SerialBT(9,10); //objek Software Serial untuk SerialBT ,pin 9 untuk RX ,pin 10 untuk TX
void setup() {
  pinMode(Selenoid,OUTPUT); //inialisasi pin Selenoid/8 adalah OUTPUT
  SerialBT.begin(9600); //Memulai Serial Bluetooth
  SerialBT.setTimeout(10); //maksimal menunggi Serial 10ms,agar proses cepat
  SerialBT.print("MASUKAN PASSWORD : "); //print "Masukan Password" pada terminal Serial
  digitalWrite(Selenoid,ON); //Awal Selenoid keadaan off
}
String password; //menampung masukan terminal

void loop() {
if(SerialBT.available() >0)         //jika ada data di Serial
{
  password = SerialBT.readString(); //kirim data tersebut ke variable password

  if(password=="0000\r"){              /*Jika Password adalah 0000,catat : harus ada \r
                                       karena setiap kirim Serial kita menggunakan CR/ENTER agar rapih */
    SerialBT.println("SELAMAT DATANG : "); //jika benar print "SELAMAT DATANG :"
    digitalWrite(Selenoid,ON);              //Relay ON 3 Detik
    delay(3000);
    digitalWrite(Selenoid,OFF);
    password = "";                          //RESET data pada variable password 
    SerialBT.print("MASUKAN PASSWORD : ");  //Kembali print "MASUKAN PASSWORD : "
    }else{
      SerialBT.println("Salah");            //Jika Salah print "Salah"
      password = "";                        //RESET data pada variable password 
      SerialBT.print("MASUKAN PASSWORD : ");}//Kembali print "MASUKAN PASSWORD : "
}
   
}
