int rows[3]={5,6,7};
int columns[3]={13,12,11};
byte sequence[9]={1,0,1,1,1,1,1,0,1};

void setup() {
for(int i=0;i<3;i++){

  pinMode(rows[i],OUTPUT);
  pinMode(columns[i],OUTPUT);
  digitalWrite(rows[i],0);
  digitalWrite(columns[i],1);
}
 
}

void loop() {

 //max visible blink = 10 ( delay )

for(byte i=0;i<9;i++){
  
  if(sequence[i]==1){

      digitalWrite(rows[i/3],1);
  digitalWrite(columns[i%3],0);
delay(2);
  digitalWrite(rows[i/3],0);
  digitalWrite(columns[i%3],1);
 
  }
   
  }

}
