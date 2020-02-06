#include "RobotMap.h"
#include "subsystems/Drivetrain.h"

#include "commands/Drivetrain/TeleopMecanumDrive.h"

Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain"){
	lf = std::make_shared<WPI_VictorSPX>(DRIVE_MOT_LF);
	lr = std::make_shared<WPI_VictorSPX>(DRIVE_MOT_LR);
	rf = std::make_shared<WPI_VictorSPX>(DRIVE_MOT_RF);
	rr = std::make_shared<WPI_VictorSPX>(DRIVE_MOT_RR);

	robotDrive = std::make_shared<MecanumDrive>(*lf, *lr, *rf, *rr);
	robotDrive->SetExpiration(0.1);

	//invert motors
	//rf->SetInverted(true);
	//rr->SetInverted(true);
	//lf->SetInverted(true);
	//lr->SetInverted(true);

	try {
		/***********************************************************************
		 * navX-MXP:
		 * - Communication via RoboRIO MXP (SPI, I2C, TTL UART) and USB.
		 * - See http://navx-mxp.kauailabs.com/guidance/selecting-an-interface.
		 *
		 * Multiple navX-model devices on a single robot are supported.
		 ************************************************************************/
		gyro = new AHRS(SPI::Port::kMXP);
	} catch (std::exception& ex ) {
		std::string err_string = "Error instantiating navX MXP:  ";
		err_string += ex.what();
		DriverStation::ReportError(err_string.c_str());
	}

}

void Drivetrain::InitDefaultCommand(){
	SetDefaultCommand(new TeleopMecanumDrive());
}

void Drivetrain::DriveMecanum(double throttle, double strafe, double turn){
	if (DRIVE_FIELD_CENTRIC){
		//field centric drive
		robotDrive->DriveCartesian(strafe, throttle, turn, GetGyroAngle());
		//robotDrive->DriveCartesian(strafe, -throttle, turn);
	} else {
		//not field centric
		robotDrive->DriveCartesian(strafe, throttle, turn);
	}
}

void Drivetrain::DriveMecanumStop(){
	robotDrive->DriveCartesian(0.0, 0.0, 0.0);
}

double Drivetrain::GetGyroAngle(){
	return gyro->GetAngle();
}