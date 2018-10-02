/*
randomStream implemention file.
Author: Anthony Jaghab (c), all rights reserved.
*/

#include "randomStream.h"
#include <climits>
#include <ostream>

void randomStream::genRndNum(std::string fileName, int& numIter) {
	std::ofstream file(fileName);

	std::random_device rnd; // creates a random seed
	std::mt19937 gen(rnd()); // using mersenne twitter engine seeding with rnd
	std::uniform_int_distribution<> minMax(INT_MIN, INT_MAX); // uniform dist. from INTMIN TO INTMAX.
	std::uniform_int_distribution<> rndLetter(0, 5); // uniform dist. from 0 to 5.

	int rndNum = 0; //represents the random number between INTMIN - INTMAX.
	int letterCode = 0; // REPRESENTS THE LETTER between 0 - 5.	
	char letters[6] = { 'A','D','P','E','C','S' }; // char array representing the characters from the enum.

	// if file isn't open, it doesnt exist. Exit method.
	if (!(file.is_open())) {
		std::cerr << "File was not found. Error on line " << __LINE__ << std::endl;
		return;
	}

	letterCode = rndLetter(gen); // gets a random number between 0-5.
	file << letters[letterCode] << " "; 
	rndNum = minMax(gen); // Gets a random number between INTMIN TO INTMAX.

	if (letterCode == 0) { // is A, append rnd num.
		file << " " << minMax(gen); // append random number to 'A'
	}

	for (int i = 1; i < numIter; i++) { // for n-1 n
		rndNum = minMax(gen); // Gets a random number between INTMIN TO INTMAX.
		letterCode = rndLetter(gen); // gets a random number between 0-5.

		file << std::endl << letters[letterCode];

		// if lettercode is 0, then append rnd number
		if (letterCode == 0) { // is A, append rnd num.
			file << " " << minMax(gen); // append random number to 'A'
		}
	}

	file.close();
}
