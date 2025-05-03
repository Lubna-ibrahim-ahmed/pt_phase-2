#include "CSquare.h"
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;


}
void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSq(Center, FigGfxInfo, Selected);
}