#pragma once

#include "frc/commands/Command.h"

class MoveWristToPosition: public frc::Command
{
    private:
        double m_TARGET_POS;
	public:
		MoveWristToPosition(double pos);
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
};