void setup() {
  Serial.begin(9600);
pinMode(3,OUTPUT); // pin 2 sebagai output

}
void loop() {
digitalWrite(3,HIGH); //2 = pin ,HIGH/1 = 5 VOLT 
delay(100); //Jeda 100ms atau 0,1 detik
digitalWrite(3,LOW); // 2 = pin, LOW/0 = 0 VOLT 
delay(100); //jeda 100ms atau 0,1 detik

}
