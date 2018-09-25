#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(3);
void setup() {
motor1.setSpeed(255);
motor2.setSpeed(255);// put your setup code here, to run once:

}

void loop() {
delay(20000);  // put your main code here, to run repeatedly:
motor1.run(FORWARD);
motor2.run(BACKWARD);//RIGHT
delay(1000);
motor1.run(FORWARD);
motor2.run(FORWARD);//forward
delay(5000);
motor1.run(BACKWARD);
motor2.run(FORWARD);//LEFT turn
delay(3000);    
}
