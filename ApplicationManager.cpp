#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddHexagonAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddSelectAction.h"
#include "Figures/CFigure.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
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



		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
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

	return NULL;
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
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
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
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
