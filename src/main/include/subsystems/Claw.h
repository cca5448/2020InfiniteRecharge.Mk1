#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>

class Claw : public frc::Subsystem
{
	private:
        std::shared_ptr<frc::Servo> claw_motor;
        std::shared_ptr<frc::AnalogPotentiometer> claw_pot;

	public:
		Claw();
		void InitDefaultCommand() override;
		void StopClaw();
		void MoveClawToFullClose();
		void MoveClawToCaptureHatch();
		void MoveClawToFullOpen();
		void MoveClawToCaptureCargo();
		void MoveClawToEmerHatchRelease();
		double GetClawPotValue();
		double GetClawMotorSpeed();
};
