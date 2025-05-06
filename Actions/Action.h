#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

class ApplicationManager; //forward class declaration

//Base class for all possible actions
class Action
{
protected:
ApplicationManager *pManager;	//Actions need AppMngr to do their job
bool CutValidation = false; 
public:
Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

// Provide a public getter for pManager to resolve accessibility issues
ApplicationManager* GetApplicationManager() const { return pManager; }

//Reads parameters required for action to execute (code depends on action type)
virtual void ReadActionParameters() = 0;

//Execute action (code depends on action type)
virtual void Execute() = 0;
 bool GetCutValidation() { return CutValidation; } //ساعات بتبقي كدا
};

#endif