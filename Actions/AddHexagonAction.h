#pragma once
#ifndef ADD_HEXA_ACTION_H
#define ADD_HEXA_ACTION_H
#include "Action.h"

class AddHexagonAction : public Action
{
private:
	Point P1;
	GfxInfo RectGfxInfo;
public:
	AddHexagonAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	
	virtual void Execute();


};

#endif