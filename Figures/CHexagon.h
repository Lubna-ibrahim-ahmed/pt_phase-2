
#include "CFigure.h"
#include<string>
class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual CFigure* figcopy() const;//ساعات بتبقي كدا
	virtual bool IsInside(Point P) const;
	virtual void MoveTo(Point newCenter);
};


	void Save(ofstream& OutFile) override;
	void Load(ifstream& InFile) override;
	bool IsInside(Point P) const override;
	Point getmainposition() const override;
	void setmainpos(Point p) override;
	color GetDrawColor() override {
		return FigGfxInfo.FillClr;
	}

};
