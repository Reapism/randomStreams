/*
randomStream.h
Contains the class definition and function prototypes 
*/

#ifndef randomStream
#define H_randomStream

#include <iostream>
#include <random>
#include <climits>
#include <string>
#include <fstream>

class randomStream {
private:

	enum Letters{A, D, P, E, C, S};
public:
	/*
	Parameterized constructor for randomStream.
	fileName : string - the exact name of the file e.g. file.txt
	numIter : int - the number of iterations of creating random Letters.

	If numIter
	*/
	randomStream(std::string fileName, int numIter = 10) {
		
		if (numIter < 1) {
			std::cerr << "Error on line " << __LINE__ <<
				". numIter was passed with a value < than 1.";
			return;
		}

		genRndNum(fileName, numIter);
	}

	/*
	Generates numIter letters random numbers numIter 
	times from INT_MIN - INT_MAX.
	*/
	void genRndNum(std::string fileName,int& numIter);

};




#endif
