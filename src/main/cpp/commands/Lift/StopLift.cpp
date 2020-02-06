#include "commands/Lift/StopLift.h"
#include "Robot.h"
#include "RobotMap.h"

StopLift::StopLift(){
	Requires(Robot::lift.get());
}

void StopLift::Initialize(){
    printf("Lift: Stop Lift\n");
	Robot::lift->SetLiftSpeed(0.0);
}

void StopLift::Execute(){
	
}

bool StopLift::IsFinished(){
	return false;
}

void StopLift::End(){
}

void StopLift::Interrupted(){
	End();
}

