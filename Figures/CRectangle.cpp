#include "CRectangle.h"
#include "CFigure.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

bool CRectangle::IsInside(Point P) const
{
	double left = min(Corner1.x, Corner2.x);
	double right = max(Corner1.x, Corner2.x);
	double top = min(Corner1.y, Corner2.y);
	double bottom = max(Corner1.y, Corner2.y);
	if ((P.x >= left && P.x <= right) && (P.y >= top && P.y <= bottom))
	{
		return true;
	}
	else
		return false;
}

void CRectangle::Draw(Output* pOut) const
{   
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, IsSelected());
}
