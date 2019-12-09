/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Simon Kroll                                               */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// FrontLeft            motor         1               
// FrontRight           motor         2               
// RearLeft             motor         3               
// RearRight            motor         4               
// LeftIntake           motor         5               
// RightIntake          motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/


void tankDrive(int leftSpeed, int rightSpeed){
  FrontLeft.setVelocity(leftSpeed, percent);
  RearLeft.setVelocity(leftSpeed, percent);
  FrontRight.setVelocity(rightSpeed,percent);
  RearRight.setVelocity(rightSpeed,percent);
  FrontLeft.spin(forward);
  FrontRight.spin(forward);
  RearLeft.spin(forward);
  RearRight.spin(forward);
}

void intake(int speed){
  LeftIntake.setVelocity(speed,percent);
  RightIntake.setVelocity(speed,percent);
  LeftIntake.spin(forward);
  RightIntake.spin(forward);
}

void tilt(int speed){
  LeftTilt.setVelocity(speed,percent);
  RightTilt.setVelocity(speed,percent);
  LeftTilt.spin(forward);
  RightTilt.spin(forward);
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

    tankDrive(Controller1.Axis3.position(percent),Controller1.Axis2.position(percent));

    if (Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing())
      intake(50);

    if (Controller1.ButtonR2.pressing() && !Controller1.ButtonR1.pressing())
      intake(-50);
    if (!Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing())
      intake(0);
    

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................


      if (Controller1.ButtonR2.pressing() && !Controller1.ButtonR1.pressing())
        intake(-50);
     if (!Controller1.ButtonR1.pressing() && !Controller1.ButtonR2.pressing())
        intake(0);
    //
    if (Controller1.ButtonL1.pressing() && !Controller1.ButtonL2.pressing())
      tilt(25);
      else if (!Controller1.ButtonL1.pressing() && Controller1.ButtonL2.pressing())
        tilt(-50);
        else
          tilt(0);
    //
    
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
