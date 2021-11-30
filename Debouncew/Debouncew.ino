
///////////DEBOUNCE//////////////////

const uint8_t fretsPin[]={NULL,A0,A1,A2,A3,3,6};
uint8_t fretsData[7];
const uint8_t led[]={NULL,9,10,11,12,13};
const uint8_t select=8,
              start=7,
              x=A4,
              y=A5;
              
class button{
  public:
    byte pin;
    bool baca = 1;
    bool kondisi = 1;
    bool terbaca = 1;
    unsigned long waktu;
    byte batas = 5;
  button(byte pin){
    this -> pin = pin;
    pinMode(pin,INPUT_PULLUP);
  }
  
  bool read(){
  baca = digitalRead(pin);
  if(baca != kondisi){
    waktu = millis();
  }
  if(millis() - waktu > batas){
    if(baca != terbaca){
      terbaca = baca;
      if(terbaca == 0){
      return 0;
      }else{  return 1;}
     }
  }
  kondisi = baca;
  return 1;
  }
};
////////////////////////////////////
//button S1(fretsPin[1]);
//button S2(fretsPin[2]);
//button S3(fretsPin[3]);
//button S4(fretsPin[4]);
//button S5(fretsPin[5]);
//button S6(fretsPin[6]);
button SW[] = {
    button(fretsPin[1]),
    button(fretsPin[2]),
    button(fretsPin[3]),
    button(fretsPin[4]),
    button(fretsPin[1]),
    button(fretsPin[1]),
    };

void setup() {

Serial.begin(9600);
}
void loop() {
//  fretsData[1] = S1.read();
//  fretsData[2] = S2.read();
//  fretsData[3] = S3.read();
//  fretsData[4] = S4.read();
//  fretsData[5] = S5.read();
//  fretsData[6] = S6.read(); 
if(SW[2].read() ==0 ){
      Serial.println("3");
}
//if(empat.read()  ==1 ){
//      Serial.println("4");
//}
}
