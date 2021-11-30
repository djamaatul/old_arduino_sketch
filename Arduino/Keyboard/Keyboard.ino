
///////////DEBOUNCE//////////////////

class button{
  public:
    byte pin;
    bool baca = 0;
    bool kondisi = 0;
    bool terbaca = 0;
    unsigned long waktu;
    byte batas = 5;
  button(byte pin){
    this -> pin = pin;
    pinMode(pin,INPUT);
  }
  
  bool read(){
  baca = digitalRead(pin);
  if(baca != kondisi){
    waktu = millis();
  }
  if(millis() - waktu > batas){
    if(baca != terbaca){
      terbaca = baca;
      if(terbaca){
      return 1;
      }else{  return 0;}
     }
  }
  kondisi = baca;
  return 0;
  }
};
////////////////////////////////////

button t1(2);
button t2(3);
button t3(4);
button t4(5);

void setup() {

  Serial.begin(9600);
}

void loop() {
Serial.print(t1.read());
Serial.print(t2.read());
Serial.println(t3.read());
}
