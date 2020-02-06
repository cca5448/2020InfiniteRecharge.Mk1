#pragma once

#include "frc/commands/Command.h"

class ClawEmerHatchRelease: public frc::Command
{
	public:
		ClawEmerHatchRelease();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};