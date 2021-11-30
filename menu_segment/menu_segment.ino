#define b1 A0 //define the button pin
#define b2 A1 

///////////DEBOUNCE//////////////////
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
//////////////DEBOUNCE////////
//djamaatul 21/9/20 /////
class button{
  public:
    byte pin;
    bool baca = 0;
    bool kondisi = 0;
    bool terbaca = 0;
    unsigned long waktu;
    byte batas = 2;
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

byte number[28]{
               0b00111111, //0
               0b00000110, //1
               0b01011011, //2
               0b01001111, //3
               0b01100110, //4 
               0b01101101, //5
               0b01111101, //6
               0b00000111, //7
               0b01111111, //8
               0b01101111, //9
               0b01110111, //a
               0b01111100, //b
               0b00111001, //c
               0b01011110, //d
               0b01111001, //e
               0b01110001, //f
               0b01101111, //g
               0b01110110, //h
               0b00111000, //l
               0b01011100, //o
               0b01110011, //p
               0b01100111, //q
               0b00011001, //r
               0b01111000, //t
               0b00011100, //u
               0b00111110, //v
               0b01101111, //y
               0b00000000, //NULL
               };
byte pindig[]={10,11,12,13};
byte pinseg[]={2,3,4,5,6,7,8,9};

void setup() {
  Serial.begin(9600);
  for(uint8_t i = 0;i <=7 ; i++){
    pinMode(pinseg[i],OUTPUT);
  }
  
  for(uint8_t i = 0;i <=3 ; i++){
    pinMode(pindig[i],OUTPUT);
  }
  isclear(pinseg,7,0);
  isclear(pindig,3,1);
}

button button1(b1); // DEKLARASI TOMBOL
button button2(b2);

uint8_t menuIn=0; //menu in ... //pilih 
char data[4];
String StringSeg;
void loop() {
menuIn =0;
    if(button1.read()){       //Button 1 read
      menuIn++;               //menuIn increase
      pemilihan(menuIn);           //to menu function
      if(menuIn >=4){          //reset to zero //menu length
        menuIn=0;}
    }
Serial.println("RUNNING");
}


void pemilihan(uint8_t ke){ //select fungtion
uint8_t pilih;
 pilih =data[ke];
 while(1){
 if(button2.read()){
    pilih++;
    data[ke] = pilih;
 }
 if(pilih >= sizeof(number)){
    pilih =0; 
  }
 if(button1.read()){
    menuIn++;
    if(menuIn >4){
      return 0;
    }
  }
if(jeda(200)){
  
bool state;
state = !state;
       digitalWrite(pindig[ke],state);
}
Serial.print(menuIn);
Serial.print(" :");
Serial.println(pilih);
  }
  return 0;
}


void setdig(byte pilih){
   for(int x = 0;x<=3;x++){
   if(x ==pilih){
     digitalWrite(pindig[x],0);
     }
     else if (x != pilih){
     digitalWrite(pindig[x],1);
     }
  }
}

void setseg(uint8_t no){
  bool bitset;
    for(uint8_t i = 0 ;i <=7;i ++){
     bitset = bitRead(number[no],i);
     digitalWrite(pinseg[i],bitset);
    }
    delay(5);
}

void segPrint(String chara,bool scroll){
char is[8];
  chara.toCharArray(is,8);
  for(byte x = 0 ;x<chara.length();x++){

    switch(is[x]){ //character
      case 'a' : setseg(10);
      break;
      case 'b' :setseg(11);
      break;
      case 'c' :setseg(12);
      break;
      case 'd' :setseg(13);
      break;
      case 'e' :setseg(14);
      break;
      case 'f' :setseg(15);
      break;
      case 'g' :setseg(16);
      break;
      case 'h' :setseg(17);
      break;
      case 'l' :setseg(18);
      break;
      case 'o' :setseg(19);
      break;
      case 'p' :setseg(20);
      break;
      case 'q' :setseg(21);
      break;
      case 'r' :setseg(22);
      break;
      case 't' :setseg(23);
      break;
      case 'u' :setseg(24);
      break;
      case 'v' :setseg(25);
      break;
      case 'y' :setseg(25);
      break;
      case ' ' :setseg(27);
      break;
      default  :setseg(is[x]-'0'); //char to int
      break;
    }
  }
}
void isclear(String data,uint8_t ndata, uint8_t dataclear){ //hapus data array
  for(uint8_t i = 0;i <=ndata ; i++){
  digitalWrite(data[i],dataclear);
  }
}

unsigned long waktu;
unsigned long batas;

bool jeda(int sampai){ //blink
  waktu=millis();

  if(waktu - batas > sampai){
     batas=waktu;
     return 1;
     }
  return 0;
}
