#define ON LOW
#define OFF !ON
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
LiquidCrystal_I2C lcd(0x20,20,4);


byte led = 3;
byte pb = 2;
byte pb2 = 4;
void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,OUTPUT);
    pinMode(4,INPUT_PULLUP);
  lcd.init();
}

long waktu =0;
long tbounce =0;
byte sbounce = 50;
bool statepb=OFF;
bool statepb2=OFF;
bool stateled=0;
void loop() {
  Serial.println(EEPROM.read(0));
  bt(pb);
 lcd.setCursor(0,0);
 digitalWrite(led,EEPROM.read(0));
}
void bt(int apb){

    waktu = millis();
    if(waktu - tbounce >= sbounce){
      statepb=digitalRead(apb);
      if(statepb != statepb2){
        if(statepb == 1){
      stateled = !stateled;
EEPROM.write(0,stateled);
        }
    }
    statepb2 = statepb;
    tbounce = waktu;
  }
}
