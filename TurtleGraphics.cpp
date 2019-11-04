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

//Process comands and 2d array to flip false field to true to create a pattern;
void TurtleGraphics::processTurtleMoves(const array<int, TurtleGraphics::ARRAY_SIZE> & comds)
{
	int sentinel = 0;

	while (sentinel != END_OF_DATA)
	{
		for (size_t i = 0; i < comds.size(); i++)
		{
			switch (comds[i]) //TODO: make sure to switch with comds array to Comands enum;
			{
			case PEN_UP:
				currentPenState = false;
				//cout << "Pen is up\n";
				break;
			case PEN_DWN:
				currentPenState = true;
				//cout << "Pen is down\n";
				break;
			case TURN_RIGHT:
				//cout << "Turning right\n";
				turnRight(&currentDirection);
				break;
			case TURN_LEFT:
				//cout << "Turning left\n";
				turnLeft(&currentDirection);
				break;
			case MOVE:
				//consider passing number of elements in comds array;
				move(comds[i+1], &currentDirection, currentPenState, m_Floor);
				i++;
				break;
			case DISPLAY:
				displayFloor();
				break;
			case END_OF_DATA:
				sentinel = 9;
				break;
			}
		}
	}
}

void TurtleGraphics::move(size_t valToMoveBy, Directions *currDir, bool currPenState, array <array <bool, NCOLS>, NROWS> theGrid)
{
	/*
		move funk nees: 
			grid NROWS x NCOLS;
			comds array;
			value to move by (this is 5 so we alreay know we are moving);
			status of the pen;
	*/

	switch (*currDir)
	{
	case SOUTH:
		//traverse the grid moving south;
		for (size_t i=0; i < valToMoveBy; i++)
		{
			if (row >= (NROWS - 1))
				break;
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
		for (size_t i = 0; i < valToMoveBy; i++)
		{
			if (col <= 0)
				break;
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
		for (size_t i = 0; i < valToMoveBy; i++)
		{
			if (row <=0)
				break;
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
		for (size_t i = 0; i < valToMoveBy; i++)
		{
			if (col >= (NCOLS - 1))
				break;
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
	m_Floor = theGrid;
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
			}  //end of inner loop
		}
		cout << endl;
	}
}