#include "commands/Wrist/MoveWristStow.h"
#include "Robot.h"
#include "RobotMap.h"

MoveWristStow::MoveWristStow(){
	Requires(Robot::wrist.get());
	m_TARGET_POS = WRIST_POS_STOW;
}

void MoveWristStow::Initialize(){
    printf("Wrist: Move Wrist to %.2f\n",m_TARGET_POS);
	Robot::wrist->Enable();
	Robot::wrist->SetSetpoint(m_TARGET_POS);
}

void MoveWristStow::Execute(){
}

bool MoveWristStow::IsFinished(){
	return Robot::wrist->OnTarget();
	//return true;
}

void MoveWristStow::End(){
}

void MoveWristStow::Interrupted(){
	End();
}

