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


using namespace std;

const int SWIM_LENGTH = 100;
const int POOL_LENGTH = 75;
const int DELAY = 1;

const int SUPER_FAST = 8;
const int FAST = 6;
const int MEDIUM = 4;
const int SLOW = 2;
const int STOPPED = 0;
const int BACKWARDS = -6;

bool MeetEnd(int distanceOne[], int distanceTwo[], int time);
void UpdateSpeeds(int speedOne[], int speedTwo[], int time);
void UpdateDistance(int swimDistance[], int swimSpeed[], int time);
void PrintPosition(int speed);
void PrintPool(int Distance, int speed);
void ProgramMessage();
void Continue();
void Line();
void Delay();

int main()
{
	int swimmerOneSpeed[SWIM_LENGTH] = { 0 };
	int swimmerTwoSpeed[SWIM_LENGTH] = { 0 };
	int swimmerOneDistance[SWIM_LENGTH] = { 0 };
	int swimmerTwoDistance[SWIM_LENGTH] = { 0 };

	int time = 0;

	ProgramMessage();

	Continue();

	while (!MeetEnd(swimmerOneDistance, swimmerTwoDistance, time))
	{
		time++;
		UpdateSpeeds(swimmerOneSpeed, swimmerTwoSpeed, time);
		UpdateDistance(swimmerOneDistance, swimmerOneSpeed, time);
		UpdateDistance(swimmerTwoDistance, swimmerTwoSpeed, time);
	}
	
	for (int i = 0; i < time; i++)
	{
		cout << "Swimmer One at time equals " << i << " Second(s)\n";
		Line();

		PrintPool(swimmerOneDistance[i], swimmerOneSpeed[i]);

		Line();

		cout << "Swimmer Two at time equals " << i << " Second(s)\n";

		Line();
		PrintPool(swimmerTwoDistance[i], swimmerTwoSpeed[i]);

		Line();

		cout << endl << endl;

		Delay();
	}
		return 0;
}

bool MeetEnd(int distanceOne[], int distanceTwo[], int time)
{
	if ((distanceOne[time] + distanceTwo[time])/2 >= POOL_LENGTH)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UpdateSpeeds(int speedOne[], int speedTwo[], int times)
{
	int speedsOne[10] = { 8, 0, 0, 0, 6, 6, 2, 2, -6, -6 };
	int speedsTwo[10] = { 2, 2, 2, 2, 4, 0, 0, 0, 0, 6 };
	srand(rand());
	speedOne[times] = speedsOne[rand() % 10];
	srand(rand());
	speedTwo[times] = speedsTwo[rand() % 10];
}

void UpdateDistance(int swimDistance[], int swimSpeed[], int time)
{
	swimDistance[time] = swimSpeed[time] + swimDistance[time - 1];
	if (swimDistance[time] < 0)
	{
		swimDistance[time] = 0;
	}
}

void PrintPosition(int Speed)
{
	switch (Speed)
	{
	case SUPER_FAST:
		cout << "~";
		break;
	case FAST:
		cout << "=";
		break;
	case MEDIUM:
		cout << "-";
		break;
	case SLOW:
		cout << ".";
		break;
	case STOPPED:
		cout << "*";
		break;
	case BACKWARDS:
		cout << "<";
	}
}

void Line()
{
	for (int j = 0; j < POOL_LENGTH; j++)
	{
		cout << "_";
	}
	cout << endl;
}

void Delay()
{
	clock_t startTime = clock();
	clock_t endTime = DELAY * 1000 + startTime;
	while (clock() <= endTime);
}

void PrintPool(int Distance, int speed)
{
	for (int j = 1; j < Distance; j++)
	{
		cout << ' ';
	}

	PrintPosition(speed);

	for (int j = Distance; j < POOL_LENGTH; j++)
	{
		cout << " ";
	}
	cout << endl;
}

void ProgramMessage()
{
	cout<< "This program simulates a race between two swimmers.\n"
		<< "Each swimmer is assigned a random speed every second\n"
		<< "Base on this speed, their motion is project for the\n"
		<< "following second (speed is assumed to remain constant).\n"
		<< "This data is recorded every second for both swimmers\n"
		<< "in a seperate array. The position of each swimmer is\n"
		<< "then outputted to the screen for every second."
		<< "A seperate icon is used for each speed, the legend for\n"
		<< "which can be found below.\n\n"
		<< "\'~\' for 8m/s\n\'=\' for 6m/s\n\'-\' for 4m/s\n\'.\' for 2m/s"
		<< "\'*\' for Stopped\n\'<\' for Reverse 6m/s\n\n"
		<< "The race will now commence, press enter when ready:\n\n\n";
}

void Continue()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}