#pragma once

#include "frc/commands/Command.h"

class ClawFullOpen: public frc::Command
{
	public:
		ClawFullOpen();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};