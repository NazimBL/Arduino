
int positive[3]={5,6,7};
int negative[3]={13,12,11};
boolean state[3][3]={0,1,1,
                     1,0,1,
                     1,1,0};
void setup() {
  
for(int i=0;i<3;i++){
  pinMode(positive[i],OUTPUT);
  pinMode(negative[i],OUTPUT);
  digitalWrite(positive[i],0);
  digitalWrite(negative[i],0);
}


}

void loop() {
 
 
for(int i=0;i<3;i++){
  
  digitalWrite(positive[i],1);
  for(int j=0;j<3;j++){
    digitalWrite(negative[0],state[j][0]);
     digitalWrite(negative[1],state[j][1]);
      digitalWrite(negative[2],state[j][2]);
    delay(500);
  }

  for(int i=0;i<3;i++){
  digitalWrite(positive[i],0);
  digitalWrite(negative[i],0);
}
  }


}
