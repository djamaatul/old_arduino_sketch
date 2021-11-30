int x[]={0,2,3,4,6,7};
int y[]={0,8,10,11,12,13,A0,A1};
int xx,yy,xl,yl;
void setup() {
  for(int i=1;i<=6;i++){
    pinMode(x[i],OUTPUT);
    digitalWrite(y[i],0);
  }
  for(int i=1;i<=8;i++){
    pinMode(y[i],OUTPUT);
    digitalWrite(y[i],0);
  }
  Serial.begin(9600);
  xl = sizeof(x)/sizeof(x[0]);
  yl = sizeof(y)/sizeof(y[0]);
}

void loop() {
  int x1[] = {1,2,3,4,5};
  int y1[] = {1,2,3,4,5};
  karakter(x1,x,5,0,5,0);
  reset(x,5,0);
  karakter(y1,y,7,1,5,0);
  reset(x,5,1);
  reset(y,7,1);
  delay(500);
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
      delay(10);
    }
  }
}
