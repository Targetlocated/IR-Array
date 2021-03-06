
#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(3);
int ledPin = 6;
void setup() 
{
Serial.begin(9600);
pinMode (10, OUTPUT);
pinMode (11, OUTPUT);
pinMode (12, OUTPUT);
pinMode (13, OUTPUT);
pinMode (6, OUTPUT);
pinMode (7, OUTPUT);
pinMode (A0, INPUT);
pinMode (A1, INPUT);
pinMode (A2, INPUT);
pinMode (A3, INPUT);
pinMode (A4, INPUT);
pinMode (A5, INPUT);
motor1.setSpeed(255);
motor2.setSpeed(255);//127 for half speed:

}

void loop() {
  int s1 = digitalRead(A0);
  int s2 = digitalRead(A1);
  int s3 = digitalRead(A2);
  int s4 = digitalRead(A3);
  int s5 = digitalRead(A4);
  int s6 = digitalRead(A5);

  Serial.print(s1);
  Serial.print(" -- ");
  Serial.print(s2);
  Serial.print(" -- ");
  Serial.print(s3);
  Serial.print(" -- ");
  Serial.print(s4);
  Serial.print(" -- ");
  Serial.print(s5);
  Serial.print(" -- ");
  Serial.print(s6);
   Serial.println("");
  Serial.println("");
  delay(500);

if ( (s1==1) && (s2==1) && (s3==1) && (s4==1) && (s5==1) && (s6==1) ) {
forward();
}
else if ( (s1==1) && (s2==1) && (s3==0) && (s4==0) && (s5==1) && (s6==1) ) {
forward();// for thicker lines
}
else if ( (s1==0) && (s2==0) && (s3==0) && (s4==0) && (s5==0) && (s6==0) ) {
stop();
}
else if ( (s1==0) && (s2==0) && (s3==0) && (s4==1) && (s5==0) && (s6==0) ) {
 right();
}
else if ( (s1==0) 
&& (s2==0) && (s3==1) && (s4==0) && (s5==0) && (s6==0) ) {
left();
}
else if ( (s1==0) && (s2==1) && (s3==1) && (s4==0) && (s5==0) && (s6==0) ) {
sharpleft();
}
else if ( (s1==0) && (s2==0) && (s3==0) && (s4==1) && (s5==1) && (s6==0) ) {
sharpright();
}
else if ( (s1==1) && (s2==1) && (s3==1) && (s4==0) && (s5==0) && (s6==0) ) {
sharpleft();
}
else if ( (s1==0) && (s2==0) && (s3==0) && (s4==1) && (s5==1) && (s6==1) ) {
sharpright();
}
else{
forward();
}
}

void forward()
{
motor1.run(FORWARD);
motor2.run(FORWARD);
digitalWrite(ledPin, HIGH);
Serial.println(" Moving Forward");

}
void backward()
{motor1.run(BACKWARD);
motor2.run(BACKWARD);

digitalWrite(ledPin, HIGH);
Serial.println("Moving Backward");
}
void stop()
{motor1.run(RELEASE);
motor2.run(RELEASE);

digitalWrite(ledPin, LOW);
Serial.println("Stop");
}
void left()
{
motor1.run(BACKWARD);
motor2.run(FORWARD);
digitalWrite(ledPin, HIGH);
Serial.println(" Rotate Left");
}
void right()
{
motor1.run(FORWARD);
motor2.run(BACKWARD);
digitalWrite(ledPin, HIGH);
Serial.println(" Rotate Right");
}
void sharpleft()
{motor1.run(BACKWARD);
motor2.run(FORWARD);

digitalWrite(ledPin, HIGH);
Serial.println(" Rotate Left");
}
void sharpright()
{
motor1.run(FORWARD);
motor2.run(BACKWARD);
digitalWrite(ledPin, HIGH);
Serial.println(" Rotate Right");
}
