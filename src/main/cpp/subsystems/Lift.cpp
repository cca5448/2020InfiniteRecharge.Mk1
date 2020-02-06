#include "RobotMap.h"
#include "subsystems/Lift.h"

#include "commands/Lift/StopLift.h" 

Lift::Lift() : frc::Subsystem("Lift"){
	liftmotor = std::make_shared<WPI_TalonSRX>(LIFT_MOT);

	//invert right side
	//liftmotor->SetInverted(true);
}

void Lift::InitDefaultCommand(){
	SetDefaultCommand(new StopLift());
}

void Lift::SetLiftSpeed(double throttle){
	liftmotor->Set(throttle);
}
