#include "commands/Claw/ClawCaptureCargo.h"
#include "Robot.h"
#include "RobotMap.h"

ClawCaptureCargo::ClawCaptureCargo(){
	Requires(Robot::claw.get());
}

void ClawCaptureCargo::Initialize(){
    frc::SmartDashboard::PutString("Last Action","Claw: Capture Cargo");
    Robot::claw->MoveClawToCaptureCargo();
}

void ClawCaptureCargo::Execute(){
}

bool ClawCaptureCargo::IsFinished(){
	static int msgthrottle = 0;
	static double target = CLAW_POT_VAL_CC;
	if(msgthrottle >= 5){
		printf("Target: %.2f  Current: %.2f\n", target, Robot::claw->GetClawPotValue());
		msgthrottle=0;
	}
	return (Robot::claw->GetClawPotValue() >= (target - CLAW_POT_VAL_TOLERANCE) and Robot::claw->GetClawPotValue() <= (target + CLAW_POT_VAL_TOLERANCE));
	//return true; //this needs to read the pot and end when target reached
}

void ClawCaptureCargo::End(){
	Robot::claw->StopClaw();
}

void ClawCaptureCargo::Interrupted(){
	End();
}

