#pragma once

#include "frc/commands/Command.h"

class MoveWristStow: public frc::Command
{
    private:
        double m_TARGET_POS;
	public:
		MoveWristStow();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};