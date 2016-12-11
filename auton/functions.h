void calibrate() {
	 SensorType[Gyro] = sensorNone;
	 wait1Msec(500);

	 SensorType[Gyro] = sensorGyro;
	 wait1Msec(2000);
}

void move (float ticks, int direction) {
	nMotorEncoder[LDrive] = 0;
	nMotorEncoder[RDrive] = 0;

	while (abs(nMotorEncoder[LDrive]) < ticks && abs(nMotorEncoder[RDrive]) < ticks) {
		motor[LDrive] = direction * 127;
		motor[RDrive] = direction * 127;
		wait1Msec(20);
	}

	// brake
	motor[LDrive] = BRAKE_SPEED * -direction;
	motor[RDrive] = BRAKE_SPEED * -direction;
	wait1Msec(BRAKE_TIME);
	motor[LDrive] = 0;
	motor[RDrive] = 0;

	nMotorEncoder[LDrive] = 0;
	nMotorEncoder[RDrive] = 0;
}

/* do not rotate less than 20 degrees; decel kicks in at 20 degrees
tested but double check rotation constants: make sure that 1 was clockwise
*/
void rotate (int degrees, int direction) {
	int speed = 127;
	int decelAngle = 10;

	SensorValue[Gyro] = 0;
	while(abs(SensorValue[Gyro]) < (degrees - 2 * decelAngle) * 10) {
		moveDrive((direction * speed), (-direction * speed));
		wait1Msec(20);
	}

	// first deceleration
	speed /= 2;
	SensorValue[Gyro] = 0;
	while(abs(SensorValue[Gyro]) < decelAngle * 10){
		moveDrive((direction * speed), (-direction * speed));
		wait1Msec(20);
	}

	// second deceleration
	speed /= 2;
	SensorValue[Gyro] = 0;
	while(abs(SensorValue[Gyro]) < decelAngle * 10){
		moveDrive((direction * speed), (-direction * speed));
		wait1Msec(20);
	}

	// brake
	moveDrive((-direction * BRAKE_SPEED), (direction * BRAKE_SPEED));
	wait1Msec(100);
	moveDrive(0, 0);
}

/* makes the following assumptions:
-higher gyro value = lift is physically higher
-powering lift with positive number moves it upward, negative number moves it downward
*/
void autonLiftUp (int angle) {
	int speed = 127;
	while (SensorValue(LiftPot) < 0.8 * angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	speed /= 2;
	while (SensorValue(LiftPot) < 0.9 * angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	speed /= 2;
	while (SensorValue(LiftPot) < angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	moveLift(0);
}

void autonLiftDown (int angle) {
	int speed = -127;
	while (SensorValue(LiftPot) > 1.2 * angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	speed /= 2;
	while (SensorValue(LiftPot) > 1.1 * angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	speed /= 2;
	while (SensorValue(LiftPot) > angle) {
		moveLift(speed);
		wait1Msec(20);
	}

	moveLift(0);
}

// Bellarmine deploy; change for Fairfield
void deploy() {
	const int WING_UP_ANGLE = 1800; // wing up angle

	SensorValue(ClawSolenoid) = 1;
}
