void setup() {
Serial.begin(9600);
pinMode(10,INPUT);
pinMode(3,INPUT);
}

void loop() {
if(digitalRead(10)==1){
  Serial.print("2");  
}
if(digitalRead(3)==1){
  Serial.println("3");  
}

}
