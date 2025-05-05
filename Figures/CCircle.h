
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
	void Save(ofstream& OutFile);
	void Load(ifstream& InFile);
};