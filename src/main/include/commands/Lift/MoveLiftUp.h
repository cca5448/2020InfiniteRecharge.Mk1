#pragma once

#include "frc/commands/Command.h"

class MoveLiftUp: public frc::Command
{
	public:
		MoveLiftUp();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};