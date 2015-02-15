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

typedef enum { red = 'R', yellow = 'Y', proceed = '-', draw } player;
const int ARRAY_SIZE = 9;
const int COLUMN_WIDTH = 4;

void GetFirstPlayer(player &firstPlayer, player &secondPlayer);
void CreateBoard(player matrix[][ARRAY_SIZE]);
void GetNextMove(player matrix[][ARRAY_SIZE], int height[ARRAY_SIZE], player redOrYellow);
void PrintBoard(player matrix[][ARRAY_SIZE]);
player Winner(player matrix[][ARRAY_SIZE]);
player CheckRow(player matrix[][ARRAY_SIZE]);
player CheckCollumn(player matrix[][ARRAY_SIZE]);
player CheckDiagonalForward(player matrix[][ARRAY_SIZE], int j = 0, int i = 0, int counter = 0);
player CheckDiagonalBackward(player matrix[][ARRAY_SIZE], int j = 0, int i = ARRAY_SIZE - 1, int counter = 0);
player CheckDraw(player matrix[][ARRAY_SIZE]);
player CheckRowInternal(player matrix[][ARRAY_SIZE], int j, int i = 0, int counter = 0);
player CheckCollumnInternal(player matrix[][ARRAY_SIZE], int i, int j = 0, int counter = 0);

int main(void)
{
	player firstPlayer;
	player secondPlayer;
	player winner = proceed;
	player board[ARRAY_SIZE][ARRAY_SIZE];

	int height[ARRAY_SIZE]{0, 0, 0, 0};
	
	GetFirstPlayer(firstPlayer, secondPlayer);

	CreateBoard(board);
	PrintBoard(board);

	while (winner == proceed)
	{
		GetNextMove(board, height, firstPlayer);
		PrintBoard(board);
		winner = Winner(board);

		if (winner != firstPlayer)
		{
			GetNextMove(board, height, secondPlayer);
			PrintBoard(board);
			winner = Winner(board);
		}
	}

	if (winner == draw)
	{
		cout << "The game was a draw";
	}
	else
	{
		cout << static_cast<char>(winner) << " wins!!";
	}

	return 0;
}

void GetFirstPlayer(player &firstPlayer, player &secondPlayer)
{
	char inputPlayer;

	cout << "This program alows people to play the game ConnectFour. \n\n"
		<< "First player, Please enter 'Y' for Yellow or 'R' for Red: ";

	cin >> inputPlayer;

	inputPlayer = static_cast<char>(toupper(inputPlayer));

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
			matrix[j][i] = proceed;
		}
	}
}

void GetNextMove(player matrix[][ARRAY_SIZE], int height[], player redOrYellow)
{
	int move;
	int collumn;
	int row;

	cout << "Player \'" << static_cast<char>(redOrYellow) << "\' "
		 << "Please select a column to make a move: ";

	cin >> move;

	cout << endl << endl;

	collumn = move - 1;
	row = height[collumn];
	
	matrix[row][collumn] = redOrYellow;
	height[collumn]++;
}

void PrintBoard(player matrix[][ARRAY_SIZE])
{
	for (int counter = 1; counter <= ARRAY_SIZE; counter++)
	{
		cout << setw(COLUMN_WIDTH - 1) << counter << " ";
	}
	cout << "\n";

	for (int i = ARRAY_SIZE - 1; i >= 0; i--)
	{
		for (int counter = 0; counter < ARRAY_SIZE * COLUMN_WIDTH; counter++)
		{
			cout << "-";
		}
		cout << "-\n";
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			cout << "| " << setw(COLUMN_WIDTH - 3)
				 << static_cast<char>(matrix[i][j]) << " ";
		}
		cout << "|\n";
	}
	for (int counter = 0; counter < ARRAY_SIZE * COLUMN_WIDTH; counter++)
	{
		cout << "-";
	}
	cout << "-\n\n\n";
}

player Winner(player matrix[][ARRAY_SIZE])
{
	player winner = proceed;
	
	winner = CheckRow(matrix);

	if (winner == proceed)
	{
		winner = CheckCollumn(matrix);

		if (winner == proceed)
		{
			winner = CheckDiagonalForward(matrix);

			if (winner == proceed)
			{
				winner = CheckDiagonalBackward(matrix);

				if (winner == proceed)
				{
					CheckDraw(matrix);
				}
			}
		}
	}
	
	return winner;
}

player CheckRow(player matrix[][ARRAY_SIZE])
{
	player winner = proceed;

	for (int j = 0; j < ARRAY_SIZE; j++)
	{
		if (winner == proceed)
		{
			winner = CheckRowInternal(matrix, j);
		}
	}
	return winner;
}

player CheckCollumn(player matrix[][ARRAY_SIZE])
{
	player winner = proceed;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (winner == proceed)
		{
			winner = CheckCollumnInternal(matrix, i);
		}
	}

	return winner;
}

player CheckDraw(player matrix[][ARRAY_SIZE])
{
	player winner = proceed;
	
	if (matrix[ARRAY_SIZE - 1][0] != proceed)
	{
		winner = draw;
		cout << static_cast<char>(winner);
	}
	return winner;
}

player CheckRowInternal(player matrix[][ARRAY_SIZE], int j, int i, int counter)
{
	if (counter == 3)
	{
		if (matrix[j][i] != proceed)
		{
			return matrix[j][i];
		}
		else
		{
			i++;
			return CheckRowInternal(matrix, j, i);
		}
	}
	else if (i >= ARRAY_SIZE - 1)
	{
		return proceed;
	}
	else if (matrix[j][i] == matrix[j][i + 1])
	{
		counter++;
		i++;
		return CheckRowInternal(matrix, j, i, counter);
	}
	else
	{
		i++;
		return CheckRowInternal(matrix, j, i);
	}

}

player CheckCollumnInternal(player matrix[][ARRAY_SIZE], int i, int j, int counter)
{
	if (counter == 3)
	{
		if (matrix[j][i] != proceed)
		{
			return matrix[j][i];
		}
		else
		{
			j++;
			return CheckCollumnInternal(matrix, i, j);
		}
	}
	
	else if (j >= ARRAY_SIZE - 1)
	{
		return proceed;
	}
	
	else if (matrix[j][i] == matrix[j + 1][i])
	{
		counter++;
		j++;
		return CheckCollumnInternal(matrix, i, j, counter);
	}
	else
	{
		j++;
		return CheckCollumnInternal(matrix, i, j);
	}

}

player CheckDiagonalForward(player matrix[][ARRAY_SIZE], int j, int i, int counter)
{
	if (counter == 3)
	{
		if (matrix[j][i] != proceed)
		{
			return matrix[j][i];
		}
		else
		{
			j++;
			i++;
			return CheckDiagonalForward(matrix, j, i);
		}
	}

	else if (j >= ARRAY_SIZE - 1)
	{
		return proceed;
	}

	else if (matrix[j][i] == matrix[j + 1][i + 1])
	{
		counter++;
		j++;
		i++;
		return CheckDiagonalForward(matrix, j, i, counter);
	}
	else
	{
		j++;
		i++;
		return CheckDiagonalForward(matrix, j, i);
	}

}

player CheckDiagonalBackward(player matrix[][ARRAY_SIZE], int j, int i, int counter)
{
	if (counter == 3)
	{
		if (matrix[j][i] != proceed)
		{
			return matrix[j][i];
		}
		else
		{
			j++;
			i--;
			return CheckDiagonalBackward(matrix, j, i);
		}
	}

	else if (j >= ARRAY_SIZE - 1)
	{
		return proceed;
	}

	else if (matrix[j][i] == matrix[j + 1][i - 1])
	{
		counter++;
		j++;
		i--;
		return CheckDiagonalBackward(matrix, j, i, counter);
	}
	else
	{
		j++;
		i--;
		return CheckDiagonalBackward(matrix, j, i);
	}

}