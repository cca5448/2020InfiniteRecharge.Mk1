#include "commands/Wrist/commandgroups/WristDown.h"
#include "RobotMap.h"

//include all single commands needed for the group
#include "commands/Wrist/MoveWristToPosition.h"

WristDown::WristDown(){
    AddParallel(new MoveWristToPosition(WRIST_POS_DOWN));
}