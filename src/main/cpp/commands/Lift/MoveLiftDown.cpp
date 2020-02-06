#include "commands/Lift/MoveLiftDown.h"
#include "Robot.h"
#include "RobotMap.h"

MoveLiftDown::MoveLiftDown(){
	Requires(Robot::lift.get());
}

void MoveLiftDown::Initialize(){
    printf("Lift: Move Down\n");
	Robot::lift->SetLiftSpeed(LIFT_SPEED);
}

void MoveLiftDown::Execute(){
	
}

bool MoveLiftDown::IsFinished(){
	return false; //never stop
}

void MoveLiftDown::End(){
	Robot::lift->SetLiftSpeed(0.0);
}

void MoveLiftDown::Interrupted(){
	End();
}

