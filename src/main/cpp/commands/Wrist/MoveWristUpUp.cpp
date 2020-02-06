#include "commands/Wrist/MoveWristUpUp.h"
#include "Robot.h"
#include "RobotMap.h"

MoveWristUpUp::MoveWristUpUp(){
	Requires(Robot::wrist.get());
	m_TARGET_POS = WRIST_POS_UPUP;
}

void MoveWristUpUp::Initialize(){
    printf("Wrist: Move Wrist to %.2f\n",m_TARGET_POS);
	Robot::wrist->SetSetpoint(m_TARGET_POS);
	Robot::wrist->Enable();
}

void MoveWristUpUp::Execute(){
}

bool MoveWristUpUp::IsFinished(){
	return Robot::wrist->OnTarget();
	//return true;
}

void MoveWristUpUp::End(){
   printf("Wrist: Done Moving Up\n");
}

void MoveWristUpUp::Interrupted(){
	End();
}

