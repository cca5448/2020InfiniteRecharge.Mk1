#pragma once

#include "frc/commands/Command.h"

class MoveWristUpUp: public frc::Command
{
    private:
        double m_TARGET_POS;
	public:
		MoveWristUpUp();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};