#include "AddSelectAction.h"
#include "..\Figures\CFigure.h"
#include"..\Figures\CCircle.h"
#include "..\ApplicationManager.h"



AddSelectAction::AddSelectAction(ApplicationManager* pApp) :Action(pApp)
{
}
void AddSelectAction::selectfigure(Point P)
{
	
	CFigure* clickedfigure = pManager->GetFigure(P.x, P.y);
	if (clickedfigure == nullptr)
	{
		pManager->unselectall(); //unselecting all the figures since the user presses in empty area
		pManager->UpdateInterface();
		return;
	}
	if (clickedfigure->IsSelected() == true)
	{
		clickedfigure->SetSelected(false);      //unselect the selected figure sice it was already selected 
	}
	else
	{
		clickedfigure->SetSelected(true);      //selecting another shape with the already selected shape so selecting multiple shapes
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
