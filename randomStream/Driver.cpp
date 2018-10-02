/*
Assignment 1: Random Streams

Author: Anthony Jaghab (c), all rights reserved.
*/

#include <iostream>
#include <random>
#include <string>
#include "randomStream.h"

/*
Main entry point.
*/
int main() {
	std::string fileName;
	std::cout << "Please input a filename: ";
	
	std::cin >> fileName;

	int iter;
	std::cout << "Please enter the number of iterations: ";

	std::cin >> iter;

	std::cout << "Creating " << fileName << ".. and iterating.." << std::endl;
	std::cout << "\nIterating " << iter << " times.\n";
	randomStream rs(fileName, iter); // create a randomStream

	std::cout << "\nDone... Check file in project dir" << std::endl;
	
	system("pause");
	return 0;
}