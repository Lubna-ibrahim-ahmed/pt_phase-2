#include "CTriangle.h"
CTriangle::CTriangle(Point P1, Point P2,Point P3 , GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(Corner1, Corner2,Corner3, FigGfxInfo, IsSelected());
}
CFigure* CTriangle::figcopy() const {
	return new CTriangle(*this);
} //ساعات بتبقي كدا
bool CTriangle::IsInside(Point P) const
{
	if ((P.x >= Corner1.x && P.x <= Corner2.x) && (P.y >= Corner1.x && P.y <= Corner2.y))
	{
		return true;
	}
	return false;
}
void CTriangle::MoveTo(Point newCenter) {


	Corner1.x = newCenter.x + this->CenterOffset1.x;
	Corner1.y = newCenter.y + this->CenterOffset1.y;
	Corner2.x = newCenter.x + this->CenterOffset2.x;
	Corner2.y = newCenter.y + this->CenterOffset2.y;
	Corner3.x = newCenter.x + this->CenterOffset3.x;
	Corner3.y = newCenter.y + this->CenterOffset3.y;
}

Point CTriangle::getcenter()
{
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return Center;
}

Point CTriangle::Centeroffset1()
{
	this->CenterOffset1.x = (Corner1.x - Center.x);
	this->CenterOffset1.y = (Corner1.y - Center.y);
	return this->CenterOffset1;
}
Point CTriangle::Centeroffset2()
{
	this->CenterOffset2.x = (Corner2.x - Center.x);
	this->CenterOffset2.y = (Corner2.y - Center.y);
	return this->CenterOffset2;
}
Point CTriangle::Centeroffset3()
{
	this->CenterOffset3.x = (Corner3.x - Center.x);
	this->CenterOffset3.y = (Corner3.y - Center.y);
	return this->CenterOffset3;
}
