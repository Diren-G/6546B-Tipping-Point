/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

//functions
// left
motor L1 = motor(PORT1, ratio18_1, false);
motor L2 = motor(PORT3, ratio18_1, false);

// right
motor R1 = motor(PORT13, ratio18_1, true);
motor R2 = motor(PORT14, ratio18_1, true);

// drive bases
motor_group DriveL(L1, L2);
motor_group DriveR(R1, R1);

//functioms
void turn_left(int degree){
  double starting_degree = inertial1.heading(degrees);
  double final_degree = starting_degree + degree;
  while(inertial1.heading(degrees) != final_degree){
    DriveL.spin(forward);
    DriveR.spin(reverse);
  }
}

void turn_right(int degree){
  double starting_degree = inertial1.heading(degrees);
  double final_degree = starting_degree - degree;
  while(inertial1.heading(degrees) != final_degree){
    DriveL.spin(reverse);
    DriveR.spin(forward);
  }
}
//function end


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

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
  //exstensions and start-up
  /*
  extend the mobile goal clamp so its out
  update intake to always spin
  */
  
  // white
  /*
  forward to location which is roughly near the goal
  use vision to align 
  while (ultrasonic distance is less than x distance) move forward
      WILL NEED A LIMIT SO THAT WE DONT GO PAST AND INVALIDATE OUR TEAMS AUTON
  move forward for overbite
  snag yellow
  rotate left about 45
  forward to location which is roughly near the goal
  use vision to align
  while (ultrasonic distance is less than x distance) move forward
  move forward for overbite
  snag red
  */

  //blue
  /*
  forward to location which is roughly near the goal
  use vision to align 
  while (ultrasonic distance is less than x distance) move forward
      WILL NEED A LIMIT SO WE DONT GO PAST AND INVALIDATE THE AUTON
  move forward for overbite
  snag yellow
  rotate right about 170
  forward to location which is roughly near the goal
  use vision to align
  while (ultrasonic distance is less than x distance) move forward
  move forward for overbite
  snag red
  */
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
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

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
