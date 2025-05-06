#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	Point CenterOffset1;
	Point CenterOffset2;
	Point CenterOffset3;
	Point Center;

public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool IsInside(Point P) const;
	virtual CFigure* figcopy() const;
	virtual void MoveTo(Point newCenter);
	Point getcenter();
	Point Centeroffset1();
	Point Centeroffset2();
	Point Centeroffset3();
};

