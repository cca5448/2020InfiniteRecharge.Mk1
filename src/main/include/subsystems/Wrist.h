#pragma once

#include <frc/WPILib.h>
#include <frc/commands/PIDSubsystem.h>
#include <ctre/Phoenix.h>

class Wrist : public frc::PIDSubsystem
{
    public:
		std::shared_ptr<WPI_TalonSRX> Wrist_Motor;
		std::shared_ptr<frc::AnalogPotentiometer> Wrist_Pot;

		Wrist();
		void InitDefaultCommand() override;
		double ReturnPIDInput();
		int GetScaledPIDInput();
		void UsePIDOutput(double output);
};
