/*
Implementation file for cStack class
*/
#include "cStack.h"
#include <iostream>

using namespace std;

/*
Default constructor of STACK class to make top data member of STACK class NULL
*/
cStack::cStack() :top(NULL) {}

/*
Parameterized Constructor
*/
cStack::cStack(cNode *&ptr) : top(ptr) {
	top->nextNode = NULL;
	ptr = NULL;
}

/*
Function to check if Stack is not empty
*/
bool cStack::isNotEmpty() const {
	if (top != NULL) { //if STACK is not empty returning true
		return true;
	}
	else {//if STACK is empty returning false
		return false;
	}
}

/*
Function to check if stack is empty
*/
bool cStack::isEmpty() const {
	if (top == NULL) {//if STACK is empty returning true
		return true;
	}
	else {//if STACK is not empty returning false
		return false;
	}
}

/*
Cascaded push function which addes a new node to Stack at top
*/
cStack & cStack::push(cNode *&ptr) {
	ptr->nextNode = top;
	top = ptr;
	ptr = NULL;
	return *this;
}

/*
Cascaded pop function which removes the lastest node from Stack
*/
cNode * cStack::pop() {
	cNode *ptr;
	ptr = top;
	top = top->nextNode;
	ptr->nextNode = NULL;
	return ptr;
}

/*
Function to print all the elements present in the Stack
*/
void cStack::print() const {
	if (isEmpty()) { //Checking if the STACK is empty
		cout << "There is no element." << endl;
	}
	else {
		cout << "All the elements are: ";
		cNode *ptr; //Declaring a runner pointer to move through
		ptr = top;
		while (ptr) { //Moving through the STACK and printing the data of each node present in the STACK
			ptr->print();
			ptr = ptr->nextNode;
		}
		cout << "\n\n";
	}
}


/*
Self Defined Copy Constructor to avoid shallow copy
*/
cStack::cStack(const cStack & src) {
	this->top = src.top;
	if (src.top) {
		cNode *sPtr, *dPtr;
		dPtr = top = new cNode(*src.top);
		sPtr = src.top->nextNode;
		while (sPtr) {
			dPtr->nextNode = new cNode(*src.top);
			sPtr = sPtr->nextNode;
			dPtr = dPtr->nextNode;
		}
	}
}

/*
Assignment Operator overloaded
*/
cStack & cStack::operator = (const cStack & rObj) {
	if (this == &rObj) {
		return *this;
	}if (true) {
		cStack temp;
		temp.top = top;
	}
	if (true) {
		cStack temp;
		temp = rObj;
		top = temp.top;
		temp.top = NULL;
		return *this;
	}
}

//Destructor to return the heap memory used during the program
cStack::~cStack() {
	cNode *ptr = top;
	while (ptr) {
		ptr = ptr->nextNode;
		delete top;
		top = ptr;
	}
}


#pragma once