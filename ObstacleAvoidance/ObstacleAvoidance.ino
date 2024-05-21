#include <AFMotor.h>
#include <Servo.h>

#define TRIGGER_PIN 13 // Ultrasonic sensor trigger pin
#define ECHO_PIN 12    // Ultrasonic sensor echo pin
#define SERVO_PIN 10    // Servo motor pin

Servo servoMotor; // Create a servo object

int distanceMs;
int Left;
int Right;
int Straight;
unsigned long startTime;
int straightDistance;
int leftDistance;
int rightDistance;

// Create instances of the AF_DCMotor class for each motor connected to the motor shield
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  servoMotor.attach(SERVO_PIN);

  motor1.setSpeed(120); // Set motor speed to maximum
  motor2.setSpeed(120); // Set motor speed to maximum
  motor3.setSpeed(120); // Set motor speed to maximum
  motor4.setSpeed(120); // Set motor speed to maximum


}

int measureDistance() {
  long duration, distance;

  // Trigger the ultrasonic sensor to send out a pulse
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Measure the time it takes for the pulse to return
  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance based on the speed of sound
  distance = duration * 0.034 / 2;

  // distance= duration / 29 / 2;

  // Return the measured distance
  return distance;
}


void forward(){
  motor1.run(BACKWARD); // Run motor forward
  motor2.run(FORWARD); // Run motor forward
  motor3.run(BACKWARD); // Run motor forward
  motor4.run(BACKWARD); // Run motor forward
}
void backward(){
  motor1.run(FORWARD); // Run motor forward
  motor2.run(BACKWARD); // Run motor forward
  motor3.run(FORWARD); // Run motor forward
  motor4.run(FORWARD); // Run motor forward
}

void left() {
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

}

void right() {
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);

}

void stop(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

int seeLeft(){
  servoMotor.write(20); 
  delay(2000);
  Left = measureDistance();
  
  return Left;
  
}


int seeRight(){
  servoMotor.write(180);
  delay(2000);
  Right= measureDistance();

  return Right;
}

int seeStraight(){
  servoMotor.write(90);

  Straight= measureDistance();

  return Straight;

}


void loop() {

  distanceMs = measureDistance();
  Serial.print("Distance : ");
  Serial.println(distanceMs);

  if(distanceMs < 30){
    Serial.println("Stop");
    stop();
    Serial.println("Backward");
    backward();
    delay(800);
    int seeLefteye = seeLeft();
    int seeRighteye = seeRight();
    servoMotor.write(90);
    if(seeLefteye > seeRighteye){
      Serial.println("Turning Left");
      left();
      delay(1500);
    }else{
      Serial.println("Turning Right");
      right();
      delay(1500);

    }

  }else{
    Serial.println("Forward");
    forward();
  }

}
