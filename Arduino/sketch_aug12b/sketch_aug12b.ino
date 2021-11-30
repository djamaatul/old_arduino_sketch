int x[]={0,2,3,4,6,7};
int y[]={0,8,10,11,12,13,A0,A1};
unsigned long ms1;
int interval = 1000;
int a,b = 1;
void setup() {
  ms1 = millis();
  for(int i=1;i<=6;i++){
    pinMode(x[i],OUTPUT);
    digitalWrite(y[i],1);
  }
  for(int i=1;i<=8;i++){
    pinMode(y[i],OUTPUT);
    digitalWrite(y[i],0);
  }
  Serial.begin(9600);
}

void loop() {
  int x1[] = {1,2,3,4,5};
  int y1[] = {1,2,3,4,5,6,7};
  karakter(x1,x,5,0,5,0);
  karakter(y1,y,7,1,7,0);
//  long ms = millis();
//  if(ms-ms1>=interval){
//    ms1 = millis();
//  }
}

void reset(int arr[],int len,bool y){
  for(int i = 0; i<=len; i++){
    digitalWrite(arr[i],!y);
  }
}

void karakter(int aktif[],int arr, int arr_len,bool y, int len,bool reve){
  for(int i = 0; i<len; i++){
    int io = aktif[i];
    if(reve){
      io = aktif[len-i];
    }
    except(io,arr,y,arr_len);
  }
}

void except(int search,int arr[],bool y, int len){
  //int i = sizeof(arr)/sizeof(arr[0]);
  int o = len;
  for(int i = 0; i<=o; i++){
    if(i==search){
      digitalWrite(arr[i],!y);
    }else{
      digitalWrite(arr[i],y);
      delay(100);
    }
  }
}
