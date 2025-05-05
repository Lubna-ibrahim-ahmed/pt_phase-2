#pragma once
#include "CFigure.h"
class CSquare :public CFigure
{
private:
	Point Center;
public:
	string ID = "CSquare";
	string getID() override { return ID; }
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& OutFile);
	void Load(ifstream& InFile);
};