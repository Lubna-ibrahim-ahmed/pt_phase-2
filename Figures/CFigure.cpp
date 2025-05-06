#include "CFigure.h"
#include "..\Actions\AddSelectAction.h"


CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


color CFigure::StringToColor(string str) {
    if (str == "BLACK") return BLACK;
    if (str == "RED") return RED;
    if (str == "BLUE") return BLUE;
    if (str == "GREEN") return GREEN;
    if (str == "WHITE") return WHITE;
    return BLACK; // Default color
}
 color CFigure::GetDrawColor() {
    return FigGfxInfo.FillClr;
}
