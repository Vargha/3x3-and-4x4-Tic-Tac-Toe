#include "stdafx.h"
#include "NewGame.h"


NewGame::NewGame() : GridGame(4)
{
}


NewGame::~NewGame()
{
}


bool NewGame::placeMark(int row, int col, int p) {	//A virtual function for placing mark.
	if (row<0 || col<0 || row >= myGrid.arrSize || col >= myGrid.arrSize)
	{
		cout << "Please enter a valid number between 0 and " << myGrid.arrSize << endl;
		return false;
	}
	if (myGrid.isFixed(row, col)) {
		cout << "Invalid Move! Square is occupied." << endl;
		return false;
	}
	myGrid.setNumber(row, col, p);
	return true;									// success in fixing a block
}

void NewGame::placeMark(int player) { //A virtual function for placing mark.
	smartMove();
}

int NewGame::getStatus() const {	//A  function for checking the game status.
	return gameStatus;
};

void NewGame::smartMove() {
	for (int i = 0; i<myGrid.arrSize; i++) {				// loop through rows 
		for (int j = 0; j<myGrid.arrSize; j++) {			//loop through columns
			if (myGrid.grd[i][j] == 0) {				// square is open
				myGrid.grd[i][j] = 2;
				if (checkWin(2, i, j)) {		// method searches if the open square is a potential win
					setStatus(2, i, j);
					return;
				}
				else myGrid.grd[i][j] = 0;
			}
		}
	}
	for (int i = 0; i<myGrid.arrSize; i++) {				// loop through rows 
		for (int j = 0; j<myGrid.arrSize; j++) {			//loop through columns
			if (myGrid.grd[i][j] == 0) {				// square is open
				myGrid.grd[i][j] = 1;
				if (checkWin(1, i, j)) {		// method searches if the open square is a potential win
					myGrid.grd[i][j] = 2;
					setStatus(2, i, j);			// square is either a possible win for comp or player, either way place comp move there
					return;
				}
				else myGrid.grd[i][j] = 0;
			}
		}
	}
	int i, j;
	i = rand() % myGrid.arrSize;
	j = rand() % myGrid.arrSize;
	while (myGrid.grd[i][j] != 0) {
		i = rand() % myGrid.arrSize;
		j = rand() % myGrid.arrSize;
	}
	myGrid.grd[i][j] = 2;
	setStatus(2, i, j);
}