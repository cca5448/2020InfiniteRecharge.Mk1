#include <math.h>
#include "OI.h"
#include "RobotMap.h"
#include <frc/WPILib.h>
#include <frc/smartdashboard/SmartDashboard.h>

//claw
#include "commands/Claw/ClawCaptureCargo.h"
#include "commands/Claw/ClawCaptureHatch.h"
#include "commands/Claw/ClawEmerHatchRelease.h"
#include "commands/Claw/ClawFullClose.h"
#include "commands/Claw/ClawFullOpen.h"
#include "commands/Claw/ClawStop.h"
//lift
#include "commands/Lift/MoveLiftUp.h"
#include "commands/Lift/MoveLiftDown.h"
#include "commands/Lift/StopLift.h"
//wrist
#include "commands/Wrist/MoveWristUp.h"
#include "commands/Wrist/MoveWristUpUp.h"
#include "commands/Wrist/MoveWristDown.h"
#include "commands/Wrist/MoveWristStow.h"

OI::OI()
{
	//constants are from RobotMap.h
	//joysticks
	drive_stick.reset(new frc::Joystick(JOY_DRIVE));
	steer_stick.reset(new frc::Joystick(JOY_STEER));
	lift_stick.reset(new frc::Joystick(JOY_LIFT));
	r_buttons.reset(new frc::Joystick(JOY_RIGHT));
	l_buttons.reset(new frc::Joystick(JOY_LEFT));

	//left button definitions
	//lift
	button_lift_up.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_UP));
	button_lift_down.reset(new frc::JoystickButton(l_buttons.get(),BTN_LIFT_DOWN));
	//wrist
	button_wrist_upup.reset(new frc::JoystickButton(l_buttons.get(),BTN_WRIST_UPUP));
	button_wrist_up.reset(new frc::JoystickButton(l_buttons.get(),BTN_WRIST_UP));
	button_wrist_down.reset(new frc::JoystickButton(l_buttons.get(),BTN_WRIST_DOWN));
	button_wrist_stow.reset(new frc::JoystickButton(l_buttons.get(),BTN_WRIST_STOW));
	//other
	button_cam_aa.reset(new frc::JoystickButton(l_buttons.get(),BTN_CAM_AA));

	//right button definitions
	//claw
	button_claw_cc.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_CC));
	button_claw_ch.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_CH));
	button_claw_fc.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_FC));
	button_claw_fo.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_FO));
	button_claw_ehr.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_EHR));
	button_claw_stop.reset(new frc::JoystickButton(r_buttons.get(),BTN_CLAW_STOP));
	//lighting
	button_light_mu.reset(new frc::JoystickButton(r_buttons.get(),BTN_LIGHT_MODEUP));
	button_light_md.reset(new frc::JoystickButton(r_buttons.get(),BTN_LIGHT_MODEDN));

	//assign commands to buttons
	//lift
	button_lift_up->WhileHeld(new MoveLiftUp());
	button_lift_down->WhileHeld(new MoveLiftDown());
	//button_lift_up->WhenPressed(new MoveLiftUp());
	//button_lift_up->WhenReleased(new StopLift());
	//button_lift_down->WhenPressed(new MoveLiftDown());
	//button_lift_down->WhenReleased(new StopLift());
	//wrist
	button_wrist_upup->WhileHeld(new MoveWristStow());
	button_wrist_upup->WhenReleased(new MoveWristUpUp());
	button_wrist_up->WhileHeld(new MoveWristStow());
	button_wrist_up->WhenReleased(new MoveWristUp());
	button_wrist_down->WhenPressed(new MoveWristDown());
	button_wrist_stow->WhenPressed(new MoveWristStow());
	//claw
	button_claw_cc->WhenPressed(new ClawCaptureCargo());
	button_claw_ch->WhenPressed(new ClawCaptureHatch());
	button_claw_fc->WhenPressed(new ClawFullClose());
	button_claw_fo->WhenPressed(new ClawFullOpen());
	button_claw_ehr->WhenPressed(new ClawEmerHatchRelease());
	button_claw_stop->WhenPressed(new ClawStop());
	//climber
	//button_end_dn->WhenPressed(new ClimberDown());
	//button_end_dnall->WhenPressed(new ClimberDownAll());
	//button_end_up->WhenPressed(new ClimberUp());
	//other
	//button_cam_aa->WhenPressed(new AimAssist());
	//button_light_md->WhenPressed(new LightModeDown());
	//button_light_mu->WhenPressed(new LightModeUp());
}

double OI::GetThrottleAxis(){
	//method will return the drive throttle axis
	double tval = RampingDeadZone(drive_stick->GetRawAxis(JOY_DRIVE_AXIS_THROTTLE));
	frc::SmartDashboard::PutNumber("Throttle Val", tval);
	return (tval * -1.0);
	//return drive_stick->GetRawAxis(JOY_DRIVE_AXIS_THROTTLE);
}
double OI::GetStrafeAxis(){
	//method will return the strafe axis
	double sval = RampingDeadZone(drive_stick->GetRawAxis(JOY_DRIVE_AXIS_STRAFE));
	frc::SmartDashboard::PutNumber("Strafe Val", sval);
	return (sval * 1.0);
	//return drive_stick->GetRawAxis(JOY_DRIVE_AXIS_STRAFE);
}
double OI::GetTurnAxis(){
	//method will return the turn axis
	double val = DeadZone(steer_stick->GetRawAxis(JOY_STEER_AXIS_TURN));
	frc::SmartDashboard::PutNumber("Turn Val", val);
	return (val * -1.0);
	//return steer_stick->GetRawAxis(JOY_STEER_AXIS_TURN);
}
double OI::GetLiftAxis(){
	//method will return the lift adjust axis
	return -(DeadZone(lift_stick->GetRawAxis(JOY_LIFT_AXIS_LIFT)));
	//return lift_stick->GetRawAxis(JOY_LIFT_AXIS_LIFT);
}

double OI::DeadZone(double uval)
{
	//if the uval is in the deadzone defined in robotmap.h, return 0.0 instead
	if (uval >= -JOYSTICK_DEADZONE && uval <= JOYSTICK_DEADZONE) {
		return 0.0;
	}
	return uval;
}

double OI::SteeringDeadZone(double sval)
{
	//This uses math to ramp the throttle starting at the deadzone edge, rather than
	//just starting at the value of the end of the deadzone
	double f_absval, f_n, f_y, f_pow;
	double invert = 1.0;
	if (sval < 0) invert = -1.0;
	f_absval = fabs(sval);
	f_n = 1 + JOYSTICK_DEADZONE_TURN;
	f_y = f_absval;
	f_y *= f_n;
	f_y -= JOYSTICK_DEADZONE_TURN;
	f_pow = f_n * JOYSTICK_RAMP_POWER_TURN;
	f_y = pow(f_y,f_pow);
	f_y *= invert;
	return f_y;

	/*
	 * https://www.desmos.com/calculator
	 * y=(xn-a)^mn //formula for speed ramp
	 * m=1.5 //ramp power of 1.5 (normal 1.1-1.8)
	 * a=0.3 //deadzone of 0.3
	 * n=1+a (multiplier to account for dead zone)
	 */
}

double OI::RampingDeadZone(double uval)
{
	//This uses math to ramp the throttle starting at the deadzone edge, rather than
	//just starting at the value of the end of the deadzone
	double f_absval, f_n, f_y, f_pow;
	double invert = 1.0;
	if (uval < 0) invert = -1.0;
	f_absval = fabs(uval);
	f_n = 1 + JOYSTICK_DEADZONE;
	f_y = f_absval;
	f_y *= f_n;
	f_y -= JOYSTICK_DEADZONE;
	f_pow = f_n * JOYSTICK_RAMP_POWER;
	f_y = pow(f_y,f_pow);
	f_y *= invert;
	return f_y;

	/*
	 * https://www.desmos.com/calculator
	 * y=(xn-a)^mn //formula for speed ramp
	 * m=1.5 //ramp power of 1.5 (normal 1.1-1.8)
	 * a=0.3 //deadzone of 0.3
	 * n=1+a (multiplier to account for dead zone)
	 */
}
