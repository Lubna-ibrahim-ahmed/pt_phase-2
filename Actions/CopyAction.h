
#include "Action.h"

class CopyAction : public Action
{
public:
    CopyAction(ApplicationManager* pApp); // constructor
    virtual void ReadActionParameters();   
    virtual void Execute();                // main logic
};
#pragma once
