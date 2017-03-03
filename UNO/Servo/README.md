#Servo



1. Angle range

	> 0 °~180 °

2. Connections

	> Servo <-> Arduino
	
	> Red Cable - 5V
	
	> Black or Brown - GND
	
	> Orange or Yellow - Digital pin 9(PWM)


#Joystick

1. Connections

	> Joystick <-> Arduino
	
	> VCC - 5V
	
	> GND - GND
	
	> X - A1

	> Y - A0
	
	> SET - Digital pin 2(PWM)
	
2. Set button

	> Some type of Joystick, does not have the SET pin. But you can see a button on the stick board. X=1023 when you press the button down on Joystick.
	
3. Effective range

	> From the reference, the range is 0-1023, but my Joystick is 275-754.
	
	> X=1023 means press down

#Reference

1. [Arduino-2-Servos-Thumbstick-joystick](http://www.instructables.com/id/Arduino-2-Servos-Thumbstick-joystick/?ALLSTEPS)
2. [arduino-joystick-module](http://42bots.com/tutorials/arduino-joystick-module-example/)