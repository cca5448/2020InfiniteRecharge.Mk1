#pragma once

#include <frc/WPILib.h>

class OI
{
	public:
		OI();
		double GetThrottleAxis(); //returns the axis to drive the robot
		double GetScootAxis(); //returns the axis to strafe the robot
		double GetTurnAxis(); //returns the axis to turn the robot
	private:
		//private functions
		double DeadZone(double uval);
		double SteeringDeadZone(double uval);
		double RampingDeadZone(double uval);

		//create joystick objects
		std::shared_ptr<frc::Joystick> drive_stick;
		std::shared_ptr<frc::Joystick> steer_stick;
		std::shared_otr<frc::Joystick> scoot_stick;
		std::shared_ptr<frc::Joystick> l_buttons; //left set of buttons
		std::shared_ptr<frc::Joystick> r_buttons; //right set of buttons

		//create buttons for control
		//drivetrain
		std::shared_ptr<frc::JoystickButton> button_drive_shift_fast; //shift to go-fast mode
		std::shared_ptr<frc::JoystickButton> button_drive_shift_hard; //shift to go-hard mode
				
		//scoot
		std::shared_ptr<frc::JoystickButton> button_scoot_active; //activate scoot system
		
		//lift
		std::shared_ptr<frc::JoystickButton> button_lift_up; //lift up
		std::shared_ptr<frc::JoystickButton> button_lift_down; //lift down
		
		//nipper
		std::shared_ptr<frc::JoystickButton> button_nipper_up; //nipper up (stowed)
		std::shared_ptr<frc::JoystickButton> button_nipper_down; //nipper down (engaged)
		std::shared_ptr<frc::JoystickButton> button_nipper_fwd; //nipper forward
		std::shared_ptr<frc::JoystickButton> button_nipper_rev; //nipper reverse
		
		//other
		std::shared_ptr<frc::JoystickButton> button_light_mu; //light mode up
		std::shared_ptr<frc::JoystickButton> button_light_md; //light mode down
};

