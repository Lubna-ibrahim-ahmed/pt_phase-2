#include "CTriangle.h"

CTriangle::CTriangle() : CFigure(GfxInfo()) {
	Corner1 = { 0, 0 };
	Corner2 = { 0, 0 };
	Corner3 = { 0, 0 };
}

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, IsSelected());
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
bool CTriangle::IsInside(Point P) const
{

	double A = 0.5 * abs(Corner1.x * (Corner2.y - Corner3.y) +
		Corner2.x * (Corner3.y - Corner1.y) +
		Corner3.x * (Corner1.y - Corner2.y));

	double A1 = 0.5 * abs(P.x * (Corner2.y - Corner3.y) +
		Corner2.x * (Corner3.y - P.y) +
		Corner3.x * (P.y - Corner2.y));

	double A2 = 0.5 * abs(Corner1.x * (P.y - Corner3.y) +
		P.x * (Corner3.y - Corner1.y) +
		Corner3.x * (Corner1.y - P.y));

	double A3 = 0.5 * abs(Corner1.x * (Corner2.y - P.y) +
		Corner2.x * (P.y - Corner1.y) +
		P.x * (Corner1.y - Corner2.y));


	return abs(A - (A1 + A2 + A3)) <= 0.001;
}
Point CTriangle::getmainposition() const
{
	Point centroid;
	centroid.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	centroid.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return centroid;
}
void CTriangle::setmainpos(Point p)
{

	Point oldCenter;
	oldCenter.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	oldCenter.y = (Corner1.y + Corner2.y + Corner3.y) / 3;


	int dx = p.x - oldCenter.x;
	int dy = p.y - oldCenter.y;

	// Apply shift
	Corner1.x += dx; Corner1.y += dy;
	Corner2.x += dx; Corner2.y += dy;
	Corner3.x += dx; Corner3.y += dy;
}


CFigure* CTriangle::figcopy() const {
	return new CTriangle(*this);
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
