#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include <fstream>

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp) {}

void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//get file name
	pOut->PrintMessage("Saving File Name: ");
	name = pIn->GetString(pOut) + ".txt";
	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//1- open file
	ofstream SFile(name);
	//2- call ApplicationManager::SaveAll()
	pManager->SaveAll(SFile);
	//3- close file
	SFile.close();
}