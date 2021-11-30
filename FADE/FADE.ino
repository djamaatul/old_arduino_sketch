void setup() {
  Serial.begin(9600);
pinMode(3,OUTPUT); // pin 2 sebagai output

}
void loop() {
 
for(int i=0;i<=224;i++){
analogWrite(3,i);
delay(10);
}
for(int e=224;e>=0;e--){
analogWrite(3,e);
delay(10);
}
}
