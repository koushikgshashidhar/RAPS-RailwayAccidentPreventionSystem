#include <Servo.h>

#define echoPin 11
#define trigPin 12

#define echoPin2 5
#define trigPin2 6

#define led 2
#define led2 8


long duration,duration2,distance,distance2;
int angle=0;
const int buzzer=10;

Servo myservo;
Servo myservo2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  
  myservo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,LOW);
  digitalWrite(led2,LOW);


  
  digitalWrite(trigPin,LOW);
  digitalWrite(trigPin2,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);

  // sensor 2

 // digitalWrite(trigPin2,LOW);
  //delayMicroseconds(2);

  //digitalWrite(trigPin2,HIGH);
  //delayMicroseconds(10);

  //digitalWrite(trigPin2,LOW);
  
  duration=pulseIn(echoPin,HIGH);
  distance=duration/58.2;
  Serial.println(distance);
  //delay(50);


  duration2=pulseIn(echoPin2,HIGH);
  distance2=duration2/58.2;
  Serial.println(distance2);
  //delay(50);


  if((distance>=10 && distance<=30) or (distance2>=10 && distance2<=30))            //change this to  distance  or  distance2 >=20 then we can get o/p if we change direction of train also.....
  {
    tone(buzzer,10);
    digitalWrite(led,HIGH);
    
    //digitalWrite(led,LOW);
    digitalWrite(led2,LOW);
    
    //delay(2000);
    //noTone(buzzer);
    for(angle=0;angle<100;angle+=1)
    {
      myservo.write(angle);
      delay(50);
    }
    delay(3000);
    //exit (0);
    
  }

  if((distance>=10 && distance<=20) or (distance2>=10 && distance2<=20))
  
  {
    //tone(buzzer,10);
    //delay(2000);
      noTone(buzzer);
      
      digitalWrite(led2,HIGH);
      
      //digitalWrite(led2,LOW);
      digitalWrite(led,LOW);
    
      for(angle=100;angle>1;angle-=1)
      {
        myservo.write(angle);
        delay(20);
      
      }
      delay(3000);
      
  }

}
