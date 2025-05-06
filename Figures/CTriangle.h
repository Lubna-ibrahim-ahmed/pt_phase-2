#pragma once
#include "CFigure.h"
#include<string>
class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;

public:
	string ID = "CTriangle";
	string getID() override { return ID; }
	CTriangle();
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& OutFile) override;
	void Load(ifstream& InFile) override;
	bool IsInside(Point p) const override;
	Point getmainposition() const override;
	void setmainpos(Point p) override;
	color GetDrawColor()  override {
		return FigGfxInfo.FillClr;
	}
};