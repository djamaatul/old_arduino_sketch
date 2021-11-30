int x[]={0,2,3,4,6,7};
int y[]={0,8,10,11,12,13,A0,A1};
int xx,yy
,xl,yl;
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
   for(int a = 1; a<=xl; a++){
      for(int b = 1; b<=yl; b++){
        except(a,x,0,xl);
        except(b,y,1,yl);
      }
      for(int b = yl; b>=1; b--){
        except(a,x,0,xl);
        except(b,y,1,yl);
      }
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
