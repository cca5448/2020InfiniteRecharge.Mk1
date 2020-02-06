//This contains the variables for the robot. Anything that is configurables goes here

#pragma once

//Tuneables - Move this to network tables
const float JOYSTICK_DEADZONE = 0.25; //dead zone
const float JOYSTICK_RAMP_POWER = 1.0; //speed ramp power - this is for ramping dead zone
const float JOYSTICK_DEADZONE_TURN = 0.4; //dead zone for turn
const float JOYSTICK_RAMP_POWER_TURN = 0.9; //speed ramp power for turn

//DRIVER STATION
//Joysticks
const unsigned short JOY_LEFT           = 0; //Left joystick USB ID
const unsigned short JOY_RIGHT          = 1; //Right joystick USB ID
const unsigned short JOY_DRIVE          = JOY_LEFT; //Drive joystick
const unsigned short JOY_STEER          = JOY_RIGHT; //Steering joystick
const unsigned short JOY_SCOOT        = JOY_LEFT; //Endgame joystick (Use throttle stick other axis)
const unsigned short JOY_DRIVE_AXIS_THROTTLE    = 1; //Throttle Axis
const unsigned short JOY_STEER_AXIS_TURN        = 0; //Turn Axis
const unsigned short JOY_SCOOT_AXIS_STRAFE    = 0; //Strafe Axis during endgame (re-use turn axis)

//Buttons (Left Joystick)
const unsigned short BTN_LIFT_UP        = 5; //Lift Up
const unsigned short BTN_LIFT_DOWN      = 4; //Lift Down
const unsigned short BTN_SCOOT_ACTIVE   = 9; //Scoot Hook Active

//Buttons (Right Joystick)
const unsigned short BTN_NIPPER_UP      = 5; //Nipper Arm Up
const unsigned short BTN_NIPPER_DOWN    = 4; //Nipper Arm Down
const unsigned short BTN_NIPPER_REV     = 3; //Nipper Wheel Rev
const unsigned short BTN_NIPPER_FWD     = 2; //Nipper Wheel Fwd

//DRIVETRAIN
//The drivetrain system uses 2-CIM ball shifting gear boxes with pneumatic shifters
const unsigned short DRIVE_MOT_LF			= 1; //Left Front
const unsigned short DRIVE_MOT_LR			= 2; //Left Rear //slave
const unsigned short DRIVE_MOT_RF			= 3; //Right Front
const unsigned short DRIVE_MOT_RR			= 4; //Right Rear //slave
const unsigned short DRIVE_SHIFT_ID     = 1; //Drivetrain shift pneumatic ID

//LIFT SYSTEM
//The lift system is the elevator system, driven by chains and sprockets
const unsigned short LIFT_MOT_1     = 7; //CAN ID for Lift Motor 1
const unsigned short LIFT_MOT_2     = 8; //CAN ID for Lift Motor 2 //slave
const unsigned double LIFT_SPEED     = 0.10; //Lift motor speed

//SCOOT SYSTEM
//The scoot system is the hooks that hang on the bar at endgame and have active driven rollers to move left or right
const unsigned short SCOOT_MOT_1    = 5; //CAN ID for Scoot Motor 1
const unsigned short SCOOT_MOT_2    = 6; //CAN ID for Scoot Motor 2 //slave
const unsigned double SCOOT_SPEED    = 0.10; //Scoot motor speed

//NIPPER SYSTEM
//The nipper is the record player like arm that has a wheel, color sensor, and pneumatic cylinder
const unsigned short NIPPER_MOT_1   = 9; //CAN ID for Nipper Motor 1
const unsigned short NIPPER_SPEED   = 0.10; //Nipper Wheel Speed
const unsigned short NIPPER_ARM_ID   = 1; //Nipper Arm pneumatic ID
