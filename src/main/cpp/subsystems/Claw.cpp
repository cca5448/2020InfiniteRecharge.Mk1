#include "subsystems/Claw.h"
#include "RobotMap.h"
#include <frc/smartdashboard/SmartDashboard.h>

Claw::Claw() : frc::Subsystem("Claw"){
	claw_motor.reset(new frc::Servo(CLAW_MOT));
    claw_pot.reset(new frc::AnalogPotentiometer(CLAW_POT,100,CLAW_POT_OFFSET));
}

void Claw::InitDefaultCommand(){
    StopClaw();
}

void Claw::StopClaw(){
    //Stop claw
    claw_motor->Set(.5);
}

double Claw::GetClawMotorSpeed(){
    claw_motor->Get();
}

void Claw::MoveClawToFullClose(){
    //Close claw until claw pot value is less than recorded close value
    static double pos = CLAW_POT_VAL_FC;
    if (claw_pot->Get() < pos) {
        claw_motor->Set((0.5 + CLAW_MOT_SPEED));
    } else {
        claw_motor->Set((0.5 - CLAW_MOT_SPEED));
    }
}

void Claw::MoveClawToCaptureHatch(){
    //Open the claw until claw pot value is at or more than recorded capture value
    static double pos = CLAW_POT_VAL_CH;
    if (claw_pot->Get() < pos) {
        claw_motor->Set((0.5 + CLAW_MOT_SPEED));
    } else {
        claw_motor->Set((0.5 - CLAW_MOT_SPEED));
    }
}

void Claw::MoveClawToFullOpen(){
    //Open the claw until claw pot value is at the max value
    static double pos = CLAW_POT_VAL_FO;
    if (claw_pot->Get() < pos) {
        claw_motor->Set((0.5 + CLAW_MOT_SPEED));
    } else {
        claw_motor->Set((0.5 - CLAW_MOT_SPEED));
    }
}

void Claw::MoveClawToCaptureCargo(){
    //Close the claw until claw pot value is at or below the recorded capture value
    static double pos = CLAW_POT_VAL_CC;
    if (claw_pot->Get() < pos) {
        claw_motor->Set((0.5 + CLAW_MOT_SPEED));
    } else {
        claw_motor->Set((0.5 - CLAW_MOT_SPEED));
    }
}

void Claw::MoveClawToEmerHatchRelease(){
    //Close the claw until claw pot value is at or less than recorded min value
    static double pos = CLAW_POT_VAL_EHR;
    if (claw_pot->Get() < pos) {
        claw_motor->Set((0.5 + CLAW_MOT_SPEED));
    } else {
        claw_motor->Set((0.5 - CLAW_MOT_SPEED));
    }
}

double Claw::GetClawPotValue(){
    //Read the analogpot value and return the corrected value
    return claw_pot->Get();
}
