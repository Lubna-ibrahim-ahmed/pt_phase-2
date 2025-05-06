#include "../ApplicationManager.h"
#include "../Figures\CFigure.h"
#include "CopyAction.h"
#include "Action.h"

CopyAction::CopyAction(ApplicationManager* pApp) :Action(pApp) {}

void CopyAction::ReadActionParameters() {}
void CopyAction::Execute() {
    CFigure* selected = pManager->GetSelectedFigure();
    if (selected != nullptr) {
        CFigure* copy = selected->figcopy();
        pManager->SetClipboard(copy);
        pManager->GetOutput()->PrintMessage("Copied to clipboard.");
    }
    else {
        pManager->GetOutput()->PrintMessage("No figure selected!");
    }
}
