const byte pindat = 2;
const byte pinlatch = 3;
const byte pinclock = 4;
const byte pb = 5;
byte data=0x0;
bool state=0,state2=0;
unsigned long waktu;
unsigned long akhir=waktu,akhir2=waktu;
void setup() {
  Serial.begin(9600);
  pinMode(pindat,OUTPUT);
  pinMode(pinclock,OUTPUT);
  pinMode(pb,INPUT);
  pinMode(pinlatch,OUTPUT);
}

void loop() {
  if(digitalRead(pb)){
    bitWrite(data,1,1);
  }else{bitClear(data,1);}
  bounc(20);
if(state){
  bitSet(data,3);
}else{bitClear(data,3);}
  bounc2(100);
if(state2){
  bitSet(data,6);
}else{bitClear(data,6);}
  digitalWrite(pinlatch,0);
  shiftOut(pindat,pinclock,LSBFIRST,data);
  digitalWrite(pinlatch,1);
}
bool bounc(int batas){
  waktu = millis();
  if(waktu - akhir >=batas ){
    akhir = waktu;
    state = !state;
    return true;
  }
  return false;
}
bool bounc2(int batas){
  waktu = millis();
  if(waktu - akhir2 >=batas ){
    akhir2 = waktu;
    state2 = !state;
    return true;
  }
  return false;
}
