#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1);
Servo myservo;
int x = 0;
int pos = 0;
int posr = 12;
int negr = 7;
int posl = 13;
int negl = 8;
int trigpin = 5;
int echopin = 6;
String command;
int dur, distance;

void setup() 
{
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(posr, OUTPUT);
  pinMode(negr, OUTPUT);
  pinMode(posl, OUTPUT);
  pinMode(negl, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  myservo.attach(10);
  x=0;
}

void loop() 
{
  while (BT.available())
  { 
    delay (10);
    char t = BT.read();
    command += t;
  }
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  dur = pulseIn(echopin, HIGH);
  distance = (dur / 2) / 29.1;
  //Serial.print(distance + "\n");
  if (distance < 6 and x == 1)
  {
    digitalWrite(posr, LOW);
    digitalWrite(negr, LOW);
    digitalWrite(posl, LOW);
    digitalWrite(negl, LOW);
    delay(5);
  }
  if (command.length() > 0)
  {
    //Serial.println(command);
    delay(1000);

    if (command == "forward")
    {
      digitalWrite(posr, HIGH);
      digitalWrite(negr, LOW);
      digitalWrite(posl, HIGH);
      digitalWrite(negl, LOW);
      x = 1;
    }
    else if (command == "backward")
    {
      digitalWrite(posr, LOW);
      digitalWrite(negr, HIGH);
      digitalWrite(posl, LOW);
      digitalWrite(negl, HIGH);
      x=2;
    }
    else if (command == "right")
    { 
      digitalWrite(posr, LOW);
      digitalWrite(negr, HIGH);
      digitalWrite(posl, HIGH);
      digitalWrite(negl, LOW);
      x=3;
      
    }

    else if (command == "left")
    { 
      digitalWrite(posr, HIGH);
      digitalWrite(negr, LOW);
      digitalWrite(posl, LOW);
      digitalWrite(negl, HIGH);
      x=4;
    }

    else if (command == "stop")
    { 
      digitalWrite(posr, LOW);
      digitalWrite(negr, LOW);
      digitalWrite(posl, LOW);
      digitalWrite(negl, LOW);
    }
    command = ""; //reset the variable
  }
}
