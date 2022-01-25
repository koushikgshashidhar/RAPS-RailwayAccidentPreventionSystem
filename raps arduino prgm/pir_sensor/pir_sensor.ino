//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 2;
int vcc1 = 7;       
 
//the time when the sensor outputs a low impulse
long unsigned int lowIn;        
 
//the amount of milliseconds the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000; 
 
boolean lockLow = true;
boolean takeLowTime; 
 
int pirPin = 3;    //the digital pin connected to the PIR sensor's output
int ledPin = 13;
int pirPin1 = 4;

 
 
/////////////////////////////
//SETUP
void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(vcc1, OUTPUT);
  digitalWrite(pirPin, LOW);
  pinMode(pirPin1, INPUT);
 digitalWrite(vcc1, HIGH);
  digitalWrite(pirPin1, LOW);
 digitalWrite(ledPin, LOW);
  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  }
 
////////////////////////////
//LOOP
void loop(){
 
 
     while(digitalRead(pirPin) == HIGH or digitalRead(pirPin1)==HIGH){
        //the led visualizes the sensors output pin state
       digitalWrite(ledPin, HIGH);
       if(lockLow){ 
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;           
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec");
         delay(50);
         }      
       }   
  }
