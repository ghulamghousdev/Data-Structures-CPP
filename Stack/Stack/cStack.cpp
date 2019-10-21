#include "cStack.h"
#include <iostream>
#include <fstream>
using namespace std;

/*
Default constructor of STACK class to make top data member of STACK class
*/
cStack::cStack():top(NULL){}

/*
Parameterized Constructor
*/
cStack::cStack(cNode *&ptr):top(ptr) {
	top->nextNode = NULL;
	ptr = NULL;
}

//cStack constructor to input nodes from file 
cStack::cStack(ifstream &inFile) : top(NULL), count(0) {
	int size;
	inFile.read((char*)& size, sizeof(size));
	if (size > 0) {
		cNode *rptr;
		rptr = top = new cNode(inFile);
		count = size;
		for (int i = 0; i < count; ++i) {
			rptr->nextNode = new cNode(inFile);
			rptr = rptr->nextNode;
		}
		rptr->nextNode = NULL;
	}
}

//Constructors for FILE HANDLING 'OUTPUT DATA TO FILE'
cStack::cStack(ofstream &outFile) {
	outFile.write((char*)&count, sizeof(count));
	if (count > 0) {
		cNode *ptr = top;
		ptr = new cNode(outFile);
		for (int i = 1; i < count; i++) {
			ptr->nextNode = new cNode(outFile);
			ptr = ptr->nextNode;
		}
	}
}

//Member function to write cStack nodes to file
void cStack::writeToFile(ofstream &oFile) {
	if (!(oFile.is_open())) {
		cout << "File is not opened !" << endl;
	}
	else {
		oFile.write((char*)&count, sizeof(count));

		if (count > 0) {
			cNode *rptr = top;
			for (int i = 0; i < count; ++i) {
				rptr->writeNodeToFile(oFile);
				rptr = rptr->nextNode;
			}
		}
	}
}

//Member function to read input nodes from file
void cStack::readFromFile(ifstream &inFile) {

	if (true) {
		cStack temp;
		temp.top = this->top;
	}

	inFile.read((char*)&count, sizeof(count));
	cout << "count = " << count << endl;

	if (count > 0) {
		cNode *temp;
		temp = top = new cNode(inFile);

		for (int i = 1; i < count; ++i) {
			temp->nextNode = new cNode(inFile);
			temp = temp->nextNode;
		}
		temp->nextNode = NULL;
	}
}

/*
Function to check if Stack is not empty
*/
bool cStack::isNotEmpty() const{
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
Cascaded pop function which removes the last node from Stack
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
		cout << "Stack is empty." << endl;
	}
	else {
		cout << "All the elements in the STACK is: ";
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
			dPtr->nextNode = new cNode(*sPtr);
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


