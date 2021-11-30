
///////////MULTITASK//////////////////
//by djamaatul 14/10/2020
class multitask{
  public :
  unsigned long waktu;
  unsigned long current;
  uint16_t batas ;
bool task(uint16_t batas){
  waktu = millis();
  if( waktu - current == batas){
    current = waktu;
  return 1;
  }
  return 0;
}
};
//////////////////////////////////
multitask text1; //declaration is : multitask *name
multitask text2;


void setup() {
Serial.begin(9600);
}
//bool state;
void loop() {
if(text1.task(1000)){ // how to use *name.task(time execute)
  Serial.println("**"); // execute this!! 
//  state != state;             //example for led blink without delay
//  digitalWrite(pinled,state);
}

if(text2.task(100)){
  Serial.println("#####"); //0,1second
}

}
