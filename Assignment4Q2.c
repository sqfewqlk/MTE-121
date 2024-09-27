
task main()
{
	const float WHEEL_RADIUS = 2.75;
	const float CONVERSION_FACTOR = (2*PI*WHEEL_RADIUS)/360.0;\
	bool upPress = false;
	bool downPress = false;
	bool leftPress = false;
	bool rightPress = false;

	sensorType[S3] = sensorEV3_Gyro;
	wait1Msec(50);
	sensorMode[S3] = modeEV3Gyro_Calibration;
	wait1Msec(50);
	sensorMode[S3] = modeEV3Gyro_RateAndAngle;
	wait1Msec(50);


	displayTextLine(4, "Group 17 TYK NH");

	while(!getButtonPress(buttonAny))
	{}
	if(getButtonPress(buttonUp))
	{
		upPress = true;
	}else if(getButtonPress(buttonDown))
	{
		downPress = true;
	}
	while(getButtonPress(buttonAny))
	{}

	if(upPress == true)
	{
		motor[motorA] = motor[motorD] = -50;
		while(abs(nMotorEncoder[motorA])*CONVERSION_FACTOR < 60)
		{}
		motor[motorA] = motor[motorD] = 0;
	}else if(downPress == true)
	{
		motor[motorA] = motor[motorD] = 50;
		while(abs(nMotorEncoder[motorA])*CONVERSION_FACTOR < 60)
		{}
		motor[motorA] = motor[motorD] = 0;
	}

	while(!getButtonPress(buttonAny))
	{}
	if(getButtonPress(buttonLeft))
	{
		leftPress = true;
	}else if(getButtonPress(buttonRight))
	{
		rightPress = true;
	}
	while(getButtonPress(buttonAny))
	{}
	resetGyro(S3);

	if(leftPress == true)
	{
		motor[motorA] = -25;
		motor[motorD] = 25;
		while(abs(getGyroDegrees(S3)) < 180)
		{}
		motor[motorA] = motor[motorD] = 0;
	}else if(rightPress == true)
	{
		motor[motorA] = 25;
		motor[motorD] = -25;
		while(abs(getGyroDegrees(S3)) < 180)
		{}
		motor[motorA] = motor[motorD] = 0;
	}

}
