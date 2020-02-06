#include "commands/Claw/ClawFullOpen.h"
#include "Robot.h"
#include "RobotMap.h"

ClawFullOpen::ClawFullOpen(){
	Requires(Robot::claw.get());
}

void ClawFullOpen::Initialize(){
    frc::SmartDashboard::PutString("Last Action","Claw: Full Open");
    Robot::claw->MoveClawToFullOpen();
}

void ClawFullOpen::Execute(){
}

bool ClawFullOpen::IsFinished(){
	static int msgthrottle = 0;
	static double target = CLAW_POT_VAL_FO;
	if(msgthrottle >= 5){
		printf("Target: %.2f  Current: %.2f\n", target, Robot::claw->GetClawPotValue());
		msgthrottle=0;
	}
	return (Robot::claw->GetClawPotValue() >= (target - CLAW_POT_VAL_TOLERANCE) and Robot::claw->GetClawPotValue() <= (target + CLAW_POT_VAL_TOLERANCE));
	//return true; //this needs to read the pot and end when target reached
}

void ClawFullOpen::End(){
	Robot::claw->StopClaw();
}

void ClawFullOpen::Interrupted(){
	End();
}

