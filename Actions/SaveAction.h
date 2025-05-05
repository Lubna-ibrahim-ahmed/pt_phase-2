#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H

#include "Action.h"

class SaveAction : public Action
{
private:
	string name;
public:
	SaveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
#endif