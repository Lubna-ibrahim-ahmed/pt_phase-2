#pragma once
#include "CFigure.h"
class CSquare :public CFigure
{
private:
	Point Center;
public:
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& OutFile) override;
	void Load(ifstream& InFile) override;
};