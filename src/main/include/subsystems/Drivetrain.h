#pragma once

#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <AHRS.h>
#include <frc/drive/MecanumDrive.h>


class Drivetrain : public frc::Subsystem
{
	private:
		std::shared_ptr<WPI_VictorSPX> lf;
		std::shared_ptr<WPI_VictorSPX> rf;
		std::shared_ptr<WPI_VictorSPX> lr;
		std::shared_ptr<WPI_VictorSPX> rr;
		std::shared_ptr<MecanumDrive> robotDrive;
		AHRS* gyro;

	public:
		Drivetrain();
		void InitDefaultCommand() override;
		void DriveMecanum(double throttle = 0.0, double strafe = 0.0, double turn = 0.0);
		void DriveMecanumStop();
		double GetGyroAngle();
};