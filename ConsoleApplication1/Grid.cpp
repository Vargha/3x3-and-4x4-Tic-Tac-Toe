#include "stdafx.h"


Grid::Grid()
{
}
Grid::Grid(int n) :arrSize(n) {
	grd = new int*[n];
	for (int i = 0; i < n; i++)
	{
		grd[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			grd[i][j] = 0;
		}
	}
}


Grid::~Grid() {
	for (int i = 0; i < arrSize; i++) { delete[] grd[i]; }
	delete[] grd;
	//cout << "DESTRUCTOR\n";
};

//Copy constructor that creates a grid with an object of Grid (do a deep copy).
Grid::Grid(const Grid &obj) : arrSize(obj.arrSize) {
	grd = new int*[obj.arrSize];
	for (int i = 0; i < obj.arrSize; i++)
	{
		grd[i] = new int[obj.arrSize];
		for (int j = 0; j < obj.arrSize; j++)
		{
			grd[i][j] = obj.grd[i][j];
		}
	}
	//cout << "copy constructor" << endl;
}

//move constructor
Grid::Grid(Grid &&obj) :arrSize(0), grd(nullptr) {
	std::swap(grd, obj.grd);
	std::swap(arrSize, obj.arrSize);
	//cout << "move constructor" << endl;
	// the other destructor gonna take care of leaked memory. WoW AAron
}

//Read number at grid location (row,col).
int Grid::getNumber(int row, int col) const{
	return grd[row][col];
}

//Set number at grid location (row,col) to “num”.
void Grid::setNumber(int row, int col, int num) {
	grd[row][col] = num;
}

//Return true if the grid location (row,col) is fixed, i.e., not empty.
bool Grid::isFixed(int row, int col) const {
	if (getNumber(row, col) == 0)	return false;
	return true;
}

//Clear all values to 0 in all locations.
void Grid::clearGrid() {
	for (int i = 0; i<arrSize; i++)
	{
		for (int j = 0; j<arrSize; j++)
		{
			grd[i][j] = 0;
		}
	}
}

