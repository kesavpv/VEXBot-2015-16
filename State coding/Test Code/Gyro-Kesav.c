#pragma config(StandardModel, "RVW SWERVEBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turnAngle(float angle)
{
	int speed = 63;

	while(SensorValue[gyro] < SensorValue[gyro]+(10*angle))
	{
		if(angle < 0)
		{
			motor[rightMotor] = -speed;
			motor[leftMotor] = speed;
		}
		else if(angle > 0)
		{
			motor[rightMotor] = speed;
			motor[leftMotor] = -speed;
		}
	}
}

task main()
{
	SensorValue[gyro] = 0;
	wait1Msec(1000);

	while(SensorValue[gyro] < 900)
	{
		motor[leftMotor] = -63;
		motor[rightMotor] = 63;
	}

	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}
