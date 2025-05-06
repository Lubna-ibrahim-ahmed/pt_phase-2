#include "CutAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "../Figures/CFigure.h"

CutAction::CutAction(ApplicationManager* pApp) : Action(pApp) {}

void CutAction::ReadActionParameters() {

}

void CutAction::Execute() {
    Output* pOut = pManager->GetOutput();
    CFigure* selectedFig = pManager->GetSelectedFigure();

    if (selectedFig) {
        // 1. Copy the figure to clipboard
        CFigure* cutCopy = selectedFig->figcopy();
        pManager->SetClipboard(cutCopy);

        // 2. Track the original cut figure (DO NOT DELETE IT YET)
        pManager->SetCutFigure(selectedFig); // Store in ApplicationManager

        // 3. Visual feedback: Turn the figure gray
        selectedFig->ChngDrawClr(GRAY);
        pManager->SetSelectedFigure(nullptr); // Deselect
        pManager->UpdateInterface(); // Refresh UI

        pOut->PrintMessage("Figure cut. Paste to finalize deletion.");
    }
    else {
        pOut->PrintMessage("No figure selected to cut!");
    }
}
