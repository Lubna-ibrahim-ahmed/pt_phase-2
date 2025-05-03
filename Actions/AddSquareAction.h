#pragma once
#ifndef ADD_SQUARE_ACTION_H
#define ADD_SQUARE_ACTION_H
#include "Action.h"

class AddSquareAction : public Action
{
private:
	Point P1;
	GfxInfo RectGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();


	virtual void Execute();


};

#endif