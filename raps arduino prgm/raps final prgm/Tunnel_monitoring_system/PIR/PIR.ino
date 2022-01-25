//pir sensor

int ledpinred=12;
int ledpingreen=13;
int inputpin=2;
int inputpin1=4;
int pirstate = LOW;
int val=0;
int val1=0;

void setup() {
  pinMode(ledpinred,OUTPUT);
  pinMode(inputpin,INPUT);
  pinMode(ledpingreen,OUTPUT);
  pinMode(inputpin1,INPUT);
  
  Serial.begin(1000000);

}

void loop() {
  digitalWrite(ledpingreen,HIGH);
  val=digitalRead(inputpin);
  val1=digitalRead(inputpin1); 
  if(val==HIGH  or val1==HIGH)
  {
    digitalWrite(ledpinred,HIGH);
    digitalWrite(ledpingreen,LOW);
    if(pirstate == LOW)
    {
     Serial.println(" motion detected");
     pirstate=HIGH; 
    }
  }
  else{
    digitalWrite(ledpinred,LOW);
    digitalWrite(ledpingreen,HIGH);
    if(pirstate == HIGH)
    {
     Serial.println(" motion ENDED");
     pirstate=LOW; 
    }
  }

}
