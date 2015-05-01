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
#include <Windows.h>

using namespace std;

//Initialize Constants and enum types
enum player { red = 'R', yellow = 'Y', proceed = '-', draw };
const int ARRAY_SIZE = 9;
const int COLUMN_WIDTH = 4;

//Functions Prototypes
void GetFirstPlayer(player &firstPlayer, player &secondPlayer);
void CreateBoard(player matrix[][ARRAY_SIZE]);
void GetNextMove(player matrix[][ARRAY_SIZE], int height[ARRAY_SIZE], player redOrYellow);
void PrintBoard(player matrix[][ARRAY_SIZE]);
player Winner(player matrix[][ARRAY_SIZE]);
player CheckRow(player matrix[][ARRAY_SIZE]);
player CheckCollumn(player matrix[][ARRAY_SIZE]);
player CheckDiagonalForwardInternal(player matrix[][ARRAY_SIZE], int j, int i = 0, int counter = 0);
player CheckDiagonalBackwardInternal(player matrix[][ARRAY_SIZE], int j, int i = ARRAY_SIZE - 1, int counter = 0);
player CheckDiagonalForward(player matrix[][ARRAY_SIZE]);
player CheckDiagonalBackward(player matrix[][ARRAY_SIZE]);
player CheckDraw(player matrix[][ARRAY_SIZE]);
player CheckRowInternal(player matrix[][ARRAY_SIZE], int j, int i = 0, int counter = 0);
player CheckCollumnInternal(player matrix[][ARRAY_SIZE], int i, int j = 0, int counter = 0);
void TextColor(string color);


int main(void)
{
	//Initialize Variables for players and winners
	player firstPlayer;
	player secondPlayer;
	player winner = proceed;

	//Initialize Board Array
	player board[ARRAY_SIZE][ARRAY_SIZE];
	
	//Initialize Height array for tracking next space in a collum
	int height[ARRAY_SIZE]{0, 0, 0, 0};
	
	//Print welcome message ask the first play what color they want
	GetFirstPlayer(firstPlayer, secondPlayer);

	//Populate board array with values
	CreateBoard(board);

	//Print initial board to screen
	PrintBoard(board);

	//While the winner variable remains at the 'proceed' value
	//	the game continues (empty spaces evaluate to 'proceed')
	while (winner == proceed)
	{
		//Prompt player one to make their move
		GetNextMove(board, height, firstPlayer);

		//Print the board after their move
		PrintBoard(board);

		//Check the board for a winner, set winner equal
		//	to the result of the function
		winner = Winner(board);

		//If the first player did not win, prompt the second player
		//	to make a move and then print and check the board again
		if (winner != firstPlayer)
		{
			GetNextMove(board, height, secondPlayer);
			PrintBoard(board);
			winner = Winner(board);
		}
	}

	//Once the winner function returns a value other than 'proceed'
	//	the while loop breaks...

	//Prints the result of the game to the board.
	if (winner == draw)
	{
		cout << "The game was a draw";
	}
	else if (winner == red)
	{
		TextColor("red");
		cout << "The Red player wins";
		TextColor("default");
	}
	else
	{
		TextColor("yellow");
		cout << "The Yellow player wins";
		TextColor("default");
	}

	return 0;
}

//--------------------
//Functon asks the first player to select a color, and sets the 
//	value of the other player to the unused color
//--------------------
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

//--------------------
//This function uses a nested for loop to populate 
//	the board array with 'blank space' values
//--------------------
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

//--------------------
//This function receives an input from the player for which collum
//	they wish to make their move in. It then uses a secondary one
//	dimensional array 'height' to determine the row to place the 
//	move in. It increments this 1D array after every move for the 
//	appropriate collumn
//--------------------
void GetNextMove(player matrix[][ARRAY_SIZE], int height[], player redOrYellow)
{
	int move;
	int collumn;
	int row;

	cout << "Player \'" << static_cast<char>(redOrYellow) << "\' "
		 << "Please select a column to make a move: ";

	cin >> move;

	//This is where the error was...the >= needed to be a >
	// as seen below
	while (move > ARRAY_SIZE)
	{
		cout << "\nYou did not make a valid move,"
			 << "\nplease select a collumn between 1 and "
			 << ARRAY_SIZE << ": "; 

		cin >> move;
	}

	cout << endl << endl;

	collumn = move - 1;
	row = height[collumn];
	
	matrix[row][collumn] = redOrYellow;
	height[collumn]++;
}

//--------------------
//This function prints the board to the screen. It is formatted using
//	for loops in this way so that the screen formatting will remain
//	valid regardless of what the board size is set to. It will adapt
// accordingly.
//--------------------
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
			if (matrix[i][j] == proceed)
			{
				cout << "| " << setw(COLUMN_WIDTH - 3)
					<< "-" << " ";
			}
			else if (matrix[i][j] == red)
			{
				cout << "| ";
				TextColor("red");
				cout << setw(COLUMN_WIDTH - 3)
		 			<< "O" << " ";
				TextColor("default");
			}
			else
			{
				cout << "| ";
				TextColor("yellow");
				cout << setw(COLUMN_WIDTH - 3)
					<< "O" << " ";
				TextColor("default");
			}
			
		}
		cout << "|\n";
	}
	for (int counter = 0; counter < ARRAY_SIZE * COLUMN_WIDTH; counter++)
	{
		cout << "-";
	}
	cout << "-\n\n\n";
}

//--------------------
//This function checks the board array for a winner by checking
//	each row, then each collum, then each diagonal. The 'internal'
//	functions exists as recursive checking functions for each
//	individual row/collum/diagonal and allow the program to
//	adjust to increasing/decreasing board size
//--------------------
player Winner(player matrix[][ARRAY_SIZE])
{
	//The function uses the nested if statements because 
	//	we don't need to check additional board areas
	//	once we have found a winner, in fact it would
	//	reset the winner variable and the game would
	//	crash.
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

//--------------------
//Checks all of the rows, but only calls the 'RowInternal' Function
//	if there is not yet a winner.
//--------------------
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

//--------------------
//Same as above except for the collumns
//--------------------
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

//--------------------
//Same as above except for the diagonals beginning in
// array coordinate [0][0]
//--------------------
player CheckDiagonalForward(player matrix[][ARRAY_SIZE])
{
	player winner = proceed;

	for (int j = 0; j < ARRAY_SIZE - 2; j++)
	{
		if (winner == proceed)
		{
			winner = CheckDiagonalForwardInternal(matrix, j);
		}

	}
	for (int i = 0; i < ARRAY_SIZE - 2; i++)
	{
		if (winner == proceed)
		{
			winner = CheckDiagonalForwardInternal(matrix, 0, i);
		}
	}

	return winner;
}

//--------------------
//Same as above except for the diagonals beginning in
// array coordinate [0][ARRAY_SIZE - 1]
//--------------------
player CheckDiagonalBackward(player matrix[][ARRAY_SIZE])
{
	player winner = proceed;

	for (int j = 0; j < ARRAY_SIZE - 2; j++)
	{
		if (winner == proceed)
		{
			winner = CheckDiagonalBackwardInternal(matrix, j);
		}

	}
	for (int i = ARRAY_SIZE - 1; i > 2; i--)
	{
		if (winner == proceed)
		{
			winner = CheckDiagonalBackwardInternal(matrix, 0, i);
		}
	}
	return winner;
}

//--------------------
//Checks the board for a draw by checking if the top row has any
// remaining moves
//--------------------
player CheckDraw(player matrix[][ARRAY_SIZE])
{
	player winner = proceed;
	
	int counter = 0;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (matrix[ARRAY_SIZE - 1][i] != proceed)
		{
			counter++;
		}
	}
	if (counter >= ARRAY_SIZE - 1)
	{
		winner = draw;
	}
	return winner;
}

//--------------------
//Function that checks each individual row for 4 common values
// (ignoring blank spaces) and once they are encountered, returns
// the value of the last space checked.
//--------------------
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

//--------------------
//See description for previous function, same but for collumns 
//--------------------
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

//--------------------
//See description for previous function, same but for diagonals,
//	beginning in the corner [0][0] of the array
//--------------------
player CheckDiagonalForwardInternal(player matrix[][ARRAY_SIZE], int j, int i, int counter)
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
			return CheckDiagonalForwardInternal(matrix, j, i);
		}
	}


	else if (j >= ARRAY_SIZE - 1)
	{
		return proceed;
	}

	else if (i >= ARRAY_SIZE - 1)
	{
		return proceed;
	}


	else if (matrix[j][i] == matrix[j + 1][i + 1])
	{
		counter++;
		j++;
		i++;
		return CheckDiagonalForwardInternal(matrix, j, i, counter);
	}
	else
	{
		j++;
		i++;
		return CheckDiagonalForwardInternal(matrix, j, i);
	}

}

//--------------------
//See description for previous function, same but for diagonals,
//	beginning in the corner [0][0] of the array
//--------------------
player CheckDiagonalBackwardInternal(player matrix[][ARRAY_SIZE], int j, int i, int counter)
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
			return CheckDiagonalBackwardInternal(matrix, j, i);
		}
	}

	else if (j >= ARRAY_SIZE - 1)
	{
		return proceed;
	}

	else if (i <= 0)
	{
		return proceed;
	}

	else if (matrix[j][i] == matrix[j + 1][i - 1])
	{
		counter++;
		j++;
		i--;
		return CheckDiagonalBackwardInternal(matrix, j, i, counter);
	}
	else
	{
		j++;
		i--;
		return CheckDiagonalBackwardInternal(matrix, j, i);
	}

}

/// TextColor - 	Sets the text color for console output
/// 			This sets the text color only, not the background color.
///			Reset the text to "default" to print normal console text.
///			Requires: #include <windows.h>
///
/// TextColor - 	Sets the text color for console output
/// 			This sets the text color only, not the background color.
///			Reset the text to "default" to print normal console text.
///			Requires: #include <windows.h>
///
void TextColor(string color)
{
	if (color == "red")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	}
	else if (color == "yellow")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
	}
	else if (color == "white")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
	}
	else if (color == "default")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	}

}