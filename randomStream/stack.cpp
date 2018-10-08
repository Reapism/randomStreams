// (c) 2018 David Gerstl, all rights reserved

// for cin, cout, cerr
#include <iostream>
#include <new>
#include "stack.h"

using farmingdale::SUCCESS;
using farmingdale::FAILURE;

bool operator!=(const farmingdale::stack &lhs, const farmingdale::stack &rhs) {
	return (!(lhs == rhs));
}

farmingdale::stack::stack() {
	internalData = new std::string[SIZE];
}

farmingdale::stack::~stack() {
	delete[] internalData;
}
// copy ctor
// note the initialization list
farmingdale::stack::stack(const stack &copyMe)
	:
	count(copyMe.count),
	currentCapacity(copyMe.currentCapacity)
{
	internalData = new std::string[currentCapacity];
	for (int i = 0; i < count; ++i) {
		internalData[i] = copyMe.internalData[i];
	} // for

}
bool farmingdale::stack::operator==(const farmingdale::stack &rhs) const {
	if (count != rhs.count) {
		return false;
	}
	for (int i = 0; i < count; ++i) {
		if (internalData[i] != rhs.internalData[i]) {
			return false;
		} // if
	} // for
	return true;
}
farmingdale::status farmingdale::stack::push(std::string pleaseInsertMe) {
	// count is an lvalue
	// SIZE is an rvalue
	if (isFull()) {
		// first alloc a new piece of memory
		std::string * tempBuffer = 0;
		int newCapacity = currentCapacity * 2;
		try {
			tempBuffer = new std::string[newCapacity];
		}
		catch (std::bad_alloc) {
			return FAILURE;
		}
		// copy the stack
		for (int i = 0; i < count; ++i) {
			tempBuffer[i] = internalData[i];
		} // for
		// get rid of old memory
		delete[] internalData;
		// fix pointer and capacity
		internalData = tempBuffer;
		std::cerr << "Reallocation from size " << currentCapacity
			<< " to size " << newCapacity << std::endl;
		currentCapacity = newCapacity;
	} // if 
	internalData[count] = pleaseInsertMe;
	++count;
	return SUCCESS;
}

farmingdale::status farmingdale::stack::pop(std::string &returnedValue) {
	if (0 == count) {
		return FAILURE;
	}
	returnedValue = internalData[count - 1];
	--count;
	return SUCCESS;
}
farmingdale::status farmingdale::stack::top(std::string &returnedValue) {
	if (0 == count) {
		return FAILURE;
	}
	returnedValue = internalData[count - 1];
	return SUCCESS;
}


bool farmingdale::stack::isEmpty() {

	// placeholder
	return true;
}