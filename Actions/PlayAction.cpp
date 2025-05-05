#include "PlayAction.h"
#include "..\ApplicationManager.h"

PlayAction::PlayAction(ApplicationManager* pApp) : Action(pApp) {}

void PlayAction::ReadActionParameters() {}

void PlayAction::Execute()
{
    // Clear the drawing area
    pManager->GetOutput()->ClearDrawArea();
    // Clear the status bar
    pManager->GetOutput()->ClearStatusBar();
    // Clear the toolbar
    pManager->GetOutput()->ClearToolBar();

    // Set the interface mode to play
    pManager->GetOutput()->CreatePlayToolBar();
    pManager->GetOutput()->CreateStatusBar();

    // Print a message to indicate play mode
    pManager->GetOutput()->PrintMessage("Play Mode: Click to select a figure or click on the toolbar to perform actions.");
}