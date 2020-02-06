#pragma once

#include "frc/commands/Command.h"

class ClawFullClose: public frc::Command
{
	public:
		ClawFullClose();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};