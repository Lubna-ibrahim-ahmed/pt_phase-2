#include "ClearAllAction.h"
#include "..\ApplicationManager.h"

ClearAllAction::ClearAllAction(ApplicationManager* pApp) : Action(pApp) {}

void ClearAllAction::ReadActionParameters() {}

void ClearAllAction::Execute()
{
	// Clear all figures
	pManager->clearFigures();
	// Clear the drawing area
	pManager->GetOutput()->ClearDrawArea();
	// Print a message to inform the user
	pManager->GetOutput()->PrintMessage("All figures cleared.");
	// Update the interface
	pManager->UpdateInterface();
}