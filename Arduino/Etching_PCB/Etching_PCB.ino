#define s1 3
#define s2 4
#define m1 5
#define m2 6         
bool k1,k2;
void setup() {
  Serial.begin(9600);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(s1,INPUT_PULLUP);
  pinMode(s2,INPUT_PULLUP);
    pinMode(2,OUTPUT);
    digitalWrite(2,1);
k1=1;
k2=1;
maju();
}
byte  pinsp = 9;
void loop() {
  digitalWrite(pinsp,1);
Serial.print(digitalRead(s1));
Serial.print(" ");
Serial.println(digitalRead(s2));
maju();
delay(500);
mundur();
delay(500);

//if(!k1){
//  maju();
//  Serial.println("maju");
//}else if(!k2){
//  mundur();
//    Serial.println("mundur");
//}
//
//if((digitalRead(s1) == 0 || k1 == 1) && digitalRead(s2)==1){
//  k1 = 1;
//  k2 = 0; 
//}else if((digitalRead(s1) == 1 || k2 == 1) && digitalRead(s2)==0)
//   k1 = 0;
//  k2 = 1; 
}
void maju(){
digitalWrite(m1,0);
digitalWrite(m2,1);
}
void mundur(){
digitalWrite(m1,1);
digitalWrite(m2,0);
}
