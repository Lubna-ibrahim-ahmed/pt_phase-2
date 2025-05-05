#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
		pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetString(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}
// function to get color from user
    color Input::Getchar(Output* pO) const
{
		color inputcolor;
	    char Key;
		while (1)
		{
			pO->PrintMessage("Choose a color: enter ""R"" (red) , enter ""B"" (black), enter ""Y"" (yellow) , enter ""O"" (orange) ,enter ""G"" (green) , enter ""L"" (blue) ");
			pWind->WaitKeyPress(Key);
			if (Key == 'r' || Key == 'R')
				inputcolor = RED;
			else if (Key == 'B' || Key == 'b')
				inputcolor = BLACK;
			else if (Key == 'Y' || Key == 'y')
				inputcolor = YELLOW;
			else if (Key == 'O' || Key == 'o')
				inputcolor = ORANGE;
			else if (Key == 'G' || Key == 'g')
				inputcolor = GREEN;
			else if (Key == 'l' || Key == 'L')
				inputcolor = BLUE;

              return inputcolor;
		} 
}


//This function reads the position where the user clicks to determine the desired action
	ActionType Input::GetUserAction() const
	{	
		int x,y;
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

		if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
		{
			//[1] If user clicks on the Toolbar
			if ( y >= 0 && y < UI.ToolBarHeight)

			{	
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_SELECT: return TO_SELECT;
				case ITM_RECT: return DRAW_RECT;
				case ITM_SQR: return DRAW_SQUARE;
				case ITM_TRI: return DRAW_TRIANGLE;
				case ITM_HEXA: return DRAW_HEXAGON;
				case ITM_CIR: return DRAW_CIRCLE;
				case ITM_DELETE: return TO_DELETE;
				case ITM_COPY: return TO_COPY;
				case ITM_SWAP: return TO_SWAP;
				case ITM_CLEAR: return TO_CLEAR;
				case ITM_ROT: return TO_ROTATE;
				case ITM_CUT: return TO_CUT;
				case ITM_PASTE: return TO_PASTE;
				case ITM_SAVE: return TO_SAVE;
				case ITM_LOAD: return TO_LOAD;
				case ITM_REDO: return REDO;
				case ITM_UNDO: return UNDO;
				case ITM_PLAYMODE: return TO_PLAY;
				case ITM_EXIT: return EXIT;
				
				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}

			//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return DRAWING_AREA;	
			}
		
			//[3] User clicks on the status bar
			return STATUS;
		}
		else	//GUI is in PLAY mode
		{
			if (y >= 0 && y < UI.ToolBarHeight)
			{
				int ClickedItemOrder = (x / UI.MenuItemWidth);
				

				switch (ClickedItemOrder)
				{
				  case ITM_MISSING: return MISSING;
			      case ITM_MATCH: return MATCH;
			      case ITM_DRAWMODE: return TO_DRAW;

				  default: return EMPTY;	
				}
			}
			//[2] User clicks on the drawing area
			if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			{
				return DRAWING_AREA;
			}
			//[3] User clicks on the status bar
			return STATUS;
		}
	  
			///TODO:_____done
			//perform checks similar to Draw mode checks above
			//and return the correspoding action
			return TO_PLAY;	//just for now. This should be updated
	}	
	void Input::FlushMouseQueue() const
	{
		pWind->FlushMouseQueue();	//Flush key queue
	}


	/////////////////////////////////
	
	Input::~Input()
	{
	}
