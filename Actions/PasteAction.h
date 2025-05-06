#pragma once


#include "Action.h"
class PasteAction : public Action {
private:
    Point P; // Clicked point
public:
    PasteAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};
