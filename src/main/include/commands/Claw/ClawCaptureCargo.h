#pragma once

#include "frc/commands/Command.h"

class ClawCaptureCargo: public frc::Command
{
	public:
		ClawCaptureCargo();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};