#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
RTC_DS1307 jam;
LiquidCrystal_I2C lcd(0x3F,16,2);
String hari[]={"Minggu","Senin","Selasa","Rabu","Kamis","Jumat","Sabtu"};
void setup() {
jam.begin();
lcd.init();
lcd.backlight();
Serial.begin(9600);

}

void loop() {
      DateTime now = jam.now();
  lcd.clear();
lcd.setCursor(0,0);
lcd.print(hari[now.dayOfTheWeek()]+" : ");
lcd.setCursor(7,0);
lcd.print(now.hour());
lcd.print(":");
lcd.print(now.minute());
lcd.print(":");
lcd.print(now.second());
lcd.setCursor(0,1);
lcd.print(now.unixtime());

delay(1000);
}
