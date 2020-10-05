#ifndef CHECKS
#define CHECKS
#include<string>
#include <iostream>
#include "Entering.h"

enum stateOfProgram {
	EXIT = 0, MULTIPLE_CHECKS = 1, SINGLE_CHECK = 2, PRINT_CHECKED = 3, ABOUT_THE_PROGRAM = 4
};
//

void printMainMenu() {
	std::cout
		<< "========================================" << std::endl
		<< "=== Welcome to my Electro-calculator ===" << std::endl
		<< "========================================" << std::endl
		<< std::endl
		<< "Please enter one of these presented options: " << std::endl
		<< std::endl
		<< "Enter 1 if you want to make multiple checks on electrical wire losses." << std::endl
		<< "Enter 2 if you want to make a single check on a wire loss" << std::endl
		<< "Enter 3 if you want to print all wire checks you have entered so far." << std::endl
		<< "Enter 4 to view additional information about this program." << std::endl
		<< "Enter 0 to exit this program." << std::endl
		<< std::endl
		<< "Enter your choice :";
	
}

bool checkForChars(std::string& incomingString) {

	if (incomingString == "") {					//if the users inserted string is empty 
		std::cout << "Please enter a number from the menu :";
		return false;
	}

	int everyCharIsEmpty = 0;

	for (size_t i = 0; i < incomingString.size() && i < 30; i++) {

		if (!isdigit(incomingString[i]) && incomingString[i] != ' ') {
			std::cout << "You have entered an invalid character. Please try again :";
			return false;
		}

		if (incomingString[i] == ' ') {
			everyCharIsEmpty++;
		}
	}

	if (incomingString.size() == everyCharIsEmpty) {

		std::cout << "Please insert something :";
		return false;
	}

	return true;
}

bool checkForStates(int insertedNumber) {
	if (insertedNumber == 0 || insertedNumber == 1 || insertedNumber == 2 || insertedNumber == 3 || insertedNumber == 4) {
		return true;
	}
	return false;
}


int pickingState() {

	std::string income;		//creating a string

	bool checkingTheInput = false;		//a helping bool otherwise it has problem with the output

	int incomeInt = 0;       //seting it to zero just in case of an error

	do {
		std::getline(std::cin, income);      //reading the line

		bool checkingTheInput = checkForChars(income);   //checking for unwanted characters in the string that are not digits

		if (checkingTheInput) {

			incomeInt = stoi(income);          //converting the string into an int
			if (!checkForStates(incomeInt)) {
				std::cout << "Please enter a number included in the menu options :";
				continue;
			}
			break;                             //breaking the loop if it is - cuz this way everything is ok
		}
	} while (!checkingTheInput);		//the loop will end if the user entered a correct number and didn't use some char


	return incomeInt;

}

void menuState(int incomeInt) {
	

	switch (incomeInt) {
	case MULTIPLE_CHECKS:
		entering();
		printMainMenu();
		menuState(pickingState());
		break;

	case SINGLE_CHECK:
		singleEntering();
		printMainMenu();
		menuState(pickingState());
		break;

	case PRINT_CHECKED:
		printTheVector();
		printMainMenu();
		menuState(pickingState());
		break;

	case ABOUT_THE_PROGRAM:
		printInformation();
		printMainMenu();
		menuState(pickingState());
		break;

	case EXIT:
		break;
	default:
		break;
	}

}




#endif // !CHECKS
