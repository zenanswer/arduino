#include <Servo.h>

//JoyStick
int xPin = A1;
int yPin = A0;
int buttonPin = 2; //PWM

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

//Servo
Servo myservo;
int servo_value = 0;

void setup() {
  Serial.begin(9600);

  //JoyStick
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP); 

  //Servo
  myservo.attach(9);
}

void loop() {
  //JoyStick
  int new_xPosition = analogRead(xPin);
  int new_yPosition = analogRead(yPin);
  //About this, check the comments below.
  int new_buttonState = 0;
  //int new_buttonState = digitalRead(buttonPin);

  bool output = false;
  if (new_xPosition != xPosition) {
    xPosition = new_xPosition;
    output = true;
  }
  if (new_yPosition != yPosition) {
    yPosition = new_yPosition;
    output = true;
  }
  /*
  if (new_buttonState != buttonState) {
    buttonState = new_buttonState;
    output = true;
  }
  */
  //if X=1023 is button down in my JoyStick
  if (xPosition == 1023)
    new_buttonState = 1;
  else
    new_buttonState = 0;

  if (new_buttonState != buttonState) {
    buttonState = new_buttonState;
    output = true;
  }

  if (output) {
    char state[64];
    sprintf(state, "X %3d, Y %3d, Button: %d", 
      xPosition, yPosition, buttonState);
    Serial.println(state);
  }

  //Position range, the range should be 0-1023,
  //but my JoyStick is 275-754
  int new_servo_value = map(xPosition, 275, 754, 0, 180); 

  if (new_servo_value != servo_value) {
    servo_value = new_servo_value;
    myservo.write(servo_value);
  }

  delay(100);
}
