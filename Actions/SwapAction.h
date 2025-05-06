#pragma once
#include "Action.h"
class SwapAction :public Action
{
public:
	SwapAction(ApplicationManager* App);
	void ReadActionParameters() override;
	void Execute() override;
};

