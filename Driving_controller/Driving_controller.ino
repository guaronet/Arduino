
/* Driving a car with two motors/wheels using L298N dual motor controller
 * created on 18 June 2016
 * by Leonardo Tolosa <http://www.guaronet.com> 
 * 
 */

// Variables declarations ##############

// turn direction for testing (right/left)
int tRight = 13;   // Pin 13 as input to turn right
int tLeft = 12;   // Pin 12 as input to turn left


// Motor A
int en1 = 11; // Enable motor A (PWM)
int in1 = 8;  // IN1 motor A
int in2 = 7;  // IN2 motor A
int speedMotorA;


// Motor B
int en2 = 10;  // Enable mmotor B  (PWM) 
int in3 = 4;   // IN3 motor B
int in4 = 2;   // IN4 motor B
int speedMotorB;


/*
 * the wheels brake when the three variables are LOW
 */


void setup() {
  // put your setup code here, to run once:
// motor A
pinMode (en1, OUTPUT);
pinMode (in1, OUTPUT);
pinMode (in2, OUTPUT);
// motor B
pinMode (en2, OUTPUT);
pinMode (in3, OUTPUT);
pinMode (in4, OUTPUT);

// Set brake as initial conditions
analogWrite (en1, 0);
analogWrite (en2, 0);
digitalWrite (in1, LOW);
digitalWrite (in2, LOW);
digitalWrite (in3, LOW);
digitalWrite (in4, LOW);

// turn for testing
pinMode(tRight, INPUT);
pinMode(tLeft, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Testing the car movement ################

  //(tRight == HIGH) ? turnRight(100,255): brakeMotors();
  //(tLeft == HIGH) ? turnRight(255,100): brakeMotors();
  
   turnRight(255,255);
  
}

// functions declarations

// Set brake motors A and B ##############

void brakeMotors (){
analogWrite (en1, 0);
digitalWrite (in1, LOW);
digitalWrite (in2, LOW);
analogWrite (en2, 0);
digitalWrite (in3, LOW);
digitalWrite (in4, LOW);
}

// Turn right the car ##############

void turnRight (int speedMotorA, int speedMotorB){
// motor A moves forward (speedMotorA < speedMotor B)
analogWrite (en1, speedMotorA);
digitalWrite (in1, LOW);
digitalWrite (in2, HIGH);
// motor B moves backward (speedMotorA < speedMotor B)
analogWrite (en2, speedMotorB);
digitalWrite (in1, HIGH);
digitalWrite (in2, LOW);
}


// Turn left the car ##############

void turnLeft(int speedMotorA, int speedMotorB){
// motor A moves backward (speedMotorA > speedMotor B)
analogWrite (en1, speedMotorA);
digitalWrite (in1, HIGH);
digitalWrite (in2, LOW);
// motor B moves forward (speedMotorA > speedMotor B)
analogWrite (en2, speedMotorB);
digitalWrite (in1, LOW);
digitalWrite (in2, HIGH);
}








