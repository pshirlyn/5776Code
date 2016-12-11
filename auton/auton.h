// use claw to knock stars off fence
void fenceStars (int direction) {
	move(START_TO_LINE, FORWARD);
	rotate(45, direction * COUNTERCLOCKWISE);
	move(ALIGN, FORWARD);
	rotate(45, direction * CLOCKWISE);
	deploy();
	autonLiftUp(LIFT_HIGH_FENCE);
	clawState(OPEN);
	move(LINE_TO_FENCE, FORWARD);
	move(FENCE_TO_LINE, BACKWARD);
}

// pick up cube and knock it over central fence, knocking stars with it
void cubeScore (int direction) {
	rotate(90, direction * CLOCKWISE);
	autonLiftDown(LIFT_DOWN);
	move(POSTFENCE_TO_CUBE_1, FORWARD);
	clawState(CLOSED);
	autonLiftUp(LIFT_CUBE_SCORE/5); // just enough to have cube not drag on ground - change denominator if need be
	move(POSTFENCE_TO_CUBE_2, FORWARD);
	rotate(90, direction * CLOCKWISE);
	move(CUBE_TO_FENCE, BACKWARD);
	autonLiftUp(4 * LIFT_CUBE_SCORE/5); // release cube - lift whatever distance wasn't lifted initially
	clawState(OPEN); // not sure if auton release works; test
}


