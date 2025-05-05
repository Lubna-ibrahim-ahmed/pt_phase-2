#pragma once
#include "Action.h"
class AddMatchAction :public Action
{
public:
	Point selected;
	AddMatchAction(ApplicationManager* pApp);
	void Execute() override;
	void ReadActionParameters();
	void AddMatchAction::selectfig(Point point);

};

