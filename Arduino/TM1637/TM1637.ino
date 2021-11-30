#include <TM1637Display.h>
#define CLK 3
#define DIO 4
#define pb 2
TM1637Display display(CLK, DIO);
int nilai;
void setup() {
Serial.begin(115200);
  pinMode(pb,INPUT);
  display.setBrightness(0x0f);
    attachInterrupt(digitalPinToInterrupt(pb),Update,HIGH);
}
void loop() {
//  for (nilai = 00; nilai <= 9999; nilai++) {
//    display.showNumberDec(nilai);
//  } uint8_t data[] = { 0xff, 0x7f, 0xff, 0xff };
 nilai++;
Serial.println(nilai);
}
void Update(){
 display.showNumberDec(nilai);
  
}
