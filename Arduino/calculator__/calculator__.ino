char angka[3];
int di = 0;
void setup() {
Serial.begin(9600);
}

void loop() {
String input;
  if(Serial.available()>0){
    input = Serial.readString();
    angka[di] = input.toInt();
    if(di==0){
      Serial.print(input+"+");
    }else{
      Serial.print(input+"=");
    }
    di++;
  }
  if(di==2){
    Serial.println(angka[0]+angka[1]);
    di = 0;
  }
}
