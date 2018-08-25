char reception='v';
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:


  int heart=analogRead(A0);
  int saturation=analogRead(A1);
  
  if(Serial.available()){
    
    reception=(char)Serial.read();
    //Serial.println(reception);
    
    if(reception=='1'){
      int hearBeat=50;
      
      Serial.write(hearBeat);
     
      }else if(reception=='2'){
        int saturation=75;
      
      Serial.write(saturation);
        
        }
       
    }

}



