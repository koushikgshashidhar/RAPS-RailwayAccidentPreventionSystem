#include <Servo.h>
Servo myservo;
int angle=0;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
for(angle=0;angle<180;angle+=1)
{
  myservo.write(angle);
  delay(20);
}
for(angle=180;angle>=1;angle-=1)
{
  myservo.write(angle);
  delay(20);
}
exit (0);
}
