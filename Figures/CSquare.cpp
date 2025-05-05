#include "CSquare.h"

CSquare::CSquare() : CFigure(GfxInfo()) {
	Center = { 0, 0 };
}

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSq(Center, FigGfxInfo, IsSelected());
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQUARE" << " ";
	OutFile << ID << " " << Center.x << " " << Center.y << " ";
	OutFile << ColorToString(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		OutFile << ColorToString(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
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