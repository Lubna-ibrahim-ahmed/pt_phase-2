#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include <fstream>

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp) {}

void LoadAction::ReadActionParameters()
{
    //Get a Pointer to the Input / Output Interfaces
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    //get file name
    pOut->PrintMessage("Loading File Name: ");
    name = pIn->GetString(pOut) + ".txt";
    pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
    // This action needs to read some parameters first
    ReadActionParameters();

    Output* pOut = pManager->GetOutput();

    // Open file
    ifstream LFile(name);

    if (!LFile.is_open()) {
        pOut->PrintMessage("Couldn't Open File.");
    }
    else {
        // Clear all figures using the public method
        pManager->clearFigures();

        // Call ApplicationManager::LoadAll()
        pManager->LoadAll(LFile);

        // Update interface
        pManager->UpdateInterface();

        // Close file
        LFile.close();
    }
}