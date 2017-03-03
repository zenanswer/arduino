#include <Servo.h>

Servo myservo;

int value = 0;

void setup() {
  myservo.attach(9);
}

void loop() {
  if (value == 0)
    value = 180;
  else
    value = 0;
  myservo.write(value);
  delay(1500);
}
