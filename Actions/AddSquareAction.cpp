#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddSquareAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Center");


	pIn->GetPointClicked(P1.x, P1.y);


	SquareGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pIn->Getchar(pOut);

	pOut->ClearStatusBar();

}

//Execute the action no errors
void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CSquare* S = new CSquare(P1, SquareGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(S);
}
