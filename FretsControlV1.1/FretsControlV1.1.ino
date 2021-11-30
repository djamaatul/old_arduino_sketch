#include <USBKeyboard.h>
#define LAYOUT LAYOUT_US

USBKeyboard control = USBKeyboard();

const uint8_t fretsPin[]={NULL,A0,A1,A2,A3,3,6};
const uint8_t led[]={NULL,9,10,11,12,13};
const uint8_t select=8,
              start=7,
              x=A4,
              y=A5;

void setup() {

Serial.begin(9600);
   for(uint8_t i = 1; i<=6;i++){
       pinMode(fretsPin[i],INPUT_PULLUP);
       digitalWrite(fretsPin[i],1);
   }
   for(uint8_t i = 1; i<=5;i++){
    pinMode(led[i],OUTPUT);}
    pinMode(start,INPUT_PULLUP); 
    pinMode(select,INPUT_PULLUP); 
    digitalWrite(start,1);
    digitalWrite(select,1);
TIMSK0 = 0;
}

void loop() {
control.update();
statusKey();
keyClear();
delayMicroseconds(20000);
}

void joy(){                                     //Send data Joy
      if(analogRead(x) < 500){
//     UsbKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  }
//  else if(1111analogRead(x) > 600){               //not work
//     UsbKeyboard.sendKeyStroke(KEY_ARROW_RIGHT);
//  }
    if(analogRead(y) < 500){
//     UsbKeyboard.sendKeyStroke(KEY_ARROW_UP);
  }
//  else if(analogRead(y) > 600){               //not work
//     UsbKeyboard.sendKeyStroke(KEY_ARROW_DOWN);
//  }
}

void statusKey(){                           //Get Status data Switch Key
  
    for(uint8_t i = 1; i<=6;i++){
        if(digitalRead(fretsPin[i]) == 0 ){
          sendkey(i);}
    }
    if(digitalRead(select) ==0 ){
      sendkey(7);
    }else if(digitalRead(start) == 0 ){
      sendkey(8);
    };
}
void sendkey(uint8_t to){         
  switch(to){
    case 1:
//    Serial.println("1");
    control.sendReport(0, control.asciiToKeycode('1'), 0, 0, 0, 0, 0);
      break;
    case 2:
//     Serial.println("2");
    control.sendReport(0, control.asciiToKeycode('2'), 0, 0, 0, 0, 0);
       break;
    case 3:
//     Serial.println("3");
    control.sendReport(0, control.asciiToKeycode('3'), 0, 0, 0, 0, 0);
      break;
    case 4:
//     Serial.println("4");
    control.sendReport(0, control.asciiToKeycode('4'), 0, 0, 0, 0, 0);
      break;
    case 5:
//     Serial.println("5");
    control.sendReport(0, control.asciiToKeycode('5'), 0, 0, 0, 0, 0);
      break;
    case 6:
//     Serial.println("6");
    control.sendReport(0, control.asciiToKeycode('6'), 0, 0, 0, 0, 0);
      break;
    case 7:
//     Serial.println("7");
    control.sendReport(0, control.asciiToKeycode('\40'), 0, 0, 0, 0, 0);
      break;
    case 8:                             
//     Serial.println("8");
    control.sendReport(0, control.asciiToKeycode('\12'), 0, 0, 0, 0, 0);
      break;
   default :
      break;
  }
}
bool keyClear(){
        if(digitalRead(fretsPin[1]) == 1 && digitalRead(fretsPin[2]) == 1 && digitalRead(fretsPin[3]) == 1 &&digitalRead(fretsPin[4]) == 1 &&digitalRead(fretsPin[5]) == 1 &&
        digitalRead(start) == 1 &&digitalRead(select) == 1){
    control.sendReport(0,0, 0, 0, 0, 0, 0);}
}
