// Line Follower Robot with 5 IR Sensors
// Connections:
// Sensor Array: VCC-5V, GND-GND, S1-A0, S2-A1, S3-A2, S4-A3, S5-A4
// L298N: ENA-5, IN1-6, IN2-7, IN3-8, IN4-9, ENB-10

// ===== ADJUSTABLE PARAMETERS =====
#define NUM_SENSORS 5
const int sensorPins[NUM_SENSORS] = {A0, A1, A2, A3, A4}; // Sensor pins
const int sensorThreshold = 500; // Adjust this based on your surface (0-1023)
const int lineWidth = 3; // Line width in cm

// Motor control pins
const int enA = 5;  // Left motor speed
const int in1 = 6;  // Left motor forward
const int in2 = 7;  // Left motor backward
const int in3 = 8;  // Right motor forward
const int in4 = 9;  // Right motor backward
const int enB = 10; // Right motor speed

// Speed settings (0-255)
const int baseSpeed = 150;    // Base speed
const int turnSpeed = 200;    // Turning speed
const int donutSpeed = 200;   // Speed for 360 donut
const int stopSpeed = 0;      // Stop speed

// PID Control (adjust these values)
float Kp = 25;  // Proportional gain
float Ki = 0;   // Integral gain
float Kd = 15;  // Derivative gain

// ===== GLOBAL VARIABLES =====
int sensorValues[NUM_SENSORS];
int sensorState[NUM_SENSORS];
int lastError = 0;
int integral = 0;

void setup() {
  // Initialize motor control pins
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  
  // Initialize serial monitor for debugging
  Serial.begin(9600);
  
  // Set initial motor states
  stopMotors();
}

void loop() {
  readSensors();
  
  // Check if all sensors see white (donut mode)
  if (allSensorsWhite()) {
    doDonut();
    return;
  }
  
  // Check if all sensors see black (stop condition)
  if (allSensorsBlack()) {
    stopMotors();
    return;
  }
  
  // Normal line following
  followLine();
}

void readSensors() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
    sensorState[i] = (sensorValues[i] > sensorThreshold) ? 0 :1;
  }
}

bool allSensorsWhite() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (sensorState[i] == 1) return false;
  }
  return true;
}

bool allSensorsBlack() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (sensorState[i] == 0) return false;
  }
  return true;
}

void followLine() {
  // Calculate position error using weighted average
  int position = 0;
  int sum = 0;
  int sensorCount = 0;
  
  for (int i = 0; i < NUM_SENSORS; i++) {
    position += (i * 1000 * sensorState[i]); // Weighted by position
    sum += sensorState[i];
  }
  
  if (sum != 0) {
    position = position / sum;
  } else {
    position = 2000; // If no line detected, keep previous position
  }
  
  // Calculate error (2000 is center position)
  int error = position - 2000;
  
  // PID calculations
  integral += error;
  int derivative = error - lastError;
  int correction = (Kp * error + Ki * integral + Kd * derivative) / 100;
  
  // Apply motor speeds
  int leftSpeed = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;
  
  // Constrain speeds to valid range
  leftSpeed = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);
  
  // Set motor directions and speeds
  setMotorSpeeds(leftSpeed, rightSpeed);
  
  lastError = error;
}

void doDonut() {
  // Rotate right continuously
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, donutSpeed);
  analogWrite(enB, donutSpeed);
  
  // Keep checking sensors while in donut mode
  while (allSensorsWhite()) {
    readSensors();
    delay(10);
  }
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  // Left motor
  if (leftSpeed > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    leftSpeed = -leftSpeed;
  }
  
  // Right motor
  if (rightSpeed > 0) {
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    rightSpeed = -rightSpeed;
  }
  
  // Set motor speeds
  analogWrite(enA, constrain(leftSpeed, 0, 255));
  analogWrite(enB, constrain(rightSpeed, 0, 255));
}