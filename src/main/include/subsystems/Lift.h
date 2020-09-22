/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"

class Lift : public frc2::SubsystemBase {
 public:
  Lift();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  bool isFwdLimitReached();
  bool isRevLimitReached();
  void OverrideLimits(bool force);
  void runLiftUp(bool force);
  void runLiftDown(bool force);
  void stopLift();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  std::shared_ptr<WPI_TalonSRX> liftmotor1;
  std::shared_ptr<WPI_TalonSRX> liftmotor2;
  //TalonSRX *liftmotor1;
  //TalonSRX *liftmotor2;
};
