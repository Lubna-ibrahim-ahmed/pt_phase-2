	#include "AddHexagonAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexagonAction::AddHexagonAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddHexagonAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center");


	pIn->GetPointClicked(P1.x, P1.y);


	HexaGfxInfo.FillClr = pIn->Getchar(pOut);


	HexaGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();

	pOut->ClearStatusBar();

}

//Execute the action no errors
void AddHexagonAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CHexagon* H = new CHexagon(P1, HexaGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(H);
}
