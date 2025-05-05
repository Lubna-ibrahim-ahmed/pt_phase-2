#ifndef CRECT_H
#define CRECT_H
#include<string>
#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	string ID ="CRectangle";
	string getID() override { return ID; }
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool IsInside(Point P) const override;
	void Save(ofstream& OutFile) override;
	void Load(ifstream& InFile) override;
};

#endif