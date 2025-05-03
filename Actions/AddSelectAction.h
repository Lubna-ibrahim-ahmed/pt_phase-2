#pragma once
// if we need to include
#include "Action.h"

class AddSelectAction : public Action
{
public:
	Point selected;
	void selectfigure(Point P);   //khadija
	AddSelectAction(ApplicationManager* pApp);
	void Execute() override;
	void ReadActionParameters();
	
};

