void setup() {
for(int i = 8;i <=11;i++){
  pinMode(i,OUTPUT);
}
for(int i = 8;i <=11;i++){
  digitalWrite(i,0);
}
}

void loop() {

  digitalWrite(8,1);
  delay(100);
  digitalWrite(8,0);


}
