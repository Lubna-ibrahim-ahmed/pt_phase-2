
#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual CFigure* figcopy() const;//ساعات بتبقي كدا
	virtual bool IsInside(Point P) const;
	virtual void MoveTo(Point newCenter);
};


