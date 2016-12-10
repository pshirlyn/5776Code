// FIND VALUES FOR ALL CONSTANTS DEFINED AS 999
#define BRAKE_SPEED 30
#define BRAKE_TIME 30

// drive constants
#define FORWARD 1
#define BACKWARD -1
#define CLOCKWISE 1
#define COUNTERCLOCKWISE -1
#define LEFT 1
#define RIGHT -1

// knock fence stars off
#define START_TO_LINE 999 // should be to white line (about 1/2 tile)
#define ALIGN 999 // slight distance after turn to center robot on fence
#define LINE_TO_FENCE 999 // however long needed to get to fence

// cube score
#define FENCE_TO_LINE 999 // should be the same as LINE_TO_FENCE but for safety
#define POSTFENCE_TO_CUBE_1 999 // distance from where robot is on the white line from after fence push to cube
#define POSTFENCE_TO_CUBE_2 999 // slight distance to center robot with respect to lower fence
#define CUBE_TO_FENCE 999 // after cube has been picked up distance from cube to low fence

// lift constants
#define UP 1
#define DOWN -1

#define LIFT_HIGH_FENCE 999
#define LIFT_CUBE_SCORE 999 // angle potentiometer needs to be at to dump cube over lower fence and knock stars with it
#define LIFT_DOWN 999

// claw constants
#define OPEN 1
#define CLOSED 0
