//connect 3.3v to AREF

const int xPin = A5;
const int yPin = A4;
const int zPin = A3;  

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  analogReference(EXTERNAL);    //connect 3.3v to AREF
  Serial.print("x" );
  Serial.print(analogRead(xPin) );
  Serial.print("\t");
  Serial.print("y" );
  Serial.print(analogRead(yPin));
  Serial.print("\t");
  Serial.print("z");
  Serial.print(analogRead(zPin));
  Serial.println();

  delay(2000);                     
  
}
