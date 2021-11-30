#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd1(0x3F,16,2);
LiquidCrystal_I2C lcd2(0x27,16,2);

void setup() {
lcd1.init();
lcd2.init();
lcd1.backlight();
lcd2.backlight();
}
void kanan(LiquidCrystal_I2C lcd_, int row){
  
  for(int i=0;i<=16;i++){
  lcd_.setCursor(i,row);
  lcd_.print(".");
  delay(100);
  lcd_.clear();
  
}
}
void kiri(){
  
}
void loop() {
  kanan(lcd1,0);
  kanan(lcd1,1);
}
