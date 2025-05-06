#include "CHexagon.h"

CHexagon::CHexagon() : CFigure(GfxInfo()) {
	Center = { 0, 0 };
}


CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}
void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHex(Center,FigGfxInfo, IsSelected());
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "HEXAGON" << " ";
	OutFile << ID << " " << Center.x << " " << Center.y << " ";
	OutFile << ColorToString(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		OutFile << ColorToString(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

void CHexagon::Load(ifstream& InFile)
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
bool CHexagon::IsInside(Point P) const
{
	double distx = P.x - Center.x;
	double disty = P.y - Center.y;
	double distance = sqrt(pow(distx, 2) + pow(disty, 2));
	return distance <= 100;
}
Point CHexagon::getmainposition() const
{
	return Center;
}
void CHexagon::setmainpos(Point p)
{
	int dx = p.x - Center.x;
	int dy = p.y - Center.y;

	Center.x += dx;
	Center.y += dy;

}
