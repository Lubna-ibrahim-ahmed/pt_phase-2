#pragma once
#include "SwapAction.h"
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
SwapAction::SwapAction(ApplicationManager* App):Action(App)
{
}
void SwapAction:: ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("click at the first shape");
	Point P1;
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("click on the first shape");
	Point P2;
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->ClearStatusBar();
}
void SwapAction::Execute()
{
	CFigure* selectedf[2];
	int c = 0;
	for (int i = 0; i < pManager->getfigurecount(); i++)
	{
		CFigure* fig = pManager->getfiglistindex(i);
		if (fig!=nullptr && fig->IsSelected() == true)
		{
			if (c < 2)
			{
				selectedf[c++] = fig;
			}
			if (c == 2)
			{
				break;
			}
		}
	}
	if (c < 0 || c > 2)
	{
		pManager->GetOutput()->PrintMessage("Please select 2 figures to swap them");
		return;
	}
	Point pos1 = selectedf[0]->getmainposition();
	Point pos2 = selectedf[1]->getmainposition();
	selectedf[0]->setmainpos(pos2);
	selectedf[1]->setmainpos(pos1);
	pManager->UpdateInterface();

}