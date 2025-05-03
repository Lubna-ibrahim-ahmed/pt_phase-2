
#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point length;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};


