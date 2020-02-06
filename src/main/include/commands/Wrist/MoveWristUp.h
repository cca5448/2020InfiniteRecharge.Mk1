#pragma once

#include "frc/commands/Command.h"

class MoveWristUp: public frc::Command
{
    private:
        double m_TARGET_POS;
	public:
		MoveWristUp();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};