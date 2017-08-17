#pragma once
#define MAX 5
class Grid
{
private:
	
public:
	int** grd;
	int arrSize;
	Grid();
	~Grid();

	Grid(Grid && obj);

	Grid(int n);	//Constructor that creates an empty grid where n denotes the number of rows (and the number of columns).

	Grid(const Grid & obj);
	int getNumber(int row, int col) const;
	void setNumber(int row, int col, int num);
	bool isFixed(int row, int col) const;
	void clearGrid();

};


