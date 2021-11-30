/*  
   project by djamaatul 
/20 November 2020

*/


#include <USBKeyboard.h>
#define LAYOUT LAYOUT_US

USBKeyboard control = USBKeyboard();

const uint8_t fretsPin[]={NULL,A0,A1,A2,A3,3,6,7,8};  //Frets Pin 
const uint8_t led[]={NULL,13,12,11,10,9}; //Led Pin
const uint8_t x=A4, //XJoyStick Pin
              y=A5; //YJoystick Pin     
                        
uint8_t counter =0 ;    //Counter for Trigger LED Animation 
uint16_t waktu =0;      //this is Clock 
uint8_t kecepatan=8;    //Speed of Counter is 8
uint8_t ledMode = 0 ;   //LED MODE 

byte aniLed1[] = {B0100000,B0010000,B0001000,B0000100,B0000010,B00000000,B0100000,B0010000,B0001000,B0000100,B0000010,B00000000};   //LED Animation 1
byte aniLed2[] = {B0000010,B0000100,B0001000,B0010000,B0100000,B00000000,B0000010,B0000100,B0001000,B0010000,B0100000,B00000000};   //LED Animation 2
byte aniLed3[] = {B0110000,B0111000,B0111100,B0111110,B0011110,B0001110,B0000110,B0000010,B0000110,B0001110,B0011110,B01111100};   //LED Animation 3
byte aniLed4[] = {B0100000,B0000000,B0000000,B0010000,B0000000,B0001000,B0000000,B0000100,B0000000,B0000010,B0000000,B00000000};    //LED Animation 4
byte aniLed5[] = {B0100010,B0010100,B0001000,B0010100,B0100010,B00000000,B0100010,B0010100,B0001000,B0010100,B0100010,B00000000};   //LED Animation 5


void setup() {
//  Serial.begin(9600);
  for(uint8_t i = 1; i<=8;i++){                     ////Frets as INPUT PULLUP
      pinMode(fretsPin[i],INPUT_PULLUP);
      digitalWrite(fretsPin[i],1);
     }
  for(uint8_t i = 1; i<=5;i++){                     ///LED Pin as OUTPUT
  pinMode(led[i],OUTPUT);    
      }
/* USB timing has to be exact, therefore deactivate Timer0 interrupt */
  TIMSK0 = 0;
}
                                                                                                                                                                                                                                                                                                                                                                
uint8_t debounce =0; //cant millis() :/

void loop() {
  /* call this function at least every 20ms, otherwise an USB timeout will occur */  
 
  control.update();
  
if(digitalRead(fretsPin[6]) == 0){ //holding FretsPin[6] or joy button to next ledMode // 
    debounce++;
  if(debounce  <1){
   if(ledMode >=6){
       ledMode = 0;
     }else{
      ledMode++;}
  }else if(debounce >  1 && digitalRead( fretsPin[6]) == 1 ) {
    debounce =0;
  }

}
  keyClear();  /// No Key send Action if not any Frest Pressed 
     
  if(waktu >=kecepatan){   //this 8  turn a blink clock ,VUSB Library cant use millis for multitask;
     waktu = 0;
  }else{waktu++;}

  if(counter >=11){   //Range of Counter of 1 animation
     counter = 0;     //Reset to zero
  }else{
    if(waktu == 0){     //Counter Increase Trigger if Clock is zero
      if(ledMode==6 ){    //Special Speed  Counter for LED MODE 6
        kecepatan = 4;    //Speed 6
        counter = random(0,5); //and Counter Random 
        }else{
          kecepatan = 8;      //If Else LEDMODE 6 == Speed to 8 and counter increase
          counter++;}    
    }
  }
/*function for Check Frets State and send it */
joy();    
satu();
dua();
tiga();
empat();
lima();
Start();
Select();                                                              
/*///////////////////////////////////////////// */
 /* due to the deactivation of the Timer0 interrupt, delay()
   * and millis() won't work, call delayMicroseconds() instead */
delayMicroseconds(20000);
}


void jika(bool a,bool b,bool c,bool d,bool e,bool f ,bool g, bool h,uint8_t key1,uint8_t key2,uint8_t key3){   ///jika is indonesianLanguage == if, jika(pin Frets1 state,pin Frets2 state,etc ...,senKeyCode1,sendKeyCode2,sendKeyCode2)

  if(digitalRead(fretsPin[1]) == a && digitalRead(fretsPin[2]) == b && digitalRead(fretsPin[3]) == c && digitalRead(fretsPin[4]) == d 
    && digitalRead(fretsPin[5]) == e && digitalRead(fretsPin[6]) == f &&  digitalRead(fretsPin[7]) == g && digitalRead(fretsPin[8]) == h){
     control.sendReport(0, key1, key2, key3, 0, 0, 0);
     }
      
  switch(ledMode){
    case 0 :
  if(digitalRead(fretsPin[1])==0){digitalWrite(led[1],1);}else{digitalWrite(led[1],0);};
  if(digitalRead(fretsPin[2])==0){digitalWrite(led[2],1);}else{digitalWrite(led[2],0);};
  if(digitalRead(fretsPin[3])==0){digitalWrite(led[3],1);}else{digitalWrite(led[3],0);};
  if(digitalRead(fretsPin[4])==0){digitalWrite(led[4],1);}else{digitalWrite(led[4],0);};
  if(digitalRead(fretsPin[5])==0){digitalWrite(led[5],1);}else{digitalWrite(led[5],0);};
    break;
    case 1 :
  setLed(aniLed1[counter]);
    break;
    case 2 :
  setLed(aniLed2[counter]);
    break;
    case 3:
  setLed(aniLed3[counter]);
    break;
    case 4:
  setLed(aniLed4[counter]);
    break;
    case 5 :
  setLed(aniLed5[counter]);
    break;
    case 6 :
  setLed(aniLed1[counter]);
    break;
    default :
    break;
    }
}
void joy(){                                     //Send data Joy666
    if(analogRead(x) < 100){   control.sendReport(0, 80, 0, 0, 0, 0, 0);} 
        else if(analogRead(x) > 900){control.sendReport(0, 79, 0, 0, 0, 0, 0);} 
  if(analogRead(y) < 100){   control.sendReport(0, 82, 0, 0, 0, 0, 0);}  
        else if(analogRead(y) > 900){control.sendReport(0, 81, 0, 0, 0, 0, 0);}
}

void satu(){
jika(0,1,1,1,1,1,1,1,30,0,0);///
jika(0,0,1,1,1,1,1,1,30,31,0);
jika(0,1,0,1,1,1,1,1,30,32,0);
jika(0,1,1,0,1,1,1,1,30,33,0);
jika(0,1,1,1,0,1,1,1,30,34,0);
jika(0,1,1,1,1,1,0,1,30,40,0);
jika(0,1,1,1,1,1,1,0,30,44,0);///
jika(0,0,1,1,1,1,1,0,30,31,44);
jika(0,1,0,1,1,1,1,0,30,32,44);
jika(0,1,1,0,1,1,1,0,30,33,44);
jika(0,1,1,1,0,1,1,0,30,34,44);
jika(0,1,1,1,1,1,0,0,30,40,44);///
jika(0,0,1,1,1,1,0,1,30,31,40);
jika(0,1,0,1,1,1,0,1,30,32,40);
jika(0,1,1,0,1,1,0,1,30,33,40);
jika(0,1,1,1,0,1,0,1,30,34,40);
jika(0,1,1,1,1,1,0,0,30,44,40);//
}
void dua(){
jika(1,0,1,1,1,1,1,1,31,0,0);///
jika(1,0,0,1,1,1,1,1,31,32,0);
jika(1,0,1,0,1,1,1,1,31,33,0);
jika(1,0,1,1,0,1,1,1,31,34,0);
jika(1,0,1,1,1,1,0,1,31,40,0);
jika(1,0,1,1,1,1,1,0,31,44,0);///
jika(1,0,0,1,1,1,1,0,31,32,44);
jika(1,0,1,0,1,1,1,0,31,33,44);
jika(1,0,1,1,0,1,1,0,31,34,44);
jika(1,0,1,1,1,1,0,0,31,40,44);///
jika(1,0,0,1,1,1,0,1,31,32,40);
jika(1,0,1,0,1,1,0,1,31,33,40);
jika(1,0,1,1,0,1,0,1,31,34,40);
jika(1,0,1,1,1,1,0,0,31,44,40);//


}
void tiga(){
jika(1,1,0,1,1,1,1,1,32,0,0);///
jika(1,1,0,0,1,1,1,1,32,33,0);
jika(1,1,0,1,0,1,1,1,32,34,0);
jika(1,1,0,1,1,1,0,1,32,40,0);
jika(1,1,0,1,1,1,1,0,32,44,0);
jika(1,1,0,0,1,1,1,0,32,33,44);
jika(1,1,0,1,0,1,1,0,32,34,44);
jika(1,1,0,1,1,1,0,0,32,40,44);///
jika(1,1,0,0,1,1,0,1,32,33,40);
jika(1,1,0,1,0,1,0,1,32,34,40);

jika(1,1,0,1,1,1,0,0,32,44,40);//
}
void empat(){
jika(1,1,1,0,1,1,1,1,33,0,0);///
jika(1,1,1,0,0,1,1,1,33,34,0);  
jika(1,1,1,0,1,1,0,1,33,40,0);
jika(1,1,1,0,1,1,1,0,33,44,0);///
jika(1,1,1,0,0,1,1,0,33,34,44);
jika(1,1,1,0,1,1,0,0,33,40,44);///
jika(1,1,1,0,0,1,0,1,33,34,40);
jika(1,1,1,0,1,1,0,0,33,44,40);//
}
   
void lima(){
jika(1,1,1,1,0,1,1,1,34,0,0);///
jika(1,1,1,1,0,1,0,1,34,40,0);
jika(1,1,1,1,0,1,1,0,34,44,0);///
jika(1,1,1,1,0,1,0,0,34,40,44);
jika(1,1,1,1,0,1,0,0,34,44,40);//
}

void Start(){
jika(1,1,1,1,1,1,0,1,40,0,0);///
}
void Select(){
jika(1,1,1,1,1,1,1,0,44,0,0);///
}

     
void keyClear(){
if(analogRead(y) > 100 && analogRead(y) < 900 && digitalRead(fretsPin[1]) == 1 && digitalRead(fretsPin[2]) == 1 && digitalRead(fretsPin[3]) == 1 && digitalRead(fretsPin[4]) == 1
&& digitalRead(fretsPin[5]) == 1 && digitalRead(fretsPin[6]) ==1 &&  digitalRead(fretsPin[7]) == 1 && digitalRead(fretsPin[8]) == 1){
    control.sendReport(0,0, 0, 0, 0, 0, 0);}
    
}

void setLed(byte ledByte){
  bool bitset;
    for(uint8_t i = 1 ;i <=5;i ++){
     bitset = bitRead(ledByte,i);
     digitalWrite(led[i],bitset);
    }
}
