#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddCircleAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center");


	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at Radius");

	
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action no errors
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CCircle* R = new CCircle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
