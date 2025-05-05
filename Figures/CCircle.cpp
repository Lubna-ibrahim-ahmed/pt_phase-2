#include "CCircle.h"
#include "CFigure.h"

CCircle::CCircle() : CFigure(GfxInfo()) {
	Center = { 0, 0 };
	length = { 0, 0 };
}

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
	double Radius = getDistance(Center, length);
	double dist = getDistance(Center, P);
	return dist <= Radius;
}
void CCircle::Draw(Output* pOut) const
{
	int Radius = getDistance(Center, length);
	pOut->DrawCir(Center,Radius, FigGfxInfo, IsSelected());
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << "CIRCLE" << " ";
	OutFile << ID << " " << Center.x << " " << Center.y << " " << length.x << " " << length.y << " ";
	OutFile << ColorToString(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		OutFile << ColorToString(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

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