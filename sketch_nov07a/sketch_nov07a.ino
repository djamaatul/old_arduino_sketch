/* Frets Control for Frets On fire or Guitar Hero */
/*by djamaatul anbiya 06/11/2020 */
#include "UsbKeyboard.h"

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
      pinMode(led[i],OUTPUT);  
  }
      pinMode(start,INPUT_PULLUP); 
      pinMode(select,INPUT_PULLUP); 
            digitalWrite(start,1);
            digitalWrite(select,1);
      
      
  #if BYPASS_TIMER_ISR
    TIMSK0&=!(1<<TOIE0); // ++
  #endif
  
}
  #if BYPASS_TIMER_ISR
  void delayMs(unsigned int ms) {
    for (int i = 0; i < ms; i++) {
      delayMicroseconds(1000);
    }
  }
  #endif
void loop() {
//   Serial.println(xx.terata(analogRead(x),10)+String(",")+yy.terata(analogRead(y),10));  //test your average your joy module
//  Serial.println(analogRead(x)+String(",")+analogRead(y));  //test your average your joy module

  UsbKeyboard.update();

  statusKey();
  #if BYPASS_TIMER_ISR  
    delayMs(50);
  #else
      delay(50);
  #endif
}

void joy(){                                     //Send data Joy
      if(analogRead(x) < 500){
     UsbKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  }
//  else if(1111analogRead(x) > 600){               //not work
//     UsbKeyboard.sendKeyStroke(KEY_ARROW_RIGHT);
//  }
    if(analogRead(y) < 500){
     UsbKeyboard.sendKeyStroke(KEY_ARROW_UP);
  }
//  else if(analogRead(y) > 600){               //not work
//     UsbKeyboard.sendKeyStroke(KEY_ARROW_DOWN);
//  }
}

void statusKey(){                           //Get Status data Switch Key
  
    for(uint8_t i = 1; i<=6;i++){
        if(digitalRead(fretsPin[i]) == 0 ){
          sendkey(i);
        }
    }
    if(digitalRead(select) ==0 ){
      sendkey(7);
    }else if(digitalRead(start) == 0 ){
      sendkey(8);
    }
}
void sendkey(uint8_t to){         
  switch(to){
    case 1:
//    Serial.println("1");
      UsbKeyboard.sendKeyStroke(KEY_1);
      break;
    case 2:
//     Serial.println("2");
      UsbKeyboard.sendKeyStroke(KEY_2);
       break;
    case 3:
//     Serial.println("3");
     UsbKeyboard.sendKeyStroke(KEY_3);
      break;
    case 4:
//     Serial.println("4");
      UsbKeyboard.sendKeyStroke(KEY_4);
      break;
    case 5:
//     Serial.println("5");
      UsbKeyboard.sendKeyStroke(KEY_5);
      break;
    case 6:
//     Serial.println("6");
      UsbKeyboard.sendKeyStroke(KEY_6);
      break;
    case 7:
//     Serial.println("7");
      UsbKeyboard.sendKeyStroke(KEY_SPACE);
      break;
    case 8:
//     Serial.println("8");
      UsbKeyboard.sendKeyStroke(KEY_ENTER);
      break;
   default :
      break;
  }
}
