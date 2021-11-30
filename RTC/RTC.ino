#include <RTC.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
static DS1307 jam;
LiquidCrystal_I2C lcd(0x3F,16,2);
String hari[]={"Minggu","Senin","Selasa","Rabu","Kamis","Jumat","Sabtu"};
void setup() {
jam.begin();
lcd.init();
lcd.backlight();
Serial.begin(9600);
 jam.setDate(26,8,2020);
jam.setTime(17,56,30);
jam.setWeek(3);
}

void loop() {
  lcd.clear();
lcd.setCursor(0,0);
lcd.print(hari[jam.getWeek()]+" : ");
lcd.setCursor(7,0);
lcd.print(jam.getHours());
lcd.print(":");
lcd.print(jam.getMinutes());
lcd.print(":");
lcd.print(jam.getSeconds());
lcd.setCursor(0,1);
lcd.print(jam.getEpoch());
delay(1000);

}
