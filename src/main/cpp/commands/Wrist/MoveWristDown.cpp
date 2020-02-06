#include "commands/Wrist/MoveWristDown.h"
#include "Robot.h"
#include "RobotMap.h"

MoveWristDown::MoveWristDown(){
	Requires(Robot::wrist.get());
	m_TARGET_POS = WRIST_POS_DOWN;
}

void MoveWristDown::Initialize(){
    printf("Wrist: Move Wrist to %.2f\n",m_TARGET_POS);
	Robot::wrist->SetSetpoint(m_TARGET_POS);
	Robot::wrist->Enable();
}

void MoveWristDown::Execute(){
}

bool MoveWristDown::IsFinished(){
	return Robot::wrist->OnTarget();
	//return true;
}

void MoveWristDown::End(){
   printf("Wrist: Done Moving Down\n");
}

void MoveWristDown::Interrupted(){
	End();
}

