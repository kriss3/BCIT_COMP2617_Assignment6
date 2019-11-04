#include<iostream>
#include "TurtleGraphics.h"

using namespace std;

TurtleGraphics::TurtleGraphics(void) : m_Floor()
{
	//bool m_Floor[NROWS][NCOLS] = { {true},{true} };
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
	//int comds[] = { 5,3,4,5,3,2,5,5,4,5,6,6,9 };
	//int comds[] = { 5,3,2,4,5,4,3,5,3,4,5,10,6,9 };
	//int comds[] = { 1,5,100,2,4,5,100,4,5,100,4,5,100,4,5,100,4,5,100 };
	//int comds[] = {5,100,2,4,5,100,6,9};

	//int comds[] = {2,5,20,4,5,60,4,5,20,4,5,60,1,6,9};

	int comds[] = { 5,5,4,5,9,2,    // go to start of first letter and put pen down

					 // B
					 5,12, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,
					 1,3,5,12,3,5,5, 5,1,4,2,5,1, 1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,

					 1,5,5,3,5,22,2, // go to start of next letter and put pen down

					 // O
					 5,10, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,7, 1,3,5,1,4,2,5,1,
					 1,3,5,1,2,5,10, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,7, 1,3,5,1,4,2,5,1,

					 1,3,5,19,2,     // go to start of next letter and put pen down

					 // B
					 5,12, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,
					 1,3,5,12,3,5,5, 5,1,4,2,5,1, 1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,

		// Test program bound checking and add border in the process

		//   Uncomment next line when ready to test bound checking
		//1,5,100,2,4,5,100,4,5,100,4,5,100,4,5,100,4,5,100,

		1,6,9 }; // finish off


	int s = size(comds);

	while (sentinel != 9)
	{
		for (int i = 0; i <= s; i++)
		{
			switch (comds[i]) //TODO: make sure to swtich with comds array to Comands enum;
			{
			case 1:
				currentPenState = false;
				//cout << "Pen is up\n";
				break;
			case 2:
				currentPenState = true;
				//cout << "Pen is down\n";
				break;
			case 3:
				//cout << "Turning right\n";
				turnRight(&currentDirection);
				break;
			case 4:
				//cout << "Turning left\n";
				turnLeft(&currentDirection);
				break;
			case 5:
				//consider passing number of elements in comds array;
				move(comds[i+1], &currentDirection, currentPenState, m_Floor, comds, s);
				i++;
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

void TurtleGraphics::move(int valToMoveBy, Directions *currDir, bool currPenState, bool theGrid[][TurtleGraphics::NCOLS], int comds[], int comdsSize) 
{
	/*
		move funk nees: 
			grid NROWS x NCOLS;
			comds array;
			value to move by (this is 5 so we alreay know we are moving);
			status of the pen;
	*/

	int x = valToMoveBy;


	switch (*currDir)
	{
	case SOUTH:
		//traverse the grid moving south;
		for (int i=0; i < x; i++)
		{
			if (currentPenState)
			{
				theGrid[row][col] = false;
				row++;
			}
			else 
			{
				row++;
			}
		}
		break;
	case WEST:
		for (int i = 0; i < x; i++)
		{
			if (currentPenState)
			{
				theGrid[row][col] = false;
				col--;
			}
			else
			{
				col--;
			}
		}
		break;
	case NORTH:
		for (int i = 0; i < x; i++)
		{
			if (currentPenState)
			{
				theGrid[row][col] = false;
				row--;
			}
			else
			{
				row--;
			}
		}
		break;
	case EAST:
		for (int i = 0; i < x; i++)
		{
			if (currentPenState)
			{
				theGrid[row][col] = false;
				col++;
			}
			else
			{
				col++;
			}
		}
		break;
	}
}

void TurtleGraphics::turnLeft(Directions *currentDirection)
{
	switch (*currentDirection)
	{
	case SOUTH:
		*currentDirection = EAST;
		break;
	case WEST:
		*currentDirection = SOUTH;
		break;
	case NORTH:
		*currentDirection = WEST;
		break;
	case EAST:
		*currentDirection = NORTH;
		break;
	}
}

void TurtleGraphics::turnRight(Directions *currentDirection)
{
	switch (*currentDirection)
	{
	case NORTH:
		*currentDirection = EAST;
		break;
	case EAST:
		*currentDirection = SOUTH;
		break;
	case SOUTH:
		*currentDirection = WEST;
		break;
	case WEST:
		*currentDirection = NORTH;
		break;
	}
}

void TurtleGraphics::displayFloor() const 
{
	cout << "Displaying all ateriks.\n\n\n" << endl;
	
	for (int i = 0; i < NROWS; i++)
	{
		for (int j = 0; j < NCOLS; j++)
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