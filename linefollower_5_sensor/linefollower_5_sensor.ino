// Driver 1
const int IN1 = 6;  // PWM capable
const int IN2 = 7;  // PWM capable
const int IN3 = 8;  // PWM capable
const int IN4 = 9;  // PWM capable

// Driver 2
const int IN5 = 10; // PWM capable
const int IN6 = 11; // PWM capable
const int IN7 = 12; // PWM capable
const int IN8 = 13; // PWM capable

// IR Sensors
const int IR1 = A0;  // Far Left
const int IR2 = A1;  // Left
const int IR3 = A2;  // Center
const int IR4 = A3;  // Right
const int IR5 = A4;  // Far Right

// PWM Speed Control
int speedLeft = 150;  // Speed for left motors (0-255)
int speedRight = 150; // Speed for right motors (0-255)

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
}

void loop() {
  int sensorValues[5] = {
    digitalRead(IR1), 
    digitalRead(IR2), 
    digitalRead(IR3), 
    digitalRead(IR4), 
    digitalRead(IR5)
  };

  if (sensorValues[2] == LOW) {
    if (sensorValues[1] == LOW) {
      if (sensorValues[0] == LOW) {
        // Line is far left
        belokkiri();
      } else {
        // Line is left
        sedikitBelokkiri();
      }
    } else if (sensorValues[3] == LOW) {
      if (sensorValues[4] == LOW) {
        // Line is far right
        belokkanan();
      } else {
        // Line is right
        sedikitBelokkanan();
      }
    } else {
      // Line is centered
      maju();
    }
  } else {
    if (sensorValues[0] == LOW || sensorValues[1] == LOW) {
      // Line is far left or left
      belokkiri();
    } else if (sensorValues[3] == LOW or sensorValues[4] == LOW) {
      // Line is far right or right
      belokkanan();
    } else {
      // Line is lost
      berhenti();
    }
  }
}

void berhenti(){
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
  analogWrite(IN5, 0);
  analogWrite(IN6, 0);
  analogWrite(IN7, 0);
  analogWrite(IN8, 0);
}

void maju(){
  analogWrite(IN1, speedLeft);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, speedRight);
  analogWrite(IN5, speedLeft);
  analogWrite(IN6, 0);
  analogWrite(IN7, 0);
  analogWrite(IN8, speedRight);
}

void belokkiri(){
  analogWrite(IN1, 0);
  analogWrite(IN2, speedLeft);
  analogWrite(IN3, 0);
  analogWrite(IN4, speedRight);
  analogWrite(IN5, speedLeft);
  analogWrite(IN6, 0);
  analogWrite(IN7, speedRight);
  analogWrite(IN8, 0);
}

void sedikitBelokkiri(){
  analogWrite(IN1, speedLeft / 2);  // Reduce speed to turn slightly left
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, speedRight);
  analogWrite(IN5, speedLeft / 2);  // Reduce speed to turn slightly left
  analogWrite(IN6, 0);
  analogWrite(IN7, 0);
  analogWrite(IN8, speedRight);
}

void belokkanan(){
  analogWrite(IN1, speedLeft);
  analogWrite(IN2, 0);
  analogWrite(IN3, speedRight);
  analogWrite(IN4, 0);
  analogWrite(IN5, 0);
  analogWrite(IN6, speedLeft);
  analogWrite(IN7, 0);
  analogWrite(IN8, speedRight);
}

void sedikitBelokkanan(){
  analogWrite(IN1, speedLeft);
  analogWrite(IN2, 0);
  analogWrite(IN3, speedRight / 2);  // Reduce speed to turn slightly right
  analogWrite(IN4, 0);
  analogWrite(IN5, 0);
  analogWrite(IN6, speedLeft);
  analogWrite(IN7, speedRight / 2);  // Reduce speed to turn slightly right
  analogWrite(IN8, 0);
}
