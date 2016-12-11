void moveDrive (int left, int right) {
	motor[LDrive] = motor[LDrive2] = left;
	motor[RDrive] = motor[RDrive2] = right;
}

void moveLift (int speed) {
	motor[LLLift] = speed;
	motor[LRLift] = speed;
	motor[RLLift] = speed;
	motor[RRLift] = speed;
}

void clawState (int state) {
	SensorValue[ClawSolenoid] = state;
}
