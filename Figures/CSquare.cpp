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