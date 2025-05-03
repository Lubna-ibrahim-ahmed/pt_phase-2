#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H

#include "Action.h"
class AddCircleAction : public Action
{
private:
	Point P1, P2; 
	int Radius;
	GfxInfo RectGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};









#endif

