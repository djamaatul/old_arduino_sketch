#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
void setup() {
  Serial.begin(9600);
lcd.init();
lcd.backlight();
}
unsigned long waktu,akhir,milidetik;
byte detik,menit,jam;
void loop() {

if(clck(1000)){
  detik++;
  if(detik ==60){
    menit++;
      if(menit ==60){
    jam++;
      if(jam ==12){
    jam=0;
  }
    menit=0;
  }
    detik=0;
  }
  milidetik=0;

}
lcd.setCursor(0,0);
lcd.print((jam));
lcd.print(" : ");
lcd.print((menit));
lcd.print(" : ");
lcd.print((detik));
lcd.print(" : ");
lcd.print((milidetik));
}
bool clck(int batas){
 waktu = millis();
 if(waktu - akhir >=batas) {
 akhir=waktu;
 return 1;
 }
 return 0;
}
