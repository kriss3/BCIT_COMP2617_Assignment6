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
	int comds[] = { 5,3,2,4,5,4,3,5,3,4,5,10,6,9 };
	int s = size(comds);

	while (sentinel != 9)
	{
		for (int i = 0; i < s; i++)
		{
			switch (comds[i]) //TODO: make sure to swtich with comds array to Comands enum;
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
				turnRight(&currentDirection);
				break;
			case 4:
				cout << "Turning left\n";
				turnLeft(&currentDirection);
				break;
			case 5:
				//consider passing number of elements in comds array;
				move(comds[i+1], &currentDirection, currentPenState, m_Floor, comds, size(comds));
				cout << "Moving cursor by 9\n";
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

	/*
							Rows       Columns
		I have a grid  22     x   70	
		All values in the grid are populated with value TRUE;



	*/

	int x = valToMoveBy;
	cout << "Moving\n";
	//first, based on the direction make a move;
	switch (*currDir)
	{
	case SOUTH:
		//traverse the grid moving south;
		if (currPenState)
		{
			for (int i=0; i < valToMoveBy; i++)
			{
				theGrid[row][col] = false;
				row++;
			}
		}
		else
		{
			for (int i = 0; i < valToMoveBy; i++)
			{
				row++;
			}
		}
		break;
	case WEST:
		if (currPenState)
		{
			for (int i = 0; i < valToMoveBy; i++)
			{
				theGrid[row][col] = false;
				col++;
			}
		}
		else
		{
			for (int i = 0; i < valToMoveBy; i++)
			{
				col++;
			}
		}
		break;
	case NORTH:
		if (currPenState)
		{
			for (int i = 0; i < valToMoveBy; i++)
			{
				theGrid[row][col] = false;
				row++;
			}
		}
		else
		{
			for (int i = 0; i < valToMoveBy; i++)
			{
				row++;
			}
		}
		break;
	case EAST:
		if (currPenState)
		{
			for (int i = 0; i < valToMoveBy; i++)
			{
				theGrid[row][col] = false;
				col++;
			}
		}
		else
		{
			for (int i = 0; i <= valToMoveBy; i++)
			{
				col++;
			}
		}
		break;
	}
}

void TurtleGraphics::turnLeft(Directions *currentDirection)
{
	cout << "Turning Left\n";

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
	cout << "Turning Right\n";
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