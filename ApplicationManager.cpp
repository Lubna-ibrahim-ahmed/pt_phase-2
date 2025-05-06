#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddHexagonAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddSelectAction.h"
#include "Actions/SaveAction.h"
#include "Actions/LoadAction.h"
#include "Figures/CFigure.h"
#include "Figures/CCircle.h"
#include "Figures/CRectangle.h"
#include "Figures/CTriangle.h"
#include "Figures/CHexagon.h"
#include "Figures/CSquare.h"
#include "Actions/ClearAllAction.h"
#include "Actions/PlayAction.h"
#include <fstream>
#include "Actions/SwapAction.h"
#include "Actions\AddMatchAction.h"
#include "Actions\CopyAction.h"
#include "Actions\PasteAction.h"
#include "Actions\CutAction.h"
#include "Actions\DeleteAction.h"
#include"GUI/Output.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	CutFigure = nullptr;
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	

	SelectedFigure = nullptr;
	Clipboard = nullptr;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::SaveAll(ofstream& OutFile) {
	OutFile << FigCount << endl; // Save the number of figures

	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Save(OutFile); // Call Save for each figure
	}
}

void ApplicationManager::LoadAll(ifstream& InFile) {
	clearFigures(); // Clear existing figures before loading new ones

	int count;
	InFile >> count; // Read the number of figures

	for (int i = 0; i < count; i++) {
		string figType;
		InFile >> figType;

		CFigure* pFig = nullptr;
		
		if (figType == "RECTANGLE") {
			pFig = new CRectangle();
		}
		else if (figType == "CIRCLE") {
			pFig = new CCircle();
		}
		else if (figType == "TRIANGLE") {
			pFig = new CTriangle();
		}
		else if (figType == "HEXAGON") {
			pFig = new CHexagon();
		}
		else if (figType == "SQUARE") {
			pFig = new CSquare();
		}
		else {
			continue; // Skip unknown figure types
		}
		
		if (pFig) {
			pFig->Load(InFile);
			AddFigure(pFig); // Add the loaded figure to the list
		}
	}

	UpdateInterface(); // Update the interface after loading
}

void ApplicationManager::clearFigures() {
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i]; // Delete each figure
		FigList[i] = nullptr; // Set the pointer to null
	}
	FigCount = 0; // Reset the figure count
	UpdateInterface(); // Update the interface
}

////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{   
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_CIRCLE:
			pAct = new AddCircleAction(this);
			break;
		case DRAW_SQUARE:
			pAct = new AddSquareAction(this);
			break;
		case DRAW_HEXAGON:
			pAct = new AddHexagonAction(this);
			break;
		case DRAW_TRIANGLE:
			pAct = new AddTriAction(this);
			break;
		case TO_SELECT:
			pAct = new AddSelectAction(this);
			break;
		case TO_SAVE:
			pAct = new SaveAction(this);
			break;
		case TO_LOAD:
			pAct = new LoadAction(this);
			break;
		case TO_CLEAR:
			pAct = new ClearAllAction(this);
			break;
		case TO_PLAY:
			pAct = new PlayAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
		case TO_SWAP:
			pAct = new SwapAction(this);
			break;
			break;
		case MISSING:
			break;

		case MATCH:
			pAct = new AddMatchAction(this);
			break;
		
		case TO_COPY:
			pAct = new CopyAction(this);
			break;

		case TO_PASTE:
			pAct = new PasteAction(this);
			break;

		case TO_CUT:
			pAct = new CutAction(this);
			break;

		case TO_DELETE:
			pAct = new DeleteAction(this);
			break;
	}

	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	Point P;
	P.x = x;
	P.y = y;

	for (int i = FigCount - 1; i >= 0; i--)    //FigCount-1 since the FigCount array starts from 0
	{
		if (FigList[i] != NULL && FigList[i]->IsInside(P) == true)
		{
			return FigList[i];
		}
	}
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return nullptr;
}

void ApplicationManager::PrintFigureInfo()
{
	int rectcount = 0, tricount = 0, hexcount = 0, circlecount = 0, selectedcount = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true)
		{
			selectedcount++;       ////lesa mesh metkamela

		}
	}
}

void ApplicationManager::unselectall()
{
	for (int i = FigCount - 1; i >= 0; i--)  //unselecting all the selected figures since the user pressed in an empty region, in a function
	{
		FigList[i]->SetSelected(false);
	}
	UpdateInterface();
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();	//First clear the drawing area

	for(int i=0; i<FigCount; i++)
		
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
int ApplicationManager::getfigurecount()
{
	return FigCount;
}
CFigure* ApplicationManager::getfiglistindex(int i) const
{
	if (i >= 0 && i <= FigCount)
	{
		return FigList[i];
	}
	else
		return nullptr;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

void ApplicationManager::SetClipboard(CFigure * fig) {
	if (Clipboard) {
		delete Clipboard;
		Clipboard = nullptr;
	}

		if (fig) {
		Clipboard = fig->figcopy(); // Deep copy

	}
	
}
void ApplicationManager::SetSelectedFigure(CFigure * pFig) {
		// Select new figure
		SelectedFigure = pFig;


}
CFigure * ApplicationManager::GetSelectedFigure() const {
	return SelectedFigure;
	
}

CFigure * ApplicationManager::GetClipboard() const {
	return Clipboard;
}
void ApplicationManager::DeleteFigure(CFigure * pFig) {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] == pFig) {
			delete FigList[i];
			
			for (int j = i; j < FigCount - 1; j++) {
				FigList[j] = FigList[j + 1];
			}
			FigList[--FigCount] = nullptr;
			break;
		}
	}
}