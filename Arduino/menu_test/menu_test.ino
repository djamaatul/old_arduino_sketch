//by djamaatul /////

#define b1 A0 //define the button pin
#define b2 A1

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
/////////////////DEBOUNCE ///////////


button button1(b1); // DEKLARASI TOMBOL
button button2(b2);

void setup() {
Serial.begin(9600);

}

uint8_t menuIn=0,pilih=0; //menu in ... //pilih or select
uint8_t luasdata =26; //luas data pilih  or Lentgth of data select
uint8_t data[2] ={0,0}; //data //you can change it with EEPROM or RTC data;

void loop() {

    if(button1.read()){       //Button 1 read
      menuIn++;               //menuIn increase
      menu(menuIn);           //to menu function
      if(menuIn >2){          //reset to zero //menu length
        menuIn=0;
      }
    }
Serial.print("RUNNING MODE :"); //indicator of data
Serial.print(data[0]);
Serial.print("X");
Serial.println(data[1]);

}

void menu(uint8_t ke){    //to set  send data to menu involved
  if(ke ==1){
    pemilihan(0);
  }else if(ke ==2){
    pemilihan(1);
  }
}
void pemilihan(uint8_t ke){ //select fungtion
 pilih =0;
 while(1){
Serial.print("EDIT MODE "+(String)menuIn + " :\t");
Serial.print(data[0]);
Serial.print(" X ");
Serial.println(data[1]);
 if(button2.read()){
    pilih++;
    data[ke] = pilih;
 }
 if(pilih >= luasdata){
    pilih =0; 
  }
 if(button1.read()){
    menuIn++;
    menu(menuIn);
    return 0;

 }
 }
}
