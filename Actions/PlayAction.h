#pragma once

#include "Action.h"

class PlayAction : public Action
{
public:
	PlayAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};