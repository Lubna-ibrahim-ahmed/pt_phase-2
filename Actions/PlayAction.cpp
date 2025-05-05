#include "PlayAction.h"
#include "..\ApplicationManager.h"

PlayAction::PlayAction(ApplicationManager* pApp) : Action(pApp) {}

void PlayAction::ReadActionParameters() {}

void PlayAction::Execute()
{
    // Set the interface mode to play
    pManager->GetOutput()->CreatePlayToolBar();
    pManager->GetOutput()->CreateStatusBar();
    // Print a message to indicate play mode
    pManager->GetOutput()->PrintMessage("Play Mode: Click to select a figure or click on the toolbar to perform actions.");
}