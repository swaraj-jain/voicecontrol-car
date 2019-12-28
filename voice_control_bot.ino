#include <Servo.h>
Servo myservo;
int pos = 0; 
int posr=4;
int negr=5;
int posl=6;
int negl=7;
int trigpin=8;
int echopin=9;
String command;
int dur,distance;

void setup() {
    Serial.begin(9600);
    pinMode(posr,OUTPUT);
    pinMode(negr,OUTPUT);
    pinMode(posl,OUTPUT);
    pinMode(negl,OUTPUT);
    pinMode(trigpin,OUTPUT);
    pinMode(echopin,INPUT);
    myservo.attach(10);
    

}

void loop() {
 while(Serial.available()==0)
 {//wait till get any input}
  command=Serial.read();
  Serial.println(command);
  delay(1000);
  if(command=="forward")
  {  digitalWrite(trigpin,LOW);
   delayMicroseconds(2);
   digitalWrite(trigpin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigpin,LOW);
   dur=pulseIn(echopin,HIGH);
   distance=(dur/2)/29.1;
   Serial.print(distance);
   if(distance>12)
   {digitalWrite(posr,HIGH);
   digitalWrite(negr,LOW);
   digitalWrite(posl,HIGH);
   digitalWrite(negl,LOW);}
  }
  else if(command=="backward")
  { for(pos=0;pos<=180;pos++)
      {myservo.write(pos);}  
     digitalWrite(trigpin,LOW);
     delayMicroseconds(2);
     digitalWrite(trigpin,HIGH);
     delayMicroseconds(10);
     digitalWrite(trigpin,LOW);
     dur=pulseIn(echopin,HIGH);
     distance=(dur/2)/29.1;
     Serial.print(distance);
     for(pos=180;pos>=0;pos--)
      {myservo.write(pos);}  
     if(distance>20)
    {digitalWrite(posr,LOW);
    digitalWrite(negr,HIGH);
    digitalWrite(posl,LOW);
    digitalWrite(negl,HIGH);
    }
    else
    {digitalWrite(posr,LOW);
    digitalWrite(negr,LOW);
    digitalWrite(posl,LOW);
    digitalWrite(negl,LOW);}
  }
   else if(command=="right")
  { for(pos=0;pos>=-90;pos--)
     {myservo.write(pos);}
     digitalWrite(trigpin,LOW);
     delayMicroseconds(2);
     digitalWrite(trigpin,HIGH);
     delayMicroseconds(10);
     digitalWrite(trigpin,LOW);
     dur=pulseIn(echopin,HIGH);
     distance=(dur/2)/29.1;
     Serial.print(distance);
     for(pos=-90;pos<=0;pos++)
     {myservo.write(pos);}
     if(distance>12)
    {digitalWrite(posr,LOW);
    digitalWrite(negr,LOW);
    digitalWrite(posl,HIGH);
    digitalWrite(negl,LOW);}
    else
    {digitalWrite(posr,LOW);
    digitalWrite(negr,LOW);
    digitalWrite(posl,LOW);
    digitalWrite(negl,LOW);}
   
  }
   else if(command=="left")
   {for(pos=0;pos>=90;pos++)
     {myservo.write(pos);}
     digitalWrite(trigpin,LOW);
     delayMicroseconds(2);
     digitalWrite(trigpin,HIGH);
     delayMicroseconds(10);
     digitalWrite(trigpin,LOW);
     dur=pulseIn(echopin,HIGH);
     distance=(dur/2)/29.1;
     Serial.print(distance);
     for(pos=90;pos>=0;pos--)
     {myservo.write(pos);}
     if(distance>12)
   {digitalWrite(posr,HIGH);
   digitalWrite(negr,LOW);
   digitalWrite(posl,LOW);
   digitalWrite(negl,LOW);}
   else
    {digitalWrite(posr,LOW);
    digitalWrite(negr,LOW);
    digitalWrite(posl,LOW);
    digitalWrite(negl,LOW);}
   }
    else if(command=="stop") 
  {digitalWrite(posr,LOW);
   digitalWrite(negr,LOW);
   digitalWrite(posl,LOW);
   digitalWrite(negl,LOW);
  }
   else 
  {digitalWrite(posr,LOW);
   digitalWrite(negr,LOW);
   digitalWrite(posl,LOW);
   digitalWrite(negl,LOW);
  }
  
  
}
}
