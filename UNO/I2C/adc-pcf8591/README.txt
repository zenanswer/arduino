#PCF8591 YL-40 AD DA Module

https://brainfyre.wordpress.com/2012/10/25/pcf8591-yl-40-ad-da-module-review/

The jumpers control whether analog input channels of the IC are connected to the analog sources:
    Jumper P4 - AIN1: The temperature sensed by the R6 thermistor is provided to the ADC.
    Jumper P5 - AIN0: The R7 photocell voltage (resistance drop) is provided to the DAC.
    Jumper P6 - AIN3: The single turn 10K ohm trimpot voltage (resistance drop – brighter light, lower resistance).

#Define

PCF8591 (0x90 >> 1) // Device address = 0       
PCF8591_DAC_ENABLE 0x40
PCF8591_ADC_CH0 0x40
PCF8591_ADC_CH1 0x41
PCF8591_ADC_CH2 0x42
PCF8591_ADC_CH3 0x43

#DA

Wire.beginTransmission(PCF8591);
Wire.write(PCF8591_DAC_ENABLE); 
Wire.write(dac_value); //Send the desired DAC value (0-255)
Wire.endTransmission();

#AD

Wire.beginTransmission(PCF8591);
Wire.write(PCF8591_ADC_CH2);
Wire.endTransmission();
Wire.requestFrom((int) PCF8591,2);
while (Wire.available()) {
	adc_value = Wire.read(); //This needs two reads to get the value.
	adc_value = Wire.read();
}

## Raw value into Voltage 
Voltage = (RawValue * 5.0 ) / 256.0

