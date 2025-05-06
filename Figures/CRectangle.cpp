#include "CRectangle.h"
#include "CFigure.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


void CRectangle::Draw(Output* pOut) const
{   
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, IsSelected());
}
CFigure* CRectangle::figcopy() const {
	return new CRectangle(*this);
} //ساعات بتبقي كدا

bool CRectangle::IsInside(Point P) const
{
	if ((P.x >= Corner1.x && P.x <= Corner2.x) && (P.y >= Corner1.x && P.y <= Corner2.y))
	{
		return true;
	}
}

void CRectangle::MoveTo(Point newCenter) {
	int width = abs(Corner1.x - Corner2.x);
	int height = abs(Corner1.y - Corner2.y);

	Corner1.x = newCenter.x - width / 2;
	Corner1.y = newCenter.y - height / 2;
	Corner2.x = newCenter.x + width / 2;
	Corner2.y = newCenter.y + height / 2;
}