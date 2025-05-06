
#include "CFigure.h"
#include<string>
class CHexagon : public CFigure
{
private:
	Point Center;
public:
	string ID = "CHexagon";
	string getID() override { return ID; }
	CHexagon();
	CHexagon(Point,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& OutFile) override;
	void Load(ifstream& InFile) override;
	bool IsInside(Point P) const override;
	Point getmainposition() const override;
	void setmainpos(Point p) override;
	color GetDrawColor() override {
		return FigGfxInfo.FillClr;
	}

};