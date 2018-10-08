/*
Assignment 3: Random Streams/Test Stack

What's really interesting is I sorta already
did this in my previous assignment by mistake!
Just with a few changes to the menu.

Author: Anthony Jaghab (c), all rights reserved.
*/

#include <iostream>
#include <string>
#include <fstream>
#include "randomStream.h" // gen random numbers
#include "stack.h" // original stack
#include "mysteryStack.h" // mystery stack

/*
Prototypes.
*/
void createFile(std::string, int);
int testStream(std::string);
void menu();

/*
Usings (for more clarity.)
*/
using farmingdale::SUCCESS;
using farmingdale::FAILURE;

/*
Main entry point.
*/
int main() {
	menu(); // runs the menu
	std::cout << "\n\n\nProgram finished operating.\n\n";
	system("pause");
	return 0;
}

/*
Creates a menu to run the program.
*/
void menu() {
	system("CLS");

	std::cout << "Assignment 3: Menu" << std::endl;
	std::cout << "1. Exit." << std::endl;
	std::cout << "2. Create new random stream." << std::endl;
	std::cout << "3. Run teststream on existing file." << std::endl;
	std::cout << "4. Create new random stream and run teststream.\n" << std::endl;
	std::cout << "Enter your choice: ";


	int in = 1;
	std::cin >> in;

	switch (in) {

	case 1: { 
		return;
	}

	case 2: { // use existing file for teststream
		std::string fileName;
		std::cout << "\nPlease input a new filename: ";

		std::cin >> fileName;

		int iter;
		std::cout << "Please enter the number of iterations: ";

		std::cin >> iter;
		createFile(fileName, iter);
		system("pause");
		break;
	}

	case 3: { // run teststream only on existing file
		std::string fileName;
		std::cout << "Please input an existing filename: ";

		std::cin >> fileName;
		int isError = testStream(fileName); // gets the line number if an error occured.

		if (isError != 0) {
			std::cerr << "Failed test! Error on line " << isError << std::endl;
		}
		else {
			std::cout << "\n\nPassed test..\n\n";
		}
		system("pause");
		break;
	} 

	case 4: { // create file, run teststream
		std::string fileName;
		std::cout << "Please input a new filename: ";

		std::cin >> fileName;

		int iter;
		std::cout << "Please enter the number of iterations: ";

		std::cin >> iter;
		createFile(fileName, iter);
		int isError = testStream(fileName); // gets the line number if an error occured.

		if (isError != 0) {
			std::cerr << "Failed test! Error on line " << isError << std::endl;
		}
		else {
			std::cout << "\n\nPassed test..\n\n";
		}
		system("pause");
		break; }

	default: { // recursively call menu until a 1, 2 or 3 is called.
		std::cerr << "\n\nYou need to select a choice.\n\n";
		system("pause");
		system("CLS");
		menu();
		return; } // default
	} // switch
	menu(); // call menu until exit.
}

/*
Creates a file from Assignment 1
FIXED to produce a random number on
only lines that A are on.
*/
void createFile(std::string fileName, int iter) {
	// outputs
	std::cout << "Creating " << fileName << ".. and iterating.." << std::endl;
	std::cout << "\nIterating " << iter << " times.\n";
	randomStream rs(fileName, iter); // create a randomStream'
	std::cout << "Created " << fileName <<"\n\n";
}

/*
TestStream:
Returns a line number if there is a failure,
0 if succesful
*/
int testStream(std::string fileName) {

	std::ifstream inFile(fileName);
	// if file isn't able to open, display error and break method.
	if (!inFile.is_open()) { std::cerr << "Cannot find file."; return 1; }


	//create two farmingdale::stacks, and one mystery::stack.
	farmingdale::stack s1, s2;
	mystery::stack s3(0);
	
	std::string line; // string containing the whole line
	char letter; // the character for each line
	
	while (std::getline(inFile, line, '\n')) { // get the line from file with \n as delimiter	
		letter = line[0]; // gets the first character of every line.


		//switch on the letter.
		switch (letter) {
		case 'A': {
			std::string pushed = line.substr(2); // std::string to push.

			farmingdale::status returnStatus = s1.push(pushed); // check return status of pushing the string.

			// if the return status is any different than the first stack, there is an error.
			if (returnStatus == s2.push(pushed) && returnStatus == s3.push(pushed)) {
				//return 0; // 0 is success.
			} else {
				return __LINE__; } // returns the line number int

			break; }

		case 'P': {

			std::string peeked; // std::string that got peeked.
			farmingdale::status returnStatus = s1.peek(peeked);

			// all returnStatus' should be the same. if any differ, there is an error.
			if (returnStatus == s2.peek(peeked) && returnStatus == s3.peek(peeked)) {

			} else {
				return __LINE__; } // returns the line number int

			break; }

		case 'D': {

			std::string popped; // std::string that got popped.
			farmingdale::status returnStatus = s1.peek(popped);

			// all returnStatus' should be the same. if any differ, there is an error.
			if (returnStatus == s2.peek(popped) && returnStatus == s3.peek(popped)) {
				//return 0; // 0 is success
			}
			else {
				return __LINE__;
			} // returns the line number int

			break; }

		default: break;
		} // switch
	} // while


	inFile.close(); // close file.
	return 0; // we passed because we didn't return a line number for an error!
}