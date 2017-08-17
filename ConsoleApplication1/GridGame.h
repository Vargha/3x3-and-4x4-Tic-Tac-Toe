#pragma once
#include "Grid.h"
class GridGame // :	public grid
{
protected:
	int gameStatus=3;	// 0=tie, 1=P1-Won, 2=P2-Won, 3=Otherwise
	

public:
	int count=0;
	Grid myGrid;
	GridGame(int n);
	~GridGame();
	virtual int getStatus() const=0; //A virtual function for checking the game status.

	void setStatus(int p, int row, int col);

	bool checkWin(int p, int row, int col);

	bool checkDraw();
	
	virtual bool placeMark (int row, int col, int p) = 0;	//A virtual function for placing mark.

	virtual void placeMark(int player) = 0;

	void drawGrid() const;

	void restart();

	bool checkRow(int p, int row);

	bool checkCol(int p, int col);

	bool checkFDiag(int p);

	bool checkBDiag(int p);

};

