#include "AddSelectAction.h"
#include "..\Figures\CFigure.h"
#include"..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include"..\GUI/Input.h"
#include"..\GUI/Output.h"


AddSelectAction::AddSelectAction(ApplicationManager* pApp) :Action(pApp)
{
}
void AddSelectAction::selectfigure(Point point)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* clickedfigure = pManager->GetFigure(point.x, point.y);
	if (clickedfigure == nullptr)
	{
		pManager->unselectall(); //unselecting all the figures since the user presses in empty area
		pManager->UpdateInterface();
		pOut->PrintMessage("Figures unselected");
		return;
	}
	if (clickedfigure->IsSelected() == true)
	{
		clickedfigure->SetSelected(false);      //unselect the selected figure sice it was already selected 
		pOut->PrintMessage("Figure unselected");
	}
	else
	{
		clickedfigure->SetSelected(true);      //selecting another shape with the already selected shape so selecting multiple shapes
        
        pManager->SetSelectedFigure(clickedfigure); // Use the pManager instance to call the non-static member function
        pOut->PrintMessage("Figure selected");

	}

	pManager->UpdateInterface();


}
void AddSelectAction::ReadActionParameters()
{ 
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click on a shape to select it or unselect it");
	pIn->GetPointClicked(selected.x, selected.y);
	
}
void AddSelectAction::Execute()
{
	ReadActionParameters();
	selectfigure(selected);
	pManager->UpdateInterface();
	pManager->PrintFigureInfo();
}
