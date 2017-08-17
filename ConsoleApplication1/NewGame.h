#pragma once
#include "GridGame.h"

class NewGame : public GridGame
{
public:
	NewGame();
	~NewGame();
	int bestI = 0, bestJ = 0;
	int getStatus() const;	// 0=tie, 1=P1-Won, 2=P2-Won, 3=Otherwise
	void smartMove();
	bool placeMark(int row, int col, int p);							//A  function for placing mark.
	void placeMark(int player);											//A  function for placing mark.
};

