#ifndef CFIGURE_H
#define CFIGURE_H
#include<string>
#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	string ID;		//Each figure has an ID
	bool Selected = false;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual string getID() {
		return ID;
	}
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual bool IsInside(Point P) const = 0;
	color Getchar(Output* pO) ;

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar

	string CFigure::ColorToString(color c);
	color CFigure::StringToColor(string str);
};

#endif