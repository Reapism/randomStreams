#include "testStack.h"
#include <iostream>
#include <string>
#include <fstream>
#include <new>

void teststack::testStack(std::string fileName) {

	std::ifstream inFile(fileName);

	// if file isn't open, display error and break method.
	if (inFile.is_open()) { std::cerr << "Cannot find file."; return; }


}