#include <Servo.h>

#define echoPin 11 //SENSOR1 PIN 11
#define trigPin 12 //SENSOR1 PIN 12

#define echoPin2 5 //SENSOR2 PIN 5
#define trigPin2 6 //SENSOR2 PIN 6

#define led 2   //LED RED
#define led2 8 //LED GREEN

#define echoPin3 9 // sensor3  pin 9
#define trigPin3 10 // sensor3  pin 10

long duration,duration2,duration3,distance,distance2,distance3;
int angle=0;

const int buzzer = 4; //Define pin 4 for buzzer

Servo myservo;


void setup(){
    // put your setup code here, to run once:
    Serial.begin(1000000);
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);

    pinMode(trigPin2,OUTPUT);
    pinMode(echoPin2,INPUT);
  
    pinMode(trigPin3,OUTPUT);
    pinMode(echoPin3,INPUT);
  
    pinMode(buzzer,OUTPUT);
    pinMode(led,OUTPUT);
    pinMode(led2,OUTPUT);
  
    myservo.attach(7);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
 C:     //led initialization
        digitalWrite(led,HIGH);
        digitalWrite(led2,LOW);
        
        // sensor 1 activation
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
        
        // sensor 2 activation
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
        
        // sensor 3 activation
        digitalWrite(trigPin3,LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin3,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin3,LOW);
        duration3=pulseIn(echoPin3,HIGH);
        distance3=duration3/58.2;
        Serial.print("distance3:");
        Serial.println(distance3);
        delay(50);
   
        if((distance>=3 && distance<=6))            //change this to  distance  or  distance2 >=20 then we can get o/p if we change direction of train also.....
        {
            tone(buzzer,10);
            delay(2000);
            digitalWrite(trigPin3,LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin3,HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin3,LOW);
            duration3=pulseIn(echoPin3,HIGH);
            distance3=duration3/58.2;
            Serial.print("distance3:");
            Serial.println(distance3);
            delay(50);
            while(distance3>=3 && distance3<=6)
            {
                digitalWrite(trigPin3,LOW);
                delayMicroseconds(2);
                digitalWrite(trigPin3,HIGH);
                delayMicroseconds(10);
                digitalWrite(trigPin3,LOW);
                duration3=pulseIn(echoPin3,HIGH);
                distance3=duration3/58.2;
                Serial.print("distance3:");
                Serial.println(distance3);
                delay(50);
            }
            
            
            
            for(angle=90;angle<180;angle+=1)
            {
                myservo.write(angle);
                delay(20);
            }
            digitalWrite(led2,HIGH);
            digitalWrite(led,LOW);
            noTone(buzzer);
            
  A:        digitalWrite(trigPin2,LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin2,HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin2,LOW);
            duration2=pulseIn(echoPin2,HIGH);
            distance2=duration2/58.2;
            Serial.print("distance2:");
            Serial.println(distance2);
            delay(50);
      
            digitalWrite(trigPin3,LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin3,HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin3,LOW);
            duration3=pulseIn(echoPin3,HIGH);
            distance3=duration3/58.2;
            Serial.print("distance3:");
            Serial.println(distance3);
            delay(50);
            if(distance2>=3 && distance2<=6)
            { 
          
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
      
        digitalWrite(trigPin3,LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin3,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin3,LOW);
        duration3=pulseIn(echoPin3,HIGH);
        distance3=duration3/58.2;
        Serial.print("distance3:");
        Serial.println(distance3);
        delay(50);

        if((distance2>=3 && distance2<=6))
        {
            tone(buzzer,10);
            delay(2000);
            while(distance3>=3 && distance3<=6)
            {
                  digitalWrite(trigPin3,LOW);
                  delayMicroseconds(2);
                  digitalWrite(trigPin3,HIGH);
                  delayMicroseconds(10);
                  digitalWrite(trigPin3,LOW);
                  duration3=pulseIn(echoPin3,HIGH);
                  distance3=duration3/58.2;
                  Serial.print("distance3:");
                  Serial.println(distance3);
                  delay(50);

            }
            
            
            for(angle=90;angle<180;angle+=1)
            {
                 myservo.write(angle);
                 delay(20);
            }
            digitalWrite(led,LOW);
            digitalWrite(led2,HIGH);
            noTone(buzzer);
 B:         digitalWrite(trigPin,LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin,HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin,LOW);
            duration=pulseIn(echoPin,HIGH);
            distance=duration/58.2;
            Serial.print("distance:");
            Serial.println(distance);
            delay(50);
            if(distance>=3 && distance<=6)
            {   
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
