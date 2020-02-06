#pragma once

#include "frc/commands/Command.h"

class ClawCaptureHatch: public frc::Command
{
	public:
		ClawCaptureHatch();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};