/*******************************************************************************
** Program:		Project 1 - Langton's Ant
** Author:		Elaine Kim
** Date:		July 1, 2019
** Description:	This is the header file for Ant.cpp that contains the Ant class
** variables and functions.
*******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

class Ant
{
private:
    char **board;
    int rows;
    int columns;
    int antRow;
    int antCol;
    int maxSteps;
    int steps;
    int direction;      // NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3

    void changeColor();
    void turnLeft();
    void turnRight();
    void takeStep();

public: 
    Ant();
    void makeBoard();
    void startAnt();
    int getSteps();
    int getMaxSteps();
    void displayBoard();
    void moveAnt();
};
#endif