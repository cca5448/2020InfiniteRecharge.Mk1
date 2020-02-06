#pragma once

#include "frc/commands/Command.h"

class MoveLiftDown: public frc::Command
{
	public:
		MoveLiftDown();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};