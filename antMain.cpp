/*******************************************************************************
** Program:		Project 1 - Langton's Ant
** Author:		Elaine Kim
** Date:		July 1, 2019
** Description:	This program simulates Langton's Ant. The user chooses how many 
** steps the ant takes. The ant will move according to Langton's Ant rule until 
** the number of steps runs out. Each step is printed to the console. This file 
** contains the main function and primary function to display the menu and get
** the user's menu choice.
*******************************************************************************/
#include <iostream>
#include "Ant.hpp"

using std::cout;
using std::cin;
using std::endl;

// Function declaration
int displayMenu();

int main()
{
	// Variables
	int choice;	
	Ant run;

	// Call function to display menu
	choice = displayMenu();			

	// If user does not want to quit, proceed
	if (choice == 1)
	{
		// Call functions
		run.makeBoard();
		run.startAnt();

		// Call functions while number of steps is less than the max steps
		while (run.getSteps() < run.getMaxSteps()){
			run.displayBoard();
			run.moveAnt();
		}
	}
return 0;
}

/******************************************************************************
** Function: displayMenu
** This function displays the menu choices and validates the user's input.
******************************************************************************/
int displayMenu() {
	int choice; 			// Holds the user's choice

	system ("cls"); 		// Clear the screen
	cout << "\t MENU \n";
	cout << "1) Start Langton's Ant Simulation" << endl; 
	cout << "2) Quit\n\n";
	cout << "Enter your choice: ";
	cin >> choice;
	
	// Validate user input
	// Use cin.clear() and cin.ignore() to clear the error flag on cin
    // Source: https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
	while (choice < 1 || choice > 2) {
		cout << "Invalid choice. Please choose either 1 or 2 and re-enter: "; 
		cin.clear();
      	cin.ignore(10000,'\n');
		cin >> choice;
	}
	return choice;
}
