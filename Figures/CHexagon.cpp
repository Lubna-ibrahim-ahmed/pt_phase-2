#include "CHexagon.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	

}
void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHex(Center,FigGfxInfo, IsSelected());
}
CFigure* CHexagon::figcopy() const {
	return new CHexagon(*this);
} //ساعات بتبقي كدا

bool CHexagon::IsInside(Point P) const
{

	float dx = P.x - Center.x;
	float dy = P.y - Center.y;

	float distanceSquared = dx * dx + dy * dy;
	float radius = 100;

	return distanceSquared <= radius * radius;
}
void CHexagon::MoveTo(Point newCenter)
{
	Center.x = newCenter.x;
	Center.y = newCenter.y;
}