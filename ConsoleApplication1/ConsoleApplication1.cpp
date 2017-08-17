// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GridGame.h"
#include "TicTacToe.h"
#include "NewGame.h"

char prompt();
void play(char mode);
void tic(TicTacToe ttt);
void ngame(NewGame ng);
int howManyPlayers();
char playAgain();
int getRow();
int getCol();

void singlePttt(TicTacToe ttt);
void twoPttt(TicTacToe ttt);


void singlePng(NewGame ng);
void twoPng(NewGame ng);


int main()
{
	char c;
	c=prompt();
	while (1)
	{
		if (c == 'q')
			break;
		else
			play(c);
		c = prompt();
	}
	cout << "Thanks For Playing Bye"<<endl;
	
	return 0;
}

char prompt()
{
	char c;
	cout << "\nTo play TicTacToe enter t\nTo play the NewGame enter n\nOr you may exit by entering q" << endl;
	cin >> c;
	while (1) 
	{
		if (c == 'n' || c == 't' || c == 'q')
			break;
		else
		{
			cout << "\nTo play TicTacToe enter t\nTo play the NewGame enter n\nOr you may exit by entering q" << endl;
			cin >> c;
		}
	}
	return c;
}

void play(char mode)
{
	cout << "\nYou chose to play: ";
	if (mode == 't')
	{
		cout << "TicTacToe\n" << endl;
		TicTacToe ttt;
		tic(ttt);
	}
	else
	{
		cout << "The New Game" << endl;
		cout << "Just get 3 marks on a line to win--marks do not need to be in consecutive order\n" << endl;
		NewGame ng;
		ngame(ng);
	}
}

void tic(TicTacToe ttt)
{
	char r='y';
	int compFlag = 1;
	while (r=='y')
	{
		compFlag = howManyPlayers();
		if (compFlag == 1)
			singlePttt(ttt);
		else
			twoPttt(ttt);
		r = playAgain();
	}
}

void ngame(NewGame ng)
{
	char r = 'y';
	int compFlag = 1;
	while (r == 'y')
	{
		compFlag = howManyPlayers();
		if (compFlag == 1)
			singlePng(ng);
		else
			twoPng(ng);
		r = playAgain();
	}
}

int howManyPlayers()
{
	int i;
	cout << "Enter 2 for two human players or Enter 1 to play against computer" << endl;
	cin >> i;
	while (1)
	{
		if (i==1 || i==2)
			break;
		else
		{
			cout << "Enter 2 for two human players or Enter 1 to play against computer" << endl;
			cin >> i;
		}
	}

	return i;
}

void singlePttt(TicTacToe ttt)
{
	int p = 1, row, col;
	ttt.count = 0; //count how many moves for draw
	while (ttt.getStatus() == 3 && ttt.count<9)
	{
		cout << "\nPlayer 1 make a move" << endl;
		while (1)
		{
			row = getRow();
			col = getCol();
			if (ttt.placeMark(row, col, p))
				break;
		}
		ttt.drawGrid();
		ttt.count++;
		ttt.setStatus(1, row, col);
		if (ttt.getStatus() != 3 || ttt.count>=9) {
			break;
		}
		cout << "\nComputers move" << endl;
		ttt.smartMove();
		ttt.drawGrid();
		ttt.count++;
	}
	if (ttt.getStatus() == 1)
		cout << "Well Done You Defeated The Computer!" << endl;
	else if (ttt.getStatus() == 2)
		cout << "The Computer Won, Better Luck Next Time." << endl;
	else
		cout << "Game Ended In A Draw" << endl;
	ttt.restart();

}

void twoPttt(TicTacToe ttt)
{
	int p = 1, row, col;
	ttt.count = 0; //count how many moves for draw
	while (ttt.getStatus() == 3 && ttt.count<9)
	{
		cout << "\nPlayer 1 make a move" << endl;
		while (1)
		{
			row = getRow();
			col = getCol();
			if (ttt.placeMark(row, col, 1))
				break;
		}
		ttt.drawGrid();
		ttt.count++;
		ttt.setStatus(1, row, col);
		if (ttt.getStatus() != 3 || ttt.count >= 9) {
			break;
		}
		cout << "\nPlayer 2 make a move" << endl;
		while (1)
		{
			row = getRow();
			col = getCol();
			if (ttt.placeMark(row, col, 2))
				break;
		}
		ttt.drawGrid();
		ttt.count++;
		ttt.setStatus(2, row, col);
	}
	if (ttt.getStatus() == 1)
		cout << "Player 1 Is The Winner!" << endl;
	else if (ttt.getStatus() == 2)
		cout << "Player 2 Is The Winner!" << endl;
	else
		cout << "Game Ended In A Draw" << endl;
	ttt.restart();

}


void singlePng(NewGame ng)
{
	int p = 1, row, col;
	ng.count = 0; //count how many moves for draw
	while (ng.getStatus() == 3 && ng.count<16)
	{
		cout << "\nPlayer 1 make a move" << endl;
		while (1)
		{
			row = getRow();
			col = getCol();
			if (ng.placeMark(row, col, p))
				break;
		}
		ng.drawGrid();
		ng.count++;
		ng.setStatus(1, row, col);
		if (ng.getStatus() != 3 || ng.count >= 16) {
			break;
		}
		cout << "\nComputers move" << endl;
		ng.smartMove();
		ng.drawGrid();
		ng.count++;
	}
	if (ng.getStatus() == 1)
		cout << "Well Done You Defeated The Computer!" << endl;
	else if (ng.getStatus() == 2)
		cout << "The Computer Won, Better Luck Next Time." << endl;
	else
		cout << "Game Ended In A Draw" << endl;
	ng.restart();

}

void twoPng(NewGame ng)
{
	int p = 1, row, col;
	ng.count = 0; //count how many moves for draw
	while (ng.getStatus() == 3 && ng.count<16)
	{
		cout << "\nPlayer 1 make a move" << endl;
		while (1)
		{
			row = getRow();
			col = getCol();
			if (ng.placeMark(row, col, 1))
				break;
		}
		ng.drawGrid();
		ng.count++;
		ng.setStatus(1, row, col);
		if (ng.getStatus() != 3 || ng.count >= 16) {
			break;
		}
		cout << "\nPlayer 2 make a move" << endl;
		while (1)
		{
			row = getRow();
			col = getCol();
			if (ng.placeMark(row, col, 2))
				break;
		}
		ng.drawGrid();
		ng.count++;
		ng.setStatus(2, row, col);
	}
	if (ng.getStatus() == 1)
		cout << "Player 1 Is The Winner!" << endl;
	else if (ng.getStatus() == 2)
		cout << "Player 2 Is The Winner!" << endl;
	else
		cout << "Game Ended In A Draw" << endl;
	ng.restart();

}

char playAgain()
{
	char r;
	cout << "To play again enter y, to go to main menu enter any other character: " << endl;
	cin >> r;
	return r;
}

int getRow()
{
	int row;
	cout << "Enter a row: ";
	cin >> row;
	return row;
}

int getCol()
{
	int col;
	cout << "Enter a column: ";
	cin >> col;
	return col;
}
