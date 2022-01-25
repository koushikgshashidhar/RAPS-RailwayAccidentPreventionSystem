//L293D
//Motor A
const int motorPin1 = 3; // Pin 14 of L293
const int motorPin2 = 4; // Pin 10 of L293
//Motor B
const int motorPin3 = 8; // Pin 7 of L293
const int motorPin4 = 9; // Pin 2 of L293
void setup()
 
{
//Set pins as outputs
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);

pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);

 /*
//Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4
 
//This code will turn Motor A clockwise for 2 sec.
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
delay(2000);
 
//This code will turn Motor A counter-clockwise for 2 sec
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
delay(2000);
 
//This code will turn Motor B clockwise for 2 sec.
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(2000);
//This code will turn Motor B counter-clockwise for 2 sec.
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
delay(2000);
 
//And this code will stop motors
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
delay(2000);
 
//And this code will stop motors
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(2000);
*/
}
 
void loop()
 
{
  //This code will turn Motor A clockwise
        digitalWrite(motorPin1, HIGH);
            digitalWrite(motorPin2, LOW);
            digitalWrite(motorPin3, HIGH);
            digitalWrite(motorPin4, LOW);
 

}
