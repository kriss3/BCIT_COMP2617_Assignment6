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
	int comds[] = { 5,5,4,5,9,2 };
	int s = size(comds);
	
	for(int i = 0; i < s; i++)
	{
		switch (comds[i])
		{
			case 1:
				penState = 1;
				cout << "Pen is up\n";
				break;
			case 2:
				penState = 2;
				cout << "Pen is down\n";
				break;
			case 3:
				currentDirection = 1; //turning right
				cout << "Turning right\n";
				break;
			case 4:
				currentDirection = 0; //turning left
				cout << "Turning left\n";
				break;
			case 5:
				cout << "Moving cursor by 9\n";
				xAxis = 5;
				yAxis = 10;
				m_Floor[xAxis][yAxis] = false;
				m_Floor[6][yAxis] = false;
				m_Floor[7][yAxis] = false;
				m_Floor[8][yAxis] = false;
				m_Floor[8][11] = false;
				m_Floor[8][12] = false;
				m_Floor[8][13] = false;

				break;
		}
	}


	displayFloor();


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