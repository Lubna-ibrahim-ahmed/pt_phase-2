#pragma once
#include "CFigure.h"
class CSquare :public CFigure
{
private:
	Point Center;
public:
CSquare(Point, GfxInfo FigureGfxInfo);
virtual void Draw(Output* pOut) const;
virtual CFigure* figcopy() const;//ساعات بتبقي كدا
virtual bool IsInside(Point P) const;
virtual void MoveTo(Point newCenter);

};




