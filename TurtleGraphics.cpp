#include<iostream>
#include "TurtleGraphics.h"

using namespace std;

TurtleGraphics::TurtleGraphics(void) : m_Floor()
{

}

void TurtleGraphics::processTurtleMoves(const int commands[])
{
	cout << "Processing commands" << endl;
	
	for (size_t i = 0; i < NROWS; i++)
	{
		for (size_t j = 0; j < NCOLS; j++)
		{
			m_Floor[i][j] = 1;
			cout << m_Floor[i][j];
		}
		cout << endl;
	}
}

void TurtleGraphics::displayFloor() const 
{
	cout << "Displaying all aterix" << endl;
}