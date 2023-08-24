#include "Puzzle.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
using namespace std;

Puzzle::Puzzle(){}

void Puzzle::printBoard(int board[][10], int amt)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for(int row = 0; row <= amt; row++)
	{
		for(int column = 0; column <= amt; column++)
		{
			if(board[row][column] == 0)
			{
				SetConsoleTextAttribute(hConsole, 7);
				cout << "\xB1\xB1 ";
			}
			else
			{
				if(board[row][column] == solvedBoard[row][column])
					SetConsoleTextAttribute(hConsole, 7);
				else
					SetConsoleTextAttribute(hConsole, 7); 
				if (board[row][column]<10) 
					cout<<"0";
				cout<<board[row][column] << " ";
			}
		}
		cout<<endl;
	}
	SetConsoleTextAttribute(hConsole, 7);
}
void Puzzle::initializeBoard(int board[][10], int amt)
{
	int i = 1;
	for(int row = 0; row <= amt; row++)
	{
		for(int column = 0; column <= amt; column++)
		{
			board[row][column] = i;
			solvedBoard[row][column] = i;
			i++;
		}
		board[amt][amt] = 0;
		solvedBoard[amt][amt] = 0;
	}
}

void Puzzle::slideTile(int board[][10],int move, int amt)
{
	int emptyRow;
	int emptyCol;
	bool legalMoves[4] = {1,1,1,1};
	for(int row = 0; row <= amt; row++)
	{
		for(int column = 0; column <= amt; column++)
		{
			if(board[row][column] == 0) //Find location of empty space
			{
				emptyRow = row;
				emptyCol = column;
			}
		}
	}
	if(emptyRow + 1 > amt)
		legalMoves[2] = false;
	else if(emptyRow - 1 < 0)
		legalMoves[3] = false;

	if(emptyCol - 1 < 0)
		legalMoves[1] = false;
	else if(emptyCol + 1 > amt)
		legalMoves[0] = false;

	switch(move)
	{
	case 0:
		if(legalMoves[move])
		{
			board[emptyRow][emptyCol] = board[emptyRow][emptyCol + 1];
			board[emptyRow][emptyCol + 1] = 0;
			emptyCol = emptyCol+1;
		}
		break;
	case 1:
		if(legalMoves[move])
		{
			board[emptyRow][emptyCol] = board[emptyRow][emptyCol - 1];
			board[emptyRow][emptyCol- 1] = 0;
			emptyCol = emptyCol-1;
		}
		break;
	case 2:
		if(legalMoves[move])
		{
			board[emptyRow][emptyCol] = board[emptyRow+1][emptyCol];
			board[emptyRow+1][emptyCol] = 0;
			emptyRow = emptyRow+1;
		}
		break;
	case 3:
		if(legalMoves[move])
		{
			board[emptyRow][emptyCol] = board[emptyRow-1][emptyCol];
			board[emptyRow-1][emptyCol] = 0;
			emptyRow = emptyRow-1;
		}
		break;
	}

}
bool Puzzle::isBoardSolved(int board[][10], int amt)
{
	bool boardSolved = true;
	int row = 0;
	int col = 0;
	while(boardSolved && row<=amt)
	{
		if(solvedBoard[row][col] == board[row][col])
		{
			col++;
			if(col == amt)
			{
				row++;
				col = 0;
			}
		}
		else 
			boardSolved = false;
	}
	return boardSolved;
}

void Puzzle::scrambleBoard(int board[][10], int amt)
{
	time_t t;
    srand((unsigned) time(&t));
	int move;
	while(isBoardSolved(board,amt))
	{
		for(int i = 0; i < 100000;i++)
		{
			move = rand() % 4;
			slideTile(board,move,amt);
		}
	}
}