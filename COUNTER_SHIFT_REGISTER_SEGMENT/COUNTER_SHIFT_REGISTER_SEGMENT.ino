/* 
 by djamaatul anbiya
 31 agustus 2020
*/
const byte pdata   =  2;
const byte platch  =  3;
const byte pclock  =  4;
const byte dg[]    = {8,9,10,11};
/*            BIT ANGKA            */
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
  
unsigned long waktu;
unsigned long batas;
byte satuan ;
byte puluhan;
byte ratusan;
byte ribuan;

void setup(){
  waktu =millis();
  Serial.begin(9600);
  for(byte i = 0;i <=3;i++)
  {
    pinMode(dg[i],OUTPUT);
  }
    pinMode(pdata,OUTPUT);
    pinMode(platch,OUTPUT);
    pinMode(pclock,OUTPUT);
}

void loop() {
  if(jeda(1000)) //nilai jeda 100=  100millidetik / 0,1 detik
   {
     satuan++; //menambah nilai satuan setiap jeda diatas 
    if(satuan >=10){
      puluhan ++; //menambah nilai puluhan setiap satuan >= 10
      if(puluhan >=10){
        ratusan++; //menambah nilai ratusan setiap puluhan >= 10
        if(ratusan >=10){
          ribuan++; //menambah nilai ribuan setiap ratusan >= 10
          if(ribuan >=10){
            ribuan =0; //reset ribuan ke 0 saat >=10
          }
          ratusan=0;  //reset ratusan ke 0 saat >=10
        }
        puluhan=0;  //reset puluhan ke 0 saat >=10
        }
      satuan=0; //reset satuan ke 0 saat >=10
    }
  }
  digit(0); //digit 4
  tf(satuan);//kirim  angka satuan  ke shift register
  
  digclear(); //off semua digit
  
  digit(3); //digit 3
  tf(puluhan); //kirim angka puluhan ke shift register
  
  digclear(); //off semua digit
  
  digit(2); //digit 2
  tf(ratusan); //kirim  angka ratusan  ke shift register
  
  digclear(); //off semua digit
  
  digit(1); //digit 1
  tf(ribuan); //kirim  angka ribuan  ke shift register
}

/*            FUUNGSI TRANSFER                          */
void tf(byte dat){
  digitalWrite(platch,0);
  shiftOut(pdata,pclock,LSBFIRST,angka[dat]);
  digitalWrite(platch,1);  
 
}
/*            FUUNGSI PILIH DIGIT                      */
void digit(byte pilih){
  for(int x = 0;x<=3;x++){
    if(x ==pilih){
      digitalWrite(dg[x],1);
      }
      else if (x != pilih){
      digitalWrite(dg[x],0);
      }
 }
 delay(1);
}
/*            FUUNGSI OFF SEMUA DIGIT                */
void digclear(){
   for(int x = 0;x<=3;x++){
   digitalWrite(dg[x],0);
   }
}
/*            FUUNGSI DELAY DENGAN MILLIS            */
bool jeda(int sampai){
  waktu=millis();
  if(waktu - batas > sampai){
     batas=waktu;
     return 1;
     }
  return 0;
}
