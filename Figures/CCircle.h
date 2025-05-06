
#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point length;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual CFigure* figcopy() const;//ساعات بتبقي كدا
	virtual bool IsInside(Point P) const;
	virtual void MoveTo(Point newCenter);
};


