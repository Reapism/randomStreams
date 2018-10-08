// (c) 2018 David Gerstl, all rights reserved
// same as #pragma once but more portable

/*
Converted this stack to work with std::string.
*/

#ifndef H_STACK
#define H_STACK

namespace farmingdale {
	class stack;
	enum status { SUCCESS, FAILURE };
	const int SIZE = 10;
}
class farmingdale::stack { // note the scope resolution operator
private:
	int count = 0;
	int currentCapacity = SIZE;
	std::string *internalData = 0;
	inline bool isFull() { return (count == currentCapacity); }
public:
	// default ctor
	stack();
	// copy ctor
	stack(const stack &);
	// dctor
	~stack();
	bool isEmpty();
	status push(std::string pleaseInsertMe);
	status pop(std::string &returnedValue);
	status top(std::string &returnedValue);
	status peek(std::string &returnValue) { return top(returnValue); }
	int capacity() { return 100000; }
	// == as a member function
	// note the use of const-reference to avoid the implicit copy of arguments that might be very large.
	// we need this to promise that it doesn't change the stack (trailing const) or we cannot call this from operator!= which has a const& LHS
	bool operator==(const stack &rhs) const;

	// rule of threes says that if we implement one of these, all need to be implemented
	// destructor
	// copy ctor
	// assignment operator (=)
};
// why is this here?
// because it is an outside FUNCTION (not a METHOD), so outside the class
// but we want it to be available to all USERS OF THE CLASS, so inside this header file
bool operator!=(const farmingdale::stack &lhs, const farmingdale::stack &rhs); // this is an outside function
#endif // H_STACK
