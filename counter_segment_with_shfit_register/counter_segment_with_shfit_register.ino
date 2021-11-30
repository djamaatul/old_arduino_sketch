const byte pdata =  2;
const byte platch =  3;
const byte pclock=  4;
const byte dg[] = {8,9};
const byte angka[]={
  0b00000011,//0
  0b10011111,//1
  0b00100101,//2
  0b00001101,//3
  0b10011001,//4
  0b01001001,//5
  0b01000001,//6
  0b00011111,//7
  0b00000001,//8
  0b00001001,//9
  0b11111110,//.
  };
void setup() {
  Serial.begin(9600);
for(byte i = 0;i <=1;i++){
  pinMode(dg[i],OUTPUT);
}
  pinMode(pdata,OUTPUT);
  pinMode(platch,OUTPUT);
  pinMode(pclock,OUTPUT);
}

  byte data ;
byte puluhan;
void loop() {
for(byte x=0;x <=9;x++){
  data = x;
  digit(1);
tf(data);
digit(0);
tf(puluhan);
if(data == 9){
  puluhan ++; 
  if(puluhan==9){
    puluhan=0;
  }
}
delay(10);
}
}
void tf(byte dat){
  digitalWrite(platch,0);
  shiftOut(pdata,pclock,LSBFIRST,angka[dat]);
  digitalWrite(platch,1);  
 
}
void digit(byte kecuali){
 for(int x = 0;x<=1;x++){
if(x !=kecuali){
  digitalWrite(dg[x],0);
}else if (x == kecuali){
  digitalWrite(dg[x],1);}
 }
  delay(10);
}
