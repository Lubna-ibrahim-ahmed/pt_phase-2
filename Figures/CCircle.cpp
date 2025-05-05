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
	double Radius = getDistance(Center, length);
	double dist = getDistance(Center, P);
	return dist <= Radius;
}
void CCircle::Draw(Output* pOut) const
{
	int Radius = getDistance(Center, length);
	pOut->DrawCir(Center,Radius, FigGfxInfo, IsSelected());
}