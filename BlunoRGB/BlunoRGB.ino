int R = 9, G =3, B = 10;
int Num[3] = {0};
int Rvalue = 0,Gvalue = 0,Bvalue = 0;
String comdata = "";
void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  Num[0] = Num[1] = Num[2] = 0;
  while(Serial.available()>0){
    comdata += char(Serial.read());
    delay(2);
  }
  int j = 0;
  if(comdata.length() > 0){/*<RGBLED>123,20,40;*/
    char *p = (char *)comdata.c_str();
    if(strncmp(p,"<RGBLED>",8) == 0){
      //Serial.println(comdata);
      for(int i = 8;i<comdata.length();i++){
        if(comdata[i] == ','){
          j++;
        }else if(comdata[i] == ';'){
          break;
        }else{
          Num[j] = Num[j]*10 +(comdata[i]-'0');
        }
      }
        Rvalue = Num[0];
        Gvalue = Num[1];
        Bvalue = Num[2];
    }
  }
 comdata = "";
  analogWrite(R, Rvalue);
  analogWrite(G,Gvalue);
  analogWrite(B,Bvalue);
}
