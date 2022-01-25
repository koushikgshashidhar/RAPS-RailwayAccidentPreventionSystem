#include <DFRobot_sim808.h>
#include <SoftwareSerial.h>

#define led 2   //LED RED

//L293D
//Motor A
const int motorPin1 = 3; // Pin 3 of L293
const int motorPin2 = 4; // Pin 4 of L293
//Motor B
const int motorPin3 = 8; // Pin 8 of L293
const int motorPin4 = 9; // Pin 9 of L293
//buzzer
const int buzzer = 35;

//connect 3.3v to AREF
const int xPin = A5;
const int yPin = A4;
const int zPin = A3;  


#define echoPin 13 //SENSOR1 PIN 13
#define trigPin 12 //SENSOR1 PIN 12

#define echoPin2 5 //SENSOR2 PIN 5
#define trigPin2 6 //SENSOR3 PIN 6

#define echoPin3 48 //SENSOR2 PIN 30
#define trigPin3 49 //SENSOR3 PIN 31

long duration,duration2,duration3,distance,distance2,distance3;


#define MESSAGE_LENGTH 160
char message[MESSAGE_LENGTH];
int messageIndex = 0;
int danger=0;
char MESSAGE[300];
char lat[12];
char lon[12];
char wspeed[12];

char phone[16];
char datetime[24];

#define PIN_TX 51
#define PIN_RX 50
SoftwareSerial mySerial(PIN_TX,PIN_RX);
DFRobot_SIM808 sim808(&mySerial);//Connect RX,TX,PWR,

void sendSMS();
void getGPS(int danger);
void readSMS();

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);

  //Set pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT); 

  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);

  pinMode(trigPin3,OUTPUT);
  pinMode(echoPin3,INPUT);
  
  pinMode(buzzer,OUTPUT);

  //******** Initialize sim808 module *************
  while(!sim808.init())
  {
      Serial.print("Sim808 init error\r\n");
      delay(1000);
  }
  

  Serial.println("SIM Init success");    
  Serial.println("Init Success, please send SMS message to start!");
}

void loop()
{
    
   int x,y,z;
    
   //*********** Detecting unread SMS ************************
   messageIndex = sim808.isSMSunread();

   //*********** At least, there is one UNREAD SMS ***********
   if (messageIndex > 0)
   { 
       readSMS();
       if(message[0]=='7')
       {
            //This code will turn Motor A clockwise
            digitalWrite(motorPin2, HIGH);
            digitalWrite(motorPin1, LOW);

            //This code will turn Motor B clockwise
            digitalWrite(motorPin4, LOW);
            digitalWrite(motorPin3, HIGH);
    
            while(danger==0)
            {
                analogReference(EXTERNAL);    //connect 3.3v to AREF
                x=(analogRead(xPin) -392);
                Serial.print(analogRead(xPin) -392);
                Serial.print("\t");
                y=(analogRead(yPin)-400);
                Serial.print(analogRead(yPin)-400);
                Serial.print("\t");
                z=(analogRead(zPin)-310);
                Serial.print(analogRead(zPin)-310);
                Serial.println();
                delay(500);                     

                // track1 crack sensor1
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

                //track2 crack sensor2
                digitalWrite(trigPin2,LOW);
                delayMicroseconds(2);
                digitalWrite(trigPin2,HIGH);
                delayMicroseconds(10);
                duration2=pulseIn(echoPin2,HIGH);
                distance2=duration2/58.2;
                Serial.print("distance2:");
                Serial.println(distance2);
                delay(50);

                //obstacle detection sensor3
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
                while(distance3<10)
                {
                    tone(buzzer,10);
                    Serial.print("obstacle detected\n");
                    delay(2000);
                    noTone(buzzer); 
                }
       
                if(distance>5 or distance2>5 )
                {
                    danger=2;

                    //And this code will stop motors
                    digitalWrite(motorPin1, LOW);
                    digitalWrite(motorPin2, LOW);
                    //And this code will stop motors
                    digitalWrite(motorPin3, LOW);
                    digitalWrite(motorPin4, LOW);

                }
                else if( x >30 or y>30)
                {
                    danger=1;

                    //And this code will stop motors
                    digitalWrite(motorPin1, LOW);
                    digitalWrite(motorPin2, LOW); 
                    //And this code will stop motors
                    digitalWrite(motorPin3, LOW);
                    digitalWrite(motorPin4, LOW);

                }
        
            }
            getGPS(danger);
            digitalWrite(led,HIGH);
            sendSMS();
            
            //************* Turn off the GPS power ************
            sim808.detachGPS();
            digitalWrite(led,LOW);
            Serial.println("Please send SMS message to restart!");
      }
      danger=0;
    }
}

//function to read message
void readSMS()
{
    Serial.print("messageIndex: ");
    Serial.println(messageIndex);
    sim808.readSMS(messageIndex, message, MESSAGE_LENGTH, phone, datetime);
             
    //***********In order not to full SIM Memory, is better to delete it**********
    sim808.deleteSMS(messageIndex);
    Serial.print("From number: ");
    Serial.println(phone);  
    Serial.print("Datetime: ");
    Serial.println(datetime);        
    Serial.print("Recieved Message: ");
    Serial.println(message);
}

//function to get location
void getGPS( int danger)
{ 
    while(!sim808.attachGPS())
    {
        Serial.println("Open the GPS power failure");
        delay(1000);
    }
    delay(1000);
    Serial.println("Open the GPS power success");
    // getting gps coordinates
    while(!sim808.getGPS())
    {
    Serial.println("gps tracking on process");
    }

    Serial.print(sim808.GPSdata.year);
    Serial.print("/");
    Serial.print(sim808.GPSdata.month);
    Serial.print("/");
    Serial.print(sim808.GPSdata.day);
    Serial.print(" ");
    Serial.print(sim808.GPSdata.hour);
    Serial.print(":");
    Serial.print(sim808.GPSdata.minute);
    Serial.print(":");
    Serial.print(sim808.GPSdata.second);
    Serial.print(":");
    Serial.println(sim808.GPSdata.centisecond);
    Serial.print("latitude :");
    Serial.println(sim808.GPSdata.lat);
    Serial.print("longitude :");
    Serial.println(sim808.GPSdata.lon);
    Serial.print("speed_kph :");
    Serial.println(sim808.GPSdata.speed_kph);
    Serial.print("heading :");
    Serial.println(sim808.GPSdata.heading);
    Serial.println();
    if(danger==1)
      Serial.print("derailed");
    else if (danger==2)
      Serial.print("cracked");
    float la = sim808.GPSdata.lat;
    float lo = sim808.GPSdata.lon;
    float ws = sim808.GPSdata.speed_kph;

    dtostrf(la, 4, 6, lat); //put float value of la into char array of lat. 4 = number of digits before decimal sign. 6 = number of digits after the decimal sign.
    dtostrf(lo, 4, 6, lon); //put float value of lo into char array of lon
    dtostrf(ws, 6, 2, wspeed);  //put float value of ws into char array of wspeed
    if(danger==1)
      sprintf(MESSAGE, "Latitude : %s\nLongitude : %s\nWind Speed : %s kph\n Derailment Detected  Try With This Link.\nhttp://www.latlong.net/Show-Latitude-Longitude.html\nhttp://maps.google.com/maps?q=%s,%s\n", lat, lon, wspeed, lat, lon);
    else
      sprintf(MESSAGE, "Latitude : %s\nLongitude : %s\nWind Speed : %s kph\n Crack Detected  Try With This Link.\nhttp://www.latlong.net/Show-Latitude-Longitude.html\nhttp://maps.google.com/maps?q=%s,%s\n", lat, lon, wspeed, lat, lon);
}

//function to send sms
void sendSMS()
{
    Serial.println("Start to send message ...");
  
    Serial.println(MESSAGE);
    Serial.println(phone);
  
    sim808.sendSMS(phone,MESSAGE);
  
}




