#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>


class Lift : public frc::Subsystem
{
	private:
		std::shared_ptr<WPI_TalonSRX> liftmotor;

	public:
		Lift();
		void InitDefaultCommand() override;
		void SetLiftSpeed(double speed);
};