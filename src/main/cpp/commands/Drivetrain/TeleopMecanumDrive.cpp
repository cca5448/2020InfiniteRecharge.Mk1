#include "commands/Drivetrain/TeleopMecanumDrive.h"
#include "Robot.h"

TeleopMecanumDrive::TeleopMecanumDrive()
{
	Requires(Robot::drivetrain.get()); //requires the drivetrain subsystem
}

void TeleopMecanumDrive::Initialize()
{
}

void TeleopMecanumDrive::Execute()
{
	//printf("throt=%2f strf=%2f steer=%2f",Robot::oi->GetThrottleAxis(),Robot::oi->GetStrafeAxis(),Robot::oi->GetTurnAxis());
	Robot::drivetrain->DriveMecanum(Robot::oi->GetThrottleAxis(), Robot::oi->GetStrafeAxis(), Robot::oi->GetTurnAxis());
}

bool TeleopMecanumDrive::IsFinished()
{
	return false;
}

void TeleopMecanumDrive::End()
{
	Robot::drivetrain->DriveMecanumStop(); //sets the speed to 0 so doesnt drive or continue driving
}

void TeleopMecanumDrive::Interrupted()
{
	End();
}

