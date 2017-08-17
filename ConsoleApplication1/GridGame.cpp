#include "stdafx.h"
#include "GridGame.h"


GridGame::GridGame(int n) : myGrid(n)
{
	restart();
}


GridGame::~GridGame()
{
}

void GridGame::setStatus(int p, int row, int col)
{
	if (checkWin(p, row, col))
	{
		gameStatus = p;
		return;
	}
	//if (checkDraw())
		//gameStatus = 0;
	gameStatus = 3;
	return ;
	
}

bool GridGame::checkWin(int p, int row, int col)
{	
	if (checkRow(p, row))
		return true;
	if (checkCol(p, col))
		return true;
	if (checkFDiag(p))
		return true;
	if (checkBDiag(p))
		return true;

	return false;
}

bool GridGame::checkDraw()
{
	for (int i = 0; i < myGrid.arrSize; i++)
	{
		for (int j = 0; j < myGrid.arrSize; j++)
		{
			if (myGrid.grd[i][j] == 0)
				false;
		}
	}
	return true;
}

void GridGame::drawGrid() const
{
	cout << "  ";
	for (int r = 0; r < myGrid.arrSize; r++)
		cout << " " << r;
	cout << endl;

	for (int i = 0; i < myGrid.arrSize; i++) {

		cout << i << " " << "|";
		for (int j = 0; j < myGrid.arrSize; j++) {
			cout << myGrid.grd[i][j] << "|";
		}
		cout << endl;
	}
}

void GridGame::restart()
{	// Resetting the board
	for (int i = 0; i < myGrid.arrSize; i++) {
		for (int j = 0; j < myGrid.arrSize; j++) {
			myGrid.grd[i][j] = 0;
		}
	}
	gameStatus = 3;
	//cout << "Game Board reset." << endl;
}

bool GridGame::checkRow(int p, int row)
{
	int sum = 0;
	for (int i = 0; i < myGrid.arrSize; i++)
	{
		if (myGrid.grd[row][i] == p)
			sum++;
		if (sum >= 3)
			return true;
	}
	return false;
}

bool GridGame::checkCol(int p, int col)
{
	int sum = 0; 
	for (int i = 0; i < myGrid.arrSize; i++)
	{
		if (myGrid.grd[i][col] == p)
			sum++;
		if (sum >= 3)
			return true;
	}
	return false;
}

bool GridGame::checkFDiag(int p)
{
	int sum = 0;
		for (int j = 0, i = myGrid.arrSize - 1; j < myGrid.arrSize; j++, i--)
		{
			if (myGrid.grd[i][j] == p)
				sum++;
			if (sum >= 3)
				return true;
		}
		return false;
}

bool GridGame::checkBDiag(int p)
{
	int sum = 0;
		for (int i = 0; i< myGrid.arrSize; i++)
		{
			if (myGrid.grd[i][i] == p)
				sum++;
			if (sum >= 3)
				return true;
		}
		return false;
}

bool GridGame::placeMark(int row, int col, int p) {	//A virtual function for placing mark.
	if (myGrid.isFixed(row, col)) return false;
	myGrid.setNumber(row, col, p);
	return true;									// success in fixing a block
}