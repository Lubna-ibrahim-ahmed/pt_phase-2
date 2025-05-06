#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
protected:
	string Printed_message;
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;
	void ClearToolBar() const;                                //Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	
	///Make similar functions for drawing all other figure types.
	void DrawSq(Point center, GfxInfo SquareGfxInfo, bool selected = false) const; //Draw a Square
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected = false) const;  //Draw a Triangle
	void DrawHex(Point center, GfxInfo HexGfxInfo, bool selected = false) const; //Draw a Hexagon
	void DrawCir(Point center, int radius, GfxInfo HexGfxInfo, bool selected = false) const; //Draw a Circle
	


	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	string getPrinted();
	
	~Output();
};

#endif