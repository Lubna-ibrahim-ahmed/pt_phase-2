#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;  
	CFigure* CutFigure;
	CFigure* SelectedFigure; //ساعات بتبقي كدا
public:	
	ApplicationManager(); 
	~ApplicationManager();
	void SetCutFigure(CFigure* fig) { CutFigure = fig; }
	CFigure* GetCutFigure() const { return CutFigure; }
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void PrintFigureInfo();    //funtion to print shape information in the status bar
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void unselectall();        //function to unselect all the shapes
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	







	void SetSelectedFigure(CFigure* pFig);//ساعات بتبقي كدا
	CFigure* GetSelectedFigure() const;//ساعات بتبقي كدا
	void SetClipboard(CFigure* fig);//ساعات بتبقي كدا
	CFigure* GetClipboard() const;//ساعات بتبقي كدا

		void DeleteFigure(CFigure* pFig);

	// -- Clipboard Management Functions
	void SaveAll(ofstream& File);
	void LoadAll(ifstream& File);
	void clearFigures(); //function to clear all the figures
	int getfigurecount(); //getter to get the count of the figures
	CFigure* getfiglistindex(int i) const;//getter to get the index of FigList since its private
};

#endif
