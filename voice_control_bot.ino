int posr=4;
int negr=5;
int posl=6;
int negl=7;
String command;

void setup() {
    Serial.begin(9600);
    pinMode(posr,OUTPUT);
    pinMode(negr,OUTPUT);
    pinMode(posl,OUTPUT);
    pinMode(negl,OUTPUT);

}

void loop() {
 while(Serial.available()==0)
 {//wait till get any input}
  command=Serial.read();
  Serial.println(command);
  delay(1000);
  if(command=="forward")
  {digitalWrite(posr,HIGH);
   digitalWrite(negr,LOW);
   digitalWrite(posl,HIGH);
   digitalWrite(negl,LOW);
  }
  else if(command=="backward")
  {digitalWrite(posr,LOW);
   digitalWrite(negr,HIGH);
   digitalWrite(posl,LOW);
   digitalWrite(negl,HIGH);
  }
   else if(command=="right")
  {digitalWrite(posr,LOW);
   digitalWrite(negr,LOW);
   digitalWrite(posl,HIGH);
   digitalWrite(negl,LOW);
  }
   else if(command=="left")
  {digitalWrite(posr,HIGH);
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
