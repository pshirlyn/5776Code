void moveDrive (int left, int right) {
	motor[LDrive] = left;
	motor[RDrive] = right;
}

void moveLift (int speed) {
	motor[LLLift] = speed;
	motor[LRLift] = speed;
	motor[RLLift] = speed;
	motor[RRLift] = speed;
}

void clawState (int state) {
	SensorValue(ClawSolenoid) = state;
}
