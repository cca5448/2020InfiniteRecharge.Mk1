#include "commands/Lift/MoveLiftUp.h"
#include "Robot.h"
#include "RobotMap.h"

MoveLiftUp::MoveLiftUp(){
	Requires(Robot::lift.get());
}

void MoveLiftUp::Initialize(){
    printf("Lift: Move Up\n");
	Robot::lift->SetLiftSpeed(-LIFT_SPEED);
}

void MoveLiftUp::Execute(){
	
}

bool MoveLiftUp::IsFinished(){
	return false; //never stop
}

void MoveLiftUp::End(){
	Robot::lift->SetLiftSpeed(0.0);
}

void MoveLiftUp::Interrupted(){
	End();
}

