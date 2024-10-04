//Tristan Yan-Klassen and Noah Harman

const float CONVERSION_FACTOR = (2*PI*2.75)/360.0;

void configure_sensor()
{
	sensorType[S2] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S2] = modeEV3Color_Color;
	wait1Msec(50);
	sensorType[S4] = sensorEV3_Ultrasonic;
	wait1Msec(50);
	nMotorEncoder[motorA] = 0;
	wait1Msec(50);

}

float encoder_speed(int motor_power, float distance)
{
	ClearTimer(T1);
	nMotorEncoder[motorA] = 0;
	motor[motorA] = motor[motorD] = motor_power;
	while(abs(nmotorEncoder[motorA]) * CONVERSION_FACTOR < distance)
	{}
	motor[motorA] = motor[motorD] = 0;
	float time_elapsed = time1[T1]/1000.0;
	return distance/time_elapsed;
}

float ultrasonic_speed(int motor_power, float distance)
{
	ClearTimer(T1);
	float initial_dist = 0;
	initial_dist = sensorValue [S4];
	motor[motorA] = motor[motorD] = motor_power;
	while(sensorValue[S4] > initial_dist - distance)
	{}
	motor[motorA] = motor[motorD] = 0;
	float time_elapsed = time1[T1]/1000.0;
	return distance/time_elapsed;
}

void print_speed(int row, float speed)
{
	displayTextLine(row,"Speed is %0.2f", speed);
}



task main()
{
	displayTextLine(4, "Group 34 TYK NH");
	configure_sensor();

	while(SensorValue[S2] != (int)colorRed && SensorValue[S2] != (int)colorBlue)
	{}
	if(SensorValue[S2] == (int)colorRed)
	{
		float speed = 0;
		speed = encoder_speed(50, 60.0);
		print_speed(5, speed);
		displayTextLine(10, "red");
	}
	else
	{
		float speed = 0;
		speed = ultrasonic_speed(50, 60.0);
		print_speed(5, speed);
	}
	wait1Msec(10000);

}

/*
Holding Red:

Group 34 TYK NH
Speed is 23.99


Holding Blue:

Group 34 TYK NH
Speed is 23.54






*/
