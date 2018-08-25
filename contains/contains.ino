void setup() {
 
Serial.begin(9600);
}

void loop() {

  Serial.println(contains("khaled is a whore","is"));

}
bool contains(String cmd,String resp){

bool tag=true;
int cmd_length=cmd.length();
int resp_length=resp.length();
char cmd_buff[cmd_length];
char resp_buff[resp_length];
byte i=0;
while(cmd.charAt(i)!='\0'){
 cmd_buff[i]=cmd.charAt(i);
 i++;
}
i=0;
while(resp.charAt(i)!='\0'){
 resp_buff[i]=resp.charAt(i);
 i++;
}
i=0;
int index=cmd.indexOf(resp);
int end_of_me=cmd_length-index;
//while(resp.charAt(i)!='\0'){
//  if(resp.charAt(i)==cmd.charAt(index) && resp.charAt(i+1)==cmd.charAt(index+1)&& 
//  resp.charAt(i+2)==cmd.charAt(index+2) &&
//  resp.charAt(i+3)==cmd.charAt(index+3)
//  
//  )return true;
//  else return false;
while(resp.charAt(i)!='\0'){
if(resp.charAt(i)!=cmd.charAt(index)){
  tag=false;
   break;
}  
else {
  i++;
  index++;
}

}
return tag;
 
}
