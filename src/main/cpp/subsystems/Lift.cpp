/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/Lift.h"

Lift::Lift() {
  // Implementation of subsystem constructor goes here.
	liftmotor1 = std::make_shared<WPI_TalonSRX>(LIFT_MOT_1);
  liftmotor2 = std::make_shared<WPI_TalonSRX>(LIFT_MOT_2);
  //liftmotor1 = new TalonSRX(LIFT_MOT_1);
  //liftmotor2 = new TalonSRX(LIFT_MOT_2);
  
  //factory reset hardware to prevent unexpected behaviors
  liftmotor1->ConfigFactoryDefault();
  liftmotor2->ConfigFactoryDefault();

  //make liftmotor2 a follower to liftmotor1
  liftmotor2->Follow(*liftmotor1);

  //make sure controllers are configured for brake mode
  liftmotor1->SetNeutralMode(NeutralMode::Brake);
  liftmotor2->SetNeutralMode(NeutralMode::Brake);

  //configure limit switches
  liftmotor1->ConfigForwardLimitSwitchSource(
      LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,
      LIFT_LIMIT_TIMEOUT
  );
  liftmotor1->ConfigReverseLimitSwitchSource(
      LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,
      LIFT_LIMIT_TIMEOUT
  );
/*
  liftmotor2->ConfigForwardLimitSwitchSource(
      LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,
      30
  );
  liftmotor2->ConfigReverseLimitSwitchSource(
      LimitSwitchSource::LimitSwitchSource_FeedbackConnector,
      LimitSwitchNormal::LimitSwitchNormal_NormallyOpen,
      30
  );
*/
}

void Lift::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

bool Lift::isFwdLimitReached() { // Check if the fwd limit switch has been reached
  int isFwdLimitSwitchClosed = liftmotor1->GetSensorCollection().IsFwdLimitSwitchClosed();
  return isFwdLimitSwitchClosed;
}

bool Lift::isRevLimitReached() { // Check if the rev limit switch has been reached
  int isRevLimitSwitchClosed = liftmotor1->GetSensorCollection().IsRevLimitSwitchClosed();
  return isRevLimitSwitchClosed;
}

void Lift::OverrideLimits(bool force) { //Override the limit switches
  liftmotor1->OverrideLimitSwitchesEnable(!!force);
}

void Lift::runLiftUp(bool force = false) { //Run the lift up
  OverrideLimits(force);
  liftmotor1->Set(ControlMode::PercentOutput, LIFT_SPEED);
}

void Lift::runLiftDown(bool force = false) { //Run the lift down
  OverrideLimits(force);
  liftmotor1->Set(ControlMode::PercentOutput, LIFT_SPEED * -1.0);
}

void Lift::stopLift() {
  liftmotor1->StopMotor();
}