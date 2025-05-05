
#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon();
	CHexagon(Point,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	
	void Save(ofstream& OutFile) override;
	void Load(ifstream& InFile) override;
};