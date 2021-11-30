void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);
}
char isi;
String kalimat;
void loop() {
if(Serial.available() >0){
  isi = Serial.read();
 if(isi !='='){
 kalimat += isi; 
 }
  if(isi=='='){
               Serial.println(kalimat);
        if(kalimat=="assiap"){
      Serial.println("Benar");
      digitalWrite(13,1);
      delay(3000);
            digitalWrite(13,0);
    }else{
      Serial.println("Salah");
      kalimat = "";}

    }

}

}
