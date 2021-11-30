/* 
 by djamaatul anbiya
 25 agustus 2020
*/

const byte pdata =  2;
const byte platch =  3;
const byte pclock=  4;
const byte pb=5;
byte data = 0 ;
byte bin1[]={ //data animasi1
129,//B10000001
66, //B01000010
36, //B00101000
24, //B00010000
36, //B00100100
66, //B01000010
};

void setup() {
  pinMode(pdata,OUTPUT);
  pinMode(platch,OUTPUT);
  pinMode(pclock,OUTPUT);
  pinMode(pb,INPUT);
  Serial.begin(9600);
}
int mode=0; 
void loop() {
  
for(int i=0;i<=40;i++){ //perulangan kanan 5X(40/8 = 5);
  kanan();tf();
  delay(100);
}

for(int i=0;i<=40;i++){ //perulangan kiri 5X(40/8 = 5);
  kiri();tf();
  delay(100);
}

for(int i=0;i<=35;i++){ //perulangan animasi1 5X(40/8 = 5);
  anim1();tf();
  delay(100);
}


}

void tf() //Kirim data ke shift register
{
  digitalWrite(platch,0);
  shiftOut(pdata,pclock,LSBFIRST,data);
  digitalWrite(platch,1);
}
void kanan()
{
  data = data <<= 1; //geser bit ke kiri
  if(data ==0)  //jika data 0/B00000000 ganti ke 1/B00000001
  {data = 1;}
}
void kiri()
{
  data = data >>= 1;  //geser bit ke kanan
  if(data ==0) //jika data 0/B00000000 ganti ke 128/B10000000
  {data = 128;}
}
byte a;
void anim1(){
 data =  bin1[a];
 if(a>=sizeof(bin1)-1){ //jika a bin1 >= length bin1 atau 5 ,maka a = 0
  a = 0;
 }else{a++;} //jika tidak >= length bin1 atau 5 ,maka a++
 delay(40);
}
