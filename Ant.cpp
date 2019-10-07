/*******************************************************************************
** Program:		Langton's Ant
** Author:		Elaine Kim
** Date:		July 1, 2019
** Description:	This program simulates Langton's Ant. The user chooses how many 
** steps the ant takes. The ant will move according to Langton's Ant rule until 
** the number of steps runs out. Each step is printed to the console. This file 
** contains the function definitions of all the functions necessary to simulate 
** Langton's Ant.
*******************************************************************************/
#include <iostream>
#include "Ant.hpp"

using std::cout;
using std::cin;
using std::endl;

// Initialize variables
Ant::Ant()
{
	rows = 0;
	columns = 0;
    	steps = 0;
  	direction = NORTH;
	board = NULL;
}

/******************************************************************************
** Function: makeBoard
** This function asks the user for the number of rows and columns for the board
** and then creates borders and white space for the board.
******************************************************************************/
void Ant::makeBoard(){

    // Ask user for number of rows
    cout << "\nEnter the number of rows (between 2 and 100): "; 
    cin >> rows; 

    // Determine if number of rows are within range
    // Use cin.clear() and cin.ignore() to clear the error flag on cin
    // Source: https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
    while (rows < 2 || rows > 100){
        cout << "Invalid. The number must be between 2 and 100. Please re-enter: ";
        cin.clear();
      	cin.ignore(10000,'\n');
        cin >> rows;
    }

    // Ask user for number of columns
    cout << "\nEnter the number of columns (between 2 and 100): ";
    cin >> columns;

    // Determine if number of columns are within range
    while (columns < 2 || columns > 100){
        cout << "\nInvalid. The number must be between 2 and 100. Please re-enter: ";
        cin.clear();
      	cin.ignore(10000,'\n');
        cin >> columns;
    }

    // Make the board using dynamic 2D array
    // Source: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
	board = new char*[rows];
	for (int i = 0; i < rows; i++) {
		board[i] = new char[columns];
	}

    // Fill game board with white spaces
    for (int j = 0; j < rows; j++) {
    for (int k = 0; k < columns; k++) {
		board[j][k] = ' ';
	}
    }
}

/******************************************************************************
** Function: startAnt
** This function asks starting row and column of the ant and then determines
** if the starting position is within the board.
******************************************************************************/
void Ant::startAnt(){
    // Ask user to enter the starting row of the ant
    cout << "\nPlease enter the starting row for the ant: ";
    cin >> antRow;

    // Determine if the row is within the board
    // The ant's starting row cannot be less than 1 nor greater than rows-2 
    // for the ant to be able to move
    while (antRow < 1 || antRow > rows - 2){
        cout << "\nInvalid. The number must be between 1 and " << columns << endl;
        cout << "Please re-enter: "; 
        cin.clear();
      	cin.ignore(10000,'\n');
        cin >> antRow;
    }

    // Ask user to enter the starting column of the ant
    cout << "\nPlease enter the starting column for the ant: ";
    cin >> antCol;

    // Determine if the column is within the board
    // The ant's starting column cannot be less than 1 nor greater than rows-2 
    // for the ant to be able to move
    while (antCol < 1 || antCol > columns - 2){
        cout << "Invalid. The number must be between 1 and " << rows << endl;
        cout << "Please re-enter: ";
        cin.clear();
      	cin.ignore(10000,'\n');
        cin >> antCol; 
    }

    // Ask user for number of steps during simulation
    cout << "\nHow many steps will the simulation do? Steps: ";
    cin >> maxSteps; 

    // Determine if user entered valid number of steps
    // Must be between 0 and 15,000
    while (maxSteps < 0 || maxSteps > 15000){
        cout << "\nInvalid. The number must be between 1 and 15,000.";
        cout << "Please re-enter: ";
        cin.clear();
      	cin.ignore(10000,'\n');
        cin >> maxSteps;
    }
}

/******************************************************************************
** Function: getMaxSteps
** This function returns maxSteps
******************************************************************************/
int Ant::getMaxSteps(){
    return maxSteps;
}

/******************************************************************************
** Function: getSteps
** This function returns steps
******************************************************************************/
int Ant::getSteps(){
    return steps;
}

/******************************************************************************
** Function: displayBoard
** This function creates the borders of the board and displays the board to the
** user.
******************************************************************************/
void Ant::displayBoard(){
    // Print the upper border
    for (int y = 0; y < columns + 2; y++){
        cout << "-";
    }
    cout << "\n";

    for (int x = 0; x < rows; x++) {
         // Print the left border
        cout << '|';                                
		for (int y = 0; y < columns; y++) {
            if (x == antRow && y == antCol){
                // Print the ant
                cout << '*';                        
            }
            else {
                cout << board[x][y];
            }
		}
        // Print the right border and new line
		cout << "|\n";  
	}
    // Print the lower border 
    for (int y = 0; y < columns + 2; y++){
        cout << "-";
    }
	cout << "\n";
}

/******************************************************************************
** Function: changeColor
** This function changes the color of the space of the board. If the space is 
** white, it will be changed to black. If the space is black, it will be changed
** to white.
******************************************************************************/
void Ant::changeColor(){
    if (board[antRow][antCol] == ' '){
        board[antRow][antCol] = '#';
    }
    else {
        board[antRow][antCol] = ' ';
    }
}

/******************************************************************************
** Function: turnLeft
** This function turns the ant to the left. The modulus operator is used to 
** ensure that the ant will only face NORTH (0), EAST (1), SOUTH (2), or WEST (3) 
******************************************************************************/
void Ant::turnLeft(){
    direction = (direction + 3) % 4;
}

/******************************************************************************
** Function: turnRight
** This function turns the ant to the right. The modulus operator is used to 
** ensure that the ant will only face NORTH (0), EAST (1), SOUTH (2), or WEST (3) 
******************************************************************************/
void Ant::turnRight(){
    direction = (direction + 1) % 4;
}

/******************************************************************************
** Function: takeStep
** This function determines which direction the ant is facing and then moves
** the ant one step forward in the direction the ant is facing. This function 
** uses the modulus operator to wrap the board around so the ant will appear on 
** the other side if the ant hits the edge of the board.
******************************************************************************/
void Ant::takeStep(){
    // If the ant is facing north, move one space up
    if (direction == NORTH){
        antRow = (antRow - 1 + rows) % rows;   
    }
    // If the ant is facing east, move one space to the right
    else if (direction == EAST){
        antCol = (antCol + 1) % columns;
    }
    // If the ant is facing south, move one space down
    else if (direction == SOUTH){
        antRow = (antRow + 1) % rows;
    }
    // Else, move the ant one space to the right
    else {
        antCol = (antCol - 1 + columns) % rows;
    }
}

/******************************************************************************
** Function: moveAnt
** This function calls other functions to move the ant according to Langton's 
** Ant rules. If the ant is on a white space, the ant turns right and the space
** changes to black. If the ant is on a black space, the ant turns left and the
** space changes to white.
******************************************************************************/
void Ant::moveAnt(){
    steps++;        // Keeps track of the number of steps the ant has made

    // If the space is white, turn right, change the space to black, 
    // and move one step forward
    if (board[antRow][antCol] == ' '){
        turnRight();
        changeColor();
        takeStep();
    }    
    // Else if the space is not white (black), turn left, change the space to white
    // and move one step forward
    else{
        turnLeft();
        changeColor();
        takeStep();
    }
}

