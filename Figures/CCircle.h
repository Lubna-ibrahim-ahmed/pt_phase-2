
#include "CFigure.h"
#include<string>
class CCircle : public CFigure
{
private:
	Point Center;
	Point length;
public:
	string ID = "CCircle";
	string getID() override { return ID; }

	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	bool IsInside(Point P) const override;
	virtual void Draw(Output* pOut) const;
    CFigure * figcopy() const;
	virtual void MoveTo(Point newCenter);
	void CCircle::Save(ofstream& OutFile);
	void CCircle::Load(ifstream& InFile) override;
	Point getmainposition() const override;
	void setmainpos(Point p) override;
	color GetDrawColor()  override {
		return FigGfxInfo.FillClr;
	}
	
};