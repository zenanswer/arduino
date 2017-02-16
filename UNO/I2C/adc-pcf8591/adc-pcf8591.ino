#include "Wire.h"

// I2C bus address,
//Arduino sends 7-bit addresses,
//but the PCF8591 wants an 8-bit,
//so we shift the byte over by one bit.
#define PCF8591 (0x90>>1)

#define ADC0 0x00 //P5, R7 photocell voltage
#define ADC1 0x01 //P4, temperature
#define ADC2 0x02
#define ADC3 0x03 //P6, single turn 10K ohm trimpot voltage

int RawValue0 = 0;
int RawValue2 = 0;
float Voltage = 0.0;

int readPCF8591(int id) {
  Wire.beginTransmission(PCF8591); // wake up PCF8591
  Wire.write(id); // control byte - read ADC0
  Wire.endTransmission(); // end tranmission
  Wire.requestFrom(PCF8591, 2);
  int RawValue = 0;
  while (Wire.available()) {
    RawValue = Wire.read(); //This needs two reads to get the value.
    RawValue = Wire.read();
  }
  Serial.print("id:");
  Serial.print(id);
  Serial.print(", value:");
  Serial.println(RawValue);

}

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}
void loop()
{
  readPCF8591(ADC1);
  delay(1000);
  readPCF8591(ADC2);
  delay(1000);
}

