/*
Function definations of cNode class
*/

#include <iostream>
#include "cNode.h"
using namespace std;


//default constructor
cNode::cNode() :data(0) {}

/*
Parameterized constructor used to assign value passed
by the user to the data member named as data
*/
cNode::cNode(int d,int p) : data(d),priority(p) {}


/*
Function used to set data passed by the user in node of STACK
*/
cNode& cNode::setData(int number) {
	this->data = number;
	return *this;
}

/*
Function used to get data and return it from a node of STACK
*/
int cNode::getData() {
	return data;
}

/*
Print function is used to print all the elements of the STACK
*/
void cNode::print() const {
	cout << data << " ";
}
/*
Setting the priority of data
*/
void cNode::setPriority(int prior) {
	priority = prior;
}

/*
Getting the priority of data
*/
int cNode::getPriority() {
	return priority;
}

/*
Function to print priority of data
*/
void cNode::printPriority() const {
	cout << priority << " ";
}

/*
Default desstructor wouldn't delete the memory allocated on HEAP
*/
cNode::~cNode()
{
}
#pragma once