const int NUMDIR = 7;

void calibrateGyro(tSensors gyroPort)
{
	SensorType[gyroPort] = sensorEV3_Gyro;
	wait1Msec(50);
	SensorMode[gyroPort] = modeEV3Gyro_Calibration;
	wait1Msec(50);
	SensorMode[gyroPort] = modeEV3Gyro_RateAndAngle;
	wait1Msec(50);
}

void drive(string dir, int dist)
{
	nMotorEncoder[motorA] = 0;
	resetGyro(S3);
	if(dir == "ST")
	{
		motor[motorA] = motor[motorD] = 50;
		while(abs(nMotorEncoder[motorA]) < dist)
		{}
	}else if(dir == "CW")
	{
		motor[motorA] = 50;
		motor[motorD] = -50;
		while(abs(getGyroDegrees(S3)) < dist)
		{}
	}else if(dir == "CCW")
	{
		motor[motorA] = -50;
		motor[motorD] = 50;
		while(abs(getGyroDegrees(S3)) < dist)
		{}
	}


	motor[motorA] = motor[motorD] = 0;
}

task main(){
  string directions[NUMDIR]={"ST","CW","ST","CW","ST", "CCW", "ST"};
  int magnitudes[NUMDIR]={1200, 90, 900, 90, 900, 45, 1100};
  calibrateGyro(S3);

  for(int i=0; i<NUMDIR;i++)
  {
  	drive(directions[i], magnitudes[i]);
  }

  displayTextLine(4, "Group 95, Friday, 8:30AM");

  while(!getButtonPress(buttonEnter))
  {}

}
