#include "CRectangle.h"
#include "CFigure.h"

CRectangle::CRectangle() : CFigure(GfxInfo()) {
	Corner1 = { 0, 0 };
	Corner2 = { 0, 0 };
}

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

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << "RECTANGLE" << " ";

	OutFile << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";

	OutFile << ColorToString(FigGfxInfo.DrawClr) << " ";

	if (FigGfxInfo.isFilled)
		OutFile << ColorToString(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

void CRectangle::Load(ifstream& InFile)
{
	// Read the figure cooordinates
	InFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;

	string drawColor, fillColor;

	// Read the drawing color
	InFile >> drawColor;
	FigGfxInfo.DrawClr = StringToColor(drawColor);

	// Read the filling color
	InFile >> fillColor;
	if (fillColor == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = StringToColor(fillColor);
	}
}