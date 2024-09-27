
task main()
{
	const float WHEEL_RADIUS = 2.75;
	const float CONVERSION_FACTOR = (2*PI*WHEEL_RADIUS)/360.0;

	sensorType[S1] = sensorEV3_Touch;
	wait1Msec(50);

	displayTextLine(4, "Group 17 TYK NH");
	nMotorEncoder[motorA] = 0;

	while(!getButtonPress(ENTER_BUTTON))
	{}
	while(getButtonPress(ENTER_BUTTON))
	{}

	motor[motorA] = motor[motorD] = 25;
	while(sensorValue[S1] == 0)
	{}
	motor[motorA] = motor[motorD] = 0;

	int initialDist = abs(nMotorEncoder[motorA]);
	nMotorEncoder[motorA] = 0;
	wait1Msec(2000);

	motor[motorA] = motor[motorD] = -25;
	while(abs(nMotorEncoder[motorA])*CONVERSION_FACTOR < 20)
	{}
	motor[motorA] = motor[motorD] = 0;
	wait1Msec(3000);

	motor[motorA] = motor[motorD] = -25;
	while(abs(nMotorEncoder[motorA]) < 2*initialDist)
	{}
	motor[motorA] = motor[motorD] = 0;

	displayTextLine(8, "Original distance: %f cm", initialDist*CONVERSION_FACTOR);
	wait1Msec(10000);





}
