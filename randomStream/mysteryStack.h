// (c) 2013-2017 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class farmingdale::stack: General integer stack implementation based on array. 
// We will add dynamic arrays (for unlimited size), templates (to allow multiple types) etc.

// note: This is not thread safe--there are no mutexes or locks on the indexes.

// like #pragma once but more portable
#ifndef H_MYSTERY_STACK
#define H_MYSTERY_STACK

#include <string>

namespace mystery {
	enum statusCode { SUCCESS, FAILURE };
	class stack;
}

class mystery::stack {
private:
	std::string * data;			  // This should become a dynamic array
	int sz;
	int param;
	int nextInsertIndex; // index of the first empty spot
public:
	stack(int); // parameterized ctor - see my assignment
	stack(const stack& copyMe);

	// returns the current capacity. Used for testing and using this fixed size version
	inline int stackCapacity() const { return sz; } // returns the current queue capacity-will change in dynamic
	inline bool isEmpty() const { return (0 == nextInsertIndex); }
	inline bool isFull() { return (sz == nextInsertIndex); }
	statusCode push(std::string addMe);
	statusCode pop(std::string &returnedElement);
	statusCode peek(std::string &returnedElement) const;
};


#endif // ifdef H_MYSTERY_STACK

