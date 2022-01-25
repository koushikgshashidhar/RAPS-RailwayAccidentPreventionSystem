
#define echoPin 30
#define trigPin 31

long duration,distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1000000);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);

  distance=duration/58.2;

  Serial.println(distance);
  delay(50);
}
