#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual CFigure* figcopy() const;//ساعات بتبقي كدا
	virtual bool IsInside(Point P) const;
	virtual void MoveTo(Point newCenter);

};

#endif