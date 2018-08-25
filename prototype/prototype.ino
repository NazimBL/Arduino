
int rows[3]={5,6,7};
int cols[3]={11,12,13};
int x=0,y=1;

void setup() {
for (int i=0;i<3;i++){
  pinMode(rows[i],OUTPUT);
  pinMode(cols[i],OUTPUT);
  digitalWrite(rows[i],0);
  digitalWrite(cols[i],1);
}
  Serial.begin(9600);

}

void loop() {
  
 digitalWrite(rows[x],1);
  digitalWrite(cols[y],0);

if(Serial.available()){
  
  char c=Serial.read();
  
  if(c=='m'){
    zero();
     y++;
     if(y>2) y=0;
    
    }
    else if(c=='k'){
       zero();
     y--;
     if(y<0) y=2;
      }
      else if(c=='o'){
          zero();
     x++;
     if(x>2) x=0;
      }
       else if(c=='l'){
       zero();
     x--;
     if(x<0) x=2;
      }
      
  }


}
void zero(){
 for (int i=0;i<3;i++){
 
  digitalWrite(rows[i],0);
  digitalWrite(cols[i],1);
} 
  
  }


