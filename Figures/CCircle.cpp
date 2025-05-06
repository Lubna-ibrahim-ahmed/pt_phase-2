#include "CCircle.h"
#include "CFigure.h"
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	length = P2;
}
double getDistance(Point P1, Point P2)
	{
		return sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
	}
bool CCircle::IsInside(Point P) const
{
	return sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
};


void CCircle::Draw(Output* pOut) const
{
	int Radius = getDistance(Center, length);
	pOut->DrawCir(Center, Radius, FigGfxInfo, IsSelected());
};
CFigure* CCircle::figcopy() const {
	return new CCircle(*this);
};//ساعات بتبقي كدا

bool CCircle::IsInside(Point P) const
{
	int Radius = getDistance(Center, length);
	if (getDistance(P, Center) <= Radius)
	{
		return true;
	}
	return false;
}
void CCircle::MoveTo(Point newCenter) {
	int Radius = getDistance(Center, length);
	Center.x = newCenter.x;
	Center.y = newCenter.y;
	length.x = Center.x + Radius;
	length.y = Center.y + Radius;

void CCircle::Load(ifstream& InFile)
{
	InFile >> ID >> Center.x >> Center.y >> length.x >> length.y;
	string drawColor, fillColor;
	InFile >> drawColor;
	FigGfxInfo.DrawClr = StringToColor(drawColor);
	InFile >> fillColor;
	if (fillColor == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.FillClr = StringToColor(fillColor);
		FigGfxInfo.isFilled = true;
	}
}
Point CCircle::getmainposition() const
{
	return Center;
}
void CCircle::setmainpos(Point p) 
{
	int dx = p.x - Center.x;
	int dy = p.y - Center.y;

	Center.x += dx;
	Center.y += dy;

	length.x += dx;
	length.y += dy;
}
