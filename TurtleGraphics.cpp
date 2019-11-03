#include<iostream>
#include "TurtleGraphics.h"

using namespace std;

TurtleGraphics::TurtleGraphics(void) : m_Floor()
{
	for (size_t i = 0; i < NROWS; i++)
	{
		for (size_t j = 0; j < NCOLS; j++)
		{
			m_Floor[i][j] = true;
		}
	}
}

void TurtleGraphics::processTurtleMoves(const int commands[])
{

	int sentinel = 0;
	cout << "Processing commands" << endl;
	//5,5,4,5,9,2 => move, by five, turn left, move, by 9, pen down
	/*
		1 - pen up
		2 - pen down
		3 - turn right
		4 - turn left
		5,10 move by 10
		6 - print array;
		9 - exit;
	*/
	int comds[] = { 5,5,4,5,9,2,5,12,6,9 };
	int s = size(comds);

	while (sentinel != 9)
	{
		for (int i = 0; i < s; i++)
		{
			switch (comds[i])
			{
			case 1:
				currentPenState = false;
				cout << "Pen is up\n";
				break;
			case 2:
				currentPenState = true;
				cout << "Pen is down\n";
				break;
			case 3:
				cout << "Turning right\n";
				turnRight(currentDirection);
				break;
			case 4:
				cout << "Turning left\n";
				turnLeft(currentDirection);
				break;
			case 5:
				//consider passing number of elements in comds array;
				move(currentDirection, comds, 11); //TODO: pass a real size of the comds array
				cout << "Moving cursor by 9\n";
				break;
			case 6:
				displayFloor();
				break;
			case 9:
				sentinel = 9;
				break;
			}
		}
	}
}

int TurtleGraphics::move(Directions currDir, int comds[], int comdsSize) 
{
	int x = 0;
	cout << "Moving\n";

	if (currentDirection == 1) {
		xAxis = comds[comdsSize + 1];
	}
	if (currentDirection == 0) {
		yAxis = comds[comdsSize + 1];
	}

	return x;
}

void TurtleGraphics::turnLeft(Directions currentDirection)
{
	cout << "Turning Left\n";

	switch (currentDirection)
	{
	case SOUTH:
		currentDirection = EAST;
		break;
	case WEST:
		currentDirection = SOUTH;
		break;
	case NORTH:
		currentDirection = WEST;
		break;
	case EAST:
		currentDirection = NORTH;
		break;
	}
}

void TurtleGraphics::turnRight(Directions currentDirection)
{
	cout << "Turning Right\n";
	switch (currentDirection)
	{
	case NORTH:
		currentDirection = EAST;
		break;
	case EAST:
		currentDirection = SOUTH;
		break;
	case SOUTH:
		currentDirection = EAST;
		break;
	case WEST:
		currentDirection = NORTH;
		break;
	}
}

void TurtleGraphics::displayFloor() const 
{
	cout << "Displaying all aterix" << endl;
	
	for (size_t i = 0; i < NROWS; i++)
	{
		for (size_t j = 0; j < NCOLS; j++)
		{
			if (m_Floor[i][j] == false)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

}