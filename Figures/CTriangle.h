#pragma once
#include "CFigure.h"

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
};