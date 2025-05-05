#include "CTriangle.h"

CTriangle::CTriangle() : CFigure(GfxInfo()) {
	Corner1 = { 0, 0 };
	Corner2 = { 0, 0 };
	Corner3 = { 0, 0 };
}

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

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "TRIANGLE" << " ";
	OutFile << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " ";
	OutFile << ColorToString(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		OutFile << ColorToString(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

void CTriangle::Load(ifstream& InFile)
{
	// Read the figure cooordinates
	InFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
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
		FigGfxInfo.FillClr = StringToColor(fillColor);
		FigGfxInfo.isFilled = true;
	}
}