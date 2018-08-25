void split(String NMEA,char splitChar,String data[],byte dataSize){
  long j=0;
  //check variable 
  long k=0;
  for(byte a=0;a<dataSize;a++)data[a]="";
  for(byte i=0;j<NMEA.length();i++){ 
        while(NMEA.charAt(j)!=splitChar){
            if(k>3)break;
            if(NMEA.charAt(j)=='\0')k++;
            data[i].concat(NMEA.charAt(j));                     
            j++;                      
         }
        j++;               
  }  
}
bool contains(String cmd,String resp){

byte i=0;
int index=cmd.indexOf(resp);

if (index >=0 ) return true;
if (index == -1) return false;
}

