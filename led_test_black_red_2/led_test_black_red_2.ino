 
 #define SENSOR_D2 A0// Pins of reflectance sensor
 #define led 8
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(led,OUTPUT);
digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val =read_sensors();
  Serial.println(val);
  if (val==1)
  {
    digitalWrite(led,HIGH); 
    }
    else
    {
        digitalWrite(led,LOW);
    }

}
int read_sensors()
{
  //Read Sensor of Right
  int sensors = 0;  
int samir= analogRead(SENSOR_D2);
int valu=map(samir,0,1023,0,3800);
if (samir<1000)
    sensors += 1;
    return  sensors;
   }
