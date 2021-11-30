#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SD.h>
File root;
const int chipSelect = 10;
const char baris = 4;
const char kolom = 3;
const char pinbaris[baris] = {2,3,4,6};
const char pinkolom[kolom] = {7,8,9};
char key[baris][kolom]={
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};

Keypad keypad = Keypad (makeKeymap(key),pinbaris,pinkolom,baris,kolom);

LiquidCrystal_I2C lcd(0x3F,16,2);


void setup() {
    Serial.begin(9600);
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  lcd.init();
  lcd.backlight();
  root  = SD.open("/");
}

String a;
void loop() {
  File entry;
root.rewindDirectory();

char tombol = keypad.getKey();
  if(tombol){
   root.openNextFile();
}
entry.close();
lcd.setCursor(0,0);
Serial.print(entry.name());
}
