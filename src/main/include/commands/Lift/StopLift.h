#pragma once

#include "frc/commands/Command.h"

class StopLift: public frc::Command
{
	public:
		StopLift();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};