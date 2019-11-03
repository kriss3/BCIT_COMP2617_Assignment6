// Assignment 6 Solution: TurtleGraphics.h
// Declaration of class TurtleGraphics.
// Member functions are defined in TurtleGraphics.cpp.
// Author: Bob Langelaan 
// Date: June 5, 2019

#pragma once

// Define some enum types that will be used in solution.

enum Commands { PEN_UP = 1, PEN_DWN = 2, TURN_RIGHT = 3, TURN_LEFT = 4, MOVE = 5, DISPLAY = 6, END_OF_DATA = 9 };
enum Directions { NORTH, EAST, SOUTH, WEST };

class TurtleGraphics
{
private:

	const static int NROWS = 22;  // number of rows in floor
	const static int NCOLS = 70;  // number of colums in floor

	const static int STARTING_ROW = 0;    // row that turtle will start in
	const static int STARTING_COL = 0;    // column that turtle will start in

	const static Directions STARTING_DIRECTION = SOUTH; // direction that turtle 
	                      // will be facing at the start

	const static bool STARTING_PEN_POSITION = false; // Pen will be up when 
	                            // program starts
                                // false means pen up, true means pen down

	bool currentPenState = STARTING_ROW; // pen is in up position by default;
	Directions currentDirection = STARTING_DIRECTION; //initial direction SOUTH;
	
	int row = STARTING_ROW; //initial xAxis position x=0;
	int col = STARTING_COL; // initial yAxis position y=0;
	bool m_Floor [NROWS][NCOLS];   // floor on which turtle will draw

public:
	TurtleGraphics(void); //ctor will init. floor to all "true" values, 
	                      //     as well as initialization of other data members
	void processTurtleMoves( const int commands[]);  // will process
	                   // the commands contained in array "commands"	
	void displayFloor() const;  // will display floor on the screen
	int move(int valueToMoveBy, Directions *dir, bool currentPenState, bool theGrid[][NCOLS], int comdsArr[], int comdsSize);
	void turnLeft(Directions *dir);
	void turnRight(Directions *dir);
};



