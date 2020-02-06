#include "commands/Wrist/MoveWristToPosition.h"
#include "Robot.h"

MoveWristToPosition::MoveWristToPosition(double pos){
	Requires(Robot::wrist.get());
	m_TARGET_POS = pos;
}

void MoveWristToPosition::Initialize(){
    printf("Wrist: Move Wrist to %.2f\n",m_TARGET_POS);
	Robot::wrist->Enable();
	Robot::wrist->SetSetpoint(m_TARGET_POS);
}

void MoveWristToPosition::Execute(){
}

bool MoveWristToPosition::IsFinished(){
	return Robot::wrist->OnTarget();
	//return true;
}

void MoveWristToPosition::End(){
}

void MoveWristToPosition::Interrupted(){
	End();
}

