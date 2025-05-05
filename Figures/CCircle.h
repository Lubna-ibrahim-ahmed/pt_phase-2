
#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point length;
public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	bool IsInside(Point P) const override;
	virtual void Draw(Output* pOut) const;
	void CCircle::Save(ofstream& OutFile);
	void CCircle::Load(ifstream& InFile);
};