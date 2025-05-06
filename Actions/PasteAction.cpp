#include "PasteAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include<iostream>
#include "../Figures/CFigure.h"

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp) {}

void PasteAction::ReadActionParameters() {
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();


    pIn->GetPointClicked(P.x, P.y);
    pOut->ClearStatusBar();
}

void PasteAction::Execute() {
    CFigure* clipboardFig = pManager->GetClipboard();
    if (!clipboardFig) {
        pManager->GetOutput()->PrintMessage("Clipboard is empty!");
        return;
    }

    // 1. Read paste location
    ReadActionParameters();

    // 2. Create and add the pasted figure
    CFigure* newFig = clipboardFig->figcopy();
    newFig->MoveTo(P); // Move to clicked position
    pManager->AddFigure(newFig);

    // 3. Delete the original cut figure (if it exists)
    CFigure* cutFigure = pManager->GetCutFigure();
    if (cutFigure) {
        pManager->DeleteFigure(cutFigure); // Delete the original
        pManager->SetCutFigure(nullptr); // Reset tracker
        pManager->UpdateInterface(); // Refresh UI
    }

    pManager->GetOutput()->PrintMessage("Figure pasted. Original deleted.");
}
