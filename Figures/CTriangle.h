//﻿#include "CFigure.h"

#pragma once
#include "CFigure.h"
#include<string>
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

	void Save(ofstream& OutFile) override;
	void Load(ifstream& InFile) override;
	bool IsInside(Point p) const override;
	Point getmainposition() const override;
	void setmainpos(Point p) override;
	color GetDrawColor()  override {
		return FigGfxInfo.FillClr;
	}
};
