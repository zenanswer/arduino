#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

int sensorPin = A0;
int sensorValue = 0;

int waitCnt = 0;

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Brightness Level");
  Serial.begin (9600);
}

void loop() {
  waitCnt ++;
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if (waitCnt > 10) {
    //lcd.clear();
    lcd.setCursor(0, 1);
    char value[16];
    sprintf(value, "          --% 4d", sensorValue);
    lcd.print(value);
    waitCnt = 0;
  }
  delay(100);
}
