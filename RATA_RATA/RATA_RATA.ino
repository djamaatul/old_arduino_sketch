class rata{   //my average class
  public:
    uint16_t data;
    uint8_t pada;
    uint16_t jumlah;
    uint16_t is;
  rata(uint16_t data,uint8_t pada){
    this->data = data;
    this->pada = pada;
  }
uint16_t terata(){ //how to use *name.rerata(VariableData,lengthAverage);
  jumlah = 0;
  for(uint8_t i =0;i <=pada ;i++){
     jumlah += data;
  }

  is = jumlah/pada;
  return is;
}
  
};
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
