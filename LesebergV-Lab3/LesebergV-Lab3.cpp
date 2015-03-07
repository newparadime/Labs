////////////////////////////////
// Swim Meet - Lab 3
//
// Vincent Leseberg
////////////////////////////////

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;

//Declare Array Constants
const int SWIM_LENGTH = 100;
const int POOL_LENGTH = 75;
const int DELAY = 1;

//Declare Swimming Speed constants
const int SUPER_FAST = 8;
const int FAST = 6;
const int MEDIUM = 4;
const int SLOW = 2;
const int STOPPED = 0;
const int BACKWARDS = -6;

//Function Prototypes
bool MeetEnd(int poolOne[], int poolTwo[]);
void Winner(int laneOne[], int laneTwo[]);
int GetSpeed(int swimmer);
int MakePool(int pool[], int speed, int position);
char PrintPosition(int speed);
void PrintLane(int lane[]);
void ProgramMessage();
void Continue();
void Line();
void Delay();

//Main Program Functon 
int main()
{
	//Declare Program Variables
	int swimmerOneLane[POOL_LENGTH] = { 0 };
	int swimmerTwoLane[POOL_LENGTH] = { 0 };
	int positionOne = 0;
	int positionTwo = 0;
	int time = 0;

	//Print Program Purpose to Screen
	ProgramMessage();

	//Wait for user input to continue
	Continue();

	//Loop continues until one swimmer wins
	while (!MeetEnd(swimmerOneLane, swimmerTwoLane))
	{
		//Generate position for Swimmer One and update array
		positionOne = MakePool(swimmerOneLane, GetSpeed(1), positionOne);

		//Generate position for Swimmer Two and update array
		positionTwo = MakePool(swimmerTwoLane, GetSpeed(2), positionTwo);

		//Print lane position for swimmer one
		cout << "Swimmer One at time equals " << time << " Second(s)\n";
		Line();

		PrintLane(swimmerOneLane);

		Line();
		
		//Print lane position for swimmer two
		cout << "Swimmer Two at time equals " << time << " Second(s)\n";

		Line();
		
		PrintLane(swimmerTwoLane);

		Line();

		cout << endl << endl;

		//One second delay function to wait till next calculation of speed
		Delay();

		//Increase time counter
		time++;
	}

	//Once loop exits and one swimmer has reached the end of the pool, 
	//function is called to determine the winner
	Winner(swimmerOneLane, swimmerTwoLane);

	return 0;
}

//Boolean function determine when the swim meet has ended
bool MeetEnd(int poolOne[], int poolTwo[])
{
	//Checks the sum of the last two meters of the pool,
	//If it is greater than zero, one swimmer has reached the end of the pool
	if (poolOne[POOL_LENGTH - 1] + poolTwo[POOL_LENGTH - 1] > 0) return true;
	
	else return false;
}

//Function to return the 
int GetSpeed(int swimmer)
{
	//Arrays filled with speeds for each swimmer,
	//Arranged based on probabilies provided
	int speedsOne[10] = { 8, 0, 0, 0, 6, 6, 2, 2, -6, -6 };
	int speedsTwo[10] = { 2, 2, 2, 2, 4, 0, 0, 0, 0, 6 };
	
	//If function is asked for swimmer one, that array is used
	if (swimmer == 1)
	{
		//Random function modulo ten provides a random number from
		//o to 9. This is fed to the speed array to return a random speed
		srand(rand());
		return speedsOne[rand() % 10];
	}

	//If function is asked for swimmer two, that array is used
	else
	{
		//Refer to above comment...
		srand(rand());
		return speedsTwo[rand() % 10];
	}
}

//Updates array for the lane of the swimmer,
// returns current position in lane
int MakePool(int pool[], int speed, int position)
{
	//Current position is updated based on speed that second
	int end = position + speed;
	
	//If that new position is longer than the pool length
	//the position is truncated to the pool length
	if (end > POOL_LENGTH)
	{
		end = POOL_LENGTH;
	}

	//If the speed received is positive, the array is filled
	//with that speed for the interval from the last position
	//reported through the current end position
	if (speed > 0)
	{
		for (int i = position; i < end; i++)
		{
			pool[i] = speed;
		}
	}

	//If the speed is negative, the array is backfilled,
	// as above
	else
	{
		for (int i = position; i > end; i--)
		{
			pool[i] = speed;
		}
	}

	//End position is returned
	return end;
}

//Switch statement to return correct character for 
//the provided numerical speed
char PrintPosition(int Speed)
{
	char position;
	switch (Speed)
	{
	case SUPER_FAST:
		position = '~';
		break;
	case FAST:
		position = '=';
		break;
	case MEDIUM:
		position = '-';
		break;
	case SLOW:
		position = '.';
		break;
	case STOPPED:
		position = ' ';
		break;
	case BACKWARDS:
		position = '<';
	}
	return position;
}

//Prints a line equal on length to the number of 
// characters for the pool length
void Line()
{
	for (int j = 0; j < POOL_LENGTH; j++)
	{
		cout << "-";
	}
	cout << endl;
}

//Delay function for 1 second delay
void Delay()
{
	clock_t endTime = DELAY * 1000 + clock();
	while (clock() <= endTime);
}

//Prints the current lane array substituting the 
//indicated character from the program message
//for the numerical speed
void PrintLane(int lane[])
{
	for (int j = 0; j < POOL_LENGTH; j++)
	{
		cout << PrintPosition(lane[j]);
	}
	cout << endl;
}

//Prints program message to screen
void ProgramMessage()
{
	cout<< "This program simulates a race between two swimmers.\n"
		<< "Each swimmer is assigned a random speed every second\n"
		<< "Base on this speed, their motion is projected for the\n"
		<< "following second (speed is assumed to remain constant).\n"
		<< "This data is recorded every second for both swimmers\n"
		<< "in a seperate array. The position of each swimmer is\n"
		<< "then outputted to the screen for every second.\n"
		<< "A seperate icon is used for each speed, the legend for\n"
		<< "which can be found below.\n\n"
		<< "\'~\' for 8m/s\n\'=\' for 6m/s\n\'-\' for 4m/s\n\'.\' for 2m/s"
		<< "\'*\' for Stopped\n\'<\' for Reverse 6m/s\n\n"
		<< "The race will now commence, press enter when ready:\n\n\n";
}

//Waits for the user to press enter to continue
void Continue()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Determines the winner of the race and prints 
//it to the screen
void Winner(int laneOne[], int laneTwo[])
{
	//Declare string to store the winner
	string winner;

	//If the last element of the array for the lane
	// of the first swimmer is greater than one,
	// they win.
	if (laneOne[POOL_LENGTH - 1] > laneTwo[POOL_LENGTH - 1]) winner = "One";
	
	//Otherwise, winner two wins, we don't need to check
	// their array space, because we already know that the
	// race is over
	
	else winner = "Two";

	//Print results
	cout << "The race is over. Swimmer ";
	cout << winner;
	cout << " wins!!!\n\n";
}