////////////////////////////////////////////////
// Vincent Leseberg CST 138-02
// Lab 2: Connect Four
// Purpose: Create a playable ConnectFour game
//
////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Functions.h"

using namespace std;

enum player { red = 'R', yellow = 'Y', proceed = '-' };
const int ARRAY_SIZE = 4;

void GetFirstPlayer(player &firstPlayer, player &secondPlayer);
void CreateBoard(player matrix[][ARRAY_SIZE]);
void GetNextMove(player matrix[][ARRAY_SIZE], int height[ARRAY_SIZE], player redOrYellow);
void PrintBoard(player matrix[][ARRAY_SIZE]);
player Winner(player matrix[][ARRAY_SIZE]);

int main(void)
{
	cout << red << "test";
	player firstPlayer;
	player secondPlayer;
	player board[ARRAY_SIZE][ARRAY_SIZE];

	int height[ARRAY_SIZE]{0, 0, 0};
	
	GetFirstPlayer(firstPlayer, secondPlayer);

	CreateBoard(board);

	while (Winner(board) == proceed)
	{
		PrintBoard(board);
		GetNextMove(board, height, redOrYellow);
	}

	return 0;
}

void GetFirstPlayer(player &firstPlayer, player &secondPlayer)
{
	char inputPlayer;

	cout << "This program alows to people to play the game ConnectFour. \n"
		<< "First player, Please enter 'Y' for Yellow or 'R' for Red: ";

	cin >> inputPlayer;

	cout << endl << endl;

	if (inputPlayer == 'R')
	{
		firstPlayer = red;
		secondPlayer = yellow;
	}

	else
	{
		firstPlayer = yellow;
		secondPlayer = red;
	}
}

void CreateBoard(player matrix[][ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			matrix[i][j] = proceed;
		}
	}
}

void GetNextMove(player matrix[][ARRAY_SIZE], int height[], player redOrYellow)
{
	int move;
	int positionX;
	int positionY;

	cout << "Please select a column to make a move: ";

	cin >> move;

	cout << endl << endl;

	positionX = move;
	positionY = height[move];
	
	matrix[positionX][positionY] = redOrYellow;
	height[move]++;
}

void PrintBoard(player matrix[][ARRAY_SIZE])
{
	for (int i = 0; i < 4; i++)
	{
		cout << "---------------------\n";
		for (int j = 0; j < 4; j++)
		{
			cout << "| " << setw(2) << matrix[i][j] << setw(1) << " ";
		}
		cout << "|\n";
	}
	cout << "---------------------";
}

player Winner(player matrix[][ARRAY_SIZE])
{
	player winner;
	for (int j = 0; j < ARRAY_SIZE; j++)
	{
		int i;
		for (i = 0; i < ARRAY_SIZE - 1 && matrix[i][j] == matrix[i+1][j]; i++)
		{
			winner = matrix[i + 1][j];
		}

	}

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		int j;
		for (j = 0; j < ARRAY_SIZE - 1 && matrix[i][j] == matrix[i][j+1]; j++)
		{
			winner = matrix[i][j+1];
		}

	}

	int i = 0;
	for (int j = 0; j < ARRAY_SIZE - 1 && matrix[i][j] == matrix[i + 1][j + 1]; j++)
	{
		winner = matrix[i + 1][j + 1];
		i++;
	}

	i = 3;
	for (int j = 0; j < ARRAY_SIZE - 1 && matrix[i][j] == matrix[i - 1][j + 1]; i++)
	{
		winner = matrix[i - 1][j + 1];
		i--;
	}

	return winner;
}