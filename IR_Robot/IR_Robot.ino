#include<AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
int a=32; //declaration du capteur droit IR
int b=36; //declaration du capteur gauche IR
bool gauche=0,droite=0;
int trig=24; //declaration du trigger
int echo=25; //declaration du echo
long cm;
long lecture_echo; //declaration de lecture echo
int ledd=26;// declaration de led droit
int ledg=27;//declaration de led gauche

void setup() {
  // put your setup code here, to run once:
pinMode(a,INPUT_PULLUP);
pinMode(b,INPUT_PULLUP);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(trig,HIGH);
pinMode(ledd,OUTPUT);
pinMode(ledg,OUTPUT);
Serial.begin(9600);
}

 // put your main code here, to run repeatedly:
robot();
digitalWrite(ledd,1);
digitalWrite(ledg,1);
gauche=digitalRead(b);
droite=digitalRead(a);
Serial.println(gauche);
Serial.println(droite);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
lecture_echo= pulseIn(echo,HIGH);
cm=lecture_echo/29/2;
Serial.println("distancecm:");
Serial.println(cm);
}
void robot(){
  motor1.run(FORWARD);
motor1.setSpeed(255);
motor2.run(FORWARD);
motor2.setSpeed(255);
if((gauche==1)&&(droite==1))
{motor1.run(FORWARD);
motor1.setSpeed(255);
motor2.run(FORWARD);
motor2.setSpeed(255);
  }
if((gauche==0)&&(droite==1))
{motor1.run(FORWARD);
motor1.setSpeed(150);
motor2.run(FORWARD);
motor2.setSpeed(255);
  }
if((gauche==1)&&(droite==0))
{motor1.run(FORWARD);
motor1.setSpeed(255);
motor2.run(FORWARD);
motor2.setSpeed(150);
  }
 if((gauche==0)&&(droite==0))
 {motor1.run(RELEASE);
  motor2.run(RELEASE);
}
if((gauche==1)&&(droite==1)&&(cm<10))
{motor1.run(RELEASE);
motor2.run(RELEASE);
digitalWrite(ledd,LOW);
digitalWrite(ledg,LOW);
}
}