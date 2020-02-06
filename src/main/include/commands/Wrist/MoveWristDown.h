#pragma once

#include "frc/commands/Command.h"

class MoveWristDown: public frc::Command
{
    private:
        double m_TARGET_POS;
	public:
		MoveWristDown();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};