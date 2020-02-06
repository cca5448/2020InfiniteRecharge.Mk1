#include "commands/Wrist/commandgroups/StowWrist.h"
#include "RobotMap.h"

//include all single commands needed for the group
#include "commands/Wrist/MoveWristToPosition.h"

StowWrist::StowWrist(){
    AddParallel(new MoveWristToPosition(WRIST_POS_STOW));
}