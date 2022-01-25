#include <Servo.h>

#define echoPin 11 //SENSOR1 PIN 11
#define trigPin 12 //SENSOR1 PIN 12

#define echoPin2 5 //SENSOR2 PIN 5
#define trigPin2 6 //SENSOR3 PIN 6

#define led 2   //LED RED
#define led2 8 //LED GREEN


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
 C: digitalWrite(led,HIGH);
    digitalWrite(led2,LOW);


  
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);

  
    duration=pulseIn(echoPin,HIGH);
    distance=duration/58.2;
    Serial.print("distance:");
    Serial.println(distance);
    delay(50);

    digitalWrite(trigPin2,LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin2,HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin2,LOW);

    duration2=pulseIn(echoPin2,HIGH);
    distance2=duration2/58.2;
    Serial.print("distance2:");
    Serial.println(distance2);
    delay(50);


    if((distance>=0 && distance<=25))            //change this to  distance  or  distance2 >=20 then we can get o/p if we change direction of train also.....
    {
      tone(buzzer,10);
      digitalWrite(led2,HIGH);
    
      digitalWrite(led,LOW);
    
   
      for(angle=90;angle<180;angle+=1)
      {
        myservo.write(angle);
        delay(20);
      }
      delay(200);
A:    digitalWrite(trigPin2,LOW);
      delayMicroseconds(2);

      digitalWrite(trigPin2,HIGH);
      delayMicroseconds(10);

      digitalWrite(trigPin2,LOW);

      duration2=pulseIn(echoPin2,HIGH);
      distance2=duration2/58.2;
      Serial.print("distance2:");
      Serial.println(distance2);
      delay(50);
      if(distance2>=0 && distance2<=25)
        {
          
          noTone(buzzer);
      
          digitalWrite(led,HIGH);
          digitalWrite(led2,LOW);
    
          for(angle=180;angle>90;angle-=1)
          {
            myservo.write(angle);
            delay(20);
          }
          delay(2000);
          goto C;
       }
      goto A;
      }

      if((distance2>=0 && distance2<=25))
      {
        tone(buzzer,10);
    
        digitalWrite(led,LOW);
        digitalWrite(led2,HIGH);
    
    for(angle=90;angle<180;angle+=1)
    {
      myservo.write(angle);
      delay(20);
    }
   delay(200);
 B: digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration=pulseIn(echoPin,HIGH);
    distance=duration/58.2;
    Serial.print("distance:");
    Serial.println(distance);
    delay(50);
    if(distance>=0 && distance<=25)
    {
        
      noTone(buzzer);
      
      digitalWrite(led,HIGH);
      digitalWrite(led2,LOW);
    
      for(angle=180;angle>90;angle-=1)
      {
        myservo.write(angle);
        delay(20);
      }
      
      delay(2000);
        goto C;
    }   
        goto B;
     
  }

}
