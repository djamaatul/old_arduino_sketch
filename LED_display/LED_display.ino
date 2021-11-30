int x[5]={2,3,4,6,7};
int y[7]={8,10,11,12,13,A0,A1};
int kx;
int rx;
int ky;
int ry;
void setup() {
  Serial.begin(9600);
for(int i=0;i<=4;i++){
  pinMode(x[i],OUTPUT);
}
for(int b=0;b<=6;b++){
  pinMode(y[b],OUTPUT);
}
}
void xy1(bool a,bool b,bool c,bool d,bool e){

   digitalWrite(y[0],0);
      digitalWrite(y[1],1);
         digitalWrite(y[2],1);
            digitalWrite(y[3],1);
               digitalWrite(y[4],1);
                  digitalWrite(y[5],1);
                     digitalWrite(y[6],1);
 digitalWrite(x[0],a);
  digitalWrite(x[1],b);
   digitalWrite(x[2],c);
    digitalWrite(x[3],d);
     digitalWrite(x[4],e);
}
void xy2(bool e,bool q,bool r,bool s,bool t){
   digitalWrite(y[0],1);
      digitalWrite(y[1],0);
         digitalWrite(y[2],1);
            digitalWrite(y[3],1);
               digitalWrite(y[4],1);
                  digitalWrite(y[5],1);
                     digitalWrite(y[6],1);
 digitalWrite(x[0],e);
  digitalWrite(x[1],q);
   digitalWrite(x[2],r);
    digitalWrite(x[3],s);
     digitalWrite(x[4],t);
}
void xy3(bool a,bool b,bool c,bool d,bool e){
   digitalWrite(y[0],1);
      digitalWrite(y[1],1);
         digitalWrite(y[2],0);
            digitalWrite(y[3],1);
               digitalWrite(y[4],1);
                  digitalWrite(y[5],1);
                     digitalWrite(y[6],1);
 digitalWrite(x[0],a);
  digitalWrite(x[1],b);
   digitalWrite(x[2],c);
    digitalWrite(x[3],d);
     digitalWrite(x[4],e);
}
void xy4(bool a,bool b,bool c,bool d,bool e){
   digitalWrite(y[0],1);
      digitalWrite(y[1],1);
         digitalWrite(y[2],1);
            digitalWrite(y[3],0);
               digitalWrite(y[4],1);
                  digitalWrite(y[5],1);
                     digitalWrite(y[6],1);
 digitalWrite(x[0],a);
  digitalWrite(x[1],b);
   digitalWrite(x[2],c);
    digitalWrite(x[3],d);
     digitalWrite(x[4],e);
}
void xy5(bool a,bool b,bool c,bool d,bool e){
   digitalWrite(y[0],1);
      digitalWrite(y[1],1);
         digitalWrite(y[2],1);
            digitalWrite(y[3],1);
               digitalWrite(y[4],0);
                  digitalWrite(y[5],1);
                     digitalWrite(y[6],1);
 digitalWrite(x[0],a);
  digitalWrite(x[1],b);
   digitalWrite(x[2],c);
    digitalWrite(x[3],d);
     digitalWrite(x[4],e);
}
void xy6(bool a,bool b,bool c,bool d,bool e){
   digitalWrite(y[0],1);
      digitalWrite(y[1],1);
         digitalWrite(y[2],1);
            digitalWrite(y[3],1);
               digitalWrite(y[4],1);
                  digitalWrite(y[5],0);
                     digitalWrite(y[6],1);
 digitalWrite(x[0],a);
  digitalWrite(x[1],b);
   digitalWrite(x[2],c);
    digitalWrite(x[3],d);
     digitalWrite(x[4],e);
}
void xy7(bool a,bool b,bool c,bool d,bool e){
   digitalWrite(y[0],1);
      digitalWrite(y[1],1);
         digitalWrite(y[2],1);
            digitalWrite(y[3],1);
               digitalWrite(y[4],1);
                  digitalWrite(y[5],1);
                     digitalWrite(y[6],0);
 digitalWrite(x[0],a);
  digitalWrite(x[1],b);
   digitalWrite(x[2],c);
    digitalWrite(x[3],d);
     digitalWrite(x[4],e);
}
void loop() {

digitalWrite(x[0],1);
digitalWrite(x[1],0);
digitalWrite(x[2],0);
digitalWrite(x[3],0);
digitalWrite(x[4],0);
for(int o=1;o<=6;o++){
  digitalWrite(y[1],1); 
digitalWrite(y[o],0);  
delay(20);
digitalWrite(y[o],1);  
}
digitalWrite(y[0],1);
digitalWrite(y[1],1);
digitalWrite(y[2],1);
digitalWrite(y[3],1);
digitalWrite(y[4],1);
digitalWrite(y[5],1);
digitalWrite(y[6],0);
for(int o=0;o<=4;o++){
digitalWrite(x[o],1);  
delay(20);
digitalWrite(x[o],0);  
}
digitalWrite(x[0],0);
digitalWrite(x[1],0);
digitalWrite(x[2],0);
digitalWrite(x[3],0);
digitalWrite(x[4],1);
for(int o=6;o>=0;o--){
digitalWrite(y[o],0);  
delay(20);
digitalWrite(y[o],1);  
}
digitalWrite(y[0],0);
digitalWrite(y[1],1);
digitalWrite(y[2],1);
digitalWrite(y[3],1);
digitalWrite(y[4],1);
digitalWrite(y[5],1);
digitalWrite(y[6],1);
for(int o=4;o>=1;o--){
digitalWrite(x[o],1);  
delay(20);
digitalWrite(x[o],0);  
}
digitalWrite(x[0],0);
digitalWrite(x[1],1);
digitalWrite(x[2],0);
digitalWrite(x[3],0);
digitalWrite(x[4],0);
for(int o=1;o<=5;o++){
  digitalWrite(y[0],1);  
digitalWrite(y[o],0);  
delay(20);
digitalWrite(y[o],1);  
}
digitalWrite(y[0],1);
digitalWrite(y[1],1);
digitalWrite(y[2],1);
digitalWrite(y[3],1);
digitalWrite(y[4],1);
digitalWrite(y[5],0);
digitalWrite(y[6],1);
for(int o=1;o<=3;o++){
  digitalWrite(x[1],0); 
digitalWrite(x[o],1);  
delay(20);
digitalWrite(x[o],0);  
}
digitalWrite(x[0],0);
digitalWrite(x[1],0);
digitalWrite(x[2],0);
digitalWrite(x[3],1);
digitalWrite(x[4],0);
for(int o=5;o>=1;o--){
    digitalWrite(y[1],1);   
digitalWrite(y[o],0);  
delay(20);
digitalWrite(y[o],1);  
}
digitalWrite(y[0],0);
digitalWrite(y[1],1);
digitalWrite(y[2],1);
digitalWrite(y[3],1);
digitalWrite(y[4],1);
digitalWrite(y[5],1);
digitalWrite(y[6],1);
for(int o=3;o>=1;o--){
  digitalWrite(x[0],0); 
digitalWrite(x[o],1);  
delay(20);
digitalWrite(x[o],0);  
}

}
