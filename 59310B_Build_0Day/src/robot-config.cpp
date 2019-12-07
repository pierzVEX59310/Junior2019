#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FrontLeft = motor(PORT1, ratio18_1, false);
motor FrontRight = motor(PORT2, ratio18_1, false);
motor RearLeft = motor(PORT3, ratio18_1, false);
motor RearRight = motor(PORT4, ratio18_1, false);
motor LeftIntake = motor(PORT5, ratio18_1, false);
motor RightIntake = motor(PORT6, ratio18_1, true);
motor LeftTilt = motor(PORT7, ratio18_1, false);
motor RightTilt = motor(PORT8, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}