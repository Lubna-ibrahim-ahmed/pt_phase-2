#include "AddMatchAction.h"
#include "..\Figures\CFigure.h"
#include"..\Figures\CCircle.h"
#include "..\ApplicationManager.h"



AddMatchAction::AddMatchAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddMatchAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	int selectedCount = 0;
	bool bothSelected = false;
	CFigure* selectedList[2];
   
	while (selectedCount <2) {
		pOut->PrintMessage("Click on a shape to select it");
	    pIn->GetPointClicked(selected.x, selected.y);
		 CFigure* clickedfigure = pManager->GetFigure(selected.x, selected.y);

		if (clickedfigure == nullptr)
		{
			pManager->unselectall(); //unselecting all the figures since the user presses in empty area
			pManager->UpdateInterface();
			pOut->PrintMessage("Figures unselected");
			continue;
		}
		if (clickedfigure->IsSelected() == true)
		{
			clickedfigure->SetSelected(false);      //unselect the selected figure sice it was already selected 
			pOut->PrintMessage("Figure unselected");
		}
		else
		{
			clickedfigure->SetSelected(true);      //selecting another shape with the already selected shape so selecting multiple shapes
			pOut->PrintMessage("Figure selected");
			selectedList[selectedCount] = clickedfigure;
			selectedCount++;
			
		}

		pManager->UpdateInterface();
		if (selectedCount == 2) {

			break;
		}
		
	}
	if ((selectedList[0] != nullptr && selectedList[1] != nullptr)
		&&(selectedList[0]->getID() == selectedList[1]->getID())
		&&(selectedList[0]->GetDrawColor() == selectedList[1]->GetDrawColor()))
	{

		pOut->PrintMessage("Figures match");
		selectedList[0]->SetSelected(false);
		selectedList[1]->SetSelected(false);

	}else 
	{
		pOut->PrintMessage("Figures do not match");
		selectedList[0]->SetSelected(false);
		selectedList[1]->SetSelected(false);
	}
}

void AddMatchAction::Execute()
{
	ReadActionParameters();
	
}
