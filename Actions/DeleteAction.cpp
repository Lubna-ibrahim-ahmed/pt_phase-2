#include "DeleteAction.h"
#include "../ApplicationManager.h"
#include "../Figures/CFigure.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp) {}

void DeleteAction::Execute() {
    CFigure* selected = pManager->GetSelectedFigure();

    if (selected) {
        pManager->DeleteFigure(selected); // Delete from FigList
        pManager->SetSelectedFigure(nullptr); // Clear selection
        pManager->UpdateInterface(); // Refresh UI
        pManager->GetOutput()->PrintMessage("Figure deleted.");
    }
    else {
        pManager->GetOutput()->PrintMessage("No figure selected to delete!");
    }
}