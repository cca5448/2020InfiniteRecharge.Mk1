#pragma once

#include "frc/commands/Command.h"

class TeleopMecanumDrive: public frc::Command
{
	public:
		TeleopMecanumDrive();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};