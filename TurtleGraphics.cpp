// Assign 6 TurtleGraphics class
// File Name: TurtleGraphics.cpp
// Author: Krzysztof Szczurowski
// ID: A01013054
// Date: Nov. 2nd, 2019

#include<iostream>
#include "TurtleGraphics.h"

using namespace std;

//ctor to populate 2d bool array with default values to True;
TurtleGraphics::TurtleGraphics(void) : m_Floor()  // if I don't do m_Floor() in ctor VS throws:
//Warning	C26495	Variable 'TurtleGraphics::m_Floor' is uninitialized.Always initialize a member variable;
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
			if (comds[i] <= 0)
			{
				break; //command cannot be less than or equal ZERO;
			}
			switch (comds[i]) //TODO: make sure to switch with comds array to Comands enum;
			{
			case PEN_UP:
				currentPenState = false;
				break;
			case PEN_DWN:
				currentPenState = true;
				break;
			case TURN_RIGHT:
				turnRight(&currentDirection);
				break;
			case TURN_LEFT:
				turnLeft(&currentDirection);
				break;
			case MOVE:
				if (comds[i+1] < 1) //check to make sure we are moving by at least one field;
				{
					break;
				}
				//pass the next element after '5' to indicate how many 'fields' to move by
				move(comds[i+1], &currentDirection, currentPenState, m_Floor);
				i++; // already processed the 'move', skipping the next element;
				break;
			case DISPLAY:
				displayFloor();
				break;
			case END_OF_DATA:
				sentinel = 9;
				break;
			default:
				cout << "\nProcessTurtle Move. Adding this part as the last thing to implement. This block should not be accessed!";
				break;
			}
		}
	}
}

//implemntation of move function: 
//takes value to move by (number of fields), current direction, current pen status, 2d array (our matrix);
void TurtleGraphics::move(size_t valToMoveBy, Directions *currDir, bool currPenState, array <array <bool, NCOLS>, NROWS> theGrid)
{
	/*
		move funk needs: 
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
		//traverse the grid moving west;
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
		//traverse the grid moving north;
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
		//traverse the grid moving east;
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
	default:
		cout << "\nMOVE. Adding this as a last step. This block should not be accessed!";
		break;
	}
	m_Floor = theGrid;
}

//implementation of the turnLeft function taking a pointer to current direction;
// returns void but need to update the status of the currenct directin inside the function;
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
	default:
		cout << "\nTurn LEFT. Adding this as a last step. This block should not be accessed!";
		break;
	}
}

//implementation of the turnLeft function taking a pointer to current direction;
// returns void but need to update the status of the currenct directin inside the function;
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
	default:
		cout << "\nTurn Right. Adding this as a last step. This block should not be accessed!";
		break;
	}
}

//implementation of function to display the pattern;
//traversing floor matrix and displaying asteriks on every field marked as FALSE;
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