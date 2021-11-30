const byte pindat = 2;
const byte pinlatch = 3;
const byte pinclock = 4;
byte data=B01010000;
unsigned long waktu;
unsigned long akhir=waktu;
void setup() {
  pinMode(pindat,OUTPUT);
  pinMode(pinclock,OUTPUT);
  pinMode(pinlatch,OUTPUT);
}

void loop() {
  if(bounc(200)){   
 if(data == B01010000)
 {
  data = B00100000;
 }else 
  {
  data = B01010000;
  }
  }
  digitalWrite(pinlatch,0);
  shiftOut(pindat,pinclock,LSBFIRST,data);
  digitalWrite(pinlatch,1); 
}
bool bounc(int batas){
  waktu = millis();
  if(waktu - akhir >=batas ){
    akhir = waktu;
    return true;
  }
  return false;
}
