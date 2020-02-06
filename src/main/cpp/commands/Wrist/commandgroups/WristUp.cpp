#include "commands/Wrist/commandgroups/WristUp.h"
#include "RobotMap.h"

//include all single commands needed for the group
#include "commands/Wrist/MoveWristToPosition.h"

WristUp::WristUp(){
    AddParallel(new MoveWristToPosition(WRIST_POS_UP));
}