#pragma once
#include "CFigure.h"
#include<string>
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





	string ID = "CSquare";
	string getID() override { return ID; }
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& OutFile) override;
	void Load(ifstream& InFile) override;
	bool IsInside(Point P) const override;
	Point getmainposition() const override;
	void setmainpos(Point p) override;
	color GetDrawColor() override{
		return FigGfxInfo.FillClr;
	}
}; 
