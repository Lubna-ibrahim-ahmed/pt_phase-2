#include "CSquare.h"
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;


}
void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSq(Center, FigGfxInfo, IsSelected());
}
CFigure* CSquare::figcopy() const {
	return new CSquare(*this);
} //ساعات بتبقي كدا
bool CSquare::IsInside(Point P) const
{
	return (P.x >= Center.x - 100 && P.x <= Center.x + 100 &&
		P.y >= Center.y - 100 && P.y <= Center.y + 100);
}
void CSquare::MoveTo(Point newCenter) {

	Center = newCenter;

}
void CSquare::Load(ifstream& InFile)
{
	InFile >> ID >> Center.x >> Center.y;
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
bool CSquare::IsInside(Point point) const
{
	//const int side = 100;
	double halfside = 50;  //ask lobna law el side length 100 fe3lan wala
	double left = Center.x - halfside;
	double bottom = Center.y + halfside;
	double right = Center.x + halfside;
	double top = Center.y - halfside;
	if (point.x >= left && point.x <= right && point.y >= top && point.y <= bottom)
	{
		return true;
	}
	else
		return false;
		
}
Point CSquare::getmainposition() const
{
	return Center;
}
void CSquare::setmainpos(Point p) 
{
	Center = p;
}
